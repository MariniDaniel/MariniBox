#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Socios.h"
#define ERROR -1
#define EXITO 0
#define DESCENDENTE 0
#define ASCENDENTE 1

void init_Autores(eAutores autores[], int tam)
{
    int CodigoAutor[10] = {1001,1002,1003,1004,1005,1006,1007,1008,1009,1010};
    char nombre[10][31]= {"Daniel","Tomas","Joaquin","Raul","Sebastian","Thiago","Alexis","Stephen","Manuel","Eliza"};
    char apellido[10][31]= {"Ortiz","Salguez","Casco","Milton","Bulga","Zorzano","Juarez","King","Mas","Carriot"};


    for(int i=0; i<tam; i++)
    {
        autores[i].CodigoAutor=CodigoAutor[i];

        strcpy(autores[i].nombre, nombre[i]);

        strcpy(autores[i].apellido, apellido[i]);


    }
}


void init_Libros(eLibro libros[], int tam)
{
    int CodigoLibro[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};//Diferentes codigos para no mezclar
    int codigoAutor[10] = { 1010, 1005, 1008, 1007, 1002, 1004, 1009, 1003, 1006, 1001};
    char titulo[10][31]= {"Larga Marcha","Starwars","Minotauro","Martin Fierro","HarryPotter","Tango","Infantil","Independiente","Terror","100Chistes"};

    for(int i=0; i<tam; i++)
    {
        libros[i].CodigoLibro=CodigoLibro[i];

        strcpy(libros[i].titulo, titulo[i]);

        libros[i].codigoAutor=codigoAutor[i];



    }
}

int inicializar_Socios(eSocio lista[], int tam)
{
    int retorno=-1;

    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = VACIO;

        retorno=0;
    }

    return retorno;
}

int buscarLibre(eSocio lista[], int tam)
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


int buscar_Socios_PorId(eSocio lista[], int tam, int codigoSocio)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO && lista[i].codigoSocio == codigoSocio)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int hay_Socios_Cargados(eSocio lista[], int tam)
{
    int haySocios = -1;

    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            haySocios = 0;
            break;
        }
    }

    return haySocios;
}


int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int alta_Socios(eSocio lista[], int tam)
{
    int indice;
    int respuesta;
    char auxNombre[31] ;
    char auxApellido[31] ;
    char auxSexo;
    char auxTelefono[31];
    char auxEmail[31];
    int retorno=-1;


    indice = buscarLibre(lista, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {



        fflush(stdin);
        getValidString("\nIngrese nombre: ","\nError, por favor solo ingrese letras","\nError ,se exedio del limite de letras\n",auxNombre,1,30);
        stringToUpper(auxNombre);

        strcpy(lista[indice].nombre,auxNombre);


        fflush(stdin);
        getValidString("Ingrese apellido: ","\nError, por favor solo ingrese letras","\nError ,se exedio del limite de letras\n",auxApellido,1,30);
        stringToUpper(auxApellido);

        strcpy(lista[indice].apellido,auxApellido);


        fflush(stdin);
        getSexChar("Ingrese sexo: ","Error, ingrese  <F-M>\n",&auxSexo);

        lista[indice].sexo=auxSexo;

        fflush(stdin);
        getString("Ingrese telefono (debe tener un guion): ",auxTelefono);
        strcpy(lista[indice].telefono,auxTelefono);
        while(!Telefono(auxTelefono))
        {
            system("cls");
            printf("\nEl telefono debe contener 1 guion: ");
            getString("\nIngrese telefono (debe tener un guion): ",auxTelefono);
        }



        printf("\nIngrese su fecha de ingreso\n\n");
        cargarFecha_Socios(lista,indice);




        fflush(stdin);
        getString("ingrese email(datos alfanumericos): ",auxEmail);
        while(!strchr(auxEmail, '@') != NULL)
        {
            system("cls");
            printf("!\nNo es una direccion de correo o no uso arroba.\n");
            getString("\nReingrese email(datos alfanumericos): ",auxEmail);
        }



        strcpy(lista[indice].eMail,auxEmail);

        fflush(stdin);
        getValidInt("Esta seguro que quiere darle de alta a este empleado? <1.Si-2.No>","\Eerror ingrese un dato valido  <1-2>\n",1,2,&respuesta);


        if(respuesta==1)
        {

            lista[indice].isEmpty = OCUPADO;

            lista[indice].codigoSocio=generarNextId();

            printf("Alta empleado exitosa!!!\n\n");
            retorno=0;
        }
        else
        {
            printf("Alta cancelada");
        }
    }

    return retorno;
}

void cargarFecha_Socios(eSocio lista[],int indice)
{
    int auxDia;
    int auxMes;
    int auxAnio;


    getValidInt("Ingrese dia: ","\nPor favor ingrese un dia valido entre 1 y 30: \n",1,30,&auxDia);


    lista[indice].fechaDeAsociado.dia=auxDia;


    getValidInt("Ingrese mes:","Por favor ingrese un mes valido entre 1 y 12: \n",1,12,&auxMes);

    lista[indice].fechaDeAsociado.mes=auxMes;


    getValidInt("Ingrese anio: ","Por favor ingrese un anio valido entre 1980 y 2019: \n",1980,2019,&auxAnio);

    lista[indice].fechaDeAsociado.anio=auxAnio;
}

void mostrar_Socio(eSocio socio)
{


    printf("%2d   %10s   %7s   %5c   %10s  %10s %d/%d/%d\n", socio.codigoSocio, socio.nombre,socio.apellido, socio.sexo,socio.telefono,socio.eMail,socio.fechaDeAsociado.dia,socio.fechaDeAsociado.mes,socio.fechaDeAsociado.anio);

}


int mostrar_Socios(eSocio lista[], int tam)
{

    int retorno=-1;

    printf(" Codigo   Nombre    Apellido    Sexo    Telefono   Email  Fecha De Asociado\n\n");
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            mostrar_Socio(lista[i]);

            retorno=0;
        }
    }

    if( retorno == -1)
    {
        printf("\nNo hay empleados que mostrar\n");
    }

    return retorno;
}

int  modificar_Socios(eSocio lista[], int tam)
{
    int respuesta;
    int auxLegajo;
    int i;
    int indice;
    int existeSocio=0;
    int retorno=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            printf("\nCantidad de empleados %d",lista[i].codigoSocio);
        }
    }

    mostrar_Socios(lista,tam);
    printf("\nQue socio queres modificar? (Ingresar Codigo socio) ");
    fflush(stdin);
    scanf("%d",&auxLegajo);


    indice=buscar_Socios_PorId(lista,tam,auxLegajo);

    if(auxLegajo==lista[indice].codigoSocio && lista[indice].isEmpty==OCUPADO)
    {
        existeSocio=1;

        fflush(stdin);
        getValidInt("Esta seguro que quiere modificar a este socio? 1(Si) o 2(No)","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

        switch(respuesta)
        {
        case 1:

            modf_Socios(lista,indice);
            retorno=0;

            break;
        case 2:

            printf("Modificacion cancelada");
            retorno=-1;
            break;

        }
    }

    if(existeSocio==0)
    {
        printf("ERROR, el empleado no existe\n");
    }


    return retorno;

}

void modf_Socios(eSocio lista[], int indice)
{
    int opcion;
    char auxNewName[31];
    char auxNewLastName[31];
    char auxNewSex;
    char auxNewTelefono[31];
    char auxNewEmail[31];



    do
    {
        system("cls");
        printf("\n1.Modificar Nombre\n");
        printf("2.Modificar Apellido\n");
        printf("3.Modificar Telefono\n");
        printf("4.Modificar Sexo\n");
        printf("5.Modificar Email\n");
        printf("6.Modificar Fecha de ingreso\n");
        printf("7.Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:

            fflush(stdin);
            getValidString("Ingrese nuevo nombre :","ERROR,ingrese el nombre nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewName,1,30);
            stringToUpper(auxNewName);

            strcpy(lista[indice].nombre,auxNewName);

            printf("\nDato modificado\n");
            break;

        case 2:

            fflush(stdin);
            getValidString("Ingrese nuevo apellido :","ERROR,ingrese el apellido nuevamente (solo letras)","ERROR, se exedio del limite de la cadena",auxNewLastName,1,30);
            stringToUpper(auxNewLastName);
            strcpy(lista[indice].apellido, auxNewLastName);

            printf("\nDato modificado\n");
            break;

        case 3:

            fflush(stdin);
            getString("Ingrese el nuevo telefono (debe tener un guion): ",auxNewTelefono);
            strcpy(lista[indice].telefono,auxNewTelefono);
            while(!Telefono(auxNewTelefono))
            {
                system("cls");
                printf("\nEl telefono debe contener 1 guion: ");
                getString("\nIngrese telefono (debe tener un guion): ",auxNewTelefono);
            }

            printf("\nDato modificado\n");
            break;
        case 4:

            fflush(stdin);
            getSexChar("ingrese nuevo sexo","Error ingrese sexo valido <F-M>\n",&auxNewSex);
            lista[indice].sexo=auxNewSex;

            printf("\nDato modificado\n");
            break;
        case 5:


            fflush(stdin);
            getString("ingrese nuevo email(datos alfanumericos): ",auxNewEmail);
            while(!strchr(auxNewEmail, '@') != NULL)
            {
                system("cls");
                printf("!\nNo es una direccion de correo o no uso arroba.\n");
                getString("\nReingrese email(datos alfanumericos): ",auxNewEmail);

            }
            strcpy(lista[indice].eMail,auxNewEmail);
            printf("\nDato modificado\n");
            break;
        case 6:

            printf("Ingrese nueva fecha de ingreso");
            cargarFecha_Socios(lista,indice);

            break;
        case 7:

            printf("REGRESANDO AL MENU PRINCIPAL\n");

            break;
        default:
            printf("ERROR!! por favor ingrese una de las opciones validaas <1-7>\n");
            break;

        }

        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(opcion!=7);

}

int baja_Socios(eSocio lista[], int tam)
{
    int auxLegajo;
    int respuesta;
    int i;
    int retorno=-1;
    int existeSocio=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==OCUPADO)
        {
            printf("\nCantidad de empleados %d\n",lista[i].codigoSocio);
        }
    }

    mostrar_Socios(lista,tam);
    printf("\nQue socio queres dar de baja? (Ingresar ID socio) ");
    fflush(stdin);
    scanf("%d",&auxLegajo);


    for(i=0; i<tam; i++)
    {
        if(auxLegajo==lista[i].codigoSocio && lista[i].isEmpty==OCUPADO)
        {
            existeSocio=1;
            fflush(stdin);
            getValidInt("Esta seguro que quiere darle de baja a este socio? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

            switch(respuesta)
            {
            case 1:
                lista[i].isEmpty=VACIO;
                retorno=0;
                printf("Baja Exitosa\n");
                break;
            case 2:
                printf("Baja Cancelada\n");
                break;

            }

            break;
        }
    }

    if(existeSocio==0)
    {
        printf("ERROR, el socio no existe\n");
    }

    return retorno;
}

int ordenar_Socios(eSocio lista[],int tam )
{
    eSocio auxSocio;
    int retorno=-1;

    for(int i =0 ; i<tam-1 ; i ++)
    {
        for(int j= i+1 ; j<tam; j++)
        {
            if(strcmp(lista[j].apellido,lista[i].apellido)<0)
            {
                auxSocio = lista[i];
                lista[i] = lista[j];
                lista[j] = auxSocio;
            }
            else if(strcmp(lista[j].apellido,lista[i].apellido) ==0 && strcmp(lista[j].nombre,lista[i].nombre)<0)
            {
                auxSocio = lista[i];
                lista[i] = lista[j];
                lista[j] = auxSocio;
            }
        }


        retorno=0;
    }

    mostrar_Socios(lista,tam);
    return retorno;
}



int inicializar_Prestamo(ePrestamo lista[], int tam)
{
    int retorno=-1;

    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = VACIO;

        retorno=0;
    }

    return retorno;
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


int mostrar_Libros(eLibro lista[], int tam)
{

    int retorno=-1;

    printf(" Codigo de libro       Codigo de Autor    Titulo\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrar_libro(lista[i]);
        retorno=0;
    }

    return retorno;
}

void mostrar_libro(eLibro libros)
{


    printf("%5d   %20d   %20s   \n", libros.CodigoLibro,libros.codigoAutor,libros.titulo);

}

int mostrar_Autores(eAutores lista[], int tam)
{

    int retorno=-1;

    printf(" Codigo de Autor       Nombre de Autor    Apellido de Autor\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrar_Autor(lista[i]);
        retorno=0;
    }

    return retorno;
}

void mostrar_Autor(eAutores autores)
{


    printf("%5d   %20s   %20s   \n", autores.CodigoAutor,autores.nombre,autores.apellido);

}

//De aca para abajo verificar
int alta_Prestamos(ePrestamo listaPrestamos[],eSocio listaSocio[],eLibro listaLibro[],int tamSocio,int tamLibro,int tamPrestamo)
{

    int indice;
    int respuesta;
    int auxIdSocio;
    int auxIdLibro;
    int retorno=-1;


    indice = buscarLibre_Prestamo(listaPrestamos, tamPrestamo);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {

        system("cls");

        mostrar_Socios(listaSocio,tamSocio);
        printf("\ningrese codigo socio: ");
        scanf("%d",&auxIdSocio);



        mostrar_Libros(listaLibro,tamLibro);
        printf("ingrese codigo libro: ");
        scanf("%d",&auxIdLibro);

        printf("\nIngrese fecha de prestamo\n\n");
        cargarFecha_Prestamo(listaPrestamos,indice);



        //separo

        fflush(stdin);
        getValidInt("Esta seguro que quiere darle de alta a este Prestamo? <1.Si-2.No>","\Eerror ingrese un dato valido  <1-2>\n",1,2,&respuesta);

        if(respuesta==1)
        {

            listaPrestamos[indice].isEmpty = OCUPADO;
            listaPrestamos[indice].CodigoLibro=auxIdLibro;
            listaPrestamos[indice].CodigoSocio=auxIdSocio;
            listaPrestamos[indice].CodigoPrestamo=generarNextId_Prestamo();

            printf("Alta Prestamo exitosa!!!\n\n");

            retorno=0;

        }
        else
        {

            printf("alta cancelada");

        }
    }

    return retorno;





}

void cargarFecha_Prestamo(ePrestamo lista[],int indice)
{
    int auxDia;
    int auxMes;
    int auxAnio;


    getValidInt("Ingrese dia: ","\nPor favor ingrese un dia valido entre 1 y 30: \n",1,30,&auxDia);


    lista[indice].fechaPrestamo.dia=auxDia;


    getValidInt("Ingrese mes:","Por favor ingrese un mes valido entre 1 y 12: \n",1,12,&auxMes);

    lista[indice].fechaPrestamo.mes=auxMes;


    getValidInt("Ingrese anio: ","Por favor ingrese un anio valido entre 1980 y 2019: \n",2000,2030,&auxAnio);

    lista[indice].fechaPrestamo.anio=auxAnio;

}



//MOstar prestamos





void mostrar_Prestamo(ePrestamo prestamos)
{


    printf("%10d   %15d   %15d   %10d/%d/%d  \n",prestamos.CodigoLibro,prestamos.CodigoPrestamo,prestamos.CodigoSocio,prestamos.fechaPrestamo.dia,prestamos.fechaPrestamo.mes,prestamos.fechaPrestamo.anio);

}


int mostrar_Prestamos(ePrestamo lista[], int tam)
{

    int retorno=-1;

    printf(" Codigo de libro   Codigo de prestamo    Codigo de socio    SFecha De Prestamo\n\n");
    for(int i=0; i < tam; i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            mostrar_Prestamo(lista[i]);

            retorno=0;
        }
    }

    if( retorno == -1)
    {
        printf("\nNo hay Prestamos que mostrar\n");
    }

    return retorno;
}

//informes

void alquileresPorSocio(ePrestamo listaPrestamos[], int tamPrestamos,eSocio listaSocios[],int tamSocio, eLibro listaLibro[],int tamLibros)
{
    int auxCodCliente;
    mostrar_Socios(listaSocios,tamSocio);

    printf("\nIngresar Codigo socio: \n\n");
    fflush(stdin);
    scanf("%d",&auxCodCliente);
    int flag = 0;

    system("cls");
    printf("id   cod de libro:   cod de cliente:   fecha:   \n\n");

    for(int i=0; i < tamPrestamos; i++)
    {
        if(listaPrestamos[i].CodigoSocio==auxCodCliente && listaPrestamos[i].isEmpty==0)
        {
            mostrarPrestamos(listaPrestamos[i],listaSocios[i],listaLibro[i]);


            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay alquileres cargados para ese cliente");
    }
    printf("\n\n");
}


void mostrarPrestamos(ePrestamo prestamoMostrar,eSocio socioMostrar,eLibro libroMostrar)
{

    printf("\ncodigo de Prestamo: %d  codigo de libro: %d \nTitulo: %s \ncodigo de cliente:%d , fecha de alquiler: %02d/%02d/%d\n  nombre: %s\n",prestamoMostrar.CodigoPrestamo,libroMostrar.CodigoLibro,libroMostrar.titulo,socioMostrar.codigoSocio,prestamoMostrar.fechaPrestamo.dia,prestamoMostrar.fechaPrestamo.mes,prestamoMostrar.fechaPrestamo.anio,socioMostrar.nombre);

}




void libroPorSocio(ePrestamo listaPrestamo[], int tamPrestamo,eSocio listaSocio[],int tamSocio,eLibro listaLibro[],int tamLibro)
{
    int auxCodigoLibro;
    int auxCliente,index;

    mostrar_Libros(listaLibro,tamLibro);
    printf("\nIngresar el codigo de libro: \n\n");
    fflush(stdin);
    scanf("%d",&auxCodigoLibro);

    int flag = 0;

    system("cls");

    printf("id   cod de libro:   cod de cliente:   fecha:   \n\n");

    for(int i=0; i < tamPrestamo; i++)
    {
        if(listaPrestamo[i].CodigoLibro==auxCodigoLibro && listaPrestamo[i].isEmpty==0)
        {
            auxCliente=buscarSocio(listaSocio,tamSocio,listaPrestamo[i].CodigoSocio);

            index=listaPrestamo[i].CodigoSocio-1;
            mostrar_Socio(listaSocio[index]);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No se alquilo ese juego\n");
    }
    printf("\n\n");
}


int buscarSocio(eSocio lista[], int tam, int codigo)//devuelvo el indice del socio.
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].codigoSocio == codigo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}





int getOrder()
{
    int orden;
    printf("Ingrese el orden en que quiere ordenar el apellido de los socios\n0. Descendente\n1. Ascendente\n");
    scanf("%d", &orden);
    return orden;
}

int sortSocios(eSocio* listaSocio, int tamSocio, int orde)
{
    int ret = ERROR;
    eSocio aux;
    if(tamSocio > 0 && listaSocio != NULL)
    {
        switch(orde)
        {
        case DESCENDENTE:
            for(int i = 0; i < tamSocio - 1; i++)
            {
                for(int j = i + 1; j < tamSocio; j++)
                {
                    if(strcmp(listaSocio[j].apellido, listaSocio[i].apellido) > 0 && listaSocio[j].isEmpty == OCUPADO && listaSocio[i].isEmpty == OCUPADO)
                    {
                        aux = listaSocio[i];
                        listaSocio[i] = listaSocio[j];
                        listaSocio[j] = aux;
                    }
                    else if(strcmp(listaSocio[j].apellido, listaSocio[i].apellido) == 0  && listaSocio[j].isEmpty == OCUPADO && listaSocio[i].isEmpty == OCUPADO)
                    {
                        aux = listaSocio[i];
                        listaSocio[i] = listaSocio[j];
                        listaSocio[j] = aux;
                    }
                }
            }
            ret = EXITO;
            break;
        case ASCENDENTE:
            for(int i = 0; i < tamSocio - 1; i++)
            {
                for(int j = i + 1; j < tamSocio; j++)
                {
                    if(strcmp(listaSocio[j].apellido, listaSocio[i].apellido) < 0  && listaSocio[j].isEmpty == OCUPADO && listaSocio[i].isEmpty == OCUPADO)
                    {
                        aux = listaSocio[i];
                        listaSocio[i] = listaSocio[j];
                        listaSocio[j] = aux;
                    }
                    else if(strcmp(listaSocio[j].apellido, listaSocio[i].apellido) == 0   && listaSocio[j].isEmpty == OCUPADO && listaSocio[i].isEmpty == OCUPADO)
                    {
                        aux = listaSocio[i];
                        listaSocio[i] = listaSocio[j];
                        listaSocio[j] = aux;
                    }
                }
            }
            ret = EXITO;
            break;
        default:
            printf("Opcion de ordenamiento invalida ");
        }
    }
    return ret;
}
