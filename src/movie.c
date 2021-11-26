#include <time.h>
#include <ctype.h>
#include "movie.h"
#include "entradas.h"



//----New---
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

//----New Parametros---
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

//----Delete---
int movie_delete(eMovie* this){
    int todoOk = 0;

    if (this != NULL){
        free(this);
        todoOk = 1;
    }

    return todoOk;
}

//----Setters---
//id
int movie_setId(eMovie* this,int id){
    int todoOk = 0;

    if (this != NULL && id > 0){
        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
//titulo
int movie_setTitulo(eMovie* this,char* titulo){
    int todoOk = 0;

    if (this != NULL && titulo != NULL){
        strcpy(this->titulo, titulo);
        todoOk = 1;
    }

    return todoOk;
}
//genero
int movie_setGenero(eMovie* this,char* genero){
    int todoOk = 0;

    if (this != NULL && genero != NULL){
        strcpy(this->genero, genero);
        todoOk = 1;
    }

    return todoOk;
}
//duracion
int movie_setRating(eMovie* this, float rating)
{
    int todoOk = 0;

    if (this != NULL && rating >= 0){
        this->rating = rating;

        todoOk = 1;
    }

    return todoOk;
}

//----Getters---
//id
int movie_getId(eMovie* this,int* id){
    int todoOk = 0;

    if (this != NULL && id != NULL){
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}

//titulo
int movie_getTitulo(eMovie* this,char* titulo){
    int todoOk = 0;

    if (this != NULL && titulo != NULL){
        strcpy(titulo, this->titulo);
        todoOk = 1;
    }

    return todoOk;
}

//genero
int movie_getGenero(eMovie* this,char* genero){
    int todoOk = 0;

    if (this != NULL && genero != NULL){
        strcpy(genero, this->genero);
        todoOk = 1;
    }

    return todoOk;
}

//duracion
int movie_getRating(eMovie* this, float* rating)
{
    int todoOk = 0;

    if (this != NULL && rating >= 0){
        *rating = this->rating;
        todoOk = 1;
    }

    return todoOk;
}

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

int movie_pedirGenero(LinkedList* lista, char generoSeleccionado[])
{
	int todoOk=1;
	char generos [100][40];
	char auxGenero[40];
	int option;
	int maxGeneros;

	eMovie* auxMovie = NULL;
	int tam;
	tam = ll_len(lista);
	int flag = 0;


	if(lista!=NULL)
	{
		for(int i = 0; i<100;i++)
		{
			strcpy(generos[i], " ");
		}

		for(int i = 0; i<tam; i++) //recorro lista pelis
		{
			//tengo un genero
			flag=0;
			auxMovie = ll_get(lista, i);
			movie_getGenero(auxMovie, auxGenero);

			//tengo que compararlo con la lista.
			for(int j = 0; j<100; j++) //recorro lista generos
			{
				if(strcmp(auxGenero, generos[j])==0) //si exite entro
				{
					flag = 1;
					break;
				}
			}

			if(!flag)
			{
				//busco espacio genero libre.
				for(int j=0; j<100; j++)
				{
					if(strcmp(generos[j], " ")==0)
					{
						strcpy(generos[j], auxGenero);
						break;
					}
				}



			}



		}

		printf("   *** lista de generos ***\n");
			printf("--------------------------------\n");
			printf(" ID   Genero ***\n");
			for(int i = 0; i<100;i++)
			{
				if(strcmp(generos[i], " ")!=0)
				{
					printf("  %d. %s\n", i+1, generos[i]);
					maxGeneros=i;
				}
			}


			getInt("Por favor, ingrese el ID del genero: ", "ERROR. Por favor, ingrese el ID del genero (Solo numeros): " , &option);

			while((option-1)>maxGeneros)
			{
				getInt("ERROR ID INCORRECTO. Por favor, ingrese el ID del genero: ", "ERROR. Por favor, ingrese el ID del genero (Solo numeros): " , &option);
			}

			strcpy(generoSeleccionado, generos[option-1]);

			todoOk=1;

	}

	return todoOk;
}

//filtrar genero


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





