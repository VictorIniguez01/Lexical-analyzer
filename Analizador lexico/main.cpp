#include "scanner.hpp"
#include <iostream>


using namespace std;


extern FILE *yyin;      
extern int yylex();     
extern char *yytext;
extern int line;


int main(){

    string archivo;
    // test.txt
    printf("Nombre del archivo de texto: ");
    cin >> archivo;
    printf("\n");

    yyin = fopen(archivo.c_str(), "r");

    if(yyin == nullptr) {
        printf("Archivo no encontrado\n");
        return 0;
    }

    int token;

    do{

        token = yylex();

        switch(token){

            case _ptcoma:  printf("ptcoma [%s]\n", yytext); break;
            case _dospts:  printf("dospts [%s]\n", yytext); break;
            case _interr:  printf("interr [%s]\n", yytext); break;
            case _condi:  printf("condi [%s]\n", yytext); break;
            case _or:  printf("or [%s]\n", yytext); break;
            case _and:  printf("and [%s]\n", yytext); break;
            case _not:  printf("not [%s]\n", yytext); break;
            case _igual:  printf("igual [%s]\n", yytext); break;
            case _nigual:  printf("nigual [%s]\n", yytext); break;
            case _dparen:  printf("dparen [%s]\n", yytext); break;
            case _iparen:  printf("iparen [%s]\n", yytext); break;
            case _false:   printf("false [%s]\n", yytext); break;
            case _true: printf("true [%s]\n", yytext); break;
            case _result:  printf("result [%s]\n", yytext); break;
            case _id:   printf("id [%s]\n", yytext); break;
            case _of:   printf("Fin del analisis\nLineas leidas: %i", line); break;
            case _err:  printf("err [%s]\n", yytext);

            default:    printf("WTF\n");
        }

    }while(token != _err && token != _of);

    fclose(yyin);

    return 0;
}