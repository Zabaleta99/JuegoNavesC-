#include "Objects.h"

Objects::Objects()
{
	this->size = 216;
	this->array = new Objects[216];
}
Objects::~Objects()
{
	this->size = 0;
	delete[] this->array;
}
int Objects::getSize() const
{
	return this->size;
}
void Objects::setSize(int size)
{
	this->size = size;
}
int Objects::getArray() const
{
	return this->array;
}
void Objects::setArray(Object* array)
{
	this->array = array;
}