/*
 * arrayFecha.c
 *
 *  Created on: 23 oct. 2021
 *      Author: Alan
 */

#include "arrayFecha.h"

sCalendario tomarFecha(char* mensajeDia,char* mensajeMes,char* mensajeAnio,char* mensajeError) {
	sCalendario fechas;

	fechas.anio= tomarInt (mensajeAnio,mensajeError,2021, 2025);
	fechas.mes= tomarInt (mensajeMes,mensajeError,1, 12);
	fechas.dia= tomarInt (mensajeDia,mensajeError,1, 31);
	if (fechas.mes==4 || fechas.mes==6 || fechas.mes==9 || fechas.mes==11) {
		while (fechas.dia>30) {
			printf ("ERROR. El mes ingresado no puede tener 31 dias. Intente ingresar nuevamente el dia\n");
			fechas.dia= tomarInt (mensajeDia,mensajeError,1, 31);
		}
	}
	if (fechas.mes==2) {
		while (fechas.dia>28) {
			printf ("ERROR. El mes ingresado no puede tener mas de 28 dias. Intente ingresar nuevamente el dia\n");
			fechas.dia= tomarInt (mensajeDia,mensajeError,1, 31);
		}
	}



	return fechas;
}
void mostrarFecha(sCalendario fecha)
{
	printf(" %d/%d/%d\n", fecha.dia, fecha.mes, fecha.anio);
}
