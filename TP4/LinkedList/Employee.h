#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int nivel;
    int cantProdVend;
    float montoVendido;
    float comision;

}Vendedor;

Vendedor* vendedor_new();
Vendedor* vendedor_newParametros(char* idStr,char* nombreStr, char* nivel, char* cantProdVendStr, char* montoVendido, char* comision);
void employee_delete();

int vendedor_setId(Vendedor* this,int id);
int vendedor_getId(Vendedor* this,int* id);

int vendedor_setNombre(Vendedor* this,char* nombre);
int vendedor_getNombre(Vendedor* this,char* nombre);

int vendedor_setHorasTrabajadas(Vendedor* this,int horasTrabajadas);
int vendedor_getHorasTrabajadas(Vendedor* this,int* horasTrabajadas);

int vendedor_setSueldo(Vendedor* this,int sueldo);
int vendedor_getSueldo(Vendedor* this,int* sueldo);

void  vendedor_showEmployee(Vendedor* this);
void  vendedor_showEmployees(Vendedor* this);

int vendedor_sortByName(void* vendedor, void* empleadoB);
int vendedor_sortById(void* vendedor, void* empleadoB);
int vendedor_sortByHsTrabajadas(void* vendedor, void* empleadoB);
int vendedor_sortBySueldo(void* vendedor, void* empleadoB);
float vendedor_loadSueldo(void* vendedor);
int vendedor_niveles(void* vendedor, int* nivel);

#endif // employee_H_INCLUDED
