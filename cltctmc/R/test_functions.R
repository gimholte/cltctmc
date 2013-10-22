hypgeo_test <- function(x, n){
	suppressWarnings(.Call( "hypgeo_test", as.double(x), 
			as.double(rep(0.0, n + 1)),
			PACKAGE = "cltctmc" ))
}

pclt_test <- function(t, l1, l2, nmax) {
    suppressWarnings(.Call("pclt_test", as.double(c(t, l1, l2)),
            as.double(rep(0.0, nmax + 1)),
            PACKAGE = "cltctmc"))	
}

tree_class_test <- function(tree, l1, l2, nmax) {
    .Call("treeCltSum", tree$edge, tree$edge.length,
            tree$tip.state, l1, l2, nmax, PACKAGE = "cltctmc")
}


