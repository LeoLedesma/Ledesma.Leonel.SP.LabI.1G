#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "entradas.h"
#include "parser.h"
#include "menu.h"
#include "movie.h"


int controller_loadFromText(LinkedList* listaMovies)
{

    int todoOk = 0;

    char path[20];


    utn_getString(path, 20, "Por favor, ingrese el nombre del archivo (sin extension): ", "ERROR. ingrese un nombre valido: ", 10);
    strcat(path, ".csv");

    FILE* fPath = fopen(path, "r");

    if (fPath != NULL && listaMovies!=NULL)
    {
        parser_MovieFromText(fPath, listaMovies);
        fclose(fPath);
        fPath = NULL;
        todoOk = 1;

    } else {
       printf("El archivo no se pudo abrir o no existe\n");
       todoOk = 0;
    }

    return todoOk;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayPelis)
{
	int todoOk = 0;
	int cant;



	FILE *fPath = fopen(path, "w");
	eMovie *auxMovie = NULL;

	if (pArrayPelis != NULL && fPath != NULL)
	{
		fprintf(fPath, "id_peli,titulo,genero,duracion\n");

		cant = ll_len(pArrayPelis);
		for (int i = 0; i < cant; i++)
		{
			auxMovie = (eMovie*) ll_get(pArrayPelis, i);

			if (auxMovie != NULL)
			{

				fprintf(fPath, "%d,%s,%s,%.1f\n", auxMovie->id,
						auxMovie->titulo, auxMovie->genero,
						auxMovie->rating);
			}
		}
		todoOk = 1;
		printf("Archivo guardado con exito!\n");
		fclose(fPath);
		auxMovie = NULL;
	}
	else
	{
		printf("Ocurrio un error al guardar el archivo!\n");
	}

	return todoOk;
}

//imprimir uno
void controller_imprimirUnaMovie(eMovie* unaMovie)
{


	int id;
	char titulo[40];
	char genero[20];
	float rating;

	if (unaMovie != NULL && movie_getId(unaMovie, &id)
					&& movie_getTitulo(unaMovie, titulo)
					&& movie_getGenero(unaMovie, genero)
					&& movie_getRating(unaMovie, &rating))
	{

		printf("%-4d      %-30s      %-15s        %.1f  \n", id, titulo,genero, rating);


	}


}


int controller_imprimirMovies(LinkedList* lista){
	int todoOk = 0;
	int tam;

	if (lista != NULL) {
		system("cls");
		printf("                        *** Listado de Pelis ***\n");
		printf("---------------------------------------------------------------------------\n");
		printf("Id        Titulo                             Genero                 Rating\n");
		printf("----------------------------------------------------------------------------\n");

		tam = ll_len(lista);

		for (int i = 0; i < tam ; i++) {
			controller_imprimirUnaMovie((eMovie*) ll_get(lista, i));
		}
		todoOk = 1;
	}

	return todoOk;
}

LinkedList* controller_asignarRatings(LinkedList* lista)
{
	LinkedList* pListaMapeada = NULL;
		void* (*funcion)(void*);

		if(lista!=NULL)
		{
			funcion = movie_asignarRatingAleatorio;
			pListaMapeada = ll_map(lista, funcion);

		}


	return pListaMapeada;
}

LinkedList* controller_asignarGeneros(LinkedList* lista)
{
	LinkedList* pListaMapeada = NULL;
			void* (*funcion)(void*);

			if(lista!=NULL)
			{
				funcion = movie_asignarGeneroAleatorio;
				pListaMapeada = ll_map(lista, funcion);

			}


		return pListaMapeada;
	}



LinkedList* controller_filtrarPorTipo(LinkedList* lista)
{
	LinkedList* pListaFiltrada = NULL;
	char generoSeleccionado[40];

	movie_pedirGenero(lista, generoSeleccionado);

	return pListaFiltrada;
}

int controller_filtrarPorGenero(LinkedList* lista)
{
    int todoOk = 0;
    int (*pFiltrarGenero)(void*);
    char path[30];


    LinkedList* newList = NULL;

    int idGenero;
    int flag = 0;

    if (lista != NULL)
    {


        //pido genero
        idGenero = menuGeneros();

        switch (idGenero) {
        case 1://drama
            pFiltrarGenero = movie_filtrarDrama;
            flag = 1;
            break;

        case 2://comedia
            pFiltrarGenero = movie_filtrarComedia;
            flag = 1;
            break;

        case 3://accion
            pFiltrarGenero = movie_filtrarAccion;
            flag = 1;
            break;

        case 4://terror
            pFiltrarGenero = movie_filtrarTerror;
            flag = 1;
            break;
        default://invalido
        	printf("Ingreso una opcion invalida. Vuelva a intentarlo.\n");
            break;
        }

    }

    //filtro
    if (flag){

        newList = ll_filter(lista, pFiltrarGenero);
        printf("llegue");

        if(newList!=NULL)
        {
        	if(ll_len(newList)>0)
        	{

        	controller_imprimirMovies(newList);

        	utn_getString(path, 30, "Por favor, ingrese el nombre con el que desea guardar el archivo: ", "ERROR. Por favor, ingrese el nombre con el que desea guardar el archivo: ", 9);
        	strcat(path, ".csv");
        	controller_saveAsText(path, newList);

        	}
        	else{
        		printf("No hay peliculas del genero seleccionado.\n");
        	}

        }
        else
        {
        	printf("Ocurrio un error. Por favor intente nuevamente.\n");
        }



        todoOk = 1;
    }



    return todoOk;
}

LinkedList* controller_ordenar(LinkedList* lista)
{
	LinkedList* listaOrdenada = NULL;

	int (*pOrdenarMovies)(void*, void*);


	if(lista!=NULL)
	{
		listaOrdenada = ll_clone(lista);


		if(lista!=NULL)
				{

					pOrdenarMovies = movie_ordenarMovies;
					ll_sort(listaOrdenada, pOrdenarMovies, 1);

					controller_imprimirMovies(listaOrdenada);

				}

	}

	return listaOrdenada;
}




/*LinkedList* controller_clonarLista(LinkedList* lista)
{
	LinkedList* listaClonada = ll_newLinkedList();
	ePeli* auxPeli = (ePeli*) malloc(sizeof(ePeli));
	ePeli* unaPeli=NULL;

	auxPeli = NULL;

	int id;
	char titulo[40];
	char genero[20];
	int duracion;
	int tam;



	if(auxPeli!=NULL && listaClonada!=NULL && lista!=NULL)
	{
		tam=ll_len(lista);

		for(int i=0; i<tam; i++)
		{
			unaPeli = ll_get(lista, i);

			unaPeli = (ePeli*) unaPeli;

			movie_getId(unaPeli, &id);
			movie_getTitulo(unaPeli, titulo);
			movie_getGenero(unaPeli, genero);
			movie_getDuracion(unaPeli, &duracion);

			movie_setId(auxPeli, id);
			movie_setTitulo(auxPeli, titulo);
			movie_setGenero(auxPeli, genero);
			movie_setDuracion(auxPeli, duracion);

			ll_add(listaClonada, auxPeli);
		}

	}

	return listaClonada;
}*/



