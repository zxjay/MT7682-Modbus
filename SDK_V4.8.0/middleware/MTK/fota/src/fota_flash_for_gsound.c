/* Copyright Statement:
 *
 * (C) 2017  Airoha Technology Corp. All rights reserved.
 *
 * This software/firmware and related documentation ("Airoha Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to Airoha Technology Corp. ("Airoha") and/or its licensors.
 * Without the prior written permission of Airoha and/or its licensors,
 * any reproduction, modification, use or disclosure of Airoha Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 * You may only use, reproduce, modify, or distribute (as applicable) Airoha Software
 * if you have agreed to and been bound by the applicable license agreement with
 * Airoha ("License Agreement") and been granted explicit permission to do so within
 * the License Agreement ("Permitted User").  If you are not a Permitted User,
 * please cease any access or use of Airoha Software immediately.
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT AIROHA SOFTWARE RECEIVED FROM AIROHA AND/OR ITS REPRESENTATIVES
 * ARE PROVIDED TO RECEIVER ON AN "AS-IS" BASIS ONLY. AIROHA EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES AIROHA PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH AIROHA SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN AIROHA SOFTWARE. AIROHA SHALL ALSO NOT BE RESPONSIBLE FOR ANY AIROHA
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND AIROHA'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO AIROHA SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT AIROHA'S OPTION, TO REVISE OR REPLACE AIROHA SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * AIROHA FOR SUCH AIROHA SOFTWARE AT ISSUE.
 */


#include "fota_multi_info.h"
#include "fota_multi_info_util.h"
#include "fota_flash_for_gsound.h"


#ifdef __FOTA_FOR_BISTO__

bool g_bisto_fota_running;

void fota_set_bisto_fota_running(void)
{
    g_bisto_fota_running = TRUE;
}


bool fota_is_bisto_fota_running(void)
{
    return g_bisto_fota_running;
}


FOTA_ERRCODE fota_flash_alloc_partition_info(FotaStorageType *storage_type, uint32_t *address,uint32_t size)
{
	uint8_t is_inuse = fota_flash_query_is_inuse();
	FOTA_LOG_I("size : %x, is_inuse:%d,", size,is_inuse);
	if (is_inuse) {
		FOTA_LOG_I("query fail, current fota is doing");
		return FOTA_ERRCODE_FAIL;
	}
	if (!address) {
		return FOTA_ERRCODE_FAIL;
	}
	uint32_t len;
	
	*storage_type = fota_flash_get_storage_type();
	FOTA_LOG_I("type = %d", *storage_type);
	if (ExternalFlash == *storage_type) {
#ifdef FOTA_EXTERNAL_FLASH_SUPPORT
		fota_flash_partition_info *partition_info = fota_flash_get_partition_info(FLASH_PARTITION_TYPE_FOTA_EXT);
		if (!partition_info) {
			return FOTA_ERRCODE_FAIL;
		}
		*address = partition_info->LoadAddressLow;
		len = partition_info->BinaryLengthLow;

		FOTA_LOG_I("iexternal: size : 0x%0x, size:%x, address = 0x%0x, partiont = %x", len, size, *address, partition_info->LoadAddressLow);
		if (len < (size + 0x1000)) {
			FOTA_LOG_I("query partition fail, alloc size > total len");
			return FOTA_ERRCODE_FAIL;
		}
#else
			return FOTA_ERRCODE_UNSUPPORTED;
#endif
	} else if (InternalFlash == *storage_type) {
		fota_flash_partition_info *partition_info = fota_flash_get_partition_info(FLASH_PARTITION_TYPE_FOTA);
		if (!partition_info) {
			return FOTA_ERRCODE_FAIL;
		}
		*address = partition_info->LoadAddressLow;
		len = partition_info->BinaryLengthLow;
		FOTA_LOG_I("internal: len 0x%0x, size:0x%x, address = 0x%0x, partiont = %x", len, size, *address, partition_info->LoadAddressLow);

		if (len < (size + 0x1000)) {
			FOTA_LOG_I("query partition fail, alloc size > total len");
			return FOTA_ERRCODE_FAIL;
		}
	} else {
		return FOTA_ERRCODE_UNSUPPORTED;
	}
	FOTA_LOG_I("query partition success");
	return FOTA_ERRCODE_SUCCESS;
}


FOTA_ERRCODE fota_get_fw_version(uint8_t *version, Imageversiontype version_type)
{
    fota_version_type_enum ver_type = FOTA_VERSION_TYPE_NONE;

    if (currversion == version_type)
    {
        ver_type = FOTA_VERSION_TYPE_STORED;
    }
    else if (newversion == version_type)
    {
        ver_type = FOTA_VERSION_TYPE_PACKAGE;
    }
    
    return fota_version_get(version, FOTA_VERSION_MAX_SIZE, ver_type);
}


FOTA_ERRCODE fota_notify_download_done()
{
	//to do judge if it equal current storage
	/*FOTA_ERRCODE ret = fota_multi_info_sector_reset();


	FOTA_LOG_I("%s, multi_info:ret = %d, type = %d", __FUNCTION__, ret, type);
	if (ret == FOTA_ERRCODE_SUCCESS) {
		ret = fota_check_fota_package_integrity(type);
	}
*/
    FotaStorageType type = fota_flash_get_storage_type();
	FOTA_ERRCODE ret = fota_check_fota_package_integrity(type);

	FOTA_LOG_I("%s,check_integrity = %d", __FUNCTION__, ret);
	if (ret == FOTA_ERRCODE_SUCCESS) {
		ret = fota_upgrade_flag_set();
	}
	FOTA_LOG_I("%s,end---ret = %d", __FUNCTION__, ret);
	return ret;
}

FOTA_ERRCODE fota_erase(uint32_t address, FotaStorageType flash_type)
{
	int32_t ret = FOTA_ERRCODE_FAIL;
	FotaStorageType cur_type = fota_flash_get_storage_type();
	FOTA_LOG_I("%s,addr = %x, flash_type = %d, cur_type = %d", __FUNCTION__, address, flash_type, cur_type);
	if (flash_type != cur_type) {
		return ret;
	}

	if (flash_type == InternalFlash) {
		ret = fota_flash_erase(address, HAL_FLASH_BLOCK_4K, 1);
	} else if (flash_type == ExternalFlash) {
		ret = fota_flash_erase(address, HAL_FLASH_BLOCK_4K, 0);
	}

	FOTA_LOG_I("%s,ret = %d", __FUNCTION__, ret);
	return ret;
}


FOTA_ERRCODE fota_download(uint32_t address,  const uint8_t *data, uint32_t length, FotaStorageType flash_type)
{
	int32_t ret = FOTA_ERRCODE_FAIL;
	FotaStorageType cur_type = fota_flash_get_storage_type();
	FOTA_LOG_I("%s,addr = %x, flash_type = %d, cur_type = %d, len = %x",__FUNCTION__,address,flash_type, cur_type, length);
	if (flash_type != cur_type) {
		return ret;
	}
	if (flash_type == InternalFlash) {
		ret =  fota_flash_write(address, data, length, 1);
	} else if (flash_type == ExternalFlash) {
		ret = fota_flash_write(address, data, length, 0);
	}

	FOTA_LOG_I("%s,ret = %d", __FUNCTION__,ret);
	return ret;
}

FOTA_ERRCODE fota_start_transaction(void)
{

	fota_flash_set_flag_inuse(1);

	FOTA_ERRCODE ret = fota_multi_info_sector_reset();
	FOTA_LOG_I("%s, ret = %d", __FUNCTION__,ret);

	return ret;
}

void fota_reboot()
{
	fota_device_reboot();
}
FOTA_ERRCODE fota_query_upgrade_result(uint16_t *result)
{
	FOTA_LOG_I("%s, start_query", __FUNCTION__);

	FOTA_ERRCODE ret = fota_state_read(result);
	
	FOTA_LOG_I("%s, ret = %d", __FUNCTION__,ret);
	return ret;
}
#endif


