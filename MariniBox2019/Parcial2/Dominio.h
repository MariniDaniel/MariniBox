#ifndef eDominio_H_INCLUDED
#define eDominio_H_INCLUDED
typedef struct
{
    int id;
    char dominio[128];
    int anio;
    char tipo;
} eDominio;

/** \brief crea un nuevo dominio con parametros vacios
 *
 * \return eDominio* retorna el puntero al dominio
 *
 */
eDominio* eDominio_new();
/** \brief crea un nuevo dominio con parametros
 *
 * \param idStr char*
 * \param dominioStr char*
 * \param anioStr char*
 * \return eDominio* retorna el puntero al dominio
 *
 */
eDominio* eDominio_newParametros(char* idStr,char* dominioStr,char* anioStr);
/** \brief guarda el id en la estructura
 *
 * \param this eDominio*
 * \param id int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int eDominio_setId(eDominio* this,int id);
/** \brief obtiene el id de la estructura
 *
 * \param this eDominio*
 * \param id int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int eDominio_getId(eDominio* this,int* id);

/** \brief guarda el dominio en la estructura
 *
 * \param this eDominio*
 * \param nombre char*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int eDominio_setDominio(eDominio* this,char* dominio);
/** \brief obtiene el dominio de la estructura
 *
 * \param this eDominio*
 * \param nombre char*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int eDominio_getDominio(eDominio* this,char* dominio);

/** \brief guarda el tipo en la estructura
 *
 * \param this eDominio*
 * \param horasTrabajadas int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int eDominio_setTipo(eDominio* this,char tipo);
/** \brief obtiene el tipo de la estructura
 *
 * \param this eDominio*
 * \param horasTrabajadas int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int eDominio_getTipo(eDominio* this,char* tipo);

/** \brief guarda el anio en la estructura
 *
 * \param this eDominio*
 * \param sueldo int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int eDominio_setAnio(eDominio* this,int anio);
/** \brief obtiene el anio de la estructura
 *
 * \param this eDominio*
 * \param sueldo int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int eDominio_getAnio(eDominio* this,int* anio);
/** \brief mapea los elementos recibidos como parametros
 *
 * \param persona void*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int eDominio_mapearTipo(void* pElement);

/** \brief funcion criterio para con la condicion para filtrar
 *
 * \param persona void*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int eDominio_filtrarMoto(void* pElement);

/** \brief funcion criterio para con la condicion para filtrar
 *
 * \param persona void*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int eDominio_filtrarAuto(void* pElement);

#endif // eDominio_H_INCLUDED
