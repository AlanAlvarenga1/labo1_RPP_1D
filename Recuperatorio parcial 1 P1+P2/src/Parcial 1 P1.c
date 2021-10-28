/*
 ============================================================================
 Name        : Parcial.c
 Author      : Alan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "nexo.h"
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion=0;
	int cantEstadias=0;
	int cantPerros=0;
	int cantDuenios=0;
	int sumaEdadPerros=0;
	float promedioEdadPerros;
	int ultimoIDPerro=6999;
	int ultimoIDEstadia=99999;
	int ultimoIDDuenio=29999;
	int posicionPerroConMasEstadias;

	sPerro perrosGuarderia[maxPerros];
	sEstadiaDiaria datosGuarderia[maxEstadias];
	sDuenio dueniosPerros[maxDuenios];

	inicializarPerros (perrosGuarderia,500);
	inicializarGuarderia (datosGuarderia,500);
	inicializarDuenios (dueniosPerros,500);

	hardCodearPerros (perrosGuarderia, 3,&cantPerros,&sumaEdadPerros,&ultimoIDPerro);
	hardCodearDuenios (dueniosPerros, 5,&cantDuenios,&ultimoIDDuenio);
	promedioEdadPerros=sumaEdadPerros/cantPerros;

	while (opcion!=9) {
		mostrarMenu (&opcion);
		ordenarEstadias (datosGuarderia,dueniosPerros,maxEstadias);

		switch (opcion) {
			case 1:
				if (cantPerros>0) {
					if (registrarEstadia (datosGuarderia,perrosGuarderia,dueniosPerros,maxChar,maxPerros,maxDuenios,ultimoIDEstadia,maxEstadias)==0) {
						ultimoIDEstadia++;
						cantEstadias++;
					}
				}
				else {
					printf ("ERROR. Es necesario registrar al menos a un perro.\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 2:
				if (cantEstadias>0) {
					modificarReserva (datosGuarderia, perrosGuarderia,dueniosPerros,maxEstadias,maxDuenios,maxPerros);
				}
				else {
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 3:
				if (cantEstadias>0) {
					if (bajaEstadia (datosGuarderia,perrosGuarderia,dueniosPerros,maxEstadias)==0) {
						cantEstadias--;
					}
					else {
						printf ("ERROR. No se ha podido realizar la baja de la estadia. Intente nuevamente\n\n");
					}
				}
				else {
					printf ("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 4:
				if (cantEstadias>0) {
					listarEstadias (datosGuarderia,dueniosPerros,perrosGuarderia,maxEstadias);
				}
				else {
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 5:
				if (cantPerros>0) {
					listarPerros (perrosGuarderia,maxPerros);
				}
				else {
					printf ("ERROR. No se ha cargado ningun perro. Intente nuevamente luego de cargar uno\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 6:
				if (cantPerros>0) {
					printf ("El promedio de edad de los perros cargados es de %f años",promedioEdadPerros);
				}
				else {
					printf ("ERROR. No se ha cargado ningun perro. Intente nuevamente luego de cargar uno\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 7:
				if (cantEstadias>0) {
					posicionPerroConMasEstadias=detectarPerroConMasEstadias (perrosGuarderia,maxPerros);
					printf ("------------------------------------------------------------------------------------------------------------------------------\n");
					printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre","Raza","Edad","Cantidad de estadias\n");
					printUnPerro(perrosGuarderia,posicionPerroConMasEstadias);
					printf ("------------------------------------------------------------------------------------------------------------------------------\n");
				}
				else {
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 8:
				if (cantEstadias>0) {
					listadoPerrosConEstadias(datosGuarderia,perrosGuarderia,dueniosPerros,maxPerros,maxEstadias);
				}
				else {
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 9:
				printf ("Gracias por usar este programa!!!");
		}
	}
}
