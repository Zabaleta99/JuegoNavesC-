#ifndef MENUMAIN_H_
#define MENUMAIN_H_

#include "Menu.h"
#include "Usuario.h"
#include "MenuInicio.h"
#include "MenuIniciarSesion.h"
#include "MenuRegistrarse.h"
#include "MenuPlayer.h"

class MenuMain : public Menu
{
	public:
		MenuMain();
		void liberarMemoriaMenuMain (int *size, Usuario* arrayUsers);
		virtual void desplegarMenu();
		
};

#endif