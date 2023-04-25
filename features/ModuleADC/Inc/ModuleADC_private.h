/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleADC_private.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM ADC Module
********************************************************************************/

#ifndef __ADC_MODULE_PRIVATE_H__
#define	__ADC_MODULE_PRIVATE_H__

	
	
/*********************** INCLUDES **********************************************/

#include "ModuleADC_definition.h"

#include "BodyControlMAIN_public.h"
//#include "ModuleADC_public.h"
#include "ModuleAUDIO_public.h"
#include "ModuleCAN_public.h"
#include "ModuleCONTROL_public.h"
#include "ModuleFLASH_public.h"
#include "ModulePOWERSWITCH_public.h"
#include "ModuleRTC_public.h"
#include "ModuleSDCARD_public.h"
#include "ModuleTELEMETRY_public.h"

/*********************** DEFINES ***********************************************/

/* Main Class Create */
Adc_Type adcModule = {0};

/********************** FUNCTION PROTOTYPE **************************************/	
	
 void ModuleADC_HWInit(void);
 void ModuleADC_SWInit(void);
 void ModuleADC_MAIN_Process(void);
 void ModuleADC_MAIN_Routine(void);

 //@INFO: Private Function Decleration
 void ModuleADC_StartUP(void);
 void ModuleADC_MAIN(void);

 void ModuleADC_CTOR(Adc_Type* param , adc_st* _obj );

 U32 Process_AnalogSignals_ReadChannel(U8 MUX_SELECT, U8 SELECT_PIN);


 EEM_U16 calculateMotorSpeedLeft(adc_st* analogHandle);
 EEM_U16 calculateMotorSpeedRight(adc_st* analogHandle);
 DirectionMode_Type getMotorDirection(adc_st* analogHandle);

 //@INFO: Public Function Decleration
 U16 getWheelAngle(adc_st* analogHandle);
 U16 getBrakeParam(adc_st* analogHandle);
 U16 getGasParam(adc_st* analogHandle);

 void setMotorSpeed1  ( BCM_Module_st* BCM_MS1_SpeedHandle , adc_st* analogHandle);
 void setAnalogSignals( BCM_Module_st* BCM_MS1_ModeHandle , adc_st* analogHandle);


#endif /*__ADC_MODULE_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































