/*
 * duenio.c
 *
 *  Created on: 15 oct. 2021
 *      Author: Alan
 */

#include "ArrayDuenio.h"

void inicializarDuenios (sDuenio* lista,int max) {
	int i;

	for (i=0;i<max;i++) {
		lista[i].estaVacio=VACIO;
	}
}

void hardCodearDuenios (sDuenio *lista, int cantHardcodear,int* cuentaDuenios,int* idFinal) {
	int i;
	int id[] = {30000,30001,30002,30003,30004};
	char nombre[][41]= {"Marcos","Pablo","Juan","Lucas","Federico"};
	int telefono[]= {1144103546,1178921361,1112378945,1174195286,1198653274};
	int cantDuenios=0;

	for (i=0;i<cantHardcodear;i++) {
		lista[i].id=id[i];
		strcpy(lista[i].nombre,nombre[i]);
		lista[i].telefono=telefono[i];
		lista[i].estaVacio=OCUPADO;

		cantDuenios++;
	}

	*cuentaDuenios=cantDuenios;
	*idFinal=id[i];
}

int buscarDuenioID(sDuenio* lista,int idRecibido,int max) {
	int i;
	int retorno = -1;

	for(i=0; i<max; i++) {
		if(lista[i].estaVacio == OCUPADO && lista[i].id == idRecibido) {
			retorno = i;
			break;
		}
	}

	return retorno;
}

void listarDuenios(sDuenio* lista,int max) {
	int i;

	printf ("------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("%-10s %-25s %s\n","ID","Nombre del dueño","Telefono del dueño");
	printf ("------------------------------------------------------------------------------------------------------------------------------\n");

	for (i=0;i<max;i++) {
		if (lista[i].estaVacio==OCUPADO) {
			printf ("%-10d %-25s %d\n",lista[i].id,lista[i].nombre,lista[i].telefono);
		}
	}
	printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
}
