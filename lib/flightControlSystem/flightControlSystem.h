/*
 * File: flightControlSystem.h
 *
 * Code generated for Simulink model 'flightControlSystem'.
 *
 * Model version                  : 1.138
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Nov 19 00:07:40 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR (32-bit)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_flightControlSystem_h_
#define RTW_HEADER_flightControlSystem_h_
#include "rtwtypes.h"
#include <math.h>
#ifndef flightControlSystem_COMMON_INCLUDES_
# define flightControlSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                /* flightControlSystem_COMMON_INCLUDES_ */

/* Child system includes */
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
#define stateEstimator_MDLREF_HIDE_CHILD_
#include "stateEstimator.h"
#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
#define flightController_MDLREF_HIDE_CHILD_
#include "flightController.h"
#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_flightControlSystem_T RT_MODEL_flightControlSystem_T;

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

#ifndef DEFINED_TYPEDEF_FOR_extraSensorData_t_
#define DEFINED_TYPEDEF_FOR_extraSensorData_t_

typedef struct {
  real32_T opticalFlow_data[3];
  real32_T posVIS_data[4];
  real32_T usePosVIS_flag;
} extraSensorData_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_acc_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_acc_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T temperature;
} HAL_acc_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_gyro_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_gyro_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
  real32_T temperature;
  int32_T temperature_lsb;
} HAL_gyro_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_fifo_gyro_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_fifo_gyro_SI_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
} HAL_fifo_gyro_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_magn_mG_t_
#define DEFINED_TYPEDEF_FOR_HAL_magn_mG_t_

typedef struct {
  real32_T x;
  real32_T y;
  real32_T z;
} HAL_magn_mG_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_pressure_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_pressure_SI_t_

typedef struct {
  real_T temperature;
  real32_T pressure;
} HAL_pressure_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_echo_t_
#define DEFINED_TYPEDEF_FOR_HAL_echo_t_

typedef struct {
  uint16_T begin_echo_index;
  uint16_T end_echo_index;
  int16_T max_value_index;
  int32_T max_value;
  uint16_T precedent;
  int16_T d_echo;
  uint16_T pre_max_index;
} HAL_echo_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_list_echo_t_
#define DEFINED_TYPEDEF_FOR_HAL_list_echo_t_

typedef struct {
  HAL_echo_t tab_echo[30];
  uint8_T number_of_echoes;
} HAL_list_echo_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_ultrasound_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_ultrasound_SI_t_

typedef struct {
  real32_T altitude;
  real32_T raw_altitude;
  uint16_T nb_echo;
  int32_T measure_ref;
  int32_T measure_status;
  uint8_T new_data;
  HAL_list_echo_t HAL_list_echo;
  HAL_list_echo_t HAL_list_echo_p;
} HAL_ultrasound_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_vbat_SI_t_
#define DEFINED_TYPEDEF_FOR_HAL_vbat_SI_t_

typedef struct {
  real32_T vbat_V;
  uint32_T vbat_percentage;
} HAL_vbat_SI_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HAL_acquisition_t_
#define DEFINED_TYPEDEF_FOR_HAL_acquisition_t_

typedef struct {
  int32_T number_HAL_read_call;
  uint32_T timestamp;
  uint16_T status;
  uint8_T used;
  uint8_T count_user;
  HAL_acc_SI_t HAL_acc_SI;
  HAL_gyro_SI_t HAL_gyro_SI;
  uint16_T HAL_fifo_count;
  uint32_T fifo_timestamp;
  HAL_fifo_gyro_SI_t HAL_fifo_gyro_SI_TempCorr[5];
  HAL_fifo_gyro_SI_t HAL_fifo_acce_SI_TempCorr[5];
  HAL_fifo_gyro_SI_t HAL_fifo_gyro_SI[5];
  HAL_fifo_gyro_SI_t HAL_fifo_acce_SI[5];
  real32_T HAL_ref_IMU_temp;
  uint8_T HAL_fifo_fsync[5];
  int32_T HAL_fifo_size;
  HAL_magn_mG_t HAL_magn_mG;
  HAL_pressure_SI_t HAL_pressure_SI;
  HAL_ultrasound_SI_t HAL_ultrasound_SI;
  uint8_T padding[196];
  HAL_vbat_SI_t HAL_vbat_SI;
} HAL_acquisition_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SensorsBus_
#define DEFINED_TYPEDEF_FOR_SensorsBus_

typedef struct {
  extraSensorData_t VisionSensors;
  HAL_acquisition_t HALSensors;
  real32_T SensorCalibration[8];
} SensorsBus;

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

#ifndef DEFINED_TYPEDEF_FOR_sensordata_t_
#define DEFINED_TYPEDEF_FOR_sensordata_t_

typedef struct {
  real32_T ddx;
  real32_T ddy;
  real32_T ddz;
  real32_T p;
  real32_T q;
  real32_T r;
  real32_T altitude_sonar;
  real32_T prs;
  real32_T vbat_V;
  uint32_T vbat_percentage;
} sensordata_t;

#endif

/* Block signals and states (default storage) for system '<Root>/Flight Control System' */
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_

typedef struct {
  statesEstim_t estimator;             /* '<S1>/estimator' */
  statesEstim_t Memory_PreviousInput;  /* '<S4>/Memory' */
} DW_FlightControlSystem_flightControlSystem_T;

#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'flightControlSystem' */
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_

typedef struct {
  DW_FlightControlSystem_flightControlSystem_T FlightControlSystem;/* '<Root>/Flight Control System' */
} DW_flightControlSystem_f_T;

#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

#ifndef flightControlSystem_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_flightControlSystem_T {
  const char_T **errorStatus;
};

#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

#ifndef flightControlSystem_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_flightControlSystem_T rtm;
} MdlrefDW_flightControlSystem_T;

#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern CommandBus cmd_inport;          /* '<Root>/AC cmd' */
extern SensorsBus sensor_inport;       /* '<Root>/Sensors' */
extern real32_T motors_outport[4];     /* '<S1>/controller' */
extern uint8_T flag_outport;           /* '<S2>/Merge' */
extern void flightControlSystem_Init(void);
extern void flightControlSystem_Disable(void);
extern void flightControlSystem(void);

/* Model reference registration function */
extern void flightControlSystem_initialize(const char_T **rt_errorStatus);

#ifndef flightControlSystem_MDLREF_HIDE_CHILD_

extern void flightControlSystem_FlightControlSystem_Init(uint8_T *rty_Flag);
extern void flightControlSystem_FlightControlSystem_Disable(void);
extern void flightControlSystem_FlightControlSystem(const CommandBus
  *rtu_ReferenceValueServerCmds, const SensorsBus *rtu_Sensors, real32_T
  rty_motorCmds[4], uint8_T *rty_Flag,
  DW_FlightControlSystem_flightControlSystem_T *localDW);

#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

#ifndef flightControlSystem_MDLREF_HIDE_CHILD_

extern MdlrefDW_flightControlSystem_T flightControlSystem_MdlrefDW;

#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

#ifndef flightControlSystem_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_flightControlSystem_f_T flightControlSystem_DW;

#endif                                /*flightControlSystem_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Data Type Conversion1' : Unused code path elimination
 * Block '<S3>/Data Type Conversion11' : Unused code path elimination
 * Block '<S3>/Data Type Conversion2' : Unused code path elimination
 * Block '<S3>/Data Type Conversion3' : Unused code path elimination
 * Block '<S3>/Data Type Conversion7' : Unused code path elimination
 * Block '<S3>/Data Type Conversion9' : Unused code path elimination
 * Block '<S3>/To Workspace' : Unused code path elimination
 * Block '<S3>/To Workspace1' : Unused code path elimination
 * Block '<S3>/To Workspace2' : Unused code path elimination
 * Block '<S3>/To Workspace3' : Unused code path elimination
 * Block '<S3>/To Workspace4' : Unused code path elimination
 * Block '<S3>/To Workspace5' : Unused code path elimination
 * Block '<S3>/To Workspace6' : Unused code path elimination
 * Block '<S2>/Gain' : Eliminated nontunable gain of 1
 * Block '<S2>/Gain1' : Eliminated nontunable gain of 1
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
 * '<Root>' : 'flightControlSystem'
 * '<S1>'   : 'flightControlSystem/Flight Control System'
 * '<S2>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags'
 * '<S3>'   : 'flightControlSystem/Flight Control System/Logging'
 * '<S4>'   : 'flightControlSystem/Flight Control System/landing logic'
 * '<S5>'   : 'flightControlSystem/Flight Control System/sensordata_group'
 * '<S6>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant'
 * '<S7>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant1'
 * '<S8>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant2'
 * '<S9>'   : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant3'
 * '<S10>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant4'
 * '<S11>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Compare To Constant5'
 * '<S12>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Geofencing error'
 * '<S13>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/Normal condition'
 * '<S14>'  : 'flightControlSystem/Flight Control System/Crash Predictor Flags/estimator//Optical flow error'
 * '<S15>'  : 'flightControlSystem/Flight Control System/landing logic/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_flightControlSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
