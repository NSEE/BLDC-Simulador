/* Include files */

#include "blascompat32.h"
#include "observador_multirate_2_sfun.h"
#include "c11_observador_multirate_2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "observador_multirate_2_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c11_debug_family_names[16] = { "deltaT", "A", "B", "L",
  "nargin", "nargout", "u", "y", "new_sens", "clock", "x_hat", "y_hat", "x", "t",
  "C", "D" };

/* Function Declarations */
static void initialize_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void initialize_params_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void enable_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void disable_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void set_sim_state_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance, const mxArray
   *c11_st);
static void finalize_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void sf_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void c11_chartstep_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void initSimStructsc11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_b_D, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_b_C, const char_T *c11_identifier, real_T
  c11_y[2]);
static void c11_d_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_e_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_b_t, const char_T *c11_identifier);
static real_T c11_f_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_g_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_b_x, const char_T *c11_identifier, real_T
  c11_y[2]);
static void c11_h_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_i_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_y_hat, const char_T *c11_identifier);
static real_T c11_j_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_k_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_x_hat, const char_T *c11_identifier, real_T
  c11_y[2]);
static void c11_l_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2]);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_m_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4]);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[29]);
static void c11_eml_scalar_eg(SFc11_observador_multirate_2InstanceStruct
  *chartInstance);
static void c11_b_eml_scalar_eg(SFc11_observador_multirate_2InstanceStruct
  *chartInstance);
static void c11_check_forloop_overflow_error
  (SFc11_observador_multirate_2InstanceStruct *chartInstance);
static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_n_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_o_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_observador_multirate_2,
  const char_T *c11_identifier);
static uint8_T c11_p_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_observador_multirate_2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_x_not_empty = FALSE;
  chartInstance->c11_t_not_empty = FALSE;
  chartInstance->c11_C_not_empty = FALSE;
  chartInstance->c11_D_not_empty = FALSE;
  chartInstance->c11_is_active_c11_observador_multirate_2 = 0U;
}

static void initialize_params_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
}

static void enable_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[2];
  const mxArray *c11_b_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  int32_T c11_i1;
  real_T c11_c_u[2];
  const mxArray *c11_d_y = NULL;
  real_T c11_b_hoistedGlobal;
  real_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  real_T c11_c_hoistedGlobal;
  real_T c11_e_u;
  const mxArray *c11_f_y = NULL;
  int32_T c11_i2;
  real_T c11_f_u[2];
  const mxArray *c11_g_y = NULL;
  uint8_T c11_d_hoistedGlobal;
  uint8_T c11_g_u;
  const mxArray *c11_h_y = NULL;
  real_T *c11_y_hat;
  real_T (*c11_x_hat)[2];
  c11_y_hat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c11_x_hat = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(7), FALSE);
  for (c11_i0 = 0; c11_i0 < 2; c11_i0++) {
    c11_u[c11_i0] = (*c11_x_hat)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_hoistedGlobal = *c11_y_hat;
  c11_b_u = c11_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  for (c11_i1 = 0; c11_i1 < 2; c11_i1++) {
    c11_c_u[c11_i1] = chartInstance->c11_C[c11_i1];
  }

  c11_d_y = NULL;
  if (!chartInstance->c11_C_not_empty) {
    sf_mex_assign(&c11_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c11_d_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_b_hoistedGlobal = chartInstance->c11_D;
  c11_d_u = c11_b_hoistedGlobal;
  c11_e_y = NULL;
  if (!chartInstance->c11_D_not_empty) {
    sf_mex_assign(&c11_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_c_hoistedGlobal = chartInstance->c11_t;
  c11_e_u = c11_c_hoistedGlobal;
  c11_f_y = NULL;
  if (!chartInstance->c11_t_not_empty) {
    sf_mex_assign(&c11_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_e_u, 0, 0U, 0U, 0U, 0),
                  FALSE);
  }

  sf_mex_setcell(c11_y, 4, c11_f_y);
  for (c11_i2 = 0; c11_i2 < 2; c11_i2++) {
    c11_f_u[c11_i2] = chartInstance->c11_x[c11_i2];
  }

  c11_g_y = NULL;
  if (!chartInstance->c11_x_not_empty) {
    sf_mex_assign(&c11_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c11_g_y, sf_mex_create("y", c11_f_u, 0, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c11_y, 5, c11_g_y);
  c11_d_hoistedGlobal = chartInstance->c11_is_active_c11_observador_multirate_2;
  c11_g_u = c11_d_hoistedGlobal;
  c11_h_y = NULL;
  sf_mex_assign(&c11_h_y, sf_mex_create("y", &c11_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 6, c11_h_y);
  sf_mex_assign(&c11_st, c11_y, FALSE);
  return c11_st;
}

static void set_sim_state_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance, const mxArray
   *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[2];
  int32_T c11_i3;
  real_T c11_dv1[2];
  int32_T c11_i4;
  real_T c11_dv2[2];
  int32_T c11_i5;
  real_T *c11_y_hat;
  real_T (*c11_x_hat)[2];
  c11_y_hat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c11_x_hat = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
    "x_hat", c11_dv0);
  for (c11_i3 = 0; c11_i3 < 2; c11_i3++) {
    (*c11_x_hat)[c11_i3] = c11_dv0[c11_i3];
  }

  *c11_y_hat = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 1)), "y_hat");
  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
    "C", c11_dv1);
  for (c11_i4 = 0; c11_i4 < 2; c11_i4++) {
    chartInstance->c11_C[c11_i4] = c11_dv1[c11_i4];
  }

  chartInstance->c11_D = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 3)), "D");
  chartInstance->c11_t = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 4)), "t");
  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 5)),
    "x", c11_dv2);
  for (c11_i5 = 0; c11_i5 < 2; c11_i5++) {
    chartInstance->c11_x[c11_i5] = c11_dv2[c11_i5];
  }

  chartInstance->c11_is_active_c11_observador_multirate_2 =
    c11_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 6)),
    "is_active_c11_observador_multirate_2");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_observador_multirate_2(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
}

static void sf_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
  int32_T c11_i6;
  real_T *c11_u;
  real_T *c11_y;
  boolean_T *c11_new_sens;
  real_T *c11_clock;
  real_T *c11_y_hat;
  real_T (*c11_x_hat)[2];
  c11_y_hat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c11_x_hat = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c11_new_sens = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c11_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c11_y, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c11_new_sens, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_clock, 3U);
  for (c11_i6 = 0; c11_i6 < 2; c11_i6++) {
    _SFD_DATA_RANGE_CHECK((*c11_x_hat)[c11_i6], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c11_y_hat, 5U);
  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_observador_multirate_2(chartInstance);
  sf_debug_check_for_state_inconsistency(_observador_multirate_2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_chartstep_c11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
  real_T c11_hoistedGlobal;
  real_T c11_b_hoistedGlobal;
  boolean_T c11_c_hoistedGlobal;
  real_T c11_d_hoistedGlobal;
  real_T c11_u;
  real_T c11_y;
  boolean_T c11_new_sens;
  real_T c11_clock;
  uint32_T c11_debug_family_var_map[16];
  real_T c11_deltaT;
  real_T c11_A[4];
  real_T c11_B[2];
  real_T c11_L[2];
  real_T c11_nargin = 4.0;
  real_T c11_nargout = 2.0;
  real_T c11_x_hat[2];
  real_T c11_y_hat;
  int32_T c11_i7;
  int32_T c11_i8;
  real_T c11_b;
  real_T c11_b_y;
  real_T c11_b_b;
  real_T c11_c_y;
  real_T c11_b_B;
  real_T c11_d_y;
  real_T c11_e_y;
  real_T c11_f_y;
  real_T c11_c_b;
  real_T c11_g_y;
  real_T c11_d_b;
  real_T c11_h_y;
  int32_T c11_i9;
  real_T c11_e_hoistedGlobal[2];
  int32_T c11_i10;
  real_T c11_a[4];
  int32_T c11_i11;
  real_T c11_i_y[2];
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  real_T c11_b_a[2];
  real_T c11_e_b;
  int32_T c11_i15;
  int32_T c11_i16;
  real_T c11_f_hoistedGlobal[2];
  int32_T c11_i17;
  real_T c11_j_y;
  int32_T c11_k;
  int32_T c11_b_k;
  int32_T c11_i18;
  real_T c11_f_b;
  int32_T c11_i19;
  int32_T c11_i20;
  real_T c11_g_b;
  real_T c11_k_y;
  real_T c11_h_b;
  real_T c11_l_y;
  int32_T c11_i21;
  int32_T c11_i22;
  int32_T c11_i23;
  int32_T c11_i24;
  int32_T c11_i25;
  int32_T c11_i26;
  real_T c11_i_b;
  int32_T c11_i27;
  int32_T c11_i28;
  int32_T c11_i29;
  int32_T c11_i30;
  int32_T c11_i31;
  real_T c11_m_y;
  int32_T c11_c_k;
  int32_T c11_d_k;
  real_T c11_g_hoistedGlobal;
  real_T c11_c_a;
  real_T c11_j_b;
  real_T c11_n_y;
  int32_T c11_i32;
  real_T *c11_b_u;
  real_T *c11_o_y;
  boolean_T *c11_b_new_sens;
  real_T *c11_b_clock;
  real_T *c11_b_y_hat;
  real_T (*c11_b_x_hat)[2];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c11_b_y_hat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c11_b_x_hat = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c11_b_new_sens = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_o_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
  c11_hoistedGlobal = *c11_b_u;
  c11_b_hoistedGlobal = *c11_o_y;
  c11_c_hoistedGlobal = *c11_b_new_sens;
  c11_d_hoistedGlobal = *c11_b_clock;
  c11_u = c11_hoistedGlobal;
  c11_y = c11_b_hoistedGlobal;
  c11_new_sens = c11_c_hoistedGlobal;
  c11_clock = c11_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c11_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c11_deltaT, 0U, c11_e_sf_marshallOut,
    c11_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c11_A, 1U, c11_h_sf_marshallOut,
    c11_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c11_B, 2U, c11_f_sf_marshallOut,
    c11_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c11_L, 3U, c11_f_sf_marshallOut,
    c11_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargin, 4U, c11_e_sf_marshallOut,
    c11_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargout, 5U,
    c11_e_sf_marshallOut, c11_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c11_u, 6U, c11_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_y, 7U, c11_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_new_sens, 8U, c11_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_clock, 9U, c11_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c11_x_hat, 10U, c11_f_sf_marshallOut,
    c11_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_y_hat, 11U, c11_e_sf_marshallOut,
    c11_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c11_x, 12U,
    c11_d_sf_marshallOut, c11_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c11_t, 13U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(chartInstance->c11_C, 14U,
    c11_b_sf_marshallOut, c11_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&chartInstance->c11_D, 15U,
    c11_sf_marshallOut, c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 4);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 6);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 7);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 9);
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (CV_EML_COND(0, 1, 0, !chartInstance->c11_x_not_empty)) {
    guard3 = TRUE;
  } else if (CV_EML_COND(0, 1, 1, !chartInstance->c11_t_not_empty)) {
    guard3 = TRUE;
  } else if (CV_EML_COND(0, 1, 2, !chartInstance->c11_C_not_empty)) {
    guard2 = TRUE;
  } else if (CV_EML_COND(0, 1, 3, !chartInstance->c11_D_not_empty)) {
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
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
    for (c11_i7 = 0; c11_i7 < 2; c11_i7++) {
      chartInstance->c11_x[c11_i7] = 0.0;
    }

    chartInstance->c11_x_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 11);
    chartInstance->c11_t = 0.0;
    chartInstance->c11_t_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 12);
    for (c11_i8 = 0; c11_i8 < 2; c11_i8++) {
      chartInstance->c11_C[c11_i8] = (real_T)c11_i8;
    }

    chartInstance->c11_C_not_empty = TRUE;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
    chartInstance->c11_D = 0.0;
    chartInstance->c11_D_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 16);
  if (CV_EML_IF(0, 1, 1, (real_T)c11_new_sens == 1.0)) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 17);
    c11_deltaT = c11_clock - chartInstance->c11_t;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 18);
    c11_b = c11_deltaT;
    c11_b_y = 0.2 * c11_b;
    c11_A[0] = 1.0 - c11_b_y;
    c11_A[2] = 0.0;
    c11_A[1] = c11_deltaT;
    c11_A[3] = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 19);
    c11_b_b = c11_deltaT;
    c11_c_y = 10.0 * c11_b_b;
    c11_B[0] = c11_c_y;
    c11_B[1] = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 20);
    c11_b_B = c11_deltaT;
    c11_d_y = c11_b_B;
    c11_e_y = c11_d_y;
    c11_f_y = 0.2 / c11_e_y;
    c11_c_b = c11_deltaT;
    c11_g_y = 0.04 * c11_c_b;
    c11_d_b = c11_deltaT;
    c11_h_y = 0.2 * c11_d_b;
    c11_L[0] = (-0.18 + c11_f_y) + c11_g_y;
    c11_L[1] = 0.9 - c11_h_y;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 21);
    for (c11_i9 = 0; c11_i9 < 2; c11_i9++) {
      c11_e_hoistedGlobal[c11_i9] = chartInstance->c11_x[c11_i9];
    }

    for (c11_i10 = 0; c11_i10 < 4; c11_i10++) {
      c11_a[c11_i10] = c11_A[c11_i10];
    }

    c11_eml_scalar_eg(chartInstance);
    c11_eml_scalar_eg(chartInstance);
    for (c11_i11 = 0; c11_i11 < 2; c11_i11++) {
      c11_i_y[c11_i11] = 0.0;
      c11_i12 = 0;
      for (c11_i13 = 0; c11_i13 < 2; c11_i13++) {
        c11_i_y[c11_i11] += c11_a[c11_i12 + c11_i11] *
          c11_e_hoistedGlobal[c11_i13];
        c11_i12 += 2;
      }
    }

    for (c11_i14 = 0; c11_i14 < 2; c11_i14++) {
      c11_b_a[c11_i14] = c11_B[c11_i14];
    }

    c11_e_b = c11_u;
    for (c11_i15 = 0; c11_i15 < 2; c11_i15++) {
      c11_b_a[c11_i15] *= c11_e_b;
    }

    for (c11_i16 = 0; c11_i16 < 2; c11_i16++) {
      c11_f_hoistedGlobal[c11_i16] = chartInstance->c11_C[c11_i16];
    }

    for (c11_i17 = 0; c11_i17 < 2; c11_i17++) {
      c11_e_hoistedGlobal[c11_i17] = chartInstance->c11_x[c11_i17];
    }

    c11_b_eml_scalar_eg(chartInstance);
    c11_b_eml_scalar_eg(chartInstance);
    c11_j_y = 0.0;
    c11_check_forloop_overflow_error(chartInstance);
    for (c11_k = 1; c11_k < 3; c11_k++) {
      c11_b_k = c11_k;
      c11_j_y += c11_f_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c11_b_k), 1, 2, 1, 0) - 1] *
        c11_e_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c11_b_k), 1, 2, 1, 0) - 1];
    }

    for (c11_i18 = 0; c11_i18 < 2; c11_i18++) {
      c11_e_hoistedGlobal[c11_i18] = c11_L[c11_i18];
    }

    c11_f_b = c11_y - c11_j_y;
    for (c11_i19 = 0; c11_i19 < 2; c11_i19++) {
      c11_e_hoistedGlobal[c11_i19] *= c11_f_b;
    }

    for (c11_i20 = 0; c11_i20 < 2; c11_i20++) {
      chartInstance->c11_x[c11_i20] = (c11_i_y[c11_i20] + c11_b_a[c11_i20]) +
        c11_e_hoistedGlobal[c11_i20];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 23);
    c11_deltaT = c11_clock - chartInstance->c11_t;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 24);
    c11_g_b = c11_deltaT;
    c11_k_y = 0.2 * c11_g_b;
    c11_A[0] = 1.0 - c11_k_y;
    c11_A[2] = 0.0;
    c11_A[1] = c11_deltaT;
    c11_A[3] = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 25);
    c11_h_b = c11_deltaT;
    c11_l_y = 10.0 * c11_h_b;
    c11_B[0] = c11_l_y;
    c11_B[1] = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 26);
    for (c11_i21 = 0; c11_i21 < 2; c11_i21++) {
      c11_e_hoistedGlobal[c11_i21] = chartInstance->c11_x[c11_i21];
    }

    for (c11_i22 = 0; c11_i22 < 4; c11_i22++) {
      c11_a[c11_i22] = c11_A[c11_i22];
    }

    c11_eml_scalar_eg(chartInstance);
    c11_eml_scalar_eg(chartInstance);
    for (c11_i23 = 0; c11_i23 < 2; c11_i23++) {
      c11_i_y[c11_i23] = 0.0;
      c11_i24 = 0;
      for (c11_i25 = 0; c11_i25 < 2; c11_i25++) {
        c11_i_y[c11_i23] += c11_a[c11_i24 + c11_i23] *
          c11_e_hoistedGlobal[c11_i25];
        c11_i24 += 2;
      }
    }

    for (c11_i26 = 0; c11_i26 < 2; c11_i26++) {
      c11_b_a[c11_i26] = c11_B[c11_i26];
    }

    c11_i_b = c11_u;
    for (c11_i27 = 0; c11_i27 < 2; c11_i27++) {
      c11_b_a[c11_i27] *= c11_i_b;
    }

    for (c11_i28 = 0; c11_i28 < 2; c11_i28++) {
      chartInstance->c11_x[c11_i28] = c11_i_y[c11_i28] + c11_b_a[c11_i28];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 29);
  for (c11_i29 = 0; c11_i29 < 2; c11_i29++) {
    c11_x_hat[c11_i29] = chartInstance->c11_x[c11_i29];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 30);
  for (c11_i30 = 0; c11_i30 < 2; c11_i30++) {
    c11_f_hoistedGlobal[c11_i30] = chartInstance->c11_C[c11_i30];
  }

  for (c11_i31 = 0; c11_i31 < 2; c11_i31++) {
    c11_e_hoistedGlobal[c11_i31] = chartInstance->c11_x[c11_i31];
  }

  c11_b_eml_scalar_eg(chartInstance);
  c11_b_eml_scalar_eg(chartInstance);
  c11_m_y = 0.0;
  c11_check_forloop_overflow_error(chartInstance);
  for (c11_c_k = 1; c11_c_k < 3; c11_c_k++) {
    c11_d_k = c11_c_k;
    c11_m_y += c11_f_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c11_d_k), 1, 2, 1, 0) - 1] *
      c11_e_hoistedGlobal[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c11_d_k), 1, 2, 1, 0) - 1];
  }

  c11_g_hoistedGlobal = chartInstance->c11_D;
  c11_c_a = c11_g_hoistedGlobal;
  c11_j_b = c11_u;
  c11_n_y = c11_c_a * c11_j_b;
  c11_y_hat = c11_m_y + c11_n_y;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 33);
  chartInstance->c11_t = c11_clock;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -33);
  sf_debug_symbol_scope_pop();
  for (c11_i32 = 0; c11_i32 < 2; c11_i32++) {
    (*c11_b_x_hat)[c11_i32] = c11_x_hat[c11_i32];
  }

  *c11_b_y_hat = c11_y_hat;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_observador_multirate_2
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  if (!chartInstance->c11_D_not_empty) {
    sf_mex_assign(&c11_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_b_D, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_D), &c11_thisId);
  sf_mex_destroy(&c11_b_D);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_D_not_empty = FALSE;
  } else {
    chartInstance->c11_D_not_empty = TRUE;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
    c11_y = c11_d0;
  }

  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_D;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_b_D = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_D), &c11_thisId);
  sf_mex_destroy(&c11_b_D);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i33;
  real_T c11_b_inData[2];
  int32_T c11_i34;
  real_T c11_u[2];
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i33 = 0; c11_i33 < 2; c11_i33++) {
    c11_b_inData[c11_i33] = (*(real_T (*)[2])c11_inData)[c11_i33];
  }

  for (c11_i34 = 0; c11_i34 < 2; c11_i34++) {
    c11_u[c11_i34] = c11_b_inData[c11_i34];
  }

  c11_y = NULL;
  if (!chartInstance->c11_C_not_empty) {
    sf_mex_assign(&c11_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1, 2),
                  FALSE);
  }

  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_b_C, const char_T *c11_identifier, real_T
  c11_y[2])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_C), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_b_C);
}

static void c11_d_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2])
{
  real_T c11_dv3[2];
  int32_T c11_i35;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_C_not_empty = FALSE;
  } else {
    chartInstance->c11_C_not_empty = TRUE;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv3, 1, 0, 0U, 1, 0U, 2,
                  1, 2);
    for (c11_i35 = 0; c11_i35 < 2; c11_i35++) {
      c11_y[c11_i35] = c11_dv3[c11_i35];
    }
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_C;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[2];
  int32_T c11_i36;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_b_C = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_C), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_b_C);
  for (c11_i36 = 0; c11_i36 < 2; c11_i36++) {
    (*(real_T (*)[2])c11_outData)[c11_i36] = c11_y[c11_i36];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  if (!chartInstance->c11_t_not_empty) {
    sf_mex_assign(&c11_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_e_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_b_t, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_t), &c11_thisId);
  sf_mex_destroy(&c11_b_t);
  return c11_y;
}

static real_T c11_f_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d1;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_t_not_empty = FALSE;
  } else {
    chartInstance->c11_t_not_empty = TRUE;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d1, 1, 0, 0U, 0, 0U, 0);
    c11_y = c11_d1;
  }

  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_t;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_b_t = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_t), &c11_thisId);
  sf_mex_destroy(&c11_b_t);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i37;
  real_T c11_b_inData[2];
  int32_T c11_i38;
  real_T c11_u[2];
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i37 = 0; c11_i37 < 2; c11_i37++) {
    c11_b_inData[c11_i37] = (*(real_T (*)[2])c11_inData)[c11_i37];
  }

  for (c11_i38 = 0; c11_i38 < 2; c11_i38++) {
    c11_u[c11_i38] = c11_b_inData[c11_i38];
  }

  c11_y = NULL;
  if (!chartInstance->c11_x_not_empty) {
    sf_mex_assign(&c11_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  }

  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_g_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_b_x, const char_T *c11_identifier, real_T
  c11_y[2])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_x), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_b_x);
}

static void c11_h_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2])
{
  real_T c11_dv4[2];
  int32_T c11_i39;
  if (mxIsEmpty(c11_u)) {
    chartInstance->c11_x_not_empty = FALSE;
  } else {
    chartInstance->c11_x_not_empty = TRUE;
    sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv4, 1, 0, 0U, 1, 0U, 1,
                  2);
    for (c11_i39 = 0; c11_i39 < 2; c11_i39++) {
      c11_y[c11_i39] = c11_dv4[c11_i39];
    }
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_x;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[2];
  int32_T c11_i40;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_b_x = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_x), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_b_x);
  for (c11_i40 = 0; c11_i40 < 2; c11_i40++) {
    (*(real_T (*)[2])c11_outData)[c11_i40] = c11_y[c11_i40];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_i_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_y_hat, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_y_hat),
    &c11_thisId);
  sf_mex_destroy(&c11_y_hat);
  return c11_y;
}

static real_T c11_j_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d2;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d2, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d2;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_y_hat;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_y_hat = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_y_hat),
    &c11_thisId);
  sf_mex_destroy(&c11_y_hat);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i41;
  real_T c11_b_inData[2];
  int32_T c11_i42;
  real_T c11_u[2];
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i41 = 0; c11_i41 < 2; c11_i41++) {
    c11_b_inData[c11_i41] = (*(real_T (*)[2])c11_inData)[c11_i41];
  }

  for (c11_i42 = 0; c11_i42 < 2; c11_i42++) {
    c11_u[c11_i42] = c11_b_inData[c11_i42];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_k_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_x_hat, const char_T *c11_identifier, real_T
  c11_y[2])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_x_hat), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_x_hat);
}

static void c11_l_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2])
{
  real_T c11_dv5[2];
  int32_T c11_i43;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv5, 1, 0, 0U, 1, 0U, 1, 2);
  for (c11_i43 = 0; c11_i43 < 2; c11_i43++) {
    c11_y[c11_i43] = c11_dv5[c11_i43];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_x_hat;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[2];
  int32_T c11_i44;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_x_hat = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_x_hat), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_x_hat);
  for (c11_i44 = 0; c11_i44 < 2; c11_i44++) {
    (*(real_T (*)[2])c11_outData)[c11_i44] = c11_y[c11_i44];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i45;
  int32_T c11_i46;
  int32_T c11_i47;
  real_T c11_b_inData[4];
  int32_T c11_i48;
  int32_T c11_i49;
  int32_T c11_i50;
  real_T c11_u[4];
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i45 = 0;
  for (c11_i46 = 0; c11_i46 < 2; c11_i46++) {
    for (c11_i47 = 0; c11_i47 < 2; c11_i47++) {
      c11_b_inData[c11_i47 + c11_i45] = (*(real_T (*)[4])c11_inData)[c11_i47 +
        c11_i45];
    }

    c11_i45 += 2;
  }

  c11_i48 = 0;
  for (c11_i49 = 0; c11_i49 < 2; c11_i49++) {
    for (c11_i50 = 0; c11_i50 < 2; c11_i50++) {
      c11_u[c11_i50 + c11_i48] = c11_b_inData[c11_i50 + c11_i48];
    }

    c11_i48 += 2;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_m_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4])
{
  real_T c11_dv6[4];
  int32_T c11_i51;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv6, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c11_i51 = 0; c11_i51 < 4; c11_i51++) {
    c11_y[c11_i51] = c11_dv6[c11_i51];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_A;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[4];
  int32_T c11_i52;
  int32_T c11_i53;
  int32_T c11_i54;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_A = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_A), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_A);
  c11_i52 = 0;
  for (c11_i53 = 0; c11_i53 < 2; c11_i53++) {
    for (c11_i54 = 0; c11_i54 < 2; c11_i54++) {
      (*(real_T (*)[4])c11_outData)[c11_i54 + c11_i52] = c11_y[c11_i54 + c11_i52];
    }

    c11_i52 += 2;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_observador_multirate_2_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c11_nameCaptureInfo;
  c11_ResolvedFunctionInfo c11_info[29];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i55;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29), FALSE);
  for (c11_i55 = 0; c11_i55 < 29; c11_i55++) {
    c11_r0 = &c11_info[c11_i55];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context", "nameCaptureInfo",
                    c11_i55);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name", "nameCaptureInfo",
                    c11_i55);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i55);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)), "resolved",
                    "nameCaptureInfo", c11_i55);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c11_i55);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c11_i55);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c11_i55);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c11_i55);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[29])
{
  c11_info[0].context = "";
  c11_info[0].name = "mtimes";
  c11_info[0].dominantType = "double";
  c11_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[0].fileTimeLo = 1289530492U;
  c11_info[0].fileTimeHi = 0U;
  c11_info[0].mFileTimeLo = 0U;
  c11_info[0].mFileTimeHi = 0U;
  c11_info[1].context = "";
  c11_info[1].name = "mrdivide";
  c11_info[1].dominantType = "double";
  c11_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c11_info[1].fileTimeLo = 1342828944U;
  c11_info[1].fileTimeHi = 0U;
  c11_info[1].mFileTimeLo = 1319744366U;
  c11_info[1].mFileTimeHi = 0U;
  c11_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c11_info[2].name = "rdivide";
  c11_info[2].dominantType = "double";
  c11_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[2].fileTimeLo = 1286836844U;
  c11_info[2].fileTimeHi = 0U;
  c11_info[2].mFileTimeLo = 0U;
  c11_info[2].mFileTimeHi = 0U;
  c11_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[3].name = "eml_div";
  c11_info[3].dominantType = "double";
  c11_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c11_info[3].fileTimeLo = 1313365810U;
  c11_info[3].fileTimeHi = 0U;
  c11_info[3].mFileTimeLo = 0U;
  c11_info[3].mFileTimeHi = 0U;
  c11_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[4].name = "eml_index_class";
  c11_info[4].dominantType = "";
  c11_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[4].fileTimeLo = 1323181378U;
  c11_info[4].fileTimeHi = 0U;
  c11_info[4].mFileTimeLo = 0U;
  c11_info[4].mFileTimeHi = 0U;
  c11_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[5].name = "eml_scalar_eg";
  c11_info[5].dominantType = "double";
  c11_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[5].fileTimeLo = 1286836796U;
  c11_info[5].fileTimeHi = 0U;
  c11_info[5].mFileTimeLo = 0U;
  c11_info[5].mFileTimeHi = 0U;
  c11_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[6].name = "eml_xgemm";
  c11_info[6].dominantType = "char";
  c11_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[6].fileTimeLo = 1299091172U;
  c11_info[6].fileTimeHi = 0U;
  c11_info[6].mFileTimeLo = 0U;
  c11_info[6].mFileTimeHi = 0U;
  c11_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[7].name = "eml_blas_inline";
  c11_info[7].dominantType = "";
  c11_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c11_info[7].fileTimeLo = 1299091168U;
  c11_info[7].fileTimeHi = 0U;
  c11_info[7].mFileTimeLo = 0U;
  c11_info[7].mFileTimeHi = 0U;
  c11_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c11_info[8].name = "mtimes";
  c11_info[8].dominantType = "double";
  c11_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[8].fileTimeLo = 1289530492U;
  c11_info[8].fileTimeHi = 0U;
  c11_info[8].mFileTimeLo = 0U;
  c11_info[8].mFileTimeHi = 0U;
  c11_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[9].name = "eml_index_class";
  c11_info[9].dominantType = "";
  c11_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[9].fileTimeLo = 1323181378U;
  c11_info[9].fileTimeHi = 0U;
  c11_info[9].mFileTimeLo = 0U;
  c11_info[9].mFileTimeHi = 0U;
  c11_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[10].name = "eml_scalar_eg";
  c11_info[10].dominantType = "double";
  c11_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[10].fileTimeLo = 1286836796U;
  c11_info[10].fileTimeHi = 0U;
  c11_info[10].mFileTimeLo = 0U;
  c11_info[10].mFileTimeHi = 0U;
  c11_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[11].name = "eml_refblas_xgemm";
  c11_info[11].dominantType = "char";
  c11_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c11_info[11].fileTimeLo = 1299091174U;
  c11_info[11].fileTimeHi = 0U;
  c11_info[11].mFileTimeLo = 0U;
  c11_info[11].mFileTimeHi = 0U;
  c11_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[12].name = "eml_xdotu";
  c11_info[12].dominantType = "double";
  c11_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c11_info[12].fileTimeLo = 1299091172U;
  c11_info[12].fileTimeHi = 0U;
  c11_info[12].mFileTimeLo = 0U;
  c11_info[12].mFileTimeHi = 0U;
  c11_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c11_info[13].name = "eml_blas_inline";
  c11_info[13].dominantType = "";
  c11_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c11_info[13].fileTimeLo = 1299091168U;
  c11_info[13].fileTimeHi = 0U;
  c11_info[13].mFileTimeLo = 0U;
  c11_info[13].mFileTimeHi = 0U;
  c11_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c11_info[14].name = "eml_xdot";
  c11_info[14].dominantType = "double";
  c11_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c11_info[14].fileTimeLo = 1299091172U;
  c11_info[14].fileTimeHi = 0U;
  c11_info[14].mFileTimeLo = 0U;
  c11_info[14].mFileTimeHi = 0U;
  c11_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c11_info[15].name = "eml_blas_inline";
  c11_info[15].dominantType = "";
  c11_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c11_info[15].fileTimeLo = 1299091168U;
  c11_info[15].fileTimeHi = 0U;
  c11_info[15].mFileTimeLo = 0U;
  c11_info[15].mFileTimeHi = 0U;
  c11_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c11_info[16].name = "eml_index_class";
  c11_info[16].dominantType = "";
  c11_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[16].fileTimeLo = 1323181378U;
  c11_info[16].fileTimeHi = 0U;
  c11_info[16].mFileTimeLo = 0U;
  c11_info[16].mFileTimeHi = 0U;
  c11_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c11_info[17].name = "eml_refblas_xdot";
  c11_info[17].dominantType = "double";
  c11_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c11_info[17].fileTimeLo = 1299091172U;
  c11_info[17].fileTimeHi = 0U;
  c11_info[17].mFileTimeLo = 0U;
  c11_info[17].mFileTimeHi = 0U;
  c11_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c11_info[18].name = "eml_refblas_xdotx";
  c11_info[18].dominantType = "char";
  c11_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[18].fileTimeLo = 1299091174U;
  c11_info[18].fileTimeHi = 0U;
  c11_info[18].mFileTimeLo = 0U;
  c11_info[18].mFileTimeHi = 0U;
  c11_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[19].name = "eml_scalar_eg";
  c11_info[19].dominantType = "double";
  c11_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[19].fileTimeLo = 1286836796U;
  c11_info[19].fileTimeHi = 0U;
  c11_info[19].mFileTimeLo = 0U;
  c11_info[19].mFileTimeHi = 0U;
  c11_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[20].name = "eml_index_class";
  c11_info[20].dominantType = "";
  c11_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[20].fileTimeLo = 1323181378U;
  c11_info[20].fileTimeHi = 0U;
  c11_info[20].mFileTimeLo = 0U;
  c11_info[20].mFileTimeHi = 0U;
  c11_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[21].name = "eml_index_minus";
  c11_info[21].dominantType = "double";
  c11_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c11_info[21].fileTimeLo = 1286836778U;
  c11_info[21].fileTimeHi = 0U;
  c11_info[21].mFileTimeLo = 0U;
  c11_info[21].mFileTimeHi = 0U;
  c11_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c11_info[22].name = "eml_index_class";
  c11_info[22].dominantType = "";
  c11_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[22].fileTimeLo = 1323181378U;
  c11_info[22].fileTimeHi = 0U;
  c11_info[22].mFileTimeLo = 0U;
  c11_info[22].mFileTimeHi = 0U;
  c11_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[23].name = "eml_index_times";
  c11_info[23].dominantType = "coder.internal.indexInt";
  c11_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c11_info[23].fileTimeLo = 1286836780U;
  c11_info[23].fileTimeHi = 0U;
  c11_info[23].mFileTimeLo = 0U;
  c11_info[23].mFileTimeHi = 0U;
  c11_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c11_info[24].name = "eml_index_class";
  c11_info[24].dominantType = "";
  c11_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[24].fileTimeLo = 1323181378U;
  c11_info[24].fileTimeHi = 0U;
  c11_info[24].mFileTimeLo = 0U;
  c11_info[24].mFileTimeHi = 0U;
  c11_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[25].name = "eml_index_plus";
  c11_info[25].dominantType = "coder.internal.indexInt";
  c11_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c11_info[25].fileTimeLo = 1286836778U;
  c11_info[25].fileTimeHi = 0U;
  c11_info[25].mFileTimeLo = 0U;
  c11_info[25].mFileTimeHi = 0U;
  c11_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c11_info[26].name = "eml_index_class";
  c11_info[26].dominantType = "";
  c11_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[26].fileTimeLo = 1323181378U;
  c11_info[26].fileTimeHi = 0U;
  c11_info[26].mFileTimeLo = 0U;
  c11_info[26].mFileTimeHi = 0U;
  c11_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[27].name = "eml_int_forloop_overflow_check";
  c11_info[27].dominantType = "";
  c11_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c11_info[27].fileTimeLo = 1332183072U;
  c11_info[27].fileTimeHi = 0U;
  c11_info[27].mFileTimeLo = 0U;
  c11_info[27].mFileTimeHi = 0U;
  c11_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c11_info[28].name = "intmax";
  c11_info[28].dominantType = "char";
  c11_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c11_info[28].fileTimeLo = 1311273316U;
  c11_info[28].fileTimeHi = 0U;
  c11_info[28].mFileTimeLo = 0U;
  c11_info[28].mFileTimeHi = 0U;
}

static void c11_eml_scalar_eg(SFc11_observador_multirate_2InstanceStruct
  *chartInstance)
{
}

static void c11_b_eml_scalar_eg(SFc11_observador_multirate_2InstanceStruct
  *chartInstance)
{
}

static void c11_check_forloop_overflow_error
  (SFc11_observador_multirate_2InstanceStruct *chartInstance)
{
}

static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static int32_T c11_n_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i56;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i56, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i56;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
    chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_o_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_observador_multirate_2,
  const char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_observador_multirate_2), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_observador_multirate_2);
  return c11_y;
}

static uint8_T c11_p_emlrt_marshallIn(SFc11_observador_multirate_2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_observador_multirate_2InstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c11_observador_multirate_2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1571329895U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(22293479U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2782328670U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(844883591U);
}

mxArray *sf_c11_observador_multirate_2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("lm2tOesMUEWU8G1FcqWPfC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c11_observador_multirate_2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[10],T\"x_hat\",},{M[1],M[11],T\"y_hat\",},{M[4],M[0],T\"C\",S'l','i','p'{{M1x2[118 119],M[0],}}},{M[4],M[0],T\"D\",S'l','i','p'{{M1x2[136 137],M[0],}}},{M[4],M[0],T\"t\",S'l','i','p'{{M1x2[100 101],M[0],}}},{M[4],M[0],T\"x\",S'l','i','p'{{M1x2[82 83],M[0],}}},{M[8],M[0],T\"is_active_c11_observador_multirate_2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_observador_multirate_2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_observador_multirate_2InstanceStruct *chartInstance;
    chartInstance = (SFc11_observador_multirate_2InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_observador_multirate_2MachineNumber_,
           11,
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
          init_script_number_translation(_observador_multirate_2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_observador_multirate_2MachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_observador_multirate_2MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"new_sens");
          _SFD_SET_DATA_PROPS(3,1,1,0,"clock");
          _SFD_SET_DATA_PROPS(4,2,0,1,"x_hat");
          _SFD_SET_DATA_PROPS(5,2,0,1,"y_hat");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,688);
        _SFD_CV_INIT_EML_IF(0,1,0,144,200,-1,278);
        _SFD_CV_INIT_EML_IF(0,1,1,285,302,494,622);

        {
          static int condStart[] = { 147, 161, 175, 189 };

          static int condEnd[] = { 157, 171, 185, 199 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2, 3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,147,199,4,0,&(condStart[0]),&(condEnd[0]),
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
          (MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_g_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_f_sf_marshallOut,(MexInFcnForType)
            c11_f_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)
          c11_e_sf_marshallIn);

        {
          real_T *c11_u;
          real_T *c11_y;
          boolean_T *c11_new_sens;
          real_T *c11_clock;
          real_T *c11_y_hat;
          real_T (*c11_x_hat)[2];
          c11_y_hat = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c11_x_hat = (real_T (*)[2])ssGetOutputPortSignal(chartInstance->S, 1);
          c11_clock = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c11_new_sens = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c11_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_new_sens);
          _SFD_SET_DATA_VALUE_PTR(3U, c11_clock);
          _SFD_SET_DATA_VALUE_PTR(4U, *c11_x_hat);
          _SFD_SET_DATA_VALUE_PTR(5U, c11_y_hat);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_observador_multirate_2MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "92Sx4E8MBzVcqDPN17aZ3G";
}

static void sf_opaque_initialize_c11_observador_multirate_2(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_observador_multirate_2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_observador_multirate_2
    ((SFc11_observador_multirate_2InstanceStruct*) chartInstanceVar);
  initialize_c11_observador_multirate_2
    ((SFc11_observador_multirate_2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_observador_multirate_2(void *chartInstanceVar)
{
  enable_c11_observador_multirate_2((SFc11_observador_multirate_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_observador_multirate_2(void *chartInstanceVar)
{
  disable_c11_observador_multirate_2((SFc11_observador_multirate_2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_observador_multirate_2(void *chartInstanceVar)
{
  sf_c11_observador_multirate_2((SFc11_observador_multirate_2InstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_observador_multirate_2
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_observador_multirate_2
    ((SFc11_observador_multirate_2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_observador_multirate_2();/* state var info */
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

extern void sf_internal_set_sim_state_c11_observador_multirate_2(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_observador_multirate_2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_observador_multirate_2
    ((SFc11_observador_multirate_2InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_observador_multirate_2
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c11_observador_multirate_2(S);
}

static void sf_opaque_set_sim_state_c11_observador_multirate_2(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c11_observador_multirate_2(S, st);
}

static void sf_opaque_terminate_c11_observador_multirate_2(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_observador_multirate_2InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c11_observador_multirate_2
      ((SFc11_observador_multirate_2InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_observador_multirate_2_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_observador_multirate_2
    ((SFc11_observador_multirate_2InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_observador_multirate_2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_observador_multirate_2
      ((SFc11_observador_multirate_2InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_observador_multirate_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_observador_multirate_2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,11,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,2);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1526877239U));
  ssSetChecksum1(S,(2134652067U));
  ssSetChecksum2(S,(46643944U));
  ssSetChecksum3(S,(3826169746U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_observador_multirate_2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_observador_multirate_2(SimStruct *S)
{
  SFc11_observador_multirate_2InstanceStruct *chartInstance;
  chartInstance = (SFc11_observador_multirate_2InstanceStruct *)malloc(sizeof
    (SFc11_observador_multirate_2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_observador_multirate_2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_observador_multirate_2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_observador_multirate_2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_observador_multirate_2;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_observador_multirate_2;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_observador_multirate_2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_observador_multirate_2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_observador_multirate_2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_observador_multirate_2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_observador_multirate_2;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_observador_multirate_2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_observador_multirate_2;
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

void c11_observador_multirate_2_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_observador_multirate_2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_observador_multirate_2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_observador_multirate_2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_observador_multirate_2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
