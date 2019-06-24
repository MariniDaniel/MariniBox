#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define OCUPADO 0
#define VACIO 1
#include "Informes.h"
#define TAM_PRES 30

void menu_Informe(ePrestamo listaPrestamos[],int tamPrestamos,eSocio listaSocios[],int tamSocios,eLibro listaLibros[],int TamLibros,eAutores listaAutores[],int tamAutor)
{
    int option;

    do
    {

        system("cls");
        printf("  *** INFORMES ***\n\n");
        printf("1-  TOTAL Y PROMEDIO\n");
        printf("2-  DIAS QUE NO SUPERAN EL PROMEDIO\n");
        printf("3-  LISTAR SOCIOS POR LIBRO PRESTADO\n");
        printf("4-  LISTAR LIBRO/S PRESTADO POR SOCIO\n");
        printf("5-  LIBRO/S MENOS PRESTADOS\n");
        printf("6-  SOCIO/S CON MAS PRESTAMOS\n");
        printf("7-  LIBROS SOLICITADOS EN UNA FECHA\n");
        printf("8-  SOCIOS QUE REALIZARON PRESTAMO EN UNA FECHA\n");
        printf("9-  ORDENAR LIBROS BURBUJEOS\n");
        printf("10-  ORDENAR SOCIOS INSERCION\n");
        printf("11- Salir\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &option);

        switch(option)

        {
        case 1:

            printf("\nEl total de prestamos es: %d\n",cantidadPrestamos(listaPrestamos, TAM_PRES));
            printf("\nEl promedio diario de prestamos es: %.2f\n\n",promedioPrestamos(listaPrestamos, TAM_PRES));
            system("pause");

            break;
        case 2:
            printf("\nEl numero de dias que no alcanzan el promedio de prestamos es: %d\n\n",verificarPromedioPrestamos(listaPrestamos, TAM_PRES));
            system("pause");
            break;
        case 3:
            listar_Socio_Libro(listaPrestamos,tamPrestamos,listaLibros,TamLibros,listaSocios,tamSocios,listaAutores,tamAutor);
            break;
        case 4:

            listar_Libro_Socio(listaPrestamos,tamPrestamos,listaLibros,TamLibros,listaSocios,tamSocios,listaAutores,tamAutor);

            break;
        case 5:

            libro_Menos_Prestado(listaPrestamos,tamPrestamos,listaLibros,TamLibros,listaAutores,tamAutor);

            break;
        case 6:

            socio_Con_Mas_Prestamos(listaPrestamos,tamPrestamos,listaSocios,tamSocios);
            break;
        case 7:

            libros_Por_Fecha(listaPrestamos,tamPrestamos,listaLibros,TamLibros,listaAutores,tamAutor);


            break;
        case 8:

            Socios_Por_Fecha(listaPrestamos,tamPrestamos,listaSocios,tamSocios);

            break;
        case 9:
            listar_Libro_Por_Burbujeo_Descendente(listaLibros,TamLibros,listaAutores,tamAutor);


            break;
        case 10:

            listar_Socios_Por_Insercion_Ascendente(listaSocios,tamSocios);

            break;
        case 11:
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
    while(option!=11);
}




void listar_Socio_Libro(ePrestamo listaPrestamo[], int tamPrestamo, eLibro listaLibro[], int tamLibro, eSocio listaSocios[], int tamSocio,eAutores listaAutores[],int tamAutor)
{
    int idLibro;
    char titulo[51];
    int flag=0;

    idLibro=elegir_libro(listaLibro,tamLibro,listaAutores,tamAutor);
    cargarDescripcion_Libro(listaLibro, tamLibro, idLibro, titulo);

    system("cls");
    printf("\n Socios del libro: %s\n\n", titulo);

    for(int i=0; i<tamPrestamo; i++)
    {
        if(listaPrestamo[i].isEmpty == OCUPADO && idLibro == listaPrestamo[i].CodigoLibro)
        {
            for(int j=0; j<tamSocio; j++)
            {
                if(listaPrestamo[i].CodigoSocio == listaSocios[j].codigoSocio)
                {
                    flag=1;
                    mostrar_Socio(listaSocios[j]);
                    break;
                }
            }
        }
    }

    if(flag==0)
    {
        printf(" No hay Prestamos para mostrar.\n");
    }
}



int elegir_Socio(eSocio Socios[], int tamSocio)
{
    int idSocio;
    int retorno=-1;


    mostrar_Socios(Socios, tamSocio);
    printf("\n Seleccione un cliente: ");
    scanf("%d", &idSocio);

    for(int i=0; i < tamSocio; i++)
    {
        if(Socios[i].codigoSocio==idSocio && Socios[i].isEmpty == OCUPADO)
        {
            retorno=idSocio;
            break;
        }
    }

    return retorno;
}

void listar_Libro_Socio(ePrestamo listaPrestamo[], int tamPrestamo, eLibro listaLibro[], int tamLibro, eSocio listaSocios[], int tamSocio,eAutores listaAutores[],int tamAutor)
{
    int idSocio;
    char nombre[31];
    char apellido[31];
    int flag=0;

    idSocio=elegir_Socio(listaSocios,tamSocio);
    cargarDescripcion_Socio(listaSocios,tamSocio,idSocio,apellido,nombre);


    system("cls");
    printf("\n Libros del Socio: %s-%s\n\n", nombre,apellido);

    printf("Codigo        Titulo         Autor   \n\n");

    for(int i=0; i<tamPrestamo; i++)
    {
        if(listaPrestamo[i].isEmpty == OCUPADO && idSocio == listaPrestamo[i].CodigoSocio)
        {
            for(int j=0; j<tamAutor; j++)

            {

                for(int l=0; l<tamLibro; l++)
                {
                    if(listaPrestamo[i].CodigoLibro == listaLibro[l].CodigoLibro && listaAutores[j].CodigoAutor==listaLibro[l].codigoAutor)
                    {
                        flag=1;
                        mostrar_LibroCon_Autor(listaAutores,tamAutor,listaLibro[l]);
                        break;
                    }
                }

            }


        }
    }

    if(flag==0)
    {
        printf(" No hay Libros para mostrar o el socio no existe\n");
    }
}




void libro_Menos_Prestado(ePrestamo listaPrestamos[], int tamPrestamo, eLibro listaLibro[], int tamLibro,eAutores listaAutor[],int tamAutor)
{
    int contadorPrestamo=0;
    int AcumuladorLibroMenor;
    int flag=0;

    for (int i=0; i<tamLibro; i++)
    {

        contadorPrestamo = 0;
        for (int j=0; j<tamPrestamo; j++)
        {
            if (listaPrestamos[j].CodigoLibro == listaLibro[i].CodigoLibro && listaPrestamos[j].isEmpty== OCUPADO)
            {
                contadorPrestamo++;
            }
        }

        if (contadorPrestamo < AcumuladorLibroMenor || flag==0 )
        {
            AcumuladorLibroMenor = contadorPrestamo;
            flag=1;
        }



    }

    system("cls");
    printf("Codigo        Titulo         Autor   \n\n");
    for (int i=0; i<tamLibro; i++)
    {

        contadorPrestamo = 0;

        for (int j=0; j<tamPrestamo; j++)
        {
            if (listaPrestamos[j].CodigoLibro == listaLibro[i].CodigoLibro && listaPrestamos[j].isEmpty==OCUPADO)
            {
                contadorPrestamo++;
            }
        }
        if (contadorPrestamo == AcumuladorLibroMenor)
        {

            mostrar_LibroCon_Autor(listaAutor,tamAutor,listaLibro[i]);
        }

    }
}




void socio_Con_Mas_Prestamos(ePrestamo listaPrestamos[], int tamPrestamos, eSocio listaSocios[],int tamSocios)
{
    int contadorSocioMayor=0;
    int contadorSocio;
    int flag=0;

    system("cls");
    printf(" Codigo   Nombre    Apellido    Sexo    Telefono   Email      Fecha De Asociado\n\n");

    for(int i=0; i<tamSocios; i++)
    {
        contadorSocio=0;
        for(int j=0; j<tamPrestamos; j++)
        {
            if(listaSocios[i].codigoSocio == listaPrestamos[j].CodigoSocio && listaPrestamos[j].isEmpty==OCUPADO && listaSocios[i].isEmpty==OCUPADO)
            {
                contadorSocio++;
            }
        }
        if(contadorSocio>contadorSocioMayor || flag==0)
        {
            contadorSocioMayor=contadorSocio;
            flag=1;
        }

    }

    for(int i=0; i<tamSocios; i++)
    {
        contadorSocio=0;
        for(int j=0; j<tamPrestamos; j++)
        {
            if(listaSocios[i].codigoSocio == listaPrestamos[j].CodigoSocio && listaPrestamos[j].isEmpty==OCUPADO && listaSocios[i].isEmpty==OCUPADO)
            {
                contadorSocio++;
            }
        }

        if(contadorSocio == contadorSocioMayor   )
        {
            mostrar_Socio(listaSocios[i]);

        }
    }

}


void  libros_Por_Fecha(ePrestamo listaPrestamos[], int tamPrestamo, eLibro  listaLibros[], int tamLibros, eAutores listaAutores[],int tamAutores)
{
    int dia;
    int mes;
    int anio;
    int encontroFecha=0;

    system("cls");


    getValidInt("Ingrese dia: ","\nPor favor ingrese un dia valido entre 1 y 30: \n",1,30,&dia);

    getValidInt("Ingrese mes: ","\nPor favor ingrese un mes valido entre 1 y 12: \n",1,12,&mes);

    getValidInt("Ingrese anio: ","\nPor favor ingrese un anio valido entre 1960 y 2019: \n",1960,2019,&anio);

    system("cls");
    printf("Codigo        Titulo         Autor   \n\n");

    for (int i=0; i<tamPrestamo; i++)
    {
        if (listaPrestamos[i].isEmpty == OCUPADO && listaPrestamos[i].fechaPrestamo.dia == dia && listaPrestamos[i].fechaPrestamo.mes == mes && listaPrestamos[i].fechaPrestamo.anio == anio)
        {
            for (int j=0; j<tamLibros; j++)
            {
                if (listaPrestamos[i].CodigoLibro == listaLibros[j].CodigoLibro)
                {
                    mostrar_LibroCon_Autor(listaAutores,tamAutores,listaLibros[j]);
                    encontroFecha=1;
                }
            }
        }
    }

    if(encontroFecha==0)
    {
        printf("no existe un prestamo de esa fecha\n");
    }


}


void  Socios_Por_Fecha(ePrestamo listaPrestamos[], int tamPrestamo, eSocio  listaSocio[], int tamSocios)
{
    int dia;
    int mes;
    int anio;
    int encontroFecha=0;

    system("cls");


    getValidInt("Ingrese dia: ","\nPor favor ingrese un dia valido entre 1 y 30: \n",1,31,&dia);

    getValidInt("Ingrese mes: ","\nPor favor ingrese un mes valido entre 1 y 12: \n",1,12,&mes);

    getValidInt("Ingrese anio: ","\nPor favor ingrese un anio valido entre 1960 y 2019: \n",1960,2019,&anio);

    system("cls");
    printf(" Codigo   Nombre    Apellido    Sexo   Telefono    Email      Fecha De Asociado\n\n");

    for (int i=0; i<tamSocios; i++)
    {
        if (listaPrestamos[i].isEmpty == OCUPADO && listaPrestamos[i].fechaPrestamo.dia == dia && listaPrestamos[i].fechaPrestamo.mes == mes && listaPrestamos[i].fechaPrestamo.anio == anio)
        {
            for (int j=0; j<tamSocios; j++)
            {
                if (listaPrestamos[i].CodigoSocio == listaSocio[j].codigoSocio)
                {
                    mostrar_Socio(listaSocio[j]);
                    encontroFecha=1;
                }
            }
        }
    }

    if(encontroFecha==0)
    {
        printf("no existe un prestamo de esa fecha\n");
    }

}


int listar_Libro_Por_Burbujeo_Descendente(eLibro listaLibros[], int tamLibros,eAutores listaAutores[],int tamAutores)
{
    eLibro auxLibro;

    int estaOrdenado = 1;
    int retorno=-1;

    while(estaOrdenado ==1)
    {
        estaOrdenado = 0;
        for (int j=1; j<tamLibros; j++)
        {
            if (strcmp(listaLibros[j].titulo,listaLibros[j - 1].titulo)>0)
            {
                auxLibro = listaLibros[j];
                listaLibros[j] = listaLibros[j-1];
                listaLibros[j-1] = auxLibro;
                estaOrdenado = 1;
            }
        }
    }
    system("cls");
    printf("ORDENADOS DESCENDENTEMENTE\n\n");
    mostrar_Libros_Con_Autor(listaLibros,tamLibros,listaAutores,tamAutores);
    retorno=0;

    return retorno;
}

int listar_Socios_Por_Insercion_Ascendente(eSocio listaSocios[], int tamSocios)
{
    eSocio auxSocio;
    int j;
    int retorno=-1;

    for(int i=1; i<tamSocios; i++)
    {
        auxSocio = listaSocios[i];
        j=i-1;

        while(strcmp(listaSocios[j].apellido, auxSocio.apellido)>0 && j>=0)
        {
            listaSocios[j+1] = listaSocios[j];
            j--;
        }
        listaSocios[j+1]=auxSocio;
    }
    system("cls");
    printf("ORDENADOS ASCENDENTEMENTE\n\n");
    mostrar_Socios(listaSocios, tamSocios);
    retorno=0;

    return retorno;
}

void promedio_Fecha(ePrestamo listaPrestamos[],int tamPrestamo)
{



   // eFecha auxFecha;

    int contador=0;


    for(int i=0;i<tamPrestamo;i++)
    {
        if(listaPrestamos[i].isEmpty==OCUPADO)
        {
//            auxFecha=listaPrestamos[i].fechaPrestamo;
            break;

            for(int j=0; j<tamPrestamo;j++)
            {
//                if(auxFecha==listaPrestamos[j].fechaPrestamo)
                {
                    contador++;
                }
            }
        }
    }



}



int cantidadPrestamos(ePrestamo prestamos[], int tamP)
{
    int cantidadP=0;

    for (int i=0; i<tamP; i++)
    {
        if(prestamos[i].isEmpty)
        {
            cantidadP++;
        }
    }
    return cantidadP;
}

int ordenarPrestamos(ePrestamo prestamos[], int tamP)
{
    ePrestamo pAux;

    for (int i=0; i<tamP-1; i++)
    {
        for(int j=i+1; j<tamP; j++)
        {
            if((prestamos[i].fechaPrestamo.anio>prestamos[j].fechaPrestamo.anio)||(prestamos[i].fechaPrestamo.anio==prestamos[j].fechaPrestamo.anio && prestamos[i].fechaPrestamo.mes>prestamos[j].fechaPrestamo.mes)||(prestamos[i].fechaPrestamo.anio==prestamos[j].fechaPrestamo.anio && prestamos[i].fechaPrestamo.mes==prestamos[j].fechaPrestamo.mes && prestamos[i].fechaPrestamo.dia>prestamos[j].fechaPrestamo.dia))
            {
                pAux = prestamos[j];
                prestamos[j]=prestamos[i];
                prestamos[i]=pAux;
            }
        }
    }
    return 1;
}

int mostrarPrestamos(ePrestamo prestamos[], int tamP)
{
    system("cls");
    printf("\nPrestamos registrados:\n");
    printf("ID ID Socio ID Libro Fecha\n");
    for (int i=0; i<tamP; i++)
    {
        if(prestamos[i].isEmpty)
        {
            printf("%d\t%d\t%d\t%d/%d/%d\n",prestamos[i].CodigoPrestamo,prestamos[i].CodigoSocio,prestamos[i].CodigoLibro,prestamos[i].fechaPrestamo    .dia,prestamos[i].fechaPrestamo.mes,prestamos[i].fechaPrestamo.anio);

        }
    }
    return 1;
}

float promedioPrestamos(ePrestamo prestamos[], int tamP)
{
    int cantidadP;
    int fechasDif=1;
    float promedio;

    cantidadP=cantidadPrestamos(prestamos,tamP);

    ordenarPrestamos(prestamos,tamP);

    for (int i=0; i<tamP-1; i++)
    {
        for(int j = i+1; j<tamP; j++)
        {
            if((prestamos[i].isEmpty && prestamos[j].isEmpty)&&(prestamos[i].fechaPrestamo.dia!=prestamos[j].fechaPrestamo.dia || prestamos[i].fechaPrestamo.mes!=prestamos[j].fechaPrestamo.mes || prestamos[i].fechaPrestamo.anio!=prestamos[j].fechaPrestamo.anio))
            {
                i=j;
                fechasDif++;
            }
        }
    }
    promedio=(float)cantidadP/fechasDif;

    return promedio;
}


int verificarPromedioPrestamos(ePrestamo prestamos[], int tamP)
{
    int contNoPromedio=0;
    float contPrestamos=1;
    float promedio;

    promedio = promedioPrestamos(prestamos, tamP);

    for (int i=0; i<tamP-1; i++)
    {
        for(int j = i+1; j<tamP; j++)
        {
            if(prestamos[i].isEmpty && prestamos[j].isEmpty)
            {
                if(prestamos[i].fechaPrestamo.dia==prestamos[j].fechaPrestamo.dia && prestamos[i].fechaPrestamo.mes==prestamos[j].fechaPrestamo.mes && prestamos[i].fechaPrestamo.anio==prestamos[j].fechaPrestamo.anio)
                {
                    contPrestamos++;
                }
                else
                {
                    i=j;
                    if (contPrestamos<promedio)
                    {
                        contNoPromedio++;
                    }
                    contPrestamos = 1;
                }
            }
        }
    }

    if((prestamos[tamP-1].isEmpty && prestamos[tamP-2].isEmpty) && (prestamos[tamP-1].fechaPrestamo.dia!=prestamos[tamP-2].fechaPrestamo.dia || prestamos[tamP-1].fechaPrestamo.mes!=prestamos[tamP-2].fechaPrestamo.mes || prestamos[tamP-1].fechaPrestamo.anio!=prestamos[tamP-2].fechaPrestamo.anio)&&(promedio>1))
    {
        contNoPromedio++;
    }


    return contNoPromedio;
}
