/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleCAN_private.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM AUDIO Module 
********************************************************************************/

#ifndef __AUDIO_MODULE_PRIVATE_H__
#define	__AUDIO_MODULE_PRIVATE_H__

	
	
/*********************** INCLUDES **********************************************/

#include "ModuleAUDIO_definition.h"

#include "BodyControlMAIN_public.h"
#include "ModuleADC_public.h"
//#include "ModuleAUDIO_public.h"
#include "ModuleCAN_public.h"
#include "ModuleCONTROL_public.h"
#include "ModuleFLASH_public.h"
#include "ModulePOWERSWITCH_public.h"
#include "ModuleRTC_public.h"
#include "ModuleSDCARD_public.h"
#include "ModuleTELEMETRY_public.h"


/*********************** DEFINES ***********************************************/


	
	
/********************** FUNCTION PROTOTYPE **************************************/	
	
 void ModuleAUDIO_HWInit(void);
 void ModuleAUDIO_SWInit(void);
 void ModuleAUDIO_MAIN_Process(void);
 void ModuleAUDIO_MAIN_Routine(void);

 //@INFO: Public function, private decleration
 void ModuleAUDIO_StartUP(void);
 void ModuleAUDIO_MAIN(void);
	
	
	
	
#endif /*__AUDIO_MODULE_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































