#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int idVenta;
    char fechaDeVenta[11];
    char codigoDeProducto[10];
    int cantidad;
    float precioUnitario;
    char cuitCliente[10];
}S_Venta;

S_Venta* Venta_new();
void Venta_delete();
S_Venta* Venta_newConParametros(int idVenta,char* fechaDeVenta,char* codigoDeProducto,int cantidad,float precioUnitario,char* cuitCliente);

int Venta_setIdVenta(S_Venta* this,int idVenta);
int Venta_getIdVenta(S_Venta* this,int* idVenta);

int Venta_setFechaDeVenta(S_Venta* this,char* fechaDeVenta);
int Venta_getFechaDeVenta(S_Venta* this,char* fechaDeVenta);

int Venta_setCodigoDeProducto(S_Venta* this,char* codigoDeProducto);
int Venta_getCodigoDeProducto(S_Venta* this,char* codigoDeProducto);

int Venta_setCantidad(S_Venta* this,int cantidad);
int Venta_getCantidad(S_Venta* this,int* cantidad);

int Venta_setPrecioUnitario(S_Venta* this,float precioUnitario);
int Venta_getPrecioUnitario(S_Venta* this,float* precioUnitario);

int Venta_setCuitCliente(S_Venta* this,char* cuitCliente);
int Venta_getCuitCliente(S_Venta* this,char* cuitCliente);

#endif // VENTA_H_INCLUDED
