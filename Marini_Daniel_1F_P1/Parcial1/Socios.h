#ifndef SOCIOS_H_INCLUDED
#define SOCIOS_H_INCLUDED
#define OCUPADO 0
#define VACIO 1
#include "UTN_INPUT.h"
typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int codigoSocio;
    char apellido[31];
    char nombre[31];
    char sexo;
    char telefono[31];
    char eMail[31];
    eFecha fechaDeAsociado;
    int isEmpty;


}eSocio;

typedef struct
{
    int CodigoLibro;
    char titulo [51];
    int codigoAutor;

}eLibro;

typedef struct
{
    int CodigoAutor;
    char apellido [31];
    char nombre [31];

}eAutores;


typedef struct
{
    int CodigoSocio;
    int CodigoLibro;
    int CodigoPrestamo;
    eFecha fechaPrestamo;
    int isEmpty;

}ePrestamo;


/** \brief Funcion encargada de genera un numero de ID y autoincrementarlo
 *
 * \param La funcion no recibe parametros
 * \param La funcion no recibe parametros
 * \return Retorna el ID generado autoincrementado
 *
 */
int generarNextId_Prestamo();

int inicializar_Prestamo(ePrestamo lista[], int tam);

int buscarLibre_Prestamo(ePrestamo lista[], int tam);

//int alta_Prestamos(ePrestamo listaPrestamos[],eSocio listaSocio[],eLibro listaLibro[],int tamSocio,int tamLibro,int tamPrestamo);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief funcion encargada de hardcodear los menues en la estructura
 *
 * \param menues[] eMenu recibe el array de menues
 * \param tam int recibe el tamaño del array de menues
 * \return void La funcion no retorna nada
 *
 */
void init_Autores(eAutores autores[], int tam);

/** \brief funcion encargada de hardcodear los menues en la estructura
 *
 * \param menues[] eMenu recibe el array de menues
 * \param tam int recibe el tamaño del array de menues
 * \return void La funcion no retorna nada
 *
 */
 //////////////////////////////////////////////////////
void init_Libros(eLibro libros[], int tam);

/** \brief Funcion encargada de inicializar todos los elementos del array de empleados en un estado libre para cargar datos
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int retorna -1 si hubo algun error y 0 si no hubo ningun error
 *
 */
 ////////////////////////////////////////////////////////////////////////////////////////
int inicializar_Socios(eSocio lista[], int tam);


/** \brief Funcion encargada de buscar algun espacio libre en el array de Socios para cargar un nuevo dato
 *
 * \param Employee* Recibe un puntero al array de Socios
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna la primera posicion libre que encuentra la funcion
 *
 */
int buscarLibre(eSocio lista[], int tam);

/** \brief Funcion encargada de validar si existe un empleado cargado en el array
 *
 * \param list Employee* Recibe un puntero al array de Socios
 * \param len int la cantidad de elementos en el array
 * \return int Retorna -1 si no hay Socios y 0 si encontro
 *
 */
int hay_Socios_Cargados(eSocio lista[], int tam);

/** \brief Funcion encargada de genera un numero de ID y autoincrementarlo
 *
 * \param La funcion no recibe parametros
 * \param La funcion no recibe parametros
 * \return Retorna el ID generado autoincrementado
 *
 */
int generarNextId();


 /** \brief Funcion encargada de añadir a los Socios en la estructura
 *
 * \param lista[] eSocio Recibe el array de Socios
 * \param tam int recibe la cantidad de elementos en el array  de Socios
 * \param sectores[] eSector Recibe el array de sectores
 * \param tamSector int recibe la cantidad de elementos en el array de sectores
 * \return int  Retorna -1 si hubo un error y 0 si el empleado fue cargado correctamente
 *
 */
int alta_Socios(eSocio lista[], int tam);

/** \brief funcion encargada de cargar la fecha en la estructura
 *
 * \param lista[] eEmpleado recibe el array de Socios
 * \param indice int recibe la posicion del empleado a cargar su fecha
 * \return void
 *
 */
void cargarFecha_Socios(eSocio lista[],int indice);

/** \brief Funcion encargada de mostrar a un empleado
 *
 * \param sectores[] eSector recibe el array de sectores
 * \param tamSector int recibe el tamaño de sectoress
 * \param lista eEmpleado recibe el array de Socios
 * \return void La funcion no retorna nada
 *
 */
void mostrar_Socio(eSocio socio);

/** \brief Funcion encargada de mostrar el listado de todos los Socios
 *
 * \param lista[] eEmpleado recibe el array de Socios
 * \param tam int recibe el tamaño del array de Socios
 * \param sectores[] eSector recibe el array de sectores
 * \param tamSector int recibe el tamaño de sectoress
 * \return int
 *
 */
 int mostrar_Socios(eSocio lista[], int tam);

 /** \brief Funcion que busca al empleado por su numero de ID
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \param int recibe el ID generado
 * \return int retorna la posicion del array donde se encuentra el ID generado
 *
 */
 int buscar_Socios_PorId(eSocio lista[], int tam, int codigoSocio);

 /** \brief Funcion encargada de modificar los campos de un empleado
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int Recibe la cantidad de elementos en el array
 * \return int la posicion del array donde se encuentra el ID seleccionado
 *
 */
void modf_Socios(eSocio lista[], int indice);

/** \brief Funcion encargada de buscar al empleado y modificarlo
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error y 0 si se pudo modificar correctamente al empleado
 *
 */
int modificar_Socios(eSocio lista[],int tam);

/** \brief Funcion encargada de dar de baja a un empleado
 *
 * \param Employee* Recibe un puntero al array de empleados
 * \param int Recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error o 0 si se dio de baja exitosamente
 *
 */
int baja_Socios(eSocio lista[], int tam);

int ordenar_Socios(eSocio lista[],int tam );
//libros
int mostrar_Libros(eLibro lista[], int tam);
void mostrar_libro(eLibro libros);
//autores
int mostrar_Autores(eAutores lista[], int tam);
void mostrar_Autor(eAutores autores);
//prestamos
void cargarFecha_Prestamo(ePrestamo lista[],int indice);
void mostrar_Prestamo(ePrestamo prestamos);
int mostrar_Prestamos(ePrestamo lista[], int tam);




#endif // SOCIOS_H_INCLUDED
