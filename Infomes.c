#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "Parser.h"

/** \brief Retorna la cantidad de equipos por venta
 * \param lista Puntero a la lista
 * \param i Posición del elemento a obtener
 * \return En caso de error retorna 0, caso contrario retorna la cantidad de articulos vendidos en esa venta
 */
int informes_unidadesVendidasTotales(void* lista, int i)
{
    int ret = 0;
    S_Venta* ventasAux;

    if(lista != NULL)
    {
        ventasAux = ll_get(lista,i);
        ret = ventasAux->cantidad;
    }
    return ret;
}

/** \brief Retorna la cantidad de LCD por venta
 * \param lista Puntero a la lista
 * \param i Posición del elemento a obtener
 * \return En caso de error retorna 0, caso contrario retorna la cantidad de articulos vendidos en esa venta
 */
int informes_cantidadDeLCD(void* lista, int i)
{
    int ret = 0;
    S_Venta* ventasAux;

    if(lista != NULL)
    {
        ventasAux = ll_get(lista,i);
        if(strcmp(ventasAux->codigoDeProducto,"LCD_TV") == 0)
        {
            ret = ventasAux->cantidad;
        }
    }
    return ret;
}

/** \brief Retorna el total de ventas
 * \param lista Puntero a la lista
 * \param i Posición del elemento a obtener
 * \param montoMayor El monto a partir del cual se filtrará la cantidad de ventas
 * \return En caso de error retorna 0, caso contrario retorna la cantidad de ventas superior al monto mayor ingresado
 */
int informes_vendidasMayorA(void* lista, int i, int montoMayor)
{
    int ret = 0;
    int contadorDeVentas = 0;
    int montoAux = 0;
    S_Venta* ventasAux;

    if(lista != NULL)
    {
        ventasAux = ll_get(lista,i);
        montoAux = (ventasAux->precioUnitario)*(ventasAux->cantidad);
        if(montoAux >= montoMayor)
        {
            contadorDeVentas++;
            ret = contadorDeVentas;
        }
    }
    return ret;
}

/** \brief Crea el informe de las ventas
 * \param cantidadTotales Cantidad de productos totales vendidos
 * \param mayor10K Cantidad de ventas mayor a $10000
 * \param mayor20K Cantidad de ventas mayor a $20000
 * \param totalLCD Cantidad de LCD vendidos
 * \return En caso de error retorna 0, caso contrario retorna la cantidad de ventas superior al monto mayor ingresado
 */
int informes_crearInforme(int cantidadTotales, int mayor10K, int mayor20K, int totalLCD)
{
    int ret = -1;
    FILE* archivo = fopen("informes.txt", "w");

    if(archivo != NULL)
    {
        fprintf(archivo, "*************************\nInforme de ventas\n*************************\n");
        fprintf(archivo, "-Cantidad de unidades vendidas totales: %d\n", cantidadTotales);
        fprintf(archivo, "-Cantidad de ventas por un monto mayor a $10.000: %d\n", mayor10K);
        fprintf(archivo, "-Cantidad de ventas por un monto mayor a $20.000: %d\n", mayor20K);
        fprintf(archivo, "-Cantidad de LCD vendidos: %d",totalLCD);
        fprintf(archivo, "\n*************************\n");
        fclose(archivo);
        ret = 0;
    }
    return 0;
}
