

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
#define u_width 7
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
void driver_LCD1602_timestamp2string_sfcn_Outputs_wrapper(const uint8_T *timestamp,
			uint8_T *date,
			uint8_T *time)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
char tempString[17]; char tempString2[17]; int i;
/* Weekday */
    switch(timestamp[3]) {
        case 1: strcpy(tempString,"Mon. "); break;
        case 2: strcpy(tempString,"Tue. "); break;
        case 3: strcpy(tempString,"Wed. "); break;
        case 4: strcpy(tempString,"Thu. "); break;
        case 5: strcpy(tempString,"Fri. "); break;
        case 6: strcpy(tempString,"Sat. "); break;
        case 7: strcpy(tempString,"Sun. "); break;
    }
/* Day of Month */
    itoa(timestamp[4],tempString2,10);
    strcat(tempString,tempString2);
    strcat(tempString,".");
/* Month */
    itoa(timestamp[5],tempString2,10);
    strcat(tempString,tempString2);
    strcat(tempString,".");
/* Year */
    itoa(timestamp[6],tempString2,10);
    strcat(tempString,tempString2);
/* Output: Date */
    for(i=0; i<16; i++) {
        if(tempString[i] == '\0') break;
        date[i] = tempString[i];
    }
/* Hour */
    itoa(timestamp[2],tempString2,10);
    if(tempString2[1] == '\0') {
        strcpy(tempString,"0");
        strcat(tempString,tempString2);
    } else {
        strcpy(tempString,tempString2);
    }
    strcat(tempString,":");
/* Minute */
    itoa(timestamp[1],tempString2,10);
    if(tempString2[1] == '\0') strcat(tempString,"0");
    strcat(tempString,tempString2);
/* Output: Time */
    for(i=0; i<16; i++) {
        if(tempString[i] == '\0') break;
        time[i] = tempString[i];
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
