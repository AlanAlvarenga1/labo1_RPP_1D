/*
 * duenio.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Alan
 */

#ifndef ARRAYDUENIO_H_
#define ARRAYDUENIO_H_

#include "input.h"

#define maxDuenios 500

typedef struct {
	int id;
	char nombre[maxCharDuenios];
	int telefono;
	int estaVacio;
	int cantEstadias;
}sDuenio;

/**
 * @fn void inicializarDuenios(sDuenio*, int)
 * @brief Inicializa los due�os
 *
 * @param lista lista de due�os
 * @param max tama�o maximo de cantidad de due�os
 */
void inicializarDuenios (sDuenio* lista,int max);
/**
 * @fn void hardCodearDuenios(sDuenio*, int, int*, int*)
 * @brief Hardcodea due�os
 *
 * @param lista Lista de due�os
 * @param cantHardcodear cantidad de due�os a hardcodear
 * @param cuentaDuenios lleva la cuenta de cuantos due�os se registraron
 * @param idFinal ultimo id ingresado
 */
void hardCodearDuenios (sDuenio *lista, int cantHardcodear,int* cuentaDuenios,int* idFinal);
/**
 * @fn int buscarDuenioID(sDuenio*, int, int)
 * @brief Busca al due�o por su ID, y devuelve su posicion en la estructura
 *
 * @param lista Lista de due�os
 * @param idRecibido Id que recibe para su busqueda
 * @param max Cantidad maxima permitida para el registro de due�os
 * @return Devuelve la posicion del due�o buscado en el array de due�os
 */
int buscarDuenioID(sDuenio* lista,int idRecibido,int max);
/**
 * @fn void listarDuenios(sDuenio*, int)
 * @brief Muestra la lista de due�os
 *
 * @param lista lista de due�os
 * @param max cantidad maxima permitida para el registro de due�os
 */
void listarDuenios(sDuenio* lista,int max);

int chequearEstadiaAlan (sDuenio* lista,int max);

#endif /* ARRAYDUENIO_H_ */
