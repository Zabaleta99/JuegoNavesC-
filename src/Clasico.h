#ifndef CLASICO_H_
#define CLASICO_H_
#include <curses.h>
#include "NaveClasico.h"
#include "Asteroide.h"
#include "Bala.h"

class Clasico : public Juego
{
public:
	Clasico();
	void crearBalas (Bala* balas, NaveClasico* nave, int* num_balas);
	void mostrarPuntuacion (Usuario* usuarios, int player, float tiempo, int* disparosAcertados);
	void pintarChoqueAsteroideBala (WINDOW* ventana, Bala* bala);
	int choqueBalaAsteroide(WINDOW* ventana, Bala* bala, Asteroide* asteroide, int* disparosAcertados);
	void pintarBala(WINDOW* ventana, Bala* bala);
	void actualizarDisparosAcertados (int* disparosAcertados, int* num_balas);
	void actualizarC(WINDOW* ventana, NaveClasico* nave, int* disparosAcertados, int* num_balas);
	void crearAsteroidesHorizontales(Asteroide* asteroides, int* num_ast);
	void crearAsteroidesVerticales(Asteroide* asteroides, int* num_ast);
	void inicializarParametrosC(NaveClasico* nave, Asteroide* asteroides, int* num_ast, int* num_balas, int* disparosAcertados);
	void liberarMemoriaC(NaveClasico* nave, Asteroide* asteroides, int* num_ast, Bala* balas, int* num_balas, int* disparosAcertados, WINDOW* ventana);
	void reestablecerValoresC(Asteroide* asteroides, int* num_ast, Bala* balas, int* num_balas, int* disparosAcertados);
	void movimientosJugadorC(int tecla, NaveClasico* nave, Bala* balas, int* num_balas);
	void jugar(Usuario* usuarios, int player);
};

#endif