#ifndef PARSER_H_
#define PARSER_H_


#endif /* PARSER_H_ */

#include "LinkedList.h"


/// @brief Parsea los datos los datos de las peliculas desde el archivo que ingrese el usuario (modo texto).
///
/// @param pFile Archivo
/// @param list Lista de peliculas
/// @return Retorna (1) si logro cargar al menos un empleado, (0) si no.
int parser_MovieFromText(FILE* pFile , LinkedList* list);
