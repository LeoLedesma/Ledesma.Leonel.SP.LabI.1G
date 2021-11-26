
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "movie.h"



#endif /* CONTROLLER_H_ */


/** \brief Carga los datos de las peliculas desde el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo
 * \param list LinkedList* lista que va a ser cargada
 * \return int Retorna (0) si ocurrio un error al abrir el archivo, (1) si cargo exitosamente y (2) si hubo problema al cargar peliculas.
 *
 */
int controller_loadFromText(LinkedList* list);


/** \brief Guarda los datos de las peliculas  en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayPelis);


/** \brief Muestra una pelicula
 *
 * \param unaMovie eMovie*
 *
 */
void controller_imprimirUnaMovie(eMovie* unaMovie);


/** \brief Listar peliculas
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1) si la lista no era NULL y (0) si era NULL
 *
 */
int controller_imprimirMovies(LinkedList* lista);

/// @brief Asigna ratings aleatorios a la lista
///
/// @param lista
/// @return Retorna la lista con los datos cargados
LinkedList* controller_asignarRatings(LinkedList* lista);

/// @brief Asigna generos aleatorios a la lista
///
/// @param lista
/// @return Retorna la lista con los datos cargados
LinkedList* controller_asignarGeneros(LinkedList* lista);


/// @brief Filtra las peliculas por el tipo que el usuario seleccione
///
/// @param lista
/// @return Retorna una nueva lista con los datos cargados.
int controller_filtrarPorGenero(LinkedList* lista);

/// @brief Ordena por genero y dentro de las del mismo género que aparezcan ordenadas por rating descendente.
///
/// @param lista
/// @return
LinkedList* controller_ordenar(LinkedList* lista);
