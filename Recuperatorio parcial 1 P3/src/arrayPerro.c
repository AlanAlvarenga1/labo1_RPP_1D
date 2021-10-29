/*
 * array.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#include "arrayPerro.h"

void inicializarPerros (sPerro* lista,int max) {
	int i;

	for (i=0;i<max;i++) {
		lista[i].cantEstadias=0;
		lista[i].estaVacio=VACIO;
	}
}

void hardCodearPerros (sPerro *lista, int cantHardcodear,int* cuentaPerros,float* sumaEdades,int* idFinal) {
	int i;
	int id[] = {7000,7001,7002};
	char nombre[][21]= {"Lobo","Sheila","Reina"};
	char raza[][21]= {"Sharpei","Golden","Galgo"};
	int edad[]= {2,12,13};
	int cantPerros=0;
	int sumaEdadesPerros=0;

	for (i=0;i<cantHardcodear;i++) {
		lista[i].id=id[i];
		strcpy(lista[i].nombre,nombre[i]);
		strcpy(lista[i].raza,raza[i]);
		lista[i].edad=edad[i];
		lista[i].estaVacio=OCUPADO;

		cantPerros++;
		*idFinal=*idFinal+1;
		sumaEdadesPerros=sumaEdadesPerros+lista[i].edad;
	}

	*cuentaPerros=cantPerros;
	*sumaEdades=sumaEdadesPerros;
}

int registrarUnPerro (sPerro *listaPerros,int lenChar,int lenPerros,int ultimoID,float* sumaEdad) {
	int retorno=-1;
	int i=0;
	int flag=0;
	int seguir=1;

	while (flag==0 && i<lenPerros) {
		if (listaPerros[i].estaVacio==VACIO) {
			flag=1;
		}
		else {
			i++;
		}
	}
	if (flag==1) {
		while (seguir==1) {
			listaPerros[i].id=ultimoID+1;
			tomarString ("Ingrese el nombre del perro: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ", listaPerros[i].nombre, lenChar);
			tomarString ("Ingrese el nombre de la raza del perro: ","ERROR. Has ingresado un caracter invalido. Intente nuevamente: ", listaPerros[i].raza, lenChar);
			listaPerros[i].edad=tomarFloat ("Ingrese la edad del perro: ","ERROR. Has ingresado un numero invalido. Intente nuevamente: ",0, 20);

			printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
			printf ("%-10s %-25s %-25s %-25s %s\n","ID","Nombre del perro","Raza", "Edad", "Cantidad de Estadias");
			printf ("------------------------------------------------------------------------------------------------------------------------------\n");
			printUnPerro (listaPerros,i);
			printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");

			seguir=tomarInt ("¿Los datos cargados son correctos?. 0=SI 1=NO -1=SALIR: ","ERROR. Ingrese un caracter valido: ",-1, 1);

			switch (seguir) {
				case -1:
					printf ("SALIENDO.....\n\n");
					break;
				case 0:
					listaPerros[i].estaVacio=OCUPADO;
					*sumaEdad=*sumaEdad+listaPerros[i].edad;
					retorno=0;
					printf("Se registro exitosamente el perro\n\n");
					break;
				case 1:
					printf ("Vaciando los datos cargados.....\n\n");
					break;
			}
		}
	}
	else {
		printf ("ERROR. No hay espacios disponibles");
	}
	return retorno;
}


int buscarPerroID(sPerro* lista,int idRecibido,int max) {
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

int detectarPerroConMasEstadias (sPerro* lista, int max) {
	int i;
	int contadorMaxEstadias=0;
	int retorno=-1;


	for (i=0;i<max;i++) {
		if (lista[i].estaVacio==OCUPADO) {
			if (lista[i].cantEstadias>contadorMaxEstadias) {
				contadorMaxEstadias=lista[i].cantEstadias;
				retorno=i;
			}
		}
	}
	return retorno;
}

void printUnPerro (sPerro* lista,int i) {
	printf ("%-10d %-25s %-25s %-25.2f %d\n",lista[i].id,lista[i].nombre,lista[i].raza,lista[i].edad,lista[i].cantEstadias);
}

void listarPerros (sPerro* lista, int max) {
	int i;

	printf ("\n\n------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("%-10s %-25s %-25s %-25s %s\n","ID","Nombre del perro","Raza", "Edad", "Cantidad de Estadias");
	printf ("------------------------------------------------------------------------------------------------------------------------------\n");

	for (i=0;i<max;i++) {
		if (lista[i].estaVacio==OCUPADO) {
			printUnPerro (lista,i);
		}
	}
	printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
}
