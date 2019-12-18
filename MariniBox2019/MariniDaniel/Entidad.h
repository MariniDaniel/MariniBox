typedef struct{

   int idVenta;
   char fechaVenta[20];
   char tipoFoto[20];
   int cantidad;
   float precioUnitario;
   char cuitCliente[20];

}Venta;

Venta* venta_new();
Venta* venta_newParametros(char* idVentaStr, char* fechaVentaStr, char* tipoFotoStr, char* cantidadStr, char* PrecioUnitarioStr,
                           char* cuitCliente);
int venta_delete(Venta* this);
int venta_setIdVenta(Venta* this, int idVenta);
int venta_setFechaVenta(Venta* this, char* fechaVenta);
int venta_setTipoFoto(Venta* this, char* tipoFoto);
int venta_setCantidad(Venta* this, int cantidad);
int venta_setPrecioUnitario(Venta* this, float precioUnitario);
int venta_setCuitCliente(Venta* this, char* cuitCliente);
int venta_getIdVenta(Venta* this, int* idVenta);
int venta_getFechaVenta(Venta* this, char* fechaVenta);
int venta_getTipoFoto(Venta* this, char* tipoFoto);
int venta_getCantidad(Venta* this, int* cantidad);
int venta_getPrecioUnitario(Venta* this, float* precioUnitario);
int venta_getCuitCliente(Venta* this, char* cuitCliente);


int venta_fotoCantidad(void* venta);
int venta_ventasMayor150(void* venta);
int venta_ventasMayor300(void* venta);
int venta_cantidadFotosPolarodids(void* venta);
void  venta_showVenta(Venta* this);
void  venta_showVentas(Venta* this);


