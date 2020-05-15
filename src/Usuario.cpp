#include "Usuario.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int Usuario::MAX = 50;

Usuario::Usuario()
{
	this->objects = new int[1];
	this->objects[0] = -1;
}
Usuario::~Usuario()
{
	delete [] nickname;
	delete [] contrasenya;
	delete [] puntuaciones;
	delete[] objects;
}
void Usuario::setNickname (char* n) 
{
	this->nickname = new char[strlen(n)+1];
	strcpy(this->nickname, n);
}
void Usuario::setContrasenya (char* n) 
{
	this->contrasenya = new char[strlen(n)+1];
	strcpy(this->contrasenya, n);
}
void Usuario::setPuntuaciones (float* n) 
{
	this->puntuaciones = new float [2];
	this->puntuaciones[0] = n[0];
	this->puntuaciones[1] = n[1];
}

void Usuario::setPuntuacionClasico (float f)
{
	this->puntuaciones[0] = f;
}

void Usuario::setPuntuacionSupervivencia (float f)
{
	this->puntuaciones[1] = f;
}

int* Usuario::getObjects() const
{
	return this->objects;
}
void Usuario::setObjects()
{
	delete[] this->objects;
	this->objects = new int[432];
}

Usuario& Usuario::operator=(const Usuario &a)
{
	this->nickname = new char[strlen(a.nickname)+1];
	strcpy(this->nickname, a.nickname);

    this->contrasenya = new char[strlen(a.contrasenya)+1];
	strcpy(this->contrasenya, a.contrasenya);

    this->puntuaciones = new float [2];
    this->puntuaciones[0] = a.puntuaciones[0];
    this->puntuaciones[1] = a.puntuaciones[1];

    return *this;
}

Usuario* Usuario::leerUsuarios(FILE *file, int *size)
{
	char* linea = new char[MAX];
	char** items = new char*[4];

	fgets(linea, MAX, file);
	sscanf(linea, "%d", size);

	Usuario* usuarios = new Usuario [*size];

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

		usuarios[contador].puntuaciones = new float [2];
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

			int* objects = usuarios[i].getObjects();
			cout << objects[0];
			if(objects[0] != -1)
			{
				fprintf(file, ";1\n%d;%d;%d", objects[0], objects[1], objects[2]);

				if(objects[2] > 0)
				{
					for(int i=0; i<objects[2]; i++)
					{
						fprintf(file, ";%d", objects[i+3]);
					}
				}

				fprintf(file, ";%d", objects[3+objects[2]]);

				if(objects[3+objects[2]] > 0)
				{
					for(int i=0; i<objects[3+objects[2]]; i++)
					{
						fprintf(file, ";%d", objects[i+4+objects[2]]);
					}
				}
			}
			else
				fprintf(file, ";0");
		}

		else
		{
			fprintf(file, "%s;%s;%0.2f;%0.2f", usuarios[i].nickname, usuarios[i].contrasenya, usuarios[i].puntuaciones[0], usuarios[i].puntuaciones[1]);

			int* objects = usuarios[i].getObjects();

			if(objects[0] != -1)
			{
				fprintf(file, ";1\n%d;%d;%d", objects[0], objects[1], objects[2]);

				if(objects[2] > 0)
				{
					for(int i=0; i<objects[2]; i++)
					{
						fprintf(file, ";%d", objects[i+3]);
					}
				}

				fprintf(file, ";%d", objects[3+objects[2]]);

				if(objects[3+objects[2]] > 0)
				{
					for(int i=0; i<objects[3+objects[2]]; i++)
					{
						fprintf(file, ";%d", objects[i+4+objects[2]]);
					}
				}
			}
			else
				fprintf(file, ";0");

			fprintf(file, "\n");
		}
	}

	fclose(file);
	delete file;
}
