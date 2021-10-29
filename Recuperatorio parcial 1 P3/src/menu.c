/*
 * menu.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#include "menu.h"

void mostrarMenu (int* opciones) {

	printf ("\n\n-------------------MENU-------------------\n\n"
			"1) Reservar estadia\n"
			"2) Modificar estadia\n"
			"3) Cancelar estadia\n"
			"4) Listar estadia\n"
			"5) Listar perros\n"
			"6) Promediar edad de los perros\n"
			"7) Listar el perro con mas estadias\n"
			"8) Listado de perros con sus estadias\n"
			"9) Alta de perro\n"
			"10) Listar la cantidad de dueños llamados Alan que tienen al menos una estadia\n"
			"11) Listar la cantidad de dueños llamados Lucia que tienen una reserva en la segunda quincena de 2021\n"
			"12) Salir del programa\n\n");

			*opciones= tomarInt ("Ingrese la opcion que deseas utilizar: ","ERROR. Has ingresado una opcion incorrecta. 1-12: ",1, 12);
}

void subMenuModificacionEstadia(int* opciones) {

	printf ("1) Ingrese el ID de la reserva que desea modificar\n"
			"2) Modificar el telefono de contacto\n"
			"3) Modificar el perro que esta en la reserva\n"
			"4) Salir del programa\n\n");

			*opciones= tomarInt ("Ingrese la opcion que deseas utilizar: ","ERROR. Has ingresado una opcion incorrecta. 1-4: ",1, 4);
}
