/*
 * arrayFecha.h
 *
 *  Created on: 23 oct. 2021
 *      Author: Alan
 */

#ifndef ARRAYFECHA_H_
#define ARRAYFECHA_H_

#include <stdio.h>
#include <stdlib.h>

#include "input.h"

typedef struct {
	int dia;
	int mes;
	int anio;
}sCalendario;

/**
 * @fn sCalendario tomarFecha(char*, char*, char*, char*)
 * @brief Toma las fechas de la estructura de fechas
 *
 * @param mensajeDia Mensaje mostrado al pedir el dia
 * @param mensajeMes Mensaje mostrado al pedir el mes
 * @param mensajeAnio Mensaje mostrado al pedir el año
 * @param mensajeError Mensaje mostrado al momento en el que ocurre un error
 * @return retorna todos los datos recaudados a la estructura principal
 */
sCalendario tomarFecha(char* mensajeDia,char* mensajeMes,char* mensajeAnio,char* mensajeError);
/**
 * @fn void mostrarFecha(sCalendario)
 * @brief Muestra las fechas de la estructura de calendario
 *
 * @param fecha Es la estructura calendario perteneciente a la estructura principal
 */
void mostrarFecha(sCalendario fecha);



#endif /* ARRAYFECHA_H_ */
