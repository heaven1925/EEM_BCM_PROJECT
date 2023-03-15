/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

extern 	 void             	  MAIN_App (void);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define STOP_LAMP_Pin GPIO_PIN_2
#define STOP_LAMP_GPIO_Port GPIOE
#define VEHICLE_INLAMP1_Pin GPIO_PIN_3
#define VEHICLE_INLAMP1_GPIO_Port GPIOE
#define VEHICLE_INLAMP2_Pin GPIO_PIN_4
#define VEHICLE_INLAMP2_GPIO_Port GPIOE
#define BONNET_LAMP_Pin GPIO_PIN_5
#define BONNET_LAMP_GPIO_Port GPIOE
#define RIGHT_SIGNAL_Pin GPIO_PIN_6
#define RIGHT_SIGNAL_GPIO_Port GPIOE
#define LEFT_SIGNAL_Pin GPIO_PIN_13
#define LEFT_SIGNAL_GPIO_Port GPIOC
#define ADC3_IN9_5VIN_Pin GPIO_PIN_3
#define ADC3_IN9_5VIN_GPIO_Port GPIOF
#define ADC3_IN4_VINLAMP2_Pin GPIO_PIN_6
#define ADC3_IN4_VINLAMP2_GPIO_Port GPIOF
#define ADC3_IN5_BINLAMP_Pin GPIO_PIN_7
#define ADC3_IN5_BINLAMP_GPIO_Port GPIOF
#define ADC3_IN6_STOPLAMP_Pin GPIO_PIN_8
#define ADC3_IN6_STOPLAMP_GPIO_Port GPIOF
#define ADC3_IN7_RIGHTSIGNAL_Pin GPIO_PIN_9
#define ADC3_IN7_RIGHTSIGNAL_GPIO_Port GPIOF
#define ADC3_IN8_LEFTSIGNAL_Pin GPIO_PIN_10
#define ADC3_IN8_LEFTSIGNAL_GPIO_Port GPIOF
#define ADC3_IN10_12VIN_Pin GPIO_PIN_0
#define ADC3_IN10_12VIN_GPIO_Port GPIOC
#define ADC3_IN11_VMCU_Pin GPIO_PIN_1
#define ADC3_IN11_VMCU_GPIO_Port GPIOC
#define ADC3_IN12_3V3IN_Pin GPIO_PIN_2
#define ADC3_IN12_3V3IN_GPIO_Port GPIOC
#define ADC3_IN13_M0_Pin GPIO_PIN_3
#define ADC3_IN13_M0_GPIO_Port GPIOC
#define DYH_UART4_TX_GPIO0_Pin GPIO_PIN_0
#define DYH_UART4_TX_GPIO0_GPIO_Port GPIOA
#define ADC3_IN1_FRONT_LIGHT_CURRENT_Pin GPIO_PIN_1
#define ADC3_IN1_FRONT_LIGHT_CURRENT_GPIO_Port GPIOA
#define ADC3_IN2_BACK_LIGHT_CURRENT_Pin GPIO_PIN_2
#define ADC3_IN2_BACK_LIGHT_CURRENT_GPIO_Port GPIOA
#define ADC3_IN3_VINLAMP1_Pin GPIO_PIN_3
#define ADC3_IN3_VINLAMP1_GPIO_Port GPIOA
#define ADC_IN4_BRAKE_Pin GPIO_PIN_4
#define ADC_IN4_BRAKE_GPIO_Port GPIOA
#define ADC1_IN5_ANGLETEST_Pin GPIO_PIN_5
#define ADC1_IN5_ANGLETEST_GPIO_Port GPIOA
#define ADC1_IN6_GAS_Pin GPIO_PIN_6
#define ADC1_IN6_GAS_GPIO_Port GPIOA
#define ADC1_IN7_RIGHTARM_AXIS_Y_Pin GPIO_PIN_7
#define ADC1_IN7_RIGHTARM_AXIS_Y_GPIO_Port GPIOA
#define ADC1_IN14_LEFTARM_AXIS_X_Pin GPIO_PIN_4
#define ADC1_IN14_LEFTARM_AXIS_X_GPIO_Port GPIOC
#define ADC1_IN15_LEFTARM_AXIS_Y_Pin GPIO_PIN_5
#define ADC1_IN15_LEFTARM_AXIS_Y_GPIO_Port GPIOC
#define ADC1_IN9_RIGHTARM_AXIS_X_Pin GPIO_PIN_1
#define ADC1_IN9_RIGHTARM_AXIS_X_GPIO_Port GPIOB
#define DYH_GPIO2_Pin GPIO_PIN_13
#define DYH_GPIO2_GPIO_Port GPIOF
#define DYH_GPIO3_Pin GPIO_PIN_14
#define DYH_GPIO3_GPIO_Port GPIOF
#define DYH_GPIO4_Pin GPIO_PIN_15
#define DYH_GPIO4_GPIO_Port GPIOF
#define DYH_GPIO5_Pin GPIO_PIN_0
#define DYH_GPIO5_GPIO_Port GPIOG
#define DYH_GPIO6_Pin GPIO_PIN_1
#define DYH_GPIO6_GPIO_Port GPIOG
#define DYH_GPIO7_Pin GPIO_PIN_7
#define DYH_GPIO7_GPIO_Port GPIOE
#define DYH_BUSY_INPUT_Pin GPIO_PIN_8
#define DYH_BUSY_INPUT_GPIO_Port GPIOE
#define TIM1_CH1_BUZZER_Pin GPIO_PIN_9
#define TIM1_CH1_BUZZER_GPIO_Port GPIOE
#define TIM1_CH2_RGB_RED_Pin GPIO_PIN_11
#define TIM1_CH2_RGB_RED_GPIO_Port GPIOE
#define TIM1_CH3_RGB_BLUE_Pin GPIO_PIN_13
#define TIM1_CH3_RGB_BLUE_GPIO_Port GPIOE
#define TIM1_CH4_RGB_GREEN_Pin GPIO_PIN_14
#define TIM1_CH4_RGB_GREEN_GPIO_Port GPIOE
#define GPIO_Output_M1_S2_Pin GPIO_PIN_10
#define GPIO_Output_M1_S2_GPIO_Port GPIOD
#define GPIO_Output_M1_S1_Pin GPIO_PIN_11
#define GPIO_Output_M1_S1_GPIO_Port GPIOD
#define GPIO_Output_M1_S0_Pin GPIO_PIN_12
#define GPIO_Output_M1_S0_GPIO_Port GPIOD
#define GPIO_Output_M0_S2_Pin GPIO_PIN_13
#define GPIO_Output_M0_S2_GPIO_Port GPIOD
#define GPIO_Output_M0_S1_Pin GPIO_PIN_14
#define GPIO_Output_M0_S1_GPIO_Port GPIOD
#define GPIO_Output_M0_S0_Pin GPIO_PIN_15
#define GPIO_Output_M0_S0_GPIO_Port GPIOD
#define DEBUG_SET_Pin GPIO_PIN_2
#define DEBUG_SET_GPIO_Port GPIOG
#define EXTI3_SX1262_DIO2_Pin GPIO_PIN_3
#define EXTI3_SX1262_DIO2_GPIO_Port GPIOG
#define EXTI3_SX1262_DIO2_EXTI_IRQn EXTI3_IRQn
#define EXTI4_SX1262_DIO1_Pin GPIO_PIN_4
#define EXTI4_SX1262_DIO1_GPIO_Port GPIOG
#define EXTI4_SX1262_DIO1_EXTI_IRQn EXTI4_IRQn
#define GPIO_SX1262_TXEN_Pin GPIO_PIN_5
#define GPIO_SX1262_TXEN_GPIO_Port GPIOG
#define GPIO_SX1262_RXEN_Pin GPIO_PIN_6
#define GPIO_SX1262_RXEN_GPIO_Port GPIOG
#define SX1262_BUSY_INPUT_Pin GPIO_PIN_7
#define SX1262_BUSY_INPUT_GPIO_Port GPIOG
#define GPIO_SX1262_RESET_Pin GPIO_PIN_8
#define GPIO_SX1262_RESET_GPIO_Port GPIOG
#define EXTI7_MPU6050_GYRO2_Pin GPIO_PIN_7
#define EXTI7_MPU6050_GYRO2_GPIO_Port GPIOC
#define EXTI7_MPU6050_GYRO2_EXTI_IRQn EXTI9_5_IRQn
#define GPIO_MPU6050_GYRO2_AD0_Pin GPIO_PIN_8
#define GPIO_MPU6050_GYRO2_AD0_GPIO_Port GPIOC
#define DYH_UART4_RX_GPIO1_Pin GPIO_PIN_11
#define DYH_UART4_RX_GPIO1_GPIO_Port GPIOC
#define DEBUG_UART5_TX_Pin GPIO_PIN_12
#define DEBUG_UART5_TX_GPIO_Port GPIOC
#define EXTI0_IGN_KEY_Pin GPIO_PIN_0
#define EXTI0_IGN_KEY_GPIO_Port GPIOD
#define EXTI0_IGN_KEY_EXTI_IRQn EXTI0_IRQn
#define DEBUG_UART5_RX_Pin GPIO_PIN_2
#define DEBUG_UART5_RX_GPIO_Port GPIOD
#define GPIO_Output_LED_DRIVER_RESET_Pin GPIO_PIN_7
#define GPIO_Output_LED_DRIVER_RESET_GPIO_Port GPIOD
#define EXTI9_MPU6050_GYRO1_Pin GPIO_PIN_9
#define EXTI9_MPU6050_GYRO1_GPIO_Port GPIOG
#define EXTI9_MPU6050_GYRO1_EXTI_IRQn EXTI9_5_IRQn
#define GPIO_MPU6050_GYRO1_AD0_Pin GPIO_PIN_10
#define GPIO_MPU6050_GYRO1_AD0_GPIO_Port GPIOG
#define EXT11_MPU5060_GYRORIGHT_Pin GPIO_PIN_11
#define EXT11_MPU5060_GYRORIGHT_GPIO_Port GPIOG
#define EXT11_MPU5060_GYRORIGHT_EXTI_IRQn EXTI15_10_IRQn
#define GPIO_MPU6050_GYRORIGHT_AD0_Pin GPIO_PIN_12
#define GPIO_MPU6050_GYRORIGHT_AD0_GPIO_Port GPIOG
#define EXTI13_MPU6050_GYROLEFT_Pin GPIO_PIN_13
#define EXTI13_MPU6050_GYROLEFT_GPIO_Port GPIOG
#define EXTI13_MPU6050_GYROLEFT_EXTI_IRQn EXTI15_10_IRQn
#define GPIO_MPU6050_GYROLEFT_Pin GPIO_PIN_14
#define GPIO_MPU6050_GYROLEFT_GPIO_Port GPIOG
#define EXTI8_RIGHTARM_Pin GPIO_PIN_8
#define EXTI8_RIGHTARM_GPIO_Port GPIOB
#define EXTI8_RIGHTARM_EXTI_IRQn EXTI9_5_IRQn
#define GPIO_LEFTARM_INPUT_Pin GPIO_PIN_9
#define GPIO_LEFTARM_INPUT_GPIO_Port GPIOB
#define FRONT_LAMP_Pin GPIO_PIN_0
#define FRONT_LAMP_GPIO_Port GPIOE
#define BACK_LAMP_Pin GPIO_PIN_1
#define BACK_LAMP_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

#define		DEBUG_UART		huart5

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
