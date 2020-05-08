#ifndef JUEGO_H_
#define JUEGO_H_

class Juego
{
public:
	virtual void pintarAsteroides(WINDOW* ventana, Asteroide* asteroides, int* num_ast) = 0;
	virtual void subirNivel(Asteroide* asteroides, int* num_ast) = 0;
	virtual void mostrarGameOver() = 0;
	virtual int menuSalida() = 0;
	virtual WINDOW* mostrarInfo() = 0;
	virtual WINDOW* mostrarJuego() = 0;
	virtual void tamanyoTerminal() = 0;
	virtual void jugar(Usuario* usuarios, int player) = 0;
};

#endif