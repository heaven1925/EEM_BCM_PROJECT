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


	
	
/********************** FUNCTION PROTOTYPE **************************************/	
	
 void ModuleADC_HWInit(void);
 void ModuleADC_SWInit(void);
 void ModuleADC_MAIN_Process(void);
 void ModuleADC_MAIN_Routine(void);

 //@INFO: Public function, private decleration
 void ModuleADC_StartUP(void);
 void ModuleADC_MAIN(void);
	
	
	
	
#endif /*__ADC_MODULE_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































