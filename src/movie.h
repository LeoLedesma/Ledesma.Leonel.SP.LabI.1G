#ifndef MOVIE_H_
#define MOVIE_H_
#include "LinkedList.h"

typedef struct {
	int id;
	char titulo[50];
	char genero[20];
	float rating;
} eMovie;

#endif /* PELI_H_ */


eMovie* movie_new();

/// @brief Elimina una pelicula
///
/// @param this pelicula a ser eliminada
/// @return 1 si la elimino, 0 si ocurrio un error
int movie_delete(eMovie* this);

/// @brief Crea una nueva pelicula con parametros
///
/// @param idStr
/// @param tituloStr
/// @param generoStr
/// @param ratingStr
/// @return Retorna direccion de memoria de la nueva pelicula
eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr);

/// @brief Devuelve el ID de una pelicula
///
/// @param this una Pelicula
/// @param id Direccion donde se guardara el id
/// @return 1 si salio bien, 0 si hubo error
int movie_getId(eMovie* this,int* id);

/// @brief Devuelve el titulo de una pelicula
///
/// @param this una Pelicula
/// @param titulo Direccion donde se guardara el titulo
/// @return 1 si salio bien, 0 si hubo error
int movie_getTitulo(eMovie* this,char* titulo);

/// @brief Devuelve el genero de una pelicula
///
/// @param this una Pelicula
/// @param genero Direccion donde se guardara el genero
/// @return 1 si salio bien, 0 si hubo error
int movie_getGenero(eMovie* this,char* genero);

/// @brief Devuelve el genero de una pelicula
///
/// @param this
/// @param duracion
/// @return 1 si salio bien, 0 si hubo error
int movie_getRating(eMovie* this,float* duracion);

/// @brief Setea el Id a la pelicula
///
/// @param this una pelicula
/// @param id a ser seteado
/// @return 1 si salio bien, 0 si hubo error
int movie_setId(eMovie* this,int id);

/// @brief Setea el titulo a la pelicula
///
/// @param this una pelicula
/// @param titulo a ser seteado
/// @return 1 si salio bien, 0 si hubo error
int movie_setTitulo(eMovie* this,char* titulo);

/// @brief Setea el genero a la pelicula
///
/// @param this una pelicula
/// @param genero a ser seteado
/// @return 1 si salio bien, 0 si hubo error
int movie_setGenero(eMovie* this,char* genero);

/// @brief Setea el rating a la pelicula
///
/// @param this una pelicula
/// @param rating a ser seteado
/// @return 1 si salio bien, 0 si hubo error
int movie_setRating(eMovie* this,float rating);


/// @brief Asigna de manera aleatoria un rating del 1 al 10
///
/// @param unaMovie pelicula a setear
void* movie_asignarRatingAleatorio(void* unaMovie);

/// @brief Asigna de manera aleatoria un genero
///
/// @param unaMovie pelicula a setear
void* movie_asignarGeneroAleatorio(void* unaMovie);




//------filtros
int movie_filtrarTerror(void* p);
int movie_filtrarDrama(void* p);
int movie_filtrarComedia(void* p);
int movie_filtrarAccion(void* p);

int movie_ordenarMovies(void* movieI, void* movieJ);
