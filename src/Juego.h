#ifndef JUEGO_H_
#define JUEGO_H_

class Juego
{
public:
	virtual void pintarAsteroides(WINDOW* ventana, Asteroide* asteroides, int* num_ast);
	virtual void subirNivel(Asteroide* asteroides, int* num_ast);
	virtual void mostrarGameOver();
	virtual int menuSalida();
	virtual WINDOW* mostrarInfo();
	virtual WINDOW* mostrarJuego();
	virtual void tamanyoTerminal();
	virtual void jugar(Usuario* usuarios, int player);
};

#endif