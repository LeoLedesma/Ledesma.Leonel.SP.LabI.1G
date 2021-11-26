#include <time.h>
#include <ctype.h>
#include "movie.h"
#include "entradas.h"




eMovie* movie_new(){
	eMovie* nuevaMovie = (eMovie*) malloc(sizeof(eMovie));

	if ( nuevaMovie != NULL ){
		nuevaMovie->id = 0;
		strcpy(nuevaMovie->titulo, " ");
		strcpy(nuevaMovie->genero, " ");
		nuevaMovie->rating = 0.0;
	}

	return nuevaMovie;
}


eMovie* movie_newParametros(char* idStr,char* tituloStr,char* generoStr, char* ratingStr){
	eMovie* nuevaMovie = movie_new();

	if (nuevaMovie != NULL && idStr != NULL && tituloStr != NULL && generoStr != NULL
			&& ratingStr != NULL){

		movie_setId(nuevaMovie, atoi(idStr));
		movie_setTitulo(nuevaMovie, tituloStr);
		movie_setGenero(nuevaMovie, generoStr);
		movie_setRating(nuevaMovie, atof(ratingStr));
	}

	return nuevaMovie;
}


int movie_delete(eMovie* this){
	int todoOk = 0;

	if (this != NULL){
		free(this);
		todoOk = 1;
	}

	return todoOk;
}

//--------------setters
int movie_setId(eMovie* this,int id){
	int todoOk = 0;

	if (this != NULL && id > 0){
		this->id = id;
		todoOk = 1;
	}

	return todoOk;
}

int movie_setTitulo(eMovie* this,char* titulo){
	int todoOk = 0;

	if (this != NULL && titulo != NULL){
		strcpy(this->titulo, titulo);
		todoOk = 1;
	}

	return todoOk;
}

int movie_setGenero(eMovie* this,char* genero){
	int todoOk = 0;

	if (this != NULL && genero != NULL){
		strcpy(this->genero, genero);
		todoOk = 1;
	}

	return todoOk;
}

int movie_setRating(eMovie* this, float rating)
{
	int todoOk = 0;

	if (this != NULL && rating >= 0){
		this->rating = rating;

		todoOk = 1;
	}

	return todoOk;
}

//-----------getters
int movie_getId(eMovie* this,int* id){
	int todoOk = 0;

	if (this != NULL && id != NULL){
		*id = this->id;
		todoOk = 1;
	}

	return todoOk;
}


int movie_getTitulo(eMovie* this,char* titulo){
	int todoOk = 0;

	if (this != NULL && titulo != NULL){
		strcpy(titulo, this->titulo);
		todoOk = 1;
	}

	return todoOk;
}


int movie_getGenero(eMovie* this,char* genero){
	int todoOk = 0;

	if (this != NULL && genero != NULL){
		strcpy(genero, this->genero);
		todoOk = 1;
	}

	return todoOk;
}


int movie_getRating(eMovie* this, float* rating)
{
	int todoOk = 0;

	if (this != NULL && rating >= 0){
		*rating = this->rating;
		todoOk = 1;
	}

	return todoOk;
}




//------asignaciones aleatorias

void* movie_asignarRatingAleatorio(void* unaMovie)
{

	int ratingMax = 10;
	int ratingMin = 1;

	if(unaMovie!=NULL)
	{

		movie_setRating(unaMovie, floatAleatorioUnDecimal(ratingMin, ratingMax));
	}

	return unaMovie;
}


void* movie_asignarGeneroAleatorio(void* unaMovie)
{

	int idMax = 4;
	int idMin = 1;

	int idRecibido;
	char generoAsignado[20];

	if(unaMovie!=NULL)
	{

		idRecibido = intAleatorio(idMin, idMax);
		printf("ID RECIBIDO = %d", idRecibido);

		switch(idRecibido)
		{
		case 1:

			strcpy(generoAsignado, "Drama");
			break;
		case 2:
			strcpy(generoAsignado, "Comedia");
			break;
		case 3:
			strcpy(generoAsignado, "Accion");
			break;
		case 4:
			strcpy(generoAsignado, "Terror");
			break;
		}

		movie_setGenero(unaMovie, generoAsignado);

	}

	return unaMovie;
}


//---Filters---

int movie_filtrarAccion(void* p){
	int todoOk = 0;
	char auxGenero[20];
	eMovie* auxMovie = NULL;

	if (p != NULL){
		auxMovie = (eMovie*) p;
		movie_getGenero(auxMovie, auxGenero);

		if (strcmp(auxGenero, "Accion") == 0){
			todoOk = 1;
		}
	}

	return todoOk;
}

int movie_filtrarTerror(void* p){
	int todoOk = 0;
	char auxGenero[20];
	eMovie* auxMovie = NULL;

	if (p != NULL){
		auxMovie = (eMovie*) p;
		movie_getGenero(auxMovie, auxGenero);

		if (strcmp(auxGenero, "Terror") == 0){
			todoOk = 1;
		}
	}

	return todoOk;
}

int movie_filtrarComedia(void* p){
	int todoOk = 0;
	char auxGenero[20];
	eMovie* auxMovie = NULL;

	if (p != NULL){
		auxMovie = (eMovie*) p;
		movie_getGenero(auxMovie, auxGenero);

		if (strcmp(auxGenero, "Comedia") == 0){
			todoOk = 1;
		}
	}

	return todoOk;
}

int movie_filtrarDrama(void* p){
	int todoOk = 0;
	char auxGenero[20];
	eMovie* auxMovie = NULL;

	if (p != NULL){
		auxMovie = (eMovie*) p;
		movie_getGenero(auxMovie, auxGenero);

		if (strcmp(auxGenero, "Drama") == 0){
			todoOk = 1;
		}
	}

	return todoOk;
}


int movie_ordenarMovies(void* peliI, void* peliJ)
{
	int todoOk=-1;
	char generoI[40];
	char generoJ[40];
	float ratingI;
	float ratingJ;

	if(peliI!=NULL && peliJ!=NULL)
	{
		movie_getGenero(peliI, generoI);
		movie_getGenero(peliJ, generoJ);
		movie_getRating(peliI, &ratingI);
		movie_getRating(peliJ, &ratingJ);


		if(strcmp(generoI,generoJ)>0 || (strcmp(generoI,generoJ)==0 && ratingI<ratingJ))
		{
			todoOk=1;
		}else
		{
			todoOk=0;
		}

	}

	return todoOk;
}





