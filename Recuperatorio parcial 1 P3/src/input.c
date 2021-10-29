/*
 * input.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#include "input.h"

int tomarInt (char* mensajeInicio,char* mensajeError,int min,int max) {
	int numero;
	int check;

	if (mensajeInicio!=NULL && mensajeError!=NULL) {
		printf ("%s",mensajeInicio);
		fflush (stdin);
		scanf("%d",&numero);
		check=checkInt(numero,min,max);

		while (check!=0) {
			printf ("%s",mensajeError);
			fflush (stdin);
			scanf("%d",&numero);
			check=checkInt(numero,min,max);
		}
	}
	return numero;
}

int checkInt(int numero,int min,int max) {
	int retorno=0;

	if (numero<min || numero>max) {
		retorno=-1;
	}

	return retorno;
}

int tomarString (char* mensajeInicio,char* mensajeError, char* string, int tamChar) {
    int tam;
    int check;
    int retorno=-1;

    if (mensajeInicio!=NULL && mensajeError!=NULL) {
		printf ("%s",mensajeInicio);
		fflush (stdin);
		fgets (string, tamChar,stdin);
		tam=strlen (string);
		string[tam-1] = 32;

		check=checkString(string,tam);

		while (check==-1) {
			printf ("%s",mensajeError);
			fflush (stdin);
			fgets (string, tamChar,stdin);
			tam=strlen (string);
			string[tam-1] = 32;

			check=checkString(string,tam);
		}

		retorno=0;
    }

    return retorno;
}

int checkString(char* string,int tamMax) {
	int i;
	int retorno=0;

	for (i=0;i<tamMax-1;i++) {
		if ((isalpha(string[i])==0) && string[i]!=32) {
			retorno=-1;
			break;
		}
	}

	return retorno;
}

float tomarFloat (char* mensajeInicio,char* mensajeError,int min,int max) {
	float numero;
	float check;

	if (mensajeInicio!=NULL && mensajeError!=NULL) {
		printf ("%s",mensajeInicio);
		fflush (stdin);
		scanf("%f",&numero);
		check=checkInt(numero,min,max);

		while (check!=0) {
			printf ("%s",mensajeError);
			fflush (stdin);
			scanf("%f",&numero);
			check=checkInt(numero,min,max);
		}
	}
	return numero;
}

int checkFloat(float numero,float min,float max) {
	int retorno=0;

	if (numero<min || numero>max) {
		retorno=-1;
	}

	return retorno;
}

int systemPause(char* message) {
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s",message);
		getchar();
		ret=0;
	}
	return ret;
}
