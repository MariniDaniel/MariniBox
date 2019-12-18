#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Dominio.h"
#include "parser.h"

int parser_DominioFromText(FILE* pFile, LinkedList* pArrayListeDominio)
{
    char buffer[3][20];

    eDominio* newDominio;
    int cant;
    int retorno;

    fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

    while( !feof(pFile) )
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", buffer[0],  buffer[1], buffer[2]);

        if( cant == 3)
        {

            newDominio = eDominio_newParametros(buffer[0],buffer[1],buffer[2]);

            ll_add(pArrayListeDominio,newDominio);
            retorno=1;

        }
        else
        {
            retorno=-1;

        }

    }

    return retorno;
}

