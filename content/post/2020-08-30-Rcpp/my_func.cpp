#include <Rcpp.h>
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
NumericMatrix func_Rcpp(int x) {
  // NumericMatrix() is the Rcpp analogue to R's matrix()
  NumericMatrix M = NumericMatrix(x); 
  
  // In C++ indexing starts at zero, not one
  for(int row = 0; row < x; row++) {
    for(int col = 0; col < x; col++) {
      for(int m=0; m <= min(row,col); m++) {
        // C++ allows: "a += b" as shorthand for "a = a + b"
        M(row,col) += R::dpois(col-m, 1, false) *
          R::dbinom(m, row, 0.75, false);
      }
    }  
  }
  
  return M;
}
