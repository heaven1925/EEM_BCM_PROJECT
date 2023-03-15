/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModulePOWERSWITCH_private.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM POWERSWITCH Module
********************************************************************************/

#ifndef __POWERSWITCH_MODULE_PRIVATE_H__
#define	__POWERSWITCH_MODULE_PRIVATE_H__

	
	
/*********************** INCLUDES **********************************************/

#include "ModulePOWERSWITCH_definition.h"

#include "BodyControlMAIN_public.h"
#include "ModuleADC_public.h"
#include "ModuleAUDIO_public.h"
#include "ModuleCAN_public.h"
#include "ModuleCONTROL_public.h"
#include "ModuleFLASH_public.h"
//#include "ModulePOWERSWITCH_public.h"
#include "ModuleRTC_public.h"
#include "ModuleSDCARD_public.h"
#include "ModuleTELEMETRY_public.h"

/*********************** DEFINES ***********************************************/


	
	
/********************** FUNCTION PROTOTYPE **************************************/	
	
 void ModulePOWERSWITCH_HWInit(void);
 void ModulePOWERSWITCH_SWInit(void);
 void ModulePOWERSWITCH_MAIN_Process(void);
 void ModulePOWERSWITCH_MAIN_Routine(void);

 //@INFO: Public function, private decleration
 void ModulePOWERSWITCH_StartUP(void);
 void ModulePOWERSWITCH_MAIN(void);
	
	
	
	
#endif /*__POWERSWITCH_MODULE_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































