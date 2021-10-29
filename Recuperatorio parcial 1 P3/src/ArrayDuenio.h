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
 * @brief Inicializa los dueños
 *
 * @param lista lista de dueños
 * @param max tamaño maximo de cantidad de dueños
 */
void inicializarDuenios (sDuenio* lista,int max);
/**
 * @fn void hardCodearDuenios(sDuenio*, int, int*, int*)
 * @brief Hardcodea dueños
 *
 * @param lista Lista de dueños
 * @param cantHardcodear cantidad de dueños a hardcodear
 * @param cuentaDuenios lleva la cuenta de cuantos dueños se registraron
 * @param idFinal ultimo id ingresado
 */
void hardCodearDuenios (sDuenio *lista, int cantHardcodear,int* cuentaDuenios,int* idFinal);
/**
 * @fn int buscarDuenioID(sDuenio*, int, int)
 * @brief Busca al dueño por su ID, y devuelve su posicion en la estructura
 *
 * @param lista Lista de dueños
 * @param idRecibido Id que recibe para su busqueda
 * @param max Cantidad maxima permitida para el registro de dueños
 * @return Devuelve la posicion del dueño buscado en el array de dueños
 */
int buscarDuenioID(sDuenio* lista,int idRecibido,int max);
/**
 * @fn void listarDuenios(sDuenio*, int)
 * @brief Muestra la lista de dueños
 *
 * @param lista lista de dueños
 * @param max cantidad maxima permitida para el registro de dueños
 */
void listarDuenios(sDuenio* lista,int max);

int chequearEstadiaAlan (sDuenio* lista,int max);

#endif /* ARRAYDUENIO_H_ */
