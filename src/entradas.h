#ifndef ENTRADAS_H_
#define ENTRADAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TRUE 1
#define FALSE 0



//--------------PEDIDO DE DATOS------------------


/// \brief Pide al usuario la entrada de una cadena de texto, exclusiva de caracteres alfabeticos.
///  Mostrando mensaje de error si se ingreso algo diferente a letras.
///
/// \param mensaje Mensaje de pedido de ingreso.
/// \param mensajeError Mensaje de error de pedido.
/// \param entrada Puntero a la direccion donde se requiere guardar la entrada.
/// \param tam tamanio maximo de la entrada.
/// \return retorna (-1) si hubo un error o (0) si esta ok.
int getString(char mensaje[], char mensajeError[], char entrada[], int tam);


/// \brief Pide al usuario la entrada de un numero con punto flotante, validando que se ingrese correctamente.
///
/// \param mensaje Mensaje de pedido de ingreso.
/// \param mensajeError Mensaje de error de ingreso.
/// \param entrada Puntero a la direccion donde se requiere guardar la entrada.
/// \return Retorna (-1) si hubo un error o (0) si esta ok.
int getFloat(char mensaje[], char mensajeError[], float* pEntrada );


/// \brief Pide al usuario la entrada de un numero entero, validando que se ingrese correctamente.
///
/// \param mensaje Mensaje de pedido de ingreso.
/// \param mensajeError Mensaje de error de ingreso.
/// \param entrada Puntero a la direccion donde se requiere guardar la entrada.
/// \return Retorna (-1) si hubo un error o (0) si esta ok.
int getInt(char mensaje[], char mensajeError[], int* pEntrada);

/// \fn int getNumeroLimite(int*, char*, char*, int, int, int)
/// \brief
///
/// \param pResultado
/// \param mensaje
/// \param mensajeError
/// \param minimo
/// \param maximo
/// \param reintentos
/// \return
int getNumeroLimite(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


/// \brief Pide al usuario la entrada de un caracter de confirmacion( s=si, y=yes, n=no), admitiendo el ingreso de mayusculas o minisculas.
///
/// \param mensaje Mensaje de pedido de ingreso.
/// \param mensajeError Mensaje de error de ingreso.
/// \return Retorna la opcion que haya ingresado correctamente el usuario.
char getConfirmation (char mensaje[], char mensajeError[]);


/// \brief
///
/// \param pResultado variable donde se va a guardar el caracter ingresado
/// \param mensaje mensaje
/// \param mensajeError mensaje de error
/// \param minimo posicion minima del caracter segun el codigo ASCII
/// \param maximo posicion maxima del caracter segun el codigo ASCII
/// \param reintentos cantidad de veces que puede poner el caracter
/// \return 1 si guarda el caracter, 0 si falla
int utn_getCaracter(char* pResultado, char mensaje[], char mensajeError[], char minimo, char maximo, int reintentos);

/// \fn int getInt2(int*)
/// \brief
///
/// \param pResultado
/// \return
int getInt2(int* pResultado);

/// \fn int myGets(char*, int)
/// \brief
///
/// \param cadena
/// \param longitud
/// \return
int myGets(char* cadena, int longitud);


//------------------VALIDACIONES-------------------


/// \brief Valida si string es un string sin numeros.
///
/// \param string Cadena a validar
/// \return Retorna (0) si no es string sin numeros, (1) si es string sin numeros.
int isString (char string[]);

/// \brief Valida si entrada es un numero con punto flotante valido.
///
/// \param entrada Cadena a validar
/// \return Retorna (0) si no es string sin numeros, (1) si es string sin numeros.
int isFloat(char entrada[]);

/// \brief Valida si entrada es un numero entero valido.
///
/// \param entrada Cadena a validar.
/// \return
int isInt(char entrada[]);


/// \fn int esNumerico(char*, int)
/// \brief
///
/// \param cadena
/// \param limite
/// \return
int esNumerico(char* cadena, int limite);

//-----------------MODIFICACION DE ENTRADAS

/// \brief Deja o cambia todas la primer letra de cada palabras de string a mayusculas.
///
/// \param string Cadena a modificar
/// \param len Largo de cadena a modificar.
/// \return Retorna (0) si hubo un error, (1) si salio ok.
int toUpperFirstLetterPhrase(char string [], int len);

int getStringB(char *pResultado, int tam);

int esString(char *input, int tam);

int utn_getString(char *pResultado, int tam, char mensaje[], char mensajeError[], int reintentos);

float floatAleatorioUnDecimal(int numMin, int numMax);

int intAleatorio(int numMin, int numMax);


#endif /* ENTRADAS_H_ */


