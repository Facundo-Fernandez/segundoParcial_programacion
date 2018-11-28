#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_unidadesVendidasTotales(void* lista, int i);
int informes_vendidasMayorA(void* lista, int i, int montoMayor);
int informes_cantidadDeLCD(void* lista, int i);
int informes_crearInforme(int cantidadTotales, int mayor10K, int mayor20K, int totalLCD);


#endif // INFORMES_H_INCLUDED
