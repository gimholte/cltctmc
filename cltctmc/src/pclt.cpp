#include "pclt.h"
using namespace Rcpp;

void pclt(double t, double la, double lb, NumericVector & result){
	int kmax = (int) std::ceil((result.size() - 1.0) / 2);
	return ;
}

void hypgeo_1f1_array(const double x, const int kmax, NumericVector & result) {
	double bp1, b, bm1;
	const double y = x / 2.0;
	const double lx = std::log(.25 * x);
	/*
	 * Use the bessel function linear difference equation
	 * and the gamma function recursion to propogate down
	 * to k = 1 case.
	 */

	bp1 = R::bessel_i(y, kmax - .5, 2.0);
	b = R::bessel_i(y, kmax - 1.5, 2.0);

	double lgk = R::lgammafn(kmax + .5);
	result[2 * kmax] = std::log(bp1) + lgk + (.5 - kmax) * lx + x;
	if (kmax == 1) return;

	lgk = lgk - std::log(kmax - 1 + .5);
	result[2 * (kmax - 1)] = std::log(b) + lgk + (.5 - kmax + 1) * lx + x;
	if (kmax == 2) return;

	for(int k = kmax - 2; k >= 1; k--) {
		bm1 = bp1 + (2.0 * k + 1.0) * b / y;
		lgk = lgk - std::log(k + .5);
		result[2 * k] = std::log(bm1) + lgk + (.5 - k) * lx + x;
		bp1 = b;
		b = bm1;
	}
	return;
}

RcppExport SEXP hypgeo_test(SEXP rx, SEXP rk, SEXP rout) {
	NumericVector x(rx);
	IntegerVector k(rk);
	NumericVector out(rout);
	hypgeo_1f1_array(x[0], k[0], out);
	return out;
}
