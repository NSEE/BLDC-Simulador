#ifndef __c11_observador_multirate_2_h__
#define __c11_observador_multirate_2_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c11_ResolvedFunctionInfo
#define typedef_c11_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c11_ResolvedFunctionInfo;

#endif                                 /*typedef_c11_ResolvedFunctionInfo*/

#ifndef typedef_SFc11_observador_multirate_2InstanceStruct
#define typedef_SFc11_observador_multirate_2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_observador_multirate_2;
  real_T c11_x[2];
  boolean_T c11_x_not_empty;
  real_T c11_t;
  boolean_T c11_t_not_empty;
  real_T c11_C[2];
  boolean_T c11_C_not_empty;
  real_T c11_D;
  boolean_T c11_D_not_empty;
} SFc11_observador_multirate_2InstanceStruct;

#endif                                 /*typedef_SFc11_observador_multirate_2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c11_observador_multirate_2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c11_observador_multirate_2_get_check_sum(mxArray *plhs[]);
extern void c11_observador_multirate_2_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
