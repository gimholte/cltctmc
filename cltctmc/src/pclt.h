#ifndef _cltctmc_PCLT_H
#define _cltctmc_PCLT_H

#include <Rcpp.h>
#include <R.h>
#include <Rmath.h>
using namespace Rcpp;

double logspaceAdd(const double loga, const double logb);
double logspaceSubtract(const double loga, const double logb);
void hypgeoF11_k_2k(const double x, NumericVector & result, double * work_bi);
void hypgeoF11_kp1_2kp1(const double x, NumericVector & result, const double * work_bi);
void hypgeoF11_kp1_2kp1(const double x, NumericVector & result, const double * work_bi);
void pclt(const double t, const double lambda_1, const double lambda_2,
        NumericVector & result);

RcppExport SEXP hypgeo_test(SEXP rx, SEXP rout);
RcppExport SEXP pclt_test(SEXP rpar, SEXP rout);
#endif
