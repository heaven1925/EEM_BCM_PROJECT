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

#include "ModuleCAN_definition.h"


/*********************** DEFINES ***********************************************/
 extern void ModuleADC_StartUP(void);
 extern void ModuleADC_MAIN(void);

	
	
/********************** FUNCTION PROTOTYPE **************************************/	
	
 extern void Process_AnalogSignals_SeperateChannels(ADC_HandleTypeDef *hadc, U32 ADC_CHANNEL, U32 RANK);
 extern U32  Process_AnalogSignals_ReadChannel(U8 MUX_SELECT, U8 SELECT_PIN);
 extern void Process_AnalogSignals_GetAnalogSignals(void);

 extern adc_st adc_s;
	
	
	
#endif /*__ADC_MODULE_PUBLIC_H__ */	

/*********************** END OF FILE ********************************************/
















































