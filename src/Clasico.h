#ifndef CLASICO_H_
#define CLASICO_H_

#include "Comun.h"
#include "Usuarios.h"

#include <curses.h>

class NaveClasico
{
	private:
		int x;
		int y;
		int vidas;
		int corazones;

	public:
		void jugarClasico(Usuario* usuarios, int player);
		void mostrarGameOverC(void);
		void mostrarPuntuacion (Usuario* usuarios, int player, float tiempo, int* disparosAcertados);
		void pintarNaveChoqueC(WINDOW* ventana, NaveClasico* nave);
		int choqueC(WINDOW* ventana, NaveClasico* nave, Asteroide* asteroide);
		void pintarNaveC(WINDOW* ventana, NaveClasico* nave);
		int menuSalidaC(void);
		void pintarVidasC(NaveClasico* nave);
		void actualizarDisparosAcertados (int* disparosAcertados, int* num_balas);
		void actualizarC(WINDOW* ventana, NaveClasico* nave, int* disparosAcertados, int* num_balas);
		void subirNivelC(Asteroide* asteroides, int* num_ast);
		void inicializarParametrosC(NaveClasico* nave, Asteroide* asteroides, int* num_ast, int* num_balas, int* disparosAcertados);
		void liberarMemoriaC(NaveClasico* nave, Asteroide* asteroides, int* num_ast, Bala* balas, int* num_balas, int* disparosAcertados, WINDOW* ventana);
		WINDOW* mostrarInfoC(void);
		WINDOW* mostrarJuegoC(void);
		void reestablecerValoresC(Asteroide* asteroides, int* num_ast, Bala* balas, int* num_balas, int* disparosAcertados);
		void movimientosJugadorC(int tecla, NaveClasico* nave, Bala* balas, int* num_balas);
		void tamanyoAbsolutoC();
{

};

class Bala
{
	private:
		int x;
		int y;

	public:
		void crearBalas (Bala* balas, NaveClasico* nave, int* num_balas);
		void pintarChoqueAsteroideBala (WINDOW* ventana, Bala* bala);
		int choqueBalaAsteroide(WINDOW* ventana, Bala* bala, Asteroide* asteroide, int* disparosAcertados);
		void pintarBala(WINDOW* ventana, Bala* bala);


};


#endif