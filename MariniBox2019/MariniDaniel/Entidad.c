#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Llamada.h"
#include "Validaciones.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


Venta* venta_new()/**  **/
{
   //pVenta = (eDominio*)malloc(sizeof(eDominio));
    Venta* pVenta = (Venta *) calloc ( 1 , sizeof (Venta));
    if(pVenta == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }
   /* pVenta->idEnvio = 0;
    strcpy(pVenta->nombreProd, "");
    pVenta->idCamion = 0;
    strcpy(pVenta->zonaDestino, "");
    pVenta->kmRecorrido = 0;
    pVenta->tipoEntrega = 0;
    pVenta->costoEnvio = 0;*/

    return pVenta;
}

Venta* venta_newParametros(char* idVentaStr, char* fechaVentaStr, char* tipoFotoStr, char* cantidadStr, char* precioUnitarioStr,
                           char* cuitClienteStr)
{
    Venta* pVenta = venta_new();

    venta_setIdVenta(pVenta, atoi(idVentaStr));
    venta_setFechaVenta(pVenta, fechaVentaStr);
    venta_setTipoFoto(pVenta, tipoFotoStr);
    venta_setCantidad(pVenta, atoi(cantidadStr));
    venta_setPrecioUnitario(pVenta, atof(precioUnitarioStr));
    venta_setCuitCliente(pVenta, cuitClienteStr);

    return pVenta;
}

int venta_delete(Venta* this)
{
    int retorno = -1;

    if (this!=NULL )
    {
        free(this);
        retorno = RETURN_OK;
    }
    return retorno;
}

/** Setters **/
int venta_setIdVenta(Venta* this, int idVenta)
{
    int ret;
    ret = RETURN_ERROR;

    if(idVenta > 0 && this != NULL && isValidInt(idVenta, 0, 1000))
    {
        this->idVenta = idVenta;
        ret = RETURN_OK;
    }
    return ret;
}


int venta_setFechaVenta(Venta* this, char* fechaVenta)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL && isValidFecha(fechaVenta))
    {
        strcpy(this->fechaVenta, fechaVenta);
        ret = RETURN_OK;
    }
    return ret;
}

int venta_setTipoFoto(Venta* this, char* tipoFoto)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->tipoFoto, tipoFoto);
        ret = RETURN_OK;
    }
    return ret;
}

int venta_setCantidad(Venta* this, int cantidad)
{
    int ret;
    ret = RETURN_ERROR;

    if(cantidad > 0 && this != NULL && isValidInt(cantidad, 0, 1000))
    {
        this->cantidad = cantidad;
        ret = RETURN_OK;
    }
    return ret;
}

int venta_setPrecioUnitario(Venta* this, float precioUnitario)
{
    int ret;
    ret = RETURN_ERROR;

    if(precioUnitario > 0 && this != NULL && isValidFloat(precioUnitario, 0, 5000))
    {
        this->precioUnitario = precioUnitario;
        ret = RETURN_OK;
    }
    return ret;
}

int venta_setCuitCliente(Venta* this, char* cuitCliente)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL && isCuit(cuitCliente))
    {
        strcpy(this->cuitCliente, cuitCliente);
        ret = RETURN_OK;
    }
    return ret;
}

/** Getters **/
int venta_getIdVenta(Venta* this, int* idVenta)
{
    int ret;
    ret = RETURN_ERROR;
    if(idVenta != NULL && this != NULL)
    {
        *idVenta = this->idVenta;
        ret = RETURN_OK;
    }
    return ret;
}

int venta_getFechaVenta(Venta* this, char* fechaVenta)
{
    int ret = RETURN_ERROR;

    if (this!=NULL && fechaVenta!=NULL )
    {
        strcpy(fechaVenta,this->fechaVenta);
        ret = RETURN_OK;
    }
    return ret;
}

int venta_getTipoFoto(Venta* this, char* tipoFoto)
{
    int ret = RETURN_ERROR;

    if (this!=NULL && tipoFoto!=NULL )
    {
        strcpy(tipoFoto,this->tipoFoto);
        ret = RETURN_OK;
    }
    return ret;
}

int venta_getCantidad(Venta* this, int* cantidad)
{
    int ret;
    ret = RETURN_ERROR;
    if(cantidad != NULL && this != NULL)
    {
        *cantidad = this->cantidad;
        ret = RETURN_OK;
    }
    return ret;
}

int venta_getPrecioUnitario(Venta* this, float* precioUnitario)
{
    int ret;
    ret = RETURN_ERROR;
    if(precioUnitario != NULL && this != NULL)
    {
        *precioUnitario = this->precioUnitario;
        ret = RETURN_OK;
    }
    return ret;
}

int venta_getCuitCliente(Venta* this, char* cuitCliente)
{
    int ret = RETURN_ERROR;
    if (this!=NULL && cuitCliente!=NULL )
    {
        strcpy(cuitCliente,this->cuitCliente);
        ret = RETURN_OK;
    }
    return ret;
}


/** Funciones **/
int venta_fotoCantidad(void* venta)
{
    int ret = RETURN_ERROR;
    int cantidad = 0;
    Venta* aux;
    aux = (Venta*)venta;
    if(aux != NULL)
    {
        venta_getCantidad((Venta*)venta, &cantidad);
        ret = cantidad;
    }
    return ret;
}

int venta_ventasMayor150(void* venta)
{
    int ret = RETURN_ERROR;
    float total;
    int cantidad = 0;
    float precio = 0;
    venta_getCantidad(venta, &cantidad);
    venta_getPrecioUnitario(venta, &precio);
    total = precio * cantidad;
    if(total > 150)
    {
        ret = RETURN_OK;
    }
    return ret;
}
