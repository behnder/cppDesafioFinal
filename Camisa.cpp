#include "Camisa.h"

Camisa::Camisa(string calidad, int stock, string tipoManga, 
	string tipoCuello):Prenda(calidad,stock)
{
	this->tipoManga = tipoManga;
	this->tipoCuello = tipoCuello;

}

Camisa::~Camisa()
{
}

string Camisa::getTipoManga()
{
	return tipoManga;
}

string Camisa::getTipoCuello()
{
	return tipoCuello;
}

