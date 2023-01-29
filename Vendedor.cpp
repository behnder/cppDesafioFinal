#include "Vendedor.h"

int Vendedor::contadorCodigo = 0;
Vendedor::Vendedor(string nombre, string apellido)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->idVendedor = contadorCodigo++;
}
Vendedor::~Vendedor()
{
}

void Vendedor::Cotizaciones()
{
}
int Vendedor::getIdVendedor()
{
	return idVendedor;
}

string Vendedor::getApellido()
{
	return apellido;
}

string Vendedor::getNombre()
{
	return nombre;
}

