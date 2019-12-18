
/** \brief Carga los datos de los dominios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeDominio LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_loadFromText(char* path,LinkedList* pArrayListeDominio);
/** \brief Carga los datos de los dominios desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeDominio LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListeDominio);
/** \brief busca retorna el id mas grande la lista
 *
 * \param pArrayListeDominio LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_GetBiggestId(LinkedList* pArrayListeDominio);
/** \brief Alta de dominios
 *
 * \param path char*
 * \param pArrayListeDominio LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_ListDominio(LinkedList* pArrayListeDominio);

/** \brief Guarda los datos de los dominios en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeDominio LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListeDominio);
/** \brief Guarda los datos de los dominios en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeDominio LinkedList*
 * \return int 1 si todo ok -1 si hubo error
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListeDominio);

/** \brief busca si existen elementos cargados en la lista
 *
 * \param pArrayListeDominio LinkedList*
 * \return int retorna 1 si todo ok -1 si hubo error
 *
 */
int controller_listExist(LinkedList* pArrayListeDominio);

/** \brief controla el mapeo de los  elementos a la lista por criterio
 *
 * \param pArrayListeDominio LinkedList*
 * \return int retorna 1 si todo ok -1 si hubo error
 *
 */
int controller_mapEmployee(LinkedList* pArrayListeDominio);
