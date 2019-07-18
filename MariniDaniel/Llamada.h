
typedef struct{

    int problemaId;
    char descripcion[100];

}sProblema;

typedef struct{

    int idLlamada;
    char fecha[20];
    int numeroCliente;
    int idProblema;
    char solucionado[10];

}sLlamada;

/** Llamada **/
sLlamada* llamada_new();
sLlamada* llamada_newParametros(char* idLlamadaaStr, char* fechaStr, char* numeroClienteStr, char* idProblemaStr, char* solucionado);
int llamada_delete(sLlamada* this);

int llamada_setIdLlamada(sLlamada* this, int idLlamada);
int llamada_getIdLlamada(sLlamada* this, int* idLlamada);

int llamada_setFecha(sLlamada* this, char* fecha);
int llamada_getFecha(sLlamada* this, char* fecha);

int llamada_setNumeroCliente(sLlamada* this, int numeroCliente);
int llamada_getNumeroCliente(sLlamada* this, int* numeroCliente);

int llamada_setIdProblema(sLlamada* this, int idProblema);
int llamada_getIdProblema(sLlamada* this, int* idProblema);

int llamada_setSolucionado(sLlamada* this, char* solucionado);
int llamada_getSolucionado(sLlamada* this, char* solucionado);

void  llamada_showLlamada(sLlamada* this);

/** Problema **/
sProblema* problema_new();
sProblema* problema_newParametros(char* problemaIdStr, char* descripcion);
int problema_delete(sProblema* this);

int problema_setProblemaId(sProblema* this, int problemaId);
int problemada_getProblemaId(sProblema* this, int* problemaId);

int problema_setDescripcion(sProblema* this, char* descripcion);
int problema_getDescripcion(sProblema* this, char* descripcion);

void  llamada_showLlamadaProblema(sLlamada* pLlamada, sProblema* pProblema);
void problema_showProblema(sProblema* this);

int llamada_filterProblemaUno(void* llamada);
int llamada_filterProblemaDos(void* llamada);
int llamada_filterProblemaTres(void* llamada);
int llamada_filterProblemaCuatro(void* llamada);
int llamada_filterProblemaCinco(void* llamada);
