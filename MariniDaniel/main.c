#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Llamada.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

int menuPpal();
int menuEdit();
int menuSort();



int main()
{
    int option = 0;
    LinkedList* pArrayListLlamada = ll_newLinkedList();
    LinkedList* pArrayListProblema = ll_newLinkedList();
    LinkedList* pArrayListProblemaUno = ll_newLinkedList();
    LinkedList* pArrayListProblemaDos = ll_newLinkedList();
    LinkedList* pArrayListProblemaTres = ll_newLinkedList();
    LinkedList* pArrayListProblemaCuatro = ll_newLinkedList();
    LinkedList* pArrayListProblemaCinco = ll_newLinkedList();

    char path[20];
    int rta;
    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                system("cls");
                //printf("\nIngrese Nombre de Archivo: ");
                //scanf("%s", path);
                controller_loadFromText("DATA_final1.csv", pArrayListLlamada);
                controller_cargarProblemas(pArrayListProblema);
                break;
            case 2:
                system("cls");
                controller_listProblema(pArrayListLlamada, pArrayListProblema);
                break;
            case 3:
                printf("\nIngrese Numero Problema: ");
                scanf("%d", &rta);
                printf("\nIngrese Nombre de Archivo: ");
                scanf("%s", path);
                switch(rta)
                {
                    case 1:
                        pArrayListProblemaUno = ll_filter(pArrayListLlamada, llamada_filterProblemaUno);
                       // controller_listProblema(pArrayListProblemaUno, pArrayListProblema);
                        controller_saveAsText(path, pArrayListProblemaUno, pArrayListProblema);
                        break;
                    case 2:
                        pArrayListProblemaDos = ll_filter(pArrayListLlamada, llamada_filterProblemaDos);
                        controller_saveAsText(path, pArrayListProblemaDos, pArrayListProblema);
                        break;
                    case 3:
                        pArrayListProblemaTres = ll_filter(pArrayListLlamada, llamada_filterProblemaTres);
                        controller_saveAsText(path, pArrayListProblemaTres, pArrayListProblema);
                        break;
                    case 4:
                        pArrayListProblemaCuatro = ll_filter(pArrayListLlamada, llamada_filterProblemaCuatro);
                        controller_saveAsText(path, pArrayListProblemaCuatro, pArrayListProblema);
                        break;
                    case 5:
                        pArrayListProblemaCinco = ll_filter(pArrayListLlamada, llamada_filterProblemaCinco);
                        controller_saveAsText(path, pArrayListProblemaCinco, pArrayListProblema);
                        break;
                }
               // controller_saveAsText(path, pArrayListLlamada, pArrayListProblema);
                system("cls");
                break;
            case 4:
                system("cls");

                break;
            case 5:

                break;
            case 6:
                break;
        }
    }while(option != 4);
    return 0;
}

int menuPpal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  Menu:                                                   \n");
        printf("  1. Cargar Archivo                                       \n");
        printf("  2. Informar Llamadas                                    \n");
        printf("  3. Generar Archivo de Llamadas                          \n");
        printf("  4. Salir                                                    \n");
        //printf("  5.                                                      \n");
       // printf("  6. Salir                                                \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 10);

    return r;
}

int menuEdit()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione un campo a editar: \n");
        printf("     1. Nombre.                    \n");
        printf("     2. Horas Trabajadas.          \n");
        printf("     3. Sueldo                     \n");
        printf("     4. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 4);

    return r;
}

int menuSort()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione el sort:           \n");
        printf("     1. Id.                        \n");
        printf("     2. Nombre.                    \n");
        printf("     3. Horas Trabajadas.          \n");
        printf("     4. Sueldo                     \n");
        printf("     5. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 5);

    return r;
}
