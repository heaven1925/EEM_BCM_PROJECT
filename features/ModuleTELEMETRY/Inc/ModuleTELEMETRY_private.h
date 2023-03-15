/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleTELEMETRY_private.h
  * @author	 Atakan ERTEKiN,Ömer Faruk USLU
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM TELEMETRY Module
********************************************************************************/

#ifndef __TELEMETRY_MODULE_PRIVATE_H__
#define	__TELEMETRY_MODULE_PRIVATE_H__

	
	
/*********************** INCLUDES **********************************************/

#include "ModuleTELEMETRY_definition.h"

#include "BodyControlMAIN_public.h"
#include "ModuleADC_public.h"
#include "ModuleAUDIO_public.h"
#include "ModuleCAN_public.h"
#include "ModuleCONTROL_public.h"
#include "ModuleFLASH_public.h"
#include "ModulePOWERSWITCH_public.h"
#include "ModuleRTC_public.h"
#include "ModuleSDCARD_public.h"
//#include "ModuleTELEMETRY_public.h"

/*********************** DEFINES ***********************************************/


	
	
/********************** FUNCTION PROTOTYPE **************************************/	
	
 void ModuleTELEMETRY_HWInit(void);
 void ModuleTELEMETRY_SWInit(void);
 void ModuleTELEMETRY_MAIN_Process(void);
 void ModuleTELEMETRY_MAIN_Routine(void);

 //@INFO: Public function, private decleration
 void ModuleTELEMETRY_StartUP(void);
 void ModuleTELEMETRY_MAIN(void);
	
	
	
	
#endif /*__TELEMETRY_MODULE_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































