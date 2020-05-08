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
	virtual void pintarAsteroides(WINDOW* ventana, Asteroide* asteroides, int* num_ast);
	virtual void subirNivel(Asteroide* asteroides, int* num_ast);
	virtual void mostrarGameOver();
	virtual int menuSalida();
	virtual WINDOW* mostrarInfo();
	virtual WINDOW* mostrarJuego();
	virtual void tamanyoTerminal();
	virtual void jugar(Usuario* usuarios, int player);
	virtual void nuevoAsteroideVertical();
	virtual void nuevoAsteroideHorizontal();
	virtual void pintarAsteroideVertical(WINDOW* ventana);
	virtual void pintarAsteroideHorizontal(WINDOW* ventana);
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