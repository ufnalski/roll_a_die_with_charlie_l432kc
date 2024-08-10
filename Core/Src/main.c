/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "rng.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ssd1306.h"
#include "charlie_die.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define ROLLING_SPEED_INVERSE 1000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint8_t rng_flag = 0;
uint32_t roll_a_die_raw;
uint32_t die_face_stats[6];
uint8_t die_face;
volatile uint8_t roll_the_die;
char lcd_line[32];
uint32_t softTimerOLED;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == ROLL_BUTTON_Pin)
	{
		roll_the_die = 10;
	}
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_USART2_UART_Init();
	MX_RNG_Init();
	MX_I2C1_Init();
	/* USER CODE BEGIN 2 */

	HAL_RNG_GenerateRandomNumber_IT(&hrng);

	ssd1306_Init();
	ssd1306_Fill(Black);
	ssd1306_SetCursor(20, 0);
	ssd1306_WriteString("ufnalski.edu.pl", Font_6x8, White);
	ssd1306_SetCursor(2, 11);
	ssd1306_WriteString("Roll a die [RNG] with", Font_6x8, White);
	ssd1306_SetCursor(2, 22);
	ssd1306_WriteString("Charlie[plexing] demo", Font_6x8, White);

	ssd1306_UpdateScreen();

	softTimerOLED = HAL_GetTick();

	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		if ((roll_the_die > 0) && (1 == rng_flag)
				&& (HAL_GetTick() - softTimerOLED
						> ROLLING_SPEED_INVERSE / roll_the_die))
		{
			rng_flag = 0;
			roll_the_die -= 1;
			softTimerOLED = HAL_GetTick();

			roll_a_die_raw = HAL_RNG_ReadLastRandomNumber(&hrng);
			die_face = RawRandomTo6FaceDie(roll_a_die_raw);
			AddToDieStats(&die_face_stats[0], die_face);
			HAL_RNG_GenerateRandomNumber_IT(&hrng);

			switch (die_face)
			// distribution of random numbers
			{
			case 1:
				ssd1306_SetCursor(2, 35);
				sprintf(lcd_line, "([1]): %3li  [2] : %3li", die_face_stats[0],
						die_face_stats[1]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 45);
				sprintf(lcd_line, " [3] : %3li  [4] : %3li", die_face_stats[2],
						die_face_stats[3]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 55);
				sprintf(lcd_line, " [5] : %3li  [6] : %3li", die_face_stats[4],
						die_face_stats[5]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				break;
			case 2:
				ssd1306_SetCursor(2, 35);
				sprintf(lcd_line, " [1] : %3li ([2]): %3li", die_face_stats[0],
						die_face_stats[1]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 45);
				sprintf(lcd_line, " [3] : %3li  [4] : %3li", die_face_stats[2],
						die_face_stats[3]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 55);
				sprintf(lcd_line, " [5] : %3li  [6] : %3li", die_face_stats[4],
						die_face_stats[5]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				break;
			case 3:
				ssd1306_SetCursor(2, 35);
				sprintf(lcd_line, " [1] : %3li  [2] : %3li", die_face_stats[0],
						die_face_stats[1]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 45);
				sprintf(lcd_line, "([3]): %3li  [4] : %3li", die_face_stats[2],
						die_face_stats[3]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 55);
				sprintf(lcd_line, " [5] : %3li  [6] : %3li", die_face_stats[4],
						die_face_stats[5]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				break;
			case 4:
				ssd1306_SetCursor(2, 35);
				sprintf(lcd_line, " [1] : %3li  [2] : %3li", die_face_stats[0],
						die_face_stats[1]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 45);
				sprintf(lcd_line, " [3] : %3li ([4]): %3li", die_face_stats[2],
						die_face_stats[3]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 55);
				sprintf(lcd_line, " [5] : %3li  [6] : %3li", die_face_stats[4],
						die_face_stats[5]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				break;
			case 5:
				ssd1306_SetCursor(2, 35);
				sprintf(lcd_line, " [1] : %3li  [2] : %3li", die_face_stats[0],
						die_face_stats[1]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 45);
				sprintf(lcd_line, " [3] : %3li  [4] : %3li", die_face_stats[2],
						die_face_stats[3]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 55);
				sprintf(lcd_line, "([5]): %3li  [6] : %3li", die_face_stats[4],
						die_face_stats[5]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				break;
			case 6:
				ssd1306_SetCursor(2, 35);
				sprintf(lcd_line, " [1] : %3li  [2] : %3li", die_face_stats[0],
						die_face_stats[1]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 45);
				sprintf(lcd_line, " [3] : %3li  [4] : %3li", die_face_stats[2],
						die_face_stats[3]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				ssd1306_SetCursor(2, 55);
				sprintf(lcd_line, " [5] : %3li ([6]): %3li", die_face_stats[4],
						die_face_stats[5]);
				ssd1306_WriteString(lcd_line, Font_6x8, White);
				break;
			default:
				;
			}
			ssd1306_UpdateScreen();
		}

		switch (die_face)
		// diodes
		{
		case 1:
			DisplayDieFace1();
			break;
		case 2:
			DisplayDieFace2();
			break;
		case 3:
			DisplayDieFace3();
			break;
		case 4:
			DisplayDieFace4();
			break;
		case 5:
			DisplayDieFace5();
			break;
		case 6:
			DisplayDieFace6();
			break;
		default:
			;
		}

		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/** Configure the main internal regulator output voltage
	 */
	if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
	{
		Error_Handler();
	}

	/** Configure LSE Drive Capability
	 */
	HAL_PWR_EnableBkUpAccess();
	__HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE
			| RCC_OSCILLATORTYPE_MSI;
	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
	RCC_OscInitStruct.MSIState = RCC_MSI_ON;
	RCC_OscInitStruct.MSICalibrationValue = 0;
	RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
	RCC_OscInitStruct.PLL.PLLM = 1;
	RCC_OscInitStruct.PLL.PLLN = 40;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
	RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
	RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
	{
		Error_Handler();
	}

	/** Enable MSI Auto calibration
	 */
	HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */
void HAL_RNG_ReadyDataCallback(RNG_HandleTypeDef *hrng, uint32_t random32bit)
{
	rng_flag = 1;
}

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
