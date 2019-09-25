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

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* hal includes */
#include "hal.h"
#include "bsp_gpio_ept_config.h"
#include "hal_dcxo.h"

/*hal pinmux define*/
#include "hal_pinmux_define.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

#ifdef __GNUC__
int __io_putchar(int ch)
#else
int fputc(int ch, FILE *f)
#endif
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the HAL_UART_0 one at a time */
    hal_uart_put_char(HAL_UART_0, ch);
    return ch;
}

/**
*@brief Configure and initialize UART hardware initialization for logging.
*@param None.
*@return None.
*/
static void plain_log_uart_init(void)
{
    hal_uart_config_t uart_config;
    /* gpio config for uart0 */
    hal_gpio_init(HAL_GPIO_21);
    hal_gpio_init(HAL_GPIO_22);
    hal_pinmux_set_function(HAL_GPIO_21, HAL_GPIO_21_URXD0);
    hal_pinmux_set_function(HAL_GPIO_22, HAL_GPIO_22_UTXD0);

    /* COM port settings */
    uart_config.baudrate = HAL_UART_BAUDRATE_115200;
    uart_config.word_length = HAL_UART_WORD_LENGTH_8;
    uart_config.stop_bit = HAL_UART_STOP_BIT_1;
    uart_config.parity = HAL_UART_PARITY_NONE;
    hal_uart_init(HAL_UART_0, &uart_config);
}

/**
*@brief Configure and initialize the systerm clock. In this example, we invoke hal_clock_init to initialize clock driver and clock gates.
*@param None.
*@return None.
*/
static void SystemClock_Config(void)
{
    hal_clock_init();
}

/**
*@brief  Initialize the periperal driver in this function. In this example, we initialize UART, Flash, Sleep Maneger, pmu and NVIC drivers.
*@param None.
*@return None.
*/
static void prvSetupHardware(void)
{
    /* Peripherals initialization */
    
    /* bsp_ept_gpio_setting_init() under driver/board/mt76x7_hdk/ept will initialize the GPIO settings
     * generated by easy pinmux tool (ept). ept_*.c and ept*.h are the ept files and will be used by
     * bsp_ept_gpio_setting_init() for GPIO pinumux setup.
     */
    bsp_ept_gpio_setting_init();
  
    /* sleep manager init*/
    hal_sleep_manager_init();  
  
    plain_log_uart_init();
    hal_flash_init();
    hal_nvic_init();    
    hal_pmu_init();
    hal_dcxo_init();
    hal_rtc_init();
}

uint32_t example_sleep_time = 5000;
/*
 * hal_sleep_manager_set_sleep_time : Set sleep(suspend) time length.If no other wake up event occurs, the system will sleep for a specific time.Unit is ms
 * hal_sleep_manager_enter_sleep_mode : This function sets the system to sleep mode ,Ref:hal_sleep_mode_t
 * */
int main(void)
{
    /* Configure system clock */
    SystemClock_Config();

    SystemCoreClockUpdate();

    /* Configure the hardware */
    prvSetupHardware();

    printf("\r\n"); 
    __asm volatile("cpsid i");
    printf("Example:Enter Idle.\r\n");   
    hal_sleep_manager_set_sleep_time(example_sleep_time);     
    hal_sleep_manager_enter_sleep_mode(HAL_SLEEP_MODE_IDLE);
    printf("Example:Wakeup form Idle.\r\n"); 
    
    printf("\r\n"); 
    printf("Example:Enter Sleep.\r\n");
    hal_sleep_manager_set_sleep_time(example_sleep_time);
    hal_sleep_manager_enter_sleep_mode(HAL_SLEEP_MODE_SLEEP);
    printf("Example:Wakeup form Sleep.\r\n"); 
    
    /* Re-enable interrupts - see comments above the cpsid instruction() above.
     * Ref:http://www.freertos.org/FreeRTOS_Support_Forum_Archive/November_2013/freertos_Implementing_tickless_idle_on_Cortex_M4._72d095e3j.html */
    __asm volatile("cpsie i");

    /* This is for hal_examples auto-test */
    printf("example project test success.\n");        
    
    /* If all is well, the scheduler will now be running, and the following line
     will never be reached.  If the following line does execute, then there was
     insufficient FreeRTOS heap memory available for the idle and/or timer tasks
     to be created.  See the memory management section on the FreeRTOS web site
     for more details. */
    for (;;);
}

