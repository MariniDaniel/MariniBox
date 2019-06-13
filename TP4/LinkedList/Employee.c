#include <stdio.h>
#include "Employee.h"
#define RETURN_OK 1
#define RETURN_ERROR 0
Vendedor* vendedor_new()/**  **/
{
    Vendedor* vend;
    vend = (Vendedor*)malloc(sizeof(Vendedor));
    vend->id = 0;
    strcpy(vend->nombre, "");
    vend->nivel = 0;
    vend->cantProdVend = 0;
    vend->montoVendido = 0;
    vend->comision = 0;

    return vend;
}

/*
Vendedor* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Vendedor* vend;
    vend = (Vendedor*)malloc(sizeof(Vendedor));
    vend->id = idStr;
    strcpy(vend->nombre, nombreStr);
    vend->horasTrabajadas = horasTrabajadasStr;
    vend->sueldo = 0;

    return vend;
}
*/


int vendedor_setId(Vendedor* this,int id)
{
    int ret;
    ret = RETURN_ERROR;

    if(id > 0 && this != NULL)
    {
        this->id = id;
        ret = RETURN_OK;
    }
    return ret;
}
int vendedor_getId(Vendedor* this,int* id)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *id = this->id;
        ret = RETURN_OK;
    }

    return ret;
}

int vendedor_setNombre(Vendedor* this,char* nombre)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->nombre,nombre);
        ret = RETURN_OK;
    }

    return ret;
}

int vendedor_getNombre(Vendedor* this,char* nombre)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        ret = RETURN_OK;
    }

    return ret;
}

int vendedor_setCantProdVend(Vendedor* this,int cantProdVend)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->cantProdVend = cantProdVend;
        ret = RETURN_OK;
    }

    return ret;
}

int vendedor_getCantProdVend(Vendedor* this,int* cantProdVend)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *cantProdVend = this->cantProdVend;
        ret = RETURN_OK;
    }

    return ret;
}

int vendedor_setNivel(Vendedor* this,int nivel)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->nivel = nivel;
        ret = RETURN_OK;
    }

    return ret;
}
int vendedor_getNivel(Vendedor* this,int* nivel)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *nivel = this->nivel;
        ret = RETURN_OK;
    }

    return ret;
}

int vendedor_setMontoVendido(Vendedor* this,float montoVendido)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->montoVendido = montoVendido;
        ret = RETURN_OK;
    }

    return ret;
}
int vendedor_getMontoVendido(Vendedor* this, float* montoVendido)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *montoVendido = this->montoVendido;
        ret = RETURN_OK;
    }

    return ret;
}

int vendedor_setComision(Vendedor* this,float comision)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
       this->comision = comision;
        ret = RETURN_OK;
    }

    return ret;
}
int vendedor_getComision(Vendedor* this, float* comision)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        *comision = this->comision;
        ret = RETURN_OK;
    }

    return ret;
}

void  vendedor_showEmployee(Vendedor* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %s  %d  %d   %.2f   %.2f \n\n " , this->id , this->nombre ,this->nivel, this->cantProdVend, this->montoVendido, this->comision);
    }
}

void  vendedor_showEmployees(Vendedor* this)
{
    Vendedor* vend;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this);i++)
        {
            vend = (Vendedor*)ll_get(this, i);
            vendedor_showEmployee(vend);
        }
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        system("pause");
    }

}

int vendedor_sortByName(void* empleadoA, void* empleadoB)
{
    int ret;
    ret = strcmp(((Vendedor*)empleadoA)->nombre, ((Vendedor*)empleadoB)->nombre);
    return ret;
}


int vendedor_sortById(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Vendedor*)empleadoA)->id > ((Vendedor*)empleadoB)->id)
    {
        ret = 1;
    } if(((Vendedor*)empleadoA)->id < ((Vendedor*)empleadoB)->id)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;

}

int vendedor_sortByHsTrabajadas(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Vendedor*)empleadoA)->cantProdVend > ((Vendedor*)empleadoB)->cantProdVend)
    {
        ret = 1;
    }
    else if(((Vendedor*)empleadoA)->cantProdVend < ((Vendedor*)empleadoB)->cantProdVend)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int vendedor_sortBySueldo(void* empleadoA, void* empleadoB)
{
    int ret;
    if(((Vendedor*)empleadoA)->nivel > ((Vendedor*)empleadoB)->nivel)
    {
        ret = 1;
    }
    else if(((Vendedor*)empleadoA)->nivel < ((Vendedor*)empleadoB)->nivel)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

float vendedor_loadSueldo(void* vendedor)
{
    float ret;
    float porcentaje;


    if(((Vendedor*)vendedor)->nivel == 0)
    {
        porcentaje = ((Vendedor*)vendedor)->montoVendido * 0.2;
        ((Vendedor*)vendedor)->comision = porcentaje ;
    }
    else if(((Vendedor*)vendedor)->nivel >= 1)
    {
        if(((Vendedor*)vendedor)->cantProdVend < 100)
        {
            porcentaje = ((Vendedor*)vendedor)->montoVendido * 0.035;
            ((Vendedor*)vendedor)->comision = porcentaje ;
        }
        else if(((Vendedor*)vendedor)->cantProdVend >= 100)
        {
            porcentaje = ((Vendedor*)vendedor)->montoVendido * 0.05;
            ((Vendedor*)vendedor)->comision = porcentaje ;
        }
    }
    ret = ((Vendedor*)vendedor)->comision;
    return ret;
}


int vendedor_niveles(void* vendedor, int* nivel)
{
    int retAux = -1;
    void* filter;
    if(((Vendedor*)vendedor)->nivel == 0 && nivel == 0)
    {
        filter = ((Vendedor*)vendedor);
        retAux = 0;
    }
    else if(((Vendedor*)vendedor)->nivel == 1 && nivel == 1)
    {
        filter = ((Vendedor*)vendedor);
        retAux = 1;
    }
    else if(((Vendedor*)vendedor)->nivel == 2 && nivel == 2)
    {
        filter = ((Vendedor*)vendedor);
        retAux = 2;
    }
    return retAux;
}





