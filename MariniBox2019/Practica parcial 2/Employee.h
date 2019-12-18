#ifndef Eempleado_H_INCLUDED
#define Eempleado_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char empleo[128];
    int edad;
    int horasTrabajadas;
    float sueldo;
}Eempleado;

/** \brief crea un nuevo empleado con parametros vacios
 *
 * \return Eempleado* retorna el puntero al empleado
 *
 */
Eempleado* Eempleado_new();
/** \brief crea un nuevo empleado con parametros
 *
 * \param idStr char*
 * \param dominioStr char*
 * \param anioStr char*
 * \param tipoStr char*
 * \return Eempleado* retorna el puntero al empleado
 *
 */
Eempleado* Eempleado_newParametros(char* idStr,char* nombreStr,char* empleoStr, char* edadStr, char* horasStr);
//void Eempleado_delete();

/** \brief guarda el id en la estructura
 *
 * \param this Eempleado*
 * \param id int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int Eempleado_setId(Eempleado* this,int id);
/** \brief obtiene el id de la estructura
 *
 * \param this Eempleado*
 * \param id int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int Eempleado_getId(Eempleado* this,int* id);

/** \brief
 *
 * \param this Eempleado*
 * \param edad int
 * \return int
 *
 */
int Eempleado_setEdad(Eempleado* this,int edad);

/** \brief
 *
 * \param this Eempleado*
 * \param edad int*
 * \return int
 *
 */
int Eempleado_getEdad(Eempleado* this,int* edad);

/** \brief guarda el nombre en la estructura
 *
 * \param this Eempleado*
 * \param nombre char*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int Eempleado_setNombre(Eempleado* this,char* nombre);
/** \brief obtiene el nombre de la estructura
 *
 * \param this Eempleado*
 * \param nombre char*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int Eempleado_getNombre(Eempleado* this,char* nombre);

/** \brief guarda las horas en la estructura
 *
 * \param this Eempleado*
 * \param horasTrabajadas int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int Eempleado_setHorasTrabajadas(Eempleado* this,int horas);
/** \brief obtiene las horas de la estructura
 *
 * \param this Eempleado*
 * \param horasTrabajadas int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int Eempleado_getHorasTrabajadas(Eempleado* this,int* horas);

/** \brief guarda las horas en la estructura
 *
 * \param this Eempleado*
 * \param sueldo int
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int Eempleado_setEmpleo(Eempleado* this,char* empleo);
/** \brief obtiene el sueldo de la estructura
 *
 * \param this Eempleado*
 * \param sueldo int*
 * \return int 1 si esta ok y 0 si hubo error
 *
 */
int Eempleado_getEmpleo(Eempleado* this,char* empleo);
 /** \brief
  *
  * \param this Eempleado*
  * \param sueldo float
  * \return int
  *
  */
 int Eempleado_setsueldo(Eempleado* this,float sueldo);

 /** \brief
  *
  * \param this Eempleado*
  * \param sueldo float*
  * \return int
  *
  */
 int Eempleado_getsueldo(Eempleado* this,float* sueldo);

/** \brief compara que elemento es mayor y  menor y retorna el resultado
 *
 * \param personaA void*
 * \param personaB void*
 * \return int retorna la comparacion
 *
 */
int Eempleado_compararPorNombre(void* personaA, void* personaB);


int Eempleado_filtrarPorEmpleo(void* persona);


int Eempleado_mapearSueldo(void* persona);

#endif // Eempleado_H_INCLUDED
