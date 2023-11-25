/*
 * File: asbQuadcopter.c
 *
 * Code generated for Simulink model 'asbQuadcopter'.
 *
 * Model version                  : 1.288
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Nov 19 16:29:02 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "asbQuadcopter.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Used by FromWorkspace Block: '<S12>/From Workspace' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

/* Exported block signals */
SensorsBus sensor_inport;              /* '<S16>/Bus Creator1' */
CommandBus cmd_inport;                 /* '<S7>/Bus Creator' */
real32_T motors_outport[4];            /* '<Root>/FCS' */
uint8_T flag_outport;                  /* '<Root>/FCS' */

/* Continuous states */
X_asbQuadcopter_T asbQuadcopter_X;

/* Periodic continuous states */
PeriodicIndX_asbQuadcopter_T asbQuadcopter_PeriodicIndX;
PeriodicRngX_asbQuadcopter_T asbQuadcopter_PeriodicRngX;

/* Block signals and states (default storage) */
DW_asbQuadcopter_T asbQuadcopter_DW;

/* Real-time model */
RT_MODEL_asbQuadcopter_T asbQuadcopter_M_;
RT_MODEL_asbQuadcopter_T *const asbQuadcopter_M = &asbQuadcopter_M_;
extern const real32_T rtCP_pooled_t2xxtwyJQBKA[8];
extern const real32_T rtCP_pooled_OEr7FSwA8gMq[3];
extern const real32_T rtCP_pooled_wdJvobRBbaGe[3];

#define rtCP_Constant1_Value           rtCP_pooled_t2xxtwyJQBKA  /* Computed Parameter: rtCP_Constant1_Value
                                                                  * Referenced by: '<S16>/Constant1'
                                                                  */
#define rtCP_Bias1_Bias_a              rtCP_pooled_OEr7FSwA8gMq  /* Computed Parameter: rtCP_Bias1_Bias_a
                                                                  * Referenced by: '<S19>/Bias1'
                                                                  */
#define rtCP_Bias2_Bias_i              rtCP_pooled_wdJvobRBbaGe  /* Computed Parameter: rtCP_Bias2_Bias_i
                                                                  * Referenced by: '<S19>/Bias2'
                                                                  */

/* private model entry point functions */
extern void asbQuadcopter_derivatives(void);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (asbQuadcopter_M->Timing.TaskCounters.TID[2])++;
  if ((asbQuadcopter_M->Timing.TaskCounters.TID[2]) > 11) {/* Sample time: [0.06s, 0.0s] */
    asbQuadcopter_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 16;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  asbQuadcopter_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  asbQuadcopter_step();
  asbQuadcopter_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  asbQuadcopter_step();
  asbQuadcopter_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  local_stateReduction(x, rtsiGetPeriodicContStateIndices(si), 7,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void asbQuadcopter_step(void)
{
  /* local block i/o variables */
  real32_T rtb_YawPitchRoll[3];
  uint32_T rtb_FixPtSwitch;
  real_T rtb_TmpSignalConversionAtVRSinkInport3[4];
  real_T rtb_TmpSignalConversionAtVRSinkInport4[4];
  real_T rtb_TmpSignalConversionAtVRSinkInport5[4];
  real_T rtb_TmpSignalConversionAtVRSinkInport6[4];
  real_T rtb_RateTransition[4];
  real_T rtb_RateTransition1[3];
  real_T rtb_RateTransition2_k[3];
  real_T rtb_Product_j[3];
  real_T rtb_Product2_b;
  real_T rtb_TrigonometricFunction_h;
  real_T rtb_Product_k[3];
  real_T rtb_Product_o[3];
  real_T rtb_Sum_a;
  real_T rtb_Product1_p;
  real_T rtb_Sum_cy;
  real_T rtb_Sum_b;
  real_T rtb_Bias3;
  real_T rtb_Product1_i;
  HAL_echo_t rtb_HAL_echo_t;
  HAL_echo_t rtb_tab_echo[30];
  HAL_echo_t rtb_tab_echo_h[30];
  HAL_fifo_gyro_SI_t rtb_HAL_fifo_gyro_SI_TempCorr;
  real32_T rtb_DataTypeConversion_b[3];
  int32_T i;
  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&asbQuadcopter_M->solverInfo,
                          ((asbQuadcopter_M->Timing.clockTick0+1)*
      asbQuadcopter_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(asbQuadcopter_M)) {
    asbQuadcopter_M->Timing.t[0] = rtsiGetT(&asbQuadcopter_M->solverInfo);
  }

  /* RateTransition: '<S48>/Rate Transition2' incorporates:
   *  Integrator: '<S48>/Integrator'
   */
  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
    if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
        asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0) {
      asbQuadcopter_DW.RateTransition2_Buffer[0] =
        asbQuadcopter_X.Integrator_CSTATE[0];
      asbQuadcopter_DW.RateTransition2_Buffer[1] =
        asbQuadcopter_X.Integrator_CSTATE[1];
      asbQuadcopter_DW.RateTransition2_Buffer[2] =
        asbQuadcopter_X.Integrator_CSTATE[2];
      asbQuadcopter_DW.RateTransition2_Buffer[3] =
        asbQuadcopter_X.Integrator_CSTATE[3];
    }

    /* Outputs for Atomic SubSystem: '<S3>/Environment (Constant)' */
    /* BusCreator: '<S15>/Bus Creator' incorporates:
     *  BusCreator: '<S15>/Bus Creator1'
     *  Constant: '<S15>/Air Density'
     *  Constant: '<S15>/Air Temp'
     *  Constant: '<S15>/Pressure'
     *  Constant: '<S15>/Speed of Sound'
     *  Integrator: '<S48>/Integrator'
     */
    asbQuadcopter_DW.BusCreator.AtmosphereBus.air_temp = 288.0;
    asbQuadcopter_DW.BusCreator.AtmosphereBus.speed_sound = 340.0;
    asbQuadcopter_DW.BusCreator.AtmosphereBus.pressure = 101300.0;
    asbQuadcopter_DW.BusCreator.AtmosphereBus.air_density = 1.184;
    asbQuadcopter_DW.BusCreator.Gravity_ned[0] = 0.0;
    asbQuadcopter_DW.BusCreator.MagneticField_ned[0] = 0.0;
    asbQuadcopter_DW.BusCreator.Gravity_ned[1] = 0.0;
    asbQuadcopter_DW.BusCreator.MagneticField_ned[1] = 0.0;
    asbQuadcopter_DW.BusCreator.Gravity_ned[2] = 9.81;
    asbQuadcopter_DW.BusCreator.MagneticField_ned[2] = 0.0;

    /* End of Outputs for SubSystem: '<S3>/Environment (Constant)' */
  }

  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0) {
    /* SignalConversion generated from: '<S43>/VR Sink' incorporates:
     *  Bias: '<S48>/Bias'
     */
    rtb_TmpSignalConversionAtVRSinkInport3[3] =
      asbQuadcopter_DW.RateTransition2_Buffer[0] + 0.1;

    /* SignalConversion generated from: '<S43>/VR Sink' incorporates:
     *  Bias: '<S48>/Bias1'
     */
    rtb_TmpSignalConversionAtVRSinkInport4[3] =
      asbQuadcopter_DW.RateTransition2_Buffer[1] + -0.3;

    /* SignalConversion generated from: '<S43>/VR Sink' incorporates:
     *  Bias: '<S48>/Bias2'
     */
    rtb_TmpSignalConversionAtVRSinkInport5[3] =
      asbQuadcopter_DW.RateTransition2_Buffer[2] + 0.5;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport3[0] = 0.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport4[0] = 0.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport5[0] = 0.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport6[0] = 0.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport3[1] = 1.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport4[1] = 1.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport5[1] = 1.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport6[1] = 1.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport3[2] = 0.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport4[2] = 0.0;

    /* SignalConversion generated from: '<S43>/VR Sink' */
    rtb_TmpSignalConversionAtVRSinkInport5[2] = 0.0;

    /* SignalConversion generated from: '<S43>/VR Sink' incorporates:
     *  Bias: '<S48>/Bias3'
     */
    rtb_TmpSignalConversionAtVRSinkInport6[2] = 0.0;
    rtb_TmpSignalConversionAtVRSinkInport6[3] =
      asbQuadcopter_DW.RateTransition2_Buffer[3] + 0.7;
  }

  /* End of RateTransition: '<S48>/Rate Transition2' */

  /* FromWorkspace: '<S12>/From Workspace' */
  {
    real_T t = asbQuadcopter_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      asbQuadcopter_DW.FromWorkspace_PWORK.TimePtr;
    real32_T *pDataValues = (real32_T *)
      asbQuadcopter_DW.FromWorkspace_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&rtb_YawPitchRoll[0])[elIdx] = 0.0F;
        }
      }
    } else if (t == pTimeValues[1]) {
      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&rtb_YawPitchRoll[0])[elIdx] = pDataValues[1];
          pDataValues += 2;
        }
      }
    } else if (t > pTimeValues[1]) {
      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&rtb_YawPitchRoll[0])[elIdx] = 0.0F;
        }
      }
    } else {
      int_T currTimeIndex = asbQuadcopter_DW.FromWorkspace_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      {
        int_T elIdx;
        for (elIdx = 0; elIdx < 3; ++elIdx) {
          (&rtb_YawPitchRoll[0])[elIdx] = pDataValues[currTimeIndex];
          pDataValues += 2;
        }
      }

      asbQuadcopter_DW.FromWorkspace_IWORK.PrevIndex = currTimeIndex;
    }
  }

  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
    /* FromWorkspace: '<S12>/fromWS_Signal 1' */
    {
      real_T t = ((asbQuadcopter_M->Timing.clockTick1) * 0.005);
      real_T *pTimeValues = (real_T *)
        asbQuadcopter_DW.fromWS_Signal1_PWORK.TimePtr;
      real32_T *pDataValues = (real32_T *)
        asbQuadcopter_DW.fromWS_Signal1_PWORK.DataPtr;
      if (t < pTimeValues[0]) {
        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&asbQuadcopter_DW.XYZ[0])[elIdx] = 0.0F;
          }
        }
      } else if (t >= pTimeValues[3]) {
        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&asbQuadcopter_DW.XYZ[0])[elIdx] = pDataValues[3];
            pDataValues += 4;
          }
        }
      } else {
        int_T currTimeIndex = asbQuadcopter_DW.fromWS_Signal1_IWORK.PrevIndex;
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 3; ++elIdx) {
            (&asbQuadcopter_DW.XYZ[0])[elIdx] = pDataValues[currTimeIndex];
            pDataValues += 4;
          }
        }

        asbQuadcopter_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
      }
    }

    /* RateTransition: '<S7>/Rate Transition3' incorporates:
     *  Clock: '<S7>/Clock'
     *  Constant: '<S8>/Constant'
     *  RelationalOperator: '<S8>/Compare'
     */
    if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
        asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
      asbQuadcopter_DW.takeoff_flag = (asbQuadcopter_M->Timing.t[0] < 1.0);
    }

    /* End of RateTransition: '<S7>/Rate Transition3' */

    /* UnitDelay: '<S11>/Output' */
    asbQuadcopter_DW.Output = asbQuadcopter_DW.Output_DSTATE;
  }

  /* BusCreator: '<S7>/Bus Creator' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S9>/Constant'
   *  Logic: '<S7>/Logical Operator'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   */
  cmd_inport.controlModePosVSOrient = ((rtb_YawPitchRoll[2] == 0.0F) &&
    (rtb_YawPitchRoll[1] == 0.0F));
  cmd_inport.takeoff_flag = asbQuadcopter_DW.takeoff_flag;
  cmd_inport.pos_ref[0] = asbQuadcopter_DW.XYZ[0];
  cmd_inport.orient_ref[0] = rtb_YawPitchRoll[0];
  cmd_inport.pos_ref[1] = asbQuadcopter_DW.XYZ[1];
  cmd_inport.orient_ref[1] = rtb_YawPitchRoll[1];
  cmd_inport.pos_ref[2] = asbQuadcopter_DW.XYZ[2];
  cmd_inport.orient_ref[2] = rtb_YawPitchRoll[2];
  cmd_inport.live_time_ticks = asbQuadcopter_DW.Output;

  /* Outputs for Atomic SubSystem: '<S4>/Sensors (Feedthrough)' */
  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
    /* BusCreator: '<S33>/Bus Creator6' incorporates:
     *  Constant: '<S33>/begin_echo_index'
     *  Constant: '<S33>/begin_echo_index1'
     *  Constant: '<S33>/begin_echo_index2'
     *  Constant: '<S33>/begin_echo_index3'
     *  Constant: '<S33>/begin_echo_index4'
     *  Constant: '<S33>/begin_echo_index5'
     *  Constant: '<S33>/begin_echo_index6'
     */
    rtb_HAL_echo_t.begin_echo_index = 0U;
    rtb_HAL_echo_t.end_echo_index = 0U;
    rtb_HAL_echo_t.max_value_index = 0;
    rtb_HAL_echo_t.max_value = 0;
    rtb_HAL_echo_t.precedent = 0U;
    rtb_HAL_echo_t.d_echo = 0;
    rtb_HAL_echo_t.pre_max_index = 0U;

    /* Concatenate: '<S31>/Vector Concatenate' */
    rtb_tab_echo[0] = rtb_HAL_echo_t;
    rtb_tab_echo[1] = rtb_HAL_echo_t;
    rtb_tab_echo[2] = rtb_HAL_echo_t;
    rtb_tab_echo[3] = rtb_HAL_echo_t;
    rtb_tab_echo[4] = rtb_HAL_echo_t;
    rtb_tab_echo[5] = rtb_HAL_echo_t;
    rtb_tab_echo[6] = rtb_HAL_echo_t;
    rtb_tab_echo[7] = rtb_HAL_echo_t;
    rtb_tab_echo[8] = rtb_HAL_echo_t;
    rtb_tab_echo[9] = rtb_HAL_echo_t;
    rtb_tab_echo[10] = rtb_HAL_echo_t;
    rtb_tab_echo[11] = rtb_HAL_echo_t;
    rtb_tab_echo[12] = rtb_HAL_echo_t;
    rtb_tab_echo[13] = rtb_HAL_echo_t;
    rtb_tab_echo[14] = rtb_HAL_echo_t;
    rtb_tab_echo[15] = rtb_HAL_echo_t;
    rtb_tab_echo[16] = rtb_HAL_echo_t;
    rtb_tab_echo[17] = rtb_HAL_echo_t;
    rtb_tab_echo[18] = rtb_HAL_echo_t;
    rtb_tab_echo[19] = rtb_HAL_echo_t;
    rtb_tab_echo[20] = rtb_HAL_echo_t;
    rtb_tab_echo[21] = rtb_HAL_echo_t;
    rtb_tab_echo[22] = rtb_HAL_echo_t;
    rtb_tab_echo[23] = rtb_HAL_echo_t;
    rtb_tab_echo[24] = rtb_HAL_echo_t;
    rtb_tab_echo[25] = rtb_HAL_echo_t;
    rtb_tab_echo[26] = rtb_HAL_echo_t;
    rtb_tab_echo[27] = rtb_HAL_echo_t;
    rtb_tab_echo[28] = rtb_HAL_echo_t;
    rtb_tab_echo[29] = rtb_HAL_echo_t;

    /* BusCreator: '<S34>/Bus Creator6' incorporates:
     *  Constant: '<S34>/begin_echo_index'
     *  Constant: '<S34>/begin_echo_index1'
     *  Constant: '<S34>/begin_echo_index2'
     *  Constant: '<S34>/begin_echo_index3'
     *  Constant: '<S34>/begin_echo_index4'
     *  Constant: '<S34>/begin_echo_index5'
     *  Constant: '<S34>/begin_echo_index6'
     */
    rtb_HAL_echo_t.begin_echo_index = 0U;
    rtb_HAL_echo_t.end_echo_index = 0U;
    rtb_HAL_echo_t.max_value_index = 0;
    rtb_HAL_echo_t.max_value = 0;
    rtb_HAL_echo_t.precedent = 0U;
    rtb_HAL_echo_t.d_echo = 0;
    rtb_HAL_echo_t.pre_max_index = 0U;

    /* Concatenate: '<S32>/Vector Concatenate' */
    rtb_tab_echo_h[0] = rtb_HAL_echo_t;
    rtb_tab_echo_h[1] = rtb_HAL_echo_t;
    rtb_tab_echo_h[2] = rtb_HAL_echo_t;
    rtb_tab_echo_h[3] = rtb_HAL_echo_t;
    rtb_tab_echo_h[4] = rtb_HAL_echo_t;
    rtb_tab_echo_h[5] = rtb_HAL_echo_t;
    rtb_tab_echo_h[6] = rtb_HAL_echo_t;
    rtb_tab_echo_h[7] = rtb_HAL_echo_t;
    rtb_tab_echo_h[8] = rtb_HAL_echo_t;
    rtb_tab_echo_h[9] = rtb_HAL_echo_t;
    rtb_tab_echo_h[10] = rtb_HAL_echo_t;
    rtb_tab_echo_h[11] = rtb_HAL_echo_t;
    rtb_tab_echo_h[12] = rtb_HAL_echo_t;
    rtb_tab_echo_h[13] = rtb_HAL_echo_t;
    rtb_tab_echo_h[14] = rtb_HAL_echo_t;
    rtb_tab_echo_h[15] = rtb_HAL_echo_t;
    rtb_tab_echo_h[16] = rtb_HAL_echo_t;
    rtb_tab_echo_h[17] = rtb_HAL_echo_t;
    rtb_tab_echo_h[18] = rtb_HAL_echo_t;
    rtb_tab_echo_h[19] = rtb_HAL_echo_t;
    rtb_tab_echo_h[20] = rtb_HAL_echo_t;
    rtb_tab_echo_h[21] = rtb_HAL_echo_t;
    rtb_tab_echo_h[22] = rtb_HAL_echo_t;
    rtb_tab_echo_h[23] = rtb_HAL_echo_t;
    rtb_tab_echo_h[24] = rtb_HAL_echo_t;
    rtb_tab_echo_h[25] = rtb_HAL_echo_t;
    rtb_tab_echo_h[26] = rtb_HAL_echo_t;
    rtb_tab_echo_h[27] = rtb_HAL_echo_t;
    rtb_tab_echo_h[28] = rtb_HAL_echo_t;
    rtb_tab_echo_h[29] = rtb_HAL_echo_t;
    for (i = 0; i < 3; i++) {
      /* Memory: '<S16>/Memory' */
      rtb_Product_j[i] = asbQuadcopter_DW.Memory_PreviousInput.V_body[i];
      rtb_Product_k[i] = asbQuadcopter_DW.Memory_PreviousInput.Omega_body[i];
      rtb_Product_o[i] = asbQuadcopter_DW.Memory_PreviousInput.X_ned[i];

      /* Bias: '<S19>/Bias1' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion3'
       *  Memory: '<S16>/Memory'
       *  Product: '<S19>/Product'
       *  Sum: '<S19>/Sum'
       */
      asbQuadcopter_DW.Bias1[i] = (real32_T)
        (asbQuadcopter_DW.Memory_PreviousInput.Accel_body[i] -
         ((asbQuadcopter_DW.Memory_PreviousInput.DCM_be[i + 3] *
           asbQuadcopter_DW.BusCreator.Gravity_ned[1] +
           asbQuadcopter_DW.Memory_PreviousInput.DCM_be[i] *
           asbQuadcopter_DW.BusCreator.Gravity_ned[0]) +
          asbQuadcopter_DW.Memory_PreviousInput.DCM_be[i + 6] *
          asbQuadcopter_DW.BusCreator.Gravity_ned[2])) + rtCP_Bias1_Bias_a[i];

      /* Bias: '<S19>/Bias2' incorporates:
       *  DataTypeConversion: '<S19>/Data Type Conversion2'
       *  Memory: '<S16>/Memory'
       */
      asbQuadcopter_DW.Bias2[i] = (real32_T)
        asbQuadcopter_DW.Memory_PreviousInput.Omega_body[i] +
        rtCP_Bias2_Bias_i[i];
    }

    /* Saturate: '<S19>/Saturation' incorporates:
     *  Gain: '<S19>/altToprs_gain1'
     *  Memory: '<S16>/Memory'
     */
    if ((real32_T)-asbQuadcopter_DW.Memory_PreviousInput.X_ned[2] <= 0.44F) {
      asbQuadcopter_DW.altitude_sonar = 0.44F;
    } else {
      asbQuadcopter_DW.altitude_sonar = (real32_T)
        -asbQuadcopter_DW.Memory_PreviousInput.X_ned[2];
    }

    /* End of Saturate: '<S19>/Saturation' */

    /* Bias: '<S19>/Assumes takeoff was level1' incorporates:
     *  Gain: '<S19>/altToprs_gain'
     *  Memory: '<S16>/Memory'
     */
    asbQuadcopter_DW.Assumestakeoffwaslevel1 = (real32_T)(12.017250061035156 *
      asbQuadcopter_DW.Memory_PreviousInput.X_ned[2]) + 101270.953F;

    /* BusCreator: '<S22>/Bus Creator' incorporates:
     *  Constant: '<S22>/z'
     *  Constant: '<S22>/z1'
     *  Constant: '<S22>/z2'
     */
    rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

    /* Concatenate: '<S22>/Vector Concatenate' */
    asbQuadcopter_DW.VectorConcatenate[0] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate[1] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate[2] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate[3] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate[4] = rtb_HAL_fifo_gyro_SI_TempCorr;

    /* BusCreator: '<S23>/Bus Creator' incorporates:
     *  Constant: '<S23>/x'
     *  Constant: '<S23>/x1'
     *  Constant: '<S23>/x2'
     */
    rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

    /* Concatenate: '<S23>/Vector Concatenate' */
    asbQuadcopter_DW.VectorConcatenate_a[0] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_a[1] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_a[2] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_a[3] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_a[4] = rtb_HAL_fifo_gyro_SI_TempCorr;

    /* BusCreator: '<S24>/Bus Creator' incorporates:
     *  Constant: '<S24>/z'
     *  Constant: '<S24>/z1'
     *  Constant: '<S24>/z2'
     */
    rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

    /* Concatenate: '<S24>/Vector Concatenate' */
    asbQuadcopter_DW.VectorConcatenate_g[0] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_g[1] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_g[2] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_g[3] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_g[4] = rtb_HAL_fifo_gyro_SI_TempCorr;

    /* BusCreator: '<S25>/Bus Creator' incorporates:
     *  Constant: '<S25>/z'
     *  Constant: '<S25>/z1'
     *  Constant: '<S25>/z2'
     */
    rtb_HAL_fifo_gyro_SI_TempCorr.x = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.y = 0.0F;
    rtb_HAL_fifo_gyro_SI_TempCorr.z = 0.0F;

    /* Concatenate: '<S25>/Vector Concatenate' */
    asbQuadcopter_DW.VectorConcatenate_c[0] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_c[1] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_c[2] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_c[3] = rtb_HAL_fifo_gyro_SI_TempCorr;
    asbQuadcopter_DW.VectorConcatenate_c[4] = rtb_HAL_fifo_gyro_SI_TempCorr;

    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  Gain: '<S18>/Gain1'
     *  Gain: '<S18>/Gain2'
     *  Product: '<S18>/Product'
     *  Product: '<S18>/Product1'
     *  Sum: '<S18>/Add1'
     */
    rtb_DataTypeConversion_b[0] = (real32_T)(0.8 * rtb_Product_k[1] *
      -rtb_Product_o[2] + rtb_Product_j[0]);
    rtb_DataTypeConversion_b[1] = (real32_T)(-0.8 * rtb_Product_k[0] *
      -rtb_Product_o[2] + rtb_Product_j[1]);
    rtb_DataTypeConversion_b[2] = (real32_T)rtb_Product_j[2];

    /* BusCreator generated from: '<S20>/Bus Creator4' */
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_vbat_SI.vbat_V = 3.5F;
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_vbat_SI.vbat_percentage = 70U;
  }

  /* BusCreator generated from: '<S20>/Bus Creator4' incorporates:
   *  Constant: '<S21>/temperature'
   *  DataTypeConversion: '<S19>/Data Type Conversion1'
   */
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_acc_SI.x = asbQuadcopter_DW.Bias1[0];
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_acc_SI.y = asbQuadcopter_DW.Bias1[1];
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_acc_SI.z = asbQuadcopter_DW.Bias1[2];
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_acc_SI.temperature = 0.0F;

  /* BusCreator generated from: '<S20>/Bus Creator4' incorporates:
   *  Constant: '<S26>/temperature'
   *  Constant: '<S26>/temperature_lsb'
   *  DataTypeConversion: '<S19>/Data Type Conversion1'
   */
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_gyro_SI.x = asbQuadcopter_DW.Bias2[0];
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_gyro_SI.y = asbQuadcopter_DW.Bias2[1];
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_gyro_SI.z = asbQuadcopter_DW.Bias2[2];
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_gyro_SI.temperature = 0.0F;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_gyro_SI.temperature_lsb = 0;
  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
    /* BusCreator generated from: '<S20>/Bus Creator4' incorporates:
     *  Constant: '<S27>/z'
     *  Constant: '<S27>/z1'
     *  Constant: '<S27>/z2'
     */
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_magn_mG.x = 0.0F;
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_magn_mG.y = 0.0F;
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_magn_mG.z = 0.0F;

    /* BusCreator: '<S31>/Bus Creator7' incorporates:
     *  Constant: '<S31>/number_of_echoes'
     */
    asbQuadcopter_DW.HAL_list_echo.number_of_echoes = 0U;
    memcpy(&asbQuadcopter_DW.HAL_list_echo.tab_echo[0], &rtb_tab_echo[0], 30U *
           sizeof(HAL_echo_t));

    /* BusCreator: '<S32>/Bus Creator7' incorporates:
     *  Constant: '<S32>/number_of_echoes'
     */
    memcpy(&asbQuadcopter_DW.HAL_list_echo_o.tab_echo[0], &rtb_tab_echo_h[0],
           30U * sizeof(HAL_echo_t));
    asbQuadcopter_DW.HAL_list_echo_o.number_of_echoes = 0U;
  }

  /* BusCreator generated from: '<S20>/Bus Creator4' incorporates:
   *  Constant: '<S28>/temperature'
   *  DataTypeConversion: '<S19>/Data Type Conversion1'
   */
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_pressure_SI.temperature = 0.0;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_pressure_SI.pressure =
    asbQuadcopter_DW.Assumestakeoffwaslevel1;

  /* BusCreator: '<S29>/Bus Creator2' incorporates:
   *  Constant: '<S29>/raw_altitude'
   *  Constant: '<S29>/raw_altitude1'
   *  Constant: '<S29>/raw_altitude2'
   *  Constant: '<S29>/raw_altitude3'
   *  Constant: '<S29>/raw_altitude4'
   *  DataTypeConversion: '<S19>/Data Type Conversion1'
   */
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ultrasound_SI.altitude =
    asbQuadcopter_DW.altitude_sonar;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ultrasound_SI.raw_altitude = 0.0F;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ultrasound_SI.nb_echo = 0U;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ultrasound_SI.measure_ref = 0;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ultrasound_SI.measure_status = 0;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ultrasound_SI.new_data = 0U;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ultrasound_SI.HAL_list_echo =
    asbQuadcopter_DW.HAL_list_echo;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ultrasound_SI.HAL_list_echo_p =
    asbQuadcopter_DW.HAL_list_echo_o;

  /* BusCreator: '<S20>/Bus Creator4' incorporates:
   *  Constant: '<S20>/number_HAL_read_call'
   *  Constant: '<S20>/number_HAL_read_call1'
   *  Constant: '<S20>/number_HAL_read_call2'
   *  Constant: '<S20>/number_HAL_read_call3'
   *  Constant: '<S20>/number_HAL_read_call4'
   *  Constant: '<S20>/number_HAL_read_call5'
   *  Constant: '<S20>/number_HAL_read_call6'
   *  Constant: '<S20>/number_HAL_read_call7'
   *  Constant: '<S20>/number_HAL_read_call8'
   */
  asbQuadcopter_DW.HAL_acquisition_t_g.number_HAL_read_call = 0;
  asbQuadcopter_DW.HAL_acquisition_t_g.timestamp = 0U;
  asbQuadcopter_DW.HAL_acquisition_t_g.status = 0U;
  asbQuadcopter_DW.HAL_acquisition_t_g.used = 0U;
  asbQuadcopter_DW.HAL_acquisition_t_g.count_user = 0U;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_fifo_count = 0U;
  asbQuadcopter_DW.HAL_acquisition_t_g.fifo_timestamp = 0U;
  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_ref_IMU_temp = 0.0F;
  for (i = 0; i < 5; i++) {
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_fifo_gyro_SI_TempCorr[i] =
      asbQuadcopter_DW.VectorConcatenate[i];
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_fifo_acce_SI_TempCorr[i] =
      asbQuadcopter_DW.VectorConcatenate_a[i];
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_fifo_gyro_SI[i] =
      asbQuadcopter_DW.VectorConcatenate_g[i];
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_fifo_acce_SI[i] =
      asbQuadcopter_DW.VectorConcatenate_c[i];
    asbQuadcopter_DW.HAL_acquisition_t_g.HAL_fifo_fsync[i] = 0U;
  }

  asbQuadcopter_DW.HAL_acquisition_t_g.HAL_fifo_size = 0;
  memset(&asbQuadcopter_DW.HAL_acquisition_t_g.padding[0], 0, 196U * sizeof
         (uint8_T));

  /* End of BusCreator: '<S20>/Bus Creator4' */
  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
    /* BusCreator: '<S16>/Bus Creator1' incorporates:
     *  BusCreator: '<S16>/Bus Creator2'
     *  Constant: '<S16>/Constant1'
     *  Constant: '<S16>/_DUMMY_FLAG_usePosVIS'
     */
    sensor_inport.VisionSensors.opticalFlow_data[0] = rtb_DataTypeConversion_b[0];
    sensor_inport.VisionSensors.opticalFlow_data[1] = rtb_DataTypeConversion_b[1];
    sensor_inport.VisionSensors.opticalFlow_data[2] = rtb_DataTypeConversion_b[2];
    sensor_inport.VisionSensors.posVIS_data[0] = -99.0F;
    sensor_inport.VisionSensors.posVIS_data[1] = 0.0F;
    sensor_inport.VisionSensors.posVIS_data[2] = 0.0F;
    sensor_inport.VisionSensors.posVIS_data[3] = -9.0F;
    sensor_inport.VisionSensors.usePosVIS_flag = 0.0F;
    sensor_inport.HALSensors = asbQuadcopter_DW.HAL_acquisition_t_g;
    for (i = 0; i < 8; i++) {
      sensor_inport.SensorCalibration[i] = rtCP_Constant1_Value[i];
    }

    /* End of BusCreator: '<S16>/Bus Creator1' */

    /* ModelReference: '<Root>/FCS' */
    flightControlSystem();
  }

  /* End of Outputs for SubSystem: '<S4>/Sensors (Feedthrough)' */

  /* ModelReference: '<S1>/Nonlinear Airframe' */
  nonlinearAirframe(&(asbQuadcopter_DW.NonlinearAirframe_InstanceData.rtm),
                    &motors_outport[0], &asbQuadcopter_DW.BusCreator,
                    &asbQuadcopter_DW.NonlinearAirframe,
                    &(asbQuadcopter_DW.NonlinearAirframe_InstanceData.rtdw),
                    &(asbQuadcopter_X.NonlinearAirframe_CSTATE));

  /* Gain: '<S52>/1//2' */
  rtb_Bias3 = 0.5 * asbQuadcopter_DW.NonlinearAirframe.Euler[0];

  /* Trigonometry: '<S52>/Trigonometric Function' */
  rtb_Product1_i = sin(rtb_Bias3);

  /* Product: '<S52>/Product' */
  rtb_Product_j[0] = rtb_Product1_i;
  rtb_Product_j[1] = rtb_Product1_i * 0.0;
  rtb_Product_j[2] = rtb_Product1_i * 0.0;

  /* Gain: '<S54>/1//2' */
  rtb_Product1_p = 0.5 * asbQuadcopter_DW.NonlinearAirframe.Euler[2];

  /* Trigonometry: '<S54>/Trigonometric Function1' */
  rtb_Product1_i = cos(rtb_Product1_p);

  /* Gain: '<S53>/1//2' */
  rtb_Sum_a = 0.5 * asbQuadcopter_DW.NonlinearAirframe.Euler[1];

  /* Trigonometry: '<S53>/Trigonometric Function1' */
  rtb_Product2_b = cos(rtb_Sum_a);

  /* Trigonometry: '<S54>/Trigonometric Function' */
  rtb_TrigonometricFunction_h = sin(rtb_Product1_p);

  /* Trigonometry: '<S53>/Trigonometric Function' */
  rtb_Sum_a = sin(rtb_Sum_a);

  /* Product: '<S54>/Product' */
  rtb_Product_k[0] = rtb_TrigonometricFunction_h * 0.0;

  /* Product: '<S53>/Product' */
  rtb_Product_o[0] = rtb_Sum_a * 0.0;

  /* Product: '<S54>/Product' */
  rtb_Product_k[1] = -rtb_TrigonometricFunction_h;

  /* Product: '<S53>/Product' */
  rtb_Product_o[1] = rtb_Sum_a * 0.0;

  /* Product: '<S54>/Product' */
  rtb_Product_k[2] = rtb_TrigonometricFunction_h * 0.0;

  /* Product: '<S53>/Product' */
  rtb_Product_o[2] = rtb_Sum_a;

  /* Sum: '<S55>/Sum' incorporates:
   *  Product: '<S53>/Product'
   *  Product: '<S54>/Product'
   *  Product: '<S55>/Product'
   *  Product: '<S55>/Product1'
   *  Product: '<S55>/Product2'
   *  Product: '<S55>/Product3'
   */
  rtb_Sum_a = ((rtb_Product1_i * rtb_Product2_b - rtb_Product_k[0] *
                rtb_Product_o[0]) - -rtb_TrigonometricFunction_h *
               rtb_Product_o[1]) - rtb_Product_k[2] * rtb_Sum_a;

  /* Sum: '<S56>/Sum' incorporates:
   *  Product: '<S54>/Product'
   *  Product: '<S56>/Product'
   *  Product: '<S56>/Product1'
   *  Product: '<S56>/Product2'
   *  Product: '<S56>/Product3'
   */
  rtb_Product1_p = ((rtb_Product1_i * rtb_Product_o[0] + rtb_Product_k[0] *
                     rtb_Product2_b) + -rtb_TrigonometricFunction_h *
                    rtb_Product_o[2]) - rtb_Product_k[2] * rtb_Product_o[1];

  /* Trigonometry: '<S52>/Trigonometric Function1' */
  rtb_Bias3 = cos(rtb_Bias3);

  /* Sum: '<S57>/Sum' incorporates:
   *  Product: '<S54>/Product'
   *  Product: '<S57>/Product'
   *  Product: '<S57>/Product1'
   *  Product: '<S57>/Product2'
   *  Product: '<S57>/Product3'
   */
  rtb_TrigonometricFunction_h = ((rtb_Product1_i * rtb_Product_o[1] -
    rtb_Product_k[0] * rtb_Product_o[2]) + -rtb_TrigonometricFunction_h *
    rtb_Product2_b) + rtb_Product_k[2] * rtb_Product_o[0];

  /* Product: '<S58>/Product' */
  rtb_Product1_i *= rtb_Product_o[2];

  /* Product: '<S58>/Product3' */
  rtb_Product2_b *= rtb_Product_k[2];

  /* Sum: '<S58>/Sum' incorporates:
   *  Product: '<S58>/Product1'
   *  Product: '<S58>/Product2'
   */
  rtb_Product1_i = ((rtb_Product_k[0] * rtb_Product_o[1] + rtb_Product1_i) -
                    rtb_Product_k[1] * rtb_Product_o[0]) + rtb_Product2_b;

  /* Sum: '<S60>/Sum' incorporates:
   *  Product: '<S60>/Product'
   *  Product: '<S60>/Product1'
   *  Product: '<S60>/Product2'
   *  Product: '<S60>/Product3'
   */
  rtb_Product2_b = ((rtb_Sum_a * rtb_Product_j[0] + rtb_Product1_p * rtb_Bias3)
                    + rtb_TrigonometricFunction_h * rtb_Product_j[2]) -
    rtb_Product1_i * rtb_Product_j[1];

  /* Sum: '<S61>/Sum' incorporates:
   *  Product: '<S61>/Product'
   *  Product: '<S61>/Product1'
   *  Product: '<S61>/Product2'
   *  Product: '<S61>/Product3'
   */
  rtb_Sum_b = ((rtb_Sum_a * rtb_Product_j[1] - rtb_Product1_p * rtb_Product_j[2])
               + rtb_TrigonometricFunction_h * rtb_Bias3) + rtb_Product1_i *
    rtb_Product_j[0];

  /* Sum: '<S62>/Sum' incorporates:
   *  Product: '<S62>/Product'
   *  Product: '<S62>/Product1'
   *  Product: '<S62>/Product2'
   *  Product: '<S62>/Product3'
   */
  rtb_Sum_cy = ((rtb_Sum_a * rtb_Product_j[2] + rtb_Product1_p * rtb_Product_j[1])
                - rtb_TrigonometricFunction_h * rtb_Product_j[0]) +
    rtb_Product1_i * rtb_Bias3;

  /* Product: '<S59>/Product1' */
  rtb_Product1_p *= rtb_Product_j[0];

  /* Product: '<S59>/Product2' */
  rtb_TrigonometricFunction_h *= rtb_Product_j[1];

  /* Product: '<S59>/Product3' */
  rtb_Product1_i *= rtb_Product_j[2];

  /* Sum: '<S59>/Sum' incorporates:
   *  Product: '<S59>/Product'
   */
  rtb_Bias3 = ((rtb_Sum_a * rtb_Bias3 - rtb_Product1_p) -
               rtb_TrigonometricFunction_h) - rtb_Product1_i;

  /* Trigonometry: '<S49>/Trigonometric Function2' */
  if (rtb_Bias3 > 1.0) {
    rtb_Bias3 = 1.0;
  } else {
    if (rtb_Bias3 < -1.0) {
      rtb_Bias3 = -1.0;
    }
  }

  rtb_TrigonometricFunction_h = acos(rtb_Bias3);

  /* End of Trigonometry: '<S49>/Trigonometric Function2' */

  /* Trigonometry: '<S49>/Trigonometric Function' */
  rtb_Bias3 = sin(rtb_TrigonometricFunction_h);

  /* Switch: '<S49>/Switch' incorporates:
   *  Constant: '<S49>/Constant'
   */
  if (!(rtb_Bias3 != 0.0)) {
    rtb_Bias3 = 1.0E-6;
  }

  /* End of Switch: '<S49>/Switch' */

  /* RateTransition: '<S43>/Rate Transition' incorporates:
   *  Gain: '<S44>/rad-->deg1'
   *  Gain: '<S49>/2'
   *  Product: '<S49>/Product'
   *  RateTransition: '<S43>/Rate Transition1'
   */
  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
    if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
        asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0) {
      asbQuadcopter_DW.RateTransition_Buffer[0] = rtb_Product2_b / rtb_Bias3;
      asbQuadcopter_DW.RateTransition_Buffer[1] = rtb_Sum_b / rtb_Bias3;
      asbQuadcopter_DW.RateTransition_Buffer[2] = rtb_Sum_cy / rtb_Bias3;
      asbQuadcopter_DW.RateTransition_Buffer[3] = 2.0 *
        rtb_TrigonometricFunction_h;
    }

    if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
        asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0) {
      asbQuadcopter_DW.RateTransition1_Buffer[0] =
        asbQuadcopter_DW.NonlinearAirframe.X_ned[0];
      asbQuadcopter_DW.RateTransition1_Buffer[1] =
        -asbQuadcopter_DW.NonlinearAirframe.X_ned[2];
      asbQuadcopter_DW.RateTransition1_Buffer[2] =
        asbQuadcopter_DW.NonlinearAirframe.X_ned[1];
    }
  }

  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0) {
    rtb_RateTransition[0] = asbQuadcopter_DW.RateTransition_Buffer[0];
    rtb_RateTransition[1] = asbQuadcopter_DW.RateTransition_Buffer[1];
    rtb_RateTransition[2] = asbQuadcopter_DW.RateTransition_Buffer[2];
    rtb_RateTransition[3] = asbQuadcopter_DW.RateTransition_Buffer[3];
    rtb_RateTransition1[0] = asbQuadcopter_DW.RateTransition1_Buffer[0];
    rtb_RateTransition1[1] = asbQuadcopter_DW.RateTransition1_Buffer[1];
    rtb_RateTransition1[2] = asbQuadcopter_DW.RateTransition1_Buffer[2];
  }

  /* End of RateTransition: '<S43>/Rate Transition' */

  /* Bias: '<S43>/Camera bias Iso' */
  rtb_Product_j[0] = asbQuadcopter_DW.NonlinearAirframe.X_ned[0] + 0.9009;
  rtb_Product_j[1] = asbQuadcopter_DW.NonlinearAirframe.X_ned[1] + 0.99;
  rtb_Product_j[2] = asbQuadcopter_DW.NonlinearAirframe.X_ned[2] + -0.6247;

  /* RateTransition: '<S43>/Rate Transition2' incorporates:
   *  Gain: '<S46>/rad-->deg1'
   */
  if ((rtmIsMajorTimeStep(asbQuadcopter_M) &&
       asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
       (asbQuadcopter_M) &&
       asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0)) {
    asbQuadcopter_DW.RateTransition2_Buffer_h[0] = rtb_Product_j[0];
    asbQuadcopter_DW.RateTransition2_Buffer_h[1] = -rtb_Product_j[2];
    asbQuadcopter_DW.RateTransition2_Buffer_h[2] = rtb_Product_j[1];
  }

  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0) {
    rtb_RateTransition2_k[0] = asbQuadcopter_DW.RateTransition2_Buffer_h[0];
    rtb_RateTransition2_k[1] = asbQuadcopter_DW.RateTransition2_Buffer_h[1];
    rtb_RateTransition2_k[2] = asbQuadcopter_DW.RateTransition2_Buffer_h[2];
  }

  /* End of RateTransition: '<S43>/Rate Transition2' */

  /* Bias: '<S43>/Camera bias Chase' */
  rtb_Product_j[0] = asbQuadcopter_DW.NonlinearAirframe.X_ned[0] + -4.0;
  rtb_Product_j[1] = asbQuadcopter_DW.NonlinearAirframe.X_ned[1];
  rtb_Product_j[2] = asbQuadcopter_DW.NonlinearAirframe.X_ned[2] + -0.9558;

  /* RateTransition: '<S43>/Rate Transition3' incorporates:
   *  Gain: '<S45>/rad-->deg1'
   */
  if ((rtmIsMajorTimeStep(asbQuadcopter_M) &&
       asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) && (rtmIsMajorTimeStep
       (asbQuadcopter_M) &&
       asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0)) {
    asbQuadcopter_DW.RateTransition3_Buffer[0] = rtb_Product_j[0];
    asbQuadcopter_DW.RateTransition3_Buffer[1] = -rtb_Product_j[2];
    asbQuadcopter_DW.RateTransition3_Buffer[2] = rtb_Product_j[1];
  }

  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[2] == 0) {
    rtb_Product_j[0] = asbQuadcopter_DW.RateTransition3_Buffer[0];
    rtb_Product_j[1] = asbQuadcopter_DW.RateTransition3_Buffer[1];
    rtb_Product_j[2] = asbQuadcopter_DW.RateTransition3_Buffer[2];
  }

  /* End of RateTransition: '<S43>/Rate Transition3' */
  if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
      asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
    /* Gain: '<S48>/Visualization Gain' incorporates:
     *  DataTypeConversion: '<S48>/Data Type Conversion'
     *  Gain: '<S48>/Gain'
     */
    asbQuadcopter_DW.VisualizationGain[0] = -13840.8 * motors_outport[0] *
      0.0001;
    asbQuadcopter_DW.VisualizationGain[1] = -13840.8 * motors_outport[1] *
      0.0001;
    asbQuadcopter_DW.VisualizationGain[2] = -13840.8 * motors_outport[2] *
      0.0001;
    asbQuadcopter_DW.VisualizationGain[3] = -13840.8 * motors_outport[3] *
      0.0001;

    /* Assertion: '<S40>/Assertion' incorporates:
     *  Constant: '<S40>/min_val'
     *  RelationalOperator: '<S40>/min_relop'
     */
    utAssert(71.3232 <= asbQuadcopter_DW.NonlinearAirframe.LLA[2]);

    /* Assertion: '<S5>/Flag has been triggered' incorporates:
     *  Constant: '<S35>/Constant'
     *  Logic: '<S5>/Logical Operator'
     *  RelationalOperator: '<S35>/Compare'
     */
    utAssert(flag_outport <= 0);

    /* Switch: '<S14>/FixPt Switch' incorporates:
     *  Constant: '<S13>/FixPt Constant'
     *  Sum: '<S13>/FixPt Sum1'
     */
    rtb_FixPtSwitch = asbQuadcopter_DW.Output + 1U;
  }

  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    if (rtmIsMajorTimeStep(asbQuadcopter_M) &&
        asbQuadcopter_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S11>/Output' */
      asbQuadcopter_DW.Output_DSTATE = rtb_FixPtSwitch;

      /* Update for Atomic SubSystem: '<S4>/Sensors (Feedthrough)' */
      /* Update for Memory: '<S16>/Memory' */
      asbQuadcopter_DW.Memory_PreviousInput = asbQuadcopter_DW.NonlinearAirframe;

      /* End of Update for SubSystem: '<S4>/Sensors (Feedthrough)' */
    }

    /* Update for ModelReference: '<S1>/Nonlinear Airframe' */
    nonlinearAirframe_Update();
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(asbQuadcopter_M)) {
    rt_ertODEUpdateContinuousStates(&asbQuadcopter_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++asbQuadcopter_M->Timing.clockTick0;
    asbQuadcopter_M->Timing.t[0] = rtsiGetSolverStopTime
      (&asbQuadcopter_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      asbQuadcopter_M->Timing.clockTick1++;
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void asbQuadcopter_derivatives(void)
{
  XDot_asbQuadcopter_T *_rtXdot;
  _rtXdot = ((XDot_asbQuadcopter_T *) asbQuadcopter_M->derivs);

  /* Derivatives for Integrator: '<S48>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = asbQuadcopter_DW.VisualizationGain[0];
  _rtXdot->Integrator_CSTATE[1] = asbQuadcopter_DW.VisualizationGain[1];
  _rtXdot->Integrator_CSTATE[2] = asbQuadcopter_DW.VisualizationGain[2];
  _rtXdot->Integrator_CSTATE[3] = asbQuadcopter_DW.VisualizationGain[3];

  /* Derivatives for ModelReference: '<S1>/Nonlinear Airframe' */
  nonlinearAirframe_Deriv(&(asbQuadcopter_DW.NonlinearAirframe_InstanceData.rtdw),
    &(((XDot_asbQuadcopter_T *) asbQuadcopter_M->derivs)
      ->NonlinearAirframe_CSTATE));
}

/* Model initialize function */
void asbQuadcopter_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&asbQuadcopter_M->solverInfo,
                          &asbQuadcopter_M->Timing.simTimeStep);
    rtsiSetTPtr(&asbQuadcopter_M->solverInfo, &rtmGetTPtr(asbQuadcopter_M));
    rtsiSetStepSizePtr(&asbQuadcopter_M->solverInfo,
                       &asbQuadcopter_M->Timing.stepSize0);
    rtsiSetdXPtr(&asbQuadcopter_M->solverInfo, &asbQuadcopter_M->derivs);
    rtsiSetContStatesPtr(&asbQuadcopter_M->solverInfo, (real_T **)
                         &asbQuadcopter_M->contStates);
    rtsiSetNumContStatesPtr(&asbQuadcopter_M->solverInfo,
      &asbQuadcopter_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&asbQuadcopter_M->solverInfo,
      &asbQuadcopter_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&asbQuadcopter_M->solverInfo,
      &asbQuadcopter_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&asbQuadcopter_M->solverInfo,
      &asbQuadcopter_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&asbQuadcopter_M->solverInfo, (&rtmGetErrorStatus
      (asbQuadcopter_M)));
    rtsiSetRTModelPtr(&asbQuadcopter_M->solverInfo, asbQuadcopter_M);
  }

  rtsiSetSimTimeStep(&asbQuadcopter_M->solverInfo, MAJOR_TIME_STEP);
  asbQuadcopter_M->intgData.y = asbQuadcopter_M->odeY;
  asbQuadcopter_M->intgData.f[0] = asbQuadcopter_M->odeF[0];
  asbQuadcopter_M->intgData.f[1] = asbQuadcopter_M->odeF[1];
  asbQuadcopter_M->intgData.f[2] = asbQuadcopter_M->odeF[2];
  asbQuadcopter_M->contStates = ((X_asbQuadcopter_T *) &asbQuadcopter_X);
  asbQuadcopter_M->periodicContStateIndices = ((int_T*)
    asbQuadcopter_PeriodicIndX);
  asbQuadcopter_M->periodicContStateRanges = ((real_T*)
    asbQuadcopter_PeriodicRngX);
  rtsiSetSolverData(&asbQuadcopter_M->solverInfo, (void *)
                    &asbQuadcopter_M->intgData);
  rtsiSetSolverName(&asbQuadcopter_M->solverInfo,"ode3");
  rtmSetTPtr(asbQuadcopter_M, &asbQuadcopter_M->Timing.tArray[0]);
  asbQuadcopter_M->Timing.stepSize0 = 0.005;

  /* Model Initialize function for ModelReference Block: '<S1>/Nonlinear Airframe' */
  nonlinearAirframe_initialize(rtmGetErrorStatusPointer(asbQuadcopter_M),
    rtmGetStopRequestedPtr(asbQuadcopter_M), &(asbQuadcopter_M->solverInfo),
    &(asbQuadcopter_DW.NonlinearAirframe_InstanceData.rtm));

  /* Model Initialize function for ModelReference Block: '<Root>/FCS' */
  flightControlSystem_initialize(rtmGetErrorStatusPointer(asbQuadcopter_M));

  /* Start for FromWorkspace: '<S12>/From Workspace' */
  {
    static real_T pTimeValues0[] = { 0.0, 100.0 } ;

    static real32_T pDataValues0[] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

    asbQuadcopter_DW.FromWorkspace_PWORK.TimePtr = (void *) pTimeValues0;
    asbQuadcopter_DW.FromWorkspace_PWORK.DataPtr = (void *) pDataValues0;
    asbQuadcopter_DW.FromWorkspace_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S12>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 100.0 } ;

    static real32_T pDataValues0[] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, -1.5F, -1.5F } ;

    asbQuadcopter_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    asbQuadcopter_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    asbQuadcopter_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }

  /* InitializeConditions for Integrator: '<S48>/Integrator' */
  asbQuadcopter_X.Integrator_CSTATE[0] = 0.1;
  asbQuadcopter_X.Integrator_CSTATE[1] = 0.2;
  asbQuadcopter_X.Integrator_CSTATE[2] = -0.3;
  asbQuadcopter_X.Integrator_CSTATE[3] = -0.4;

  /* SystemInitialize for Atomic SubSystem: '<S4>/Sensors (Feedthrough)' */
  /* InitializeConditions for Memory: '<S16>/Memory' */
  asbQuadcopter_DW.Memory_PreviousInput =
    asbQuadcopter_ConstP.Memory_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S4>/Sensors (Feedthrough)' */

  /* SystemInitialize for ModelReference: '<Root>/FCS' */
  flightControlSystem_Init();

  /* SystemInitialize for ModelReference: '<S1>/Nonlinear Airframe' */
  nonlinearAirframe_Init(&(asbQuadcopter_X.NonlinearAirframe_CSTATE));

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[7] = { 0, 1, 2, 3, 4, 5, 6 };

    real_T rootPeriodicContStateRanges[14] = { -6.2831853071795862,
      6.2831853071795862, -6.2831853071795862, 6.2831853071795862,
      -6.2831853071795862, 6.2831853071795862, -6.2831853071795862,
      6.2831853071795862, -3.1415926535897931, 3.1415926535897931,
      -3.1415926535897931, 3.1415926535897931, -3.1415926535897931,
      3.1415926535897931 };

    (void) memcpy((void*)asbQuadcopter_PeriodicIndX,
                  rootPeriodicContStateIndices,
                  7*sizeof(int_T));
    (void) memcpy((void*)asbQuadcopter_PeriodicRngX, rootPeriodicContStateRanges,
                  14*sizeof(real_T));
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
