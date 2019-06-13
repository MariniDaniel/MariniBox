#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[6];
    char nombreStr[20];
    char nivelStr[6];
    char cantProdVendStr[10];
    char montoVendidoStr[10];



    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idStr, nombreStr, nivelStr, cantProdVendStr, montoVendidoStr);
            if(cant != 5)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                Vendedor* vend = vendedor_new();
                vend->id = atoi(idStr);
                strcpy(vend->nombre, nombreStr);
                vend->nivel = atoi(nivelStr);
                vend->cantProdVend = atoi(cantProdVendStr);
                vend->montoVendido = atof(montoVendidoStr);
                vend->comision = 0;
                ll_add(pArrayListEmployee, vend);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Arvhivo hay datos\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVendedor LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListVendedor)
{
    int ret;
    ret = RETURN_ERROR;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

                Vendedor* vend = vendedor_new();
                ret = fread(vend, sizeof(Vendedor),1,pFile);
                if(ret != 1)
                {
                    printf("Error al caargar datos\n");
                }
                else
                {
                    ll_add(pArrayListVendedor, vend);
                }
        }
    fclose(pFile);
    ret = RETURN_OK;
    }
    else
    {
        printf("No hay datos");
        system("pause");
    }

    return ret;
}


