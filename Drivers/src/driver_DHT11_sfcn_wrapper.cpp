

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
 #include "driver_DHT11_DHT.h"
 #include "driver_DHT11_DHT.cpp"
 DHT dht(1,DHT11);
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
extern "C" void driver_DHT11_sfcn_Outputs_wrapper(real32_T *temperature,
			real32_T *humidity,
			const real_T *xD,
			const uint8_T  *pinNumber, const int_T  p_width0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* Loop */
if(xD[0] == 1) {
    #ifndef MATLAB_MEX_FILE
        temperature[0] = dht.readTemperature();
        humidity[0] = dht.readHumidity();
    #endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
extern "C" void driver_DHT11_sfcn_Update_wrapper(real32_T *temperature,
			real32_T *humidity,
			real_T *xD,
			const uint8_T  *pinNumber,  const int_T  p_width0)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/* Setup */
if(xD[0] < 1) {
    #ifndef MATLAB_MEX_FILE
        dht = DHT(pinNumber[0],DHT11);
    #endif
    xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
