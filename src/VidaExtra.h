#ifndef VIDAEXTRA_H_
#define VIDAEXTRA_H_

class VidaExtra
{
	int x;
	int y;
public: 
	VidaExtra(int x, int y): x(x), y(y){}
	int getX();
	void setX();
	int getY();
	void setY();
};

#endif