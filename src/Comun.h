#ifndef _COMUN_H_
#define _COMUN_H_

#include <curses.h>

#include "NaveSupervivencia.h"

class Asteroide
{
	private:
		int x;
		int y;
		int tipo;

	public:
		//SUPERVIVENCIA
		void nuevoAsteroideVerticalS(Asteroide* asteroide);
		void nuevoAsteroideHorizontalS(Asteroide* asteroide);
		void pintarAsteroideVerticalS(WINDOW* ventana, Asteroide* asteroide);
		void pintarAsteroideHorizontalS(WINDOW* ventana, Asteroide* asteroide);
		int choqueAsteroide(WINDOW* ventana, NaveSupervivencia* nave, Asteroide* asteroide);
		void pintarAsteroidesS(WINDOW* ventana, Asteroide* asteroides, int* num_ast);
		//CLASICO
		void nuevoAsteroideHorizontalC(Asteroide* asteroide);
		void nuevoAsteroideVerticalC(Asteroide* asteroide);
		void pintarAsteroideHorizontalC(WINDOW* ventana, Asteroide* asteroide);
		void pintarAsteroideVerticalC(WINDOW* ventana, Asteroide* asteroide);
		void pintarAsteroidesC(WINDOW* ventana, Asteroide* asteroides, int* num_ast);
		void crearAsteroidesHorizontales(Asteroide* asteroides, int* num_ast);
		void crearAsteroidesVerticales(Asteroide* asteroides, int* num_ast);
};

#endif