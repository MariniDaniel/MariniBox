
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEempleado LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEempleado);
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEempleado LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */

int controller_sortEempleado(LinkedList* pArrayListEempleado);
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEempleado LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_ListEempleado(LinkedList* pArrayListEempleado);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEempleado LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEempleado);
/** \brief busca si existen elementos cargados en la lista
 *
 * \param pArrayListEempleado LinkedList*
 * \return int retorna 1 si todo ok -1 si hubo error
 *
 */
int controller_listExist(LinkedList* pArrayListEempleado);

/** \brief
 *
 * \param pArrayListEempleado LinkedList*
 * \return int
 *
 */
int controller_filter(LinkedList* pArrayListEempleado);

/** \brief
 *
 * \param pArrayListeDominio LinkedList*
 * \return int
 *
 */
int controller_mapEmployee(LinkedList* pArrayListeDominio);
