#pragma once
#include "Prenda.h"
#include <string>
class Pantalon : public  Prenda
{
private:
	string tipoCorte;
public:
	Pantalon(string calidad, int stock, string tipoCorte);
	~Pantalon();
	string getTipoCorte();


};

