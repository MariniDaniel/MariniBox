#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Prestamos.h"

void init_Prestamo(ePrestamo Prestamo[], int tam)
{
    int codigoPrestamo[15] = { 201, 202, 203, 204, 205, 206, 207, 208, 209, 210,211, 212, 213, 214, 215};
    int codigoSocio[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,3,  4, 6, 7, 7};
    int codigoLibro[15]= {101, 105, 103, 104, 105, 105, 107, 108, 109, 105, 101, 106, 103, 103, 101};
    eFecha fechaPrestamo[15] = {{13,7,2018},{1,9,2017},{2,10,2008},{24,12,2005},{12,2,2019},{12,2,2019},{28,3,2017},{7,4,2019},{5,5,2005},{13,7,2018},{12,2,2006},{28,3,2019},{7,4,2017},{28,3,2019},{13,7,2018}};


    for(int i=0; i<15; i++)
    {
        Prestamo[i].CodigoLibro=codigoLibro[i];

        Prestamo[i].CodigoPrestamo=codigoPrestamo[i];

        Prestamo[i].CodigoSocio=codigoSocio[i];

        Prestamo[i].fechaPrestamo=fechaPrestamo[i];

        generarNextId_Prestamo();

        Prestamo[i].isEmpty=OCUPADO;

        sumarPrestamo(1);


    }
}


int hay_Prestamos_Cargados(ePrestamo listaPrestamos[], int tamPrestamos)
{
    int hayPrestamos = -1;

    for(int i=0; i < tamPrestamos; i++)
    {
        if(listaPrestamos[i].isEmpty == OCUPADO)
        {
            hayPrestamos = 0;
            break;
        }
    }

    return hayPrestamos;
}

void menu_Prestamos(ePrestamo listaPrestamos[],int tamPrestamos,eSocio listaSocios[],int tamSocios,eLibro listaLibros[],int TamLibros,eAutores listaAutores[],int tamAutor)
{
    int option;

    do
    {

        system("cls");
        printf("  *** PRESTAMOS ***\n\n");
        printf("1- Alta prestamos\n");
        printf("2- Listar los Prestamos\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)

        {
        case 1:

            alta_Prestamos(listaPrestamos,tamPrestamos,listaSocios,tamSocios,listaLibros,TamLibros);

            break;
        case 2:
            if(hay_Prestamos_Cargados(listaPrestamos,tamPrestamos)==0)
            {

            mostrar_Prestamos(listaPrestamos,tamPrestamos,listaSocios,tamSocios,listaLibros,TamLibros,listaAutores,tamAutor);
            }
            else
            {
                printf("ERROR, por favor cargue un prestamo antes de continuar\n");

            }
            break;
        case 3:
            printf("\nREGRESANDO AL MENU PRINCIPAL\n");
            break;
        default:
            printf("\nERROR! Por favor ingrese una opcion valida <1-7>\n");
            break;
        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(option!=3);
}

void cargarFecha_Prestamos(ePrestamo lista[],int indice)
{
    int auxDia;
    int auxMes;
    int auxAnio;


    getValidInt("Ingrese dia: ","\nPor favor ingrese un dia valido entre 1 y 30: \n",1,30,&auxDia);

    lista[indice].fechaPrestamo.dia=auxDia;


    getValidInt("Ingrese mes:","Por favor ingrese un mes valido entre 1 y 12: \n",1,12,&auxMes);

    lista[indice].fechaPrestamo.mes=auxMes;


    getValidInt("Ingrese anio: ","Por favor ingrese un anio valido entre 1960 y 2030: \n",1980,2019,&auxAnio);

    lista[indice].fechaPrestamo.anio=auxAnio;
}

int inicializar_Prestamo(ePrestamo lista[], int tam)
{
    int myReturn=-1;

    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = VACIO;

        myReturn=0;
    }

    return myReturn;
}


int buscarLibre_Prestamo(ePrestamo lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int generarNextId_Prestamo()
{
    static int id=200;

    id ++;

    return id;
}

int sumarPrestamo(int caso)

{
    static int alta=0;
    switch(caso)
    {
    case 0:
        return alta;
        break;
    case 1:
        alta++;
        break;
    }


}

int alta_Prestamos(ePrestamo listaPrestamos[],int tamPrestamo,eSocio listaSocio[],int tamSocio,eLibro listaLibro[],int tamLibro)
{

    int indice;
    int respuesta;
    int socio;
    int auxIdSocio;
    int auxIdLibro;
    int myReturn=-1;
    int existeSocio=-1;
    int existeLibro=-1;
    int contadorPrestamos=0;


    indice = buscarLibre_Prestamo(listaPrestamos, tamPrestamo);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {

        system("cls");
        mostrar_Socios(listaSocio,tamSocio);
        do
        {

            printf("\nIngrese el codigo del socio a recibir el prestamo: ");
            fflush(stdin);
            scanf("%d",&auxIdSocio);

            for(int i=0; i < tamSocio; i++)
            {
                if(auxIdSocio==listaSocio[i].codigoSocio && listaSocio[i] .isEmpty==OCUPADO)
                {
                    existeSocio=0;
                    listaPrestamos[indice].CodigoSocio=auxIdSocio;
                    break;
                }



            }

        }
        while(existeSocio==-1);

        socio=buscar_Socios_PorId(listaSocio,tamSocio,auxIdSocio);

        printf("%s",listaSocio[socio].nombre);






        for(int i=0; i<tamLibro; i++)
        {

            printf("\nCodigo libro %d",listaLibro[i].CodigoLibro);

        }




        do
        {

            printf("\nIngrese codigo libro que se va a llevar: ");
            fflush(stdin);
            scanf("%d",&auxIdLibro);

            for(int i=0; i < tamLibro; i++)
            {
                if(auxIdLibro==listaLibro[i].CodigoLibro )
                {
                    listaPrestamos[indice].CodigoLibro=auxIdLibro;
                    existeLibro=0;
                }
            }

        }
        while(existeLibro==-1);



        system("cls");



        printf("Ingrese fecha del prestamo: \n");
        cargarFecha_Prestamos(listaPrestamos,indice);



            listaPrestamos[indice].isEmpty = OCUPADO;


            listaPrestamos[indice].CodigoPrestamo=generarNextId_Prestamo();

            contadorPrestamos=sumarPrestamo(1);
            printf("Alta Prestamo exitosa!!!\n\n");
            printf("\nTotal de prestamos hasta ahora: %d",contadorPrestamos);

            myReturn=0;


    }

    return myReturn;





}


void mostrar_Prestamos(ePrestamo listaPrestamos[],int tamPrestamo,eSocio listaSocio[],int tamSocio,eLibro listaLibro[],int tamLibro,eAutores listaAutores[],int tamAutor)
{
    char titulo[20];
    char NombreSocio[20];
    char ApellidoSocio[20];

    system("cls");
    printf("  *** Listado de Prestamos ***\n\n");
    printf("\nPrestamo   Socio     Apellido       Libro            Titulo             Fecha\n");

    for(int i=0; i< tamPrestamo; i++)
    {
        if(listaPrestamos[i].isEmpty==OCUPADO)
        {

            for(int j = 0; j < tamSocio; j++)
            {
                if(listaPrestamos[i].CodigoSocio == listaSocio[j].codigoSocio)
                {
                    strcpy(NombreSocio, listaSocio[j].nombre);
                    strcpy(ApellidoSocio, listaSocio[j].apellido);
                    break;
                }
            }
            for(int k = 0; k < tamLibro; k++)
            {
                if(listaPrestamos[i].CodigoLibro == listaLibro[k].CodigoLibro)
                {
                    strcpy(titulo, listaLibro[k].titulo);
                    break;
                }

            }

            printf("%d",listaPrestamos[i].CodigoPrestamo);
            printf("%10d",listaPrestamos[i].CodigoSocio);
            printf("%15s",ApellidoSocio);
            printf("%10d",listaPrestamos[i].CodigoLibro);
            printf("%20s",titulo);
            printf("%10d/%d/%d\n",listaPrestamos[i].fechaPrestamo.dia,listaPrestamos[i].fechaPrestamo.mes,listaPrestamos[i].fechaPrestamo.anio);


        }

    }

}
