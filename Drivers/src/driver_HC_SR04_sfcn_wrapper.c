

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#ifndef MATLAB_MEX_FILE
 #include <Arduino.h>
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
 
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void driver_HC_SR04_sfcn_Outputs_wrapper(uint16_T *distance,
			const real_T *xD,
			const uint8_T  *trigParam, const int_T  p_width0,
			const uint8_T  *echoParam, const int_T  p_width1)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* Loop */
if(xD[0] == 1) {
    #ifndef MATLAB_MEX_FILE     // Only when code for hardware is generated
        unsigned long duration;
        /* Trigger Command */
            digitalWrite(trigParam[0], LOW); 
            delayMicroseconds(2);
            digitalWrite(trigParam[0], HIGH);
            delayMicroseconds(10); 
            digitalWrite(trigParam[0], LOW);
        /* Read Answer */
            duration = pulseInLong(echoParam[0], HIGH, 25000);
            distance[0] = duration/58.2;
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
void driver_HC_SR04_sfcn_Update_wrapper(uint16_T *distance,
			real_T *xD,
			const uint8_T  *trigParam,  const int_T  p_width0,
			const uint8_T  *echoParam,  const int_T  p_width1)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/* Setup */
if(xD[0] != 1) {
    #ifndef MATLAB_MEX_FILE     // Only when code for hardware is generated
        pinMode(trigParam[0], OUTPUT);
        pinMode(echoParam[0], INPUT);
    #endif
        
    xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
