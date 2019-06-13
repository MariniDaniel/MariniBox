#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int menuPpal();
int menuEdit();
int menuSort();



int main()
{
    int option = 0;
    LinkedList* eVendedor = ll_newLinkedList();
    LinkedList* eVendedorNivel = ll_newLinkedList();

    int nivel;

    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",eVendedor);
                break;
            case 2:
               controller_ListEmployee(eVendedor);
                break;
            case 3:
               ll_map(eVendedor, vendedor_loadSueldo);
                break;
            case 4:
               eVendedorNivel =  ll_filter(eVendedor, vendedor_niveles);
               controller_saveAsText("nivel.csv", eVendedorNivel);
                break;
            case 5:
                controller_ListEmployee(eVendedorNivel);
                break;
            case 6:
                break;
        }
    }while(option != 6);
    return 0;
}

int menuPpal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  Menu:                                                                          \n");
        printf("  1. Cargar datos                                                                \n");
        printf("  2. Listar                                                                      \n");
        printf("  3. Calcular Comision                                                           \n");
        printf("  4. Elegir nivel                                                                \n");
        printf("  5. Listar nivel elegido                                                        \n");
        printf("  6. Salir                                                                       \n");
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

