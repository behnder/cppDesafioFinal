#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Prenda.h"


using namespace std;
class Tienda
{
private:
	string nombre;
	string direccion;
	list<shared_ptr<Prenda>> listaPrendas;
public:
	Tienda(string nombre, string direccion);
	~Tienda();

	void CargarCamisas();
	void CargarPantalones();
	list<shared_ptr<Prenda>> getPrendas();
	void setListaPrendas(list<shared_ptr<Prenda>> newListaPrendas);
	string getNombre();
	string getDireccion();

};

