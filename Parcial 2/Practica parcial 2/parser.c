#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int parser_EempleadoFromText(FILE* pFile , LinkedList* pArrayListEempleado)
{
    char buffer[5][20];
    Eempleado* newEempleado;
    int cant;
    int retorno;

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

    while( !feof(pFile) )
    {
        newEempleado=Eempleado_new();

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3],buffer[4]);

        if( cant == 5)
        {

         newEempleado = Eempleado_newParametros(buffer[0], buffer[1],buffer[2],buffer[3],buffer[4]);

         ll_add(pArrayListEempleado,newEempleado);
         retorno=1;

        }
        else
        {
            retorno=-1;

        }

    }

    return retorno;
}
