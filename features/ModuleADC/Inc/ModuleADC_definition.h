/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleADC_definition.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM ADC Module
********************************************************************************/

#ifndef __ADC_MODULE_DEFINITION_H__
#define	__ADC_MODULE_DEFINITION_H__

	
	
/*********************** INCLUDES **********************************************/
#include "types.h"
#include "main.h"


/*********************** DEFINES ***********************************************/

	/* Analog Mux Definitions for BCM_BIG										  */
	#define AN_MUX_S0_SET()     HAL_GPIO_WritePin(GPIO_Output_M0_S0_GPIO_Port, GPIO_Output_M0_S0_Pin, GPIO_PIN_SET)
	#define AN_MUX_S0_RESET()   HAL_GPIO_WritePin(GPIO_Output_M0_S0_GPIO_Port, GPIO_Output_M0_S0_Pin, GPIO_PIN_RESET)
	#define AN_MUX_S1_SET()     HAL_GPIO_WritePin(GPIO_Output_M0_S1_GPIO_Port, GPIO_Output_M0_S1_Pin, GPIO_PIN_SET)
	#define AN_MUX_S1_RESET()   HAL_GPIO_WritePin(GPIO_Output_M0_S1_GPIO_Port, GPIO_Output_M0_S1_Pin, GPIO_PIN_RESET)
	#define AN_MUX_S2_SET()     HAL_GPIO_WritePin(GPIO_Output_M0_S2_GPIO_Port, GPIO_Output_M0_S2_Pin, GPIO_PIN_SET)
	#define AN_MUX_S2_RESET()   HAL_GPIO_WritePin(GPIO_Output_M0_S2_GPIO_Port, GPIO_Output_M0_S2_Pin, GPIO_PIN_RESET)

	#define A0_MUX_SET()    AN_MUX_S2_RESET(); AN_MUX_S1_RESET(); AN_MUX_S0_RESET(); /* 000 */
	#define A1_MUX_SET()    AN_MUX_S2_RESET(); AN_MUX_S1_RESET(); AN_MUX_S0_SET();   /* 001 */
	#define A2_MUX_SET()    AN_MUX_S2_RESET(); AN_MUX_S1_SET();   AN_MUX_S0_RESET(); /* 010 */
	#define A3_MUX_SET()    AN_MUX_S2_RESET(); AN_MUX_S1_SET();   AN_MUX_S0_SET();   /* 011 */
	#define A4_MUX_SET()    AN_MUX_S2_SET();   AN_MUX_S1_RESET(); AN_MUX_S0_RESET(); /* 100 */
	#define A5_MUX_SET()    AN_MUX_S2_SET();   AN_MUX_S1_RESET(); AN_MUX_S0_SET();   /* 101 */
	#define A6_MUX_SET()    AN_MUX_S2_SET();   AN_MUX_S1_SET();   AN_MUX_S0_RESET(); /* 110 */
	#define A7_MUX_SET()    AN_MUX_S2_RESET(); AN_MUX_S1_RESET(); AN_MUX_S0_RESET(); /* 111 */

	/* Analog Multiplexer Selection									                         */
	#define PROCESS_ANALOGSIGNALS_AN_MUX1				0x1
	#define PROCESS_ANALOGSIGNALS_AN_MUX2				0x2
	/* ACS712 POWER Selection									*/
	#define PROCESS_ANALOGSIGNALS_AN_VIN				0x3
	#define PROCESS_ANALOGSIGNALS_AN_ACS_5V				0x4
	#define PROCESS_ANALOGSIGNALS_AN_ACS_12V			0x5
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VMCU			0x6
	#define PROCESS_ANALOGSIGNALS_AN_ACS_3V3			0x7
	/* ACS712 DRIVER Selection									*/
	#define PROCESS_ANALOGSIGNALS_AN_ACS_FL				0x8
	#define PROCESS_ANALOGSIGNALS_AN_ACS_BL				0x9
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VINL1			0x10
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VINL2			0x11
	#define PROCESS_ANALOGSIGNALS_AN_ACS_BINL			0x12
	#define PROCESS_ANALOGSIGNALS_AN_ACS_STOP			0x13
	#define PROCESS_ANALOGSIGNALS_AN_ACS_RS				0x14
	#define PROCESS_ANALOGSIGNALS_AN_ACS_LS				0x15
	/* GPIO DRIVER Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_RS_VRx				0x16
	#define PROCESS_ANALOGSIGNALS_AN_RS_VRy				0x17
	#define PROCESS_ANALOGSIGNALS_AN_LS_VRx				0x18
	#define PROCESS_ANALOGSIGNALS_AN_LS_VRy				0x19
	#define PROCESS_ANALOGSIGNALS_AN_DIREKSIYON			0x20
	#define PROCESS_ANALOGSIGNALS_AN_FREN				0x21
	#define PROCESS_ANALOGSIGNALS_AN_GAZ				0x22

	/* Analog Multiplexer ADC Handler Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_MUX1_HANDLE        hadc3        /*PC0 */
	#define PROCESS_ANALOGSIGNALS_AN_MUX2_HANDLE        hadc3        /*PC1 */
	/* ACS712 POWER ADC Handler Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_VIN_HANDLE			hadc3		 /*PC4 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_5V_HANDLE		hadc3		 /*PC4 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_12V_HANDLE		hadc3		 /*PC5 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VMCU_HANDLE	hadc3		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_3V3_HANDLE		hadc3		 /*PB1 */
	/* ACS712 DRIVER ADC Handler Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_FL_HANDLE		hadc3		 /*PC4 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_BL_HANDLE		hadc3		 /*PC5 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VINL1_HANDLE	hadc3		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VINL2_HANDLE	hadc3		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_BINL_HANDLE	hadc3		 /*PC4 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_STOP_HANDLE	hadc3		 /*PC5 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_RS_HANDLE		hadc3		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_LS_HANDLE		hadc3		 /*PB1 */
	/* GPIO DRIVER ADC Handler Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_RS_VRx_HANDLE		hadc1		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_RS_VRy_HANDLE		hadc1		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_LS_VRx_HANDLE		hadc1		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_LS_VRy_HANDLE		hadc1		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_DIREKSIYON_HANDLE	hadc1		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_FREN_HANDLE		hadc1		 /*PB1 */
	#define PROCESS_ANALOGSIGNALS_AN_GAZ_HANDLE			hadc1		 /*PB1 */


	/* Analog Multiplexer ADC Channel Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_MUX1_CHANNEL       ADC_CHANNEL_13       /* ADC3	- AN_MUX1  */
	#define PROCESS_ANALOGSIGNALS_AN_MUX2_CHANNEL       ADC_CHANNEL_14       /* ADC3	- AN_MUX2  */
	/* ACS712 POWER ADC Channel Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_VIN_CHANNEL		ADC_CHANNEL_15		 /* ADC3	- VOLTAGE_IN  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_5V_CHANNEL		ADC_CHANNEL_9		 /* ADC3	- CURRENT_5V  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_12V_CHANNEL	ADC_CHANNEL_10		 /* ADC3	- CURRENT_12V   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VMCU_CHANNEL	ADC_CHANNEL_11		 /* ADC3	- CURRENT_VMCU   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_3V3_CHANNEL	ADC_CHANNEL_12		 /* ADC3	- CURRENT_3V3   */
	/* ACS712 DRIVER ADC Channel Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_FL_CHANNEL		ADC_CHANNEL_1		 /* ADC3	- CURRENT_FRONT_LAMB   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_BL_CHANNEL		ADC_CHANNEL_2		 /* ADC3	- CURRENT_BACK_LAMB   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VINL1_CHANNEL	ADC_CHANNEL_3		 /* ADC3	- CURRENT_VEHICLE_IN_LAMB1   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VINL2_CHANNEL	ADC_CHANNEL_4		 /* ADC3	- CURRENT_VEHICLE_IN_LAMB2   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_BINL_CHANNEL	ADC_CHANNEL_5		 /* ADC3	- CURRENT_BAGGET_IN_LAMB   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_STOP_CHANNEL	ADC_CHANNEL_5		 /* ADC3	- CURRENT_STOP_LAMB   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_RS_CHANNEL		ADC_CHANNEL_7		 /* ADC3	- CURRENT_RIGHT_SIGNAL   */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_LS_CHANNEL		ADC_CHANNEL_8		 /* ADC3	- CURRENT_LEFT_SIGNAL   */
	/* GPIO DRIVER ADC Channel Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_RS_VRx_CHANNEL		ADC_CHANNEL_9		 /* ADC1	- JOYSTICK_RIGTH_SIGNAL_VRx   */
	#define PROCESS_ANALOGSIGNALS_AN_RS_VRy_CHANNEL		ADC_CHANNEL_7		 /* ADC1	- JOYSTICK_RIGTH_SIGNAL_VRy   */
	#define PROCESS_ANALOGSIGNALS_AN_LS_VRx_CHANNEL		ADC_CHANNEL_14		 /* ADC1	- JOYSTICK_LEFT_SIGNAL_VRx   */
	#define PROCESS_ANALOGSIGNALS_AN_LS_VRy_CHANNEL		ADC_CHANNEL_15		 /* ADC1	- JOYSTICK_LEFT_SIGNAL_VRY   */
	#define PROCESS_ANALOGSIGNALS_AN_DIREKSIYON_CHANNEL	ADC_CHANNEL_5		 /* ADC1	- DIREKSIYON   */
	#define PROCESS_ANALOGSIGNALS_AN_FREN_CHANNEL		ADC_CHANNEL_4		 /* ADC1	- FREN   */
	#define PROCESS_ANALOGSIGNALS_AN_GAZ_CHANNEL		ADC_CHANNEL_6		 /* ADC1	- GAZ   */


	/* Analog Multiplexer ADC Rank Selection									  */
	/* @INFO: All ADC Ranks are same because adc working with re-init mode		  */
	#define PROCESS_ANALOGSIGNALS_AN_MUX1_RANK       	0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_MUX2_RANK       	0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_VIN_RANK		 	0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_5V_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_12V_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VMCU_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_3V3_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_FL_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_BL_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VINL1_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_VINL2_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_BINL_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_STOP_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_RS_RANK		0x3             /* ADC3	  */
	#define PROCESS_ANALOGSIGNALS_AN_ACS_LS_RANK		0x3             /* ADC3	  */
	/* GPIO DRIVER ADC Rank Selection									 */
	#define PROCESS_ANALOGSIGNALS_AN_RS_VRx_RANK		0x1             /* ADC1	  */
	#define PROCESS_ANALOGSIGNALS_AN_RS_VRy_RANK		0x1             /* ADC1	  */
	#define PROCESS_ANALOGSIGNALS_AN_LS_VRx_RANK		0x1             /* ADC1	  */
	#define PROCESS_ANALOGSIGNALS_AN_LS_VRy_RANK		0x1             /* ADC1	  */
	#define PROCESS_ANALOGSIGNALS_AN_DIREKSIYON_RANK	0x1             /* ADC1	  */
	#define PROCESS_ANALOGSIGNALS_AN_FREN_RANK			0x1             /* ADC1	  */
	#define PROCESS_ANALOGSIGNALS_AN_GAZ_RANK			0x1             /* ADC1	  */

	/* Analog Mux Multiplexer Pin Select										  */
	#define PROCESS_ANALOGSIGNALS_SELECT_NULL           0xff
	#define PROCESS_ANALOGSIGNALS_SELECT_PIN0           0x0
	#define PROCESS_ANALOGSIGNALS_SELECT_PIN1           0x1
	#define PROCESS_ANALOGSIGNALS_SELECT_PIN2           0x2
	#define PROCESS_ANALOGSIGNALS_SELECT_PIN3           0x3
	#define PROCESS_ANALOGSIGNALS_SELECT_PIN4           0x4
	#define PROCESS_ANALOGSIGNALS_SELECT_PIN5           0x5
	#define PROCESS_ANALOGSIGNALS_SELECT_PIN6           0x6
	#define PROCESS_ANALOGSIGNALS_SELECT_PIN7           0x7


typedef enum
{
	ModuleADC_MAIN_State_IDLE = 0,
	ModuleADC_MAIN_State_ROUTINE ,
	ModuleADC_MAIN_State_PROCESS ,
	ModuleADC_MAIN_State_SUSPEND ,

}ModuleADC_MAIN_State_et;
	
	
/********************** FUNCTION PROTOTYPE **************************************/	
	

	
	
	
	
#endif /*__ADC_MODULE_DEFINITION_H__ */	

/*********************** END OF FILE ********************************************/
















































