#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"
#include "Prestamos.h"
#include "UTN_INPUT.h"

void promedio_Fecha(ePrestamo listaPrestamos[],int tamPrestamo);

/** \brief ordena los socios por el metodo de insercion ascendentemente
 *
 * \param listaSocios[] eSocio array de socios
 * \param tamSocios int tamaño del array de socios
 * \return int Retorna -1 si hubo un error y 0 si el socio fue cargado correctamente
 *
 */
int listar_Socios_Por_Insercion_Ascendente(eSocio listaSocios[], int tamSocios);
/** \brief ordena los libros por el metodo del burbujeo eficiente descendentemente
 *
 * \param listaLibros[] eLibro array de libros
 * \param tamLibros int tamaño del array de libros
 * \param listaAutores[] eAutores array de autores
 * \param tamAutores int tamaño del array de autores
 * \return int Retorna -1 si hubo un error y 0 si el socio fue cargado correctamente
 *
 */
int listar_Libro_Por_Burbujeo_Descendente(eLibro listaLibros[], int tamLibros,eAutores listaAutores[],int tamAutores);
/** \brief lista los socios que solicitaron un prestamo en una fecha predeterminada
 *
 * \param listaPrestamos[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño de l array de prestamos
 * \param listaSocio[] eSocio array de socios
 * \param tamSocios int tamaño del array de socios
 * \return void
 *
 */
void  Socios_Por_Fecha(ePrestamo listaPrestamos[], int tamPrestamo, eSocio  listaSocio[], int tamSocios);
/** \brief lista los libros que fueron solicitados para un prestamo en una fecha determinada
 *
 * \param listaPrestamos[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño del array de prestamos
 * \param listaLibros[] eLibro array de libros
 * \param tamLibros int tamaño del array de libros
 * \param listaAutores[] eAutores array de autores
 * \param tamAutores int tamaño del array de autores
 * \return void
 *
 */
void libros_Por_Fecha(ePrestamo listaPrestamos[], int tamPrestamo, eLibro  listaLibros[], int tamLibros, eAutores listaAutores[],int tamAutores);
/** \brief  lista el/los socios con mas prestamos solicitados
 *
 * \param listaPrestamos[] ePrestamo  de de prestamos
 * \param tamPrestamos int tamaño del array de prestamos
 * \param listaSocios[] eSocio array de socios
 * \param tamSocios int tamaño del array de socios
 * \return void
 *
 */
void socio_Con_Mas_Prestamos(ePrestamo listaPrestamos[], int tamPrestamos, eSocio listaSocios[],int tamSocios);
/** \brief lista el libro que menos fue solicitado para un prestamo
 *
 * \param listaPrestamos[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño del array de prestamos
 * \param listaLibro[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param listaAutor[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return void
 *
 */
void libro_Menos_Prestado(ePrestamo listaPrestamos[], int tamPrestamo, eLibro listaLibro[], int tamLibro,eAutores listaAutor[],int tamAutor);
/** \brief lista los libros de un socio
 *
 * \param listaPrestamo[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño del array de prestamos
 * \param listaLibro[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param listaSocios[] eSocio array de socios
 * \param tamSocio int tamaño del array de socios
 * \param listaAutores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return void
 *
 */
void listar_Libro_Socio(ePrestamo listaPrestamo[], int tamPrestamo, eLibro listaLibro[], int tamLibro, eSocio listaSocios[], int tamSocio,eAutores listaAutores[],int tamAutor);
/** \brief busca en socio por el id y lo retorna
 *
 * \param Socios[] eSocio array de socios
 * \param tamSocio int tamaño de socios
 * \return int retorna el id del socios
 *
 */
int elegir_Socio(eSocio Socios[], int tamSocio);
/** \brief busca un libro por id y lo retorna
 *
 * \param listaLibro[] eLibro array dd libros
 * \param tamLibro int tamaño de array de libros
 * \param listaAutores[] eAutores array de autores
 * \param tamAutor int tamaño de array de autores
 * \return int retorna el id de libros
 *
 */
int elegir_libro(eLibro listaLibro[], int tamLibro,eAutores listaAutores[],int tamAutor);
/** \brief lista los socios de un libro prestado
 *
* \param listaPrestamo[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño del array de prestamos
 * \param listaLibro[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param listaSocios[] eSocio array de socios
 * \param tamSocio int tamaño del array de socios
 * \param listaAutores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return void
 *
 */
void listar_Socio_Libro(ePrestamo listaPrestamo[], int tamPrestamo, eLibro listaLibro[], int tamLibro, eSocio listaSocios[], int tamSocio,eAutores listaAutores[],int tamAutor);
/** \brief  imprime el menu de los informes
 *
 * \param listaPrestamo[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño del array de prestamos
 * \param listaLibro[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param listaSocios[] eSocio array de socios
 * \param tamSocio int tamaño del array de socios
 * \param listaAutores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return void
 *
 */
void menu_Informe(ePrestamo listaPrestamos[],int tamPrestamos,eSocio listaSocios[],int tamSocios,eLibro listaLibros[],int TamLibros,eAutores listaAutores[],int tamAutor);

//void totalGeneral_Promedio_Prestamos(ePrestamo listaPrestamos[],int tamPrestamos);




void promedio_Fecha(ePrestamo listaPrestamos[],int tamPrestamo);
int cantidadPrestamos(ePrestamo prestamos[], int tamP);
int ordenarPrestamos(ePrestamo prestamos[], int tamP);
int mostrarPrestamos(ePrestamo prestamos[], int tamP);
float promedioPrestamos(ePrestamo prestamos[], int tamP);







#endif // INFORMES_H_INCLUDED
