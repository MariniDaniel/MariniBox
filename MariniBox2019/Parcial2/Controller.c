#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Dominio.h"
#include "parser.h"
#include "UTN_INPUT.h"

int controller_listExist(LinkedList* pArrayListeDominio)
{
    int existe = -1;

    if(ll_len(pArrayListeDominio)>0)
    {
        existe = 1;
    }

    return existe;
}


int controller_loadFromText(char* path,LinkedList* pArrayListeDominio)
{

    int retorno=-1;
    FILE* Pfile = fopen(path,"r");

    if(Pfile!=NULL&& pArrayListeDominio !=NULL)
    {
        if(parser_DominioFromText(Pfile,pArrayListeDominio))
        {

            retorno=1;

        }

        else
        {
            retorno =-1;
        }

    }

    else
    {
        retorno =-1;
    }

    fclose(Pfile);
    free(Pfile);


    return retorno;
}


int controller_ListDominio(LinkedList* pArrayListeDominio)
{
    eDominio* auxDominio = eDominio_new();
    int idAuxiliar;
    char dominioAuxiliar[50];
    int anioAuxiliar;
    char tipoAuxiliar;
    int retorno=-1;
    int i;

    if(auxDominio!=NULL && pArrayListeDominio!=NULL)
    {
        system("cls");
        puts(" [ID]\t[DOMINIO]\t[ANIO]\t[TIPO]\n\n");

        for(i=0; i < ll_len(pArrayListeDominio); i++)
        {
            auxDominio = ll_get(pArrayListeDominio, i);

            eDominio_getId(auxDominio, &idAuxiliar);
            eDominio_getDominio(auxDominio,dominioAuxiliar);
            eDominio_getAnio(auxDominio,&anioAuxiliar);
            eDominio_getTipo(auxDominio,&tipoAuxiliar);

            printf("%5d  %10s %10d  %5c\n",idAuxiliar, dominioAuxiliar, anioAuxiliar, tipoAuxiliar);

        }

        retorno=1;
    }

    else
    {
        retorno=-1;
    }

    printf("\n\n");

    return retorno;
}



int controller_saveAsText(char* path, LinkedList* pArrayListeDominio)
{
    int retorno=-1;
    int len;
    int idAuxiliar;
    char dominioAuxiliar[50];
    int anioAuxiliar;
    char tipoAuxiliar;
    int i;
    FILE* Pfile = fopen(path,"w+");
    eDominio* auxEdominio=eDominio_new();

    if(Pfile != NULL && pArrayListeDominio != NULL && auxEdominio!=NULL )
    {
        len=ll_len(pArrayListeDominio);
        fprintf(Pfile, "id,dominio,anio,tipo\n");

        for(i=0; i<len; i++)
        {
            auxEdominio= ll_get(pArrayListeDominio,i);

            eDominio_getId(auxEdominio, &idAuxiliar);
            eDominio_getDominio(auxEdominio,dominioAuxiliar);
            eDominio_getAnio(auxEdominio,&anioAuxiliar);
            eDominio_getTipo(auxEdominio,&tipoAuxiliar);

            fprintf(Pfile,"%d,%s,%d,%c\n",idAuxiliar,dominioAuxiliar,anioAuxiliar,tipoAuxiliar);

        }

        retorno = 1;

    }
    else
    {
        retorno=-1;
    }

    fclose(Pfile);

    return retorno;
}


int controller_mapEmployee(LinkedList* pArrayListeDominio)
{
    int retorno=1;

    if(pArrayListeDominio!=NULL)
    {

        if(ll_map(pArrayListeDominio,eDominio_mapearTipo))
        {
        retorno=1;

        }
        else
        {
            retorno=-1;
        }

    }
    else
    {
        retorno=-1;
    }

    return retorno;
}
