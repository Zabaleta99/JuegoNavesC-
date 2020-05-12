#ifndef MENUREGISTRARSE_H_
#define MENUREGISTRARSE_H_

#include "Menu.h"
#include "Usuario.h"

class MenuRegistrarse : public Menu
{
	MenuRegistrarse(){}
	void menuRegistrarse (Usuario *usuarios, int size);
	virtual void desplegarMenu();
	void liberarMemoriaMenuRegistrarse(WINDOW* registro, Usuario* usuariosActualizados, int size, char* userIntroduced, char* passIntroduced, char* passConfiIntroduced);

};
#endif