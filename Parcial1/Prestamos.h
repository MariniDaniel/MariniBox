#ifndef PRESTAMOS_H_INCLUDED
#define PRESTAMOS_H_INCLUDED
#include "UTN_INPUT.h"
#include "Autores.h"
#include "Libros.h"
#include "Socios.h"

typedef struct
{
    int CodigoSocio;
    int CodigoLibro;
    int CodigoPrestamo;
    eFecha fechaPrestamo;
    int isEmpty;

}ePrestamo;




/** \brief busca si existe un prestamo cargado en el sistema
 *
 * \param listaPrestamos[] ePrestamo array de prestamos
 * \param tamPrestamos int tamaño del array de prestamos
 * \return int Retorna -1 si no hay Socios y 0 si encontro
 *
 */
int hay_Prestamos_Cargados(ePrestamo listaPrestamos[], int tamPrestamos);
/** \brief Funcion encargada de genera un numero de ID y autoincrementarlo
 *
 * \param La funcion no recibe parametros
 * \param La funcion no recibe parametros
 * \return Retorna el ID generado autoincrementado
 *
 */
int generarNextId_Prestamo();

/** \brief inicializa los elemntos del array de prestamos en vacio
 *
 * \param lista[] ePrestamo array de prestamos
 * \param tam int tamaño del array de prestamos
 * \return int retorna -1 si hubo algun error y 0 si no hubo ningun error
 *
 */
int inicializar_Prestamo(ePrestamo lista[], int tam);

/** \brief busca un espacio libre en el array de prestamos
 *
 * \param lista[] ePrestamo array de prestamos
 * \param tam int la cantidad de elementos en el array
 * \return int Retorna -1 si no hay Socios y 0 si encontro
 *
 */
int buscarLibre_Prestamo(ePrestamo lista[], int tam);

/** \brief imprime el menu de prestamos
 *
 * \param listaPrestamos[] ePrestamo array de prestamos
 * \param tam int tamaño del array de prestamos
 * \param listaSocios[] eSocio array de socios
 * \param tamSocios int tamaño del array de socios
 * \param listaLibros[] eLibro array de libros
 * \param TamLibros int tamaño del array de libros
 * \param listaAutores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return void
 *
 */
void menu_Prestamos(ePrestamo listaPrestamos[] ,int tam,eSocio listaSocios[],int tamSocios,eLibro listaLibros[],int TamLibros,eAutores listaAutores[],int tamAutor);

/** \brief da de alta una instancia de prestamo
 *
 * \param listaPrestamos[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño del array de prestamos
 * \param listaSocio[] eSocio  array de socios
 * \param tamSocio int tamaño del array de socios
 * \param listaLibro[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \return int Retorna -1 si hubo un error y 0 si el socio fue cargado correctamente
 *
 */
int alta_Prestamos(ePrestamo listaPrestamos[],int tamPrestamo,eSocio listaSocio[],int tamSocio,eLibro listaLibro[],int tamLibro);

/** \brief muestra un solo prestamo
 *
 * \param istaPrestamos[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño del array de prestamos
 * \param listaSocio[] eSocio  array de socios
 * \param tamSocio int tamaño del array de socios
 * \param listaLibro[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param indice int el indice donde se encuentra el prestamo obtenido
 * \return void
 *
 */
void mostrar_Prestamo(ePrestamo listaPrestamos[],int tamPrestamo,eSocio listaSocio[],int tamSocio,eLibro listaLibro[],int tamLibro,int indice);

/** \brief muestra todos los prestamos
 *
 * \param listaPrestamos[] ePrestamo array de prestamos
 * \param tamPrestamo int tamaño del array de prestamos
 * \param listaSocio[] eSocio array de socios
 * \param tamSocio int tamaño del array de socios
 * \param listaLibro[] eLibro array de libros
 * \param tamLibro int tamaño del array de libros
 * \param listaAutores[] eAutores array de autores
 * \param tamAutor int tamaño del array de autores
 * \return void
 *
 */
void mostrar_Prestamos(ePrestamo listaPrestamos[],int tamPrestamo,eSocio listaSocio[],int tamSocio,eLibro listaLibro[],int tamLibro,eAutores listaAutores[],int tamAutor);

/** \brief harcodea los prestamos
 *
 * \param Prestamo[] ePrestamo array de prestamos
 * \param tam int tamaño del array de prestamos
 * \return void
 *
 */
void init_Prestamo(ePrestamo Prestamo[], int tam);

/** \brief carga la fecha del prestamo en la estructura
 *
 * \param lista[] ePrestamo array de prestamos
 * \param indice int indice del array donde se va a cargar la fecha
 * \return void
 *
 */
void cargarFecha_Prestamos(ePrestamo lista[],int indice);

/** \brief contador que va sumando en cada instancia de prestamo
 *
 * \param caso int el caso 1 o 0 dependiendo si va a mostrar o contar
 * \return int retorna la cantidad de altas de prestamos
 *
 */
int sumarPrestamo(int caso);



#endif // PRESTAMOS_H_INCLUDED
