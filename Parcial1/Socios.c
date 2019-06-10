#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Socios.h"





void init_Socios(eSocio socios[], int tam)
{
    int codigoSocio[10] = {1, 2, 3, 4, 5,6, 7, 8, 9, 10};
    char nombre[10][31]= {"Pepe","Daniel","Jon","Bill ","Charlie","Laura","Miriam","Sansa","Bran ","Lydia"};
    char apellido[10][31]= {"Toro","Marini","Snow","licker","Day","Jurez","Silva","Stark","Stark","Diaz"};
    char sexo[10]= {'M','M','M','M','M','F','F','F','M','F'};
    char telefono[10][31]= {"234-123","524-234","987-542","654-312 ","456-567","524-873","246-631","246-123","554-978 ","432-135"};;
    char eMail[10][31]= {"PeLado@out.com","Danielito@out.com","Prox0@yah.com","HITCH@off.com","TORITA@yah.com","Silva21@out.com","Miriamq2@off.com","Stark@yah.com","Stark2@off.com","Diaz1@out.com"};;
    eFecha fechaDeAsociado[10]= {{9,5,2001},{1,9,1975},{2,10,2008},{24,12,2019},{15,1,2012},{12,2,1993},{28,3,1984},{7,4,1981},{5,5,1998},{13,7,2002} };


    for(int i=0; i<10; i++)
    {
        socios[i].codigoSocio=codigoSocio[i];

        strcpy(socios[i].nombre, nombre[i]);

        strcpy(socios[i].apellido, apellido[i]);

        socios[i].sexo=sexo[i];

        strcpy(socios[i].telefono, telefono[i]);

        strcpy(socios[i].eMail, eMail[i]);

        socios[i].fechaDeAsociado=fechaDeAsociado[i];

        generarNextId();

        socios[i].isEmpty=OCUPADO;
    }

}


int inicializar_Socios(eSocio lista[], int tam)
{
    int myReturn=-1;

    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = VACIO;

        myReturn=0;
    }

    return myReturn;
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
    int myReturn=-1;


    indice = buscarLibre(lista, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {



        fflush(stdin);
        getValidString("\nIngrese nombre: ","\nError por favor solo ingrese caracteres","\nError se exedio del limite de caracteres\n",auxNombre,1,30);
        stringToUpper(auxNombre);

        strcpy(lista[indice].nombre,auxNombre);
        system("cls");

        fflush(stdin);
        getValidString("Ingrese apellido: ","\nError por favor solo ingrese caracteres","\nError se exedio del limite de caracteres\n",auxApellido,1,30);
        stringToUpper(auxApellido);

        strcpy(lista[indice].apellido,auxApellido);
        system("cls");

        fflush(stdin);
        getSexChar("ingrese sexo","Error ingrese sexo: valido <F-M>\n",&auxSexo);

        lista[indice].sexo=auxSexo;

        system("cls");


        fflush(stdin);
        getString("ingrese telefono (debe tener un guion y 6 numeros): ",auxTelefono);

        while(! (esTelefono(auxTelefono,7,7) ) )
        {

            fflush(stdin);
            getString("Reingrese telefono: (debe tener un guion y 6 numeros)",auxTelefono);

        }


        strcpy(lista[indice].telefono,auxTelefono);

        system("cls");

        fflush(stdin);
        getString("ingrese email(debe tener un almenos un @ y no empezar con un numero ): ",auxEmail);

        while(! (esEmail(auxEmail) ) )
        {

            fflush(stdin);
            getString("Reingrese email: (debe tener un almenos un @ y no empezar con un numero )",auxEmail);

        }


        strcpy(lista[indice].eMail,auxEmail);

        printf("\nIngrese su fecha de ingreso\n\n");
        cargarFecha_Socios(lista,indice);

        fflush(stdin);
        getValidInt("Esta seguro que quiere darle de alta a este socio? <1.Si-2.No>","\Eerror ingrese un dato valido  <1-2>\n",1,2,&respuesta);




        if(respuesta==1)
        {

            lista[indice].isEmpty = OCUPADO;

            lista[indice].codigoSocio=generarNextId();

            printf("Alta socio exitosa!!!\n\n");

            myReturn=0;

        }
        else
        {

            printf("alta cancelada");

        }
    }

    return myReturn;
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


    getValidInt("Ingrese anio: ","Por favor ingrese un anio valido entre 1960 y 2030: \n",1980,2019,&auxAnio);

    lista[indice].fechaDeAsociado.anio=auxAnio;
}

void mostrar_Socio(eSocio socio)
{

    printf("%2d   %9s   %7s   %5c   %10s  %10s %7d/%d/%d\n", socio.codigoSocio, socio.nombre,socio.apellido, socio.sexo,socio.telefono,socio.eMail,socio.fechaDeAsociado.dia,socio.fechaDeAsociado.mes,socio.fechaDeAsociado.anio);

}


int mostrar_Socios(eSocio lista[], int tam)
{

    int retorno=-1;

    printf(" Codigo   Nombre    Apellido   Sexo     Telefono   Email      Fecha De Asociado\n\n");
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
        printf("\nNo hay socios que mostrar\n");
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

    mostrar_Socios(lista,tam);
    printf("\nQue socio queres modificar? (Ingresar Codigo socio) ");
    fflush(stdin);
    scanf("%d",&auxLegajo);


    indice=buscar_Socios_PorId(lista,tam,auxLegajo);

    if(auxLegajo==lista[indice].codigoSocio && lista[indice].isEmpty==OCUPADO)
    {
        existeSocio=1;

        fflush(stdin);
        getValidInt("Esta seguro que quiere modificar a este socio? <1.Si-2.No>","ERROR, ingrese una opcion valida <1-2>",1,2,&respuesta);

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
        printf("ERROR, el socio no existe\n");
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
            getString("ingrese telefono (debe tener un guion y 6 numeros): ",auxNewTelefono);

            while(! (esTelefono(auxNewTelefono,7,7) ) )
            {
                fflush(stdin);
                getString("Reingrese telefono: (debe tener un guion y 6 numeros)",auxNewTelefono);

            }

            strcpy(lista[indice].telefono,auxNewTelefono);

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
            getString("ingrese email(debe tener un almenos un @ y no empezar con un numero ): ",auxNewEmail);

            while(! (esEmail(auxNewEmail) ) )
            {
                fflush(stdin);
                getString("Reingrese email: (debe tener un almenos un @ y no empezar con un numero )",auxNewEmail);

            }
            strcpy(lista[indice].eMail, auxNewEmail);

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

void cargarDescripcion_Socio(eSocio listaSocios[], int tamSocios, int idSocios, char apellido[],char nombre[])
{
    for(int i=0; i < tamSocios; i++)
    {
        if( listaSocios[i].codigoSocio == idSocios)
        {
            strcpy(nombre, listaSocios[i].nombre);
            strcpy(apellido, listaSocios[i].apellido);
            break;
        }
    }
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
