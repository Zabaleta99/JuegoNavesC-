#include "Usuario.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int Usuario::MAX = 50;


Usuario::~Usuario()
{
	delete [] nickname;
	delete [] contrasenya;
	delete [] puntuaciones;
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

int Usuario::getObjects() const
{
	return this->objects;
}
void Usuario::setObjects(Objects objects)
{
	this->objects = objects;
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
		}

		else
		{
			fprintf(file, "%s;%s;%0.2f;%0.2f\n", usuarios[i].nickname, usuarios[i].contrasenya, usuarios[i].puntuaciones[0], usuarios[i].puntuaciones[1]);
		}
	}
	fclose(file);
	delete file;
}
