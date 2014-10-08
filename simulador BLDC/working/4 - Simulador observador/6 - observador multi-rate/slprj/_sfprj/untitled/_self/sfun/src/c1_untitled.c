/* Include files */

#include "blascompat32.h"
#include "untitled_sfun.h"
#include "c1_untitled.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[16] = { "deltaT", "A", "B", "L",
  "nargin", "nargout", "u", "y", "trigger", "trigger_sens", "clock", "y1", "x",
  "t", "C", "D" };

/* Function Declarations */
static void initialize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void initialize_params_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static void enable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void disable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c1_untitled(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void sf_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void c1_chartstep_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void initSimStructsc1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_D, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_C, const char_T *c1_identifier, real_T c1_y[2]);
static void c1_d_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_t, const char_T *c1_identifier);
static real_T c1_f_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_x, const char_T *c1_identifier, real_T c1_y[2]);
static void c1_h_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_i_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_y1, const char_T *c1_identifier);
static real_T c1_j_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_k_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_l_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[29]);
static void c1_eml_scalar_eg(SFc1_untitledInstanceStruct *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_untitledInstanceStruct *chartInstance);
static void c1_check_forloop_overflow_error(SFc1_untitledInstanceStruct
  *chartInstance);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_m_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_n_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_untitled, const char_T *c1_identifier);
static uint8_T c1_o_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_x_not_empty = FALSE;
  chartInstance->c1_t_not_empty = FALSE;
  chartInstance->c1_C_not_empty = FALSE;
  chartInstance->c1_D_not_empty = FALSE;
  chartInstance->c1_is_active_c1_untitled = 0U;
}

static void initialize_params_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
}

static void enable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i0;
  real_T c1_b_u[2];
  const mxArray *c1_c_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_c_hoistedGlobal;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  int32_T c1_i1;
  real_T c1_e_u[2];
  const mxArray *c1_f_y = NULL;
  uint8_T c1_d_hoistedGlobal;
  uint8_T c1_f_u;
  const mxArray *c1_g_y = NULL;
  real_T *c1_y1;
  c1_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(6), FALSE);
  c1_hoistedGlobal = *c1_y1;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    c1_b_u[c1_i0] = chartInstance->c1_C[c1_i0];
  }

  c1_c_y = NULL;
  if (!chartInstance->c1_C_not_empty) {
    sf_mex_assign(&c1_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_b_hoistedGlobal = chartInstance->c1_D;
  c1_c_u = c1_b_hoistedGlobal;
  c1_d_y = NULL;
  if (!chartInstance->c1_D_not_empty) {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 2, c1_d_y);
  c1_c_hoistedGlobal = chartInstance->c1_t;
  c1_d_u = c1_c_hoistedGlobal;
  c1_e_y = NULL;
  if (!chartInstance->c1_t_not_empty) {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c1_y, 3, c1_e_y);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_e_u[c1_i1] = chartInstance->c1_x[c1_i1];
  }

  c1_f_y = NULL;
  if (!chartInstance->c1_x_not_empty) {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_f_y, sf_mex_create("y", c1_e_u, 0, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 4, c1_f_y);
  c1_d_hoistedGlobal = chartInstance->c1_is_active_c1_untitled;
  c1_f_u = c1_d_hoistedGlobal;
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_f_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 5, c1_g_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_untitled(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[2];
  int32_T c1_i2;
  real_T c1_dv1[2];
  int32_T c1_i3;
  real_T *c1_y1;
  c1_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_y1 = c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u,
    0)), "y1");
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)), "C",
                        c1_dv0);
  for (c1_i2 = 0; c1_i2 < 2; c1_i2++) {
    chartInstance->c1_C[c1_i2] = c1_dv0[c1_i2];
  }

  chartInstance->c1_D = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "D");
  chartInstance->c1_t = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 3)), "t");
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 4)), "x",
                        c1_dv1);
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    chartInstance->c1_x[c1_i3] = c1_dv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_untitled = c1_n_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 5)), "is_active_c1_untitled");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_untitled(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
}

static void sf_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  real_T *c1_u;
  real_T *c1_y;
  real_T *c1_trigger;
  boolean_T *c1_trigger_sens;
  real_T *c1_clock;
  real_T *c1_y1;
  c1_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_trigger_sens = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_trigger = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_trigger, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_trigger_sens, 3U);
  _SFD_DATA_RANGE_CHECK(*c1_clock, 4U);
  _SFD_DATA_RANGE_CHECK(*c1_y1, 5U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_untitled(chartInstance);
  sf_debug_check_for_state_inconsistency(_untitledMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  boolean_T c1_d_hoistedGlobal;
  real_T c1_e_hoistedGlobal;
  real_T c1_u;
  real_T c1_y;
  real_T c1_trigger;
  boolean_T c1_trigger_sens;
  real_T c1_clock;
  uint32_T c1_debug_family_var_map[16];
  real_T c1_deltaT;
  real_T c1_A[4];
  real_T c1_B[2];
  real_T c1_L[2];
  real_T c1_nargin = 5.0;
  real_T c1_nargout = 1.0;
  real_T c1_y1;
  int32_T c1_i4;
  int32_T c1_i5;
  real_T c1_b;
  real_T c1_b_y;
  real_T c1_b_b;
  real_T c1_c_y;
  int32_T c1_i6;
  real_T c1_b_B;
  real_T c1_d_y;
  real_T c1_e_y;
  real_T c1_f_y;
  real_T c1_c_b;
  real_T c1_g_y;
  real_T c1_d_b;
  real_T c1_h_y;
  int32_T c1_i7;
  real_T c1_f_hoistedGlobal[2];
  int32_T c1_i8;
  real_T c1_a[4];
  int32_T c1_i9;
  real_T c1_i_y[2];
  int32_T c1_i10;
  int32_T c1_i11;
  int32_T c1_i12;
  real_T c1_b_a[2];
  real_T c1_e_b;
  int32_T c1_i13;
  int32_T c1_i14;
  real_T c1_g_hoistedGlobal[2];
  int32_T c1_i15;
  real_T c1_j_y;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i16;
  real_T c1_f_b;
  int32_T c1_i17;
  int32_T c1_i18;
  real_T c1_g_b;
  real_T c1_k_y;
  real_T c1_h_b;
  real_T c1_l_y;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  int32_T c1_i24;
  int32_T c1_i25;
  real_T c1_i_b;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  int32_T c1_i29;
  real_T c1_m_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  real_T c1_h_hoistedGlobal;
  real_T c1_c_a;
  real_T c1_j_b;
  real_T c1_n_y;
  real_T *c1_b_y1;
  real_T *c1_b_u;
  real_T *c1_o_y;
  real_T *c1_b_trigger;
  boolean_T *c1_b_trigger_sens;
  real_T *c1_b_clock;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c1_b_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_trigger_sens = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_trigger = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_o_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_u;
  c1_b_hoistedGlobal = *c1_o_y;
  c1_c_hoistedGlobal = *c1_b_trigger;
  c1_d_hoistedGlobal = *c1_b_trigger_sens;
  c1_e_hoistedGlobal = *c1_b_clock;
  c1_u = c1_hoistedGlobal;
  c1_y = c1_b_hoistedGlobal;
  c1_trigger = c1_c_hoistedGlobal;
  c1_trigger_sens = c1_d_hoistedGlobal;
  c1_clock = c1_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_deltaT, 0U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_A, 1U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_B, 2U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_L, 3U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 4U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 5U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_u, 6U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_y, 7U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_trigger, 8U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_trigger_sens, 9U, c1_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_clock, 10U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_y1, 11U, c1_e_sf_marshallOut,
    c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c1_x, 12U,
    c1_d_sf_marshallOut, c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c1_t, 13U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c1_C, 14U,
    c1_b_sf_marshallOut, c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c1_D, 15U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (CV_EML_COND(0, 1, 0, !chartInstance->c1_x_not_empty)) {
    guard3 = TRUE;
  } else if (CV_EML_COND(0, 1, 1, !chartInstance->c1_t_not_empty)) {
    guard3 = TRUE;
  } else if (CV_EML_COND(0, 1, 2, !chartInstance->c1_C_not_empty)) {
    guard2 = TRUE;
  } else if (CV_EML_COND(0, 1, 3, !chartInstance->c1_D_not_empty)) {
    guard1 = TRUE;
  } else {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
  }

  if (guard3 == TRUE) {
    guard2 = TRUE;
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, TRUE);
    CV_EML_IF(0, 1, 0, TRUE);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 10);
    for (c1_i4 = 0; c1_i4 < 2; c1_i4++) {
      chartInstance->c1_x[c1_i4] = 0.0;
    }

    chartInstance->c1_x_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 11);
    chartInstance->c1_t = -0.1;
    chartInstance->c1_t_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
    for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
      chartInstance->c1_C[c1_i5] = (real_T)c1_i5;
    }

    chartInstance->c1_C_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
    chartInstance->c1_D = 0.0;
    chartInstance->c1_D_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  if (CV_EML_IF(0, 1, 1, (real_T)c1_trigger_sens == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
    c1_deltaT = c1_clock - chartInstance->c1_t;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
    c1_b = c1_deltaT;
    c1_b_y = 0.2 * c1_b;
    c1_A[0] = 1.0 - c1_b_y;
    c1_A[2] = 0.0;
    c1_A[1] = c1_deltaT;
    c1_A[3] = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
    c1_b_b = c1_deltaT;
    c1_c_y = 10.0 * c1_b_b;
    c1_B[0] = c1_c_y;
    c1_B[1] = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 20);
    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      chartInstance->c1_C[c1_i6] = (real_T)c1_i6;
    }

    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
    c1_b_B = c1_deltaT;
    c1_d_y = c1_b_B;
    c1_e_y = c1_d_y;
    c1_f_y = 0.2 / c1_e_y;
    c1_c_b = c1_deltaT;
    c1_g_y = 0.04 * c1_c_b;
    c1_d_b = c1_deltaT;
    c1_h_y = 0.2 * c1_d_b;
    c1_L[0] = (-0.18 + c1_f_y) + c1_g_y;
    c1_L[1] = 0.9 - c1_h_y;
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
    for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
      c1_f_hoistedGlobal[c1_i7] = chartInstance->c1_x[c1_i7];
    }

    for (c1_i8 = 0; c1_i8 < 4; c1_i8++) {
      c1_a[c1_i8] = c1_A[c1_i8];
    }

    c1_eml_scalar_eg(chartInstance);
    c1_eml_scalar_eg(chartInstance);
    for (c1_i9 = 0; c1_i9 < 2; c1_i9++) {
      c1_i_y[c1_i9] = 0.0;
      c1_i10 = 0;
      for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
        c1_i_y[c1_i9] += c1_a[c1_i10 + c1_i9] * c1_f_hoistedGlobal[c1_i11];
        c1_i10 += 2;
      }
    }

    for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
      c1_b_a[c1_i12] = c1_B[c1_i12];
    }

    c1_e_b = c1_u;
    for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
      c1_b_a[c1_i13] *= c1_e_b;
    }

    for (c1_i14 = 0; c1_i14 < 2; c1_i14++) {
      c1_g_hoistedGlobal[c1_i14] = chartInstance->c1_C[c1_i14];
    }

    for (c1_i15 = 0; c1_i15 < 2; c1_i15++) {
      c1_f_hoistedGlobal[c1_i15] = chartInstance->c1_x[c1_i15];
    }

    c1_b_eml_scalar_eg(chartInstance);
    c1_b_eml_scalar_eg(chartInstance);
    c1_j_y = 0.0;
    c1_check_forloop_overflow_error(chartInstance);
    for (c1_k = 1; c1_k < 3; c1_k++) {
      c1_b_k = c1_k;
      c1_j_y += c1_g_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 2, 1, 0) - 1] *
        c1_f_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 2, 1, 0) - 1];
    }

    for (c1_i16 = 0; c1_i16 < 2; c1_i16++) {
      c1_f_hoistedGlobal[c1_i16] = c1_L[c1_i16];
    }

    c1_f_b = c1_y - c1_j_y;
    for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
      c1_f_hoistedGlobal[c1_i17] *= c1_f_b;
    }

    for (c1_i18 = 0; c1_i18 < 2; c1_i18++) {
      chartInstance->c1_x[c1_i18] = (c1_i_y[c1_i18] + c1_b_a[c1_i18]) +
        c1_f_hoistedGlobal[c1_i18];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
    if (CV_EML_IF(0, 1, 2, c1_trigger == 1.0)) {
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
      c1_deltaT = c1_clock - chartInstance->c1_t;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
      c1_g_b = c1_deltaT;
      c1_k_y = 0.2 * c1_g_b;
      c1_A[0] = 1.0 - c1_k_y;
      c1_A[2] = 0.0;
      c1_A[1] = c1_deltaT;
      c1_A[3] = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
      c1_h_b = c1_deltaT;
      c1_l_y = 10.0 * c1_h_b;
      c1_B[0] = c1_l_y;
      c1_B[1] = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
      for (c1_i19 = 0; c1_i19 < 2; c1_i19++) {
        chartInstance->c1_C[c1_i19] = (real_T)c1_i19;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
      for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
        c1_f_hoistedGlobal[c1_i20] = chartInstance->c1_x[c1_i20];
      }

      for (c1_i21 = 0; c1_i21 < 4; c1_i21++) {
        c1_a[c1_i21] = c1_A[c1_i21];
      }

      c1_eml_scalar_eg(chartInstance);
      c1_eml_scalar_eg(chartInstance);
      for (c1_i22 = 0; c1_i22 < 2; c1_i22++) {
        c1_i_y[c1_i22] = 0.0;
        c1_i23 = 0;
        for (c1_i24 = 0; c1_i24 < 2; c1_i24++) {
          c1_i_y[c1_i22] += c1_a[c1_i23 + c1_i22] * c1_f_hoistedGlobal[c1_i24];
          c1_i23 += 2;
        }
      }

      for (c1_i25 = 0; c1_i25 < 2; c1_i25++) {
        c1_b_a[c1_i25] = c1_B[c1_i25];
      }

      c1_i_b = c1_u;
      for (c1_i26 = 0; c1_i26 < 2; c1_i26++) {
        c1_b_a[c1_i26] *= c1_i_b;
      }

      for (c1_i27 = 0; c1_i27 < 2; c1_i27++) {
        chartInstance->c1_x[c1_i27] = c1_i_y[c1_i27] + c1_b_a[c1_i27];
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
  for (c1_i28 = 0; c1_i28 < 2; c1_i28++) {
    c1_g_hoistedGlobal[c1_i28] = chartInstance->c1_C[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 2; c1_i29++) {
    c1_f_hoistedGlobal[c1_i29] = chartInstance->c1_x[c1_i29];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  c1_m_y = 0.0;
  c1_check_forloop_overflow_error(chartInstance);
  for (c1_c_k = 1; c1_c_k < 3; c1_c_k++) {
    c1_d_k = c1_c_k;
    c1_m_y += c1_g_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_d_k), 1, 2, 1, 0) - 1] *
      c1_f_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_d_k), 1, 2, 1, 0) - 1];
  }

  c1_h_hoistedGlobal = chartInstance->c1_D;
  c1_c_a = c1_h_hoistedGlobal;
  c1_j_b = c1_u;
  c1_n_y = c1_c_a * c1_j_b;
  c1_y1 = c1_m_y + c1_n_y;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -31);
  sf_debug_symbol_scope_pop();
  *c1_b_y1 = c1_y1;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_D_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_D, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_D), &c1_thisId);
  sf_mex_destroy(&c1_b_D);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_D_not_empty = FALSE;
  } else {
    chartInstance->c1_D_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d0;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_D;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_b_D = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_D), &c1_thisId);
  sf_mex_destroy(&c1_b_D);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i30;
  real_T c1_b_inData[2];
  int32_T c1_i31;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i30 = 0; c1_i30 < 2; c1_i30++) {
    c1_b_inData[c1_i30] = (*(real_T (*)[2])c1_inData)[c1_i30];
  }

  for (c1_i31 = 0; c1_i31 < 2; c1_i31++) {
    c1_u[c1_i31] = c1_b_inData[c1_i31];
  }

  c1_y = NULL;
  if (!chartInstance->c1_C_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_C, const char_T *c1_identifier, real_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_C), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_C);
}

static void c1_d_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv2[2];
  int32_T c1_i32;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_C_not_empty = FALSE;
  } else {
    chartInstance->c1_C_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 2, 1,
                  2);
    for (c1_i32 = 0; c1_i32 < 2; c1_i32++) {
      c1_y[c1_i32] = c1_dv2[c1_i32];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_C;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i33;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_b_C = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_C), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_C);
  for (c1_i33 = 0; c1_i33 < 2; c1_i33++) {
    (*(real_T (*)[2])c1_outData)[c1_i33] = c1_y[c1_i33];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  if (!chartInstance->c1_t_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_t, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_t), &c1_thisId);
  sf_mex_destroy(&c1_b_t);
  return c1_y;
}

static real_T c1_f_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_t_not_empty = FALSE;
  } else {
    chartInstance->c1_t_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
    c1_y = c1_d1;
  }

  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_t;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_b_t = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_t), &c1_thisId);
  sf_mex_destroy(&c1_b_t);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i34;
  real_T c1_b_inData[2];
  int32_T c1_i35;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i34 = 0; c1_i34 < 2; c1_i34++) {
    c1_b_inData[c1_i34] = (*(real_T (*)[2])c1_inData)[c1_i34];
  }

  for (c1_i35 = 0; c1_i35 < 2; c1_i35++) {
    c1_u[c1_i35] = c1_b_inData[c1_i35];
  }

  c1_y = NULL;
  if (!chartInstance->c1_x_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_x, const char_T *c1_identifier, real_T c1_y[2])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_x), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_x);
}

static void c1_h_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv3[2];
  int32_T c1_i36;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_x_not_empty = FALSE;
  } else {
    chartInstance->c1_x_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 1, 2);
    for (c1_i36 = 0; c1_i36 < 2; c1_i36++) {
      c1_y[c1_i36] = c1_dv3[c1_i36];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_x;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i37;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_b_x = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_x), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_x);
  for (c1_i37 = 0; c1_i37 < 2; c1_i37++) {
    (*(real_T (*)[2])c1_outData)[c1_i37] = c1_y[c1_i37];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_i_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_y1, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y1), &c1_thisId);
  sf_mex_destroy(&c1_y1);
  return c1_y;
}

static real_T c1_j_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_y1;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_y1 = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_y1), &c1_thisId);
  sf_mex_destroy(&c1_y1);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i38;
  real_T c1_b_inData[2];
  int32_T c1_i39;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i38 = 0; c1_i38 < 2; c1_i38++) {
    c1_b_inData[c1_i38] = (*(real_T (*)[2])c1_inData)[c1_i38];
  }

  for (c1_i39 = 0; c1_i39 < 2; c1_i39++) {
    c1_u[c1_i39] = c1_b_inData[c1_i39];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_k_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv4[2];
  int32_T c1_i40;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i40 = 0; c1_i40 < 2; c1_i40++) {
    c1_y[c1_i40] = c1_dv4[c1_i40];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_L;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i41;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_L = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_L), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_L);
  for (c1_i41 = 0; c1_i41 < 2; c1_i41++) {
    (*(real_T (*)[2])c1_outData)[c1_i41] = c1_y[c1_i41];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  real_T c1_b_inData[4];
  int32_T c1_i45;
  int32_T c1_i46;
  int32_T c1_i47;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i42 = 0;
  for (c1_i43 = 0; c1_i43 < 2; c1_i43++) {
    for (c1_i44 = 0; c1_i44 < 2; c1_i44++) {
      c1_b_inData[c1_i44 + c1_i42] = (*(real_T (*)[4])c1_inData)[c1_i44 + c1_i42];
    }

    c1_i42 += 2;
  }

  c1_i45 = 0;
  for (c1_i46 = 0; c1_i46 < 2; c1_i46++) {
    for (c1_i47 = 0; c1_i47 < 2; c1_i47++) {
      c1_u[c1_i47 + c1_i45] = c1_b_inData[c1_i47 + c1_i45];
    }

    c1_i45 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_l_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv5[4];
  int32_T c1_i48;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv5, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    c1_y[c1_i48] = c1_dv5[c1_i48];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_A;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i49;
  int32_T c1_i50;
  int32_T c1_i51;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_A = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_A), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_A);
  c1_i49 = 0;
  for (c1_i50 = 0; c1_i50 < 2; c1_i50++) {
    for (c1_i51 = 0; c1_i51 < 2; c1_i51++) {
      (*(real_T (*)[4])c1_outData)[c1_i51 + c1_i49] = c1_y[c1_i51 + c1_i49];
    }

    c1_i49 += 2;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[29];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i52;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29), FALSE);
  for (c1_i52 = 0; c1_i52 < 29; c1_i52++) {
    c1_r0 = &c1_info[c1_i52];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i52);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i52);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[29])
{
  c1_info[0].context = "";
  c1_info[0].name = "mtimes";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[0].fileTimeLo = 1289530492U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "mrdivide";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[1].fileTimeLo = 1342828944U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 1319744366U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[2].name = "rdivide";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[2].fileTimeLo = 1286836844U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[3].name = "eml_div";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[3].fileTimeLo = 1313365810U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[4].name = "eml_index_class";
  c1_info[4].dominantType = "";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[4].fileTimeLo = 1323181378U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[5].name = "eml_scalar_eg";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[5].fileTimeLo = 1286836796U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[6].name = "eml_xgemm";
  c1_info[6].dominantType = "char";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[6].fileTimeLo = 1299091172U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[7].name = "eml_blas_inline";
  c1_info[7].dominantType = "";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[7].fileTimeLo = 1299091168U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[8].name = "mtimes";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].fileTimeLo = 1289530492U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[9].name = "eml_index_class";
  c1_info[9].dominantType = "";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[9].fileTimeLo = 1323181378U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[10].name = "eml_scalar_eg";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[10].fileTimeLo = 1286836796U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[11].name = "eml_refblas_xgemm";
  c1_info[11].dominantType = "char";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[11].fileTimeLo = 1299091174U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[12].name = "eml_xdotu";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[12].fileTimeLo = 1299091172U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[13].name = "eml_blas_inline";
  c1_info[13].dominantType = "";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[13].fileTimeLo = 1299091168U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[14].name = "eml_xdot";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[14].fileTimeLo = 1299091172U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[15].name = "eml_blas_inline";
  c1_info[15].dominantType = "";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[15].fileTimeLo = 1299091168U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[16].name = "eml_index_class";
  c1_info[16].dominantType = "";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[16].fileTimeLo = 1323181378U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[17].name = "eml_refblas_xdot";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[17].fileTimeLo = 1299091172U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[18].name = "eml_refblas_xdotx";
  c1_info[18].dominantType = "char";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[18].fileTimeLo = 1299091174U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[19].name = "eml_scalar_eg";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[19].fileTimeLo = 1286836796U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[20].name = "eml_index_class";
  c1_info[20].dominantType = "";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[20].fileTimeLo = 1323181378U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[21].name = "eml_index_minus";
  c1_info[21].dominantType = "double";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[21].fileTimeLo = 1286836778U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[22].name = "eml_index_class";
  c1_info[22].dominantType = "";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[22].fileTimeLo = 1323181378U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[23].name = "eml_index_times";
  c1_info[23].dominantType = "coder.internal.indexInt";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[23].fileTimeLo = 1286836780U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[24].name = "eml_index_class";
  c1_info[24].dominantType = "";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[24].fileTimeLo = 1323181378U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[25].name = "eml_index_plus";
  c1_info[25].dominantType = "coder.internal.indexInt";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[25].fileTimeLo = 1286836778U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[26].name = "eml_index_class";
  c1_info[26].dominantType = "";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[26].fileTimeLo = 1323181378U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[27].name = "eml_int_forloop_overflow_check";
  c1_info[27].dominantType = "";
  c1_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[27].fileTimeLo = 1332183072U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[28].name = "intmax";
  c1_info[28].dominantType = "char";
  c1_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[28].fileTimeLo = 1311273316U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
}

static void c1_eml_scalar_eg(SFc1_untitledInstanceStruct *chartInstance)
{
}

static void c1_b_eml_scalar_eg(SFc1_untitledInstanceStruct *chartInstance)
{
}

static void c1_check_forloop_overflow_error(SFc1_untitledInstanceStruct
  *chartInstance)
{
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_m_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i53;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i53, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i53;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_n_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_untitled, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_untitled), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_untitled);
  return c1_y;
}

static uint8_T c1_o_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_untitledInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1757634640U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2776754646U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3407985061U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(760563223U);
}

mxArray *sf_c1_untitled_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lwSesisRRLgLeXz1o360HC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c1_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[10],T\"y1\",},{M[4],M[0],T\"C\",S'l','i','p'{{M1x2[120 121],M[0],}}},{M[4],M[0],T\"D\",S'l','i','p'{{M1x2[138 139],M[0],}}},{M[4],M[0],T\"t\",S'l','i','p'{{M1x2[102 103],M[0],}}},{M[4],M[0],T\"x\",S'l','i','p'{{M1x2[84 85],M[0],}}},{M[8],M[0],T\"is_active_c1_untitled\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_untitledInstanceStruct *chartInstance;
    chartInstance = (SFc1_untitledInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_untitledMachineNumber_,
          1,
          1,
          1,
          6,
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
          init_script_number_translation(_untitledMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_untitledMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_untitledMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"trigger");
          _SFD_SET_DATA_PROPS(3,1,1,0,"trigger_sens");
          _SFD_SET_DATA_PROPS(4,1,1,0,"clock");
          _SFD_SET_DATA_PROPS(5,2,0,1,"y1");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,712);
        _SFD_CV_INIT_EML_IF(0,1,0,146,202,-1,283);
        _SFD_CV_INIT_EML_IF(0,1,1,289,310,520,540);
        _SFD_CV_INIT_EML_IF(0,1,2,520,540,-1,540);

        {
          static int condStart[] = { 149, 163, 177, 191 };

          static int condEnd[] = { 159, 173, 187, 201 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2, 3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,149,201,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)c1_e_sf_marshallIn);

        {
          real_T *c1_u;
          real_T *c1_y;
          real_T *c1_trigger;
          boolean_T *c1_trigger_sens;
          real_T *c1_clock;
          real_T *c1_y1;
          c1_y1 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c1_trigger_sens = (boolean_T *)ssGetInputPortSignal(chartInstance->S,
            3);
          c1_trigger = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_trigger);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_trigger_sens);
          _SFD_SET_DATA_VALUE_PTR(4U, c1_clock);
          _SFD_SET_DATA_VALUE_PTR(5U, c1_y1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_untitledMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "ncz2RzEfjB08uAMRmWtDGG";
}

static void sf_opaque_initialize_c1_untitled(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_untitledInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
  initialize_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_untitled(void *chartInstanceVar)
{
  enable_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_untitled(void *chartInstanceVar)
{
  disable_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_untitled(void *chartInstanceVar)
{
  sf_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_untitled(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_untitled((SFc1_untitledInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_untitled();/* state var info */
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

extern void sf_internal_set_sim_state_c1_untitled(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_untitled();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_untitled((SFc1_untitledInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_untitled(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_untitled(S);
}

static void sf_opaque_set_sim_state_c1_untitled(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_untitled(S, st);
}

static void sf_opaque_terminate_c1_untitled(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_untitled_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_untitled(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_untitled((SFc1_untitledInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1480992126U));
  ssSetChecksum1(S,(925273795U));
  ssSetChecksum2(S,(3862838461U));
  ssSetChecksum3(S,(2278489371U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_untitled(SimStruct *S)
{
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)malloc(sizeof
    (SFc1_untitledInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_untitled;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_untitled;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_untitled;
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

void c1_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
