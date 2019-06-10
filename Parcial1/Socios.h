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



/** \brief hardcodeo socios
 *
 * \param socios[] eSocio
 * \param tam int
 * \return void
 *
 */
void init_Socios(eSocio socios[], int tam);
/** \brief Funcion encargada de inicializar todos los elementos del array de socios en un estado libre para cargar datos
 *
 * \param Employee* Recibe un puntero al array de socios
 * \param int recibe la cantidad de elementos en el array
 * \return int retorna -1 si hubo algun error y 0 si no hubo ningun error
 *
 */
int inicializar_Socios(eSocio lista[], int tam);


/** \brief Funcion encargada de buscar algun espacio libre en el array de Socios para cargar un nuevo dato
 *
 * \param Employee* Recibe un puntero al array de Socios
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna la primera posicion libre que encuentra la funcion
 *
 */
int buscarLibre(eSocio lista[], int tam);

/** \brief Funcion encargada de validar si existe un socio cargado en el array
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
 * \return int  Retorna -1 si hubo un error y 0 si el socio fue cargado correctamente
 *
 */
int alta_Socios(eSocio lista[], int tam);


/** \brief funcion encargada de cargar la fecha en la estructura
 *
 * \param lista[] esocio recibe el array de Socios
 * \param indice int recibe la posicion del socio a cargar su fecha
 * \return void
 *
 */
void cargarFecha_Socios(eSocio lista[],int indice);

/** \brief Funcion encargada de mostrar a un socio
 *
 * \param sectores[] eSector recibe el array de sectores
 * \param tamSector int recibe el tamaño de sectoress
 * \param lista esocio recibe el array de Socios
 * \return void La funcion no retorna nada
 *
 */
void mostrar_Socio(eSocio socio);

/** \brief Funcion encargada de mostrar el listado de todos los Socios
 *
 * \param lista[] esocio recibe el array de Socios
 * \param tam int recibe el tamaño del array de Socios
 * \param sectores[] eSector recibe el array de sectores
 * \param tamSector int recibe el tamaño de sectoress
 * \return int
 *
 */
 int mostrar_Socios(eSocio lista[], int tam);

 /** \brief Funcion que busca al socio por su numero de ID
 *
 * \param Employee* Recibe un puntero al array de socios
 * \param int recibe la cantidad de elementos en el array
 * \param int recibe el ID generado
 * \return int retorna la posicion del array donde se encuentra el ID generado
 *
 */
 int buscar_Socios_PorId(eSocio lista[], int tam, int codigoSocio);

 /** \brief Funcion encargada de modificar los campos de un socio
 *
 * \param Employee* Recibe un puntero al array de socios
 * \param int Recibe la cantidad de elementos en el array
 * \return int la posicion del array donde se encuentra el ID seleccionado
 *
 */
void modf_Socios(eSocio lista[], int indice);

/** \brief Funcion encargada de buscar al socio y modificarlo
 *
 * \param Employee* Recibe un puntero al array de socios
 * \param int recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error y 0 si se pudo modificar correctamente al socio
 *
 */
int modificar_Socios(eSocio lista[],int tam);

/** \brief Funcion encargada de dar de baja a un socio
 *
 * \param Employee* Recibe un puntero al array de socios
 * \param int Recibe la cantidad de elementos en el array
 * \return int Retorna -1 si hubo un error o 0 si se dio de baja exitosamente
 *
 */
int baja_Socios(eSocio lista[], int tam);

/** \brief funcion encarfada de ordenar a los socios de por apellido y sector y mostralos
 *
 * \param lista[] eSocio array de socios
 * \param tam int tamaño del array de socios
 * \return int Retorna -1 si hubo un error o 0 si no
 *
 */
int ordenar_Socios(eSocio lista[],int tam );

/** \brief
 *
 * \param listaSocios[] eSocio
 * \param tamSocios int
 * \param idSocios int
 * \param apellido[] char
 * \param nombre char
 * \return void
 *
 */
void cargarDescripcion_Socio(eSocio listaSocios[], int tamSocios, int idSocios, char apellido[],char nombre[]);

#endif // SOCIOS_H_INCLUDED
