#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llamada.h"
#include "Validaciones.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** Llamada New New Parameters**/
sLlamada* llamada_new()
{
    sLlamada* pLlamada = (sLlamada *) calloc ( 1 , sizeof (sLlamada));
    if(pLlamada == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }
    return pLlamada;
}

sLlamada* llamada_newParametros(char* idLlamadaaStr, char* fechaStr, char* numeroClienteStr, char* idProblemaStr, char* solucionadoStr)
{
    sLlamada* pLlamada;
    sLlamada* ret = NULL;
    int idLlamada;
    int numeroCliente;
    int idProblema;
    if(idLlamadaaStr != NULL && fechaStr != NULL && numeroClienteStr != NULL && idProblemaStr != NULL && solucionadoStr != NULL)
    {
        pLlamada = llamada_new();
        idLlamada = atoi(idLlamadaaStr);
        numeroCliente = atoi(numeroClienteStr);
        idProblema = atoi(idProblemaStr);
        if(llamada_setIdLlamada(pLlamada, idLlamada)&&
            llamada_setFecha(pLlamada, fechaStr)&&
            llamada_setNumeroCliente(pLlamada, numeroCliente)&&
            llamada_setIdProblema(pLlamada, idProblema)&&
            llamada_setSolucionado(pLlamada,solucionadoStr))
        {
            ret = pLlamada;
        }
        else
        {
            llamada_delete(pLlamada);
        }
    }
    return ret;
}


int llamada_delete(sLlamada* this)
{
    int retorno = -1;

    if (this!=NULL )
    {
        free(this);
        retorno = RETURN_OK;
    }
    return retorno;
}

/** Get y Set Id Llamada **/
int llamada_setIdLlamada(sLlamada* this, int idLlamada)
{
    int ret;
    ret = RETURN_ERROR;

    if(idLlamada > 0 && this != NULL && isValidInt(idLlamada, 0, 1000))
    {
        this->idLlamada = idLlamada;
        ret = RETURN_OK;
    }
    return ret;
}

int llamada_getIdLlamada(sLlamada* this, int* idLlamada)
{
    int ret;
    ret = RETURN_ERROR;
    if(idLlamada != NULL && this != NULL)
    {
        *idLlamada = this->idLlamada;
        ret = RETURN_OK;
    }
    return ret;
}

/** Get y Set Fecha **/
int llamada_setFecha(sLlamada* this, char* fecha)
{
    int ret = RETURN_ERROR;

    if (this != NULL && fecha !=NULL && isValidFecha(fecha))
    {
        strcpy(this->fecha, fecha);
        ret = RETURN_OK;
    }
    return ret;
}

int llamada_getFecha(sLlamada* this, char* fecha)
{
    int ret = RETURN_ERROR;

    if (this!=NULL && fecha!=NULL )
    {
        strcpy(fecha,this->fecha);
        ret = RETURN_OK;
    }
    return ret;
}

/** Get y Set Numero Cliente **/
int llamada_setNumeroCliente(sLlamada* this, int numeroCliente)
{
    int ret;
    ret = RETURN_ERROR;

    if(numeroCliente > 0 && this != NULL && isValidInt(numeroCliente, 0, 100000))
    {
        this->numeroCliente = numeroCliente;
        ret = RETURN_OK;
    }
    return ret;
}

int llamada_getNumeroCliente(sLlamada* this, int* numeroCliente)
{
    int ret;
    ret = RETURN_ERROR;
    if(numeroCliente != NULL && this != NULL)
    {
        *numeroCliente = this->numeroCliente;
        ret = RETURN_OK;
    }
    return ret;
}

/** Get y Set Id Problema **/
int llamada_setIdProblema(sLlamada* this, int idProblema)
{
    int ret;
    ret = RETURN_ERROR;

    if(idProblema > 0 && this != NULL && isValidInt(idProblema, 1, 5))
    {
        this->idProblema = idProblema;
        ret = RETURN_OK;
    }
    return ret;
}

int llamada_getIdProblema(sLlamada* this, int* idProblema)
{
    int ret;
    ret = RETURN_ERROR;
    if(idProblema != NULL && this != NULL)
    {
        *idProblema = this->idProblema;
        ret = RETURN_OK;
    }
    return ret;
}

/** Get y Set Solucionado **/
int llamada_setSolucionado(sLlamada* this, char* solucionado)
{
    int ret = RETURN_ERROR;

    if (this != NULL && solucionado !=NULL)
    {
        strcpy(this->solucionado, solucionado);
        ret = RETURN_OK;
    }
    return ret;
}

int llamada_getSolucionado(sLlamada* this, char* solucionado)
{
    int ret = RETURN_ERROR;

    if (this!=NULL && solucionado!=NULL )
    {
        strcpy(solucionado,this->solucionado);
        ret = RETURN_OK;
    }
    return ret;
}







/** Problema **/
sProblema* problema_new()/**  **/
{
    sProblema* pProblema = (sProblema *) calloc ( 1 , sizeof (sProblema));
    if(pProblema == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return pProblema;
}

sProblema* problema_newParametros(char* problemaIdStr, char* descripcion)
{
    sProblema* pProblema;
    sProblema* ret = NULL;
    int idProblema;

    if(problemaIdStr != NULL && descripcion != NULL)
    {
        pProblema = llamada_new();
        idProblema = atoi(problemaIdStr);
        if(problema_setProblemaId(pProblema, idProblema)&&
            problema_setDescripcion(pProblema, descripcion))
        {
            ret = pProblema;
        }
        else
        {
            llamada_delete(pProblema);
        }
    }
    return ret;
}


int problema_delete(sProblema* this)
{
    int retorno = -1;

    if (this!=NULL )
    {
        free(this);
        retorno = RETURN_OK;
    }
    return retorno;
}

/**  Get y Set Problema Id**/
int problema_setProblemaId(sProblema* this, int problemaId)
{
    int ret;
    ret = RETURN_ERROR;

    if(problemaId > 0 && this != NULL && isValidInt(problemaId, 0, 10))
    {
        this->problemaId = problemaId;
        ret = RETURN_OK;
    }
    return ret;
}

int problema_getProblemaId(sProblema* this, int* problemaId)
{
    int ret;
    ret = RETURN_ERROR;
    if(problemaId != NULL && this != NULL)
    {
        *problemaId = this->problemaId;
        ret = RETURN_OK;
    }
    return ret;
}

/**  Get y Set Descripcion**/
int problema_setDescripcion(sProblema* this, char* descripcion)
{
    int ret = RETURN_ERROR;

    if (this != NULL && descripcion !=NULL)
    {
        strcpy(this->descripcion, descripcion);
        ret = RETURN_OK;
    }
    return ret;
}

int problema_getDescripcion(sProblema* this, char* descripcion)
{
    int ret = RETURN_ERROR;

    if (this!=NULL && descripcion!=NULL )
    {
        strcpy(descripcion,this->descripcion);
        ret = RETURN_OK;
    }
    return ret;
}


/** Mostrar LLamada **/
void  llamada_showLlamada(sLlamada* this)
{
    int idLlamadaAux;
    char auxFecha[50];
    int auxNumeroCliente;
    int auxIdProblema;
    char auxSolucionado[50];

    if((sLlamada*)this != NULL )
    {
        if( llamada_getIdLlamada((sLlamada*)this, &idLlamadaAux)&&
            llamada_getFecha((sLlamada*)this, auxFecha)&&
            llamada_getNumeroCliente((sLlamada*)this, &auxNumeroCliente)&&
            llamada_getIdProblema((sLlamada*)this, &auxIdProblema)&&
            llamada_getSolucionado((sLlamada*)this, auxSolucionado))
        {
            printf("%4d %15s %d %d %s\n\n ", idLlamadaAux, auxFecha, auxNumeroCliente,
               auxIdProblema, auxSolucionado);
        }
    }
}


void problema_showProblema(sProblema* this)
{
    int problemaIdAux;
    char auxDescripcion[50];

    if((sProblema*)this != NULL )
    {
        if( problema_getProblemaId((sProblema*)this, &problemaIdAux)&&
            problema_getDescripcion((sProblema*)this, auxDescripcion))
        {
            printf("%d %15s\n", problemaIdAux, auxDescripcion);
        }
    }
}

int llamada_filterProblemaUno(void* llamada)
{
    sLlamada* pLlamada;
    pLlamada = llamada;
    int ret = RETURN_ERROR;
    if(pLlamada->idProblema == 1)
    {
        ret = RETURN_OK;
    }
}


int llamada_filterProblemaDos(void* llamada)
{
    sLlamada* pLlamada;
    pLlamada = llamada;
    int ret = RETURN_ERROR;
    if(pLlamada->idProblema == 2)
    {
        ret = RETURN_OK;
    }
}

int llamada_filterProblemaTres(void* llamada)
{
    sLlamada* pLlamada;
    pLlamada = llamada;
    int ret = RETURN_ERROR;
    if(pLlamada->idProblema == 3)
    {
        ret = RETURN_OK;
    }
}

int llamada_filterProblemaCuatro(void* llamada)
{
    sLlamada* pLlamada;
    pLlamada = llamada;
    int ret = RETURN_ERROR;
    if(pLlamada->idProblema == 4)
    {
        ret = RETURN_OK;
    }
}

int llamada_filterProblemaCinco(void* llamada)
{
    sLlamada* pLlamada;
    pLlamada = llamada;
    int ret = RETURN_ERROR;
    if(pLlamada->idProblema == 5)
    {
        ret = RETURN_OK;
    }
}
