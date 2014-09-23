/*
 * untitled.c
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
#include "untitled.h"
#include "untitled_private.h"

/* Block signals (auto storage) */
BlockIO_untitled untitled_B;

/* Block states (auto storage) */
D_Work_untitled untitled_DWork;

/* Real-time model */
RT_MODEL_untitled untitled_M_;
RT_MODEL_untitled *const untitled_M = &untitled_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
      y = 0.0;
    } else {
      y = (tmp - floor(tmp)) * u1;
    }
  }

  return y;
}

/* Model step function */
void untitled_step(void)
{
  /* local block i/o variables */
  real_T rtb_MathFunction;
  real_T rtb_Sum;
  real_T rtb_Memory;

  /* Sin: '<Root>/Sine Wave2' */
  untitled_B.SineWave2 = sin(untitled_P.SineWave2_Freq * untitled_M->Timing.t[0]
    + untitled_P.SineWave2_Phase) * untitled_P.SineWave2_Amp +
    untitled_P.SineWave2_Bias;

  /* Memory: '<S2>/Memory' */
  rtb_Memory = untitled_DWork.Memory_PreviousInput;

  /* Gain: '<S1>/Graus // pulso' incorporates:
   *  Memory: '<S2>/Memory'
   */
  rtb_Sum = untitled_P.Grauspulso_Gain * untitled_DWork.Memory_PreviousInput;

  /* Sum: '<S2>/Sum' incorporates:
   *  RelationalOperator: '<S6>/FixPt Relational Operator'
   *  UnitDelay: '<S6>/Delay Input1'
   */
  rtb_Sum = (real_T)(0.0 != untitled_DWork.DelayInput1_DSTATE) + rtb_Memory;

  /* Math: '<S2>/Math Function' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_MathFunction = rt_modd_snf(rtb_Sum, untitled_P.Constant_Value);

  /* Matfile logging */
  rt_UpdateTXYLogVars(untitled_M->rtwLogInfo, (untitled_M->Timing.t));

  /* Update for Memory: '<S2>/Memory' */
  untitled_DWork.Memory_PreviousInput = rtb_MathFunction;

  /* Update for UnitDelay: '<S6>/Delay Input1' */
  untitled_DWork.DelayInput1_DSTATE = 0.0;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(untitled_M)!=-1) &&
        !((rtmGetTFinal(untitled_M)-untitled_M->Timing.t[0]) >
          untitled_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(untitled_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++untitled_M->Timing.clockTick0)) {
    ++untitled_M->Timing.clockTickH0;
  }

  untitled_M->Timing.t[0] = untitled_M->Timing.clockTick0 *
    untitled_M->Timing.stepSize0 + untitled_M->Timing.clockTickH0 *
    untitled_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    untitled_M->Timing.clockTick1++;
    if (!untitled_M->Timing.clockTick1) {
      untitled_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&untitled_M->solverInfo,
                          &untitled_M->Timing.simTimeStep);
    rtsiSetTPtr(&untitled_M->solverInfo, &rtmGetTPtr(untitled_M));
    rtsiSetStepSizePtr(&untitled_M->solverInfo, &untitled_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&untitled_M->solverInfo, (&rtmGetErrorStatus
      (untitled_M)));
    rtsiSetRTModelPtr(&untitled_M->solverInfo, untitled_M);
  }

  rtsiSetSimTimeStep(&untitled_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&untitled_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(untitled_M, &untitled_M->Timing.tArray[0]);
  rtmSetTFinal(untitled_M, 6.0);
  untitled_M->Timing.stepSize0 = 0.0001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    untitled_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(untitled_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(untitled_M->rtwLogInfo, (NULL));
    rtliSetLogT(untitled_M->rtwLogInfo, "tout");
    rtliSetLogX(untitled_M->rtwLogInfo, "");
    rtliSetLogXFinal(untitled_M->rtwLogInfo, "");
    rtliSetSigLog(untitled_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(untitled_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(untitled_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(untitled_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(untitled_M->rtwLogInfo, 1);
    rtliSetLogY(untitled_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(untitled_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(untitled_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(BlockIO_untitled));

  /* states (dwork) */
  (void) memset((void *)&untitled_DWork, 0,
                sizeof(D_Work_untitled));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(untitled_M->rtwLogInfo, 0.0, rtmGetTFinal
    (untitled_M), untitled_M->Timing.stepSize0, (&rtmGetErrorStatus(untitled_M)));

  /* InitializeConditions for Memory: '<S2>/Memory' */
  untitled_DWork.Memory_PreviousInput = untitled_P.Memory_X0;

  /* InitializeConditions for UnitDelay: '<S6>/Delay Input1' */
  untitled_DWork.DelayInput1_DSTATE = untitled_P.DelayInput1_InitialCondition;
}

/* Model terminate function */
void untitled_terminate(void)
{
}
