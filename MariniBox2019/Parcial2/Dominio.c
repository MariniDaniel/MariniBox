#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dominio.h"
#include <ctype.h>
#include "UTN_INPUT.h"


eDominio* eDominio_new()
{
    eDominio* newDominio = (eDominio*)malloc(sizeof(eDominio));

    if(newDominio!=NULL)
    {
        newDominio->tipo='0';
        newDominio->anio= 0;
        newDominio->id= 0;
        strcpy(newDominio->dominio,"");
    }

    return newDominio;
}


eDominio* eDominio_newParametros(char* idStr,char* dominioStr,char* anioStr)
{
    eDominio* newDominioParam = eDominio_new();
    int retorno = 0;

    if(newDominioParam != NULL)
    {
        if(eDominio_setId(newDominioParam, atoi(idStr) ) )
        {
            if(eDominio_setDominio(newDominioParam, dominioStr))
            {
                if(eDominio_setAnio(newDominioParam, atoi(anioStr)) )
                {
                    retorno = 1;
                }
            }
        }

        if(retorno == 0)
        {
            free(newDominioParam);
            newDominioParam = NULL;
        }
    }
    return newDominioParam;
}


int eDominio_setAnio(eDominio* this,int anio)
{
    int retorno =0;

    if(this != NULL )
    {
        this->anio = anio;

        retorno=1;
    }

    return retorno;
}


int eDominio_getAnio(eDominio* this,int* anio)
{
    int retorno =0;

    if(this!=NULL && anio!=NULL)
    {
        *anio=this->anio;

        retorno=1;
    }

    return retorno;
}


int eDominio_setId(eDominio* this,int id)
{
    int retorno =0;

    if(this != NULL)
    {
        this->id = id;
        retorno=1;
    }

    return retorno;
}


int eDominio_getId(eDominio* this,int* id)
{
    int retorno =0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;

        retorno=1;
    }

    return retorno;
}


int eDominio_setDominio(eDominio* this,char* dominio)
{
    int retorno =0;

    if(this != NULL && dominio!=NULL)
    {

        strcpy(this->dominio,dominio);
        retorno=1;
    }

    return retorno;
}


int eDominio_getDominio(eDominio* this,char* dominio)
{
    int retorno =0;

    if(this != NULL && dominio!=NULL)
    {
        strcpy(dominio,this->dominio);

        retorno=1;
    }

    return retorno;
}


int eDominio_setTipo(eDominio* this,char tipo)
{
    int retorno =0;

    if(this != NULL )
    {
        this->tipo = tipo;
        retorno=1;
    }

    return retorno;
}


int eDominio_getTipo(eDominio* this,char* tipo)
{
    int retorno=0;

    if(this!=NULL && tipo!=NULL)
    {
        *tipo=this->tipo;

        retorno=1;
    }

    return retorno;
}


int eDominio_mapearTipo(void* pElement)
{
    int retorno = -1;
    eDominio* auxeDominio;
    char auxDominio[20];


    if(pElement != NULL)
    {
        auxeDominio = (eDominio*) pElement;

        eDominio_getDominio(auxeDominio,auxDominio);

        if(isalpha(auxDominio[0])!=0)
        {

            eDominio_setTipo(auxeDominio,'A');
            retorno=1;
        }
        else
        {
            eDominio_setTipo(auxeDominio,'M');
            retorno=1;
        }

    }
    return retorno;
}

int eDominio_filtrarMoto(void* pElement)
{
    int retorno = -1;
    eDominio* auxEdominio;
    char auxTipo;

    if(pElement != NULL)
    {
        auxEdominio = (eDominio*) pElement;
        eDominio_getTipo(auxEdominio,&auxTipo);
        if(auxTipo=='M')
        {
            retorno = 1;
        }
    }
    return retorno;
}

int eDominio_filtrarAuto(void* pElement)
{
    int retorno = -1;
    eDominio* auxEdominio;
    char auxTipo;

    if(pElement != NULL)
    {
        auxEdominio = (eDominio*) pElement;
        eDominio_getTipo(auxEdominio,&auxTipo);

        if(auxTipo=='A')
        {
            retorno = 1;
        }
    }
    return retorno;
}

