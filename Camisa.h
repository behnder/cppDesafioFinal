#pragma once
#include "Prenda.h"
#include <string>
class Camisa :public  Prenda
{
protected:
	string tipoManga;
	string tipoCuello;
public:
	Camisa(string calidad, int stock, string tipoManga, string tipoCuello);
	~Camisa();

	string getTipoManga();
	string getTipoCuello();
};

