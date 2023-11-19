/*
 * File: nonlinearAirframe_RotorDynamics.h
 *
 * Code generated for Simulink model 'nonlinearAirframe'.
 *
 * Model version                  : 1.158
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Nov 19 00:10:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_nonlinearAirframe_RotorDynamics_h_
#define RTW_HEADER_nonlinearAirframe_RotorDynamics_h_
#include <math.h>
#ifndef nonlinearAirframe_COMMON_INCLUDES_
# define nonlinearAirframe_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* nonlinearAirframe_COMMON_INCLUDES_ */

#include "nonlinearAirframe_types.h"

extern void nonlinearAirframe_RotorDynamics(const real_T rtu_Vb[3], const real_T
  rtu_pqr[3], const real_T *rtu_rho, real32_T rtu_w, const real_T rtu_Arm[3],
  real_T rty_Fxyz[3], real_T rty_Mxyz[3]);

#endif                       /* RTW_HEADER_nonlinearAirframe_RotorDynamics_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
