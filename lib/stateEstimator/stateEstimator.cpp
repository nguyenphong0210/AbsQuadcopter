/*
 * File: stateEstimator.c
 *
 * Code generated for Simulink model 'stateEstimator'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Nov 19 00:05:16 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "stateEstimator.h"
#include "rt_powf_snf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

MdlrefDW_stateEstimator_T stateEstimator_MdlrefDW;

/* Block states (default storage) */
DW_stateEstimator_f_T stateEstimator_DW;
extern const real_T rtCP_pooled_b5NceP1yVsZG[4];
extern const real_T rtCP_pooled_OlAt8KbpQEG0[3];
extern const real32_T rtCP_pooled_kqUvCpwgnPyl[4];
extern const real32_T rtCP_pooled_bW9qz7zDL7dr[4];
extern const real32_T rtCP_pooled_aLwfmFKBoRwh[6];
extern const real32_T rtCP_pooled_2aITfOsIWEfl[6];
extern const real32_T rtCP_pooled_KvfM2cKww6Wz[6];
extern const real32_T rtCP_pooled_adLCBuYxtU1Q[6];
extern const real32_T rtCP_pooled_VH0dmwbCQMUq[6];

#define rtCP_A_Value                   rtCP_pooled_b5NceP1yVsZG  /* Expression: pInitialization.A
                                                                  * Referenced by: '<S14>/A'
                                                                  */
#define rtCP_gravity_Value             rtCP_pooled_OlAt8KbpQEG0  /* Expression: [0 0 g]
                                                                  * Referenced by: '<S3>/gravity'
                                                                  */
#define rtCP_C_Value_f                 rtCP_pooled_kqUvCpwgnPyl  /* Computed Parameter: rtCP_C_Value_f
                                                                  * Referenced by: '<S76>/C'
                                                                  */
#define rtCP_D_Value_f                 rtCP_pooled_bW9qz7zDL7dr  /* Computed Parameter: rtCP_D_Value_f
                                                                  * Referenced by: '<S76>/D'
                                                                  */
#define rtCP_C_Value_p                 rtCP_pooled_kqUvCpwgnPyl  /* Computed Parameter: rtCP_C_Value_p
                                                                  * Referenced by: '<S145>/C'
                                                                  */
#define rtCP_D_Value_b                 rtCP_pooled_bW9qz7zDL7dr  /* Computed Parameter: rtCP_D_Value_b
                                                                  * Referenced by: '<S145>/D'
                                                                  */
#define rtCP_Assumingthatcalibwasdonelevel_Bias rtCP_pooled_aLwfmFKBoRwh/* Computed Parameter: rtCP_Assumingthatcalibwasdonelevel_Bias
                                                                      * Referenced by: '<S5>/Assuming that calib was done level!'
                                                                      */
#define rtCP_inverseIMU_gain_Gain      rtCP_pooled_2aITfOsIWEfl  /* Computed Parameter: rtCP_inverseIMU_gain_Gain
                                                                  * Referenced by: '<S5>/inverseIMU_gain'
                                                                  */
#define rtCP_FIR_IMUaccel_Coefficients rtCP_pooled_KvfM2cKww6Wz  /* Computed Parameter: rtCP_FIR_IMUaccel_Coefficients
                                                                  * Referenced by: '<S5>/FIR_IMUaccel'
                                                                  */
#define rtCP_IIR_IMUgyro_r_NumCoef     rtCP_pooled_adLCBuYxtU1Q  /* Computed Parameter: rtCP_IIR_IMUgyro_r_NumCoef
                                                                  * Referenced by: '<S5>/IIR_IMUgyro_r'
                                                                  */
#define rtCP_IIR_IMUgyro_r_DenCoef     rtCP_pooled_VH0dmwbCQMUq  /* Computed Parameter: rtCP_IIR_IMUgyro_r_DenCoef
                                                                  * Referenced by: '<S5>/IIR_IMUgyro_r'
                                                                  */
#define rtCP_IIRgyroz_NumCoef          rtCP_pooled_adLCBuYxtU1Q  /* Computed Parameter: rtCP_IIRgyroz_NumCoef
                                                                  * Referenced by: '<S75>/IIRgyroz'
                                                                  */
#define rtCP_IIRgyroz_DenCoef          rtCP_pooled_VH0dmwbCQMUq  /* Computed Parameter: rtCP_IIRgyroz_DenCoef
                                                                  * Referenced by: '<S75>/IIRgyroz'
                                                                  */

/*
 * Disable for enable system:
 *    '<S113>/MeasurementUpdate'
 *    '<S167>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[2],
  DW_MeasurementUpdate_stateEstimator_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S113>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S142>/Enable'
   */
  /* Disable for Outport: '<S142>/L*(y[k]-yhat[k|k-1])' */
  rty_Lykyhatkk1[0] = 0.0F;
  rty_Lykyhatkk1[1] = 0.0F;

  /* End of Outputs for SubSystem: '<S113>/MeasurementUpdate' */
  localDW->MeasurementUpdate_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S113>/MeasurementUpdate'
 *    '<S167>/MeasurementUpdate'
 */
void stateEstimator_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
  rtu_Lk[4], const real32_T rtu_yk[2], const real32_T rtu_Ck[4], const real32_T
  rtu_xhatkk1[2], const real32_T rtu_Dk[4], const real32_T rtu_uk[2], real32_T
  rty_Lykyhatkk1[2], DW_MeasurementUpdate_stateEstimator_T *localDW)
{
  real32_T rtu_yk_idx_0;
  real32_T rtu_yk_idx_1;

  /* Outputs for Enabled SubSystem: '<S113>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S142>/Enable'
   */
  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;

    /* Sum: '<S142>/Sum' incorporates:
     *  Product: '<S142>/C[k]*xhat[k|k-1]'
     *  Product: '<S142>/D[k]*u[k]'
     *  Sum: '<S142>/Add1'
     */
    rtu_yk_idx_0 = rtu_yk[0] - ((rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[2] *
      rtu_xhatkk1[1]) + (rtu_Dk[0] * rtu_uk[0] + rtu_Dk[2] * rtu_uk[1]));
    rtu_yk_idx_1 = rtu_yk[1] - ((rtu_Ck[1] * rtu_xhatkk1[0] + rtu_Ck[3] *
      rtu_xhatkk1[1]) + (rtu_Dk[1] * rtu_uk[0] + rtu_Dk[3] * rtu_uk[1]));

    /* Product: '<S142>/Product3' */
    rty_Lykyhatkk1[0] = 0.0F;
    rty_Lykyhatkk1[0] += rtu_Lk[0] * rtu_yk_idx_0;
    rty_Lykyhatkk1[0] += rtu_Lk[2] * rtu_yk_idx_1;
    rty_Lykyhatkk1[1] = 0.0F;
    rty_Lykyhatkk1[1] += rtu_Lk[1] * rtu_yk_idx_0;
    rty_Lykyhatkk1[1] += rtu_Lk[3] * rtu_yk_idx_1;
  } else {
    if (localDW->MeasurementUpdate_MODE) {
      stateEstimator_MeasurementUpdate_Disable(rty_Lykyhatkk1, localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S113>/MeasurementUpdate' */
}

/*
 * Disable for enable system:
 *    '<S120>/Enabled Subsystem'
 *    '<S174>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem_Disable(real32_T rty_deltax[2],
  DW_EnabledSubsystem_stateEstimator_T *localDW)
{
  /* Outputs for Enabled SubSystem: '<S120>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S144>/Enable'
   */
  /* Disable for Outport: '<S144>/deltax' */
  rty_deltax[0] = 0.0F;
  rty_deltax[1] = 0.0F;

  /* End of Outputs for SubSystem: '<S120>/Enabled Subsystem' */
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S120>/Enabled Subsystem'
 *    '<S174>/Enabled Subsystem'
 */
void stateEstimator_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[4], const real32_T rtu_Ck[4], const real32_T rtu_yk[2], const real32_T
  rtu_xhatkk1[2], real32_T rty_deltax[2], DW_EnabledSubsystem_stateEstimator_T
  *localDW)
{
  real32_T rtu_yk_idx_0;
  real32_T rtu_yk_idx_1;

  /* Outputs for Enabled SubSystem: '<S120>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S144>/Enable'
   */
  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    /* Sum: '<S144>/Add1' incorporates:
     *  Product: '<S144>/Product'
     */
    rtu_yk_idx_0 = rtu_yk[0] - (rtu_Ck[0] * rtu_xhatkk1[0] + rtu_Ck[2] *
      rtu_xhatkk1[1]);
    rtu_yk_idx_1 = rtu_yk[1] - (rtu_Ck[1] * rtu_xhatkk1[0] + rtu_Ck[3] *
      rtu_xhatkk1[1]);

    /* Product: '<S144>/Product2' */
    rty_deltax[0] = 0.0F;
    rty_deltax[0] += rtu_Mk[0] * rtu_yk_idx_0;
    rty_deltax[0] += rtu_Mk[2] * rtu_yk_idx_1;
    rty_deltax[1] = 0.0F;
    rty_deltax[1] += rtu_Mk[1] * rtu_yk_idx_0;
    rty_deltax[1] += rtu_Mk[3] * rtu_yk_idx_1;
  } else {
    if (localDW->EnabledSubsystem_MODE) {
      stateEstimator_EnabledSubsystem_Disable(rty_deltax, localDW);
    }
  }

  /* End of Outputs for SubSystem: '<S120>/Enabled Subsystem' */
}

/* System initialize for referenced model: 'stateEstimator' */
void stateEstimator_Init(void)
{
  /* InitializeConditions for Delay: '<S76>/MemoryX' */
  stateEstimator_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = 1U;

  /* InitializeConditions for Delay: '<S145>/MemoryX' */
  stateEstimator_DW.icLoad_g = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = 2;
}

/* Disable for referenced model: 'stateEstimator' */
void stateEstimator_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S42>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_MODE) {
    /* Disable for Outport: '<S66>/deltax' */
    stateEstimator_DW.Product2[0] = 0.0;
    stateEstimator_DW.Product2[1] = 0.0;
    stateEstimator_DW.EnabledSubsystem_MODE = false;
  }

  /* End of Disable for SubSystem: '<S42>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S120>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_f.EnabledSubsystem_MODE) {
    stateEstimator_EnabledSubsystem_Disable(stateEstimator_DW.Product2_k,
      &stateEstimator_DW.EnabledSubsystem_f);
  }

  /* End of Disable for SubSystem: '<S120>/Enabled Subsystem' */

  /* Disable for Enabled SubSystem: '<S113>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_e.MeasurementUpdate_MODE) {
    stateEstimator_MeasurementUpdate_Disable(stateEstimator_DW.Product3_m,
      &stateEstimator_DW.MeasurementUpdate_e);
  }

  /* End of Disable for SubSystem: '<S113>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S36>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_MODE) {
    /* Disable for Outport: '<S64>/L*(y[k]-yhat[k|k-1])' */
    stateEstimator_DW.Product3[0] = 0.0;
    stateEstimator_DW.Product3[1] = 0.0;
    stateEstimator_DW.MeasurementUpdate_MODE = false;
  }

  /* End of Disable for SubSystem: '<S36>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S167>/MeasurementUpdate' */
  if (stateEstimator_DW.MeasurementUpdate_b.MeasurementUpdate_MODE) {
    stateEstimator_MeasurementUpdate_Disable(stateEstimator_DW.Product3_j,
      &stateEstimator_DW.MeasurementUpdate_b);
  }

  /* End of Disable for SubSystem: '<S167>/MeasurementUpdate' */

  /* Disable for Enabled SubSystem: '<S174>/Enabled Subsystem' */
  if (stateEstimator_DW.EnabledSubsystem_m.EnabledSubsystem_MODE) {
    stateEstimator_EnabledSubsystem_Disable(stateEstimator_DW.Product2_e,
      &stateEstimator_DW.EnabledSubsystem_m);
  }

  /* End of Disable for SubSystem: '<S174>/Enabled Subsystem' */
}

/* Output and update for referenced model: 'stateEstimator' */
void stateEstimator_run(const boolean_T arg_controlModePosVSOrient_flagin, const
  sensordata_t *arg_sensordata_datin, const real32_T arg_usePosVIS_flagin, const
  real32_T arg_opticalFlow_datin[3], const real32_T arg_posVIS_datin[4],
  statesEstim_t *arg_states_estimout, const real32_T
  arg_sensorCalibration_datin[8])
{
  int32_T cff;
  int32_T denIdx;
  real32_T rtb_Product_n[3];
  real32_T rtb_VectorConcatenate[9];
  real32_T rtb_sincos_o2[3];
  real32_T rtb_r;
  real32_T rtb_Product[3];
  real32_T rtb_sincos_o1[3];
  boolean_T rtb_LogicalOperator_cg;
  real32_T rtb_SimplyIntegrateVelocity[2];
  boolean_T rtb_Compare_i;
  real32_T rtb_Product_a[2];
  real32_T rtb_MathFunction[9];
  real32_T rtb_FIR_IMUaccel[3];
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_b3;
  real32_T rtb_Merge1;
  real32_T rtb_VectorConcatenate_e[9];
  real32_T rtb_DataTypeConversion;
  real32_T rtb_TSamp[2];
  real_T rtb_Sum_i;
  real32_T rtb_MemoryX_e[2];
  real32_T rtb_DataTypeConversion2;
  real32_T rtb_Sqrt;
  real_T rtb_Sum[3];
  real32_T inverseIMU_gain[6];
  int32_T i;
  int32_T i_0;
  real32_T arg_sensordata_datin_0[6];
  real_T rtb_VectorConcatenate_1[3];
  real_T rtb_FIR_IMUaccel_0[3];
  real32_T tmp[2];
  real32_T tmp_0[2];
  real_T tmp_1[2];
  real_T rtb_Add_idx_0;
  real32_T rtb_VectorConcatenate_tmp;
  real32_T rtb_VectorConcatenate_tmp_0;
  real32_T rtb_sincos_o2_tmp;
  real32_T rtb_sincos_o1_tmp;
  real32_T rtb_sincos_o2_tmp_0;

  /* Trigonometry: '<S12>/Trigonometric Function' incorporates:
   *  Memory: '<S2>/Memory'
   *  SignalConversion generated from: '<S12>/Trigonometric Function'
   */
  rtb_sincos_o2[0] = (real32_T)sin(stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_Product_n[0] = (real32_T)cos(stateEstimator_DW.Memory_PreviousInput[2]);
  rtb_sincos_o2[1] = (real32_T)sin(stateEstimator_DW.Memory_PreviousInput[1]);
  rtb_Product_n[1] = (real32_T)cos(stateEstimator_DW.Memory_PreviousInput[1]);

  /* SignalConversion generated from: '<S13>/Vector Concatenate' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_VectorConcatenate[0] = 0.0F;

  /* SignalConversion generated from: '<S13>/Vector Concatenate' incorporates:
   *  Constant: '<S12>/Constant'
   */
  rtb_VectorConcatenate[1] = 0.0F;

  /* SignalConversion generated from: '<S13>/Vector Concatenate' */
  rtb_VectorConcatenate[2] = rtb_Product_n[1];

  /* SignalConversion generated from: '<S13>/Vector Concatenate' */
  rtb_VectorConcatenate[3] = rtb_sincos_o2[0];

  /* Product: '<S12>/Product1' */
  rtb_VectorConcatenate[4] = rtb_Product_n[0] * rtb_Product_n[1];

  /* Product: '<S12>/Product3' */
  rtb_VectorConcatenate[5] = rtb_sincos_o2[0] * rtb_sincos_o2[1];

  /* SignalConversion generated from: '<S13>/Vector Concatenate' */
  rtb_VectorConcatenate[6] = rtb_Product_n[0];

  /* Product: '<S12>/Product2' incorporates:
   *  Gain: '<S12>/Gain'
   */
  rtb_VectorConcatenate[7] = rtb_Product_n[1] * -rtb_sincos_o2[0];

  /* Product: '<S12>/Product4' */
  rtb_VectorConcatenate[8] = rtb_Product_n[0] * rtb_sincos_o2[1];

  /* Product: '<S12>/Divide' */
  for (cff = 0; cff < 9; cff++) {
    rtb_VectorConcatenate[cff] /= rtb_Product_n[1];
  }

  /* End of Product: '<S12>/Divide' */

  /* Bias: '<S5>/Assuming that calib was done level!' */
  for (i = 0; i < 6; i++) {
    rtb_MathFunction[i] = arg_sensorCalibration_datin[i] +
      rtCP_Assumingthatcalibwasdonelevel_Bias[i];
  }

  /* End of Bias: '<S5>/Assuming that calib was done level!' */

  /* Sum: '<S5>/Sum1' */
  arg_sensordata_datin_0[0] = arg_sensordata_datin->ddx - rtb_MathFunction[0];
  arg_sensordata_datin_0[1] = arg_sensordata_datin->ddy - rtb_MathFunction[1];
  arg_sensordata_datin_0[2] = arg_sensordata_datin->ddz - rtb_MathFunction[2];
  arg_sensordata_datin_0[3] = arg_sensordata_datin->p - rtb_MathFunction[3];
  arg_sensordata_datin_0[4] = arg_sensordata_datin->q - rtb_MathFunction[4];
  arg_sensordata_datin_0[5] = arg_sensordata_datin->r - rtb_MathFunction[5];
  for (i = 0; i < 6; i++) {
    /* Gain: '<S5>/inverseIMU_gain' */
    inverseIMU_gain[i] = rtCP_inverseIMU_gain_Gain[i] * arg_sensordata_datin_0[i];
  }

  /* End of Sum: '<S5>/Sum1' */

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_Merge1 = inverseIMU_gain[0] * 0.0264077242F;
  cff = 1;
  for (i = stateEstimator_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    rtb_Merge1 += stateEstimator_DW.FIR_IMUaccel_states[i] *
      rtCP_FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (i = 0; i < stateEstimator_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_Merge1 += stateEstimator_DW.FIR_IMUaccel_states[i] *
      rtCP_FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[0] = rtb_Merge1;

  /* Math: '<S2>/Math Function' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  rtb_sincos_o2[0] = rt_powf_snf(rtb_Merge1, 2.0F);

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_Merge1 = inverseIMU_gain[1] * 0.0264077242F;
  cff = 1;
  for (i = stateEstimator_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    rtb_Merge1 += stateEstimator_DW.FIR_IMUaccel_states[i + 5] *
      rtCP_FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (i = 0; i < stateEstimator_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_Merge1 += stateEstimator_DW.FIR_IMUaccel_states[i + 5] *
      rtCP_FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[1] = rtb_Merge1;

  /* Math: '<S2>/Math Function' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   */
  rtb_r = rt_powf_snf(rtb_Merge1, 2.0F);

  /* DiscreteFir: '<S5>/FIR_IMUaccel' */
  rtb_Merge1 = inverseIMU_gain[2] * 0.0264077242F;
  cff = 1;
  for (i = stateEstimator_DW.FIR_IMUaccel_circBuf; i < 5; i++) {
    rtb_Merge1 += stateEstimator_DW.FIR_IMUaccel_states[i + 10] *
      rtCP_FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  for (i = 0; i < stateEstimator_DW.FIR_IMUaccel_circBuf; i++) {
    rtb_Merge1 += stateEstimator_DW.FIR_IMUaccel_states[i + 10] *
      rtCP_FIR_IMUaccel_Coefficients[cff];
    cff++;
  }

  rtb_FIR_IMUaccel[2] = rtb_Merge1;

  /* Sqrt: '<S2>/Sqrt' incorporates:
   *  DiscreteFir: '<S5>/FIR_IMUaccel'
   *  Math: '<S2>/Math Function'
   *  Sum: '<S2>/Sum of Elements'
   */
  rtb_r = (real32_T)sqrt((rtb_sincos_o2[0] + rtb_r) + rt_powf_snf(rtb_Merge1,
    2.0F));

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  rtb_Compare = (rtb_r > 9.79038F);

  /* RelationalOperator: '<S7>/Compare' incorporates:
   *  Constant: '<S7>/Constant'
   */
  rtb_Compare_b3 = (rtb_r < 9.82962F);

  /* DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  rtb_DataTypeConversion = inverseIMU_gain[5];
  denIdx = 1;
  for (i = 0; i < 5; i++) {
    rtb_DataTypeConversion -= rtCP_IIR_IMUgyro_r_DenCoef[denIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[i];
    denIdx++;
  }

  stateEstimator_DW.IIR_IMUgyro_r_tmp = rtb_DataTypeConversion;
  rtb_r = 0.282124132F * stateEstimator_DW.IIR_IMUgyro_r_tmp;
  denIdx = 1;
  for (i = 0; i < 5; i++) {
    rtb_r += rtCP_IIR_IMUgyro_r_NumCoef[denIdx] *
      stateEstimator_DW.IIR_IMUgyro_r_states[i];
    denIdx++;
  }

  /* End of DiscreteFilter: '<S5>/IIR_IMUgyro_r' */

  /* Product: '<S2>/Product' incorporates:
   *  SignalConversion generated from: '<S2>/Product'
   */
  for (cff = 0; cff < 3; cff++) {
    rtb_Product_n[cff] = rtb_VectorConcatenate[cff + 6] * rtb_r +
      (rtb_VectorConcatenate[cff + 3] * inverseIMU_gain[4] +
       rtb_VectorConcatenate[cff] * inverseIMU_gain[3]);
  }

  /* End of Product: '<S2>/Product' */

  /* Gain: '<S2>/Gain' */
  rtb_sincos_o2[0] = 0.005F * rtb_Product_n[2];

  /* Sum: '<S2>/Sum' incorporates:
   *  Gain: '<S2>/Gain'
   *  Memory: '<S2>/Memory'
   *  SignalConversion generated from: '<S12>/Trigonometric Function'
   */
  rtb_Product_n[2] = 0.005F * rtb_Product_n[0] +
    stateEstimator_DW.Memory_PreviousInput[0];

  /* If: '<S2>/If' incorporates:
   *  Gain: '<S2>/Gain'
   *  Inport: '<S10>/prin'
   *  Logic: '<S2>/Logical Operator'
   *  Memory: '<S2>/Memory'
   *  SignalConversion generated from: '<S12>/Trigonometric Function'
   *  Sum: '<S2>/Sum'
   */
  if (rtb_Compare && rtb_Compare_b3) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Sum: '<S8>/Sum' incorporates:
     *  DiscreteFir: '<S5>/FIR_IMUaccel'
     *  Gain: '<S8>/Gain'
     *  Gain: '<S8>/Gain1'
     *  Memory: '<S2>/Memory'
     *  Product: '<S8>/Divide'
     *  SignalConversion generated from: '<S12>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function'
     */
    stateEstimator_DW.Merge[1] = (stateEstimator_DW.Memory_PreviousInput[2] +
      rtb_sincos_o2[0]) * 0.999F + (real32_T)atan(rtb_FIR_IMUaccel[1] /
      rtb_Merge1) * 0.001F;

    /* Gain: '<S8>/Gain2' */
    rtb_Merge1 = 0.101936802F * rtb_FIR_IMUaccel[0];

    /* Trigonometry: '<S8>/Trigonometric Function1' */
    if (rtb_Merge1 > 1.0F) {
      rtb_Merge1 = 1.0F;
    } else {
      if (rtb_Merge1 < -1.0F) {
        rtb_Merge1 = -1.0F;
      }
    }

    /* Sum: '<S8>/Sum1' incorporates:
     *  Gain: '<S2>/Gain'
     *  Gain: '<S8>/Gain3'
     *  Gain: '<S8>/Gain4'
     *  Memory: '<S2>/Memory'
     *  SignalConversion generated from: '<S12>/Trigonometric Function'
     *  Sum: '<S2>/Sum'
     *  Trigonometry: '<S8>/Trigonometric Function1'
     */
    stateEstimator_DW.Merge[0] = (0.005F * rtb_Product_n[1] +
      stateEstimator_DW.Memory_PreviousInput[1]) * 0.999F + 0.001F * (real32_T)
      asin(rtb_Merge1);

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    stateEstimator_DW.Merge[0] = 0.005F * rtb_Product_n[1] +
      stateEstimator_DW.Memory_PreviousInput[1];
    stateEstimator_DW.Merge[1] = stateEstimator_DW.Memory_PreviousInput[2] +
      rtb_sincos_o2[0];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem2' */
  }

  /* End of If: '<S2>/If' */

  /* If: '<S2>/If1' incorporates:
   *  Constant: '<S204>/Constant'
   *  Inport: '<S11>/yawin'
   *  Logic: '<S5>/Logical Operator'
   *  RelationalOperator: '<S204>/Compare'
   */
  if ((arg_posVIS_datin[0] != -99.0F) && (arg_usePosVIS_flagin != 0.0F)) {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* Sum: '<S9>/Sum' incorporates:
     *  Gain: '<S9>/Gain'
     *  Gain: '<S9>/Gain1'
     */
    rtb_Merge1 = 0.8F * rtb_Product_n[2] + 0.2F * arg_posVIS_datin[3];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S2>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    rtb_Merge1 = rtb_Product_n[2];

    /* End of Outputs for SubSystem: '<S2>/If Action Subsystem3' */
  }

  /* End of If: '<S2>/If1' */

  /* SignalConversion generated from: '<S16>/sincos' */
  rtb_Product_n[0] = rtb_Merge1;
  rtb_Product_n[1] = stateEstimator_DW.Merge[0];
  rtb_Product_n[2] = stateEstimator_DW.Merge[1];

  /* Trigonometry: '<S16>/sincos' incorporates:
   *  SignalConversion generated from: '<S16>/sincos'
   *  Trigonometry: '<S147>/sincos'
   */
  rtb_DataTypeConversion = (real32_T)sin(rtb_Merge1);
  rtb_sincos_o2_tmp = (real32_T)cos(rtb_Merge1);
  rtb_DataTypeConversion2 = (real32_T)sin(stateEstimator_DW.Merge[0]);
  rtb_Sqrt = (real32_T)cos(stateEstimator_DW.Merge[0]);
  rtb_sincos_o1_tmp = (real32_T)sin(stateEstimator_DW.Merge[1]);
  rtb_sincos_o2_tmp_0 = (real32_T)cos(stateEstimator_DW.Merge[1]);

  /* Fcn: '<S16>/Fcn11' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate[0] = rtb_Sqrt * rtb_sincos_o2_tmp;

  /* Fcn: '<S16>/Fcn21' incorporates:
   *  Fcn: '<S16>/Fcn22'
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o1_tmp * rtb_DataTypeConversion2;
  rtb_VectorConcatenate[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o2_tmp -
    rtb_sincos_o2_tmp_0 * rtb_DataTypeConversion;

  /* Fcn: '<S16>/Fcn31' incorporates:
   *  Fcn: '<S16>/Fcn32'
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_tmp_0 * rtb_DataTypeConversion2;
  rtb_VectorConcatenate[2] = rtb_VectorConcatenate_tmp_0 * rtb_sincos_o2_tmp +
    rtb_sincos_o1_tmp * rtb_DataTypeConversion;

  /* Fcn: '<S16>/Fcn12' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate[3] = rtb_Sqrt * rtb_DataTypeConversion;

  /* Fcn: '<S16>/Fcn22' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate[4] = rtb_VectorConcatenate_tmp * rtb_DataTypeConversion
    + rtb_sincos_o2_tmp_0 * rtb_sincos_o2_tmp;

  /* Fcn: '<S16>/Fcn32' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_DataTypeConversion - rtb_sincos_o1_tmp * rtb_sincos_o2_tmp;

  /* Fcn: '<S16>/Fcn13' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate[6] = -rtb_DataTypeConversion2;

  /* Fcn: '<S16>/Fcn23' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate[7] = rtb_sincos_o1_tmp * rtb_Sqrt;

  /* Fcn: '<S16>/Fcn33' incorporates:
   *  Trigonometry: '<S16>/sincos'
   */
  rtb_VectorConcatenate[8] = rtb_sincos_o2_tmp_0 * rtb_Sqrt;

  /* Fcn: '<S147>/Fcn11' */
  rtb_VectorConcatenate_e[0] = rtb_Sqrt * rtb_sincos_o2_tmp;

  /* Fcn: '<S147>/Fcn21' incorporates:
   *  Fcn: '<S147>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o1_tmp * rtb_DataTypeConversion2;
  rtb_VectorConcatenate_e[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o2_tmp -
    rtb_sincos_o2_tmp_0 * rtb_DataTypeConversion;

  /* Fcn: '<S147>/Fcn31' incorporates:
   *  Fcn: '<S147>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2_tmp_0 * rtb_DataTypeConversion2;
  rtb_VectorConcatenate_e[2] = rtb_VectorConcatenate_tmp_0 * rtb_sincos_o2_tmp +
    rtb_sincos_o1_tmp * rtb_DataTypeConversion;

  /* Fcn: '<S147>/Fcn12' */
  rtb_VectorConcatenate_e[3] = rtb_Sqrt * rtb_DataTypeConversion;

  /* Fcn: '<S147>/Fcn22' */
  rtb_VectorConcatenate_e[4] = rtb_VectorConcatenate_tmp *
    rtb_DataTypeConversion + rtb_sincos_o2_tmp_0 * rtb_sincos_o2_tmp;

  /* Fcn: '<S147>/Fcn32' */
  rtb_VectorConcatenate_e[5] = rtb_VectorConcatenate_tmp_0 *
    rtb_DataTypeConversion - rtb_sincos_o1_tmp * rtb_sincos_o2_tmp;

  /* Fcn: '<S147>/Fcn13' */
  rtb_VectorConcatenate_e[6] = -rtb_DataTypeConversion2;

  /* Fcn: '<S147>/Fcn23' */
  rtb_VectorConcatenate_e[7] = rtb_sincos_o1_tmp * rtb_Sqrt;

  /* Fcn: '<S147>/Fcn33' */
  rtb_VectorConcatenate_e[8] = rtb_sincos_o2_tmp_0 * rtb_Sqrt;

  /* Math: '<S73>/Math Function' */
  for (cff = 0; cff < 3; cff++) {
    rtb_MathFunction[3 * cff] = rtb_VectorConcatenate_e[cff];
    rtb_MathFunction[3 * cff + 1] = rtb_VectorConcatenate_e[cff + 3];
    rtb_MathFunction[3 * cff + 2] = rtb_VectorConcatenate_e[cff + 6];
  }

  for (cff = 0; cff < 9; cff++) {
    rtb_VectorConcatenate_e[cff] = rtb_MathFunction[cff];
  }

  /* End of Math: '<S73>/Math Function' */

  /* Delay: '<S76>/MemoryX' incorporates:
   *  DiscreteFilter: '<S75>/IIRgyroz'
   *  SampleTimeMath: '<S82>/TSamp'
   *  Sum: '<S82>/Diff'
   *  UnitDelay: '<S82>/UD'
   *
   * About '<S82>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *
   * Block description for '<S82>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S82>/UD':
   *
   *  Store in Global RAM
   */
  if (stateEstimator_DW.icLoad != 0) {
    stateEstimator_DW.MemoryX_DSTATE_d[0] = 0.0F;
    stateEstimator_DW.MemoryX_DSTATE_d[1] = 0.0F;
  }

  for (i_0 = 0; i_0 < 2; i_0++) {
    rtb_MemoryX_e[i_0] = stateEstimator_DW.MemoryX_DSTATE_d[i_0];

    /* DiscreteFilter: '<S75>/IIRgyroz' */
    cff = i_0 * 5;
    rtb_DataTypeConversion = inverseIMU_gain[i_0 + 3];
    denIdx = 1;
    for (i = 0; i < 5; i++) {
      rtb_DataTypeConversion -= stateEstimator_DW.IIRgyroz_states[cff + i] *
        rtCP_IIRgyroz_DenCoef[denIdx];
      denIdx++;
    }

    stateEstimator_DW.IIRgyroz_tmp[i_0] = rtb_DataTypeConversion;
    rtb_DataTypeConversion = 0.282124132F * stateEstimator_DW.IIRgyroz_tmp[i_0];
    denIdx = 1;
    for (i = 0; i < 5; i++) {
      rtb_DataTypeConversion += stateEstimator_DW.IIRgyroz_states[cff + i] *
        rtCP_IIRgyroz_NumCoef[denIdx];
      denIdx++;
    }

    /* SampleTimeMath: '<S82>/TSamp' incorporates:
     *  DiscreteFilter: '<S75>/IIRgyroz'
     *
     * About '<S82>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_DataTypeConversion *= 200.0F;
    rtb_SimplyIntegrateVelocity[i_0] = rtb_DataTypeConversion -
      stateEstimator_DW.UD_DSTATE[i_0];
    rtb_TSamp[i_0] = rtb_DataTypeConversion;
  }

  /* Abs: '<S75>/Abs' incorporates:
   *  Abs: '<S75>/Abs4'
   */
  rtb_DataTypeConversion2 = (real32_T)fabs(inverseIMU_gain[3]);

  /* Abs: '<S75>/Abs1' incorporates:
   *  Abs: '<S75>/Abs5'
   */
  rtb_Sqrt = (real32_T)fabs(inverseIMU_gain[4]);

  /* Abs: '<S75>/Abs3' incorporates:
   *  Abs: '<S146>/Abs1'
   */
  rtb_DataTypeConversion = (real32_T)fabs(stateEstimator_DW.Merge[1]);

  /* Abs: '<S75>/Abs2' incorporates:
   *  Abs: '<S146>/Abs'
   */
  rtb_sincos_o2_tmp = (real32_T)fabs(stateEstimator_DW.Merge[0]);

  /* Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S17>/Constant'
   *  Delay: '<S3>/Delay2'
   *  RelationalOperator: '<S17>/Compare'
   */
  if (stateEstimator_DW.Delay2_DSTATE > 0.0) {
    stateEstimator_DW.icLoad_p = 1U;
  }

  if (stateEstimator_DW.icLoad_p != 0) {
    stateEstimator_DW.MemoryX_DSTATE[0] = -0.046;
    stateEstimator_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* DiscreteFilter: '<S15>/pressureFilter_IIR' incorporates:
   *  Gain: '<S3>/prsToAltGain'
   *  Sum: '<S5>/Sum2'
   */
  stateEstimator_DW.pressureFilter_IIR_tmp = (((arg_sensordata_datin->prs -
    arg_sensorCalibration_datin[6]) * 0.0832137167F - -2.93717074F *
    stateEstimator_DW.pressureFilter_IIR_states[0]) - 2.87629962F *
    stateEstimator_DW.pressureFilter_IIR_states[1]) - -0.939098954F *
    stateEstimator_DW.pressureFilter_IIR_states[2];

  /* DiscreteFilter: '<S15>/soonarFilter_IIR' incorporates:
   *  Gain: '<S3>/invertzaxisGain'
   */
  stateEstimator_DW.soonarFilter_IIR_tmp = ((-(real_T)
    arg_sensordata_datin->altitude_sonar - -2.9371707284498907 *
    stateEstimator_DW.soonarFilter_IIR_states[0]) - 2.8762997234793319 *
    stateEstimator_DW.soonarFilter_IIR_states[1]) - -0.939098940325283 *
    stateEstimator_DW.soonarFilter_IIR_states[2];

  /* Saturate: '<S15>/SaturationSonar' incorporates:
   *  Gain: '<S3>/invertzaxisGain'
   */
  if (-(real_T)arg_sensordata_datin->altitude_sonar >= -0.44) {
    rtb_Add_idx_0 = -0.44;
  } else {
    rtb_Add_idx_0 = -(real_T)arg_sensordata_datin->altitude_sonar;
  }

  /* End of Saturate: '<S15>/SaturationSonar' */

  /* Logic: '<S15>/nicemeasurementor newupdateneeded' incorporates:
   *  Abs: '<S15>/Absestdiff'
   *  Abs: '<S15>/Absestdiff1'
   *  Abs: '<S15>/Absestdiff2'
   *  Constant: '<S67>/Constant'
   *  Constant: '<S68>/Constant'
   *  Constant: '<S69>/Constant'
   *  Constant: '<S70>/Constant'
   *  Delay: '<S3>/Delay2'
   *  DiscreteFilter: '<S15>/pressureFilter_IIR'
   *  DiscreteFilter: '<S15>/soonarFilter_IIR'
   *  Gain: '<S3>/invertzaxisGain'
   *  Logic: '<S15>/findingoutliers'
   *  Logic: '<S15>/newupdateneeded'
   *  RelationalOperator: '<S67>/Compare'
   *  RelationalOperator: '<S68>/Compare'
   *  RelationalOperator: '<S69>/Compare'
   *  RelationalOperator: '<S70>/Compare'
   *  Sum: '<S15>/Add'
   *  Sum: '<S15>/Add1'
   *  Sum: '<S15>/Add2'
   */
  rtb_Compare = (((fabs(stateEstimator_DW.Delay2_DSTATE - rtb_Add_idx_0) <= 0.3)
                  && (-(real_T)arg_sensordata_datin->altitude_sonar < -0.44)) ||
                 ((fabs((((3.75683794E-6F *
    stateEstimator_DW.pressureFilter_IIR_tmp + 1.12705138E-5F *
    stateEstimator_DW.pressureFilter_IIR_states[0]) + 1.12705138E-5F *
    stateEstimator_DW.pressureFilter_IIR_states[1]) + 3.75683794E-6F *
    stateEstimator_DW.pressureFilter_IIR_states[2]) -
                        stateEstimator_DW.Delay2_DSTATE) >= 0.8) && (fabs
    ((((3.7568380197861018E-6 * stateEstimator_DW.soonarFilter_IIR_tmp +
        1.1270514059358305E-5 * stateEstimator_DW.soonarFilter_IIR_states[0]) +
       1.1270514059358305E-5 * stateEstimator_DW.soonarFilter_IIR_states[1]) +
      3.7568380197861018E-6 * stateEstimator_DW.soonarFilter_IIR_states[2]) -
     stateEstimator_DW.Delay2_DSTATE) >= 0.4)));

  /* Outputs for Enabled SubSystem: '<S42>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S66>/Enable'
   */
  if (rtb_Compare) {
    stateEstimator_DW.EnabledSubsystem_MODE = true;

    /* Sum: '<S66>/Add1' incorporates:
     *  Constant: '<S14>/C'
     *  Delay: '<S14>/MemoryX'
     *  Gain: '<S3>/invertzaxisGain'
     *  Product: '<S66>/Product'
     */
    rtb_Sum_i = -(real_T)arg_sensordata_datin->altitude_sonar - (0.0 *
      stateEstimator_DW.MemoryX_DSTATE[1] + stateEstimator_DW.MemoryX_DSTATE[0]);

    /* Product: '<S66>/Product2' */
    stateEstimator_DW.Product2[0] = 0.02624142064187163 * rtb_Sum_i;
    stateEstimator_DW.Product2[1] = 0.0697767360714917 * rtb_Sum_i;
  } else {
    if (stateEstimator_DW.EnabledSubsystem_MODE) {
      /* Disable for Outport: '<S66>/deltax' */
      stateEstimator_DW.Product2[0] = 0.0;
      stateEstimator_DW.Product2[1] = 0.0;
      stateEstimator_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S42>/Enabled Subsystem' */

  /* Sum: '<S42>/Add' incorporates:
   *  Delay: '<S14>/MemoryX'
   */
  rtb_Add_idx_0 = stateEstimator_DW.Product2[0] +
    stateEstimator_DW.MemoryX_DSTATE[0];
  rtb_Sum_i = stateEstimator_DW.Product2[1] + stateEstimator_DW.MemoryX_DSTATE[1];

  /* Logic: '<S75>/Logical Operator3' incorporates:
   *  Abs: '<S75>/Abs'
   *  Abs: '<S75>/Abs1'
   *  Abs: '<S75>/Abs2'
   *  Abs: '<S75>/Abs3'
   *  Abs: '<S75>/Abs6'
   *  Abs: '<S75>/Abs7'
   *  Abs: '<S75>/Abs8'
   *  Abs: '<S75>/Abs9'
   *  Constant: '<S83>/Constant'
   *  Constant: '<S84>/Constant'
   *  Constant: '<S85>/Constant'
   *  Constant: '<S86>/Constant'
   *  Constant: '<S87>/Constant'
   *  Constant: '<S88>/Constant'
   *  Constant: '<S89>/Constant'
   *  Constant: '<S90>/Constant'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Delay: '<S72>/Delay'
   *  Logic: '<S75>/Logical Operator'
   *  Logic: '<S75>/Logical Operator1'
   *  Logic: '<S75>/Logical Operator2'
   *  RelationalOperator: '<S83>/Compare'
   *  RelationalOperator: '<S84>/Compare'
   *  RelationalOperator: '<S85>/Compare'
   *  RelationalOperator: '<S86>/Compare'
   *  RelationalOperator: '<S87>/Compare'
   *  RelationalOperator: '<S88>/Compare'
   *  RelationalOperator: '<S89>/Compare'
   *  RelationalOperator: '<S90>/Compare'
   *  RelationalOperator: '<S91>/Compare'
   *  RelationalOperator: '<S92>/Compare'
   *  RelationalOperator: '<S93>/Compare'
   *  Sum: '<S75>/Add'
   */
  rtb_Compare_b3 = ((((rtb_sincos_o2_tmp <= 0.6F) && (rtb_DataTypeConversion <=
    0.6F) && (rtb_DataTypeConversion2 <= 7.0F) && (rtb_Sqrt <= 7.0F) &&
                      ((real32_T)fabs(rtb_SimplyIntegrateVelocity[0]) <= 80.0F) &&
                      ((real32_T)fabs(rtb_SimplyIntegrateVelocity[1]) <= 80.0F))
                     || ((rtb_DataTypeConversion2 <= 0.5F) && (rtb_Sqrt <= 0.5F)))
                    && ((real32_T)fabs(arg_opticalFlow_datin[0] -
    stateEstimator_DW.Delay_DSTATE[0]) <= 5.0F) && ((real32_T)fabs
    (arg_opticalFlow_datin[1] - stateEstimator_DW.Delay_DSTATE[1]) <= 5.0F) &&
                    ((real32_T)rtb_Add_idx_0 <= -0.4F));

  /* Outputs for Enabled SubSystem: '<S120>/Enabled Subsystem' */
  /* Constant: '<S76>/C' */
  stateEstimator_EnabledSubsystem(rtb_Compare_b3,
    stateEstimator_ConstB.Conversion_p, rtCP_C_Value_f, &arg_opticalFlow_datin[0],
    rtb_MemoryX_e, stateEstimator_DW.Product2_k,
    &stateEstimator_DW.EnabledSubsystem_f);

  /* End of Outputs for SubSystem: '<S120>/Enabled Subsystem' */

  /* Sum: '<S120>/Add' incorporates:
   *  Delay: '<S76>/MemoryX'
   */
  rtb_SimplyIntegrateVelocity[0] = stateEstimator_DW.Product2_k[0] +
    stateEstimator_DW.MemoryX_DSTATE_d[0];
  rtb_SimplyIntegrateVelocity[1] = stateEstimator_DW.Product2_k[1] +
    stateEstimator_DW.MemoryX_DSTATE_d[1];

  /* Product: '<S3>/Product1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   *  Delay: '<S1>/Delay1'
   *  SignalConversion generated from: '<S3>/Product1'
   */
  for (cff = 0; cff < 3; cff++) {
    rtb_VectorConcatenate_1[cff] = rtb_VectorConcatenate[cff + 6] * rtb_Sum_i +
      ((real_T)rtb_VectorConcatenate[cff + 3] * stateEstimator_DW.Delay1_DSTATE
       [1] + (real_T)rtb_VectorConcatenate[cff] *
       stateEstimator_DW.Delay1_DSTATE[0]);
  }

  /* End of Product: '<S3>/Product1' */
  for (i = 0; i < 3; i++) {
    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/gravity'
     *  Math: '<S3>/Math Function'
     *  Product: '<S3>/Product'
     */
    rtb_Sum[i] = (rtb_VectorConcatenate[3 * i + 2] * rtb_FIR_IMUaccel[2] +
                  (rtb_VectorConcatenate[3 * i + 1] * rtb_FIR_IMUaccel[1] +
                   rtb_VectorConcatenate[3 * i] * rtb_FIR_IMUaccel[0])) +
      rtCP_gravity_Value[i];

    /* Trigonometry: '<S78>/sincos' */
    rtb_sincos_o2[i] = (real32_T)cos(rtb_Product_n[i]);

    /* Product: '<S73>/Product' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion2'
     *  SignalConversion generated from: '<S73>/Product'
     */
    rtb_Product[i] = rtb_VectorConcatenate_e[i + 6] * (real32_T)
      rtb_VectorConcatenate_1[2] + (rtb_VectorConcatenate_e[i + 3] *
      rtb_SimplyIntegrateVelocity[1] + rtb_VectorConcatenate_e[i] *
      rtb_SimplyIntegrateVelocity[0]);

    /* Product: '<S3>/Product' incorporates:
     *  Math: '<S3>/Math Function'
     *  Trigonometry: '<S78>/sincos'
     */
    rtb_sincos_o1[i] = (real32_T)sin(rtb_Product_n[i]);
  }

  /* Fcn: '<S78>/Fcn11' */
  rtb_VectorConcatenate_e[0] = rtb_sincos_o2[1] * rtb_sincos_o2[0];

  /* Fcn: '<S78>/Fcn21' incorporates:
   *  Fcn: '<S78>/Fcn22'
   */
  rtb_VectorConcatenate_tmp = rtb_sincos_o1[2] * rtb_sincos_o1[1];
  rtb_VectorConcatenate_e[1] = rtb_VectorConcatenate_tmp * rtb_sincos_o2[0] -
    rtb_sincos_o2[2] * rtb_sincos_o1[0];

  /* Fcn: '<S78>/Fcn31' incorporates:
   *  Fcn: '<S78>/Fcn32'
   */
  rtb_VectorConcatenate_tmp_0 = rtb_sincos_o2[2] * rtb_sincos_o1[1];
  rtb_VectorConcatenate_e[2] = rtb_VectorConcatenate_tmp_0 * rtb_sincos_o2[0] +
    rtb_sincos_o1[2] * rtb_sincos_o1[0];

  /* Fcn: '<S78>/Fcn12' */
  rtb_VectorConcatenate_e[3] = rtb_sincos_o2[1] * rtb_sincos_o1[0];

  /* Fcn: '<S78>/Fcn22' */
  rtb_VectorConcatenate_e[4] = rtb_VectorConcatenate_tmp * rtb_sincos_o1[0] +
    rtb_sincos_o2[2] * rtb_sincos_o2[0];

  /* Fcn: '<S78>/Fcn32' */
  rtb_VectorConcatenate_e[5] = rtb_VectorConcatenate_tmp_0 * rtb_sincos_o1[0] -
    rtb_sincos_o1[2] * rtb_sincos_o2[0];

  /* Fcn: '<S78>/Fcn13' */
  rtb_VectorConcatenate_e[6] = -rtb_sincos_o1[1];

  /* Fcn: '<S78>/Fcn23' */
  rtb_VectorConcatenate_e[7] = rtb_sincos_o1[2] * rtb_sincos_o2[1];

  /* Fcn: '<S78>/Fcn33' */
  rtb_VectorConcatenate_e[8] = rtb_sincos_o2[2] * rtb_sincos_o2[1];

  /* RelationalOperator: '<S77>/Compare' incorporates:
   *  Constant: '<S77>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  rtb_Compare_i = ((real32_T)rtb_Add_idx_0 <= -0.4F);

  /* Logic: '<S74>/Logical Operator' incorporates:
   *  Constant: '<S79>/Constant'
   *  Constant: '<S80>/Constant'
   *  RelationalOperator: '<S79>/Compare'
   *  RelationalOperator: '<S80>/Compare'
   */
  rtb_LogicalOperator_cg = ((arg_opticalFlow_datin[0] != 0.0F) ||
    (arg_opticalFlow_datin[1] != 0.0F));

  /* Sum: '<S74>/Add' incorporates:
   *  Product: '<S74>/Product1'
   */
  for (cff = 0; cff < 3; cff++) {
    rtb_FIR_IMUaccel_0[cff] = rtb_FIR_IMUaccel[cff] -
      ((rtb_VectorConcatenate_e[cff + 3] * 0.0 + rtb_VectorConcatenate_e[cff] *
        0.0) + rtb_VectorConcatenate_e[cff + 6] * -9.81);
  }

  /* End of Sum: '<S74>/Add' */

  /* Product: '<S74>/Product' incorporates:
   *  Gain: '<S74>/gainaccinput'
   */
  rtb_Product_a[0] = (real32_T)(0.2 * rtb_FIR_IMUaccel_0[0]) * (real32_T)
    rtb_LogicalOperator_cg * (real32_T)rtb_Compare_i;
  rtb_Product_a[1] = (real32_T)(0.2 * rtb_FIR_IMUaccel_0[1]) * (real32_T)
    rtb_LogicalOperator_cg * (real32_T)rtb_Compare_i;

  /* Outputs for Enabled SubSystem: '<S113>/MeasurementUpdate' */
  /* Constant: '<S76>/C' incorporates:
   *  Constant: '<S76>/D'
   */
  stateEstimator_MeasurementUpdate(rtb_Compare_b3,
    stateEstimator_ConstB.Conversion, &arg_opticalFlow_datin[0], rtCP_C_Value_f,
    rtb_MemoryX_e, rtCP_D_Value_f, rtb_Product_a, stateEstimator_DW.Product3_m,
    &stateEstimator_DW.MeasurementUpdate_e);

  /* End of Outputs for SubSystem: '<S113>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S36>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S64>/Enable'
   */
  if (rtb_Compare) {
    stateEstimator_DW.MeasurementUpdate_MODE = true;

    /* Sum: '<S64>/Sum' incorporates:
     *  Constant: '<S14>/C'
     *  Constant: '<S14>/D'
     *  Delay: '<S14>/MemoryX'
     *  Gain: '<S3>/invertzaxisGain'
     *  Product: '<S64>/C[k]*xhat[k|k-1]'
     *  Product: '<S64>/D[k]*u[k]'
     *  Sum: '<S64>/Add1'
     */
    rtb_Sum_i = -(real_T)arg_sensordata_datin->altitude_sonar - ((0.0 *
      stateEstimator_DW.MemoryX_DSTATE[1] + stateEstimator_DW.MemoryX_DSTATE[0])
      + 0.0 * rtb_Sum[2]);

    /* Product: '<S64>/Product3' */
    stateEstimator_DW.Product3[0] = 0.026590304322229058 * rtb_Sum_i;
    stateEstimator_DW.Product3[1] = 0.06977673607149236 * rtb_Sum_i;
  } else {
    if (stateEstimator_DW.MeasurementUpdate_MODE) {
      /* Disable for Outport: '<S64>/L*(y[k]-yhat[k|k-1])' */
      stateEstimator_DW.Product3[0] = 0.0;
      stateEstimator_DW.Product3[1] = 0.0;
      stateEstimator_DW.MeasurementUpdate_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S36>/MeasurementUpdate' */

  /* Delay: '<S145>/MemoryX' */
  if (stateEstimator_DW.icLoad_g != 0) {
    stateEstimator_DW.MemoryX_DSTATE_dl[0] = 0.1F;
    stateEstimator_DW.MemoryX_DSTATE_dl[1] = 0.0F;
  }

  rtb_MemoryX_e[0] = stateEstimator_DW.MemoryX_DSTATE_dl[0];
  rtb_MemoryX_e[1] = stateEstimator_DW.MemoryX_DSTATE_dl[1];

  /* Logic: '<S146>/Logical Operator3' incorporates:
   *  Constant: '<S199>/Constant'
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S202>/Constant'
   *  Delay: '<S73>/Delay'
   *  Math: '<S146>/Math Function'
   *  RelationalOperator: '<S199>/Compare'
   *  RelationalOperator: '<S200>/Compare'
   *  RelationalOperator: '<S201>/Compare'
   *  RelationalOperator: '<S202>/Compare'
   *  Sqrt: '<S146>/Sqrt'
   *  Sum: '<S146>/Add1'
   *  Sum: '<S146>/Sum of Elements'
   */
  rtb_Compare = ((arg_posVIS_datin[0] != -99.0F) && (rtb_sincos_o2_tmp <= 0.18F)
                 && (rtb_DataTypeConversion <= 0.18F) && ((real32_T)sqrt
    (rt_powf_snf(arg_posVIS_datin[0] - stateEstimator_DW.Delay_DSTATE_l[0], 2.0F)
     + rt_powf_snf(arg_posVIS_datin[1] - stateEstimator_DW.Delay_DSTATE_l[1],
                   2.0F)) < 1.0F));

  /* Outputs for Enabled SubSystem: '<S167>/MeasurementUpdate' */
  /* Constant: '<S145>/C' incorporates:
   *  Constant: '<S145>/D'
   */
  stateEstimator_MeasurementUpdate(rtb_Compare,
    stateEstimator_ConstB.Conversion_a, &arg_posVIS_datin[0], rtCP_C_Value_p,
    rtb_MemoryX_e, rtCP_D_Value_b, &rtb_Product[0], stateEstimator_DW.Product3_j,
    &stateEstimator_DW.MeasurementUpdate_b);

  /* End of Outputs for SubSystem: '<S167>/MeasurementUpdate' */

  /* Outputs for Enabled SubSystem: '<S174>/Enabled Subsystem' */
  stateEstimator_EnabledSubsystem(rtb_Compare,
    stateEstimator_ConstB.Conversion_g, rtCP_C_Value_p, &arg_posVIS_datin[0],
    rtb_MemoryX_e, stateEstimator_DW.Product2_e,
    &stateEstimator_DW.EnabledSubsystem_m);

  /* End of Outputs for SubSystem: '<S174>/Enabled Subsystem' */

  /* Sum: '<S174>/Add' incorporates:
   *  Delay: '<S145>/MemoryX'
   */
  rtb_MemoryX_e[0] = stateEstimator_DW.Product2_e[0] +
    stateEstimator_DW.MemoryX_DSTATE_dl[0];
  rtb_MemoryX_e[1] = stateEstimator_DW.Product2_e[1] +
    stateEstimator_DW.MemoryX_DSTATE_dl[1];

  /* DiscreteIntegrator: '<S73>/SimplyIntegrateVelocity' */
  if (arg_controlModePosVSOrient_flagin &&
      (stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState <= 0)) {
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] = 0.0F;
    stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] = 0.0F;
  }

  /* Switch: '<S73>/UseIPPosSwitch' incorporates:
   *  DiscreteIntegrator: '<S73>/SimplyIntegrateVelocity'
   */
  if (arg_usePosVIS_flagin > 0.0F) {
    /* BusCreator generated from: '<Root>/states_estimout' */
    arg_states_estimout->X = rtb_MemoryX_e[0];
    rtb_DataTypeConversion = rtb_MemoryX_e[1];
  } else {
    /* BusCreator generated from: '<Root>/states_estimout' incorporates:
     *  DiscreteIntegrator: '<S73>/SimplyIntegrateVelocity'
     */
    arg_states_estimout->X = stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0];
    rtb_DataTypeConversion = stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1];
  }

  /* End of Switch: '<S73>/UseIPPosSwitch' */

  /* BusCreator generated from: '<Root>/states_estimout' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   */
  arg_states_estimout->Y = rtb_DataTypeConversion;
  arg_states_estimout->Z = (real32_T)rtb_Add_idx_0;
  arg_states_estimout->yaw = rtb_Merge1;
  arg_states_estimout->pitch = stateEstimator_DW.Merge[0];
  arg_states_estimout->roll = stateEstimator_DW.Merge[1];
  arg_states_estimout->dx = rtb_SimplyIntegrateVelocity[0];
  arg_states_estimout->dy = rtb_SimplyIntegrateVelocity[1];
  arg_states_estimout->dz = (real32_T)rtb_VectorConcatenate_1[2];
  arg_states_estimout->p = inverseIMU_gain[3];
  arg_states_estimout->q = inverseIMU_gain[4];
  arg_states_estimout->r = rtb_r;

  /* Update for Memory: '<S2>/Memory' incorporates:
   *  SignalConversion generated from: '<S16>/sincos'
   */
  stateEstimator_DW.Memory_PreviousInput[0] = rtb_Merge1;
  stateEstimator_DW.Memory_PreviousInput[1] = stateEstimator_DW.Merge[0];
  stateEstimator_DW.Memory_PreviousInput[2] = stateEstimator_DW.Merge[1];

  /* Update for DiscreteFir: '<S5>/FIR_IMUaccel' */
  /* Update circular buffer index */
  stateEstimator_DW.FIR_IMUaccel_circBuf--;
  if (stateEstimator_DW.FIR_IMUaccel_circBuf < 0) {
    stateEstimator_DW.FIR_IMUaccel_circBuf = 4;
  }

  /* Update circular buffer */
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf] =
    inverseIMU_gain[0];
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf +
    5] = inverseIMU_gain[1];
  stateEstimator_DW.FIR_IMUaccel_states[stateEstimator_DW.FIR_IMUaccel_circBuf +
    10] = inverseIMU_gain[2];

  /* End of Update for DiscreteFir: '<S5>/FIR_IMUaccel' */

  /* Update for DiscreteFilter: '<S5>/IIR_IMUgyro_r' */
  stateEstimator_DW.IIR_IMUgyro_r_states[4] =
    stateEstimator_DW.IIR_IMUgyro_r_states[3];
  stateEstimator_DW.IIR_IMUgyro_r_states[3] =
    stateEstimator_DW.IIR_IMUgyro_r_states[2];
  stateEstimator_DW.IIR_IMUgyro_r_states[2] =
    stateEstimator_DW.IIR_IMUgyro_r_states[1];
  stateEstimator_DW.IIR_IMUgyro_r_states[1] =
    stateEstimator_DW.IIR_IMUgyro_r_states[0];
  stateEstimator_DW.IIR_IMUgyro_r_states[0] =
    stateEstimator_DW.IIR_IMUgyro_r_tmp;

  /* Update for Delay: '<S76>/MemoryX' */
  stateEstimator_DW.icLoad = 0U;

  /* Product: '<S113>/B[k]*u[k]' incorporates:
   *  Constant: '<S76>/B'
   */
  tmp[0] = 0.005F * rtb_Product_a[0] + 0.0F * rtb_Product_a[1];

  /* Product: '<S113>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S76>/A'
   *  Delay: '<S76>/MemoryX'
   */
  tmp_0[0] = 0.0F * stateEstimator_DW.MemoryX_DSTATE_d[1] +
    stateEstimator_DW.MemoryX_DSTATE_d[0];

  /* Product: '<S113>/B[k]*u[k]' incorporates:
   *  Constant: '<S76>/B'
   */
  tmp[1] = 0.0F * rtb_Product_a[0];

  /* Product: '<S113>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S76>/A'
   *  Delay: '<S76>/MemoryX'
   */
  tmp_0[1] = 0.0F * stateEstimator_DW.MemoryX_DSTATE_d[0];

  /* Product: '<S113>/B[k]*u[k]' incorporates:
   *  Constant: '<S76>/B'
   */
  tmp[1] += 0.005F * rtb_Product_a[1];

  /* Product: '<S113>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S76>/A'
   *  Delay: '<S76>/MemoryX'
   */
  tmp_0[1] += stateEstimator_DW.MemoryX_DSTATE_d[1];

  /* Update for Delay: '<S3>/Delay2' */
  stateEstimator_DW.Delay2_DSTATE = rtb_Add_idx_0;

  /* Update for Delay: '<S14>/MemoryX' */
  stateEstimator_DW.icLoad_p = 0U;
  for (i = 0; i < 2; i++) {
    /* Update for Delay: '<S76>/MemoryX' incorporates:
     *  Sum: '<S113>/Add'
     */
    stateEstimator_DW.MemoryX_DSTATE_d[i] = (tmp[i] + tmp_0[i]) +
      stateEstimator_DW.Product3_m[i];

    /* Update for DiscreteFilter: '<S75>/IIRgyroz' */
    cff = i * 5;
    stateEstimator_DW.IIRgyroz_states[cff + 4] =
      stateEstimator_DW.IIRgyroz_states[cff + 3];
    stateEstimator_DW.IIRgyroz_states[cff + 3] =
      stateEstimator_DW.IIRgyroz_states[cff + 2];
    stateEstimator_DW.IIRgyroz_states[cff + 2] =
      stateEstimator_DW.IIRgyroz_states[cff + 1];
    stateEstimator_DW.IIRgyroz_states[cff + 1] =
      stateEstimator_DW.IIRgyroz_states[cff];
    stateEstimator_DW.IIRgyroz_states[cff] = stateEstimator_DW.IIRgyroz_tmp[i];

    /* Update for UnitDelay: '<S82>/UD'
     *
     * Block description for '<S82>/UD':
     *
     *  Store in Global RAM
     */
    stateEstimator_DW.UD_DSTATE[i] = rtb_TSamp[i];

    /* Update for Delay: '<S72>/Delay' */
    stateEstimator_DW.Delay_DSTATE[i] = rtb_SimplyIntegrateVelocity[i];

    /* Product: '<S36>/A[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S14>/A'
     *  Delay: '<S14>/MemoryX'
     */
    tmp_1[i] = rtCP_A_Value[i + 2] * stateEstimator_DW.MemoryX_DSTATE[1] +
      rtCP_A_Value[i] * stateEstimator_DW.MemoryX_DSTATE[0];
  }

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/B'
   *  Product: '<S36>/B[k]*u[k]'
   *  Sum: '<S36>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE[0] = (0.0 * rtb_Sum[2] + tmp_1[0]) +
    stateEstimator_DW.Product3[0];

  /* Update for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[2] =
    stateEstimator_DW.pressureFilter_IIR_states[1];

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/B'
   *  Product: '<S36>/B[k]*u[k]'
   *  Sum: '<S36>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE[1] = (0.005 * rtb_Sum[2] + tmp_1[1]) +
    stateEstimator_DW.Product3[1];

  /* Update for DiscreteFilter: '<S15>/pressureFilter_IIR' */
  stateEstimator_DW.pressureFilter_IIR_states[1] =
    stateEstimator_DW.pressureFilter_IIR_states[0];
  stateEstimator_DW.pressureFilter_IIR_states[0] =
    stateEstimator_DW.pressureFilter_IIR_tmp;

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[2] =
    stateEstimator_DW.soonarFilter_IIR_states[1];

  /* Update for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[0] = rtb_SimplyIntegrateVelocity[0];

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[1] =
    stateEstimator_DW.soonarFilter_IIR_states[0];

  /* Update for Delay: '<S1>/Delay1' */
  stateEstimator_DW.Delay1_DSTATE[1] = rtb_SimplyIntegrateVelocity[1];

  /* Update for DiscreteFilter: '<S15>/soonarFilter_IIR' */
  stateEstimator_DW.soonarFilter_IIR_states[0] =
    stateEstimator_DW.soonarFilter_IIR_tmp;

  /* Update for Delay: '<S145>/MemoryX' */
  stateEstimator_DW.icLoad_g = 0U;

  /* Product: '<S167>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S145>/A'
   *  Delay: '<S145>/MemoryX'
   */
  rtb_Merge1 = 0.0F * stateEstimator_DW.MemoryX_DSTATE_dl[0] +
    stateEstimator_DW.MemoryX_DSTATE_dl[1];

  /* Update for Delay: '<S145>/MemoryX' incorporates:
   *  Constant: '<S145>/A'
   *  Constant: '<S145>/B'
   *  Product: '<S167>/A[k]*xhat[k|k-1]'
   *  Product: '<S167>/B[k]*u[k]'
   *  Sum: '<S167>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE_dl[0] = ((0.005F * rtb_Product[0] + 0.0F *
    rtb_Product[1]) + (0.0F * stateEstimator_DW.MemoryX_DSTATE_dl[1] +
                       stateEstimator_DW.MemoryX_DSTATE_dl[0])) +
    stateEstimator_DW.Product3_j[0];

  /* Update for Delay: '<S73>/Delay' */
  stateEstimator_DW.Delay_DSTATE_l[0] = rtb_MemoryX_e[0];

  /* Update for DiscreteIntegrator: '<S73>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[0] += 0.005F * rtb_Product[0];

  /* Update for Delay: '<S145>/MemoryX' incorporates:
   *  Constant: '<S145>/B'
   *  Product: '<S167>/B[k]*u[k]'
   *  Sum: '<S167>/Add'
   */
  stateEstimator_DW.MemoryX_DSTATE_dl[1] = ((0.0F * rtb_Product[0] + 0.005F *
    rtb_Product[1]) + rtb_Merge1) + stateEstimator_DW.Product3_j[1];

  /* Update for Delay: '<S73>/Delay' */
  stateEstimator_DW.Delay_DSTATE_l[1] = rtb_MemoryX_e[1];

  /* Update for DiscreteIntegrator: '<S73>/SimplyIntegrateVelocity' */
  stateEstimator_DW.SimplyIntegrateVelocity_DSTATE[1] += 0.005F * rtb_Product[1];
  stateEstimator_DW.SimplyIntegrateVelocity_PrevResetState = (int8_T)
    arg_controlModePosVSOrient_flagin;
}

/* Model initialize function */
void stateEstimator_o_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_stateEstimator_T *const stateEstimator_M =
    &(stateEstimator_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(stateEstimator_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
