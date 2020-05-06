#ifndef SUPERVIVENCIA_H_
#define SUPERVIVENCIA_H_

#include "Comun.h"
#include "Usuarios.h"

#include <curses.h>

class NaveSupervivencia
{
	private:
		int x;
		int y;
		int vidas;

		static int ALTO = 0;
		static int IZQUIERDA = 0;
		static int BAJO = 0;
		static int DERECHA = 0;

		static int alturaTerminal = 0;
		static int anchuraTerminal = 0;

		//los #define se convierten en static?

	public:
		void jugarSupervivencia(Usuario* usuarios, int player);
		void mostrarNivel(int* num_ast);
		void subirNivelS(Asteroide* asteroides, int* num_ast);
		void mostrarGameOverS(void);
		void pintarVidasS(NaveSupervivencia* nave);
		void actualizarS(WINDOW* ventana, NaveSupervivencia* nave);
		void pintarNaveS(WINDOW* ventana, NaveSupervivencia* nave);
		int menuSalidaS(void);
		WINDOW* mostrarInfoS(void);
		void liberarMemoriaS(NaveSupervivencia* nave, Asteroide* asteroides, int* num_ast, VidaExtra* vidasExtra, int* num_vidasExtra, WINDOW* ventana);
		void inicializarParametrosS(NaveSupervivencia* nave, Asteroide* asteroides, int* num_ast, VidaExtra* vidasExtra, int* num_vidasExtra);
		void pintarNaveChoqueS(WINDOW* ventana, NaveSupervivencia* nave);
		void movimientosJugadorS(int tecla, NaveSupervivencia* nave);
		void reestablecerValoresS(Asteroide* asteroides, int* num_ast);
		void guardarPuntuacion(Usuario* usuarios, int player, int* num_ast);
		WINDOW* mostrarJuegoS(void);
		void tamanyoTerminal();	
};


class VidaExtra
{
	private:
		int x;
		int y;
	public:
		void nuevaVidaExtra(VidaExtra* vidasExtra, int* num_vidasExtra);
		void mostrarVidaExtra(void);
		void pintarVidasExtra(WINDOW* ventana, VidaExtra* vidasExtra, int* num_vidasExtra);
		int choqueVidasExtra(WINDOW* ventana, NaveSupervivencia* nave, VidaExtra* vidasExtra, int* num_vidasExtra);
};


#endif