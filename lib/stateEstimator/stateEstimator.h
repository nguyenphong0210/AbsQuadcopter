/*
 * File: stateEstimator.h
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

#ifndef RTW_HEADER_stateEstimator_h_
#define RTW_HEADER_stateEstimator_h_
#include "rtwtypes.h"
#include <math.h>
#ifndef stateEstimator_COMMON_INCLUDES_
# define stateEstimator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* stateEstimator_COMMON_INCLUDES_ */

#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Forward declaration for rtModel */
typedef struct tag_RTM_stateEstimator_T RT_MODEL_stateEstimator_T;

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

/* Block signals and states (default storage) for system '<S113>/MeasurementUpdate' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T MeasurementUpdate_MODE;    /* '<S113>/MeasurementUpdate' */
} DW_MeasurementUpdate_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for system '<S120>/Enabled Subsystem' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S120>/Enabled Subsystem' */
} DW_EnabledSubsystem_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'stateEstimator' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  DW_EnabledSubsystem_stateEstimator_T EnabledSubsystem_m;/* '<S174>/Enabled Subsystem' */
  DW_MeasurementUpdate_stateEstimator_T MeasurementUpdate_b;/* '<S167>/MeasurementUpdate' */
  DW_EnabledSubsystem_stateEstimator_T EnabledSubsystem_f;/* '<S120>/Enabled Subsystem' */
  DW_MeasurementUpdate_stateEstimator_T MeasurementUpdate_e;/* '<S113>/MeasurementUpdate' */
  real_T Product2[2];                  /* '<S66>/Product2' */
  real_T Product3[2];                  /* '<S64>/Product3' */
  real_T MemoryX_DSTATE[2];            /* '<S14>/MemoryX' */
  real_T soonarFilter_IIR_states[3];   /* '<S15>/soonarFilter_IIR' */
  real_T Delay2_DSTATE;                /* '<S3>/Delay2' */
  real_T soonarFilter_IIR_tmp;         /* '<S15>/soonarFilter_IIR' */
  real32_T Merge[2];                   /* '<S2>/Merge' */
  real32_T Product2_e[2];              /* '<S198>/Product2' */
  real32_T Product3_j[2];              /* '<S196>/Product3' */
  real32_T Product2_k[2];              /* '<S144>/Product2' */
  real32_T Product3_m[2];              /* '<S142>/Product3' */
  real32_T FIR_IMUaccel_states[15];    /* '<S5>/FIR_IMUaccel' */
  real32_T IIR_IMUgyro_r_states[5];    /* '<S5>/IIR_IMUgyro_r' */
  real32_T MemoryX_DSTATE_d[2];        /* '<S76>/MemoryX' */
  real32_T IIRgyroz_states[10];        /* '<S75>/IIRgyroz' */
  real32_T UD_DSTATE[2];               /* '<S82>/UD' */
  real32_T Delay_DSTATE[2];            /* '<S72>/Delay' */
  real32_T pressureFilter_IIR_states[3];/* '<S15>/pressureFilter_IIR' */
  real32_T Delay1_DSTATE[2];           /* '<S1>/Delay1' */
  real32_T MemoryX_DSTATE_dl[2];       /* '<S145>/MemoryX' */
  real32_T Delay_DSTATE_l[2];          /* '<S73>/Delay' */
  real32_T SimplyIntegrateVelocity_DSTATE[2];/* '<S73>/SimplyIntegrateVelocity' */
  real32_T Memory_PreviousInput[3];    /* '<S2>/Memory' */
  real32_T IIRgyroz_tmp[2];            /* '<S75>/IIRgyroz' */
  real32_T IIR_IMUgyro_r_tmp;          /* '<S5>/IIR_IMUgyro_r' */
  real32_T pressureFilter_IIR_tmp;     /* '<S15>/pressureFilter_IIR' */
  int32_T FIR_IMUaccel_circBuf;        /* '<S5>/FIR_IMUaccel' */
  int8_T SimplyIntegrateVelocity_PrevResetState;/* '<S73>/SimplyIntegrateVelocity' */
  uint8_T icLoad;                      /* '<S76>/MemoryX' */
  uint8_T icLoad_p;                    /* '<S14>/MemoryX' */
  uint8_T icLoad_g;                    /* '<S145>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S42>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S36>/MeasurementUpdate' */
} DW_stateEstimator_f_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'stateEstimator' */
#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  const real32_T Conversion[4];        /* '<S136>/Conversion' */
  const real32_T Conversion_p[4];      /* '<S137>/Conversion' */
  const real32_T Conversion_a[4];      /* '<S190>/Conversion' */
  const real32_T Conversion_g[4];      /* '<S191>/Conversion' */
} ConstB_stateEstimator_h_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_stateEstimator_T {
  const char_T **errorStatus;
};

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_stateEstimator_T rtm;
} MdlrefDW_stateEstimator_T;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

extern const ConstB_stateEstimator_h_T stateEstimator_ConstB;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

extern void stateEstimator_Init(void);
extern void stateEstimator_Disable(void);
extern void stateEstimator_run(const boolean_T arg_controlModePosVSOrient_flagin,
  const sensordata_t *arg_sensordata_datin, const real32_T arg_usePosVIS_flagin,
  const real32_T arg_opticalFlow_datin[3], const real32_T arg_posVIS_datin[4],
  statesEstim_t *arg_states_estimout, const real32_T
  arg_sensorCalibration_datin[8]);

/* Model reference registration function */
extern void stateEstimator_o_initialize(const char_T **rt_errorStatus);

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

extern void stateEstimator_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[2],
  DW_MeasurementUpdate_stateEstimator_T *localDW);
extern void stateEstimator_MeasurementUpdate(boolean_T rtu_Enable, const
  real32_T rtu_Lk[4], const real32_T rtu_yk[2], const real32_T rtu_Ck[4], const
  real32_T rtu_xhatkk1[2], const real32_T rtu_Dk[4], const real32_T rtu_uk[2],
  real32_T rty_Lykyhatkk1[2], DW_MeasurementUpdate_stateEstimator_T *localDW);
extern void stateEstimator_EnabledSubsystem_Disable(real32_T rty_deltax[2],
  DW_EnabledSubsystem_stateEstimator_T *localDW);
extern void stateEstimator_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
  rtu_Mk[4], const real32_T rtu_Ck[4], const real32_T rtu_yk[2], const real32_T
  rtu_xhatkk1[2], real32_T rty_deltax[2], DW_EnabledSubsystem_stateEstimator_T
  *localDW);

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

extern MdlrefDW_stateEstimator_T stateEstimator_MdlrefDW;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

#ifndef stateEstimator_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern DW_stateEstimator_f_T stateEstimator_DW;

#endif                                 /*stateEstimator_MDLREF_HIDE_CHILD_*/

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S18>/CovarianceZ' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Conversion' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S61>/Conversion' : Unused code path elimination
 * Block '<S61>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Conversion' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/G' : Unused code path elimination
 * Block '<S14>/H' : Unused code path elimination
 * Block '<S14>/N' : Unused code path elimination
 * Block '<S14>/P0' : Unused code path elimination
 * Block '<S14>/Q' : Unused code path elimination
 * Block '<S14>/R' : Unused code path elimination
 * Block '<S47>/CheckSignalProperties' : Unused code path elimination
 * Block '<S54>/CheckSignalProperties' : Unused code path elimination
 * Block '<S56>/CheckSignalProperties' : Unused code path elimination
 * Block '<S57>/CheckSignalProperties' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/CovarianceZ' : Unused code path elimination
 * Block '<S136>/Data Type Duplicate' : Unused code path elimination
 * Block '<S137>/Data Type Duplicate' : Unused code path elimination
 * Block '<S138>/Conversion' : Unused code path elimination
 * Block '<S138>/Data Type Duplicate' : Unused code path elimination
 * Block '<S139>/Conversion' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S97>/Data Type Duplicate' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S102>/Data Type Duplicate' : Unused code path elimination
 * Block '<S103>/Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/Conversion' : Unused code path elimination
 * Block '<S104>/Data Type Duplicate' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S106>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/Data Type Duplicate' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S110>/Data Type Duplicate' : Unused code path elimination
 * Block '<S76>/G' : Unused code path elimination
 * Block '<S76>/H' : Unused code path elimination
 * Block '<S76>/N' : Unused code path elimination
 * Block '<S76>/P0' : Unused code path elimination
 * Block '<S76>/Q' : Unused code path elimination
 * Block '<S76>/R' : Unused code path elimination
 * Block '<S125>/CheckSignalProperties' : Unused code path elimination
 * Block '<S134>/CheckSignalProperties' : Unused code path elimination
 * Block '<S135>/CheckSignalProperties' : Unused code path elimination
 * Block '<S148>/CovarianceZ' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Conversion' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Conversion' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S151>/Data Type Duplicate' : Unused code path elimination
 * Block '<S152>/Data Type Duplicate' : Unused code path elimination
 * Block '<S153>/Data Type Duplicate' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate' : Unused code path elimination
 * Block '<S155>/Data Type Duplicate' : Unused code path elimination
 * Block '<S156>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Conversion' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S159>/Data Type Duplicate' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S163>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S145>/G' : Unused code path elimination
 * Block '<S145>/H' : Unused code path elimination
 * Block '<S145>/N' : Unused code path elimination
 * Block '<S145>/P0' : Unused code path elimination
 * Block '<S145>/Q' : Unused code path elimination
 * Block '<S145>/R' : Unused code path elimination
 * Block '<S179>/CheckSignalProperties' : Unused code path elimination
 * Block '<S188>/CheckSignalProperties' : Unused code path elimination
 * Block '<S189>/CheckSignalProperties' : Unused code path elimination
 * Block '<S2>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S13>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S58>/Conversion' : Eliminate redundant data type conversion
 * Block '<S59>/Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S14>/DataTypeConversionReset' : Eliminate redundant data type conversion
 * Block '<S32>/Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Reshape' : Reshape block reduction
 * Block '<S14>/ReshapeX0' : Reshape block reduction
 * Block '<S14>/Reshapeu' : Reshape block reduction
 * Block '<S14>/Reshapexhat' : Reshape block reduction
 * Block '<S14>/Reshapey' : Reshape block reduction
 * Block '<S71>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S81>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S76>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S109>/Conversion' : Eliminate redundant data type conversion
 * Block '<S113>/Reshape' : Reshape block reduction
 * Block '<S76>/ReshapeX0' : Reshape block reduction
 * Block '<S76>/Reshapeu' : Reshape block reduction
 * Block '<S76>/Reshapexhat' : Reshape block reduction
 * Block '<S76>/Reshapey' : Reshape block reduction
 * Block '<S72>/opticalFlowToVelocity_gain' : Eliminated nontunable gain of 1
 * Block '<S145>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S163>/Conversion' : Eliminate redundant data type conversion
 * Block '<S167>/Reshape' : Reshape block reduction
 * Block '<S145>/ReshapeX0' : Reshape block reduction
 * Block '<S145>/Reshapeu' : Reshape block reduction
 * Block '<S145>/Reshapexhat' : Reshape block reduction
 * Block '<S145>/Reshapey' : Reshape block reduction
 * Block '<S203>/Reshape (9) to [3x3] column-major' : Reshape block reduction
 * Block '<S5>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'stateEstimator'
 * '<S1>'   : 'stateEstimator/State Estimator'
 * '<S2>'   : 'stateEstimator/State Estimator/Complementary Filter'
 * '<S3>'   : 'stateEstimator/State Estimator/EstimatorAltitude'
 * '<S4>'   : 'stateEstimator/State Estimator/EstimatorXYPosition'
 * '<S5>'   : 'stateEstimator/State Estimator/SensorPreprocessing'
 * '<S6>'   : 'stateEstimator/State Estimator/Complementary Filter/Compare To Constant'
 * '<S7>'   : 'stateEstimator/State Estimator/Complementary Filter/Compare To Constant1'
 * '<S8>'   : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem'
 * '<S9>'   : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem1'
 * '<S10>'  : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem2'
 * '<S11>'  : 'stateEstimator/State Estimator/Complementary Filter/If Action Subsystem3'
 * '<S12>'  : 'stateEstimator/State Estimator/Complementary Filter/Wbe'
 * '<S13>'  : 'stateEstimator/State Estimator/Complementary Filter/Wbe/Create 3x3 Matrix'
 * '<S14>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude'
 * '<S15>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling'
 * '<S16>'  : 'stateEstimator/State Estimator/EstimatorAltitude/Rotation Angles to Direction Cosine Matrix'
 * '<S17>'  : 'stateEstimator/State Estimator/EstimatorAltitude/outlierBelowFloor'
 * '<S18>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL'
 * '<S19>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculateYhat'
 * '<S20>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CovarianceOutputConfigurator'
 * '<S21>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionA'
 * '<S22>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionB'
 * '<S23>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionC'
 * '<S24>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionD'
 * '<S25>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionG'
 * '<S26>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionH'
 * '<S27>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionN'
 * '<S28>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionP'
 * '<S29>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionP0'
 * '<S30>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionQ'
 * '<S31>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionR'
 * '<S32>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionX'
 * '<S33>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionX0'
 * '<S34>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/DataTypeConversionu'
 * '<S35>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/MemoryP'
 * '<S36>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Observer'
 * '<S37>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ReducedQRN'
 * '<S38>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Reshapeyhat'
 * '<S39>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionP0'
 * '<S40>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionQ'
 * '<S41>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ScalarExpansionR'
 * '<S42>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/UseCurrentEstimator'
 * '<S43>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkA'
 * '<S44>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkB'
 * '<S45>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkC'
 * '<S46>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkD'
 * '<S47>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkEnable'
 * '<S48>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkG'
 * '<S49>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkH'
 * '<S50>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkN'
 * '<S51>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkP0'
 * '<S52>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkQ'
 * '<S53>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkR'
 * '<S54>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkReset'
 * '<S55>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checkX0'
 * '<S56>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checku'
 * '<S57>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/checky'
 * '<S58>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionL'
 * '<S59>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionM'
 * '<S60>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionP'
 * '<S61>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/DataTypeConversionZ'
 * '<S62>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculatePL/Ground'
 * '<S63>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/CalculateYhat/Ground'
 * '<S64>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/Observer/MeasurementUpdate'
 * '<S65>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/ReducedQRN/Ground'
 * '<S66>'  : 'stateEstimator/State Estimator/EstimatorAltitude/KalmanFilter_altitude/UseCurrentEstimator/Enabled Subsystem'
 * '<S67>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling/check for min altitude'
 * '<S68>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling/currentEstimateVeryOffFromPressure'
 * '<S69>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling/currentStateVeryOffsonarflt'
 * '<S70>'  : 'stateEstimator/State Estimator/EstimatorAltitude/OutlierHandling/outlierJump'
 * '<S71>'  : 'stateEstimator/State Estimator/EstimatorAltitude/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S72>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity'
 * '<S73>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition'
 * '<S74>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling'
 * '<S75>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling'
 * '<S76>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy'
 * '<S77>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Deactivate Acceleration If OF is not used due to low altitude'
 * '<S78>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix'
 * '<S79>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)'
 * '<S80>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/do not use acc if optical flow never available (Note OF@60Hz but ZOH to 200!)1'
 * '<S81>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/AccelerationHandling/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S82>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/DiscreteDerivative'
 * '<S83>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxdw1'
 * '<S84>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxdw2'
 * '<S85>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxp'
 * '<S86>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxp2'
 * '<S87>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxq'
 * '<S88>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxq2'
 * '<S89>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw1'
 * '<S90>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw2'
 * '<S91>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw3'
 * '<S92>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/maxw4'
 * '<S93>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/DataHandling/minHeightforOF'
 * '<S94>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL'
 * '<S95>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculateYhat'
 * '<S96>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CovarianceOutputConfigurator'
 * '<S97>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionA'
 * '<S98>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionB'
 * '<S99>'  : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionC'
 * '<S100>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionD'
 * '<S101>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionG'
 * '<S102>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionH'
 * '<S103>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionN'
 * '<S104>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP'
 * '<S105>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionP0'
 * '<S106>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionQ'
 * '<S107>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionR'
 * '<S108>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionReset'
 * '<S109>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX'
 * '<S110>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionX0'
 * '<S111>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/DataTypeConversionu'
 * '<S112>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/MemoryP'
 * '<S113>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/Observer'
 * '<S114>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ReducedQRN'
 * '<S115>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/Reset'
 * '<S116>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/Reshapeyhat'
 * '<S117>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionP0'
 * '<S118>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionQ'
 * '<S119>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ScalarExpansionR'
 * '<S120>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator'
 * '<S121>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkA'
 * '<S122>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkB'
 * '<S123>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkC'
 * '<S124>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkD'
 * '<S125>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkEnable'
 * '<S126>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkG'
 * '<S127>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkH'
 * '<S128>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkN'
 * '<S129>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkP0'
 * '<S130>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkQ'
 * '<S131>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkR'
 * '<S132>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkReset'
 * '<S133>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checkX0'
 * '<S134>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checku'
 * '<S135>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/checky'
 * '<S136>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionL'
 * '<S137>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionM'
 * '<S138>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionP'
 * '<S139>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/DataTypeConversionZ'
 * '<S140>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculatePL/Ground'
 * '<S141>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/CalculateYhat/Ground'
 * '<S142>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/Observer/MeasurementUpdate'
 * '<S143>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/ReducedQRN/Ground'
 * '<S144>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorVelocity/KalmanFilter_dxdy/UseCurrentEstimator/Enabled Subsystem'
 * '<S145>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy'
 * '<S146>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling'
 * '<S147>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix'
 * '<S148>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL'
 * '<S149>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculateYhat'
 * '<S150>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CovarianceOutputConfigurator'
 * '<S151>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionA'
 * '<S152>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionB'
 * '<S153>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionC'
 * '<S154>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionD'
 * '<S155>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionG'
 * '<S156>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionH'
 * '<S157>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionN'
 * '<S158>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionP'
 * '<S159>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionP0'
 * '<S160>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionQ'
 * '<S161>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionR'
 * '<S162>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionReset'
 * '<S163>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionX'
 * '<S164>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionX0'
 * '<S165>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/DataTypeConversionu'
 * '<S166>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/MemoryP'
 * '<S167>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/Observer'
 * '<S168>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ReducedQRN'
 * '<S169>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/Reset'
 * '<S170>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/Reshapeyhat'
 * '<S171>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ScalarExpansionP0'
 * '<S172>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ScalarExpansionQ'
 * '<S173>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ScalarExpansionR'
 * '<S174>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/UseCurrentEstimator'
 * '<S175>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkA'
 * '<S176>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkB'
 * '<S177>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkC'
 * '<S178>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkD'
 * '<S179>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkEnable'
 * '<S180>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkG'
 * '<S181>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkH'
 * '<S182>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkN'
 * '<S183>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkP0'
 * '<S184>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkQ'
 * '<S185>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkR'
 * '<S186>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkReset'
 * '<S187>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checkX0'
 * '<S188>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checku'
 * '<S189>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/checky'
 * '<S190>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/DataTypeConversionL'
 * '<S191>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/DataTypeConversionM'
 * '<S192>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/DataTypeConversionP'
 * '<S193>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/DataTypeConversionZ'
 * '<S194>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculatePL/Ground'
 * '<S195>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/CalculateYhat/Ground'
 * '<S196>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/Observer/MeasurementUpdate'
 * '<S197>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/ReducedQRN/Ground'
 * '<S198>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/KalmanFilter_posxy/UseCurrentEstimator/Enabled Subsystem'
 * '<S199>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling/checkifPosavailable'
 * '<S200>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling/maxp3'
 * '<S201>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling/maxq3'
 * '<S202>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/OutlierHandling/planarjumpsVISPOS'
 * '<S203>' : 'stateEstimator/State Estimator/EstimatorXYPosition/EstimatorXYPosition/Rotation Angles to Direction Cosine Matrix/Create 3x3 Matrix'
 * '<S204>' : 'stateEstimator/State Estimator/SensorPreprocessing/Check if valid visual position estimate available'
 */
#endif                                 /* RTW_HEADER_stateEstimator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
