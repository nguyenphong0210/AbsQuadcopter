/*
 * File: rt_modd_snf.c
 *
 * Code generated for Simulink model 'nonlinearAirframe'.
 *
 * Model version                  : 1.155
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Sun Nov 19 00:07:34 2023
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <math.h>
#include "rt_modd_snf.h"

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T yEq;
  real_T q;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else {
      if ((u0 < 0.0) != (u1 < 0.0)) {
        y += u1;
      }
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
