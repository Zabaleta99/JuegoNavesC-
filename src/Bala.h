#ifndef BALA_H_
#define BALA_H_

class Bala
{
	int x;
	int y;
public:
	Bala(int x, int y): x(x), y(y){}
	int getX();
	void setX();
	int getY();
	void setY();
}

#endif