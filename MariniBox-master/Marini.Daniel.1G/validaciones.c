#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"


/** \brief muestra el menu de opciones
 *
 * \return opcion seleccionada por el usuario
 *
 */

int menu()
{
    int opcion;

    do
    {
        system("cls");
        printf("\n*** Menu de Opciones ***\n\n");
        printf(" 1-  Alta de Cliente.\n");
        printf(" 2-  Baja de Cliente.\n");
        printf(" 3-  Modificacion de Clientes.\n");
        printf(" 4-  Listar Clientes.\n");
        printf(" 5-  Alta de Alquiler.\n");
        printf(" 6-  Listar Alquileres.\n");
        printf(" 7-  Listar Juegos categorias.\n");
        printf(" 8-  Mostrar juegos de mesa\n");
        printf(" 9-  Salir\n\n");
        printf("\n Ingrese opcion: \n");
        scanf("%d", &opcion);

        if(opcion < 1 || opcion > 9)
        {
            printf("\nOpcion incorrecta.\n");
        }
    }
    while(opcion < 1 || opcion > 9);
    return opcion;
}

/** \brief menu de opciones de la modificacion
 *
 * \return  opcion
 *
 */

int submenu()
{
    int opcion;

    do
    {
        system("cls");
        printf("\n*** Seleccione una Opcion a modificar ***\n\n");
        printf(" 1-  Nombre.\n");
        printf(" 2-  Sexo.\n");
        printf(" 3-  Telefono.\n");
        printf("\n Ingrese opcion: \n");
        scanf("%d", &opcion);

        if(opcion < 1 || opcion > 3)
        {
            printf("\nOpcion incorrecta.\n");
            system("pause");
            fflush(stdin);
        }
    }
    while(opcion < 1 || opcion > 3);

    return opcion;
}

/** \brief de alta un cliente siempre q su codigo sea 0
 *
 * \param vector clientes
 * \param tamaño
 * \return OK or 1
 *
 */

int altaCliente(eCliente clientes[], int tam)
{
    int retorno = 1;
    eCliente cliente;
    int cod;
    int validar = 0;
    char nombre[51];
    char sexo;
    char telefono[21];

    do
    {

        fflush(stdin);

        if (!getStringLetras("Ingrese el nombre: ",nombre))
        {
            printf("el nombre solo contiene letras, no numeros.");
        }


    }
    while(validar == 1);

    do
    {
        fflush(stdin);
        printf("\nIngrese el sexo [f/m]: ");
        fflush(stdin);
        scanf("%c", &sexo);
        cliente.sexo = sexo;
        validar = validarSexo(sexo);

    }
    while(validar == 1);

    do
    {
        fflush(stdin);
        printf("\nIngrese un Telefono: \n\n");
        fflush(stdin);
        scanf("%s", telefono);
        strcpy(cliente.Telefono,telefono);
        validar = validarTelefono(telefono);
    }
    while(validar == 1);

    fflush(stdin);


    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].Codigo == 0)
        {
            cod = (tam + i);

            clientes[i].Codigo = cod;
            strcpy(clientes[i].Nombre, nombre);
            clientes[i].sexo = sexo;
            strcpy(clientes[i].Telefono, telefono);
            retorno = 0;
            break;
        }
    }
    return retorno;
}


/** \brief baja logica del cliente
 *
 * \param vector clientes
 * \param tamaño
 * \return OK or 1
 *
 */

int bajaCliente(eCliente clientes[], int tam)
{
    int retorno = 1;
    int cod;
    int existe;
    listarClientes(clientes,tam);
    printf("\nIngrese un Codigo de cliente: \n\n");
    scanf("%d", &cod);
    existe = existeCliente(clientes, tam, cod);
    if(existe == 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].Codigo == cod)
            {
                retorno = 0;
                clientes[i].Codigo = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief retorna si existe el empleado
 *
 * \param vcctor cliente
 * \param tamaño
 * \param codigo
 * \return OK or 1
 *
 */

int existeCliente(eCliente clientes[], int tam, int codigo)
{
    int retorno = 1;

    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].Codigo == codigo)
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

/** \brief verifica si hay alquileres en el vector
 *
 * \param vector alquiler
 * \param tamaño vector
 * \return ok or err
 *
 */

int hayAlquileres(eAlquileres alquiler[], int tam)
{
    int retorno = 1;

    for(int i = 0; i < tam; i++)
    {
        if(alquiler[i].CodigoAlquiler > 0)
        {
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief verifica si hay clientes en el cursor
 *
 * \param vector clientes
 * \param tamaño vector
 * \return ok si hay clientes, err si no hay
 *
 */

int hayClientes(eCliente clientes[], int tam)
{
    int retorno = 1;

    for(int i = 0; i < tam; i++)
    {
        if(clientes[i].Codigo > 0)
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

/** \brief modifica un campo del cliente
 *
 * \param vector cliente
 * \param  tamaño del vector
 * \return opcion seleccionada por el usuario
 *
 */

int modificarCliente(eCliente clientes[], int tam)
{
    int retorno = 1;
    int codigocliente;
    char nombre[51];
    char sexo;
    char telefono[21];
    int existe;
    int validar;
    int opcion;

    opcion = submenu();


    listarClientes(clientes,tam);
    printf("\nIngrese un Codigo de Cliente.\n");
    scanf("%d", &codigocliente);

    existe = existeCliente(clientes, tam, codigocliente);

    if(existe == 0)
    {

        for(int i = 0; i < tam; i++)
        {
            if(clientes[i].Codigo == codigocliente)
            {
                switch(opcion)
                {
                case 1:
                    do
                    {
                        fflush(stdin);

                        if (!getStringLetras("Ingrese el nombre: ",nombre))
                        {
                            printf ("El nombre debe estar compuesto solo por letras\n");
                            break;
                        }
                        else
                        {
                            validar =1;

                        }
                    }
                    while(validar == 1);
                    fflush(stdin);
                    strcpy(clientes[i].Nombre,nombre);
                    retorno = 0;
                    break;
                case 2:
                    do
                    {
                        fflush(stdin);
                        printf("\nIngrese un sexo: \n");
                        scanf("%c", &sexo);
                        validar = validarSexo(sexo);
                    }
                    while(validar == 1);
                    clientes[i].sexo = sexo;
                    retorno = 0;
                    break;
                case 3:
                    do
                    {
                        fflush(stdin);
                        printf("\nIngrese un Telefono: \n");
                        scanf("%s", telefono);
                        validar = validarTelefono(telefono);
                    }
                    while(validar == 1);
                    strcpy(clientes[i].Telefono,telefono);
                    retorno = 0;
                    break;
                case 4:
                    printf("Usted cancelo la operacion");

                    break;
                }
            }
        }

    }
    return retorno;
}


/** \brief mostrar la lista de clientes
 *
 * \param vector clientes
 * \param tamaño del vector
 *
 */

void listarClientes(eCliente vClientes[], int tam)
{
    ordenarClientes(vClientes, tam);

    printf("\nCodigo    Nombre      Sexo        Telefono\n");

    for(int i = 0; i < tam; i++)
    {
        fflush(stdin);
        if(vClientes[i].Codigo != 0)
        {
            printf("%4d    %10s      %2c        %s\n", vClientes[i].Codigo, vClientes[i].Nombre, vClientes[i].sexo, vClientes[i].Telefono);
        }
    }
}

/** \brief inicializa el vector de clientes
 *
 * \param vector clientes
 * \param tamaño del vector
 * \return nothing
 *
 */

void inicializarClientes(eCliente clientes[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        clientes[i].Codigo = 0;
        strcpy(clientes[i].Nombre,"");
        //clientes[i].sexo = "";
        strcpy(clientes[i].Telefono,"");
    }
}

/** \brief ordena el vector de clientes
 *
 * \param vector clientes
 * \param tamaño vector
 * \return nothing
 *
 */

void ordenarClientes(eCliente clientes[], int tam)
{
    //ordenar por sexo y nombre

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(clientes[i].sexo > clientes[j].sexo && clientes[i].Codigo > 0 && clientes[j].Codigo > 0)
            {
                eCliente aux;
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
            else if(clientes[i].sexo == clientes[j].sexo  && strcmp(clientes[i].Nombre,clientes[j].Nombre) > 0 && clientes[i].Codigo > 0 && clientes[j].Codigo > 0)
            {
                eCliente aux;
                aux = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = aux;
            }
        }
    }
}

/** \brief da de alta un alquiler y lo almacena en el vector alquileres
 *
 * \param VECTOR alquileres
 * \param tamaño vector alquileres
 * \param vector juegos
 * \param tamaño vector juegos
 * \param vector clientes
 * \param tamaño vector clientes
 * \return OK or 1
 *
 */

int altaAlquiler(eAlquileres alquiler[], int tam, eJuego juegos[], int tamj, eCliente clientes[], int tamc,eCategoria categoria[])
{

    int retorno = 0;
    eAlquileres unAlquiler;
    int existe = 0;
    int hayclientesenvector;

    hayclientesenvector = hayClientes(clientes, tamc);

    if(hayclientesenvector == 0)
    {

        do
        {
            listarJuegos(juegos,tam,categoria);
            fflush(stdin);
            if(existe == 1)
            {

                printf("\nCodigo de Juego incorrecto\n");
            }
            fflush(stdin);
            printf("\nIngrese el codigo del juego\n");
            fflush(stdin);
            scanf("%d", &unAlquiler.CodigoJuego);
            int cod = unAlquiler.CodigoJuego;
            existe = existeJuego(juegos, tamj, cod);

        }
        while(existe == 1);


        do
        {
            listarClientes(clientes,tam);
            if(existe == 1)
            {
                printf("\nCodigo de cliente incorrecto\n");
            }
            fflush(stdin);
            printf("\nIngrese el codigo del cliente\n");
            fflush(stdin);
            scanf("%d", &unAlquiler.CodigoCliente);
            int icli = unAlquiler.CodigoCliente;
            existe = existeCliente(clientes, tamc, icli);
            system("cls");
        }
        while(existe == 1);


        printf("\nIngrese un dia: ");
        scanf("%d", &unAlquiler.fecha.dia);

        printf("\nIngrese un mes: ");
        scanf("%d", &unAlquiler.fecha.mes);

        printf("\nIngrese un año: ");
        scanf("%d", &unAlquiler.fecha.anio);

        for(int i = 0; i < tam; i++)
        {
            if(alquiler[i].CodigoAlquiler == 0)
            {
                unAlquiler.CodigoAlquiler = tam + i;
                alquiler[i] = unAlquiler;
                break;
            }
        }

    }
    else
    {
        retorno = 1;
    }
    return retorno;
}

/** \brief muestra la lista del contenido del vector alquileres
 *
 * \param vector alquileres
 * \param tamaño vector alquiler
 * \return
 *
 */

void listarAlquileres(eAlquileres alquiler[], int tama, eCliente clientes[], int tamcl, eJuego juegos[], int tamj, eCategoria categorias[], int tamca)
{
    printf("\nCodAlquiler       Juego               Categoria               Cliente     Fecha\n");
    fflush(stdin);

    char auxCategoria[51] = "";
    char auxJuego[21] = "";
    char nombrecliente[51] = "";

    for(int i = 0; i < tama; i++)
    {
        if(alquiler[i].CodigoAlquiler > 0)
        {
            fflush(stdin);
            getJuego(juegos, tamj, alquiler[i].CodigoJuego, auxJuego);
            fflush(stdin);
            getCliente(clientes, tamcl, alquiler[i].CodigoCliente, nombrecliente);
            fflush(stdin);
            getCategoria(categorias, tamca, juegos, tamj, alquiler[i].CodigoJuego, auxCategoria);

            printf("\n%4d %20s %20s %20s %d/%d/%d\n", alquiler[i].CodigoAlquiler, auxJuego, auxCategoria, nombrecliente, alquiler[i].fecha.dia, alquiler[i].fecha.mes, alquiler[i].fecha.anio);
        }
    }
}

/** \brief devuelve la descripcion del codigo del juego seleccionado
 *
 * \param vector juego
 * \param tamaño vector
 * \param codigo juego
 */

void getJuego(eJuego juegos[], int tamj, int codj, char desc[])
{
    for(int i = 0; i < tamj; i++)
    {
        if(juegos[i].Codigo == codj)
        {
            strcpy(desc, juegos[i].Descripcion);
            break;
        }
    }
}

/** \brief devuelve la categoria del juego
 *
 * \param vector categoria
 * \param tamaño vector categoria
 * \param vector juego
 * \param tamaño vector juego
 * \param codigo juego
 *
 */

void getCategoria(eCategoria categorias[], int tamc, eJuego juegos[], int tamj, int codj, char desc[])
{
    int flag = 1;
    for(int i = 0; i < tamj; i++)
    {
        if(juegos[i].Codigo == codj)
        {
            for(int j = 0; j < tamc; j++)
            {
                if(categorias[j].id == juegos[i].idCategoria)
                {
                    strcpy(desc, categorias[j].Descripcion);
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
            {
                break;
            }
        }
    }
}

/** \brief devuelve el nombre del cliente
 *
 * \param vector cliente
 * \param tamaño vector cliente
 * \param codigo cliente
 *
 */

void getCliente(eCliente clientes[], int tamc, int codcliente, char nombre[])
{
    for(int i = 0; i < tamc; i++)
    {
        if(clientes[i].Codigo == codcliente)
        {
            strcpy(nombre, clientes[i].Nombre);
        }
    }
}

/** \brief inicializa el vector de alquileres
 *
 * \param vector alquiler
 * \param tamaño vector alquiler
 * \return nothing
 *
 */

void inicializarAlquileres(eAlquileres alquiler[], int tam)
{
    eFecha dFecha;
    dFecha.dia = 1;
    dFecha.mes = 1;
    dFecha.anio = 1900;
    for(int i = 0; i < tam; i++)
    {
        alquiler[i].CodigoAlquiler = 0;
        alquiler[i].CodigoCliente = 0;
        alquiler[i].CodigoJuego = 0;
        alquiler[i].fecha = dFecha;
    }
}

/** \brief verifica si existe el juego ingresado
 *
 * \param vector juegos
 * \param tamaño vector
 * \param codigo juego ingresado por el usuario
 * \return OK or 1
 *
 */

int existeJuego(eJuego juegos[], int tam, int cod)
{
    int retorno = 1;

    for(int i = 0; i < tam; i++)
    {
        if(juegos[i].Codigo == cod)
        {
            retorno = 0;
        }
    }

    return retorno;
}



/** \brief valida si el sexo es valido
 *
 * \param sexo ingresado por el usuario
 * \param
 * \return OK or 1
 *
 */

int validarSexo(char sexo)
{
    int retorno = 0;

    if(sexo != 'm' && sexo != 'f')
    {
        retorno = 1;
        printf("\nEl sexo es incorrecto\n");
    }
    return retorno;
}

/** \brief valida que el telefono sea valido
 *
 * \param telefono ingresado por el usuario
 * \param
 * \return OK or 1
 *
 */

int validarTelefono(char tel[])
{
    int retorno = 0;

    if(strlen(tel) > 20)
    {
        retorno = 1;
        printf("\nEl telefono es demasiado extenso\n");
    }
    return retorno;
}

/** \brief devuelve el id de categoria segun el indice
 *
 * \param vector categoria
 * \param tamaño vector
 * \param indice a buscar
 * \return idcategori
 *
 */

int getIDCategoria(eCategoria categorias[], int tam, int indice)
{
    int id;

    for(int i = 0; i < tam; i++)
    {
        if(i == indice)
        {
            id = categorias[i].id;
        }
    }

    return id;
}

/** \brief harcode cargar vector juegos
 *
 * \param vector juegos
 * \param tamaño vector
 * \return nothing
 *
 */

void cargarJuegos(eJuego juegos[], int tam, eCategoria categorias[], int tamc)
{
    eJuego harcodeJuegos[] =
    {
        {1, "Monopolis", 50.75, getIDCategoria(categorias, tamc, 0)},
        {2, "Billar", 150.00, getIDCategoria(categorias, tamc, 1)},
        {3, "TEC", 50.00, getIDCategoria(categorias, tamc, 2)},
        {4, "PING PONG", 100.30, getIDCategoria(categorias, tamc, 3)},
        {5, "Disney Magic", 300.50, getIDCategoria(categorias, tamc, 4)}
    };

    for(int i = 0; i < tam; i++)
    {
        juegos[i] = harcodeJuegos[i];
    }
}
void listarJuegos(eJuego juegos[],int tam,eCategoria categorias[])
{



    for(int i = 0; i < 5; i++)
    {
        fflush(stdin);
        if(juegos[i].Codigo != 0)
        {
            printf("\n%5d  %10s %5d  %.2f %c ", juegos[i].Codigo,juegos[i].Descripcion,juegos[i].idCategoria,juegos[i].Importe,categorias[i].Descripcion);
        }
    }

}


void listarCategorias(eCategoria categorias[],int tam)
{

    printf("\n$$$Estas son las categorias$$$ \n");


    for(int i = 0; i < tam; i++)
    {

        fflush(stdin);
        if(categorias[i].Descripcion != 0)
        {

            printf("   %10s \n", categorias[i].Descripcion);
        }
    }
}




/** \brief harcode categorias
 *
 * \param vector categorias
 * \param tamaño vector
 * \return nothing
 *
 */
void cargarCategorias(eCategoria categorias[], int tam)
{
    eCategoria sCategoria[] =
    {
        {1, "Juegos de Mesa"},
        {2, "Juegos de Azar"},
        {3, "Juegos de Estrategia"},
        {4, "Juegos de Salon"},
        {5, "Juegos de Magia"}
    };

    for(int i = 0; i < tam; i++)
    {
        categorias[i] = sCategoria[i];
    }
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    int i=0;
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        i++;
    }
    return i;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}


/*void mostrarJuegosDeMesa(eJuego juegos[],int tamJue,eCategoria categorias[],int tamCat)
{

   system("cls");
   printf("Listado de juegos de mesa\n\n");

   for(int i=0 ; i<tamJue ; i++)
   {

       if(juegos[i].idCategoria==5 )
       {
           listarJuego(juegos);
       }
       printf("\n\n");


   }

}

*/
