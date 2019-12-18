#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Llamada.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_fromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idLlamadaStr[50];
    char fechaStr[50];
    char numeroClienteStr[50];
    char idProblemaStr[50];
    char solucionadoStr[50];



    if(pFile != NULL)
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idLlamadaStr, fechaStr, numeroClienteStr, idProblemaStr, solucionadoStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idLlamadaStr, fechaStr, numeroClienteStr, idProblemaStr, solucionadoStr);
            if(cant != 5)
            {
                printf("Error al Leer Archivo\n\n");
                system("pause");
            }
            else
            {
                sLlamada* pLlamada;
                pLlamada = llamada_newParametros(idLlamadaStr, fechaStr, numeroClienteStr, idProblemaStr, solucionadoStr);
                ll_add(pArrayList, pLlamada);
            }
        }
    fclose(pFile);
    printf("Arvhivo Leido Con Exito\n\n");
    system("pause");
    RETURN_OK;
    }
    else
    {
        printf("Arvhivo No hay datos\n\n");
        system("pause");
    }

    return ret;
}

int parser_fromTextProblema(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idProblemaStr[50];
    char descripcionStr[50];


    if(pFile != NULL)
    {
        cant = fscanf(pFile,"%[^,]%[^,\n]\n", idProblemaStr, descripcionStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,]%[^,\n]\n", idProblemaStr, descripcionStr);
            printf("%d", cant);
            if(cant != 2)
            {
                printf("Error al Leer Archivo\n\n");
                system("pause");
                break;
            }
            else
            {
                sProblema* pProblema;
                pProblema = problema_newParametros(idProblemaStr, descripcionStr);
                ll_add(pArrayList, pProblema);
            }
        }
    fclose(pFile);
    printf("Arvhivo Leido Con Exito\n\n");
    system("pause");
    RETURN_OK;
    }
    else
    {
        printf("Arvhivo No hay datos\n\n");
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
 /*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListVendedor)
{
    int ret;
    ret = RETURN_ERROR;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

                Vendedor* env = vendedor_new();
                ret = fread(env, sizeof(Vendedor),1,pFile);
                if(ret != 1)
                {
                    printf("Error al caargar datos\n");
                }
                else
                {
                    ll_add(pArrayListVendedor, env);
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
*/
