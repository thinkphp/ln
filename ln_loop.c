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
#define f(x,a) exp(x) - a


double computesLN(double n, double lo, double hi) {
 
       double a = lo, b = hi, m;

       while( fabs(a - b) > EPS ) {

              m = (a + b) / 2.0;

              if( (exp( m ) - n) < 0) a = m;
 
                             else 
                                      b = m;                
       }

       return (a+b)/2.0;
       
}


double computesLN2(double n, double lo, double hi) {
 
       double a = lo, b = hi, m;

       while( fabs(a - b) > EPS ) {

              m = (a + b) / 2.0;

              if( (f( m, n) ) < 0) a = m;
 
                             else 

                                   b = m;                
       }

       return (a+b)/2.0;
       
}

double ln(double n) {

       if( n <= 0 ) return;

       if( n == 1) return 0; 

        else 

          return computesLN(n, 0, n);        
}


double ln2(double n) {

       if( n <= 0 ) return;

       if( n == 1) return 0; 

        else 

          return computesLN2(n, 0, n);        
}

int main() {

    float n;

    printf("n=");
    scanf("%f", &n);

    printf("ln(%.1f) = %.5f\n", n, ln(n));
    printf("ln(%.1f) = %.5f\n", n, ln2(n));
    printf("ln(%.1f) = %.5f <-- Built-in function", n, log(n));

 return(0);  
}