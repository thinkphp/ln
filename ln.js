
  DOMHelp = {

          $: function( id ){ return document.getElementById( id ) },

          addEvent: function(elem,evType,fn,useCapture) {

                  if(elem.addEventListener) {

                        elem.addEventListener(evType,fn,useCapture); 

                  }  else if(elem.attachEvent) {
 
                     var r = elem.attachEvent('on'+evType,fn);

                     return r; 
 
                  } else {

                     elem['on'+evType] = fn;
                  }
          },

          getTarget: function(e) {

                  var target = window.event ? window.event.srcElement : e ? e.target : null;

                      while(target.parentNode.nodeType != 3 && target.nodeName.toLowerCase() != "body") {

                            target = target.parentNode; 
                      }

                      if(!target) {return false;}

                   return target;

          },

          cancelClick: function(e) {

                 if(window.event) {

                     window.event.cancelBubble = true;

                     window.event.returnValue = false;
                 }

                 if(e && e.stopPropagation && e.preventDefault) {

                     e.stopPropagation();

                     e.preventDefault();
                 }
          },

          trim: function(s) {
 
                return s.replace(/^\s+/,"").replace(/\s+$/,""); 
          }


  };

  function ln(a,li,ls){

       if(a <= 0) {return "invalid input for function";}

       if(a == 1) {return 0;}

       if(Math.abs(li-ls) < 0.00000001) {return (li+ls)/2;}

       if( (Math.exp(li)-a)*( Math.exp((li+ls)/2) - a) < 0 ) return ln(a,li,(li+ls)/2);

                                              else

                                                                    return ln(a,(li+ls)/2,ls);   
  
  }

  function solve() {

      var input = DOMHelp.$('input').value; 

          input = DOMHelp.trim(input);

          if(input == "") {$('output').innerHTML="Empty!";return;} 

      var a;

          if(isNaN(input)) {DOMHelp.$('output').innerHTML="Error! Is Not a Number";return;}
                     
          a = parseFloat(input);

          document.getElementById('input').value = a

      var output = ln(a, 0, a)

          DOMHelp.$('output').innerHTML =  "ln(" + a + ") = " + output; 
  }


  function init() {

           DOMHelp.addEvent(DOMHelp.$("solve"),'click',solve,false);

  }

  DOMHelp.addEvent(window,'load',init,false);