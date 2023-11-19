/*
 * File: nonlinearAirframe.h
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

#ifndef RTW_HEADER_nonlinearAirframe_h_
#define RTW_HEADER_nonlinearAirframe_h_
#include <math.h>
#include <string.h>
#ifndef nonlinearAirframe_COMMON_INCLUDES_
# define nonlinearAirframe_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* nonlinearAirframe_COMMON_INCLUDES_ */

#include "nonlinearAirframe_types.h"

/* Child system includes */
#include "nonlinearAirframe_RotorDynamics.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Block signals and states (default storage) for model 'nonlinearAirframe' */
typedef struct {
  real_T Product2[3];                  /* '<S7>/Product2' */
  real_T Gain[2];                      /* '<S28>/Gain' */
  real_T Sum[3];                       /* '<S2>/Sum' */
  real_T Product[3];                   /* '<S13>/Product' */
  real_T TmpSignalConversionAtphithetaps[3];/* '<S6>/phidot thetadot psidot' */
  real_T Product2_DWORK4[9];           /* '<S7>/Product2' */
} DW_nonlinearAirframe_f_T;

/* Continuous states for model 'nonlinearAirframe' */
typedef struct {
  real_T phithetapsi_CSTATE[3];        /* '<S6>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S2>/p,q,r ' */
  real_T ubvbwb_CSTATE[3];             /* '<S2>/ub,vb,wb' */
  real_T xeyeze_CSTATE[3];             /* '<S2>/xe,ye,ze' */
} X_nonlinearAirframe_n_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_nonlinearAirfram_T[3];
typedef real_T PeriodicRngX_nonlinearAirfram_T[6];

/* State derivatives for model 'nonlinearAirframe' */
typedef struct {
  real_T phithetapsi_CSTATE[3];        /* '<S6>/phi theta psi' */
  real_T pqr_CSTATE[3];                /* '<S2>/p,q,r ' */
  real_T ubvbwb_CSTATE[3];             /* '<S2>/ub,vb,wb' */
  real_T xeyeze_CSTATE[3];             /* '<S2>/xe,ye,ze' */
} XDot_nonlinearAirframe_n_T;

/* State Disabled for model 'nonlinearAirframe' */
typedef struct {
  boolean_T phithetapsi_CSTATE[3];     /* '<S6>/phi theta psi' */
  boolean_T pqr_CSTATE[3];             /* '<S2>/p,q,r ' */
  boolean_T ubvbwb_CSTATE[3];          /* '<S2>/ub,vb,wb' */
  boolean_T xeyeze_CSTATE[3];          /* '<S2>/xe,ye,ze' */
} XDis_nonlinearAirframe_n_T;

/* Invariant block signals for model 'nonlinearAirframe' */
typedef struct {
  const real_T Selector[9];            /* '<S7>/Selector' */
  const real_T Selector2[9];           /* '<S7>/Selector2' */
  const real_T VectorConcatenate_h[12];/* '<S27>/Vector Concatenate' */
  const real_T Switch_d;               /* '<S52>/Switch' */
} ConstB_nonlinearAirframe_h_T;

/* Real-time Model Data Structure */
struct tag_RTM_nonlinearAirframe_T {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
    boolean_T *stopRequestedFlag;
  } Timing;
};

typedef struct {
  DW_nonlinearAirframe_f_T rtdw;
  RT_MODEL_nonlinearAirframe_T rtm;
} MdlrefDW_nonlinearAirframe_T;

/* Model reference registration function */
extern void nonlinearAirframe_initialize(const char_T **rt_errorStatus,
  boolean_T *rt_stopRequested, RTWSolverInfo *rt_solverInfo,
  RT_MODEL_nonlinearAirframe_T *const nonlinearAirframe_M);
extern void nonlinearAirframe_Init(X_nonlinearAirframe_n_T *localX);
extern void nonlinearAirframe_Deriv(DW_nonlinearAirframe_f_T *localDW,
  XDot_nonlinearAirframe_n_T *localXdot);
extern void nonlinearAirframe_Update(void);
extern void nonlinearAirframe(RT_MODEL_nonlinearAirframe_T * const
  nonlinearAirframe_M, const real32_T rtu_Actuators[4], const EnvironmentBus
  *rtu_Environment, StatesBus *rty_States, DW_nonlinearAirframe_f_T *localDW,
  X_nonlinearAirframe_n_T *localX);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Unit Conversion' : Unused code path elimination
 * Block '<S33>/Trigonometric Function' : Unused code path elimination
 * Block '<S16>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S18>/Reshape1' : Reshape block reduction
 * Block '<S18>/Reshape2' : Reshape block reduction
 * Block '<S19>/Reshape1' : Reshape block reduction
 * Block '<S19>/Reshape2' : Reshape block reduction
 * Block '<S7>/Reshape' : Reshape block reduction
 * Block '<S7>/Reshape1' : Reshape block reduction
 * Block '<S11>/Unit Conversion' : Eliminated nontunable gain of 1
 * Block '<S13>/Reshape1' : Reshape block reduction
 * Block '<S13>/Reshape2' : Reshape block reduction
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'nonlinearAirframe'
 * '<S1>'   : 'nonlinearAirframe/Nonlinear'
 * '<S2>'   : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)'
 * '<S3>'   : 'nonlinearAirframe/Nonlinear/AC model'
 * '<S4>'   : 'nonlinearAirframe/Nonlinear/Bus setup'
 * '<S5>'   : 'nonlinearAirframe/Nonlinear/Position on Earth'
 * '<S6>'   : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate DCM & Euler Angles'
 * '<S7>'   : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate omega_dot'
 * '<S8>'   : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Determine Force,  Mass & Inertia'
 * '<S9>'   : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Vbxw'
 * '<S10>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Velocity Conversion'
 * '<S11>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Velocity Conversion1'
 * '<S12>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Velocity Conversion2'
 * '<S13>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/transform to Inertial axes '
 * '<S14>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix'
 * '<S15>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate DCM & Euler Angles/phidot thetadot psidot'
 * '<S16>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate DCM & Euler Angles/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S17>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product'
 * '<S18>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate omega_dot/I x w'
 * '<S19>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate omega_dot/I x w1'
 * '<S20>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product/Subsystem'
 * '<S21>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Calculate omega_dot/3x3 Cross Product/Subsystem1'
 * '<S22>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Vbxw/Subsystem'
 * '<S23>'  : 'nonlinearAirframe/Nonlinear/6DOF (Quaternion)/Vbxw/Subsystem1'
 * '<S24>'  : 'nonlinearAirframe/Nonlinear/AC model/Applied Force Calculation'
 * '<S25>'  : 'nonlinearAirframe/Nonlinear/AC model/Drag Calculation'
 * '<S26>'  : 'nonlinearAirframe/Nonlinear/AC model/Gravity Force Calculation'
 * '<S27>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques'
 * '<S28>'  : 'nonlinearAirframe/Nonlinear/AC model/Drag Calculation/Drag Calc'
 * '<S29>'  : 'nonlinearAirframe/Nonlinear/AC model/Drag Calculation/Drag Calc/Dynamic Pressure'
 * '<S30>'  : 'nonlinearAirframe/Nonlinear/AC model/Drag Calculation/Drag Calc/Dynamic Pressure/dot'
 * '<S31>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/For Each Subsystem'
 * '<S32>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/MotorsToW'
 * '<S33>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/For Each Subsystem/Rotor_Dynamics'
 * '<S34>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/For Each Subsystem/Rotor_Dynamics/3x3 Cross Product'
 * '<S35>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/For Each Subsystem/Rotor_Dynamics/3x3 Cross Product1'
 * '<S36>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/For Each Subsystem/Rotor_Dynamics/3x3 Cross Product/Subsystem'
 * '<S37>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/For Each Subsystem/Rotor_Dynamics/3x3 Cross Product/Subsystem1'
 * '<S38>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/For Each Subsystem/Rotor_Dynamics/3x3 Cross Product1/Subsystem'
 * '<S39>'  : 'nonlinearAirframe/Nonlinear/AC model/Motor Forces and Torques/For Each Subsystem/Rotor_Dynamics/3x3 Cross Product1/Subsystem1'
 * '<S40>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA'
 * '<S41>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap'
 * '<S42>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap1'
 * '<S43>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LongLat_offset'
 * '<S44>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/pos_deg'
 * '<S45>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90'
 * '<S46>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap/Wrap Longitude'
 * '<S47>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant'
 * '<S48>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180'
 * '<S49>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S50>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant'
 * '<S51>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90'
 * '<S52>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap1/Wrap Longitude'
 * '<S53>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant'
 * '<S54>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180'
 * '<S55>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant'
 * '<S56>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant'
 * '<S57>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LongLat_offset/Angle Conversion2'
 * '<S58>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LongLat_offset/Find Radian//Distance'
 * '<S59>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Angle Conversion2'
 * '<S60>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom'
 * '<S61>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e'
 * '<S62>'  : 'nonlinearAirframe/Nonlinear/Position on Earth/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4'
 */
#endif                                 /* RTW_HEADER_nonlinearAirframe_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
