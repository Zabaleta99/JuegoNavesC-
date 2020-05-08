#ifndef SUPERVIVENCIA_H_
#define SUPERVIVENCIA_H_
#include <curses.h>
#include "NaveSupervivencia.h"
#include "Asteroide.h"
#include "VidaExtra.h"

class Supervivencia : public Juego
{
public:
	Supervivencia();
	void mostrarNivel(int* num_ast);
	void mostrarVidaExtra();
	void nuevaVidaExtra(VidaExtra* vidasExtra, int* num_vidasExtra);
	void pintarVidasExtra(WINDOW* ventana, VidaExtra* vidasExtra, int* num_vidasExtra);
	int choqueVidasExtra(WINDOW* ventana, NaveSupervivencia* nave, VidaExtra* vidasExtra, int* num_vidasExtra);
	void actualizarS(WINDOW* ventana, NaveSupervivencia* nave);
	void liberarMemoriaS(NaveSupervivencia* nave, Asteroide* asteroides, int* num_ast, VidaExtra* vidasExtra, int* num_vidasExtra, WINDOW* ventana);
	void inicializarParametrosS(NaveSupervivencia* nave, Asteroide* asteroides, int* num_ast, VidaExtra* vidasExtra, int* num_vidasExtra);
	void movimientosJugadorS(int tecla, NaveSupervivencia* nave);
	void reestablecerValoresS(Asteroide* asteroides, int* num_ast);
	void guardarPuntuacion(Usuario* usuarios, int player, int* num_ast);
};

#endif