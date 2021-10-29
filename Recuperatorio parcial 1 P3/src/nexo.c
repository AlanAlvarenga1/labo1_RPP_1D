/*
 * nexo.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#include "nexo.h"

int registrarEstadia (sEstadiaDiaria *registroEstadia,sPerro *listaPerros,sDuenio *listaDuenios,int lenChar,int lenPerros,int lenDuenios,int ultimoID,int max) {
	int retorno=-1;
	int i=0;
	int flag=0;
	int posicionPerro;
	int posicionDuenio;
	int seguir=1;

	printf ("\n\n-------------------REGISTRO-------------------\n\n");

	while (flag==0 && i<max) {
		if (registroEstadia[i].estaVacio==VACIO) {
			flag=1;
		}
		else {
			i++;
		}
	}
	if (flag==1) {
		while (seguir==1) {
			registroEstadia[i].id=ultimoID+1;

			listarDuenios(listaDuenios,lenDuenios);

			posicionDuenio=buscarDuenioID(listaDuenios,tomarInt("Ingrese el ID del duenio que sera registrado: ","ERROR. Has ingresado un ID incorrecto. Intente nuevamente: ",30000,35000),lenDuenios);
			while (posicionDuenio==-1) {
				posicionDuenio=buscarDuenioID(listaDuenios,tomarInt("ERROR. El ID que has ingresado no fue registrado. Intente nuevamente: ","ERROR. Has ingresado un ID incorrecto. Intente nuevamente: ",30000,35000),lenDuenios);
			}
			registroEstadia[i].idDuenio=listaDuenios[posicionDuenio].id;

			listarPerros(listaPerros,lenPerros);

			posicionPerro=buscarPerroID(listaPerros,tomarInt("Ingrese el ID del perro que sera registrado: ","ERROR. Has ingresado un ID incorrecto. Intente nuevamente: ",7000,7500),lenPerros);
			while (posicionPerro==-1) {
				posicionPerro=buscarPerroID(listaPerros,tomarInt("ERROR. El ID que has ingresado no fue registrado. Intente nuevamente: ","ERROR. Has ingresado un ID incorrecto. Intente nuevamente: ",7000,7500),lenPerros);
			}
			registroEstadia[i].idPerro=listaPerros[posicionPerro].id;

			registroEstadia[i].fecha=tomarFecha("Ingrese el dia 1-31: ","Ingrese el mes 1-12: ","Ingrese el año 2021-2025: ","ERROR. Ingresaste un caracter invalido. Intenta nuevamente: ");

			printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
			printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre del dueño","Telefono del dueño","Nombre del Perro", "Fecha de reserva\n");
			printUnaEstadia (registroEstadia,listaDuenios,listaPerros,i);
			printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");

			seguir=tomarInt ("¿Los datos cargados son correctos?. 0= SI 1= NO -1= SALIR: ","ERROR. Ingrese un caracter valido: ",-1, 1);

			switch (seguir) {
				case -1:
					printf ("\nSALIENDO.....\n\n");
					break;
				case 0:
					registroEstadia[i].estaVacio=OCUPADO;
					listaPerros[posicionPerro].cantEstadias++;
					listaDuenios[posicionDuenio].cantEstadias++;
					retorno=0;
					printf("\nSe registro exitosamente la estadia\n\n");
					break;
				case 1:
					printf ("\nVaciando los datos cargados.....\n\n");
					break;
			}
		}
	}
	else {
		printf ("ERROR. No hay espacios disponibles");
	}
	return retorno;
}

int bajaEstadia (sEstadiaDiaria* listaEstadias,sPerro* listaPerros,sDuenio* listaDuenio,int max) {
	int retorno=-1;
	int iEstadia;
	int iPerro;
	int iDuenio;
	int seguir=1;

	printf ("\n\n-------------------BAJA DE ESTADIA-------------------\n\n");

	listarEstadias(listaEstadias,listaDuenio,listaPerros, max);

	while (seguir==1) {
		iEstadia=buscarEstadiaID(listaEstadias,tomarInt ("Ingrese el ID que desea eliminar: ","ERROR. Ingresaste un valor no valido. Intente nuevamente: ",100000,100500),max);
		while (iEstadia==-1) {
			iEstadia=buscarEstadiaID(listaEstadias,tomarInt ("ERROR. No se ha encontrado algun ID a eliminar. Chequee la lista y vuelva a intentar: ","ERROR. Ingresaste un valor no valido. Intente nuevamente: ",100000,100500),max);
		}
		iPerro=buscarPerroID(listaPerros,listaEstadias[iEstadia].idPerro,max);
		iDuenio=buscarDuenioID(listaDuenio,listaEstadias[iEstadia].idDuenio,max);

		printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
		printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre del dueño","Telefono del dueño","Nombre del Perro", "Fecha de reserva\n");
		printf ("------------------------------------------------------------------------------------------------------------------------------\n");
		printUnaEstadia (listaEstadias,listaDuenio,listaPerros,iEstadia);
		printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
		seguir=tomarInt("Desea eliminar esta estadia? 0= SI 1= NO -1= SALIR: ","ERROR. Ingrese un caracter valido: ",-1,1);

		switch (seguir) {
			case -1:
				printf ("SALIENDO.....\n\n");
				break;
			case 0:
				listaEstadias[iEstadia].estaVacio=VACIO;
				listaPerros[iPerro].cantEstadias--;
				listaDuenio[iDuenio].cantEstadias--;
				retorno=0;
				printf("Se elimino exitosamente la estadia\n\n");
				break;
			case 1:
				printf ("Vaciando los datos cargados.....\n\n");
				break;
		}
	}
	return retorno;
}


void modificarReserva (sEstadiaDiaria* registroEstadia, sPerro* listaPerro, sDuenio* listaDuenios,int lenEstadias, int lenDuenios,int lenPerros) {
	int opcion=0;
	int i=-1;
	int posicionPerro;
	int posicionDuenio;
	int confirmacion;
	int nuevoTelefono;
	int nuevoPerro;

	while (opcion!=4) {
		printf ("\n\n-------------------MODIFICACION-------------------\n\n");
		if (i!=-1) {
			printf ("------------------------------------------------------------------------------------------------------------------------------\n");
			printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre del dueño","Telefono del dueño","Nombre del Perro", "Fecha de reserva");
			printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
			printUnaEstadia (registroEstadia,listaDuenios,listaPerro,i);
			printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
		}
		else {
			listarEstadias(registroEstadia,listaDuenios,listaPerro, lenEstadias);
		}
		subMenuModificacionEstadia(&opcion);

		posicionDuenio=buscarDuenioID(listaDuenios,registroEstadia[i].idDuenio,lenDuenios);
		posicionPerro=buscarPerroID(listaPerro,registroEstadia[i].idPerro,lenPerros);

		switch (opcion) {
			case 1:
				i=buscarEstadiaID(registroEstadia,tomarInt("Ingrese el ID de la estadia que deseas modificar: ","ERROR. Ingresaste un valor no valido. Intente nuevamente: ",100000,100500), lenEstadias);
				if (i==-1) {
					printf ("\nERROR. No se ha encontrado algun ID a eliminar. Chequee la lista y vuelva a intentar\n");
				}
				else {
					printf ("\nID Ingresado exitosamente\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 2:
				if (i!=-1) {
					confirmacion=1;
					while (confirmacion==1) {
						nuevoTelefono=tomarInt ("Ingrese el numero de telefono del dueño del perro. Sin guiones: ","ERROR. Has ingresado un numero invalido. Intente nuevamente: ",1000000,1199999999);

						while (nuevoTelefono==listaDuenios[posicionDuenio].telefono) {
							nuevoTelefono=tomarInt ("ERROR. No puedes cambiar al mismo numero. Intentelo nuevamente: ","ERROR. Has ingresado un numero invalido. Intente nuevamente: ",1000000,1199999999);
						}
						printf ("\n¿Desea cambiar el numero de %d a %d?\n",listaDuenios[posicionDuenio].telefono,nuevoTelefono);
						confirmacion=tomarInt("0= SI 1= NO -1= SALIR: ","ERROR. Ingrese un caracter valido: ",-1,1);

						switch (confirmacion) {
							case -1:
								printf ("\n\nSaliendo....");
								break;
							case 0:
								listaDuenios[posicionDuenio].telefono=nuevoTelefono;
								printf ("\n\nCambio realizado con exito!");
								break;
							case 1:
								printf ("\nReiniciando....\n\n");
								break;
						}
					}
				}
				else {
					printf ("\nERROR. Primero debe ingresar el ID a modificar\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 3:
				if (i!=-1) {
					confirmacion=1;
					while (confirmacion==1) {
						listarPerros(listaPerro,lenPerros);

						nuevoPerro=buscarPerroID(listaPerro,tomarInt("Ingresa el ID del perro que deseas registrar: ","ERROR. Has ingresado un ID invalido. Intenta nuevamente: ",7000,7500), maxPerros);

						while (nuevoPerro==posicionPerro) {
							nuevoPerro=buscarPerroID(listaPerro,tomarInt("ERROR. No se puede cambiar al perro por el mismo. Intente nuevamente: ","ERROR. Has ingresado un ID invalido. Intenta nuevamente: ",7000,7500), maxPerros);
						}

						printf ("¿Desea cambiar el perro de %s a %s?\n",listaPerro[posicionPerro].nombre,listaPerro[nuevoPerro].nombre);
						confirmacion=tomarInt("0= SI 1= NO -1= SALIR: ","ERROR. Ingrese un caracter valido: ",-1,1);

						switch (confirmacion) {
							case -1:
								printf ("\n\nSaliendo....");
								break;
							case 0:
								listaPerro[posicionPerro].cantEstadias--;
								registroEstadia[i].idPerro=listaPerro[nuevoPerro].id;
								listaPerro[nuevoPerro].cantEstadias++;
								printf ("\n\nCambio realizado con exito!");
								break;
							case 1:
								printf ("\n\nReiniciando....\n\n");
								break;
						}
					}
				}
				else {
					printf ("\nERROR. Primero debe ingresar el ID a modificar\n");
				}
				systemPause("Presione ENTER para continuar");
				break;
			case 4:
				printf ("ABANDONANDO PROGRAMA....\n\n");

		}
	}
}

void ordenarEstadias(sEstadiaDiaria* lista,sDuenio* listaDuenio, int max) {
	int i;
	int limit;
	int flagSwap;
	int iDuenioUno;
	int iDuenioDos;
	sEstadiaDiaria aux;

	limit=max-1;
		do {
			flagSwap=0;
			for (i=0;i<limit;i++) {
				iDuenioUno=buscarDuenioID(listaDuenio,lista[i].idDuenio,max);
				iDuenioDos=buscarDuenioID(listaDuenio,lista[i+1].idDuenio,max);


				if ((lista[i].fecha.anio<lista[i+1].fecha.anio) ||
					((lista[i].fecha.anio==lista[i+1].fecha.anio) && (lista[i].fecha.mes<lista[i+1].fecha.mes)) ||
					((lista[i].fecha.anio==lista[i+1].fecha.anio) && (lista[i].fecha.mes==lista[i+1].fecha.mes) && (lista[i].fecha.dia<lista[i+1].fecha.dia)) ||
					((lista[i].fecha.anio==lista[i+1].fecha.anio) && (lista[i].fecha.mes==lista[i+1].fecha.mes) && (lista[i].fecha.dia==lista[i+1].fecha.dia) && (strcmp (listaDuenio[iDuenioUno].nombre,listaDuenio[iDuenioDos].nombre)==-1))) {
					aux=lista[i];
					lista[i]=lista[i+1];
					lista[i+1]=aux;
					flagSwap=1;
				}
			}
			limit--;
		}while (flagSwap);
}

void listadoPerrosConEstadias(sEstadiaDiaria *listaGuarderia,sPerro *listaPerros,sDuenio *listaDuenio,int lenPerro, int lenGuarderia) {
	int i;
	int j;

	printf ("\n\n-------------------LISTADO DE PERROS Y ESTADIAS-------------------\n\n");

	for (i=0;i<lenPerro;i++) {
		if (listaPerros[i].cantEstadias>0) {
			printf ("------------------------------------------------------------------------------------------------------------------------------\n");
			printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre","Raza","Edad","Cantidad de estadias\n");
			printUnPerro(listaPerros,i);
			printf ("------------------------------------------------------------------------------------------------------------------------------\n");
			printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre del dueño","Telefono del dueño","Nombre del Perro", "Fecha de reserva\n");
			for (j=0;j<lenGuarderia;j++) {
				if (listaPerros[i].id==listaGuarderia[j].idPerro && listaPerros[i].estaVacio==OCUPADO && listaGuarderia[j].estaVacio==OCUPADO) {
					printUnaEstadia(listaGuarderia,listaDuenio,listaPerros,j);
				}
			}
			printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
			printf ("\n\n");
		}
	}
}

void printUnaEstadia (sEstadiaDiaria* listaEstadia,sDuenio* listaDuenio,sPerro* listaPerro, int i) {
	int posicionPerro;
	int posicionDuenio;

	posicionDuenio=buscarDuenioID(listaDuenio,listaEstadia[i].idDuenio,500);
	posicionPerro=buscarPerroID(listaPerro,listaEstadia[i].idPerro,500);

	printf ("%-10d %-25s %-25d %-25s",listaEstadia[i].id,listaDuenio[posicionDuenio].nombre,listaDuenio[posicionDuenio].telefono,listaPerro[posicionPerro].nombre);
	mostrarFecha(listaEstadia[i].fecha);

}

void listarEstadias(sEstadiaDiaria* lista,sDuenio* listaDuenio,sPerro* listaPerro, int max) {
	int i;

	printf ("\n------------------------------------------------------------------------------------------------------------------------------\n");
	printf ("%-10s %-25s %-25s %-25s %s","ID","Nombre del dueño","Telefono del dueño","Nombre del Perro", "Fecha de reserva\n");
	printf ("------------------------------------------------------------------------------------------------------------------------------\n");
	for (i=0;i<max;i++) {
		if (lista[i].estaVacio==OCUPADO) {
			printUnaEstadia (lista,listaDuenio,listaPerro, i);
		}
	}
	printf ("------------------------------------------------------------------------------------------------------------------------------\n\n");
}

int checkLuciaConEstadia (sEstadiaDiaria* listaEstadias,sDuenio* listaDuenio, int maxEstad, int maxDuen) {
	int retorno=-1;
	int cantVerificada=0;
	int i;
	int j;

	for (i=0;i<maxDuen;i++) {
		if (listaDuenio[i].cantEstadias>0) {
			for (j=0;j<maxEstad;j++) {
				if (listaEstadias[j].estaVacio==OCUPADO) {
					if (listaDuenio[i].id==listaEstadias[j].idDuenio) {
						if ((strcmp(listaDuenio[i].nombre,"Lucia")==0) || strcmp(listaDuenio[i].nombre,"lucia")==0) {
							if (listaEstadias[j].fecha.dia>15 && listaEstadias[j].fecha.mes==11 && listaEstadias[j].fecha.anio==2021) {
								cantVerificada++;
								break;
							}
						}
					}
				}
			}
		}
	}
	if (cantVerificada>0) {
		retorno=cantVerificada;
	}

	return retorno;
}
