int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_list(LinkedList* pArrayList);
//int controller_saveAsText(char* path , LinkedList* pArrayList);
int controller_ListEnvio(LinkedList* pArrayListEnvio);
int controller_loadFromTextProblema(char* path , LinkedList* pArrayList);
int controller_listProblema(LinkedList* pArrayList, LinkedList* pArrayListProblema);
int controller_listDescripcion(LinkedList* pArrayList);
int controller_cargarProblemas(LinkedList* pArrayList);

int controller_obenterDescripcion(LinkedList* pArrayList, int id, char* descr);
int controller_saveAsText(char* path , LinkedList* pArrayList, LinkedList* pArrayListProblema);

