/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "rtc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "uart_message_parser.h"
#include "security.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MAX_MSG_LENGTH 20
#define MAX_SECURITY_CODE_LENGTH 8
#define MAX_COMMAND_LENGTH 2
#define MAX_DATA_LENGTH 10
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t received_char;
char msg_buffer[MAX_MSG_LENGTH];
uint8_t msg_buffer_idx = 0;

char session_security_code[MAX_SECURITY_CODE_LENGTH];

char uart_msg_security_code[MAX_SECURITY_CODE_LENGTH];
char uart_msg_command[MAX_COMMAND_LENGTH];
char uart_msg_data[MAX_DATA_LENGTH];

uint8_t stop = 0;

enum States {SETUP=0, SECURITY=1, DISPLAY=2, IDLE=3};
enum States current_state = SETUP;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int _write(int file, char *ptr, int len)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, HAL_MAX_DELAY);
	return len;
}

void stateMachine(void)
{
	while(current_state != IDLE) {
		switch (current_state) {
			case SETUP:
			{
				stateSETUP();
			}
			break;
			case SECURITY:
			{
				stateSECURITY();
			}
			break;
			case DISPLAY:
			{
				stateDISPLAY();
			}
			break;
		}
	}
}

void stateSETUP(void) {
	printf("[STATE] SETUP\r\n");
	while (current_state == SETUP)
	{
		if (0 == stop)
		{
			set_random_session_security_code(session_security_code, strlen(session_security_code));
		}
		else
		{
			printf("[INFO] GENERATED SECURITY CODE: %.8s\r\n", session_security_code);
			current_state = SECURITY;
		}
	}
}

void stateSECURITY(void) {
	printf("[STATE] SECURITY\r\n");
	while (current_state == SECURITY)
	{

	}
}

void stateDISPLAY(void) {
	while (current_state == DISPLAY)
	{

	}
}

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
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart1, (uint8_t*)&msg_buffer[msg_buffer_idx++], 1);
  RTC_TimeTypeDef rtc_time;
  RTC_DateTypeDef rtc_date;
  HAL_RTC_GetTime(&hrtc, &rtc_time, RTC_FORMAT_BIN);
  HAL_RTC_GetDate(&hrtc, &rtc_date, RTC_FORMAT_BIN);
  srand(rtc_time.SecondFraction*rtc_time.Seconds*rtc_time.SubSeconds);
  stateMachine();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_OFF;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 64;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV4;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1)
	{
		if (msg_buffer_idx > MAX_MSG_LENGTH-1)
		{
			if (0 != set_security_code_from_uart_message(msg_buffer, uart_msg_security_code, sizeof(uart_msg_security_code)))
			{
				printf("[ERROR] Could not get < uart_msg_security_code > from UART message!");
			}
			else
			{
				printf("[INFO] uart_msg_security_code: %s\r\n", uart_msg_security_code);
			}
			if (0 != set_command_from_uart_message(msg_buffer, uart_msg_command, sizeof(uart_msg_command)))
			{
				printf("[ERROR] Could not get < uart_msg_command > from UART message!");
			}
			else
			{
				printf("[INFO] uart_msg_command: %s\r\n", uart_msg_command);
			}
			if (0 != set_data_from_uart_message(msg_buffer, uart_msg_data, sizeof(uart_msg_data)))
			{
				printf("[ERROR] Could not get < uart_msg_data > from UART message!");
			}
			else
			{
				printf("[INFO] uart_msg_data: %s\r\n", uart_msg_data);
			}
			memset(msg_buffer, 0, sizeof(msg_buffer));
			msg_buffer_idx = 0;
			stop = 1;
		}
		HAL_UART_Receive_IT(&huart1, (uint8_t*)&msg_buffer[msg_buffer_idx++], 1);
	}
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
