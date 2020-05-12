#ifndef USUARIO_H_
#define USUARIO_H_

#include <stdio.h>

class Usuario
{
	private:
		char* nickname;
		char* contrasenya;
		float* puntuaciones;
		static int MAX;

	public:
		Usuario(){}
		void setNickname (char* n) {this->nickname = n;}
		void setContrasenya (char* n) {this->contrasenya = n;}
		void setPuntuaciones (float* n) {this->puntuaciones = n;}

		char* getNickname ()const {return this->nickname;}
		char* getContrasenya ()const {return this->contrasenya;}
		float* getPuntuaciones ()const {return this->puntuaciones;}

		Usuario* leerUsuarios(FILE *file, int *size);
		void escribirUsuarios(Usuario *usuarios, int size);

		Usuario& operator=(const Usuario &a);

};

#endif
