/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleSDCARD_private.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM SDCARD MODULE
********************************************************************************/

#ifndef __SDCARD_MODULE_PRIVATE_H__
#define	__SDCARD_MODULE_PRIVATE_H__

	
	
/*********************** INCLUDES **********************************************/

#include "ModuleSDCARD_definition.h"

#include "BodyControlMAIN_public.h"
#include "ModuleADC_public.h"
#include "ModuleAUDIO_public.h"
#include "ModuleCAN_public.h"
#include "ModuleCONTROL_public.h"
#include "ModuleFLASH_public.h"
#include "ModulePOWERSWITCH_public.h"
#include "ModuleRTC_public.h"
//#include "ModuleSDCARD_public.h"
#include "ModuleTELEMETRY_public.h"

/*********************** DEFINES ***********************************************/


	
	
/********************** FUNCTION PROTOTYPE **************************************/	
	
 void ModuleSDCARD_HWInit(void);
 void ModuleSDCARD_SWInit(void);
 void ModuleSDCARD_MAIN_Process(void);
 void ModuleSDCARD_MAIN_Routine(void);

 //@INFO: Public function, private decleration
 void ModuleSDCARD_StartUP(void);
 void ModuleSDCARD_MAIN(void);
	
	
	
	
#endif /*__SDCARD_MODULE_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































