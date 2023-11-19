/*
 * File: nonlinearAirframe_RotorDynamics.c
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

#include "nonlinearAirframe_RotorDynamics.h"

/* Include model header file for global data */
#include "nonlinearAirframe.h"
#include "nonlinearAirframe_private.h"
#include "rt_atan2d_snf.h"

/* Output and update for atomic system: '<S31>/Rotor_Dynamics' */
void nonlinearAirframe_RotorDynamics(const real_T rtu_Vb[3], const real_T
  rtu_pqr[3], const real_T *rtu_rho, real32_T rtu_w, const real_T rtu_Arm[3],
  real_T rty_Fxyz[3], real_T rty_Mxyz[3])
{
  real_T rtb_ixj;
  real32_T rtb_R4;
  real_T rtb_R1;
  real32_T rtb_Abs_tmp;
  real_T rtb_MathFunction2_idx_1;
  real_T rtb_MathFunction2_idx_2;
  real_T rtb_Sum_h_idx_0;
  real_T rtb_Sum_h_idx_1;

  /* Sum: '<S33>/Sum' incorporates:
   *  Product: '<S36>/j x k'
   *  Product: '<S36>/k x i'
   *  Product: '<S37>/i x k'
   *  Product: '<S37>/k x j'
   *  Sum: '<S34>/Sum'
   */
  rtb_Sum_h_idx_0 = (rtu_pqr[1] * rtu_Arm[2] - rtu_pqr[2] * rtu_Arm[1]) +
    rtu_Vb[0];
  rtb_Sum_h_idx_1 = (rtu_pqr[2] * rtu_Arm[0] - rtu_pqr[0] * rtu_Arm[2]) +
    rtu_Vb[1];

  /* Trigonometry: '<S33>/Trigonometric Function1' */
  rtb_ixj = rt_atan2d_snf(rtb_Sum_h_idx_1, rtb_Sum_h_idx_0);

  /* Trigonometry: '<S33>/Trigonometric Function2' */
  rtb_R1 = cos(rtb_ixj);
  rtb_ixj = sin(rtb_ixj);

  /* Math: '<S33>/Math Function2' incorporates:
   *  Gain: '<S33>/Gain'
   *  SignalConversion generated from: '<S33>/Vector Concatenate'
   */
  rtb_MathFunction2_idx_1 = -rtb_ixj;
  rtb_MathFunction2_idx_2 = rtb_ixj;

  /* Abs: '<S33>/Abs' incorporates:
   *  Abs: '<S33>/Abs1'
   */
  rtb_Abs_tmp = (real32_T)fabs(rtu_w);

  /* Gain: '<S33>/R' incorporates:
   *  Abs: '<S33>/Abs'
   */
  rtb_R4 = 0.033F * rtb_Abs_tmp;

  /* Sum: '<S33>/Sum of Elements' incorporates:
   *  Math: '<S33>/Math Function'
   */
  rtb_ixj = rtb_Sum_h_idx_0 * rtb_Sum_h_idx_0 + rtb_Sum_h_idx_1 *
    rtb_Sum_h_idx_1;

  /* Sqrt: '<S33>/Sqrt' */
  if (rtb_ixj < 0.0) {
    rtb_ixj = 0.0;
  } else {
    rtb_ixj = sqrt(rtb_ixj);
  }

  /* End of Sqrt: '<S33>/Sqrt' */

  /* Product: '<S33>/Divide' */
  rtb_ixj /= rtb_R4;

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Constant4'
   */
  if (rtb_ixj != 0.0) {
    rtb_Sum_h_idx_0 = rtb_ixj;
  } else {
    rtb_Sum_h_idx_0 = 2.2250738585072014E-308;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Product: '<S33>/Divide2' incorporates:
   *  Constant: '<S33>/Constant'
   *  Gain: '<S33>/R1'
   *  Gain: '<S33>/R2'
   *  Math: '<S33>/Math Function1'
   *  Product: '<S33>/Divide1'
   *  Product: '<S36>/i x j'
   *  Product: '<S37>/j x i'
   *  Sum: '<S33>/Sum'
   *  Sum: '<S33>/Sum1'
   *  Sum: '<S33>/Sum2'
   *  Sum: '<S34>/Sum'
   *
   * About '<S33>/Math Function1':
   *  Operator: reciprocal
   */
  rtb_Sum_h_idx_0 = (0.40724349213201017 - ((rtu_pqr[0] * rtu_Arm[1] - rtu_pqr[1]
    * rtu_Arm[0]) + rtu_Vb[2]) / rtb_R4 * 2.0) / (1.0 / rtb_Sum_h_idx_0 - 0.5 *
    rtb_ixj);

  /* Product: '<S33>/Divide3' incorporates:
   *  Abs: '<S33>/Abs'
   *  Constant: '<S33>/Constant2'
   */
  rtb_ixj = 26.439850820016108 / rtb_Abs_tmp;

  /* Sum: '<S33>/Sum3' incorporates:
   *  Product: '<S33>/Product'
   *  Product: '<S33>/Product1'
   *  Trigonometry: '<S33>/Trigonometric Function2'
   */
  rtb_MathFunction2_idx_2 = (rtb_R1 * rtb_Sum_h_idx_0 + rtb_MathFunction2_idx_2 *
    0.0) - rtb_ixj * rtu_pqr[1];
  rtb_MathFunction2_idx_1 = (rtb_MathFunction2_idx_1 * rtb_Sum_h_idx_0 + rtb_R1 *
    0.0) - rtb_ixj * rtu_pqr[0];

  /* Trigonometry: '<S33>/Trigonometric Function4' */
  rtb_ixj = cos(rtb_MathFunction2_idx_1);

  /* Product: '<S33>/Product2' incorporates:
   *  Gain: '<S33>/Gain1'
   *  Trigonometry: '<S33>/Trigonometric Function3'
   */
  rtb_R1 = sin(rtb_MathFunction2_idx_2) * -rtb_ixj;

  /* Product: '<S33>/Product3' incorporates:
   *  Gain: '<S33>/Gain2'
   *  Trigonometry: '<S33>/Trigonometric Function3'
   */
  rtb_ixj *= -cos(rtb_MathFunction2_idx_2);

  /* Product: '<S33>/Product6' incorporates:
   *  Gain: '<S33>/R3'
   *  Math: '<S33>/Math Function3'
   */
  rtb_MathFunction2_idx_2 = rtu_w * rtu_w * 3.98647835E-8F * *rtu_rho;

  /* Product: '<S33>/Product4' incorporates:
   *  Trigonometry: '<S33>/Trigonometric Function4'
   */
  rty_Fxyz[0] = rtb_R1 * rtb_MathFunction2_idx_2;
  rty_Fxyz[1] = sin(rtb_MathFunction2_idx_1) * rtb_MathFunction2_idx_2;
  rty_Fxyz[2] = rtb_ixj * rtb_MathFunction2_idx_2;

  /* Sum: '<S33>/Sum4' incorporates:
   *  Gain: '<S33>/R4'
   *  Product: '<S33>/Product5'
   *  Product: '<S33>/Product7'
   *  Product: '<S38>/i x j'
   *  Product: '<S38>/j x k'
   *  Product: '<S38>/k x i'
   *  Product: '<S39>/i x k'
   *  Product: '<S39>/j x i'
   *  Product: '<S39>/k x j'
   *  Sum: '<S35>/Sum'
   */
  rty_Mxyz[0] = rtu_Arm[1] * rty_Fxyz[2] - rtu_Arm[2] * rty_Fxyz[1];
  rty_Mxyz[1] = rtu_Arm[2] * rty_Fxyz[0] - rtu_Arm[0] * rty_Fxyz[2];
  rty_Mxyz[2] = rtu_w * rtb_Abs_tmp * -9.62233E-11F * *rtu_rho + (rtu_Arm[0] *
    rty_Fxyz[1] - rtu_Arm[1] * rty_Fxyz[0]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
