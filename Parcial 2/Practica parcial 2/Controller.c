#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UTN_INPUT.h"



int controller_listExist(LinkedList* pArrayListEempleado)
{
    int existe = -1;
    int len =ll_len(pArrayListEempleado);


        if(len>0)
        {
            existe = 1;

        }


    return existe;
}


int controller_loadFromText(char* path, LinkedList* pArrayListEempleado)
{
    FILE* Pfile = fopen(path,"r");
    int retorno=-1;

    if(Pfile!=NULL&& pArrayListEempleado !=NULL)
    {
        if(parser_EempleadoFromText(Pfile,pArrayListEempleado))
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


    return retorno;
}


int controller_ListEempleado(LinkedList* pArrayListEempleado)
{
    Eempleado* empleado = Eempleado_new();
    int len = ll_len(pArrayListEempleado);

    int idAuxiliar;
    char nombreAuxiliar[50];
    char empleoAuxiliar[50];
    int horasAuxiliar;
    int edadAuxiliar;
    float sueldoAuxiliar;
    int retorno=-1;

    if(empleado!=NULL && pArrayListEempleado!=NULL)
    {
        system("cls");
        puts(" [ID]\t[NOMBRE]\t[EMPLEO]\t[HORAS]\t  [EDAD]      [SUELDO]\n\n");

        for(int i=0; i < len; i++)
        {
            empleado = ll_get(pArrayListEempleado, i);

            Eempleado_getId(empleado, &idAuxiliar);
            Eempleado_getNombre(empleado,nombreAuxiliar);
            Eempleado_getEmpleo(empleado,empleoAuxiliar);

            Eempleado_getHorasTrabajadas(empleado,&horasAuxiliar);
            Eempleado_getEdad(empleado,&edadAuxiliar);

            Eempleado_getsueldo(empleado,&sueldoAuxiliar);

            printf("%5d  %10s %15s %10d  %10d  %10.2f\n",idAuxiliar, nombreAuxiliar, empleoAuxiliar, horasAuxiliar,edadAuxiliar,sueldoAuxiliar);


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


int controller_sortEempleado(LinkedList* pArrayListEempleado)
{
    system("cls");
    LinkedList* listaClonada=NULL;
    int retorno=-1;

    if(pArrayListEempleado!=NULL)
    {

    listaClonada= ll_clone(pArrayListEempleado);

    printf("ORDENANDO....\n");

    ll_sort(listaClonada,Eempleado_compararPorNombre,1);

    controller_ListEempleado(listaClonada);

    retorno=1;

    }
    else
    {
        retorno=-1;
    }

    ll_deleteLinkedList(listaClonada);

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEempleado)
{
    int retorno=-1;
    int len;
    int idAuxiliar;
    char nombreAuxiliar[50];
    char empleoAuxiliar[50];
    int horasAuxiliar;
    int edadAuxiliar;
    float sueldoAuxiliar;

    FILE* Pfile = fopen(path,"w");
    Eempleado* auxEempleado=Eempleado_new();

    if(Pfile != NULL && pArrayListEempleado != NULL && auxEempleado!=NULL )
    {
        len=ll_len(pArrayListEempleado);
        fprintf(Pfile, "id,nombre,empleo,edad,horas,sueldo\n");

        for(int i=0; i<len; i++)
        {
            auxEempleado= ll_get(pArrayListEempleado,i);

            Eempleado_getId(auxEempleado, &idAuxiliar);
            Eempleado_getNombre(auxEempleado,nombreAuxiliar);
            Eempleado_getEmpleo(auxEempleado,empleoAuxiliar);
            Eempleado_getHorasTrabajadas(auxEempleado,&horasAuxiliar);
            Eempleado_getEdad(auxEempleado,&edadAuxiliar);
            Eempleado_getsueldo(auxEempleado,&sueldoAuxiliar);

            fprintf(Pfile,"%d,%s,%s,%d,%d,%.2f\n",idAuxiliar,nombreAuxiliar,empleoAuxiliar,horasAuxiliar,edadAuxiliar,sueldoAuxiliar);

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


int controller_mapEmployee(LinkedList* pArrayListEempleado)
{
    int retorno=1;

    if(pArrayListEempleado!=NULL)
    {

        if(ll_map(pArrayListEempleado,Eempleado_mapearSueldo))
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

