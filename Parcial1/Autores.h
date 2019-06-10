#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED
#include "Autores.h"
#include "UTN_INPUT.h"
#define OCUPADO 0
#define VACIO 1



typedef struct
{
    int CodigoAutor;
    char apellido [31];
    char nombre [31];

}eAutores;


/** \brief muestra todos los autores
 *
 * \param autor[] eAutores array de autores
 * \param tam int ta,año del array
 * \return void
 *
 */
void mostrar_Autores(eAutores autor[],int tam);

/** \brief busca el autor por su id y si exista carga su nombre y en la posicion deseada de  la cadena
 *
 * \param autor[] eAutores busca un autor por el id y si existe descarga su nombre en la cadena
 * \param tam int tamaño del array de autores
 * \param idAutor int codigo del autor
 * \param nombre[] char cadena a la que descargar la informacion
 * \param apellido[] char cadena a la que descargar la informacion
 * \return int retorna el id del autor
 *
 */
int obtener_Autor(eAutores autor[], int tam, int idAutor, char nombre[],char apellido[]);


/** \brief funcion encargada de hardcodear los autores en la estructura
 *
 * \param autores[] eMenu recibe el array de autores
 * \param tam int recibe el tamaño del array de autores
 * \return void La funcion no retorna nada
 *
 */
void init_Autores(eAutores autores[], int tam);



#include "Libros.h"
#endif // AUTORES_H_INCLUDED
