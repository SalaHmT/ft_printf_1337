———————————————————————————————————————————————————————————————------------------------------                  
|Variadic functions in C|          :->                                                                 
———————————————————————————————————————————————————————————————------------------------------             
1- Variadic functions are functions that can take a variable number of                       
arguments. In C programming, a variadic function adds flexibility to the                    
program. It takes one fixed argument and then any number of arguments can                    
be passed.                                                                                    
The variadic function consists of at least one fixed variable and then                       
an ellipsis(…) as the last parameter. 
———————————————————————————————————————————————————————————————------------------------------        
header file :	#include <stdarg.h>                                                                
———————————————————————————————————————————————————————————————------------------------------
<stdarg.h> includes the following methods:                                                  
va_start(va_list ap, argN) : va_start(va_list ap, argN)                                      
va_arg(va_list ap, type) : This one accesses the next variadic function argument.            
va_end(va_list ap) : This ends the traversal of the variadic function arguments.
—————————————————————————————————————————————————————————————————————————————----------------  
