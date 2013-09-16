#ifndef _cltctmc_RCPP_HELLO_WORLD_H
#define _cltctmc_RCPP_HELLO_WORLD_H

#include <Rcpp.h>
#include <R.h>
#include <cmath>
using namespace Rcpp;

void pclt(double t, double la, double lb, NumericVector & result);
void hypgeo_1f1_array(const double x, const int kmax, NumericVector & result);
RcppExport SEXP hypgeo_test(SEXP rx, SEXP rk, SEXP rout);

#endif
