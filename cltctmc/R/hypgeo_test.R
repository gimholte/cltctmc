hypgeo_test <- function(x, kmax){
	.Call( "hypgeo_test", as.double(x), as.integer(kmax), 
			as.double(rep(0.0, 2*kmax + 1)),
			PACKAGE = "cltctmc" )
}
library(cltctmc)
library(hypergeo)
x = 3.4
k = 4
hypgeo_test(x, k)
log(genhypergeo(k, 2*k, x))
log(genhypergeo(1, 2, x))
log(genhypergeo(2, 4, x))