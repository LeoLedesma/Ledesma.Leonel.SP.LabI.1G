#ifndef MENU_H_
#define MENU_H_

#include "entradas.h"
#include "LinkedList.h"
#include "controller.h"

#endif /* MENU_H_ */

/// @brief Pide al usuario que ingrese una opcion que sera utilizada en el menu principal
///
/// @return Retorna la opcion ingresada por el usuario.
int elegirOpcionMenuPrincipal();

/// @brief Menu donde se ejecutan todas las funciones que requiere el programa
///
/// @param listaPelis Lista de peliculas a cargar
/// @return retorna (1) si lista no es NULL y 0 si es NULL
int menuPrincipal(LinkedList* listaPelis);

/// @brief Le pide al usuario que ingrese una opcion que sera utilizada al filtrar por genero.
///
/// @return Retorna la opcion ingresada por el usuario.
int menuGeneros();
