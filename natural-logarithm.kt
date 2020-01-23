import kotlin.math.abs
import kotlin.math.exp
import kotlin.math.ln

val EPS = 0.00001

fun f(x: Double, a: Double) : Double {

	return exp(x) - a
}

fun DivideEtImpera(lo: Double, hi: Double, a: Double) : Double {
	
    if(abs(lo - hi) < EPS) {

       return (lo + hi) / 2.0 

    } else {

      val m:Double = (lo + hi) / 2.0 

      if(f(m,a)*f(lo,a) < 0) return DivideEtImpera(lo, m, a)

                   else      return  DivideEtImpera(m, hi, a)
    }    
}

fun _ln(a: Double) : Double {
	 
    return DivideEtImpera(0.0, a, a) 

}

fun main(arr: Array<String>) {
	
	var a: Double = 5.0

	println(_ln(a))
	println(ln(a))
}
