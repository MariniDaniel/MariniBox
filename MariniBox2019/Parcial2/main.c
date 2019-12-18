#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Dominio.h"
#include "UTN_INPUT.h"

int main()
{
    int opcion;
    char path[21];
    LinkedList* listaDominio = ll_newLinkedList();
    LinkedList* listaFiltradaA=ll_newLinkedList();
    LinkedList* listaFiltradaM=ll_newLinkedList();


    do
    {
        menu();
        opcion=getInt("\nPor favor ingrese una opcion <1-6> :");

        switch(opcion)
        {
        case 1:

            getString("\nIngrese el nombre del archivo a cargar, sin olvidarse de poner al final '.csv'\n:",path);


            if(controller_loadFromText(path,listaDominio)==1)
            {
                controller_ListDominio(listaDominio);
                printf("\n archivo cargado correctamente (modo texto)\n\n");
            }
            else
            {
                printf("\n\nERROR...No se pudo cargar el archivo\n\n");
            }

            break;

        case 2:
            if(controller_listExist(listaDominio)==1)
            {

                if(controller_mapEmployee(listaDominio)==1)
                {
                    controller_ListDominio(listaDominio);
                    printf("\n elementos mapeados correctamente\n\n");
                }
                else
                {
                    printf("\n\nERROR...No se pudieron mapear a los elementos\n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de listar\n");
            }
            break;

        case 3:

            if(controller_listExist(listaDominio)==1)
            {

                listaFiltradaA =  ll_filter(listaDominio,eDominio_filtrarAuto);
                listaFiltradaM = ll_filter(listaDominio,eDominio_filtrarMoto);

                controller_ListDominio(listaFiltradaA);
                system("pause");
                controller_ListDominio(listaFiltradaM);

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de filtrar\n");
            }

            break;
        case 4:
            if(controller_listExist(listaDominio)==1)
            {

                if(controller_saveAsText("auto.csv",listaFiltradaA))
                {
                    printf("\nArchivo auto.csv guardado\n");
                }
                else
                {
                    printf("\n\nERROR...No se pudo guardar el archivo\n\n");
                }


                if(controller_saveAsText("moto.csv",listaFiltradaM))
                {
                    printf("\nArchivo moto.csv guardado\n\n");
                }
                else
                {
                    printf("\n\nERROR...No se pudo guardar el archivo\n\n");
                }

            }
            else
            {
                printf("\nERROR...Por favor cargue elementos a la lista antes de guardad\n");
            }

            break;
        case 5:
            printf("\n\nSALIENDO DEL PROGRAMA\n\n");
            break;
        default:
            printf("\n\nERROR...Ingrese una opcion correcta <1-6>\n\n");
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion != 5);

    ll_deleteLinkedList(listaDominio);
    ll_deleteLinkedList(listaFiltradaA);
    ll_deleteLinkedList(listaFiltradaM);

    return 0;
}
