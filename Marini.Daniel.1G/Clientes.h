#ifndef INPUT_H_INCLUDED


typedef struct
{
    int codigoCliente;
    char nombre[51];
    char sexo;
    int telefono;
    int isEmpty;

} eCliente;

void inicializarCliente(eCliente* lista,int len);
int primerEspacioCliente(eCliente* lista, int len);
void addCliente(eCliente* lista, int len,int *altaBanderaCliente);
int findCliente(eCliente* lista, int len,int codigo);
int menuClientes();
void bajaCliente(eCliente* lista,int len);
void modificarCliente(eCliente* lista,int len);
void imprimirListaClientes(eCliente* lista,int len);

void ordenarClientes(eCliente* lista, int len);

#endif // INPUT_H_INCLUDED
