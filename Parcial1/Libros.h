#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
#include "Autores.h"
#define OCUPADO 0
#define VACIO 1
#include "UTN_INPUT.h"

typedef struct
{
    int CodigoLibro;
    char titulo [51];
    int codigoAutor;

}eLibro;


/** \brief busca un libro por su codigo y retorna ese codigo
 *
 * \param listaLibro[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param listaAutores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return int retorna el id del libro
 *
 */
int elegir_libro(eLibro listaLibro[], int tamLibro,eAutores listaAutores[],int tamAutor);


/** \brief busca un libro por el id y si existe descarga su nombre en la cadena
 *
 * \param listaLibros[] eLibro array de libros
 * \param tamLibros int tamaño del array de libros
 * \param idLibro int codigo del libro a buscar
 * \param titulo[] char cadena a la que descargar la informacion
 * \return void
 *
 */
void cargarDescripcion_Libro(eLibro listaLibros[], int tamLibros, int idLibro, char titulo[]);


/** \brief muestra un solo libro con su autor
 *
 * \param autores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \param libros eLibro un dato tipo eLibro
 * \return void
 *
 */
void mostrar_LibroCon_Autor(eAutores autores[], int tamAutor, eLibro libros);



/** \brief muestra la cantidad de libros de cada autor
 *
 * \param libros[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param autores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return void
 *
 */
void mostrarCantLibrosXAutor(eLibro libros[], int tamLibros, eAutores autores[], int tamAutores);


/** \brief muestra todos los libros con su respectivo autor
 *
 * \param libros[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param autores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return int Retorna -1 si hubo un error y 0 si el socio fue cargado correctamente
 *
 */
int mostrar_Libros_Con_Autor(eLibro libros[], int tamLibro, eAutores autores[], int tamAutor);

/** \brief funcion encargada de hardcodear los libros en la estructura
 *
 * \param libros[] eMenu recibe el array de
 * \param tam int recibe el tamaño del array de
 * \return void La funcion no retorna nada
 *
 */
void init_Libros(eLibro libros[], int tam);

#endif // LIBROS_H_INCLUDED
