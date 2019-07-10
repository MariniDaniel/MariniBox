#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UTN_INPUT.h"

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();

    do
    {
        menu();
        printf("\nPor favor ingrese una opcion <1-6> :");
        fflush(stdin);
        scanf("%d",&option);

        switch(option)
        {
        case 1:
            if(controller_loadFromText("datos.csv",listaEmpleados)==1)
            {
                printf("\n Empleados cargados correctamente.\n\n");
            }
            else
            {
                printf("\n\nERROR...No se pudo cargar el archivo\n\n");
            }

            break;

        case 2:
            if(controller_listExist(listaEmpleados)==1)
            {

                if(controller_sortEempleado(listaEmpleados)==1)
                {
                    printf("\n Empleados listados correctamente.\n\n");
                }
                else
                {
                    printf("\n\nERROR...No se pudieron listar a los empleados\n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de listar\n");
            }
            break;
        case 3:
            if(controller_listExist(listaEmpleados)==1)
            {

                if(controller_mapEmployee(listaEmpleados)==1)
                {

                    printf("\n Empleados mapeados correctamente (modo texto).\n\n");

                }
                else
                {
                    printf("\n\nERROR...No se pudieron mapear los sueldos \n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de mapear\n");
            }
            break;

        case 4:
              if(controller_listExist(listaEmpleados)==1)
            {

                listaFiltrada=ll_filter(listaEmpleados,Eempleado_filtrarPorEmpleo);
                controller_ListEempleado(listaFiltrada);

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de filtrar\n");
            }

            break;

        case 5:

             if(controller_listExist(listaEmpleados)==1)
            {

                if(controller_saveAsText("resultados.csv",listaFiltrada)==1)
                {

                    printf("\n Empleados guardados correctamente.\n\n");

                }
                else
                {
                    printf("\n\nERROR...No se pudo guardar la lista\n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de guardar\n");
            }
            break;

        case 6:
            printf("\n\nSALIENDO DEL PROGRAMA!!!\n\n");
            break;
        default:
            printf("\n\nERROR...Ingrese una opcion correcta <1-10>\n\n");
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option != 6);

    ll_deleteLinkedList(listaEmpleados);

    return 0;
}
