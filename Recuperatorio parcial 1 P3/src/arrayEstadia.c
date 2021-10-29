/*
 * arrayEstadia.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#include "arrayEstadia.h"

void inicializarGuarderia (sEstadiaDiaria* lista,int max) {
	int i;

	for (i=0;i<max;i++) {
		lista[i].estaVacio=VACIO;
	}
}

int buscarEstadiaID(sEstadiaDiaria* lista,int idRecibido,int max) {
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

