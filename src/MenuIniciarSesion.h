#ifndef MENUINICIARSESION_H_
#define MENUINICIARSESION_H_

#include "Menu.h"
#include "Usuario.h"

class MenuIniciarSesion : public Menu
{
	public:
		MenuIniciarSesion(){}
		int menuIniciarSesion(Usuario *usuarios, int size);
		virtual void desplegarMenu();
		void liberarMemoriaMenuInicioSesion(char* userIntroduced, char* passIntroduced, WINDOW* inicioSesion);
};

#endif
