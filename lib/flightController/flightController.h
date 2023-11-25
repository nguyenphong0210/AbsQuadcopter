/*
 * File: flightController.h
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

#ifndef RTW_HEADER_flightController_h_
#define RTW_HEADER_flightController_h_
#include "rtwtypes.h"
#include <math.h>
#ifndef flightController_COMMON_INCLUDES_
# define flightController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* flightController_COMMON_INCLUDES_ */

/* Forward declaration for rtModel */
typedef struct tag_RTM_flightController_T RT_MODEL_flightController_T;

#ifndef DEFINED_TYPEDEF_FOR_CommandBus_
#define DEFINED_TYPEDEF_FOR_CommandBus_

typedef struct {
  boolean_T controlModePosVSOrient;
  real32_T pos_ref[3];
  boolean_T takeoff_flag;
  real32_T orient_ref[3];
  uint32_T live_time_ticks;
} CommandBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_statesEstim_t_
#define DEFINED_TYPEDEF_FOR_statesEstim_t_

typedef struct {
  real32_T X;
  real32_T Y;
  real32_T Z;
  real32_T yaw;
  real32_T pitch;
  real32_T roll;
  real32_T dx;
  real32_T dy;
  real32_T dz;
  real32_T p;
  real32_T q;
  real32_T r;
} statesEstim_t;

#endif

/* Block signals and states (default storage) for model 'flightController' */
#ifndef flightController_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S2>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE[2];            /* '<S2>/Delay' */
} DW_flightController_f_T;

#endif                                 /*flightController_MDLREF_HIDE_CHILD_*/

#ifndef flightController_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_flightController_T {
  const char_T **errorStatus;
};

#endif                                 /*flightController_MDLREF_HIDE_CHILD_*/

#ifndef flightController_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_flightController_T rtm;
} MdlrefDW_flightController_T;

#endif                                 /*flightController_MDLREF_HIDE_CHILD_*/

extern void flightController_run(const CommandBus *arg_ReferenceValueServerBus,
  const statesEstim_t *arg_states_estim, real32_T arg_motors_refout[4], real32_T
  arg_pose_refout[8]);

/* Model reference registration function */
extern void flightController_g_initialize(const char_T **rt_errorStatus);

#ifndef flightController_MDLREF_HIDE_CHILD_

extern MdlrefDW_flightController_T flightController_MdlrefDW;

#endif                                 /*flightController_MDLREF_HIDE_CHILD_*/

#ifndef flightController_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_flightController_f_T flightController_DW;

#endif                                 /*flightController_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'flightController'
 * '<S1>'   : 'flightController/Flight Controller'
 * '<S2>'   : 'flightController/Flight Controller/Attitude'
 * '<S3>'   : 'flightController/Flight Controller/ControlMixer'
 * '<S4>'   : 'flightController/Flight Controller/XY-to-reference-orientation'
 * '<S5>'   : 'flightController/Flight Controller/Yaw'
 * '<S6>'   : 'flightController/Flight Controller/gravity feedforward//equilibrium thrust'
 * '<S7>'   : 'flightController/Flight Controller/thrustsToMotorCommands'
 */
#endif                                 /* RTW_HEADER_flightController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
