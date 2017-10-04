def f x,a
    Math.exp(x)-a
end

def ln a
    lo, hi = 0, a
    anEPS = 0.0001    
    while (lo-hi).abs >= anEPS 
           m = ((lo+hi)/2.0).to_f
           if f(m,a) < 0 
              lo = m 
           else
              hi = m
           end
    end
    ((lo+hi)/2.0).to_f
end

class NatLog

      def initialize( number )
          @a = number 
      end

      def f(x,a)
          Math.exp(x)-a
      end    

      def compute    
         lo, hi = 0, @a
         anEPS = 0.0001
         while (lo-hi).abs >= anEPS 
                m = ((lo+hi)/2.0).to_f
                    if self.f(m, @a) < 0 
                       lo = m 
                    else
                       hi = m
                    end
         end
        ((lo+hi)/2.0).to_f 
      end 
end

p Math.log(9)
p ln(9)
ob = NatLog.new(9)
p ob.compute