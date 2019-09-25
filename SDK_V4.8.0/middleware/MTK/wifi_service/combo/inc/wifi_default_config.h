/* Copyright Statement:
 *
 * (C) 2005-2016  MediaTek Inc. All rights reserved.
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. ("MediaTek") and/or its licensors.
 * Without the prior written permission of MediaTek and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 * You may only use, reproduce, modify, or distribute (as applicable) MediaTek Software
 * if you have agreed to and been bound by the applicable license agreement with
 * MediaTek ("License Agreement") and been granted explicit permission to do so within
 * the License Agreement ("Permitted User").  If you are not a Permitted User,
 * please cease any access or use of MediaTek Software immediately.
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT MEDIATEK SOFTWARE RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES
 * ARE PROVIDED TO RECEIVER ON AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL
 * WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 */

#ifndef __WIFI_DEFAULT_CONFIG_H__
#define __WIFI_DEFAULT_CONFIG_H__


#include "connsys_profile.h"

#ifdef __cplusplus
extern "C" {
#endif

#define WIFI_DEFAULT_OPMODE                 ("1")
#define WIFI_DEFAULT_COUNTRY_CODE           ("TW")
#define WIFI_DEFAULT_COUNTRY_REGION         ("5")
#define WIFI_DEFAULT_COUNTRY_REGION_A_BAND  ("3")
#define WIFI_DEFAULT_RADIO_ONOFF            ("0")
#define WIFI_DEFAULT_N9_DEBUG_LEVEL         ("3")
#define WIFI_DEFAULT_RTS_THRESHOLD          ("2347")
#define WIFI_DEFAULT_FRAGMENT_THRESHOLD     ("2346")
#define WIFI_DEFAULT_BG_CHANNEL_TABLE       ("1,14,0|")    //first_channel=1, num_of_ch=14,channel_prop=0(active)
#define WIFI_DEFAULT_A_CHANNEL_TABLE        ("36,8,0|100,11,0|149,4,0|")
#define WIFI_DEFAULT_SYSLOG_FILTERS         ("")
#ifdef MTK_WIFI_PRIVILEGE_ENABLE
#define WIFI_DEFAULT_WIFI_PRIVILEGE_ENABLE  ("1")
#else
#define WIFI_DEFAULT_WIFI_PRIVILEGE_ENABLE  ("0")
#endif

#define WIFI_DEFAULT_STA_FAST_LINK          ("0")
#define WIFI_DEFAULT_STA_LOCAL_ADMIN_MAC    ("1")
#define WIFI_DEFAULT_STA_MAC_ADDR           ("00:0c:43:76:87:22")
#define WIFI_DEFAULT_STA_SSID               ("MTK_SOFT_AP")
#define WIFI_DEFAULT_STA_SSID_LEN           ("11")
#define WIFI_DEFAULT_STA_BSS_TYPE           ("1")
#define WIFI_DEFAULT_STA_CHANNEL            ("1")
#define WIFI_DEFAULT_STA_BANDWIDTH          ("0")
#define WIFI_DEFAULT_STA_WIRELESS_MODE      ("9")
#define WIFI_DEFAULT_STA_BA_DECLINE         ("0")
#define WIFI_DEFAULT_STA_AUTO_BA            ("1")
#define WIFI_DEFAULT_STA_HT_MCS             ("33")
#if (PRODUCT_VERSION == 7687 || PRODUCT_VERSION == 7697)
#define WIFI_DEFAULT_STA_HT_BA_WINDOW_SIZE  ("64")
#elif (PRODUCT_VERSION == 7682 || PRODUCT_VERSION == 7686 || PRODUCT_VERSION == 5932)
#define WIFI_DEFAULT_STA_HT_BA_WINDOW_SIZE  ("4")
#endif
#define WIFI_DEFAULT_STA_HT_GI              ("1")
#define WIFI_DEFAULT_STA_HT_PROTECT         ("1")
#define WIFI_DEFAULT_STA_HT_EXT_CHANNEL     ("1")
#define WIFI_DEFAULT_STA_WMM_CAPABLE        ("1")
#define WIFI_DEFAULT_STA_LISTEN_INTERVAL    ("1")
#define WIFI_DEFAULT_STA_AUTH_MODE          ("0")
#define WIFI_DEFAULT_STA_ENCRYPT_TYPE       ("1")
#define WIFI_DEFAULT_STA_WPA_PSK            ("12345678")
#define WIFI_DEFAULT_STA_WPA_PSK_LEN        ("8")
#define WIFI_DEFAULT_STA_PAIR_CIPHER        ("0")
#define WIFI_DEFAULT_STA_GROUP_CIPHER       ("0")
#define WIFI_DEFAULT_STA_DEFAULT_KEY_ID     ("0")
#define WIFI_DEFAULT_STA_SHARE_KEY          ("12345,12345,12345,12345")
#define WIFI_DEFAULT_STA_SHARE_KEY_LEN      ("5,5,5,5")
#define WIFI_DEFAULT_STA_POWER_SAVE_MODE    ("0")
#if (PRODUCT_VERSION == 7687 || PRODUCT_VERSION == 7697)
#define WIFI_DEFAULT_STA_KEEP_ALIVE_PERIOD  ("10")
#elif (PRODUCT_VERSION == 7682 || PRODUCT_VERSION == 7686 || PRODUCT_VERSION == 5932)
#define WIFI_DEFAULT_STA_KEEP_ALIVE_PERIOD  ("55")
#endif
#define WIFI_DEFAULT_STA_BEACON_LOST_TIME   ("5")
#define WIFI_DEFAULT_APCLI_BW_AUTO_UP_BELOW ("1")
#define WIFI_DEFAULT_STA_KEEP_ALIVE_PACKET  ("1")


#define WIFI_DEFAULT_AP_LOCAL_ADMIN_MAC     ("1")
#define WIFI_DEFAULT_AP_MAC_ADDR            ("00:0c:43:76:62:12")
#define WIFI_DEFAULT_AP_SSID                ("MTK_SOFT_AP")
#define WIFI_DEFAULT_AP_SSID_LEN            ("11")
#define WIFI_DEFAULT_AP_CHANNEL             ("1")
#define WIFI_DEFAULT_AP_BANDWIDTH           ("0")
#define WIFI_DEFAULT_AP_WIRELESS_MODE       ("9")
#define WIFI_DEFAULT_AP_AUTO_BA             ("1")
#define WIFI_DEFAULT_AP_HT_MCS              ("33")
#if (PRODUCT_VERSION == 7687 || PRODUCT_VERSION == 7697)
#define WIFI_DEFAULT_AP_HT_BA_WINDOW_SIZE   ("64")
#elif (PRODUCT_VERSION == 7682 || PRODUCT_VERSION == 7686 || PRODUCT_VERSION == 5932)
#define WIFI_DEFAULT_AP_HT_BA_WINDOW_SIZE   ("4")
#endif
#define WIFI_DEFAULT_AP_HT_GI               ("1")
#define WIFI_DEFAULT_AP_HT_PROTECT          ("1")
#define WIFI_DEFAULT_AP_HT_EXT_CHANNEL      ("1")
#define WIFI_DEFAULT_AP_WMM_CAPABLE         ("1")
#define WIFI_DEFAULT_AP_DTIM_PERIOD         ("1")
#define WIFI_DEFAULT_AP_AUTH_MODE           ("0")
#define WIFI_DEFAULT_AP_ENCRYPT_TYPE        ("1")
#define WIFI_DEFAULT_AP_WPA_PSK             ("12345678")
#define WIFI_DEFAULT_AP_WPA_PSK_LEN         ("8")
#define WIFI_DEFAULT_AP_PAIR_CIPHER         ("0")
#define WIFI_DEFAULT_AP_GROUP_CIPHER        ("0")
#define WIFI_DEFAULT_AP_DEFAULT_KEY_ID      ("0")
#define WIFI_DEFAULT_AP_SHARE_KEY           ("11111,22222,33333,44444")
#define WIFI_DEFAULT_AP_SHARE_KEY_LEN       ("5,5,5,5")
#define WIFI_DEFAULT_AP_HIDDEN_SSID         ("0")
#define WIFI_DEFAULT_AP_REKEY_INTERVAL      ("3600")
#define WIFI_DEFAULT_AP_AUTO_CHANNEL_SELECT ("0")
#define WIFI_DEFAULT_AP_BEACON_DISABLE      ("0")

#define WIFI_DEFAULT_MBSS_ENABLE            ("0")
#define WIFI_DEFAULT_MBSS_SSID1             ("MTK_MBSS1")
#define WIFI_DEFAULT_MBSS_SSID2             ("MTK_MBSS2")

#ifdef MTK_WIFI_WPS_ENABLE
#define WIFI_DEFAULT_MANUFACTURER           ("MTK")
#define WIFI_DEFAULT_MODEL_NAME             ("MTK Wireless Device")
#define WIFI_DEFAULT_MODEL_NUMBER           ("MT7687")
#define WIFI_DEFAULT_SERIAL_NUMBER          ("12345678")
#define WIFI_DEFAULT_DEVICE_NAME            ("MTK IoT")
#endif

#ifdef MTK_WIFI_CONFIGURE_FREE_ENABLE
#define WIFI_DEFAULT_CONFIG_FREE_READY      ("0")
#define WIFI_DEFAULT_CONFIG_FREE_ENABLE     ("0")
#endif

#ifdef MTK_SINGLE_SKU_SUPPORT
#define WIFI_DEFAULT_SUPPORT_SINGLE_SKU ("1")    //0:not support single SKU, 1:support 2G SKU, 2:support 5G SKU, 3:support 2G and 5G SKU

#define WIFI_DEFAULT_SKU_2G_GROUP0  \
("15,15,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
16,16,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
17,17,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
18,18,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
19,19,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
15,15,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
16,16,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
17,17,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
18,18,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
19,19,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
15,15,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
16,16,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
17,17,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
18,18,18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19")

#define WIFI_DEFAULT_SKU_5G_L0 \
"11,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
12,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
13,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
11,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
12,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
13,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
11,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
12,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
13,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
11,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
12,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
13,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
11,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
12,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19"

#define WIFI_DEFAULT_SKU_5G_M0 \
"14,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
15,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
16,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
14,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
15,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
16,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
14,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
15,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
16,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
14,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
15,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
16,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
14,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
15,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19"

#define WIFI_DEFAULT_SKU_5G_H0 \
"17,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
19,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
17,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
19,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
17,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
19,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
17,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
19,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
17,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19,\
18,18,18,18,18,17,17,17,17,17,17,19,19,19,19,19,19"


#define WIFI_DEFAULT_SKU_5G_GROUP0  (WIFI_DEFAULT_SKU_5G_L0","WIFI_DEFAULT_SKU_5G_M0","WIFI_DEFAULT_SKU_5G_H0)

#endif /*MTK_SINGLE_SKU_SUPPORT*/

#ifdef MTK_ANT_DIV_ENABLE
#define WIFI_DEFAULT_ANT_NUMBER             ("0")
#define WIFI_DEFAULT_ANT_DIVERSITY_ENABLE   ("0")
#define WIFI_DEFAULT_ANT_PROB_REQ_COUNT     ("3")
#define WIFI_DEFAULT_ANT_THRESHOLD_LEVEL    ("-50")
#define WIFI_DEFAULT_ANT_DELTA_RSSI         ("5")
#define WIFI_DEFAULT_ANT_RSSI_SWITCH        ("5")
#define WIFI_DEFAULT_ANT_PRE_SELECTED_RSSI  ("-110")
#endif

int32_t wifi_get_default_config(wifi_sys_cfg_t *syscfg);



#ifdef __cplusplus
    }
#endif

#endif //__WIFI_DEFAULT_CONFIG_H__

