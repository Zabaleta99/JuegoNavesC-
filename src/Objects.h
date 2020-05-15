#ifndef OBJECTS_H_
#define OBJECTS_H_

class Object{};

class Objects
{
	int size;
	Object* array
public:
	Objects();
	~Objects();
	int getSize() const;
	void setSize(int size);
	int getArray() const;
	void setArray(Object* array);
};

class Number: public Object
{
public:
	int number;
};

#endif