#include "entradas.h"


//----------------ENTRADA DE DATOS---------------

int getString(char mensaje[], char mensajeError[], char entrada[], int tam)
{
    int todoOk = -1;
    char auxString[200];

    if(mensaje!=NULL && mensajeError!=NULL && entrada!=NULL && tam>0)
    {
        printf("%s", mensaje);
        fflush (stdin);
        gets(auxString);

        while(strlen(auxString)>tam-1 || !isString(auxString))
        {
            printf("%s", mensajeError);
            fflush (stdin);
            gets(auxString);
        }

        strcpy(entrada, auxString);
        todoOk=0;
    }

    return todoOk;
}

int getPath(char mensaje[], char mensajeError[], char entrada[], int tam)
{
    int todoOk = -1;
    char auxString[200];

    if(mensaje!=NULL && mensajeError!=NULL && entrada!=NULL && tam>0)
    {
        printf("%s", mensaje);
        fflush (stdin);
        gets(auxString);

        while(strlen(auxString)>tam-1 || !isString(auxString))
        {
            printf("%s", mensajeError);
            fflush (stdin);
            gets(auxString);
        }

        strcpy(entrada, auxString);
        todoOk=0;
    }

    return todoOk;
}


int getFloat(char mensaje[], char mensajeError[], float* pEntrada )
{
    int todoOk = -1;
    char auxString[100];

    if(mensaje!=NULL && mensajeError!=NULL && pEntrada!=NULL)
    {
        printf("%s", mensaje);
        fflush (stdin);
        gets(auxString);

        while(!isFloat(auxString))
        {
            printf("%s", mensajeError);
            fflush (stdin);
            gets(auxString);
        }

        *pEntrada = atof(auxString);

        todoOk=0;
    }
    return todoOk;
}

int getInt(char mensaje[], char mensajeError[], int* pEntrada)
{
    int todoOk = 0;
    char auxString[100];

    fflush(stdin);
    if(mensaje!=NULL && mensajeError!=NULL && pEntrada!=NULL)
    {
        printf("%s", mensaje);
        fflush (stdin);
        gets(auxString);


        while(!isInt(auxString))
        {
            printf("%s", mensajeError);
            fflush (stdin);
            gets(auxString);

        }

        *pEntrada = atoi(auxString);


        todoOk=1;

    }

    return todoOk;
}

char getConfirmation (char mensaje[], char mensajeError[])
{

    char caracterIngresado;
    char error[] = {"ERROR. Solo puedes ingresar letras. Intenta nuevamente: " };

    utn_getCaracter(&caracterIngresado, mensaje, error, 'A', 'z', 1);

    while (caracterIngresado != 's' &&  caracterIngresado != 'S' &&
            caracterIngresado != 'n' && caracterIngresado != 'N')
    {
        utn_getCaracter(&caracterIngresado, mensajeError, error, 'A', 'z', 1);
    }

    caracterIngresado=tolower(caracterIngresado);

    return caracterIngresado;
}

//-------------VALIDACIONES

int isString (char string[])
{
    int todoOk = 1;
    int stringTam = strlen(string);

    if(string!=NULL)
    {

        for(int i = 0; i<stringTam; i++)
        {
            if((!isalpha(string[i]) && string[i]!= ' '))
            {

                todoOk = 0;

                break;
            }

        }

    }

    return todoOk;
}


int isFloat(char entrada[]) //15000
{
    int todoOk = 1;
    int banderaPunto = 0;
    int stringTam = strlen(entrada);

    for(int i=0; i<stringTam ; i++)
    {
        if(entrada[i]=='.')
        {
            banderaPunto++;
        }

        if((!isdigit(entrada[i]) && entrada[i]!='.') || banderaPunto>1)
        {
            todoOk = 0;
            break;
        }

    }


    return todoOk;
}


int isInt(char entrada[])
{
    int todoOk = 1;
    int stringTam = strlen(entrada);


    if (isdigit(entrada[0]) || (entrada[0]== '-' && stringTam > 1))
    {

        for(int i = 1; i < stringTam; i++)
        {

            if (!isdigit(entrada[i]))
            {
                todoOk = 0;
                break;
            }
        }
    }
    else
    {
        todoOk = 0;
    }


    return todoOk;
}

//-------------MODIFICACIONES
int toUpperFirstLetterPhrase(char string [], int len)
{
    int todoOk=0;


    if(string!=NULL && len>0)
    {
        todoOk=1;
        strlwr(string);

        string[0]=toupper(string[0]);

        for(int i = 0; i<len; i++)
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }
        }
    }

    return todoOk;
}


int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos){
    int retorno = 0;
    char auxChar;

    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0){

        do {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &auxChar);

            if (auxChar >= minimo && auxChar <= maximo){
                *pResultado = auxChar;
                retorno = 1;
                break;

            }
            printf("%s", mensajeError);
            reintentos--;

        } while (reintentos >= 0);

    }

    return retorno;
}


int getNumeroLimite(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno=-1;
    int bufferInt;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getInt2(&bufferInt)==0 && bufferInt>=minimo && bufferInt<=maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}

 int getInt2(int* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNumerico(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atoi(bufferString);
    }
    return retorno;
}

 int myGets(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL && bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
        {
            bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
        }
        if(strnlen(bufferString,sizeof(bufferString))<= longitud)
        {
            strncpy(cadena,bufferString,longitud);
            retorno=0;
        }
    }

    return retorno;
}

 int esNumerico(char* cadena, int limite)
{
    int retorno=-1;
    int i;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        for(i=0;i<limite && cadena[i]!='\0';i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]>'9' || cadena[i]<'0')
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

 int utn_getString(char *pResultado, int tam, char mensaje[],
 		char mensajeError[], int reintentos) {
 	char bufferString[50];
 	int retorno = -1;
 	while (reintentos >= 0) {
 		reintentos--;
 		printf("%s", mensaje);
 		if (getStringB(bufferString, sizeof(bufferString)) == 0
 				&& strnlen(bufferString, sizeof(bufferString)) < tam) {
 			strncpy(pResultado, bufferString, tam);
 			retorno = 0;
 			break;
 		}
 		printf("%s", mensajeError);
 	}
 	return retorno;
 }

 int getStringB(char *pResultado, int tam) {
 	int retorno = -1;
 	char buffer[50];

 	if (pResultado != NULL) {
 		if (myGets(buffer, sizeof(buffer)) == 0
 				&& esString(buffer, sizeof(buffer)) == 0
 				&& strnlen(buffer, sizeof(buffer)) < tam) {
 			strncpy(pResultado, buffer, tam);
 			retorno = 0;
 		}
 	}
 	return retorno;
 }

 int esString(char *input, int tam) {
 	int retorno = 0;

 	if (input != NULL && tam > 0) {
 		for (int i = 0; input[i] != '\0' && i < tam; i++) {
 			if (input[i] != ' ' && input[i] != '.'
 					&& (input[i] < 'A' || input[i] > 'Z')
 					&& (input[i] < 'a' || input[i] > 'z')
 					&& (input[i] < '0' || input[i] > '9')) {
 				retorno = 1;
 				break;
 			}
 		}
 	}
 	return retorno;
 }


 float floatAleatorioUnDecimal(int numMin, int numMax)
 {
 	   float numGenerado;
 	   if(numMin<numMax)
 	   {
 		  numGenerado = (float) (rand() % (numMax*10-numMin*10+1) + numMin)/10;
 	   }

	return numGenerado;
 }

 int intAleatorio(int numMin, int numMax)
 {
 	   int numGenerado;
 	   if(numMin<numMax)
 	   {
 		  numGenerado = (rand() % (numMax-numMin+1) + numMin);
 	   }

 	    return numGenerado;
 }







