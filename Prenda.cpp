#include "Prenda.h"

Prenda::Prenda(string calidad, int stock)
{
	this->calidad = calidad;
	this->stock = stock;
}

Prenda::~Prenda()
{
}

string Prenda::getCalidad()
{
	return calidad;
}

int Prenda::getStock()
{
	return stock;
}
void Prenda::actualizarStock(int stock)
{
	 this->stock -= stock;
}

