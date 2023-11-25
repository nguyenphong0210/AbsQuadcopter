/*
 * File: flightController.c
 *
 * Code generated for Simulink model 'flightController'.
 *
 * Model version                  : 1.127
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Nov 19 00:05:04 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "flightController.h"

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

MdlrefDW_flightController_T flightController_MdlrefDW;

/* Block states (default storage) */
DW_flightController_f_T flightController_DW;
extern const real32_T rtCP_pooled_AiPFoGkd3zrs[16];
extern const real32_T rtCP_pooled_oEBofkCxx3u4[4];

#define rtCP_TorqueTotalThrustToThrustPerMotor_Value rtCP_pooled_AiPFoGkd3zrs/* Computed Parameter: rtCP_TorqueTotalThrustToThrustPerMotor_Value
                                                                      * Referenced by: '<S3>/TorqueTotalThrustToThrustPerMotor'
                                                                      */
#define rtCP_MotorDirections_Gain      rtCP_pooled_oEBofkCxx3u4  /* Computed Parameter: rtCP_MotorDirections_Gain
                                                                  * Referenced by: '<S7>/MotorDirections'
                                                                  */

/* Output and update for referenced model: 'flightController' */
void flightController_run(const CommandBus *arg_ReferenceValueServerBus, const
  statesEstim_t *arg_states_estim, real32_T arg_motors_refout[4], real32_T
  arg_pose_refout[8])
{
  real32_T rtb_TrigonometricFunction_o2;
  int32_T i;
  real32_T arg_ReferenceValueServerBus_idx_0;
  real32_T arg_ReferenceValueServerBus_idx_1;
  real32_T rtb_pitchrollerror_idx_0;
  real32_T rtb_pitchrollerror_idx_1;
  real32_T rtb_DiscreteTimeIntegrator_idx_1;
  real32_T rtb_TrigonometricFunction_o1_idx_2;
  real32_T rtb_TrigonometricFunction_o1_idx_3;
  real32_T u0;

  /* Switch: '<S1>/Switch_refAtt' incorporates:
   *  Gain: '<S4>/D_xy'
   *  Gain: '<S4>/P_xy'
   *  Sum: '<S4>/Sum18'
   */
  if (arg_ReferenceValueServerBus->controlModePosVSOrient) {
    /* Trigonometry: '<S4>/Trigonometric Function' */
    rtb_pitchrollerror_idx_1 = (real32_T)sin(arg_states_estim->yaw);
    rtb_TrigonometricFunction_o2 = (real32_T)cos(arg_states_estim->yaw);

    /* Sum: '<S4>/Sum17' */
    arg_ReferenceValueServerBus_idx_0 = arg_ReferenceValueServerBus->pos_ref[0]
      - arg_states_estim->X;
    arg_ReferenceValueServerBus_idx_1 = arg_ReferenceValueServerBus->pos_ref[1]
      - arg_states_estim->Y;

    /* Product: '<S4>/Product' incorporates:
     *  SignalConversion generated from: '<S4>/Vector Concatenate1'
     *  SignalConversion generated from: '<S4>/Vector Concatenate'
     */
    rtb_DiscreteTimeIntegrator_idx_1 = rtb_TrigonometricFunction_o2 *
      arg_ReferenceValueServerBus_idx_0 + rtb_pitchrollerror_idx_1 *
      arg_ReferenceValueServerBus_idx_1;

    /* Saturate: '<S4>/Saturation' */
    if (rtb_DiscreteTimeIntegrator_idx_1 > 3.0F) {
      rtb_DiscreteTimeIntegrator_idx_1 = 3.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator_idx_1 < -3.0F) {
        rtb_DiscreteTimeIntegrator_idx_1 = -3.0F;
      }
    }

    rtb_pitchrollerror_idx_0 = -0.24F * rtb_DiscreteTimeIntegrator_idx_1 + 0.1F *
      arg_states_estim->dx;

    /* Product: '<S4>/Product' incorporates:
     *  Gain: '<S4>/D_xy'
     *  Gain: '<S4>/Gain'
     *  Gain: '<S4>/P_xy'
     *  SignalConversion generated from: '<S4>/Vector Concatenate1'
     *  Sum: '<S4>/Sum18'
     */
    rtb_DiscreteTimeIntegrator_idx_1 = -rtb_pitchrollerror_idx_1 *
      arg_ReferenceValueServerBus_idx_0 + rtb_TrigonometricFunction_o2 *
      arg_ReferenceValueServerBus_idx_1;

    /* Saturate: '<S4>/Saturation' */
    if (rtb_DiscreteTimeIntegrator_idx_1 > 3.0F) {
      rtb_DiscreteTimeIntegrator_idx_1 = 3.0F;
    } else {
      if (rtb_DiscreteTimeIntegrator_idx_1 < -3.0F) {
        rtb_DiscreteTimeIntegrator_idx_1 = -3.0F;
      }
    }

    rtb_pitchrollerror_idx_1 = 0.24F * rtb_DiscreteTimeIntegrator_idx_1 + -0.1F *
      arg_states_estim->dy;
  } else {
    rtb_pitchrollerror_idx_0 = arg_ReferenceValueServerBus->orient_ref[1];
    rtb_pitchrollerror_idx_1 = arg_ReferenceValueServerBus->orient_ref[2];
  }

  /* End of Switch: '<S1>/Switch_refAtt' */

  /* SignalConversion generated from: '<Root>/pose_refout' incorporates:
   *  SignalConversion generated from: '<S1>/ReferenceValueServerBus_BusSelector'
   */
  arg_pose_refout[0] = arg_ReferenceValueServerBus->pos_ref[0];
  arg_pose_refout[3] = arg_ReferenceValueServerBus->orient_ref[0];
  arg_pose_refout[1] = arg_ReferenceValueServerBus->pos_ref[1];
  arg_pose_refout[4] = arg_ReferenceValueServerBus->orient_ref[1];
  arg_pose_refout[2] = arg_ReferenceValueServerBus->pos_ref[2];
  arg_pose_refout[5] = arg_ReferenceValueServerBus->orient_ref[2];

  /* Sum: '<S2>/Sum19' */
  arg_ReferenceValueServerBus_idx_0 = rtb_pitchrollerror_idx_0 -
    arg_states_estim->pitch;
  arg_ReferenceValueServerBus_idx_1 = rtb_pitchrollerror_idx_1 -
    arg_states_estim->roll;

  /* SignalConversion generated from: '<Root>/pose_refout' */
  arg_pose_refout[6] = rtb_pitchrollerror_idx_0;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  rtb_pitchrollerror_idx_0 = flightController_DW.DiscreteTimeIntegrator_DSTATE[0];

  /* SignalConversion generated from: '<Root>/pose_refout' */
  arg_pose_refout[7] = rtb_pitchrollerror_idx_1;

  /* DiscreteIntegrator: '<S2>/Discrete-Time Integrator' */
  rtb_DiscreteTimeIntegrator_idx_1 =
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1];

  /* Switch: '<S6>/TakeoffOrControl_Switch' incorporates:
   *  Constant: '<S6>/w0'
   *  Gain: '<S6>/D_z'
   *  Gain: '<S6>/P_z'
   *  Gain: '<S6>/takeoff_gain'
   *  Sum: '<S6>/Sum15'
   *  Sum: '<S6>/Sum3'
   */
  if (arg_ReferenceValueServerBus->takeoff_flag) {
    rtb_TrigonometricFunction_o2 = -0.278113484F;
  } else {
    rtb_TrigonometricFunction_o2 = (arg_ReferenceValueServerBus->pos_ref[2] -
      arg_states_estim->Z) * 0.8F - 0.3F * arg_states_estim->dz;
  }

  /* End of Switch: '<S6>/TakeoffOrControl_Switch' */

  /* Sum: '<S6>/Sum4' incorporates:
   *  Constant: '<S6>/w0'
   */
  rtb_pitchrollerror_idx_1 = rtb_TrigonometricFunction_o2 + -0.61803F;

  /* Saturate: '<S6>/SaturationThrust' incorporates:
   *  Constant: '<S6>/w0'
   *  Sum: '<S6>/Sum4'
   */
  if (rtb_TrigonometricFunction_o2 + -0.61803F > 1.20204329F) {
    rtb_pitchrollerror_idx_1 = 1.20204329F;
  } else {
    if (rtb_TrigonometricFunction_o2 + -0.61803F < -1.20204329F) {
      rtb_pitchrollerror_idx_1 = -1.20204329F;
    }
  }

  /* End of Saturate: '<S6>/SaturationThrust' */

  /* Sum: '<S5>/Sum2' incorporates:
   *  Gain: '<S5>/D_yaw'
   *  Gain: '<S5>/P_yaw'
   *  Sum: '<S5>/Sum1'
   */
  rtb_TrigonometricFunction_o2 = (arg_ReferenceValueServerBus->orient_ref[0] -
    arg_states_estim->yaw) * 0.004F - 0.0012F * arg_states_estim->r;

  /* SignalConversion generated from: '<S3>/Product' incorporates:
   *  DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
   *  Gain: '<S2>/D_pr'
   *  Gain: '<S2>/I_pr'
   *  Gain: '<S2>/P_pr'
   *  Sum: '<S2>/Sum16'
   *  Sum: '<S2>/Sum19'
   */
  rtb_TrigonometricFunction_o1_idx_2 = (0.013F *
    arg_ReferenceValueServerBus_idx_0 + 0.01F *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0]) - 0.002F *
    arg_states_estim->q;
  rtb_TrigonometricFunction_o1_idx_3 = (0.01F *
    arg_ReferenceValueServerBus_idx_1 + 0.01F *
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1]) - 0.0028F *
    arg_states_estim->p;
  for (i = 0; i < 4; i++) {
    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<S3>/TorqueTotalThrustToThrustPerMotor'
     *  SignalConversion generated from: '<S3>/Product'
     */
    u0 = rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 12] *
      rtb_TrigonometricFunction_o1_idx_3 +
      (rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 8] *
       rtb_TrigonometricFunction_o1_idx_2 +
       (rtCP_TorqueTotalThrustToThrustPerMotor_Value[i + 4] *
        rtb_TrigonometricFunction_o2 +
        rtCP_TorqueTotalThrustToThrustPerMotor_Value[i] *
        rtb_pitchrollerror_idx_1));

    /* Saturate: '<S7>/Saturation5' incorporates:
     *  Gain: '<S7>/ThrustToMotorCommand'
     */
    u0 *= -1530.72681F;
    if (u0 > 500.0F) {
      u0 = 500.0F;
    } else {
      if (u0 < 10.0F) {
        u0 = 10.0F;
      }
    }

    /* End of Saturate: '<S7>/Saturation5' */

    /* Gain: '<S7>/MotorDirections' */
    arg_motors_refout[i] = rtCP_MotorDirections_Gain[i] * u0;
  }

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/antiWU_Gain'
   *  Sum: '<S2>/Add'
   *  Sum: '<S2>/Sum19'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[0] +=
    (arg_ReferenceValueServerBus_idx_0 - 0.001F *
     flightController_DW.Delay_DSTATE[0]) * 0.005F;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] >= 2.0F) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = 2.0F;
  } else {
    if (flightController_DW.DiscreteTimeIntegrator_DSTATE[0] <= -2.0F) {
      flightController_DW.DiscreteTimeIntegrator_DSTATE[0] = -2.0F;
    }
  }

  /* Update for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[0] = rtb_pitchrollerror_idx_0;

  /* Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' incorporates:
   *  Delay: '<S2>/Delay'
   *  Gain: '<S2>/antiWU_Gain'
   *  Sum: '<S2>/Add'
   *  Sum: '<S2>/Sum19'
   */
  flightController_DW.DiscreteTimeIntegrator_DSTATE[1] +=
    (arg_ReferenceValueServerBus_idx_1 - 0.001F *
     flightController_DW.Delay_DSTATE[1]) * 0.005F;
  if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] >= 2.0F) {
    flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = 2.0F;
  } else {
    if (flightController_DW.DiscreteTimeIntegrator_DSTATE[1] <= -2.0F) {
      flightController_DW.DiscreteTimeIntegrator_DSTATE[1] = -2.0F;
    }
  }

  /* Update for Delay: '<S2>/Delay' */
  flightController_DW.Delay_DSTATE[1] = rtb_DiscreteTimeIntegrator_idx_1;
}

/* Model initialize function */
void flightController_g_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_flightController_T *const flightController_M =
    &(flightController_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(flightController_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
