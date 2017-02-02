

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
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 16
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
void driver_LCD1602_appendString_sfcn_Outputs_wrapper(const uint8_T *string1,
			const uint8_T *string2,
			uint8_T *stringOut)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* ASCII-Vector to String */
char tempString1[17]; char tempString2[17]; int i;
for(i=0; i<16; i++) {
    tempString1[i] = string1[i];
    tempString2[i] = string2[i];
}
tempString1[16] = '\0';
tempString2[16] = '\0';
/* Append String */
strcat(tempString1,tempString2);
/* String to ASCII-Vector */
for(i=0; i<16; i++) {
    stringOut[i] = tempString1[i];
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
