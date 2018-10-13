#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct{
int Codigo;
char Descripcion[21];
float Importe;
int idCategoria;
} eJuego;

typedef struct{
int id;
char Descripcion[51];
} eCategoria;

typedef struct{
int Codigo;
char Nombre[51];
char sexo;
char Telefono[21];
} eCliente;

typedef struct{
int CodigoAlquiler;
int CodigoJuego;
int CodigoCliente;
eFecha fecha;
} eAlquileres;

int menu();
int submenu();
int altaCliente(eCliente vCliente[], int tam);
int bajaCliente(eCliente vCliente[], int tam);
int existeCliente(eCliente vCliente[], int tam, int codigo);
int hayAlquileres(eAlquileres vAlquiler[], int tam);
int hayClientes(eCliente vCliente[], int tam);
int modificarCliente(eCliente vCliente[], int tam);
int altaAlquiler(eAlquileres alquiler[], int tam, eJuego juegos[], int tamj, eCliente clientes[], int tamc,eCategoria[]);
int existeJuego(eJuego vJuego[], int tam, int cod);
int validarSexo(char sexo);
int validarTelefono(char tel[]);
int getIDCategoria(eCategoria vCategoria[], int tam, int indice);
void listarClientes(eCliente vClientes[], int tam);
void inicializarClientes(eCliente vCliente[], int tam);
void ordenarClientes(eCliente vCliente[], int tam);
void listarAlquileres(eAlquileres vAlquiler[], int tama, eCliente vCliente[], int tamcl, eJuego vJuego[], int tamj, eCategoria vCategoria[], int tamca);
void listarCategorias(eCategoria categorias[],int tam);
void mostrarJuegosDeMesa(eJuego juegos[],int tam,eCategoria categorias[],int tama);
void listarJuegos(eJuego juegos[],int tam,eCategoria categorias[]);

void getJuego(eJuego vJuego[], int tamj, int codj, char desc[]);
void getCategoria(eCategoria vCategoria[], int tamc, eJuego vJuego[], int tamj, int codj, char desc[]);
void getCliente(eCliente vCliente[], int tamc, int codcliente, char nombre[]);
void inicializarAlquileres(eAlquileres vAlquiler[], int tam);
void cargarJuegos(eJuego vJuego[], int tam, eCategoria vCategoria[], int tamc);
void cargarCategorias(eCategoria vCategoria[], int tam);


void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int esSoloLetras(char str[]);




#endif  //FUNCIONES_H_INCLUDED
