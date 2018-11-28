#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "Parser.h"
#include "LinkedList.h"
#include "Informes.h"

int main()
{
    int auxVendidasTotales = 0;
    int auxMayor10K = 0;
    int auxMayor20K = 0;
    int auxLCDVendidos = 0;
    int eleccion;
    LinkedList* listaDeVentas = ll_newLinkedList();
    if(parser_parseVentas("data.csv", listaDeVentas) == 0)
    {
        printf("> Archivo cargado correctamente.\n");
    }
    else
    {
        printf("> Error al cargar el archivo.\n");
    }
    auxVendidasTotales = ll_count(listaDeVentas, informes_unidadesVendidasTotales, 0);
    auxMayor10K = ll_count(listaDeVentas, informes_vendidasMayorA, 10000);
    auxMayor20K = ll_count(listaDeVentas, informes_vendidasMayorA, 20000);
    auxLCDVendidos = ll_count(listaDeVentas, informes_cantidadDeLCD, 0);
    if(informes_crearInforme(auxVendidasTotales, auxMayor10K, auxMayor20K, auxLCDVendidos) == 0)
    {
        printf("> Informe creado correcamente.\n\n");
    }
    else
    {
        printf("> Error al crear el informe.\n\n");
    }
    printf("¿Desea mostrar el informe en la consola?\n1) Si\n2) No\n\nElección: ");
    scanf("%d",&eleccion);
    switch(eleccion)
    {
    case 1:
        system("clear");
        printf("*************************\nInforme de ventas\n*************************\n");
        printf("-Cantidad de unidades vendidas totales: %d\n", auxVendidasTotales);
        printf("-Cantidad de ventas por un monto mayor a $10.000: %d\n", auxMayor10K);
        printf("-Cantidad de ventas por un monto mayor a $20.000: %d\n", auxMayor20K);
        printf("-Cantidad de LCD vendidos: %d",auxLCDVendidos);
        printf("\n*************************\n");
        break;
    case 2:
        system("clear");
        printf("El archivo 'Informe.txt' se encuentra en el directorio raiz del programa.\n");
        break;
    default:
        printf("La opción %d no es valida", eleccion);
    }
    return 0;
}
