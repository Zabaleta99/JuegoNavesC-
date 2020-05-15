#ifndef USUARIO_H_
#define USUARIO_H_

#include <stdio.h>

class Usuario
{
	private:
		char* nickname;
		char* contrasenya;
		float* puntuaciones;
		int* objects;
		static int MAX;

	public:
		Usuario();
		~Usuario();
		void setNickname (char* n);
		void setContrasenya (char* n);
		void setPuntuaciones (float* n);

		char* getNickname ()const {return this->nickname;}
		char* getContrasenya ()const {return this->contrasenya;}
		float* getPuntuaciones ()const {return this->puntuaciones;}

		void setPuntuacionClasico (float f);
		void setPuntuacionSupervivencia (float f);

		int* getObjects() const;
		void setObjects();

		Usuario* leerUsuarios(FILE *file, int *size);
		void escribirUsuarios(Usuario *usuarios, int size);

		Usuario& operator=(const Usuario &a);

};

#endif
