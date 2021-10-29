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
	float sumaEdadPerros=0;
	float promedioEdadPerros;
	int ultimoIDPerro=6999;
	int ultimoIDEstadia=99999;
	int ultimoIDDuenio=29999;
	int posicionPerroConMasEstadias;
	int cantAlanConMasDeUnaEstadia;
	int cantLuciaConEstadiaEnQuincenaNov;

	sPerro perrosGuarderia[maxPerros];
	sEstadiaDiaria datosGuarderia[maxEstadias];
	sDuenio dueniosPerros[maxDuenios];

	inicializarPerros (perrosGuarderia,500);
	inicializarGuarderia (datosGuarderia,500);
	inicializarDuenios (dueniosPerros,500);

	hardCodearPerros (perrosGuarderia, 3,&cantPerros,&sumaEdadPerros,&ultimoIDPerro);
	hardCodearDuenios (dueniosPerros, 5,&cantDuenios,&ultimoIDDuenio);


	while (opcion!=12) {
		mostrarMenu (&opcion);
		ordenarEstadias (datosGuarderia,dueniosPerros,maxEstadias);

		promedioEdadPerros=sumaEdadPerros/cantPerros;

		switch (opcion) {
			case 1:
				if (cantPerros>0) {
					if (registrarEstadia (datosGuarderia,perrosGuarderia,dueniosPerros,maxChar,maxPerros,maxDuenios,ultimoIDEstadia,maxEstadias)==0) {
						ultimoIDEstadia++;
						cantEstadias++;
					}
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf ("ERROR. Es necesario registrar al menos a un perro.");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 2:
				if (cantEstadias>0) {
					modificarReserva (datosGuarderia, perrosGuarderia,dueniosPerros,maxEstadias,maxDuenios,maxPerros);
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 3:
				if (cantEstadias>0) {
					if (bajaEstadia (datosGuarderia,perrosGuarderia,dueniosPerros,maxEstadias)==0) {
						cantEstadias--;
					}
					else {
						printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf ("ERROR. No se ha podido realizar la baja de la estadia. Intente nuevamente");
						printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
					}
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf ("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 4:
				if (cantEstadias>0) {
					listarEstadias (datosGuarderia,dueniosPerros,perrosGuarderia,maxEstadias);
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 5:
				if (cantPerros>0) {
					listarPerros (perrosGuarderia,maxPerros);
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf ("ERROR. No se ha cargado ningun perro. Intente nuevamente luego de cargar uno");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 6:
				if (cantPerros>0) {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf ("El promedio de edad de los perros cargados es de %.2f años",promedioEdadPerros);
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf ("ERROR. No se ha cargado ningun perro. Intente nuevamente luego de cargar uno");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 7:
				if (cantEstadias>0) {
					posicionPerroConMasEstadias=detectarPerroConMasEstadias (perrosGuarderia,maxPerros);
					printf ("------------------------------------------------------------------------------------------------------------------------------\n");
					printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre","Raza","Edad","Cantidad de estadias\n");
					printUnPerro(perrosGuarderia,posicionPerroConMasEstadias);
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 8:
				if (cantEstadias>0) {
					listadoPerrosConEstadias(datosGuarderia,perrosGuarderia,dueniosPerros,maxPerros,maxEstadias);
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 9:
				if (registrarUnPerro (perrosGuarderia,maxChar,maxPerros,ultimoIDPerro,&sumaEdadPerros)==0) {
					ultimoIDPerro++;
					cantPerros++;
				}

				systemPause("Presione ENTER para continuar");
				break;
			case 10:
				if (cantEstadias>0 && cantDuenios>0) {
					cantAlanConMasDeUnaEstadia=chequearEstadiaAlan (dueniosPerros,maxDuenios);

					if (cantAlanConMasDeUnaEstadia!=-1) {
						printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf ("La cantidad de personas con el nombre Alan y con mas de una estadia es de %d",cantAlanConMasDeUnaEstadia);
						printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
					}
					else {
						printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf ("No Hay ninguna persona llamada Alan que tenga mas de una estadia registrada");
						printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
					}
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}

				systemPause("Presione ENTER para continuar");
				break;
			case 11:
				if (cantEstadias>0 && cantDuenios>0) {
					cantLuciaConEstadiaEnQuincenaNov=checkLuciaConEstadia (datosGuarderia,dueniosPerros, maxEstadias, maxDuenios);

					if (cantLuciaConEstadiaEnQuincenaNov!=-1) {
						printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
						printf ("La cantidad de personas con el nombre Lucia y con mas de una estadia en la segunda quincena de noviembre del 2021 es de %d",cantLuciaConEstadiaEnQuincenaNov);
						printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
					}
					else {
						printf ("\n\n------------------------------------------------------------------------------------------------------------------------------");
						printf ("\nNo hay ninguna persona de nombre Lucia que tenga una estadia en la segunda quincena de noviembre del 2021");
						printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
					}
				}
				else {
					printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
					printf("ERROR. No hay ninguna estadia registrada. Utilice el primer paso primero");
					printf ("\n------------------------------------------------------------------------------------------------------------------------------\n\n");
				}

				systemPause("Presione ENTER para continuar");
				break;

			case 12:
				printf ("\n\nGracias por usar este programa!!!");
		}
	}
}
