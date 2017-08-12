/**
 * 
 *         x 
 * f(x) = e - a, f : (0,a) --> R
 *
 *   x  
 *  e - a = 0
 */

#include <stdio.h>
#include <math.h>
#define EPS 0.00001


double DivideEtImpera(double n, double lo, double hi) {

       if( fabs(lo - hi) < EPS ) {

           return (lo + hi)/2.0; 

       } else if( (exp(lo) - n) * ( exp( (lo + hi)/2.0 ) - n ) < 0 ) {

              return DivideEtImpera(n, lo, ( (lo + hi)/2.0 ));

       } else {

              return DivideEtImpera(n, ( (lo + hi)/2.0 ), hi);
       }
}

double ln(double n) {

       if( n <= 0 ) return;

       if( n == 1) return 0; 

        else 

          return DivideEtImpera(n, 0, n); 
       
}

int main() {

    float n;

    printf("n=");
    scanf("%f", &n);

    printf("ln(%.1f) = %.5f\n", n, ln(n));
    printf("ln(%.1f) = %.5f", log(n));

 return(0);  
}