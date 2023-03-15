/*********************************START OF FILE********************************/
/*******************************************************************************
  * @file    ModuleADC.c
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 30.01.2023 - ...
  * @rev     V1.0.0
  * @brief	 Ege Elektromobil BCM ADC Module
********************************************************************************/

/************************** INCLUDES *******************************************/

#include "ModuleADC_private.h"

/************************** DEFINES ********************************************/
#define	MODULEADC_MAIN_THREAD

ModuleADC_MAIN_State_et ModuleADC_MAIN_State = ModuleADC_MAIN_State_IDLE;
ModuleADC_MAIN_State_et ModuleADC_PROCESS_State = ModuleADC_MAIN_State_IDLE;

adc_st adc_s = {0};

#if 1	/* Init Functions */

/*******************************************************************************
	 @func    :	
	 @param   : 
	 @return  : 
	 @date	  : 
	 @INFO		:	
********************************************************************************/
void ModuleADC_HWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleADC_SWInit(void)
{
	
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleADC_StartUP(void)
{
	ModuleADC_HWInit();
	ModuleADC_SWInit();
}


#endif


#if 1	/* Application Functions */


#endif


#ifdef MODULEADC_MAIN_THREAD

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleADC_MAIN_Routine(void)
{
    /* Read All Channels and All Data with polling method	*/

    /* MUX1 POLLING READ */
    // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
    /* Read FBR_VS1 data from Mux1-Pin0 polling mode */
    adc_s.VOLTAGE_3V3 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX1,
                                                                 PROCESS_ANALOGSIGNALS_SELECT_PIN0);
    /* Read FBL_IS1 data from Mux1-Pin1 polling mode */
    adc_s.VOLTAGE_VMCU = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX1,
                                                                 PROCESS_ANALOGSIGNALS_SELECT_PIN1);
    /* Read FBL_VS1 data from Mux1-Pin2 polling mode */
    adc_s.VOLTAGE_5V = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX1,
                                                                 PROCESS_ANALOGSIGNALS_SELECT_PIN2);
    /* Read FBR_IS1 data from Mux1-Pin3 polling mode */
    adc_s.VOLTAGE_12V = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX1,
                                                                 PROCESS_ANALOGSIGNALS_SELECT_PIN3);
    /* Read FBL_VS2 data from Mux1-Pin4 polling mode */
    adc_s.VOLTAGE_24V = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX1,
                                                                 PROCESS_ANALOGSIGNALS_SELECT_PIN4);
    // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]

    /* MUX2 POLLING READ */
    // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
    /* Read POUT_IS7 data from Mux2-Pin0 polling mode */
    adc_s.A0_IN0 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX2,
                                                             PROCESS_ANALOGSIGNALS_SELECT_PIN0);
    /* Read POUT_VS4 data from Mux2-Pin1 polling mode */
    adc_s.A0_IN1 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX2,
                                                             PROCESS_ANALOGSIGNALS_SELECT_PIN1);
    /* Read POUT_IS4 data from Mux2-Pin2 polling mode */
    adc_s.A0_IN2 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX2,
                                                             PROCESS_ANALOGSIGNALS_SELECT_PIN2);
    /* Read POUT_VS7 data from Mux2-Pin3 polling mode */
    adc_s.A0_IN3 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX2,
                                                             PROCESS_ANALOGSIGNALS_SELECT_PIN3);
    /* Read POUT_IS1 data from Mux2-Pin4 polling mode */
    adc_s.A0_IN4 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX2,
                                                                PROCESS_ANALOGSIGNALS_SELECT_PIN4);
    /* Read PVDD_SNSS data from Mux2-Pin5 polling mode */
    adc_s.A0_IN5 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX2,
                                                                PROCESS_ANALOGSIGNALS_SELECT_PIN5);
    /* Read POUT_VS1 data from Mux2-Pin6 polling mode */
    adc_s.A0_IN6 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX2,
                                                                PROCESS_ANALOGSIGNALS_SELECT_PIN6);
    /* Read V12_SNS data from Mux2-Pin7 polling mode */
    adc_s.A0_IN7 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_MUX2,
                                                                PROCESS_ANALOGSIGNALS_SELECT_PIN7);
    // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]



    /*  OTHER CHANNEL POLLING READ */
    // [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
    /* Read POUT_IS11 data from Mux5-Pin0 polling mode */
    adc_s.VIN = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_VIN,
    															   PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.ACS_5V = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_5V,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.ACS_12V = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_12V,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.ACS_VMCU = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_VMCU,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.ACS_3V3 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_3V3,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.ACS_FL = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_FL,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.ACS_BL = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_BL,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.ACS_VINL1 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_VINL1,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.ACS_VINL2 = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_VINL2,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.ACS_BINL = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_BINL,
    															PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.ACS_STOP = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_STOP,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.ACS_RS = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_RS,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.ACS_LS = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_ACS_LS,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.RS_VRx = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_RS_VRx,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.RS_VRy = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_RS_VRy,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.LS_VRx = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_LS_VRx,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.LS_VRy = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_LS_VRy,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.DIREKSIYON = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_DIREKSIYON,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_IS8 data from Mux5-Pin2 polling mode */
    adc_s.FREN = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_FREN,
   															 PROCESS_ANALOGSIGNALS_SELECT_NULL);
    /* Read POUT_VS8 data from Mux5-Pin1 polling mode */
    adc_s.GAZ = Process_AnalogSignals_ReadChannel(PROCESS_ANALOGSIGNALS_AN_GAZ,
    																PROCESS_ANALOGSIGNALS_SELECT_NULL);
     // ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]


#ifdef  DEBUG_ANALOGREAD_PROCESS
    DEBUG_Process();
#endif
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
void ModuleADC_MAIN_Process(void)
{

}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/

void ModuleADC_MAIN(void)
{
	switch(ModuleADC_MAIN_State)
	{
	    case ModuleADC_MAIN_State_IDLE:
	    	//@INFO: IDLE Operations ..
	    	ModuleADC_MAIN_State = ModuleADC_MAIN_State_ROUTINE;
	    break;

	    case ModuleADC_MAIN_State_ROUTINE:

	    	ModuleADC_MAIN_Routine();
	    break;

	    case ModuleADC_MAIN_State_PROCESS:

	    	ModuleADC_MAIN_Process();

	    break;

	    case ModuleADC_MAIN_State_SUSPEND:
	    	ModuleADC_MAIN_State = ModuleADC_MAIN_State_IDLE;
	    break;

	    default:
	    	ModuleADC_MAIN_State = ModuleADC_MAIN_State_SUSPEND;
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
void    Process_AnalogSignals_SeperateChannels(ADC_HandleTypeDef *hadc, U32 ADC_CHANNEL, U32 RANK)
{
    ADC_ChannelConfTypeDef sConfig = {0};

    sConfig.Channel      = ADC_CHANNEL;
    sConfig.Rank         = RANK;
    sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;

    if (HAL_ADC_ConfigChannel(hadc, &sConfig) != HAL_OK)
    {
        Error_Handler();
    }
}

/*******************************************************************************
	 @func    :
	 @param   :
	 @return  :
	 @date	  :
	 @INFO		:
********************************************************************************/
U32 Process_AnalogSignals_ReadChannel(U8 MUX_SELECT, U8 SELECT_PIN)
{
    ADC_HandleTypeDef tempAdcHandle;
    U32 tempAdcValue  = 0;

    /* Analog Mux Pin Selection																*/
    switch (MUX_SELECT)
    {
        case PROCESS_ANALOGSIGNALS_AN_MUX1:    /* PC1 - ADC3 - CHANNEL_13       */

            Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_MUX1_HANDLE,
                                                   PROCESS_ANALOGSIGNALS_AN_MUX1_CHANNEL,
                                                   PROCESS_ANALOGSIGNALS_AN_MUX1_RANK);

            tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_MUX1_HANDLE;

            break;

        case PROCESS_ANALOGSIGNALS_AN_MUX2:    /* PC1 - ADC3 - CHANNEL_14       */

            Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_MUX2_HANDLE,
                                                   PROCESS_ANALOGSIGNALS_AN_MUX2_CHANNEL,
                                                   PROCESS_ANALOGSIGNALS_AN_MUX2_RANK);

            tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_MUX2_HANDLE;

            break;

#define SCI_BCM_SMALL

#ifdef SCI_BCM_SMALL
        /* ACS712 POWER Selection									*/
        case PROCESS_ANALOGSIGNALS_AN_VIN:

                    Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_VIN_HANDLE,
                    										PROCESS_ANALOGSIGNALS_AN_VIN_CHANNEL,
															PROCESS_ANALOGSIGNALS_AN_VIN_RANK);

                    tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_VIN_HANDLE;

                    break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_5V:

                    Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_5V_HANDLE,
                    									   PROCESS_ANALOGSIGNALS_AN_ACS_5V_CHANNEL,
														   PROCESS_ANALOGSIGNALS_AN_ACS_5V_RANK);

                    tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_5V_HANDLE;

                    break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_12V:

                   	Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_12V_HANDLE,
                        		  	  	  	  	  	  	  PROCESS_ANALOGSIGNALS_AN_ACS_12V_CHANNEL,
														  PROCESS_ANALOGSIGNALS_AN_ACS_12V_RANK);

                    tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_12V_HANDLE;

                    break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_VMCU:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_VMCU_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_VMCU_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_VMCU_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_VMCU_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_3V3:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_3V3_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_3V3_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_3V3_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_3V3_HANDLE;

                     break;

        /* ACS712 DRIVER Selection									*/
        case PROCESS_ANALOGSIGNALS_AN_ACS_FL:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_FL_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_FL_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_FL_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_FL_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_BL:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_BL_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_BL_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_BL_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_BL_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_VINL1:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_VINL1_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_VINL1_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_VINL1_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_VINL1_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_VINL2:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_VINL2_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_VINL2_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_VINL2_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_VINL2_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_BINL:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_BINL_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_BINL_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_BINL_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_BINL_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_STOP:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_STOP_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_STOP_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_STOP_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_STOP_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_RS:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_RS_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_RS_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_RS_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_RS_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_ACS_LS:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_ACS_LS_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_ACS_LS_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_ACS_LS_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_ACS_LS_HANDLE;

                     break;

        /* GPIO DRIVER Selection									 */
        case PROCESS_ANALOGSIGNALS_AN_RS_VRx:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_RS_VRx_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_RS_VRx_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_RS_VRx_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_RS_VRx_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_RS_VRy:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_RS_VRy_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_RS_VRy_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_RS_VRy_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_RS_VRy_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_LS_VRx:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_LS_VRx_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_LS_VRx_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_LS_VRx_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_LS_VRx_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_LS_VRy:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_LS_VRy_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_LS_VRy_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_LS_VRy_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_LS_VRy_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_DIREKSIYON:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_DIREKSIYON_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_DIREKSIYON_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_DIREKSIYON_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_DIREKSIYON_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_FREN:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_FREN_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_FREN_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_FREN_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_FREN_HANDLE;

                     break;

        case PROCESS_ANALOGSIGNALS_AN_GAZ:

                     Process_AnalogSignals_SeperateChannels(&PROCESS_ANALOGSIGNALS_AN_GAZ_HANDLE,
                        								PROCESS_ANALOGSIGNALS_AN_GAZ_CHANNEL,
    													PROCESS_ANALOGSIGNALS_AN_GAZ_RANK);

                     tempAdcHandle = PROCESS_ANALOGSIGNALS_AN_GAZ_HANDLE;

                     break;

#endif

    }


    switch (SELECT_PIN)
    {
    	case PROCESS_ANALOGSIGNALS_SELECT_NULL: break;

        case PROCESS_ANALOGSIGNALS_SELECT_PIN0: A0_MUX_SET(); break;

        case PROCESS_ANALOGSIGNALS_SELECT_PIN1: A1_MUX_SET(); break;

        case PROCESS_ANALOGSIGNALS_SELECT_PIN2: A2_MUX_SET(); break;

        case PROCESS_ANALOGSIGNALS_SELECT_PIN3: A3_MUX_SET(); break;

        case PROCESS_ANALOGSIGNALS_SELECT_PIN4: A4_MUX_SET(); break;

        case PROCESS_ANALOGSIGNALS_SELECT_PIN5: A5_MUX_SET(); break;

        case PROCESS_ANALOGSIGNALS_SELECT_PIN6: A6_MUX_SET(); break;

        case PROCESS_ANALOGSIGNALS_SELECT_PIN7: A7_MUX_SET(); break;
    }

    /* 74HC4051 Enable-Pin Always ground */

    /* 74HC4051 Select-Pin Maximum response time 90ns overcondutions            */
    HAL_Delay(1);   /* 1ms blocking delay hope to solve this select sequence    */

    HAL_ADC_Start(&tempAdcHandle);

    HAL_ADC_PollForConversion(&tempAdcHandle, 100);

    tempAdcValue = HAL_ADC_GetValue(&tempAdcHandle);

    HAL_ADC_Stop(&tempAdcHandle);

    return tempAdcValue;
}

#endif

