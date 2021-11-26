#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "LinkedList.h"
#include "movie.h"

int parser_MovieFromText(FILE* pFile , LinkedList* list)
{
    int todoOk = 0;

    int cant;

    char* id = (char*) malloc(sizeof(char) * 10);
    char* titulo = (char*) malloc(sizeof(char) * 40);
    char* genero = (char*) malloc(sizeof(char) * 20);
    char* rating = (char*) malloc(sizeof(char) * 10);
    eMovie* auxMovie = NULL;

    if (list != NULL){
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, titulo, genero, rating);

        while (!feof(pFile)){
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, titulo, genero, rating);

            if (cant < 4){
                break;
            }

            auxMovie = movie_newParametros(id, titulo, genero, rating);
            if (auxMovie != NULL){
                ll_add(list, auxMovie);
                todoOk = 1;
            }

        }
        fclose(pFile);

    }
    return todoOk;
}


