/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENC_A_pin_Pin GPIO_PIN_0
#define ENC_A_pin_GPIO_Port GPIOA
#define ENC_B_pin_Pin GPIO_PIN_1
#define ENC_B_pin_GPIO_Port GPIOA
#define ENC_Z_pin_Pin GPIO_PIN_2
#define ENC_Z_pin_GPIO_Port GPIOA
#define ENC_Z_pin_EXTI_IRQn EXTI2_IRQn
#define LIMIT_SW1_pin_Pin GPIO_PIN_4
#define LIMIT_SW1_pin_GPIO_Port GPIOA
#define LIMIT_SW2_pin_Pin GPIO_PIN_5
#define LIMIT_SW2_pin_GPIO_Port GPIOA
#define ENABLE_Pin_Pin GPIO_PIN_6
#define ENABLE_Pin_GPIO_Port GPIOA
#define DIR_pin_Pin GPIO_PIN_7
#define DIR_pin_GPIO_Port GPIOA
#define PUL_pin_Pin GPIO_PIN_0
#define PUL_pin_GPIO_Port GPIOB
#define I2C_SCL_pin_Pin GPIO_PIN_8
#define I2C_SCL_pin_GPIO_Port GPIOA
#define I2C_SDA_pin_Pin GPIO_PIN_5
#define I2C_SDA_pin_GPIO_Port GPIOB
#define USART1_TX_pin_Pin GPIO_PIN_6
#define USART1_TX_pin_GPIO_Port GPIOB
#define USART1_RX_pin_Pin GPIO_PIN_7
#define USART1_RX_pin_GPIO_Port GPIOB
#define Boot0_pin_Pin GPIO_PIN_8
#define Boot0_pin_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
