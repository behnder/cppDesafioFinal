#pragma once
#include <iostream>
#include <string>
#include <list>


using namespace std;
class Prenda
{
private:
	string calidad;
	int precioUnitario;
	int stock;
public:
	Prenda(string calidad, int stock);
	virtual ~Prenda();
	string getCalidad();
	int getStock();
	void actualizarStock(int stock);
	
};

