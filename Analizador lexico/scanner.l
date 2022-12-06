%{


#include "scanner.hpp"
int line = 1;


%}


A               [a-zA-Z]
N               [0-9]


ptcoma          ";"
dospts          ":"
interr          "?"
dparen          ")"
iparen          "("
igual           "="
nigual          "!="
condi           "->"
true            "true"
false           "false"
or              "or"
and             "and"
not             "not"
result           "<<"

id              ({A}|_(_|{N})*{A})({A}|{N}|[_])*("'")?

sp              [ \t]
nl              \n


%%


{ptcoma}        return _ptcoma;
{dospts}        return _dospts;
{interr}        return _interr;
{condi}         return _condi;

{true}          return _true;
{false}         return _false;
{or}            return _or;
{and}           return _and;
{not}           return _not;

{igual}         return _igual;
{nigual}        return _nigual;
{dparen}        return _dparen;
{iparen}        return _iparen;

{result}           return _result;

{sp}            ;
{nl}            line++;

{id}            return _id;
                

<<EOF>>         return _of;      

.               {
                    printf("Error en la linea %i\n", line);
                    return _err;
                }


%%


int yywrap() {  return 1; }