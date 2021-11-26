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


int movie_delete(eMovie* this);


eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr);


int movie_getId(eMovie* this,int* id);

int movie_getTitulo(eMovie* this,char* titulo);

int movie_getGenero(eMovie* this,char* genero);

int movie_getRating(eMovie* this,float* duracion);

int movie_setId(eMovie* this,int id);

int movie_setTitulo(eMovie* this,char* titulo);

int movie_setGenero(eMovie* this,char* genero);

int movie_setRating(eMovie* this,float rating);



void* movie_asignarRatingAleatorio(void* unaMovie);

void* movie_asignarGeneroAleatorio(void* unaMovie);


int movie_pedirGenero(LinkedList* lista, char generoSeleccionado[]);

int movie_filtrarTerror(void* p);
int movie_filtrarDrama(void* p);
int movie_filtrarComedia(void* p);
int movie_filtrarAccion(void* p);

int movie_ordenarMovies(void* movieI, void* movieJ);
