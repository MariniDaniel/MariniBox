#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Juegos.h"
#include "Clientes.h"

int menuClientes()
{
    int opcionElegida;
    printf ("------------------->Menu De Clientes<-------------------\n");
    printf ("\n1- Ingrese uno para dar de alta un cliente.");
    printf ("\n2- Ingrese dos para modificar los datos de un cliente.");
    printf ("\n3- Ingrese tres para dar de baja un cliente.");
    printf ("\n4- Ingrese cuatro para listar los clientes.");
    printf ("\n\nIngrese el numero: ");
    getInt(&opcionElegida);
    return opcionElegida;
}

void inicializarCliente(eCliente* lista,int len)
{
    int i;
    for (i=0; i<len; i++)
    {
        lista[i].isEmpty = 0;
    }
}

int primerEspacioCliente(eCliente* lista, int len)
{
    int i,retorno;
    retorno = -1;
    for (i=0; i<len; i++)
    {
        if (lista[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void addCliente(eCliente* lista, int len,int *altaBanderaCliente)
{
    int r,cantidad;
    char auxNombre[51];
    char auxTelefono[51];
    r = primerEspacioCliente(lista,len);
    if (r != -1)
    {

        do
        {
            printf("Ingrese el nombre del cliente");
            getSringLetras(auxNombre);
            cantidad = strlen(auxNombre);

        }
        while(cantidad>51 || cantidad<0);
        do
        {
            printf("Ingrese el telefono del cliente");
            getString(auxTelefono);
            cantidad = strlen(auxTelefono);
        }
        while(cantidad>21 || cantidad<0);
        strcpy(lista[r].nombre,auxNombre);
        strcpy(lista[r].telefono,auxTelefono);
        lista[r].isEmpty = 1;
        *altaBanderaCliente = 1;
    }
    else
    {
        printf("No hay espacio disponble");
    }
}

int findCliente(eCliente* lista, int len,int codigo)
{
    int retorno = -1;
    int i;
    for (i=0; i<len; i++)
    {
        if(lista[i].codigoCliente == codigo)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void modificarCliente(eCliente* lista,int len)
{
    int auxCodigoCliente;
    int respuesta;
    int clienteEncontrado;
    int cantidad;
    char auxNombreCliente[51];
    char auxTelefonoCliente[51];

    printf("Ingrese el codigo del cliente que desea modificar: ");
    getInt(&auxCodigoCliente);
    clienteEncontrado = findCliente(lista,len,auxCodigoCliente);
    if (clienteEncontrado != -1)
    {
        printf("Submenu modificacion de registro del cliente:  ");
        printf("\n1- ingrese 1 para modificar el nombre:  ");
        printf("\n2- ingrese 2 para modificar el telefono:  ");
        printf ("\n\nIngrese el numero: ");
        getInt(&respuesta);
        switch(respuesta)
        {
        case 1:
            do
            {
                printf("Ingrese el nombre a modificar: ");
                getSringLetras(auxNombreCliente);
                cantidad = strlen(auxNombreCliente);
            }
            while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].nombre,auxNombreCliente);

        case 2:
            do
            {
                printf("Ingrese el telefono a modificar: ");
                getString(auxTelefonoCliente);
                cantidad = strlen(auxTelefonoCliente);
            }
            while(cantidad>51 || cantidad<0);
            strcpy(lista[clienteEncontrado].telefono,auxTelefonoCliente);
        }
    }
    else
    {
        printf("No se encuentran los datos de este cliente");
    }
}

void bajaCliente(eCliente* lista,int len)
{
    int auxCodigo,encontrado;
    printf("Ingrese el codigo del cliente que desea eliminar del registro");
    getInt(&auxCodigo);
    encontrado = findCliente(lista,len,auxCodigo);
    if (encontrado != -1)
    {
        lista[encontrado].isEmpty = 0;
    }
    else
    {
        printf("No se encuentra en el registro");
    }
}


void ordenarClientes(eCliente* lista, int len)
{
    eCliente AuxLista;
    int i,j;
    if(lista != NULL && len>0)
    {
        for (i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {


                if (strcmp(lista[i].nombre,lista[j].nombre)>0)
                {
                    AuxLista = lista[i];
                    lista[i] = lista[j];
                    lista[j] = AuxLista;
                }

            }
        }
    }
}




void imprimirListaClientes(eCliente* lista,int len)
{
    int i;
    ordenarClientes(lista,len);
    for (i=0; i<len; i++)
    {
        if (lista[i].isEmpty == 1)
        {
            printf ("\n El nombre del cliente es: %c",lista[i].nombre);
            printf ("\n El codigo del cliente es: %d",lista[i].codigoCliente);
            printf ("\n Su sexo es: %c\n",lista[i].sexo);
        }
    }
}
