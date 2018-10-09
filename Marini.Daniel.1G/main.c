#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Clientes.h"
#include "Juegos.h"
#define CANTB 20
#define CANTA 5


int main()
{
    system("color f0");
    eCliente listaC[100];
    eJuegos listaJ[20];

    int respuesta;
    int altaBanderaCliente = 0, altaBanderaJuego = 0;
    int opcionElegida;

    inicializarJuego(listaJ,CANTB);
    inicializarCliente(listaC,CANTA);
    do{
        system("cls");
        respuesta = menuPrincipal();
        if (respuesta == 1){
            system("cls");
            opcionElegida=MenuJuegos();
            switch (opcionElegida){
            case 1:
                system("cls");
                addJuego(listaJ,CANTB,&altaBanderaJuego);
                break;
            case 2:
                system("cls");
                if (altaBanderaJuego != 0){
                modificarJuego(listaJ,CANTB);
                }
                else{
                    printf("Aun no se ingresaron datos");
                }
                break;
            case 3:
                system("cls");
                if (altaBanderaJuego != 0){
                    BajaJuego(listaJ,CANTB);
                }else{
                    printf("Aun no se ingresaron datos");
                }
                break;
            case 4:
                system("cls");
                if (altaBanderaJuego != 0){
//                    imprimirListaJuegos(listaJ,CANTB);

                }else{
                    printf("Aun no se ingresaron datos");
                }
                system("pause");
                break;
            }
        }
        if (respuesta == 2){
            system("cls");
            opcionElegida = menuClientes();
            switch (opcionElegida){
                case 1:
                    addCliente(listaC,CANTA,&altaBanderaCliente);
                    break;
                case 2:
                    modificarCliente(listaC,CANTA);
                    break;
                case 3:
                    bajaCliente(listaC,CANTA);
                    break;
                case 4:
                   imprimirListaClientes(listaC,CANTA);
                    break;
                }

        }
        if (respuesta ==3)
        {
            printf("Aca van los alquileres.\n");
            system("Pause");
        }
        if (respuesta == 4){
            printf("Vuelva pronto!!!!\n");
        }
    }while(respuesta != 4);

    return 0;
}
