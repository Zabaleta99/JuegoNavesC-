#ifndef BALA_H_
#define BALA_H_

class Bala
{
	int x;
	int y;
public:
	Bala(): x(-1), y(-1){}
	Bala(int x, int y): x(x), y(y){}
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
};

#endif