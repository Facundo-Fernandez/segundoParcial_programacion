#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Venta.h"
#include "Informes.h"

/** \brief Carga los datos de las ventas desde un archivo a una lista
 * \param this LinkedList* Puntero a la lista
 * \param path Nombre de archivo, o ruta al mismo.
 * \return Si pudo llevar a cabo la operación denota 0, caso contrario denota -1.
 */
int parser_parseVentas(char* path, LinkedList* lista)
{
    FILE* pArchivo;
    int ret = -1;
    char idVenta[4];
    char fechaDeVenta[10];
    char codigoDeProducto[3];
    char cantidad[12];
    char precioUnitario[12];
    char cuitCliente[11];
    int flagOnce = 0;
    S_Venta* ventas;

    if(path != NULL && lista != NULL)
    {
        pArchivo = fopen(path, "r");
        do
        {
            if(flagOnce == 0)
            {
                fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVenta, fechaDeVenta, codigoDeProducto, cantidad, precioUnitario, cuitCliente);
                flagOnce = 1;
            }
            fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idVenta, fechaDeVenta, codigoDeProducto, cantidad, precioUnitario, cuitCliente);
            ventas = Venta_newConParametros(atoi(idVenta), fechaDeVenta, codigoDeProducto, atoi(cantidad), atof(precioUnitario), cuitCliente);
            if(ventas != NULL)
            {
                ll_add(lista, ventas);
            }
            else
            {
                printf("%d,%s,%s,%d,%f,%s\n", atoi(idVenta), fechaDeVenta, codigoDeProducto, atoi(cantidad), atof(precioUnitario), cuitCliente);
                getchar();
            }
        }while(!feof(pArchivo));
        fclose(pArchivo);
        ret=0;
    }
    return ret;
}
