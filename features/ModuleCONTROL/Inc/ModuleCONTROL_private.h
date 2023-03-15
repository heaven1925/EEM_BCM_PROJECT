/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleCAN_private.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM Control Module
********************************************************************************/

#ifndef __CONTROL_MODULE_PRIVATE_H__
#define	__CONTROL_MODULE_PRIVATE_H__

	
	
/*********************** INCLUDES **********************************************/

#include "ModuleCONTROL_definition.h"

#include "BodyControlMAIN_public.h"
#include "ModuleADC_public.h"
#include "ModuleAUDIO_public.h"
#include "ModuleCAN_public.h"
//#include "ModuleCONTROL_public.h"
#include "ModuleFLASH_public.h"
#include "ModulePOWERSWITCH_public.h"
#include "ModuleRTC_public.h"
#include "ModuleSDCARD_public.h"
#include "ModuleTELEMETRY_public.h"

/*********************** DEFINES ***********************************************/


	
	
/********************** FUNCTION PROTOTYPE **************************************/	
	
 void ModuleCONTROL_HWInit(void);
 void ModuleCONTROL_SWInit(void);
 void ModuleCONTROL_MAIN_Process(void);
 void ModuleCONTROL_MAIN_Routine(void);

 //@INFO: Public function, private decleration
 void ModuleCONTROL_StartUP(void);
 void ModuleCONTROL_MAIN(void);
	
	
	
	
#endif /*__CONTROL_MODULE_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































