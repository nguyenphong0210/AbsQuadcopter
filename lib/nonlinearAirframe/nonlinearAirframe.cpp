/*
 * File: nonlinearAirframe.c
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

#include "nonlinearAirframe.h"
#include "nonlinearAirframe_private.h"
#include "rt_modd_snf.h"
#include "rt_mrdivide_U1d1x3_U2d_9vOrDY9Z.h"

/* System initialize for referenced model: 'nonlinearAirframe' */
void nonlinearAirframe_Init(X_nonlinearAirframe_n_T *localX)
{
  /* SystemInitialize for Atomic SubSystem: '<Root>/Nonlinear' */
  /* InitializeConditions for Integrator: '<S6>/phi theta psi' */
  localX->phithetapsi_CSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/p,q,r ' */
  localX->pqr_CSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/ub,vb,wb' */
  localX->ubvbwb_CSTATE[0] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/xe,ye,ze' */
  localX->xeyeze_CSTATE[0] = 57.0;

  /* InitializeConditions for Integrator: '<S6>/phi theta psi' */
  localX->phithetapsi_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/p,q,r ' */
  localX->pqr_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/ub,vb,wb' */
  localX->ubvbwb_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/xe,ye,ze' */
  localX->xeyeze_CSTATE[1] = 95.0;

  /* InitializeConditions for Integrator: '<S6>/phi theta psi' */
  localX->phithetapsi_CSTATE[2] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/p,q,r ' */
  localX->pqr_CSTATE[2] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/ub,vb,wb' */
  localX->ubvbwb_CSTATE[2] = 0.0;

  /* InitializeConditions for Integrator: '<S2>/xe,ye,ze' */
  localX->xeyeze_CSTATE[2] = -0.046;

  /* End of SystemInitialize for SubSystem: '<Root>/Nonlinear' */
}

/* Outputs for referenced model: 'nonlinearAirframe' */
void nonlinearAirframe(RT_MODEL_nonlinearAirframe_T * const nonlinearAirframe_M,
  const real32_T rtu_Actuators[4], const EnvironmentBus *rtu_Environment,
  StatesBus *rty_States, DW_nonlinearAirframe_f_T *localDW,
  X_nonlinearAirframe_n_T *localX)
{
  /* local block i/o variables */
  real_T rtb_pqr[3];
  real_T rtb_UnitConversion[3];
  real_T rtb_Product[3];
  real_T rtb_sincos_o1[3];
  real32_T rtb_ImpSel_InsertedFor_w_at_out;
  real_T rtb_ImpSel_InsertedFor_D_at_out[3];

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  real_T rtb_VectorConcatenate[9];
  real_T rtb_sincos_o2_n[3];
  int32_T i;
  real_T rtb_ImpAsg_InsertedFor_Moments_[12];
  real_T rtb_ImpAsg_InsertedFor_Forces_a[12];
  real32_T SignedSqrt[4];
  real_T tmp[3];
  real_T tmp_0[3];
  real_T rtb_LLA;
  real_T rtb_LLA_idx_0;
  real_T rtb_LLA_idx_1;
  real_T rtb_sincos_o2_idx_1;
  real_T rtb_sincos_o2_idx_0;
  real_T rtb_sincos_o2_idx_2;
  real32_T rtu_Actuators_0;
  real_T rtb_VectorConcatenate_tmp;
  real_T rtb_VectorConcatenate_tmp_0;
  int32_T rtb_ImpSel_InsertedFor_D_at_o_0;

  /* Outputs for Atomic SubSystem: '<Root>/Nonlinear' */
  /* Trigonometry: '<S14>/sincos' incorporates:
   *  Integrator: '<S6>/phi theta psi'
   *  SignalConversion generated from: '<S14>/sincos'
   */
  rtb_sincos_o2_idx_0 = cos(localX->phithetapsi_CSTATE[2]);
  rtb_LLA_idx_0 = sin(localX->phithetapsi_CSTATE[2]);
  rtb_sincos_o2_idx_1 = cos(localX->phithetapsi_CSTATE[1]);
  rtb_LLA_idx_1 = sin(localX->phithetapsi_CSTATE[1]);
  rtb_sincos_o2_idx_2 = cos(localX->phithetapsi_CSTATE[0]);
  rtb_LLA = sin(localX->phithetapsi_CSTATE[0]);

  /* Fcn: '<S14>/Fcn11' */
  rtb_VectorConcatenate[0] = rtb_sincos_o2_idx_1 * rtb_sincos_o2_idx_0;

  /* Fcn: '<S14>/Fcn21' incorporates:
   *  Fcn: '<S14>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = rtb_LLA * rtb_LLA_idx_1;
  rtb_VectorConcatenate[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o2_idx_0 -
    rtb_sincos_o2_idx_2 * rtb_LLA_idx_0;

  /* Fcn: '<S14>/Fcn31' incorporates:
   *  Fcn: '<S14>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_idx_2 * rtb_LLA_idx_1;
  rtb_VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 * rtb_sincos_o2_idx_0 +
    rtb_LLA * rtb_LLA_idx_0;

  /* Fcn: '<S14>/Fcn12' */
  rtb_VectorConcatenate[3] = rtb_sincos_o2_idx_1 * rtb_LLA_idx_0;

  /* Fcn: '<S14>/Fcn22' */
  rtb_VectorConcatenate[4] = rtb_VectorConcatenate_tmp * rtb_LLA_idx_0 +
    rtb_sincos_o2_idx_2 * rtb_sincos_o2_idx_0;

  /* Fcn: '<S14>/Fcn32' */
  rtb_VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 * rtb_LLA_idx_0 -
    rtb_LLA * rtb_sincos_o2_idx_0;

  /* Fcn: '<S14>/Fcn13' */
  rtb_VectorConcatenate[6] = -rtb_LLA_idx_1;

  /* Fcn: '<S14>/Fcn23' */
  rtb_VectorConcatenate[7] = rtb_LLA * rtb_sincos_o2_idx_1;

  /* Fcn: '<S14>/Fcn33' */
  rtb_VectorConcatenate[8] = rtb_sincos_o2_idx_2 * rtb_sincos_o2_idx_1;

  /* Saturate: '<S32>/Saturation5' incorporates:
   *  Gain: '<S32>/Motordirections'
   */
  if (rtu_Actuators[0] > 500.0F) {
    rtu_Actuators_0 = 500.0F;
  } else if (rtu_Actuators[0] < 10.0F) {
    rtu_Actuators_0 = 10.0F;
  } else {
    rtu_Actuators_0 = rtu_Actuators[0];
  }

  /* Sqrt: '<S32>/Signed Sqrt' incorporates:
   *  Gain: '<S32>/motorsToW2_Gain'
   *
   * About '<S32>/Signed Sqrt':
   *  Operator: signedSqrt
   */
  SignedSqrt[0] = (real32_T)sqrt(13840.8F * rtu_Actuators_0);

  /* Saturate: '<S32>/Saturation5' incorporates:
   *  Gain: '<S32>/Motordirections'
   */
  if (-rtu_Actuators[1] > 500.0F) {
    rtu_Actuators_0 = 500.0F;
  } else if (-rtu_Actuators[1] < 10.0F) {
    rtu_Actuators_0 = 10.0F;
  } else {
    rtu_Actuators_0 = -rtu_Actuators[1];
  }

  /* Gain: '<S32>/motorsToW2_Gain' incorporates:
   *  Gain: '<S32>/Motordirections1'
   */
  rtu_Actuators_0 = 13840.8F * -rtu_Actuators_0;

  /* Sqrt: '<S32>/Signed Sqrt'
   *
   * About '<S32>/Signed Sqrt':
   *  Operator: signedSqrt
   */
  if (rtu_Actuators_0 < 0.0F) {
    SignedSqrt[1] = -(real32_T)sqrt((real32_T)fabs(rtu_Actuators_0));
  } else {
    SignedSqrt[1] = (rtNaNF);
  }

  /* Saturate: '<S32>/Saturation5' incorporates:
   *  Gain: '<S32>/Motordirections'
   */
  if (rtu_Actuators[2] > 500.0F) {
    rtu_Actuators_0 = 500.0F;
  } else if (rtu_Actuators[2] < 10.0F) {
    rtu_Actuators_0 = 10.0F;
  } else {
    rtu_Actuators_0 = rtu_Actuators[2];
  }

  /* Sqrt: '<S32>/Signed Sqrt' incorporates:
   *  Gain: '<S32>/motorsToW2_Gain'
   *
   * About '<S32>/Signed Sqrt':
   *  Operator: signedSqrt
   */
  SignedSqrt[2] = (real32_T)sqrt(13840.8F * rtu_Actuators_0);

  /* Saturate: '<S32>/Saturation5' incorporates:
   *  Gain: '<S32>/Motordirections'
   */
  if (-rtu_Actuators[3] > 500.0F) {
    rtu_Actuators_0 = 500.0F;
  } else if (-rtu_Actuators[3] < 10.0F) {
    rtu_Actuators_0 = 10.0F;
  } else {
    rtu_Actuators_0 = -rtu_Actuators[3];
  }

  /* Gain: '<S32>/motorsToW2_Gain' incorporates:
   *  Gain: '<S32>/Motordirections1'
   */
  rtu_Actuators_0 = 13840.8F * -rtu_Actuators_0;

  /* Sqrt: '<S32>/Signed Sqrt'
   *
   * About '<S32>/Signed Sqrt':
   *  Operator: signedSqrt
   */
  if (rtu_Actuators_0 < 0.0F) {
    SignedSqrt[3] = -(real32_T)sqrt((real32_T)fabs(rtu_Actuators_0));
  } else {
    SignedSqrt[3] = (rtNaNF);
  }

  /* Integrator: '<S2>/p,q,r ' */
  /* Unit Conversion - from: m/s to: m/s
     Expression: output = (1*input) + (0) */
  rtb_pqr[0] = localX->pqr_CSTATE[0];

  /* UnitConversion: '<S10>/Unit Conversion' incorporates:
   *  Integrator: '<S2>/ub,vb,wb'
   */
  rtb_UnitConversion[0] = localX->ubvbwb_CSTATE[0];

  /* Integrator: '<S2>/p,q,r ' */
  rtb_pqr[1] = localX->pqr_CSTATE[1];

  /* UnitConversion: '<S10>/Unit Conversion' incorporates:
   *  Integrator: '<S2>/ub,vb,wb'
   */
  rtb_UnitConversion[1] = localX->ubvbwb_CSTATE[1];

  /* Integrator: '<S2>/p,q,r ' */
  rtb_pqr[2] = localX->pqr_CSTATE[2];

  /* UnitConversion: '<S10>/Unit Conversion' incorporates:
   *  Integrator: '<S2>/ub,vb,wb'
   */
  rtb_UnitConversion[2] = localX->ubvbwb_CSTATE[2];

  /* Outputs for Iterator SubSystem: '<S27>/For Each Subsystem' incorporates:
   *  ForEach: '<S31>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* ForEachSliceSelector generated from: '<S31>/w' */
    rtb_ImpSel_InsertedFor_w_at_out = SignedSqrt[ForEach_itr];

    /* ForEachSliceSelector generated from: '<S31>/D' incorporates:
     *  ForEachSliceAssignment generated from: '<S31>/Forces'
     *  ForEachSliceAssignment generated from: '<S31>/Moments'
     */
    rtb_ImpSel_InsertedFor_D_at_out[0] =
      nonlinearAirframe_ConstB.VectorConcatenate_h[3 * ForEach_itr];
    i = 3 * ForEach_itr + 1;
    rtb_ImpSel_InsertedFor_D_at_out[1] =
      nonlinearAirframe_ConstB.VectorConcatenate_h[i];
    rtb_ImpSel_InsertedFor_D_at_o_0 = 3 * ForEach_itr + 2;
    rtb_ImpSel_InsertedFor_D_at_out[2] =
      nonlinearAirframe_ConstB.VectorConcatenate_h[rtb_ImpSel_InsertedFor_D_at_o_0];

    /* Outputs for Atomic SubSystem: '<S31>/Rotor_Dynamics' */
    nonlinearAirframe_RotorDynamics(rtb_UnitConversion, rtb_pqr,
      &rtu_Environment->AtmosphereBus.air_density,
      rtb_ImpSel_InsertedFor_w_at_out, rtb_ImpSel_InsertedFor_D_at_out,
      rtb_Product, rtb_sincos_o1);

    /* End of Outputs for SubSystem: '<S31>/Rotor_Dynamics' */

    /* ForEachSliceAssignment generated from: '<S31>/Moments' incorporates:
     *  SignalConversion generated from: '<S31>/Rotor_Dynamics'
     */
    rtb_ImpAsg_InsertedFor_Moments_[3 * ForEach_itr] = rtb_sincos_o1[0];

    /* ForEachSliceAssignment generated from: '<S31>/Forces' incorporates:
     *  SignalConversion generated from: '<S31>/Rotor_Dynamics'
     */
    rtb_ImpAsg_InsertedFor_Forces_a[3 * ForEach_itr] = rtb_Product[0];

    /* ForEachSliceAssignment generated from: '<S31>/Moments' incorporates:
     *  SignalConversion generated from: '<S31>/Rotor_Dynamics'
     */
    rtb_ImpAsg_InsertedFor_Moments_[i] = rtb_sincos_o1[1];

    /* ForEachSliceAssignment generated from: '<S31>/Forces' incorporates:
     *  SignalConversion generated from: '<S31>/Rotor_Dynamics'
     */
    rtb_ImpAsg_InsertedFor_Forces_a[i] = rtb_Product[1];

    /* ForEachSliceAssignment generated from: '<S31>/Moments' incorporates:
     *  SignalConversion generated from: '<S31>/Rotor_Dynamics'
     */
    rtb_ImpAsg_InsertedFor_Moments_[rtb_ImpSel_InsertedFor_D_at_o_0] =
      rtb_sincos_o1[2];

    /* ForEachSliceAssignment generated from: '<S31>/Forces' incorporates:
     *  SignalConversion generated from: '<S31>/Rotor_Dynamics'
     */
    rtb_ImpAsg_InsertedFor_Forces_a[rtb_ImpSel_InsertedFor_D_at_o_0] =
      rtb_Product[2];
  }

  /* End of Outputs for SubSystem: '<S27>/For Each Subsystem' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S27>/Sum of Elements1' */
    rtb_sincos_o2_n[i] = ((rtb_ImpAsg_InsertedFor_Moments_[i + 3] +
      rtb_ImpAsg_InsertedFor_Moments_[i]) + rtb_ImpAsg_InsertedFor_Moments_[i +
                          6]) + rtb_ImpAsg_InsertedFor_Moments_[i + 9];

    /* Product: '<S18>/Product' */
    rtb_sincos_o1[i] = 0.0;
    rtb_sincos_o1[i] += nonlinearAirframe_ConstB.Selector[i] * rtb_pqr[0];
    rtb_sincos_o1[i] += nonlinearAirframe_ConstB.Selector[i + 3] * rtb_pqr[1];
    rtb_sincos_o1[i] += nonlinearAirframe_ConstB.Selector[i + 6] * rtb_pqr[2];
  }

  /* Sum: '<S17>/Sum' incorporates:
   *  Product: '<S20>/i x j'
   *  Product: '<S20>/j x k'
   *  Product: '<S20>/k x i'
   *  Product: '<S21>/i x k'
   *  Product: '<S21>/j x i'
   *  Product: '<S21>/k x j'
   *  Sum: '<S7>/Sum2'
   */
  tmp[0] = rtb_pqr[1] * rtb_sincos_o1[2];
  tmp[1] = rtb_pqr[2] * rtb_sincos_o1[0];
  tmp[2] = rtb_pqr[0] * rtb_sincos_o1[1];
  tmp_0[0] = rtb_pqr[2] * rtb_sincos_o1[1];
  tmp_0[1] = rtb_pqr[0] * rtb_sincos_o1[2];
  tmp_0[2] = rtb_pqr[1] * rtb_sincos_o1[0];
  for (i = 0; i < 3; i++) {
    rtb_sincos_o1[i] = tmp[i] - tmp_0[i];

    /* Product: '<S19>/Product' */
    rtb_Product[i] = 0.0;
    rtb_Product[i] += 0.0 * rtb_pqr[0];
    rtb_Product[i] += 0.0 * rtb_pqr[1];
    rtb_Product[i] += 0.0 * rtb_pqr[2];
    rtb_sincos_o2_idx_0 = (rtb_sincos_o2_n[i] - rtb_Product[i]) -
      rtb_sincos_o1[i];

    /* Sum: '<S27>/Sum of Elements' incorporates:
     *  Sum: '<S7>/Sum2'
     */
    rtb_Product[i] = ((rtb_ImpAsg_InsertedFor_Forces_a[i + 3] +
                       rtb_ImpAsg_InsertedFor_Forces_a[i]) +
                      rtb_ImpAsg_InsertedFor_Forces_a[i + 6]) +
      rtb_ImpAsg_InsertedFor_Forces_a[i + 9];

    /* Gain: '<S26>/Gain1' */
    rtb_sincos_o1[i] = 0.063 * rtu_Environment->Gravity_ned[i];
    rtb_sincos_o2_n[i] = rtb_sincos_o2_idx_0;
  }

  /* End of Sum: '<S17>/Sum' */

  /* Product: '<S7>/Product2' */
  rt_mrdivide_U1d1x3_U2d_9vOrDY9Z(rtb_sincos_o2_n,
    nonlinearAirframe_ConstB.Selector2, localDW->Product2);

  /* Product: '<S26>/Product' */
  for (i = 0; i < 3; i++) {
    rtb_sincos_o2_n[i] = rtb_VectorConcatenate[i + 6] * rtb_sincos_o1[2] +
      (rtb_VectorConcatenate[i + 3] * rtb_sincos_o1[1] + rtb_VectorConcatenate[i]
       * rtb_sincos_o1[0]);
  }

  /* End of Product: '<S26>/Product' */

  /* Gain: '<S29>/1//2rhoV^2' incorporates:
   *  Product: '<S29>/Product2'
   *  Product: '<S30>/Product'
   *  Product: '<S30>/Product1'
   *  Product: '<S30>/Product2'
   *  Sum: '<S30>/Sum'
   */
  rtb_sincos_o2_idx_0 = ((rtb_UnitConversion[0] * rtb_UnitConversion[0] +
    rtb_UnitConversion[1] * rtb_UnitConversion[1]) + rtb_UnitConversion[2] *
    rtb_UnitConversion[2]) * rtu_Environment->AtmosphereBus.air_density * 0.5;
  if (rtmIsMajorTimeStep(nonlinearAirframe_M)) {
    /* Gain: '<S28>/Gain' incorporates:
     *  Constant: '<S28>/diameter'
     */
    localDW->Gain[0] = 0.0025;
    localDW->Gain[1] = 0.0025;
  }

  /* Product: '<S28>/Product' incorporates:
   *  Constant: '<S28>/diameter'
   *  Constant: '<S28>/dragCoeff'
   */
  rtb_sincos_o1[0] = rtb_sincos_o2_idx_0 * localDW->Gain[0] * 0.0;
  rtb_sincos_o1[1] = rtb_sincos_o2_idx_0 * localDW->Gain[1] * 0.0;
  rtb_sincos_o1[2] = rtb_sincos_o2_idx_0 * 0.01 * 0.0;

  /* Signum: '<S25>/Sign' incorporates:
   *  Sum: '<S24>/Add1'
   */
  if (rtb_UnitConversion[0] < 0.0) {
    rtb_sincos_o2_idx_0 = -1.0;
  } else if (rtb_UnitConversion[0] > 0.0) {
    rtb_sincos_o2_idx_0 = 1.0;
  } else if (rtb_UnitConversion[0] == 0.0) {
    rtb_sincos_o2_idx_0 = 0.0;
  } else {
    rtb_sincos_o2_idx_0 = (rtNaN);
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S8>/Constant'
   *  Gain: '<S25>/Gain3'
   *  Product: '<S25>/Product'
   *  Sum: '<S24>/Add1'
   */
  rtb_Product[0] = ((rtb_sincos_o1[0] * -rtb_sincos_o2_idx_0 + rtb_sincos_o2_n[0])
                    + rtb_Product[0]) / 0.063;

  /* Signum: '<S25>/Sign' incorporates:
   *  Sum: '<S24>/Add1'
   */
  if (rtb_UnitConversion[1] < 0.0) {
    rtb_sincos_o2_idx_0 = -1.0;
  } else if (rtb_UnitConversion[1] > 0.0) {
    rtb_sincos_o2_idx_0 = 1.0;
  } else if (rtb_UnitConversion[1] == 0.0) {
    rtb_sincos_o2_idx_0 = 0.0;
  } else {
    rtb_sincos_o2_idx_0 = (rtNaN);
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S8>/Constant'
   *  Gain: '<S25>/Gain3'
   *  Product: '<S25>/Product'
   *  Sum: '<S24>/Add1'
   */
  rtb_Product[1] = ((rtb_sincos_o1[1] * -rtb_sincos_o2_idx_0 + rtb_sincos_o2_n[1])
                    + rtb_Product[1]) / 0.063;

  /* Signum: '<S25>/Sign' incorporates:
   *  Sum: '<S24>/Add1'
   */
  if (rtb_UnitConversion[2] < 0.0) {
    rtb_sincos_o2_idx_0 = -1.0;
  } else if (rtb_UnitConversion[2] > 0.0) {
    rtb_sincos_o2_idx_0 = 1.0;
  } else if (rtb_UnitConversion[2] == 0.0) {
    rtb_sincos_o2_idx_0 = 0.0;
  } else {
    rtb_sincos_o2_idx_0 = (rtNaN);
  }

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S8>/Constant'
   *  Gain: '<S25>/Gain3'
   *  Product: '<S25>/Product'
   *  Sum: '<S24>/Add1'
   */
  rtb_Product[2] = ((rtb_sincos_o1[2] * -rtb_sincos_o2_idx_0 + rtb_sincos_o2_n[2])
                    + rtb_Product[2]) / 0.063;

  /* Sum: '<S9>/Sum' incorporates:
   *  Integrator: '<S2>/ub,vb,wb'
   *  Product: '<S22>/i x j'
   *  Product: '<S22>/j x k'
   *  Product: '<S22>/k x i'
   *  Product: '<S23>/i x k'
   *  Product: '<S23>/j x i'
   *  Product: '<S23>/k x j'
   */
  rtb_sincos_o1[0] = localX->ubvbwb_CSTATE[1] * rtb_pqr[2] -
    localX->ubvbwb_CSTATE[2] * rtb_pqr[1];
  rtb_sincos_o1[1] = localX->ubvbwb_CSTATE[2] * rtb_pqr[0] -
    localX->ubvbwb_CSTATE[0] * rtb_pqr[2];
  rtb_sincos_o1[2] = localX->ubvbwb_CSTATE[0] * rtb_pqr[1] -
    localX->ubvbwb_CSTATE[1] * rtb_pqr[0];
  for (i = 0; i < 3; i++) {
    /* Sum: '<S2>/Sum' */
    localDW->Sum[i] = rtb_Product[i] + rtb_sincos_o1[i];

    /* Product: '<S13>/Product' incorporates:
     *  Integrator: '<S2>/ub,vb,wb'
     *  Math: '<S2>/Transpose'
     */
    localDW->Product[i] = 0.0;
    localDW->Product[i] += rtb_VectorConcatenate[3 * i] * localX->ubvbwb_CSTATE
      [0];
    localDW->Product[i] += rtb_VectorConcatenate[3 * i + 1] *
      localX->ubvbwb_CSTATE[1];
    localDW->Product[i] += rtb_VectorConcatenate[3 * i + 2] *
      localX->ubvbwb_CSTATE[2];

    /* Trigonometry: '<S15>/sincos' incorporates:
     *  Integrator: '<S6>/phi theta psi'
     */
    rtb_sincos_o1[i] = sin(localX->phithetapsi_CSTATE[i]);
    rtb_sincos_o2_n[i] = cos(localX->phithetapsi_CSTATE[i]);
  }

  /* Outputs for Atomic SubSystem: '<S1>/Position on Earth' */
  /* UnitConversion: '<S44>/Unit Conversion' incorporates:
   *  Integrator: '<S2>/xe,ye,ze'
   *  Product: '<S43>/rad lat'
   *  Product: '<S43>/x*cos'
   *  Product: '<S43>/y*sin'
   *  Sum: '<S43>/Sum'
   */
  /* Unit Conversion - from: rad to: deg
     Expression: output = (57.2958*input) + (0) */
  rtb_sincos_o2_idx_0 = (localX->xeyeze_CSTATE[0] - localX->xeyeze_CSTATE[1] *
    0.0) * 1.5712488599660137E-7 * 57.295779513082323;

  /* Switch: '<S48>/Switch' incorporates:
   *  Abs: '<S48>/Abs'
   *  Bias: '<S48>/Bias'
   *  Bias: '<S48>/Bias1'
   *  Constant: '<S48>/Constant2'
   *  Constant: '<S49>/Constant'
   *  Math: '<S48>/Math Function1'
   *  RelationalOperator: '<S49>/Compare'
   *  Sum: '<S40>/Sum'
   */
  if (fabs(rtb_sincos_o2_idx_0 + 42.299886) > 180.0) {
    rtb_sincos_o2_idx_0 = rt_modd_snf((rtb_sincos_o2_idx_0 + 42.299886) + 180.0,
      360.0) + -180.0;
  } else {
    rtb_sincos_o2_idx_0 += 42.299886;
  }

  /* End of Switch: '<S48>/Switch' */

  /* Abs: '<S45>/Abs1' */
  rtb_LLA_idx_0 = fabs(rtb_sincos_o2_idx_0);

  /* Switch: '<S45>/Switch' incorporates:
   *  Bias: '<S45>/Bias'
   *  Bias: '<S45>/Bias1'
   *  Constant: '<S41>/Constant'
   *  Constant: '<S41>/Constant1'
   *  Constant: '<S47>/Constant'
   *  Gain: '<S45>/Gain'
   *  Product: '<S45>/Divide1'
   *  RelationalOperator: '<S47>/Compare'
   *  Switch: '<S41>/Switch1'
   */
  if (rtb_LLA_idx_0 > 90.0) {
    /* Signum: '<S45>/Sign1' */
    if (rtb_sincos_o2_idx_0 < 0.0) {
      rtb_sincos_o2_idx_0 = -1.0;
    } else if (rtb_sincos_o2_idx_0 > 0.0) {
      rtb_sincos_o2_idx_0 = 1.0;
    } else if (rtb_sincos_o2_idx_0 == 0.0) {
      rtb_sincos_o2_idx_0 = 0.0;
    } else {
      rtb_sincos_o2_idx_0 = (rtNaN);
    }

    /* End of Signum: '<S45>/Sign1' */
    rtb_sincos_o2_idx_0 *= -(rtb_LLA_idx_0 + -90.0) + 90.0;
    i = 180;
  } else {
    i = 0;
  }

  /* End of Switch: '<S45>/Switch' */

  /* Sum: '<S41>/Sum' incorporates:
   *  Integrator: '<S2>/xe,ye,ze'
   *  Product: '<S43>/rad long '
   *  Product: '<S43>/x*sin'
   *  Product: '<S43>/y*cos'
   *  Sum: '<S40>/Sum'
   *  Sum: '<S43>/Sum1'
   *  UnitConversion: '<S44>/Unit Conversion'
   */
  rtb_LLA_idx_0 = ((localX->xeyeze_CSTATE[0] * 0.0 + localX->xeyeze_CSTATE[1]) *
                   2.1165609521537427E-7 * 57.295779513082323 +
                   nonlinearAirframe_ConstB.Switch_d) + (real_T)i;

  /* Switch: '<S46>/Switch' incorporates:
   *  Abs: '<S46>/Abs'
   *  Bias: '<S46>/Bias'
   *  Bias: '<S46>/Bias1'
   *  Constant: '<S46>/Constant2'
   *  Constant: '<S50>/Constant'
   *  Math: '<S46>/Math Function1'
   *  RelationalOperator: '<S50>/Compare'
   */
  if (fabs(rtb_LLA_idx_0) > 180.0) {
    rtb_LLA_idx_0 = rt_modd_snf(rtb_LLA_idx_0 + 180.0, 360.0) + -180.0;
  }

  /* End of Switch: '<S46>/Switch' */
  /* End of Outputs for SubSystem: '<S1>/Position on Earth' */

  /* Fcn: '<S15>/phidot' incorporates:
   *  Fcn: '<S15>/psidot'
   */
  rtb_sincos_o2_idx_1 = rtb_pqr[1] * rtb_sincos_o1[0] + rtb_pqr[2] *
    rtb_sincos_o2_n[0];

  /* SignalConversion generated from: '<S6>/phi theta psi' incorporates:
   *  Fcn: '<S15>/phidot'
   *  Fcn: '<S15>/psidot'
   *  Fcn: '<S15>/thetadot'
   */
  localDW->TmpSignalConversionAtphithetaps[0] = rtb_sincos_o2_idx_1 *
    (rtb_sincos_o1[1] / rtb_sincos_o2_n[1]) + rtb_pqr[0];
  localDW->TmpSignalConversionAtphithetaps[1] = rtb_pqr[1] * rtb_sincos_o2_n[0]
    - rtb_pqr[2] * rtb_sincos_o1[0];
  localDW->TmpSignalConversionAtphithetaps[2] = rtb_sincos_o2_idx_1 /
    rtb_sincos_o2_n[1];

  /* BusCreator: '<S4>/Bus Creator5' incorporates:
   *  Constant: '<S5>/href'
   *  Integrator: '<S2>/xe,ye,ze'
   *  Integrator: '<S6>/phi theta psi'
   *  SignalConversion generated from: '<S4>/Bus Creator5'
   *  Sum: '<S40>/Sum1'
   *  UnaryMinus: '<S40>/Ze2height'
   */
  rty_States->V_body[0] = rtb_UnitConversion[0];
  rty_States->Omega_body[0] = rtb_pqr[0];
  rty_States->Euler[0] = localX->phithetapsi_CSTATE[0];
  rty_States->Accel_body[0] = rtb_Product[0];
  rty_States->dOmega_body[0] = localDW->Product2[0];
  rty_States->V_ned[0] = localDW->Product[0];
  rty_States->X_ned[0] = localX->xeyeze_CSTATE[0];
  rty_States->V_body[1] = rtb_UnitConversion[1];
  rty_States->Omega_body[1] = rtb_pqr[1];
  rty_States->Euler[1] = localX->phithetapsi_CSTATE[1];
  rty_States->Accel_body[1] = rtb_Product[1];
  rty_States->dOmega_body[1] = localDW->Product2[1];
  rty_States->V_ned[1] = localDW->Product[1];
  rty_States->X_ned[1] = localX->xeyeze_CSTATE[1];
  rty_States->V_body[2] = rtb_UnitConversion[2];
  rty_States->Omega_body[2] = rtb_pqr[2];
  rty_States->Euler[2] = localX->phithetapsi_CSTATE[2];
  rty_States->Accel_body[2] = rtb_Product[2];
  rty_States->dOmega_body[2] = localDW->Product2[2];
  rty_States->V_ned[2] = localDW->Product[2];
  rty_States->X_ned[2] = localX->xeyeze_CSTATE[2];
  rty_States->LLA[0] = rtb_sincos_o2_idx_0;
  rty_States->LLA[1] = rtb_LLA_idx_0;

  /* Outputs for Atomic SubSystem: '<S1>/Position on Earth' */
  rty_States->LLA[2] = -localX->xeyeze_CSTATE[2] - -71.3232;

  /* End of Outputs for SubSystem: '<S1>/Position on Earth' */
  memcpy(&rty_States->DCM_be[0], &rtb_VectorConcatenate[0], 9U * sizeof(real_T));

  /* End of Outputs for SubSystem: '<Root>/Nonlinear' */
}

/* Update for referenced model: 'nonlinearAirframe' */
void nonlinearAirframe_Update(void)
{
}

/* Derivatives for referenced model: 'nonlinearAirframe' */
void nonlinearAirframe_Deriv(DW_nonlinearAirframe_f_T *localDW,
  XDot_nonlinearAirframe_n_T *localXdot)
{
  /* Derivatives for Atomic SubSystem: '<Root>/Nonlinear' */
  /* Derivatives for Integrator: '<S6>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[0] = localDW->TmpSignalConversionAtphithetaps[0];

  /* Derivatives for Integrator: '<S2>/p,q,r ' */
  localXdot->pqr_CSTATE[0] = localDW->Product2[0];

  /* Derivatives for Integrator: '<S2>/ub,vb,wb' */
  localXdot->ubvbwb_CSTATE[0] = localDW->Sum[0];

  /* Derivatives for Integrator: '<S2>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[0] = localDW->Product[0];

  /* Derivatives for Integrator: '<S6>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[1] = localDW->TmpSignalConversionAtphithetaps[1];

  /* Derivatives for Integrator: '<S2>/p,q,r ' */
  localXdot->pqr_CSTATE[1] = localDW->Product2[1];

  /* Derivatives for Integrator: '<S2>/ub,vb,wb' */
  localXdot->ubvbwb_CSTATE[1] = localDW->Sum[1];

  /* Derivatives for Integrator: '<S2>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[1] = localDW->Product[1];

  /* Derivatives for Integrator: '<S6>/phi theta psi' */
  localXdot->phithetapsi_CSTATE[2] = localDW->TmpSignalConversionAtphithetaps[2];

  /* Derivatives for Integrator: '<S2>/p,q,r ' */
  localXdot->pqr_CSTATE[2] = localDW->Product2[2];

  /* Derivatives for Integrator: '<S2>/ub,vb,wb' */
  localXdot->ubvbwb_CSTATE[2] = localDW->Sum[2];

  /* Derivatives for Integrator: '<S2>/xe,ye,ze' */
  localXdot->xeyeze_CSTATE[2] = localDW->Product[2];

  /* End of Derivatives for SubSystem: '<Root>/Nonlinear' */
}

/* Model initialize function */
void nonlinearAirframe_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo, RT_MODEL_nonlinearAirframe_T *
  const nonlinearAirframe_M)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(nonlinearAirframe_M, rt_errorStatus);

  /* initialize stop requested flag */
  rtmSetStopRequestedPtr(nonlinearAirframe_M, rt_stopRequested);

  /* initialize RTWSolverInfo */
  nonlinearAirframe_M->solverInfo = (rt_solverInfo);

  /* Set the Timing fields to the appropriate data in the RTWSolverInfo */
  rtmSetSimTimeStepPointer(nonlinearAirframe_M, rtsiGetSimTimeStepPtr
    (nonlinearAirframe_M->solverInfo));
  nonlinearAirframe_M->Timing.stepSize0 = (rtsiGetStepSize
    (nonlinearAirframe_M->solverInfo));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
