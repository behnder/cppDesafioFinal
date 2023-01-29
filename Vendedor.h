#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Cotizacion.h"


using namespace std;

class Vendedor
{
private:
	string nombre;
	string apellido;
	int idVendedor;
	list<shared_ptr<Cotizacion>> listaPrendas;

	static int contadorCodigo;
public:
	Vendedor(string nombre, string apellido);
	~Vendedor();
	void Cotizaciones();
	int getIdVendedor();
	string getNombre();
	string getApellido();
};