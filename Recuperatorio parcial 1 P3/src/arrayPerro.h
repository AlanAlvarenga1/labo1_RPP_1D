/*
 * array.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Alan
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

#define maxPerros 500

typedef struct {
	int id;
	char nombre[maxChar];
	char raza[maxChar];
	float edad;
	int cantEstadias;
	int estaVacio;
}sPerro;

/**
 * @fn void inicializarPerros(sPerro*, int)
 * @brief Inicializa en vacio la lista de perros
 *
 * @param lista Lista de perros
 * @param max Cantidad maxima de perros que pueden ser registrados
 */
void inicializarPerros (sPerro* lista,int max);
/**
 * @fn void hardCodearPerros(sPerro*, int, int*, int*, int*)
 * @brief Registra automaticamente una lista de perros predefinida
 *
 * @param lista Lista de perros
 * @param cantHardcodear Cantidad de perros a hardcodear
 * @param cuentaPerros Lleva la cuenta de cuantos perros se registraron
 * @param sumaEdades Suma las edades de los perros registrados
 * @param idFinal Ultimo ID registrado
 */
void hardCodearPerros (sPerro* lista, int cantHardcodear,int* cuentaPerros,float* sumaEdades,int* idFinal);
/**
 * @fn int registrarUnPerro(sPerro*, int, int, int)
 * @brief
 *
 * @param listaPerros
 * @param lenChar
 * @param lenPerros
 * @param ultimoID
 * @return
 */
int registrarUnPerro (sPerro *listaPerros,int lenChar,int lenPerros,int ultimoID,float* sumaEdad);
/**
 * @fn int buscarPerroID(sPerro*, int, int)
 * @brief Busca perros por ID y devuelve su posicion en el array
 *
 * @param lista Lista de perros
 * @param idRecibido ID recibido para su busqueda
 * @param max Cantidad maxima de perros que se pueden registrar
 * @return Devuelve la posicion en el array del perro registrado
 */
int buscarPerroID(sPerro* lista,int idRecibido,int max);
/**
 * @fn int detectarPerroConMasEstadias(sPerro*, int)
 * @brief Detecta cual perro tiene mas estadias y retorna su posicion en el array
 *
 * @param lista Lista de perros
 * @param max Cantidad maxima de perros que se pueden registrar
 * @return Retorna la posicion del perro con mas estadias
 */
int detectarPerroConMasEstadias (sPerro* lista,int max);
/**
 * @fn void printUnPerro(sPerro*, int)
 * @brief Imprime un solo perro
 *
 * @param lista Lista de perros
 * @param i Posicion del perro a imprimir
 */
void printUnPerro (sPerro* lista,int i);
/**
 * @fn void listarPerros(sPerro*, int)
 * @brief Imprime todos los perros cargados
 *
 * @param lista Lista de perros
 * @param max Cantidad maxima de perros que se pueden registrar
 */
void listarPerros(sPerro* lista,int max);

#endif /* ARRAY_H_ */
