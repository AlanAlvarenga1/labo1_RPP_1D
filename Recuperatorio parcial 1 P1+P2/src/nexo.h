/*
 * nexo.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "arrayPerro.h"
#include "arrayEstadia.h"
#include "arrayDuenio.h"
#include "arrayFecha.h"
#include "input.h"

/**
 * @fn int registrarEstadia(sEstadiaDiaria*, sPerro*, int, int, int, int)
 * @brief Registra cada estadia solicitada
 *
 * @param registroEstadia Estructura que contiene la lista de datos de las estadias
 * @param listaPerros Estructura que contiene la lista de datos de los perros
 * @param listaDuenios Estructura que contiene la lista de datos de los dueños
 * @param lenChar Tamaño maximo de los strings
 * @param lenPerros Cantidad maxima de perros
 * @param lenDuenios Cantidad maxima de dueños
 * @param ultimoID Ultimo ID de estadia utilizada
 * @param max Cantidad maxima de estadias
 * @return Retorna si se hizo correctamente la carga. -1 Si esta mal, 0 si esta ok.
 */
int registrarEstadia (sEstadiaDiaria *registroEstadia,sPerro *listaPerros,sDuenio *listaDuenios,int lenChar,int lenPerros,int lenDuenios,int ultimoID,int max);
/**
 * @fn int bajaEstadia(sEstadiaDiaria*,sPerro*,sDuenio*, int)
 * @brief Baja logicamente una estadia ya ocupada
 *
 * @param listaEstadias Estructura de estadia
 * @param listaPerros Estructura de perros
 * @param listaDuenios Estructura de dueños
 * @param max  Numero maximo de arrays en la estructura de estadias
 * @return retorna si se realizo exitosamente la funcion 0=SI -1=NO
 */
int bajaEstadia (sEstadiaDiaria* listaEstadias,sPerro* listaPerros,sDuenio* listaDuenio,int max);
/**
 * @fn void modificarReserva(sEstadiaDiaria*, sPerro*, sDuenio*, int, int, int)
 * @brief Funcion que sirve para modificar una reserva de estadia
 *
 * @param listaEstadias Estructura de estadia
 * @param listaPerros Estructura de perros
 * @param listaDuenios Estructura de dueños
 * @param lenEstadias Cantidad maxima de estadias
 * @param lenDuenios Cantidad maxima de dueños
 * @param lenPerros Cantidad maxima de perros
 */
void modificarReserva (sEstadiaDiaria* registroEstadia, sPerro* listaPerro, sDuenio* listaDuenios,int lenEstadias, int lenDuenios,int lenPerros);
/**
 * @fn void ordenarEstadias(sEstadiaDiaria*,sDuenio* int)
 * @brief Ordena por fecha o por nombre la lista de las estadias
 *
 * @param lista Estructura de estadia
 * @param listaDuenio Estructura de dueños
 * @param max  Numero maximo de arrays en la estructura de estadias
 */
void ordenarEstadias(sEstadiaDiaria* lista,sDuenio* listaDuenio, int max);
/**
 * @fn void listadoPerrosConEstadias(sEstadiaDiaria*, sPerro*, sDuenio*, int, int)
 * @brief Muestra la lista de perros y sus respectivas reservas
 *
 * @param listaGuarderia Lista de estadias
 * @param listaPerros Lista de perros
 * @param listaDuenio Lista de dueños
 * @param lenPerro Tamaño maximo de cantidad de perros
 * @param lenGuarderia Tamaño maximo de cantidad de guarderias
 */
void listadoPerrosConEstadias(sEstadiaDiaria *listaGuarderia,sPerro *listaPerros,sDuenio *listaDuenio,int lenPerro, int lenGuarderia);
/**
 * @fn void printUnaEstadia(sEstadiaDiaria*, sDuenio*, sPerro*, int)
 * @brief Imprime una sola estadia segun la posicion indicada
 *
 * @param listaEstadia Lista de estadias
 * @param listaDuenio Lista de dueños
 * @param listaPerros Lista de perros
 * @param i Indica la posicion de la estadia que se quiere imprimir
 */
void printUnaEstadia (sEstadiaDiaria* listaEstadia,sDuenio* listaDuenio,sPerro* listaPerro, int i);
/**
 * @fn void listarEstadias(sEstadiaDiaria*, sDuenio*, sPerro*, int)
 * @brief Muestra la lista de las estadias registradas
 *
 * @param listaEstadia Lista de estadias
 * @param listaDuenio Lista de dueños
 * @param listaPerros Lista de perros
 * @param max  Numero maximo de arrays en la estructura de estadias
 */
void listarEstadias(sEstadiaDiaria* lista,sDuenio* listaDuenio,sPerro* listaPerro, int max);

#endif /* NEXO_H_ */
