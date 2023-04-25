/*******************************************************************************
  * @file    types.h
  * @author	 Atakan ERTEKiN,Ömer Faruk USLU
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil Main variables & types
********************************************************************************/

#ifndef INC_TYPES_H_
#define INC_TYPES_H_

#include <stdbool.h>
#include <ctype.h>
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#include "cmsis_os.h"
#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"

#include "EEMProtocol.h"
#include "EEMProtocol_Config.h"

#define BIT_SET(addr, shift) 	(addr | (1 << shift))
#define BIT_RESET(addr, shift) 	(addr & ~(1 << shift))
#define BIT_GET(addr, shift) 	(addr & (1 << shift))

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

#define DEBUG_MSG_SIZE  6

#define is_not                          !=
#define is                              ==
#define and                             &&
#define or                              ||

typedef     uint8_t        U8;
typedef     int8_t         S8;
typedef     uint16_t       U16;
typedef     int16_t        S16;
typedef     uint32_t       U32;
typedef     int32_t        S32;

typedef		U32			  DUMMY;  /* Used only dummy union-struct */

typedef enum {
	FALSE  = 0x0,
	TRUE   = !FALSE
}BOOL;

typedef union
{
	U32 U32;
    struct
    {
		U8 byte0;
		U8 byte1 ;
		U8 byte2 ;
		U8 byte3 ;
    } Byte;
}U32Union;

//]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

#define	ITC_UT_BYTE_SIZE	2	/* Inner-Thread Communication Bits */
typedef union{
	U16	itcFlags;
	struct{
		BOOL adc 			: 1 ;
		BOOL audio 			: 1 ;
		BOOL can 			: 1 ;
		BOOL control 		: 1 ;
		BOOL flash 			: 1 ;
		BOOL powerswitch 	: 1 ;
		BOOL rtc 			: 1 ;
		BOOL sdcard 		: 1 ;
		BOOL telemetry 		: 1 ;
		DUMMY:7;
	}__packed flag;
}__packed itc_ut;

// [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

#define		MAIN_PACKEDSIZE				0x100
typedef struct __packed{
	U8 dummy[MAIN_PACKEDSIZE];			//@INFO: 256 Byte
}main_st;

#define		ADC_PACKEDSIZE				0x100	-\
/*	U16 x 33 ADC_VALUES;	*/			66
typedef struct __packed{

		/* MUX-1 VARIABLES */
	    U16 VOLTAGE_3V3   ; /* A0 VARIABLE */
	    U16 VOLTAGE_VMCU; /* A1 VARIABLE */
	    U16 VOLTAGE_5V    ; /* A2 VARIABLE */
	    U16 VOLTAGE_12V   ; /* A3 VARIABLE */
	    U16 VOLTAGE_24V   ; /* A4 VARIABLE */
	   // U16 EMPTY   ; 	/* A5 VARIABLE */
	   // U16 EMPTY   ; 	/* A6 VARIABLE */
	   // U16 EMPTY   ; 	/* A7 VARIABLE */
	    /* MUX-2 VARIABLES */
	    U16 A0_IN0		  ; /* A0 VARIABLE */
	    U16 A0_IN1		  ; /* A1 VARIABLE */
	    U16 A0_IN2		  ; /* A2 VARIABLE */
	    U16 A0_IN3		  ; /* A3 VARIABLE */
	    U16 A0_IN4	 	  ; /* A4 VARIABLE */
	    U16 A0_IN5	   	  ; /* A5 VARIABLE */
	    U16 A0_IN6	 	  ; /* A6 VARIABLE */
	    U16 A0_IN7	  	  ; /* A7 VARIABLE */
	    /* OTHER CHANNEL VARIABLES */
	 	U16 VIN			;
	    U16 ACS_5V		;
 	    U16 ACS_12V		;
 	    U16 ACS_VMCU	;
	    U16 ACS_3V3		;
 	    U16 ACS_FL		;
	    U16 ACS_BL		;
	    U16 ACS_VINL1	;
	    U16 ACS_VINL2	;
	    U16 ACS_BINL	;
 	    U16 ACS_STOP	;
 	    U16 ACS_RS		;
 	    U16 ACS_LS		;
 	    U16 RS_VRx		;
	    U16 RS_VRy		;
	    U16 LS_VRx		;
 	    U16 LS_VRy		;
	    U16 MotorDrive  ; /*WheelAngle	; */
	    U16 Brake		;
	    U16 Gas			;


	U8 dummy[ADC_PACKEDSIZE];			//@INFO: 256 Byte
}adc_st;

#define		AUDIO_PACKEDSIZE			0x100
typedef struct __packed{
	U8 dummy[AUDIO_PACKEDSIZE];			//@INFO: 256 Byte
}audio_st;

#define		CAN_PACKEDSIZE			0x100		-\
/*	U32	msgTickCounter_u32;	*/			4		-\
/*	Union-Struct messsageID	*/			1

typedef struct __packed{

	U32	msgTickCounter_u32;

	union __packed{  U8 messsageID;
		struct __packed {
			BOOL ID01 : 1 ;
			BOOL ID02 : 1 ;
			BOOL ID03 : 1 ;
			BOOL ID04 : 1 ;
			BOOL ID05 : 1 ;
			BOOL ID06 : 1 ;
			BOOL ID07 : 1 ;
			BOOL ID08 : 1 ;
		}Flag;
	}msgSelect;

	//--------------------------------------> 4 Byte Until Here

	U8  dummy[CAN_PACKEDSIZE];		//@INFO: 256 Byte
}can_st;

#define		CONTROL_PACKEDSIZE			0x100
typedef struct __packed{
	U8 dummy[CONTROL_PACKEDSIZE];		//@INFO: 256 Byte
}control_st;

#define		FLASH_PACKEDSIZE			0x100
typedef struct __packed{
	U8 dummy[FLASH_PACKEDSIZE];			//@INFO: 256 Byte
}flash_st;

#define		POWERSWITCH_PACKEDSIZE		0x100
typedef struct __packed{
	U8 dummy[POWERSWITCH_PACKEDSIZE]; 	//@INFO: 256 Byte
}powerswitch_st;

#define		RTC_PACKEDSIZE				0x100
typedef struct __packed{
	U8 dummy[RTC_PACKEDSIZE];			//@INFO: 256 Byte
}rtc_st;

#define		SDCARD_PACKEDSIZE			0x100
typedef struct __packed{
	U8 dummy[SDCARD_PACKEDSIZE];		//@INFO: 256 Byte
}sdcard_st;

#define		TELEMETRY_PACKEDSIZE		0x100
typedef struct __packed{
	U8 dummy[TELEMETRY_PACKEDSIZE];		//@INFO: 256 Byte
}telemetry_st;



#define		GLSTRUCT_PACKEDSIZE		0x1000						- \
/* 256 Byte */						MAIN_PACKEDSIZE     		- \
/* 256 Byte */						ADC_PACKEDSIZE    			- \
/* 256 Byte */						AUDIO_PACKEDSIZE      		- \
/* 256 Byte */						CAN_PACKEDSIZE      		- \
/* 256 Byte */						CONTROL_PACKEDSIZE      	- \
/* 256 Byte */						FLASH_PACKEDSIZE   			- \
/* 256 Byte */						POWERSWITCH_PACKEDSIZE      - \
/* 256 Byte */						RTC_PACKEDSIZE     			- \
/* 256 Byte */						SDCARD_PACKEDSIZE    		- \
/* 256 Byte */						TELEMETRY_PACKEDSIZE      	/* ---> 2816 Byte until here */ - \
/* itc_ut itc  : 1 Byte */			ITC_UT_BYTE_SIZE



typedef struct
{
	main_st 		main;
	/***************************/
	adc_st			adc;
	audio_st		audio;
	can_st			can;
	control_st		control;
	flash_st		flash;
	powerswitch_st 	powerswitch;
	rtc_st			rtc;
	sdcard_st		sdcard;
	telemetry_st	telemetry;
	/***************************/
	itc_ut			itc;
	itc_ut			mainState;
	/***************************/

	U8 dummy[ GLSTRUCT_PACKEDSIZE ]; //@INFO: Total 4Kbyte - Others
}GL_st;
// ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

extern GL_st __GL;	//@INFO: attribute assigned at application.c

extern	ADC_HandleTypeDef 	hadc1;
extern	ADC_HandleTypeDef 	hadc3;

extern	CAN_HandleTypeDef 	hcan1;
extern	CAN_HandleTypeDef 	hcan2;
extern	CRC_HandleTypeDef 	hcrc;

extern	I2C_HandleTypeDef 	hi2c1;
extern	I2C_HandleTypeDef 	hi2c2;
extern	I2C_HandleTypeDef 	hi2c3;

extern	WWDG_HandleTypeDef 	hiwdg;

extern	RTC_HandleTypeDef 	hrtc;

extern 	SPI_HandleTypeDef 	hspi2;
extern 	SPI_HandleTypeDef 	hspi3;

extern 	TIM_HandleTypeDef 	htim1;

extern 	UART_HandleTypeDef 	huart4;
extern 	UART_HandleTypeDef 	huart5;

extern 	WWDG_HandleTypeDef 	hwwdg;


#endif /* INC_TYPES_H_ */
