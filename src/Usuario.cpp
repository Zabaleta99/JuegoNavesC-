#include "Usuario.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int Usuario::MAX = 50;

Usuario* Usuario::leerUsuarios(FILE *file, int *size)
{
	char* linea = new char[MAX];
	char** items = new char*[4];
	/*char* linea = malloc(MAX * sizeof(char));
	char** items = malloc(4 * sizeof(char*));*/

	fgets(linea, MAX, file);
	sscanf(linea, "%d", size);

	Usuario* usuarios = new Usuario [*size];
	//Usuario *usuarios = (Usuario*) malloc(*size * sizeof(Usuario));

	int contador = 0;
	while(fgets(linea, MAX, file))
	{
		char* token = strtok(linea, ";");
		int i=0;
		while(token != NULL)
		{
			items[i] = token;
			token = strtok(NULL, ";");
			i++;
		}

		usuarios[contador].nickname = new char [strlen(items[0])+1];
		strcpy(usuarios[contador].nickname, items[0]);

		usuarios[contador].contrasenya = new char [strlen(items[1])+1];
		strcpy(usuarios[contador].contrasenya, items[1]);

		/*usuarios[contador].nickname = malloc((strlen(items[0])+1) * sizeof(char));
		strcpy(usuarios[contador].nickname, items[0]);
		usuarios[contador].contrasenya = malloc((strlen(items[1])+1) * sizeof(char));
		strcpy(usuarios[contador].contrasenya, items[1]);*/

		usuarios[contador].puntuaciones = new float [2];

		/*usuarios[contador].puntuaciones = malloc(2 * sizeof(float));*/

		usuarios[contador].puntuaciones[0] = strtof(items[2], NULL);
		usuarios[contador].puntuaciones[1] = strtof(items[3], NULL);
		contador++;
	}
	delete [] linea;
	for(int i=0; i<4; i++)
    {
    	delete[] items[i];
    }
	delete [] items;
	/*free(linea);
	linea = NULL;
	free(items);
	items = NULL;*/
	return usuarios;
}

void Usuario::escribirUsuarios(Usuario *usuarios, int size)
{
	FILE *file = fopen("Usuarios.txt", "w");
	if (file == NULL)
	{
		cout <<"Error al abrir el fichero Usuarios.txt\n";
		exit(-1);
	}

	fprintf(file, "%d\n", size);

	for (int i=0; i<size; i++)
	{
		if (i == size-1)
		{
			fprintf(file, "%s;%s;%0.2f;%0.2f", usuarios[i].nickname, usuarios[i].contrasenya, usuarios[i].puntuaciones[0], usuarios[i].puntuaciones[1]);
		}

		else
		{
			fprintf(file, "%s;%s;%0.2f;%0.2f\n", usuarios[i].nickname, usuarios[i].contrasenya, usuarios[i].puntuaciones[0], usuarios[i].puntuaciones[1]);
		}
	}
	fclose(file);
	delete file;
	//free(file);
	//file = NULL;
}
