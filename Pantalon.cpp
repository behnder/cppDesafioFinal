#include "Pantalon.h"
#include "Prenda.h"

Pantalon::Pantalon(string calidad, int stock, string tipoCorte):
	Prenda(calidad,stock)
{
	this->tipoCorte = tipoCorte;
}

Pantalon::~Pantalon()
{
}

string Pantalon::getTipoCorte()
{
	return tipoCorte;
}

