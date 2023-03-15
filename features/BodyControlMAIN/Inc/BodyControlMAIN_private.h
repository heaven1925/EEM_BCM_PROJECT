/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    BodyControlMAIN_private.h
  * @author	 Atakan ERTEKiN 
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil CAN Stack
********************************************************************************/

#ifndef __BODYCONTROL_MAIN_PRIVATE_H__
#define	__BODYCONTROL_MAIN_PRIVATE_H__

	
	
/*********************** INCLUDES **********************************************/

#include "app.h"

#include "BodyControlMAIN_definition.h"

//#include "BodyControlMAIN_public.h"
#include "ModuleADC_public.h"
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

EEM_Protocol_st	protocol;
	
 void BodyControlMAIN_HWInit(void);
 void BodyControlMAIN_SWInit(void);
 void BodyControlMAIN_Process(void);
 void BodyControlMAIN_Routine(void);

 //@INFO: Public function, private decleration
 void BodyControlMAIN_StartUP(void);
 void BodyControlMAIN(void);
	
	
	
	
#endif /*__BODYCONTROL_MAIN_PRIVATE_H__ */	

/*********************** END OF FILE ********************************************/
















































