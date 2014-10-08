#ifndef __c24_observador_multirate_h__
#define __c24_observador_multirate_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc24_observador_multirateInstanceStruct
#define typedef_SFc24_observador_multirateInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_observador_multirate;
} SFc24_observador_multirateInstanceStruct;

#endif                                 /*typedef_SFc24_observador_multirateInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c24_observador_multirate_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_observador_multirate_get_check_sum(mxArray *plhs[]);
extern void c24_observador_multirate_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
