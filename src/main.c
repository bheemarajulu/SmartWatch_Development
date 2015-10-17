/**
  ******************************************************************************
  * @file    main.c
  * @author  Bheema
  * @version V0.1
  * @brief   STM32F429-DISCOVERY FREERTOS Task Creation.
  ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f429i_discovery_lcd.h"
#include <stdlib.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "math.h"
#include "stdio.h"
#include "FreeRTOSConfig.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
void vLEDFlashTask( void *pvParameters );
void vLEDFlashTask_1( void *pvParameters );
int i;
/* Private functions ---------------------------------------------------------*/
//task priorities
#define mainLED_TASK_PRIORITY			( tskIDLE_PRIORITY )
#define mainLED_TASK_PRIORITY_1         ( tskIDLE_PRIORITY + 1 )

/**
 * @brief   Main program
 * @param  None
 * @retval None
 */
int main(void) {
	HAL_Init();
	/* Configure the system clock */
	SystemClock_Config();
	BSP_LED_Init(LED3);
	BSP_LED_Init(LED4);
	BSP_LCD_Init();
	xTaskCreate( vLEDFlashTask, ( signed char * ) "LED4", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL );
	xTaskCreate( vLEDFlashTask_1, ( signed char * ) "LED3", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY_1, NULL );
	BSP_LCD_LayerDefaultInit(0, (uint32_t) LCD_FRAME_BUFFER);
//	BSP_LCD_SetLayerWindow(0, 0, 0, 240, 160);
	BSP_LCD_SetLayerVisible(0, ENABLE);
	BSP_LCD_SelectLayer(0);
	BSP_LCD_Clear(LCD_COLOR_RED);
	BSP_LCD_SetBackColor(LCD_COLOR_RED);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayOn();
	//portTickType xLastWakeTime;
	//const portTickType xFrequency = 2;
	//xLastWakeTime=xTaskGetTickCount();
	BSP_LCD_DisplayStringAtLineMode(1, (uint8_t *) "Test display", CENTER_MODE);
	//vTaskDelayUntil(&xLastWakeTime,xFrequency);
	//delay(100);
	//HAL_Delay(500);
	BSP_LCD_DisplayStringAtLineMode(5, (uint8_t *) "ALL CAPS", CENTER_MODE);
	//vTaskDelayUntil(&xLastWakeTime,xFrequency);
	//HAL_Delay(500);
	BSP_LCD_DisplayStringAtLineMode(8, (uint8_t *) "all lowercase", CENTER_MODE);
	//start scheduler
	vTaskStartScheduler();
	//you should never get here
	while (1) {
		//  BSP_LED_Off(LED4);
			//	BSP_LED_Toggle(LED3);
		/*	for(i=0;i<20;i++){
				BSP_LED_Toggle(LED3);
				HAL_Delay(500);
				BSP_LED_Off(LED3);
				HAL_Delay(500);
				BSP_LED_Toggle(LED4);
				HAL_Delay(500);
				BSP_LED_Off(LED4);
				HAL_Delay(500);
			}
	}
	*/
}
}

/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 180000000
 *            HCLK(Hz)                       = 180000000
 *            AHB Prescaler                  = 1
 *            APB1 Prescaler                 = 4
 *            APB2 Prescaler                 = 2
 *            HSE Frequency(Hz)              = 8000000
 *            PLL_M                          = 8
 *            PLL_N                          = 360
 *            PLL_P                          = 2
 *            PLL_Q                          = 7
 *            VDD(V)                         = 3.3
 *            Main regulator output voltage  = Scale1 mode
 *            Flash Latency(WS)              = 5
 *         The LTDC Clock is configured as follow :
 *            PLLSAIN                        = 192
 *            PLLSAIR                        = 4
 *            PLLSAIDivR                     = 8
 * @param  None
 * @retval None
 *
 * COPYRIGHT(c) 2014 STMicroelectronics
 */
static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;

	/* Enable Power Control clock */
	__PWR_CLK_ENABLE();

	/* The voltage scaling allows optimizing the power consumption when the device is
	 clocked below the maximum system frequency, to update the voltage scaling value
	 regarding system frequency refer to product datasheet.  */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/*##-1- System Clock Configuration #########################################*/
	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 360;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 7;
	HAL_RCC_OscConfig(&RCC_OscInitStruct);

	HAL_PWREx_ActivateOverDrive();

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

	/*##-2- LTDC Clock Configuration ###########################################*/
	/* LCD clock configuration */
	/* PLLSAI_VCO Input = HSE_VALUE/PLL_M = 1 Mhz */
	/* PLLSAI_VCO Output = PLLSAI_VCO Input * PLLSAIN = 192 Mhz */
	/* PLLLCDCLK = PLLSAI_VCO Output/PLLSAIR = 192/4 = 48 Mhz */
	/* LTDC clock frequency = PLLLCDCLK / RCC_PLLSAIDIVR_8 = 48/8 = 6 Mhz */
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
	PeriphClkInitStruct.PLLSAI.PLLSAIN = 192;
	PeriphClkInitStruct.PLLSAI.PLLSAIR = 4;
	PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_8;
	HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);
}

void vLEDFlashTask( void *pvParameters )
{
  portTickType xLastWakeTime;
  const portTickType xFrequency = 50000;
  xLastWakeTime=xTaskGetTickCount();
    for( ;; )
    {
    	BSP_LED_Toggle(LED4);
    	//BSP_LED_Off(LED3);
    	vTaskDelayUntil(&xLastWakeTime,xFrequency);

    }
}

void vLEDFlashTask_1( void *pvParameters )
{
  portTickType xLastWakeTime;
  const portTickType xFrequency = 2000;
  xLastWakeTime=xTaskGetTickCount();
    for( ;; )
    {
    	BSP_LED_Toggle(LED3);
    	//HAL_Delay(1000);
    	//BSP_LED_Off(LED3);
    	//BSP_LED_Off(LED4);
    	vTaskDelayUntil(&xLastWakeTime,xFrequency);

    }
}

void vApplicationStackOverflowHook( xTaskHandle *pxTask, signed portCHAR *pcTaskName )
{
  //indicate stack overflow
	BSP_LED_Init(LED3);
  for( ;; );
}
