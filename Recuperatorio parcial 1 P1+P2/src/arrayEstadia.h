/*
 * arrayEstadia.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#ifndef ARRAYESTADIA_H_
#define ARRAYESTADIA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"
#include "input.h"
#include "arrayFecha.h"

#define maxEstadias 500

typedef struct {
	int id;
	int idDuenio;
	int idPerro;
	sCalendario fecha;
	int estaVacio;
}sEstadiaDiaria;
/**
 * @fn void inicializarGuarderia(sEstadiaDiaria*, int)
 * @brief Deja a los espacios de la estructura de estadia en vacio
 *
 * @param lista Estructura de estadia
 * @param max Numero maximo de arrays en la estructura de estadias
 */
void inicializarGuarderia (sEstadiaDiaria* lista,int max);
/**
 * @fn int buscarEstadiaID(sEstadiaDiaria*, int, int)
 * @brief Busca una estadia por su ID y devuelve su posicion en el array de estructura de estadias
 *
 * @param lista Lista de estadias
 * @param idRecibido Id recibido para la busqueda
 * @param max cantidad maxima de estadias que se pueden registrar
 * @return Devuelve la posicion en el array de la estadia buscada
 */
int buscarEstadiaID(sEstadiaDiaria* lista,int idRecibido,int max);


#endif /* ARRAYESTADIA_H_ */
