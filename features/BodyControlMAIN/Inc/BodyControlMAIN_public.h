/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    BodyControlMAIN_public.h
  * @author	 Atakan ERTEKiN,Ömer Faruk USLU
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil CAN Stack
********************************************************************************/

#ifndef __BODYCONTROL_MAIN_PUBLIC_H__
#define	__BODYCONTROL_MAIN_PUBLIC_H__

	
	
/*********************** INCLUDES **********************************************/

#include "BodyControlMAIN_definition.h"


/*********************** DEFINES ***********************************************/


	
	
/********************** FUNCTION PROTOTYPE **************************************/	

extern EEM_Protocol_st	protocol;

extern void 			BodyControlMAIN_StartUP	( void );
extern void 			BodyControlMAIN			( void );
	
	
	
#endif /*__BODYCONTROL_MAIN_PUBLIC_H__ */	

/*********************** END OF FILE ********************************************/
















































