/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleFLASH_private.h
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM FLASH Module
********************************************************************************/

#ifndef __FLASH_MODULE_PRIVATE_H__
#define	__FLASH_MODULE_PRIVATE_H__

	
	
/*********************** INCLUDES **********************************************/

#include "ModuleFLASH_definition.h"

#include "BodyControlMAIN_public.h"
#include "ModuleADC_public.h"
#include "ModuleAUDIO_public.h"
#include "ModuleCAN_public.h"
#include "ModuleCONTROL_public.h"
//#include "ModuleFLASH_public.h"
#include "ModulePOWERSWITCH_public.h"
#include "ModuleRTC_public.h"
#include "ModuleSDCARD_public.h"
#include "ModuleTELEMETRY_public.h"


/*********************** DEFINES ***********************************************/

	
/********************** FUNCTION PROTOTYPE **************************************/	
	
 void ModuleFLASH_HWInit(void);
 void ModuleFLASH_SWInit(void);
 void ModuleFLASH_MAIN_Process(void);
 void ModuleFLASH_MAIN_Routine(void);

 //@INFO: Public function, private decleration
 void ModuleFLASH_StartUP(void);
 void ModuleFLASH_MAIN(void);
	
	
	
	
#endif /*__CAN_MODULE_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































