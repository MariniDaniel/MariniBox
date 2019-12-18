#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "UTN_INPUT.h"


Eempleado* Eempleado_new()
{
    Eempleado* newEempleado = (Eempleado*)malloc(sizeof(Eempleado));

    if(newEempleado!=NULL)
    {
        newEempleado->horasTrabajadas=0;
        newEempleado->edad= 0;
        newEempleado->sueldo= 0;
        newEempleado->id= 0;
        strcpy(newEempleado->nombre,"");
        strcpy(newEempleado->empleo,"");
    }

    return newEempleado;
}


Eempleado* Eempleado_newParametros(char* idStr,char* nombreStr,char* empleoStr, char* edadStr, char* horasStr)
{
    Eempleado* newEempleadoParam = Eempleado_new();
    int retorno = 0;

    if(newEempleadoParam != NULL)
    {
        if(Eempleado_setId(newEempleadoParam, atoi(idStr) ) )
        {
            if(Eempleado_setNombre(newEempleadoParam, nombreStr))
            {
                if(Eempleado_setEmpleo(newEempleadoParam,empleoStr) )
                {
                if(Eempleado_setEdad(newEempleadoParam,atoi(horasStr)) )

                {
                    if(Eempleado_setHorasTrabajadas(newEempleadoParam, atoi(edadStr)   ) )
                    {
                        retorno = 1;
                    }


                }
                }
            }
        }

        if(retorno == 0)
        {
            free(newEempleadoParam);
            newEempleadoParam = NULL;
        }
    }
    return newEempleadoParam;
}


int Eempleado_setId(Eempleado* this,int id)
{
    int retorno =0;

    if(this != NULL )
    {
        this->id = id;

        retorno=1;
    }

    return retorno;
}


int Eempleado_getId(Eempleado* this,int* id)
{
    int retorno =0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;

        retorno=1;
    }

    return retorno;
}


int Eempleado_setEdad(Eempleado* this,int edad)
{
    int retorno =0;

    if(this != NULL)
    {
        this->edad = edad;
        retorno=1;
    }

    return retorno;
}


int Eempleado_getEdad(Eempleado* this,int* edad)
{
    int retorno =0;

    if(this!=NULL && edad!=NULL)
    {
        *edad=this->edad;

        retorno=1;
    }

    return retorno;
}


int Eempleado_setNombre(Eempleado* this,char* nombre)
{
    int retorno =0;

    if(this != NULL && nombre!=NULL)
    {

        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}


int Eempleado_getNombre(Eempleado* this,char* nombre)
{
    int retorno =0;

    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);

        retorno=1;
    }

    return retorno;
}

int Eempleado_setEmpleo(Eempleado* this,char* empleo)
{
    int retorno =0;

    if(this != NULL && empleo!=NULL)
    {

        strcpy(this->empleo,empleo);
        retorno=1;
    }

    return retorno;
}


int Eempleado_getEmpleo(Eempleado* this,char* empleo)
{
    int retorno =0;

    if(this != NULL && empleo!=NULL)
    {
        strcpy(empleo,this->empleo);

        retorno=1;
    }

    return retorno;
}


int Eempleado_setHorasTrabajadas(Eempleado* this,int horas)
{
    int retorno =0;

    if(this != NULL )
    {
        this->horasTrabajadas = horas;
        retorno=1;
    }

    return retorno;
}


int Eempleado_getHorasTrabajadas(Eempleado* this,int* horas)
{
    int retorno=0;

    if(this!=NULL && horas!=NULL)
    {
        *horas=this->horasTrabajadas;

        retorno=1;
    }

    return retorno;
}

 int Eempleado_setsueldo(Eempleado* this,float sueldo)
 {
     int retorno =0;

    if(this != NULL )
    {
        this->sueldo = sueldo;
        retorno=1;
    }

    return retorno;
 }

 int Eempleado_getsueldo(Eempleado* this,float* sueldo)
{
     int retorno=0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;

        retorno=1;
    }

    return retorno;
}


 int Eempleado_compararPorNombre(void* personaA, void* personaB)
 {
     Eempleado* auxA =( Eempleado*)personaA;
     Eempleado* auxB =(Eempleado*)personaB;
     int aux;

     aux=strcmp(auxA->nombre,auxB->nombre);

     return aux;
 }

int Eempleado_mapearSueldo(void* persona)
{
  int retorno = 0;
  Eempleado* auxEempleado;
  int auxHoras;
  float auxSueldo;

  if(persona != NULL)
{
    auxEempleado = (Eempleado*) persona;

    Eempleado_getHorasTrabajadas(auxEempleado,&auxHoras);
    Eempleado_getsueldo(auxEempleado,&auxSueldo);

    if(auxSueldo>0)
    {
        retorno=0;
    }

        if(auxHoras>=0)
        {
            Eempleado_setsueldo(auxEempleado,(auxHoras*300));
            retorno = 1;
        }

  }
  return retorno;
}

int Eempleado_filtrarPorEmpleo(void* persona)
{
  int retorno = 0;
  Eempleado* auxEempleado;
  int auxEdad;
  char auxEmpleo[50];

  if(persona != NULL)
 {
    auxEempleado = (Eempleado*) persona;
    Eempleado_getEdad(auxEempleado,&auxEdad);
    Eempleado_getEmpleo(auxEempleado,auxEmpleo);

    if(strcmp(auxEmpleo,"programador")==0 && auxEdad>=20)
    {
      retorno = 1;
    }
  }
  return retorno;
}
