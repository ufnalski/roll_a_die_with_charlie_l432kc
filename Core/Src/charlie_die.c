/*
 * charlie_die.c
 *
 *  Created on: Aug 8, 2023
 *      Author: user
 */

#include "gpio.h"
#include "charlie_die.h"

uint8_t RawRandomTo6FaceDie(uint32_t raw_random_value)
{
	if (raw_random_value < 0xFFFFFFFF / 6)
	{
		return 1;
	}
	else if (raw_random_value < 0xFFFFFFFF / 3)
	{
		return 2;
	}
	else if (raw_random_value < 0xFFFFFFFF / 2)
	{
		return 3;
	}
	else if (raw_random_value < 0xFFFFFFFF / 3 * 2)
	{
		return 4;
	}
	else if (raw_random_value < 0xFFFFFFFF / 6 * 5)
	{
		return 5;
	}
	else
	{
		return 6;
	}
}

void AddToDieStats(uint32_t *die_face_stats, uint8_t die_face)
{
	if ((die_face > 0) && (die_face < 7))
	{
		*(die_face_stats + die_face - 1) += 1;
	}
}

void Led0On(void)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, CHARLIE0_Pin | CHARLIE1_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pins : PAPin PAPin */
	GPIO_InitStruct.Pin = CHARLIE0_Pin | CHARLIE1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(CHARLIE0_GPIO_Port, CHARLIE0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CHARLIE1_GPIO_Port, CHARLIE1_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = CHARLIE2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(CHARLIE2_GPIO_Port, &GPIO_InitStruct);
}

void Led3On(void)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, CHARLIE0_Pin | CHARLIE1_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pins : PAPin PAPin */
	GPIO_InitStruct.Pin = CHARLIE0_Pin | CHARLIE1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(CHARLIE0_GPIO_Port, CHARLIE0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CHARLIE1_GPIO_Port, CHARLIE1_Pin, GPIO_PIN_SET);
	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = CHARLIE2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(CHARLIE2_GPIO_Port, &GPIO_InitStruct);
}

void Led5On(void)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, CHARLIE0_Pin | CHARLIE2_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pins : PAPin PAPin */
	GPIO_InitStruct.Pin = CHARLIE0_Pin | CHARLIE2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(CHARLIE0_GPIO_Port, CHARLIE0_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CHARLIE2_GPIO_Port, CHARLIE2_Pin, GPIO_PIN_SET);
	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = CHARLIE1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(CHARLIE1_GPIO_Port, &GPIO_InitStruct);
}

void Led2On(void)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, CHARLIE0_Pin | CHARLIE2_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pins : PAPin PAPin */
	GPIO_InitStruct.Pin = CHARLIE0_Pin | CHARLIE2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(CHARLIE0_GPIO_Port, CHARLIE0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CHARLIE2_GPIO_Port, CHARLIE2_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = CHARLIE1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(CHARLIE1_GPIO_Port, &GPIO_InitStruct);
}

void Led4On(void)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, CHARLIE1_Pin | CHARLIE2_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pins : PAPin PAPin */
	GPIO_InitStruct.Pin = CHARLIE1_Pin | CHARLIE2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(CHARLIE1_GPIO_Port, CHARLIE1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(CHARLIE2_GPIO_Port, CHARLIE2_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = CHARLIE0_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(CHARLIE0_GPIO_Port, &GPIO_InitStruct);
}

void Led1On(void)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOA, CHARLIE1_Pin | CHARLIE2_Pin, GPIO_PIN_RESET);
	/*Configure GPIO pins : PAPin PAPin */
	GPIO_InitStruct.Pin = CHARLIE1_Pin | CHARLIE2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	HAL_GPIO_WritePin(CHARLIE1_GPIO_Port, CHARLIE1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(CHARLIE2_GPIO_Port, CHARLIE2_Pin, GPIO_PIN_SET);
	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = CHARLIE0_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(CHARLIE0_GPIO_Port, &GPIO_InitStruct);
}

void LedsOff(void)
{
	GPIO_InitTypeDef GPIO_InitStruct =
	{ 0 };
	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = CHARLIE0_Pin | CHARLIE1_Pin | CHARLIE2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void DisplayDieFace6(void)
{
	Led0On();
	HAL_Delay(1 * POV_DELAY); // Never ever use delay() in the main loop!!!
	Led1On();
	HAL_Delay(1 * POV_DELAY);
	Led2On();
	HAL_Delay(1 * POV_DELAY);
	Led3On();
	HAL_Delay(1 * POV_DELAY);
	Led4On();
	HAL_Delay(1 * POV_DELAY);
	Led5On();
	HAL_Delay(1 * POV_DELAY);
	LedsOff();
}

void DisplayDieFace1(void)
{
	Led1On();
	HAL_Delay(3 * POV_DELAY);
	LedsOff();
}

void DisplayDieFace2(void)
{
	Led0On();
	HAL_Delay(3 * POV_DELAY);
	Led5On();
	HAL_Delay(3 * POV_DELAY);
	LedsOff();
}

void DisplayDieFace3(void)
{
	Led0On();
	HAL_Delay(2 * POV_DELAY);
	Led1On();
	HAL_Delay(2 * POV_DELAY);
	Led5On();
	HAL_Delay(2 * POV_DELAY);
	LedsOff();
}

void DisplayDieFace4(void)
{
	Led0On();
	HAL_Delay(2 * POV_DELAY);
	Led2On();
	HAL_Delay(2 * POV_DELAY);
	Led3On();
	HAL_Delay(2 * POV_DELAY);
	Led5On();
	HAL_Delay(2 * POV_DELAY);
	LedsOff();
}

void DisplayDieFace5(void)
{
	Led0On();
	HAL_Delay(1 * POV_DELAY);
	Led1On();
	HAL_Delay(1 * POV_DELAY);
	Led2On();
	HAL_Delay(1 * POV_DELAY);
	Led3On();
	HAL_Delay(1 * POV_DELAY);
	Led5On();
	HAL_Delay(1 * POV_DELAY);
	LedsOff();
}
