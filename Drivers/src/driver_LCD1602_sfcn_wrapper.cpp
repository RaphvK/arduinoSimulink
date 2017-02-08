

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
 #include "driver_LCD1602_LiquidCrystal.h"
 #include "driver_LCD1602_LiquidCrystal.cpp"
 LiquidCrystal lcd;
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 16
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
extern "C" void driver_LCD1602_sfcn_Outputs_wrapper(const uint8_T *row1_ascii,
			const uint8_T *row2_ascii,
			const real_T *xD,
			const uint8_T  *rsParam, const int_T  p_width0,
			const uint8_T  *enParam, const int_T  p_width1,
			const uint8_T  *d4Param, const int_T  p_width2,
			const uint8_T  *d5Param, const int_T  p_width3,
			const uint8_T  *d6Param, const int_T  p_width4,
			const uint8_T  *d7Param, const int_T  p_width5)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* Loop */
if(xD[0] == 1) {
    #ifndef MATLAB_MEX_FILE
        lcd.clear();
        /* Row 1 */
            lcd.setCursor(0,0);
            /* ASCII-Vector to String */
            char tempString[17]; int i;
            for(i=0; i<16; i++) {
                tempString[i] = row1_ascii[i];
            }
            tempString[16] = '\0';
            lcd.print(tempString);
        /* Row 2 */
            lcd.setCursor(0,1);
            /* ASCII-Vector to String */
            for(i=0; i<16; i++) {
                tempString[i] = row2_ascii[i];
            }
            tempString[16] = '\0';
            lcd.print(tempString);
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
extern "C" void driver_LCD1602_sfcn_Update_wrapper(const uint8_T *row1_ascii,
			const uint8_T *row2_ascii,
			real_T *xD,
			const uint8_T  *rsParam,  const int_T  p_width0,
			const uint8_T  *enParam,  const int_T  p_width1,
			const uint8_T  *d4Param,  const int_T  p_width2,
			const uint8_T  *d5Param,  const int_T  p_width3,
			const uint8_T  *d6Param,  const int_T  p_width4,
			const uint8_T  *d7Param,  const int_T  p_width5)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/* Setup */
if(xD[0] != 1) {
    #ifndef MATLAB_MEX_FILE     // Only when code for hardware is generated
        lcd.init(1, rsParam[0], 255, enParam[0], d4Param[0], d5Param[0], d6Param[0], d7Param[0], 0, 0, 0, 0);
        lcd.begin(16,2); // Set LCD's number of columns=16 and rows=2
    #endif
        
    xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
