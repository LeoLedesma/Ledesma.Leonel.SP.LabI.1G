#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"
#include "menu.h"

int elegirOpcionMenuPrincipal(){
	int opcion;

	system("cls");
	printf("     *** MOVIES BY LEDESMA LEONEL  ***       \n");
	printf("----------------------------------------------\n");
	printf("  1. Cargar Archivo\n");
	printf("  2. Imprimir lista\n");
	printf("  3. Asignar rating\n");
	printf("  4. Asignar genero.\n");
	printf("  5. Filtrar peliculas por genero\n");
	printf("  6. Ordenar peliculas.\n");
	printf("  7. Guardar peliculas.\n");
	printf("  8. Salir\n");

	getInt("Por favor seleccione una opcion: ", "ERROR. Por favor seleccione una opcion (solo numeros): ", &opcion);

	return opcion;
}

int menuPrincipal(LinkedList* listaMovies)
{
	int todoOk = 0;
	int option;
	char salir = 'n';
	char path[40];

	int flagLoad = 0;
	int flagMapGenero = 0;
	int flagMapRating = 0;
	int flagSort = 0;
	int flagSave = 0;

	LinkedList* listaMapeada = ll_newLinkedList();
	LinkedList* listaClonada = ll_newLinkedList();


	if (listaMovies != NULL)
	{
		do
		{
			option = elegirOpcionMenuPrincipal();
			switch (option)
			{
			case 1: //cargar
				if(!flagLoad)
				{
					if(controller_loadFromText(listaMovies))
					{
						flagLoad=1;
						printf("Archivo cargado con exito!\n");
					}
				}else
				{
					printf("Los datos ya se han cargado!.\n");
				}

				break;
			case 2: //imprimir lista

				if(flagLoad)
				{
					controller_imprimirMovies(listaMovies);
				}else
				{
					printf("Primero debe cargar el archivo para mostrarlo.!\n");
				}
				break;
			case 3: //Asignar rating
				if(flagMapRating)
				{
					printf("Ya han sido cargados los ratings con anterioridad.!\n");
				}else
				{
					if(flagLoad)
					{
						listaMapeada = controller_asignarRatings(listaMovies);

						if(listaMapeada!=NULL)
						{
							printf("Ratings asignados con exito!!\n\n");

							controller_imprimirMovies(listaMovies);
							flagMapRating = 1;
						}
					}else
					{
						printf("Primero debe cargar la lista!\n");
					}
				}

				break;
			case 4: //Asignar genero
				if(flagMapGenero)
				{
					printf("Primero debe cargar el archivo para mostrarlo.!\n");
				}else
				{
					if(flagLoad)
					{
						listaMapeada = controller_asignarGeneros(listaMovies);

						if(listaMapeada!=NULL)
						{
							printf("Generos asignados con exito!!\n\n");

							controller_imprimirMovies(listaMovies);
							flagMapGenero = 1;
						}
					}else
					{
						printf("Primero debe cargar la lista!\n");
					}
				}


				break;

			case 5: //filtra por genero

				if(flagMapGenero && flagMapRating)
				{
					controller_filtrarPorGenero(listaMovies);
				}else
				{
					printf("Primero debe cargar los ratings en la lista!\n");
				}

				break;
			case 6: //ordenar por genero y rating descendente

				if(flagMapGenero && flagMapRating)
				{
					listaClonada = controller_ordenar(listaMapeada);

					if(listaClonada!=NULL)
					{
						flagSort = 1;
					}

				}else
				{
					printf("Primero debe cargar los ratings en la lista!\n");
				}

				break;
			case 7: //guardar peliculas
				if(flagSort)
				{
					utn_getString(path, 30, "Por favor, ingrese el nombre con el que desea guardar el archivo: ", "ERROR. Por favor, ingrese el nombre con el que desea guardar el archivo: ", 9);
					strcat(path, ".csv");
					controller_saveAsText(path, listaClonada);
					flagSave = 1;
				}

				break;

			case 8: //salir
				system("cls");
				if(flagSave)
					printf("ALERTA!!!   ALERTA!!!   ALERTA!!!\n");
				printf("Esta queriendo salir sin guardar los cambios. \n");


				salir = getConfirmation("Esta seguro que desea salir? (s/n): ",
						"ERROR. Esta seguro que desea salir? (s/n): ");

				break;
			default:
				printf("Ingreso una opcion invalida. Vuelva a intentarlo.\n");
				break;
			}

			printf("Presione una tecla para continuar...\n");
			fflush(stdin);
			getchar();
			//system("pause"); //Rompe el pedido de opcion en consola de eclipse.
		} while (salir == 'n');

		todoOk=1;
	}

	ll_deleteLinkedList(listaMapeada);

	return todoOk;
}

int menuGeneros(){
	int opcion;

	system("cls");
	printf("---------------------------------------\n");
	printf("      Generos existentes        \n");
	printf("---------------------------------------\n");
	printf("1. Drama\n");
	printf("2. Comedia\n");
	printf("3. Accion\n");
	printf("4. Terror\n");

	getInt("Por favor ingrese el ID del genero que desea: ", "Por favor ingrese el ID del genero que desea: ", &opcion);

	return opcion;
}


