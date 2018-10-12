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
        printf(" 1-  Alta de Cliente\n");
        printf(" 2-  Baja de Cliente\n");
        printf(" 3-  Modificacion de Cliente\n");
        printf(" 4-  Listar Clientes\n");
        printf(" 5-  Alta de Alquiler\n");
        printf(" 6-  Listar Alquileres\n");
        printf(" 7- Salir\n\n");
        printf("\n Ingrese opcion: \n");
        scanf("%d", &opcion);

        if(opcion < 1 || opcion > 7)
        {
            printf("\nOpcion incorrecta\n");
        }
    }
    while(opcion < 1 || opcion > 7);
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

int altaCliente(eCliente vCliente[], int tam)
{
    int ret = 1;
    eCliente cli;
    char vNombre[51];
    char vsexo;
    char vtelefono[21];
    int cod;
    int validar = 0;

    do
    {

         fflush(stdin);

        if (!getStringLetras("Ingrese el nombre: ",vNombre))
                {
                    printf(
                           "el nombre solo contiene letras, no numeros.");
                }

    }
    while(validar == 1);

    do
    {
        fflush(stdin);
        printf("\nIngrese el sexo: \n\n");
        fflush(stdin);
        scanf("%c", &vsexo);
        cli.sexo = vsexo;
        validar = validarSexo(vsexo);

    }
    while(validar == 1);

    do
    {
        fflush(stdin);
        printf("\nIngrese un Telefono: \n\n");
        fflush(stdin);
        scanf("%s", vtelefono);
        strcpy(cli.Telefono,vtelefono);
        validar = validarTelefono(vtelefono);
    }
    while(validar == 1);

    fflush(stdin);


    for(int i = 0; i < tam; i++)
    {
        if(vCliente[i].Codigo == 0)
        {
            cod = (tam + i);
            //cli.Codigo = cod;
            //vCliente[i] = cli;
            vCliente[i].Codigo = cod;
            strcpy(vCliente[i].Nombre, vNombre);
            vCliente[i].sexo = vsexo;
            strcpy(vCliente[i].Telefono, vtelefono);
            ret = 0;
            break;
        }
    }
    return ret;
}


/** \brief baja logica del cliente
 *
 * \param vector clientes
 * \param tamaño
 * \return OK or 1
 *
 */

int bajaCliente(eCliente vCliente[], int tam)
{
    int ret = 1;
    int cod;
    int existe;
    printf("\nIngrese un Codigo\n\n");
    scanf("%d", &cod);
    existe = existeCliente(vCliente, tam, cod);
    if(existe == 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(vCliente[i].Codigo == cod)
            {
                ret = 0;
                vCliente[i].Codigo = 0;
                break;
            }
        }
    }
    return ret;
}

/** \brief retorna si existe el empleado
 *
 * \param vcctor cliente
 * \param tamaño
 * \param codigo
 * \return OK or 1
 *
 */

int existeCliente(eCliente vCliente[], int tam, int codigo)
{
    int ret = 1;

    for(int i = 0; i < tam; i++)
    {
        if(vCliente[i].Codigo == codigo)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

/** \brief verifica si hay alquileres en el vector
 *
 * \param vector alquiler
 * \param tamaño vector
 * \return ok or err
 *
 */

int hayAlquileres(eAlquileres vAlquiler[], int tam)
{
    int ret = 1;

    for(int i = 0; i < tam; i++)
    {
        if(vAlquiler[i].CodigoAlquiler > 0)
        {
            ret = 0;
        }
    }
    return ret;
}

/** \brief verifica si hay clientes en el cursor
 *
 * \param vector clientes
 * \param tamaño vector
 * \return ok si hay clientes, err si no hay
 *
 */

int hayClientes(eCliente vCliente[], int tam)
{
    int ret = 1;

    for(int i = 0; i < tam; i++)
    {
        if(vCliente[i].Codigo > 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;
}

/** \brief modifica un campo del cliente
 *
 * \param vector cliente
 * \param  tamaño del vector
 * \return opcion seleccionada por el usuario
 *
 */

int modificarCliente(eCliente vCliente[], int tam)
{
    int ret = 1;
    int codigocliente;
    char sNombre[51];
    char sSexo;
    char sTelefono[21];
    int existe;
    int validar;
    int opc;

    opc = submenu();


    listarClientes(vCliente,tam);
    printf("\nIngrese un Codigo de Cliente.\n");
    scanf("%d", &codigocliente);

    existe = existeCliente(vCliente, tam, codigocliente);

    if(existe == 0)
    {

        for(int i = 0; i < tam; i++)
        {
            if(vCliente[i].Codigo == codigocliente)
            {
                switch(opc)
                {
                case 1:
                    do
                    {
                          fflush(stdin);

        if (!getStringLetras("Ingrese el nombre: ",sNombre))
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
                    strcpy(vCliente[i].Nombre,sNombre);
                    ret = 0;
                    break;
                case 2:
                    do
                    {
                        fflush(stdin);
                        printf("\nIngrese un sexo\n");
                        scanf("%c", &sSexo);
                        validar = validarSexo(sSexo);
                    }
                    while(validar == 1);
                    vCliente[i].sexo = sSexo;
                    ret = 0;
                    break;
                case 3:
                    do
                    {
                        fflush(stdin);
                        printf("\nIngrese un Telefono\n");
                        scanf("%s", sTelefono);
                        validar = validarTelefono(sTelefono);
                    }
                    while(validar == 1);
                    strcpy(vCliente[i].Telefono,sTelefono);
                    ret = 0;
                    break;
                }
            }
        }

    }
    return ret;
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
            printf("%4d    %20s      %c        %s\n", vClientes[i].Codigo, vClientes[i].Nombre, vClientes[i].sexo, vClientes[i].Telefono);
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

void inicializarClientes(eCliente vCliente[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vCliente[i].Codigo = 0;
        strcpy(vCliente[i].Nombre,"");
        //vCliente[i].sexo = "";
        strcpy(vCliente[i].Telefono,"");
    }
}

/** \brief ordena el vector de clientes
 *
 * \param vector clientes
 * \param tamaño vector
 * \return nothing
 *
 */

void ordenarClientes(eCliente vCliente[], int tam)
{
    //ordenar por sexo y nombre

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(vCliente[i].sexo > vCliente[j].sexo && vCliente[i].Codigo > 0 && vCliente[j].Codigo > 0)
            {
                eCliente aux;
                aux = vCliente[i];
                vCliente[i] = vCliente[j];
                vCliente[j] = aux;
            }
            else if(vCliente[i].sexo == vCliente[j].sexo  && strcmp(vCliente[i].Nombre,vCliente[j].Nombre) > 0 && vCliente[i].Codigo > 0 && vCliente[j].Codigo > 0)
            {
                eCliente aux;
                aux = vCliente[i];
                vCliente[i] = vCliente[j];
                vCliente[j] = aux;
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

int altaAlquiler(eAlquileres vAlquiler[], int tam, eJuego vJuego[], int tamj, eCliente vCliente[], int tamc)
{
    //int codigoalquiler;
    //int codigojuego;
    //int codigocliente;
    int ret = 0;
    eAlquileres unAlquiler;
    int existe = 0;
    int hayclientesenvector;

    hayclientesenvector = hayClientes(vCliente, tamc);

    if(hayclientesenvector == 0)
    {

        do
        {
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
            existe = existeJuego(vJuego, tamj, cod);
        }
        while(existe == 1);


        do
        {
            if(existe == 1)
            {
                printf("\nCodigo de cliente incorrecto\n");
            }
            fflush(stdin);
            printf("\nIngrese el codigo del cliente\n");
            fflush(stdin);
            scanf("%d", &unAlquiler.CodigoCliente);
            int icli = unAlquiler.CodigoCliente;
            existe = existeCliente(vCliente, tamc, icli);
        }
        while(existe == 1);


        printf("\nIngrese un dia\n");
        scanf("%d", &unAlquiler.fecha.dia);

        printf("\nIngrese un mes\n");
        scanf("%d", &unAlquiler.fecha.mes);

        printf("\nIngrese un año\n");
        scanf("%d", &unAlquiler.fecha.anio);

        for(int i = 0; i < tam; i++)
        {
            if(vAlquiler[i].CodigoAlquiler == 0)
            {
                unAlquiler.CodigoAlquiler = tam + i;
                vAlquiler[i] = unAlquiler;
                break;
            }
        }

    }
    else
    {
        ret = 1;
    }
    return ret;
}

/** \brief muestra la lista del contenido del vector alquileres
 *
 * \param vector alquileres
 * \param tamaño vector alquiler
 * \return
 *
 */

void listarAlquileres(eAlquileres vAlquiler[], int tama, eCliente vCliente[], int tamcl, eJuego vJuego[], int tamj, eCategoria vCategoria[], int tamca)
{
    printf("\nCodAlquiler       Juego               Categoria               Cliente     Fecha\n");
    fflush(stdin);

    char desccategoria[51] = "";
    char descjuego[21] = "";
    char nombrecliente[51] = "";

    for(int i = 0; i < tama; i++)
    {
        if(vAlquiler[i].CodigoAlquiler > 0)
        {
            fflush(stdin);
            getJuego(vJuego, tamj, vAlquiler[i].CodigoJuego, descjuego);
            fflush(stdin);
            getCliente(vCliente, tamcl, vAlquiler[i].CodigoCliente, nombrecliente);
            fflush(stdin);
            getCategoria(vCategoria, tamca, vJuego, tamj, vAlquiler[i].CodigoJuego, desccategoria);

            printf("\n%4d %20s %20s %20s %d/%d/%d\n", vAlquiler[i].CodigoAlquiler, descjuego, desccategoria, nombrecliente, vAlquiler[i].fecha.dia, vAlquiler[i].fecha.mes, vAlquiler[i].fecha.anio);
        }
    }
}

/** \brief devuelve la descripcion del codigo del juego seleccionado
 *
 * \param vector juego
 * \param tamaño vector
 * \param codigo juego
 */

void getJuego(eJuego vJuego[], int tamj, int codj, char desc[])
{
    for(int i = 0; i < tamj; i++)
    {
        if(vJuego[i].Codigo == codj)
        {
            strcpy(desc, vJuego[i].Descripcion);
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

void getCategoria(eCategoria vCategoria[], int tamc, eJuego vJuego[], int tamj, int codj, char desc[])
{
    int flag = 1;
    for(int i = 0; i < tamj; i++)
    {
        if(vJuego[i].Codigo == codj)
        {
            for(int j = 0; j < tamc; j++)
            {
                if(vCategoria[j].id == vJuego[i].idCategoria)
                {
                    strcpy(desc, vCategoria[j].Descripcion);
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

void getCliente(eCliente vCliente[], int tamc, int codcliente, char nombre[])
{
    for(int i = 0; i < tamc; i++)
    {
        if(vCliente[i].Codigo == codcliente)
        {
            strcpy(nombre, vCliente[i].Nombre);
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

void inicializarAlquileres(eAlquileres vAlquiler[], int tam)
{
    eFecha dFecha;
    dFecha.dia = 1;
    dFecha.mes = 1;
    dFecha.anio = 1900;
    for(int i = 0; i < tam; i++)
    {
        vAlquiler[i].CodigoAlquiler = 0;
        vAlquiler[i].CodigoCliente = 0;
        vAlquiler[i].CodigoJuego = 0;
        vAlquiler[i].fecha = dFecha;
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

int existeJuego(eJuego vJuego[], int tam, int cod)
{
    int ret = 1;

    for(int i = 0; i < tam; i++)
    {
        if(vJuego[i].Codigo == cod)
        {
            ret = 0;
        }
    }

    return ret;
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
    int ret = 0;

    if(sexo != 'm' && sexo != 'f')
    {
        ret = 1;
        printf("\nEl sexo es incorrecto\n");
    }
    return ret;
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
    int ret = 0;

    if(strlen(tel) > 20)
    {
        ret = 1;
        printf("\nEl telefono es demasiado extenso\n");
    }
    return ret;
}

/** \brief devuelve el id de categoria segun el indice
 *
 * \param vector categoria
 * \param tamaño vector
 * \param indice a buscar
 * \return idcategori
 *
 */

int getIDCategoria(eCategoria vCategoria[], int tam, int indice)
{
    int id;

    for(int i = 0; i < tam; i++)
    {
        if(i == indice)
        {
            id = vCategoria[i].id;
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

void cargarJuegos(eJuego vJuego[], int tam, eCategoria vCategoria[], int tamc)
{
    eJuego sJuego[] =
    {
        {1, "Estanciero", 210.56, getIDCategoria(vCategoria, tamc, 0)},
        {2, "Generala", 311.77, getIDCategoria(vCategoria, tamc, 1)},
        {3, "TEG", 215.97, getIDCategoria(vCategoria, tamc, 2)},
        {4, "Mi salon", 877.12, getIDCategoria(vCategoria, tamc, 3)},
        {5, "Mi magia", 500.01, getIDCategoria(vCategoria, tamc, 4)}
    };

   for(int i = 0; i < tam; i++)
    {
        vJuego[i] = sJuego[i];
    }
}

/** \brief harcode categorias
 *
 * \param vector categorias
 * \param tamaño vector
 * \return nothing
 *
 */

void cargarCategorias(eCategoria vCategoria[], int tam)
{
    eCategoria sCategoria[] =
    {
        {101, "mesa"},
        {102, "azar"},
        {103, "estrategia"},
        {104, "salon"},
        {105, "magia"}
    };

    for(int i = 0; i < tam; i++)
    {
        vCategoria[i] = sCategoria[i];
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
