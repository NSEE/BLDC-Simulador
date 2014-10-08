/* Include files */

#include "blascompat32.h"
#include "observador_multirate_sfun.h"
#include "c19_observador_multirate.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "observador_multirate_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c19_debug_family_names[4] = { "nargin", "nargout", "Ts", "D"
};

/* Function Declarations */
static void initialize_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance);
static void initialize_params_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance);
static void enable_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance);
static void disable_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance);
static void set_sim_state_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance, const mxArray
   *c19_st);
static void finalize_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance);
static void sf_c19_observador_multirate(SFc19_observador_multirateInstanceStruct
  *chartInstance);
static void initSimStructsc19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_D, const char_T *c19_identifier);
static real_T c19_b_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_c_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_d_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_b_is_active_c19_observador_multirate, const
  char_T *c19_identifier);
static uint8_T c19_e_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info(SFc19_observador_multirateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance)
{
  chartInstance->c19_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c19_is_active_c19_observador_multirate = 0U;
}

static void initialize_params_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance)
{
}

static void enable_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c19_update_debugger_state_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  real_T c19_hoistedGlobal;
  real_T c19_u;
  const mxArray *c19_b_y = NULL;
  uint8_T c19_b_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  real_T *c19_D;
  c19_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellarray(2), FALSE);
  c19_hoistedGlobal = *c19_D;
  c19_u = c19_hoistedGlobal;
  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_b_hoistedGlobal = chartInstance->c19_is_active_c19_observador_multirate;
  c19_b_u = c19_b_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y, FALSE);
  return c19_st;
}

static void set_sim_state_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance, const mxArray
   *c19_st)
{
  const mxArray *c19_u;
  real_T *c19_D;
  c19_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c19_doneDoubleBufferReInit = TRUE;
  c19_u = sf_mex_dup(c19_st);
  *c19_D = c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u,
    0)), "D");
  chartInstance->c19_is_active_c19_observador_multirate = c19_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 1)),
     "is_active_c19_observador_multirate");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_observador_multirate(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance)
{
}

static void sf_c19_observador_multirate(SFc19_observador_multirateInstanceStruct
  *chartInstance)
{
  real_T c19_hoistedGlobal;
  real_T c19_Ts;
  uint32_T c19_debug_family_var_map[4];
  real_T c19_nargin = 1.0;
  real_T c19_nargout = 1.0;
  real_T c19_D;
  real_T *c19_b_Ts;
  real_T *c19_b_D;
  c19_b_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c19_b_Ts = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, chartInstance->c19_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c19_b_Ts, 0U);
  _SFD_DATA_RANGE_CHECK(*c19_b_D, 1U);
  chartInstance->c19_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c19_sfEvent);
  c19_hoistedGlobal = *c19_b_Ts;
  c19_Ts = c19_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c19_debug_family_names,
    c19_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c19_nargin, 0U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c19_nargout, 1U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c19_Ts, 2U, c19_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c19_D, 3U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, 4);
  c19_D = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c19_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c19_b_D = c19_D;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c19_sfEvent);
  sf_debug_check_for_state_inconsistency(_observador_multirateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc19_observador_multirate
  (SFc19_observador_multirateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber)
{
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_observador_multirateInstanceStruct *chartInstance;
  chartInstance = (SFc19_observador_multirateInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

static real_T c19_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_D, const char_T *c19_identifier)
{
  real_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_D), &c19_thisId);
  sf_mex_destroy(&c19_D);
  return c19_y;
}

static real_T c19_b_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_D;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_observador_multirateInstanceStruct *chartInstance;
  chartInstance = (SFc19_observador_multirateInstanceStruct *)chartInstanceVoid;
  c19_D = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_D), &c19_thisId);
  sf_mex_destroy(&c19_D);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray *sf_c19_observador_multirate_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  sf_mex_assign(&c19_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_observador_multirateInstanceStruct *chartInstance;
  chartInstance = (SFc19_observador_multirateInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

static int32_T c19_c_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i0;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i0, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_b_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_observador_multirateInstanceStruct *chartInstance;
  chartInstance = (SFc19_observador_multirateInstanceStruct *)chartInstanceVoid;
  c19_b_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_b_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_b_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_d_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_b_is_active_c19_observador_multirate, const
  char_T *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_b_is_active_c19_observador_multirate), &c19_thisId);
  sf_mex_destroy(&c19_b_is_active_c19_observador_multirate);
  return c19_y;
}

static uint8_T c19_e_emlrt_marshallIn(SFc19_observador_multirateInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info(SFc19_observador_multirateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c19_observador_multirate_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(440426064U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3030602116U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3536814214U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3167862324U);
}

mxArray *sf_c19_observador_multirate_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ekMZSH4pEDqbM6p5hRtYdC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c19_observador_multirate(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"D\",},{M[8],M[0],T\"is_active_c19_observador_multirate\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_observador_multirate_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_observador_multirateInstanceStruct *chartInstance;
    chartInstance = (SFc19_observador_multirateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_observador_multirateMachineNumber_,
           19,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_observador_multirateMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_observador_multirateMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_observador_multirateMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ts");
          _SFD_SET_DATA_PROPS(1,2,0,1,"D");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,40);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)c19_sf_marshallIn);

        {
          real_T *c19_Ts;
          real_T *c19_D;
          c19_D = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c19_Ts = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_Ts);
          _SFD_SET_DATA_VALUE_PTR(1U, c19_D);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_observador_multirateMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "oKpNEL4IKI3RlTCum75s1B";
}

static void sf_opaque_initialize_c19_observador_multirate(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc19_observador_multirateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c19_observador_multirate
    ((SFc19_observador_multirateInstanceStruct*) chartInstanceVar);
  initialize_c19_observador_multirate((SFc19_observador_multirateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c19_observador_multirate(void *chartInstanceVar)
{
  enable_c19_observador_multirate((SFc19_observador_multirateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c19_observador_multirate(void *chartInstanceVar)
{
  disable_c19_observador_multirate((SFc19_observador_multirateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c19_observador_multirate(void *chartInstanceVar)
{
  sf_c19_observador_multirate((SFc19_observador_multirateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c19_observador_multirate
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_observador_multirate
    ((SFc19_observador_multirateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_observador_multirate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c19_observador_multirate(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_observador_multirate();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_observador_multirate
    ((SFc19_observador_multirateInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c19_observador_multirate(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c19_observador_multirate(S);
}

static void sf_opaque_set_sim_state_c19_observador_multirate(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c19_observador_multirate(S, st);
}

static void sf_opaque_terminate_c19_observador_multirate(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_observador_multirateInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c19_observador_multirate((SFc19_observador_multirateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_observador_multirate_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_observador_multirate
    ((SFc19_observador_multirateInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_observador_multirate(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_observador_multirate
      ((SFc19_observador_multirateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c19_observador_multirate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_observador_multirate_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,19,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,19,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1334553363U));
  ssSetChecksum1(S,(3133375262U));
  ssSetChecksum2(S,(3094612428U));
  ssSetChecksum3(S,(2401673650U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c19_observador_multirate(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_observador_multirate(SimStruct *S)
{
  SFc19_observador_multirateInstanceStruct *chartInstance;
  chartInstance = (SFc19_observador_multirateInstanceStruct *)malloc(sizeof
    (SFc19_observador_multirateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_observador_multirateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_observador_multirate;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_observador_multirate;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_observador_multirate;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c19_observador_multirate;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_observador_multirate;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_observador_multirate;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_observador_multirate;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_observador_multirate;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_observador_multirate;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_observador_multirate;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_observador_multirate;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c19_observador_multirate_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_observador_multirate(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_observador_multirate(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_observador_multirate(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_observador_multirate_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
