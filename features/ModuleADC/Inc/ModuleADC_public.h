/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleADC_public.h
  * @author	 Atakan ERTEKiN,
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM ADC Module
********************************************************************************/

#ifndef __ADC_MODULE_PUBLIC_H__
#define	__ADC_MODULE_PUBLIC_H__

	
	
/*********************** INCLUDES **********************************************/

#include "ModuleADC_definition.h"

/*********************** DEFINES ***********************************************/


/*********************** VARIABLE PROTOTYPE *************************************/
extern Adc_Type adcModule;


/********************** FUNCTION PROTOTYPE **************************************/	
	

//@INFO: extern public functions
extern void ModuleADC_StartUP(void);
extern void ModuleADC_MAIN(void);

 extern U16 getWheelAngle(adc_st* analogHandle);
 extern U16 getBrakeParam(adc_st* analogHandle);
 extern U16 getGasParam(adc_st* analogHandle);

 extern void setMotorSpeed1( BCM_Module_st* BCM_MS1_SpeedHandle , adc_st* analogHandle);

	
	
#endif /*__ADC_MODULE_PUBLIC_H__ */	

/*********************** END OF FILE ********************************************/
















































