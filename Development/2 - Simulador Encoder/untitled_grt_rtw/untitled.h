/*
 * untitled.h
 *
 * Code generation for model "untitled".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Tue Aug 19 16:59:05 2014
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_untitled_h_
#define RTW_HEADER_untitled_h_
#ifndef untitled_COMMON_INCLUDES_
# define untitled_COMMON_INCLUDES_
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include "untitled_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
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

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SineWave2;                    /* '<Root>/Sine Wave2' */
} BlockIO_untitled;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DelayInput1_DSTATE;           /* '<S6>/Delay Input1' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */
} D_Work_untitled;

/* Parameters (auto storage) */
struct Parameters_untitled_ {
  real_T SineWave2_Amp;                /* Expression: 360
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Grauspulso_Gain;              /* Expression: 360/(2*Nr)
                                        * Referenced by: '<S1>/Graus // pulso'
                                        */
  real_T Constant_Value;               /* Expression: 2*Nr
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T DelayInput1_InitialCondition; /* Expression: vinit
                                        * Referenced by: '<S6>/Delay Input1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_untitled untitled_P;

/* Block signals (auto storage) */
extern BlockIO_untitled untitled_B;

/* Block states (auto storage) */
extern D_Work_untitled untitled_DWork;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled *const untitled_M;

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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Encoder'
 * '<S2>'   : 'untitled/Encoder/Contador'
 * '<S3>'   : 'untitled/Encoder/Determinar direçao'
 * '<S4>'   : 'untitled/Encoder/Sensor Óptico'
 * '<S5>'   : 'untitled/Encoder/Sensor Óptico1'
 * '<S6>'   : 'untitled/Encoder/Contador/Detect Change'
 */
#endif                                 /* RTW_HEADER_untitled_h_ */
