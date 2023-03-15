/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    EEMProtocol.h
  * @author	 Atakan ERTEKiN,Ömer Faruk USLU
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil CAN Stack
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModuleCAN_private.h"

/************************** DEFINES ********************************************/
#define	MODULECAN_MAIN_THREAD

ModuleCAN_MAIN_State_et 	ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_IDLE;
ModuleCAN_PROCESS_State_et	ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_IDLE;

extern  BCM_Module_st	BCM_MSG;
extern  HVAC_Module_st	HVAC_MSG;
extern  SCB_Module_st	SCB_MSG;
extern  BMS_Module_st	BMS_MSG;
extern  MS1_Module_st	MS1_MSG;
extern  MS2_Module_st	MS2_MSG;
extern  ISO_Module_st	ISO_MSG;
extern  TLM_Module_st	TLM_MSG;
extern  YSB_Module_st	YSB_MSG;


#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModuleCAN_HWInit(void)
{
	/* Construction function of protocol */

	EEM_CTOR(&protocol /* Main protocol Class Construct */
	, ops /* Inherit Method Class */
#if (defined(STM32F446xx) || defined(STM32F407xx) && defined(BXCAN_Protocol))
	, &hcan1
#elif (defined(STM32H750xx) && defined(FDCAN_Protocol))
	, &fcan1
#else
/* Only works for spi2can */
#endif
	);

	/* Init protocol settings in order to 250KBps Bit Rate */
	protocol.ops.EEM_INIT(&protocol.obj);

	/* Send Test Data */
	const char testData[ EEM_MAX_SIZE ] = { 0xEE , 0x00 , 0xEE , 0x00 , 0xEE , 0x00 , 0xEE , 0x00 };
	memcpy(&protocol.obj.canPacket.DATA[0] , &testData[0] , 8);
	protocol.obj.canPacket.EXTENDED_ID.identifier = 0x1CFFFFFF;
	protocol.ops.EEM_TX( &protocol.obj.canPacket , 0);
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleCAN_SWInit(void)
{
	__GL.can.msgTickCounter_u32 = 0 ;

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleCAN_StartUP(void)
{
	ModuleCAN_HWInit();
	ModuleCAN_SWInit();

}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULECAN_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleCAN_MAIN_Routine(void)
{
	if( TRUE == __GL.can.msgSelect.Flag.ID01 )
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_PROCESS;
		ModuleCAN_PROCESS_State	= ModuleCAN_PROCESS_State_MSG01;
	}
	else if( TRUE == __GL.can.msgSelect.Flag.ID02 )
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_PROCESS;
		ModuleCAN_PROCESS_State	= ModuleCAN_PROCESS_State_MSG02;
	}
	else if( TRUE == __GL.can.msgSelect.Flag.ID03 )
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_PROCESS;
		ModuleCAN_PROCESS_State	= ModuleCAN_PROCESS_State_MSG03;
	}
	else if( TRUE == __GL.can.msgSelect.Flag.ID04 )
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_PROCESS;
		ModuleCAN_PROCESS_State	= ModuleCAN_PROCESS_State_MSG04;
	}
	else if( TRUE == __GL.can.msgSelect.Flag.ID05 )
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_PROCESS;
		ModuleCAN_PROCESS_State	= ModuleCAN_PROCESS_State_MSG05;
	}
	else if( TRUE == __GL.can.msgSelect.Flag.ID06 )
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_PROCESS;
		ModuleCAN_PROCESS_State	= ModuleCAN_PROCESS_State_MSG06;
	}
	else if( TRUE == __GL.can.msgSelect.Flag.ID07 )
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_PROCESS;
		ModuleCAN_PROCESS_State	= ModuleCAN_PROCESS_State_MSG07;
	}
	else if( TRUE == __GL.can.msgSelect.Flag.ID08 )
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_PROCESS;
		ModuleCAN_PROCESS_State	= ModuleCAN_PROCESS_State_MSG08;
	}
	else
	{
		ModuleCAN_MAIN_State 	= ModuleCAN_MAIN_State_SUSPEND;
	}

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleCAN_MAIN_Process(void)
{
	switch( ModuleCAN_PROCESS_State )
	{

	case ModuleCAN_PROCESS_State_IDLE  : break;

	case ModuleCAN_PROCESS_State_MSG01  :

		memcpy(&protocol.obj.canPacket.DATA[0] , &BCM_MSG.Message03.payload[0] , 8);
		protocol.obj.canPacket.EXTENDED_ID.identifier = BCM_MSG.Message03_ID;
		protocol.ops.EEM_TX( &protocol.obj.canPacket , 0);

		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		__GL.can.msgSelect.Flag.ID01 = FALSE;

	break;

	case ModuleCAN_PROCESS_State_MSG02 :

		memcpy(&protocol.obj.canPacket.DATA[0] , &BCM_MSG.Message04.payload[0] , 8);
		protocol.obj.canPacket.EXTENDED_ID.identifier = BCM_MSG.Message04_ID;
		protocol.ops.EEM_TX( &protocol.obj.canPacket , 0);

		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		__GL.can.msgSelect.Flag.ID02 = FALSE;

	break;

	case ModuleCAN_PROCESS_State_MSG03 :

		memcpy(&protocol.obj.canPacket.DATA[0] , &BCM_MSG.Message05.payload[0] , 8);
		protocol.obj.canPacket.EXTENDED_ID.identifier = BCM_MSG.Message05_ID;
		protocol.ops.EEM_TX( &protocol.obj.canPacket , 0);

		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		__GL.can.msgSelect.Flag.ID03 = FALSE;

	break;

	case ModuleCAN_PROCESS_State_MSG04 :

		memcpy(&protocol.obj.canPacket.DATA[0] , &BCM_MSG.Message11.payload[0] , 8);
		protocol.obj.canPacket.EXTENDED_ID.identifier = BCM_MSG.Message11_ID;
		protocol.ops.EEM_TX( &protocol.obj.canPacket , 0);

		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		__GL.can.msgSelect.Flag.ID04 = FALSE;

	break;

	case ModuleCAN_PROCESS_State_MSG05 :

		memcpy(&protocol.obj.canPacket.DATA[0] , &BCM_MSG.Message12.payload[0] , 8);
		protocol.obj.canPacket.EXTENDED_ID.identifier = BCM_MSG.Message12_ID;
		protocol.ops.EEM_TX( &protocol.obj.canPacket , 0);

		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		__GL.can.msgSelect.Flag.ID05 = FALSE;

	break;

	case ModuleCAN_PROCESS_State_MSG06 :

		memcpy(&protocol.obj.canPacket.DATA[0] , &BCM_MSG.Message19.payload[0] , 8);
		protocol.obj.canPacket.EXTENDED_ID.identifier = BCM_MSG.Message19_ID;
		protocol.ops.EEM_TX( &protocol.obj.canPacket , 0);

		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		__GL.can.msgSelect.Flag.ID06 = FALSE;

	break;

	case ModuleCAN_PROCESS_State_MSG07 :

		memcpy(&protocol.obj.canPacket.DATA[0] , &BCM_MSG.Message20.payload[0] , 8);
		protocol.obj.canPacket.EXTENDED_ID.identifier = BCM_MSG.Message20_ID;
		protocol.ops.EEM_TX( &protocol.obj.canPacket , 0);

		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		__GL.can.msgSelect.Flag.ID07 = FALSE;

	break;

	case ModuleCAN_PROCESS_State_MSG08 :

		/* NULL */
		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		__GL.can.msgSelect.Flag.ID08 = FALSE;

	break;

	case ModuleCAN_PROCESS_State_SUSPEND:

		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_IDLE;
		ModuleCAN_MAIN_State	= ModuleCAN_MAIN_State_SUSPEND;
	break;


	default:
		ModuleCAN_PROCESS_State = ModuleCAN_PROCESS_State_SUSPEND;
		ModuleCAN_MAIN_State	= ModuleCAN_MAIN_State_SUSPEND;
	break;

	}

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleCAN_MAIN(void)
{
  while(1)
  {
	if( ModuleCAN_MAIN_State == ModuleCAN_MAIN_State_SUSPEND )
	{
		ModuleCAN_MAIN_State = ModuleCAN_MAIN_State_IDLE;
		break;
	}

	switch(ModuleCAN_MAIN_State)
	{
	    case ModuleCAN_MAIN_State_IDLE:

#if defined(SPI2CAN_Protocol)
	    	/* Check Can FIFO's each 10 ms semph relases */
	    	EEM_PERIODIC(&protocol.obj.canPacket);
#endif

	    	ModuleCAN_MAIN_State = ModuleCAN_MAIN_State_ROUTINE;
	    break;

	    case ModuleCAN_MAIN_State_ROUTINE:

	    	ModuleCAN_MAIN_Routine();
	    break;

	    case ModuleCAN_MAIN_State_PROCESS:

	    	ModuleCAN_MAIN_Process();

	    break;

	    default:
	    	ModuleCAN_MAIN_State = ModuleCAN_MAIN_State_SUSPEND;
	    break;
	}
  }
}


#endif

