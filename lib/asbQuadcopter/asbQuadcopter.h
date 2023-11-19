/*
 * File: asbQuadcopter.h
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

#ifndef RTW_HEADER_asbQuadcopter_h_
#define RTW_HEADER_asbQuadcopter_h_
#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#ifndef asbQuadcopter_COMMON_INCLUDES_
# define asbQuadcopter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* asbQuadcopter_COMMON_INCLUDES_ */

/* Child system includes */
#define flightControlSystem_MDLREF_HIDE_CHILD_
// #include "flightControlSystem.h"
#include "nonlinearAirframe.h"
#include "rt_assert.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_asbQuadcopter_T RT_MODEL_asbQuadcopter_T;

#ifndef DEFINED_TYPEDEF_FOR_AtmosphereBus_
#define DEFINED_TYPEDEF_FOR_AtmosphereBus_

typedef struct {
  real_T air_temp;
  real_T speed_sound;
  real_T pressure;
  real_T air_density;
} _AtmosphereBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_EnvironmentBus_
#define DEFINED_TYPEDEF_FOR_EnvironmentBus_

typedef struct {
  real_T Gravity_ned[3];
  _AtmosphereBus AtmosphereBus;
  real_T MagneticField_ned[3];
} EnvironmentBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_StatesBus_
#define DEFINED_TYPEDEF_FOR_StatesBus_

typedef struct {
  real_T V_body[3];
  real_T Omega_body[3];
  real_T Euler[3];
  real_T Accel_body[3];
  real_T dOmega_body[3];
  real_T V_ned[3];
  real_T X_ned[3];

  /* Latitude, Longitude, Altitude */
  real_T LLA[3];
  real_T DCM_be[9];
} StatesBus;

#endif

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

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  // MdlrefDW_nonlinearAirframe_T NonlinearAirframe_InstanceData;/* '<S1>/Nonlinear Airframe' */
  HAL_acquisition_t HAL_acquisition_t_g;/* '<S20>/Bus Creator4' */
  HAL_list_echo_t HAL_list_echo;       /* '<S31>/Bus Creator7' */
  HAL_list_echo_t HAL_list_echo_o;     /* '<S32>/Bus Creator7' */
  StatesBus NonlinearAirframe;         /* '<S1>/Nonlinear Airframe' */
  StatesBus Memory_PreviousInput;      /* '<S16>/Memory' */
  EnvironmentBus BusCreator;           /* '<S15>/Bus Creator' */
  HAL_fifo_gyro_SI_t VectorConcatenate[5];/* '<S22>/Vector Concatenate' */
  HAL_fifo_gyro_SI_t VectorConcatenate_a[5];/* '<S23>/Vector Concatenate' */
  HAL_fifo_gyro_SI_t VectorConcatenate_g[5];/* '<S24>/Vector Concatenate' */
  HAL_fifo_gyro_SI_t VectorConcatenate_c[5];/* '<S25>/Vector Concatenate' */
  real_T VisualizationGain[4];         /* '<S48>/Visualization Gain' */
  real_T RateTransition2_Buffer[4];    /* '<S48>/Rate Transition2' */
  real_T RateTransition_Buffer[4];     /* '<S43>/Rate Transition' */
  real_T RateTransition1_Buffer[3];    /* '<S43>/Rate Transition1' */
  real_T RateTransition2_Buffer_h[3];  /* '<S43>/Rate Transition2' */
  real_T RateTransition3_Buffer[3];    /* '<S43>/Rate Transition3' */
  real32_T XYZ[3];                     /* '<S12>/fromWS_Signal 1' */
  real32_T Bias1[3];                   /* '<S19>/Bias1' */
  real32_T Bias2[3];                   /* '<S19>/Bias2' */
  real32_T altitude_sonar;             /* '<S19>/Saturation' */
  real32_T Assumestakeoffwaslevel1;    /* '<S19>/Assumes takeoff was level1' */
  struct {
    int_T PrevIndex;
  } FromWorkspace_IWORK;               /* '<S12>/From Workspace' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S12>/fromWS_Signal 1' */

  uint32_T Output;                     /* '<S11>/Output' */
  uint32_T Output_DSTATE;              /* '<S11>/Output' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWorkspace_PWORK;               /* '<S12>/From Workspace' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S12>/fromWS_Signal 1' */

  void *VRSink_PWORK[19];              /* '<S43>/VR Sink' */
  void* Assertion_slioAccessor;        /* '<S40>/Assertion' */
  void* Flaghasbeentriggered_slioAccessor;/* '<S5>/Flag has been triggered' */
  boolean_T takeoff_flag;              /* '<S7>/Rate Transition3' */
} DW_asbQuadcopter_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S48>/Integrator' */
  // X_nonlinearAirframe_n_T NonlinearAirframe_CSTATE;/* '<S1>/Nonlinear Airframe' */
} X_asbQuadcopter_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_asbQuadcopter_T[7];
typedef real_T PeriodicRngX_asbQuadcopter_T[14];

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[4];         /* '<S48>/Integrator' */
  // XDot_nonlinearAirframe_n_T NonlinearAirframe_CSTATE;/* '<S1>/Nonlinear Airframe' */
} XDot_asbQuadcopter_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[4];      /* '<S48>/Integrator' */
  // XDis_nonlinearAirframe_n_T NonlinearAirframe_CSTATE;/* '<S1>/Nonlinear Airframe' */
} XDis_asbQuadcopter_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: States
   * Referenced by: '<S16>/Memory'
   */
  StatesBus Memory_InitialCondition;
} ConstP_asbQuadcopter_T;

/* Real-time Model Data Structure */
struct tag_RTM_asbQuadcopter_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_asbQuadcopter_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[16];
  real_T odeF[3][16];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint32_T TID[3];
    } TaskCounters;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Continuous states (default storage) */
extern X_asbQuadcopter_T asbQuadcopter_X;

/* Block signals and states (default storage) */
extern DW_asbQuadcopter_T asbQuadcopter_DW;

/* Constant parameters (default storage) */
extern const ConstP_asbQuadcopter_T asbQuadcopter_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern SensorsBus sensor_inport;       /* '<S16>/Bus Creator1' */
extern CommandBus cmd_inport;          /* '<S7>/Bus Creator' */
extern real32_T motors_outport[4];     /* '<Root>/FCS' */
extern uint8_T flag_outport;           /* '<Root>/FCS' */

/* Model entry point functions */
extern void asbQuadcopter_initialize(void);
extern void asbQuadcopter_step(void);

/* Real-time Model object */
extern RT_MODEL_asbQuadcopter_T *const asbQuadcopter_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/FixPt Data Type Propagation' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S38>/Unit Conversion' : Unused code path elimination
 * Block '<S36>/Deg from North' : Unused code path elimination
 * Block '<S36>/Display' : Unused code path elimination
 * Block '<S36>/Display1' : Unused code path elimination
 * Block '<S36>/Display2' : Unused code path elimination
 * Block '<S36>/Display3' : Unused code path elimination
 * Block '<S36>/Display4' : Unused code path elimination
 * Block '<S36>/Display5' : Unused code path elimination
 * Block '<S36>/Display6' : Unused code path elimination
 * Block '<S36>/Display7' : Unused code path elimination
 * Block '<S36>/Display8' : Unused code path elimination
 * Block '<S39>/Unit Conversion' : Unused code path elimination
 * Block '<S36>/Gain' : Unused code path elimination
 * Block '<S36>/Gain1' : Unused code path elimination
 * Block '<S36>/Math Function' : Unused code path elimination
 * Block '<S36>/Sqrt' : Unused code path elimination
 * Block '<S36>/Sum of Elements' : Unused code path elimination
 * Block '<S41>/Unit Conversion' : Unused code path elimination
 * Block '<S42>/Unit Conversion' : Unused code path elimination
 * Block '<S18>/Reshape' : Reshape block reduction
 * Block '<S18>/VelocityToOpticalFlow_Gain' : Eliminated nontunable gain of 1
 * Block '<S19>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S17>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<S17>/Rate Transition2' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'asbQuadcopter'
 * '<S1>'   : 'asbQuadcopter/Airframe'
 * '<S2>'   : 'asbQuadcopter/Command'
 * '<S3>'   : 'asbQuadcopter/Environment'
 * '<S4>'   : 'asbQuadcopter/Sensors'
 * '<S5>'   : 'asbQuadcopter/Stop Simulation'
 * '<S6>'   : 'asbQuadcopter/Visualization'
 * '<S7>'   : 'asbQuadcopter/Command/Signal Editor'
 * '<S8>'   : 'asbQuadcopter/Command/Signal Editor/Compare To Constant'
 * '<S9>'   : 'asbQuadcopter/Command/Signal Editor/Compare To Zero'
 * '<S10>'  : 'asbQuadcopter/Command/Signal Editor/Compare To Zero1'
 * '<S11>'  : 'asbQuadcopter/Command/Signal Editor/Live Time  Ticks'
 * '<S12>'  : 'asbQuadcopter/Command/Signal Editor/Position//Attitude Reference'
 * '<S13>'  : 'asbQuadcopter/Command/Signal Editor/Live Time  Ticks/Increment Real World'
 * '<S14>'  : 'asbQuadcopter/Command/Signal Editor/Live Time  Ticks/Wrap To Zero'
 * '<S15>'  : 'asbQuadcopter/Environment/Environment (Constant)'
 * '<S16>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)'
 * '<S17>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System'
 * '<S18>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/Camera'
 * '<S19>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure'
 * '<S20>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator'
 * '<S21>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_acc_SI_creator'
 * '<S22>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_fifo_gyro_SI_t_creator'
 * '<S23>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_fifo_gyro_SI_t_creator1'
 * '<S24>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_fifo_gyro_SI_t_creator2'
 * '<S25>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_fifo_gyro_SI_t_creator3'
 * '<S26>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_gyro_SI_creator'
 * '<S27>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_magn_mG_t_creator1'
 * '<S28>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_pressure_SI_creator'
 * '<S29>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_ultrasound_SI_creator'
 * '<S30>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_vbat_SI_creator'
 * '<S31>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_ultrasound_SI_creator/HAL_list_echo_t_creator'
 * '<S32>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_ultrasound_SI_creator/HAL_list_echo_t_creator1'
 * '<S33>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_ultrasound_SI_creator/HAL_list_echo_t_creator/HAL_echo_t_creator'
 * '<S34>'  : 'asbQuadcopter/Sensors/Sensors (Feedthrough)/Sensor System/IMU_Pressure/HAL_acquisition_creator/HAL_ultrasound_SI_creator/HAL_list_echo_t_creator1/HAL_echo_t_creator'
 * '<S35>'  : 'asbQuadcopter/Stop Simulation/Compare To Zero'
 * '<S36>'  : 'asbQuadcopter/Visualization/Extract Flight Instruments'
 * '<S37>'  : 'asbQuadcopter/Visualization/Visualization'
 * '<S38>'  : 'asbQuadcopter/Visualization/Extract Flight Instruments/Altitude [ft]'
 * '<S39>'  : 'asbQuadcopter/Visualization/Extract Flight Instruments/Euler [deg]'
 * '<S40>'  : 'asbQuadcopter/Visualization/Extract Flight Instruments/Floor contact'
 * '<S41>'  : 'asbQuadcopter/Visualization/Extract Flight Instruments/V'
 * '<S42>'  : 'asbQuadcopter/Visualization/Extract Flight Instruments/Vd [ft//min]'
 * '<S43>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D'
 * '<S44>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Axes to VR Axes'
 * '<S45>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Axes to VR Axes Camera Chase'
 * '<S46>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Axes to VR Axes Camera Iso'
 * '<S47>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR'
 * '<S48>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Subsystem'
 * '<S49>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Axis Angle Vector'
 * '<S50>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Pitch & Yaw)'
 * '<S51>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Roll)'
 * '<S52>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Normalization'
 * '<S53>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Normalization1'
 * '<S54>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Normalization2'
 * '<S55>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Pitch & Yaw)/q0'
 * '<S56>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Pitch & Yaw)/q1'
 * '<S57>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Pitch & Yaw)/q2'
 * '<S58>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Pitch & Yaw)/q3'
 * '<S59>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Roll)/q0'
 * '<S60>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Roll)/q1'
 * '<S61>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Roll)/q2'
 * '<S62>'  : 'asbQuadcopter/Visualization/Visualization/Simulink 3D/Euler to VR/Quaternion Multiplication (Roll)/q3'
 */
#endif                                 /* RTW_HEADER_asbQuadcopter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
