#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

#define TAM 5


int main()
{
    system("color f0");
    //error 1 ok 0
    int opcion;
    char respuesta = 's';
    int retorno;

    eJuego vJuego[TAM];
    eCliente vCliente[TAM];
    eCategoria vCategoria[TAM];
    eAlquileres vAlquiler[TAM];

    cargarCategorias(vCategoria, TAM);
    cargarJuegos(vJuego, TAM, vCategoria, TAM);
    inicializarClientes(vCliente, TAM);
    inicializarAlquileres(vAlquiler, TAM);
    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            retorno = altaCliente(vCliente, TAM);

            if(retorno == 1)
            {
                printf("\nNo se puede dar mas de alta,espacio lleno.\n");
            }
            break;
        case 2:
            retorno = hayClientes(vCliente, TAM);
            if(retorno == 0)
            {

                retorno = bajaCliente(vCliente, TAM);
                if(retorno == 1)
                {
                    printf("\nNo existe el cliente ingresado\n");
                }

            }
            else
            {
                printf("\n No hay clientes para dar de baja\n");
            }
            break;
        case 3:
            retorno = hayClientes(vCliente, TAM);
            if(retorno == 0)
            {
                retorno = modificarCliente(vCliente, TAM);
                if(retorno == 1)
                {
                    printf("\nNo existe el cliente ingresado\n");
                }
            }
            else
            {
                printf("\nNo hay clientes para modificar\n");
            }
            break;
        case 4:
            retorno = hayClientes(vCliente, TAM);
            if(retorno == 0)
            {
                listarClientes(vCliente, TAM);
            }
            else
            {
                printf("\nNo hay Clientes para listar\n");
            }
            break;
        case 5:
            retorno = altaAlquiler(vAlquiler, TAM, vJuego, TAM, vCliente, TAM);
            if(retorno == 1)
            {
                printf("\nNo hay clientes dados de alta.\n");
            }
            break;
        case 6:
            retorno = hayAlquileres(vAlquiler, TAM);
            if(retorno == 0)
            {
                listarAlquileres(vAlquiler, TAM, vCliente, TAM, vJuego, TAM, vCategoria, TAM);
            }
            else
            {
                printf("\nNo hay alquileres para listar\n");
            }
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }

        do
        {
            fflush(stdin);
            printf("\nDesea continuar? [s/n]\n");
            scanf("%c", &respuesta);
        }
        while(respuesta != 's' && respuesta != 'n');
    }
    while(respuesta == 's');
    return 0;
}



