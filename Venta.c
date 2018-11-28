#include "Venta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

S_Venta* Venta_new()
{
    S_Venta* this;
    this=malloc(sizeof(S_Venta));
    return this;
}

void Venta_delete(S_Venta* this)
{
    free(this);
}

S_Venta* Venta_newConParametros(int idVenta,char* fechaDeVenta,char* codigoDeProducto,int cantidad,float precioUnitario,char* cuitCliente)
{
    S_Venta* this;
    this=Venta_new();

    if(
    !Venta_setIdVenta(this,idVenta)&&
    !Venta_setFechaDeVenta(this,fechaDeVenta)&&
    !Venta_setCodigoDeProducto(this,codigoDeProducto)&&
    !Venta_setCantidad(this,cantidad)&&
    !Venta_setPrecioUnitario(this,precioUnitario)&&
    !Venta_setCuitCliente(this,cuitCliente))
        return this;

    Venta_delete(this);
    return NULL;
}

int Venta_setIdVenta(S_Venta* this,int idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->idVenta=idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_getIdVenta(S_Venta* this,int* idVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *idVenta=this->idVenta;
        retorno=0;
    }
    return retorno;
}

int Venta_setFechaDeVenta(S_Venta* this,char* fechaDeVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaDeVenta!=NULL)
    {
        strcpy(this->fechaDeVenta,fechaDeVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_getFechaDeVenta(S_Venta* this,char* fechaDeVenta)
{
    int retorno=-1;
    if(this!=NULL && fechaDeVenta!=NULL)
    {
        strcpy(fechaDeVenta,this->fechaDeVenta);
        retorno=0;
    }
    return retorno;
}

int Venta_setCodigoDeProducto(S_Venta* this,char* codigoDeProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->codigoDeProducto,codigoDeProducto);
        retorno=0;
    }
    return retorno;
}

int Venta_getCodigoDeProducto(S_Venta* this,char* codigoDeProducto)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(codigoDeProducto,this->codigoDeProducto);
        retorno=0;
    }
    return retorno;
}

int Venta_setCantidad(S_Venta* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_getCantidad(S_Venta* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

int Venta_setPrecioUnitario(S_Venta* this,float precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precioUnitario=precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_getPrecioUnitario(S_Venta* this,float* precioUnitario)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precioUnitario=this->precioUnitario;
        retorno=0;
    }
    return retorno;
}

int Venta_setCuitCliente(S_Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(this->cuitCliente,cuitCliente);
        retorno=0;
    }
    return retorno;
}

int Venta_getCuitCliente(S_Venta* this,char* cuitCliente)
{
    int retorno=-1;
    if(this!=NULL && cuitCliente!=NULL)
    {
        strcpy(cuitCliente,this->cuitCliente);
        retorno=0;
    }
    return retorno;
}

