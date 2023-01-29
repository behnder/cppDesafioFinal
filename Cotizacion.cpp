#include "Cotizacion.h"

Cotizacion::Cotizacion(int idVendedor, Prenda* prendaCotizada, int cantPrendas)
{
	this->idCotizacion++;
	this->fechaYHora = "01/01/2030";
	this->idVendedor = idVendedor;
	this->tipoPrenda = prendaCotizada;
	this->cantPrendas = cantPrendas;
}

Cotizacion::~Cotizacion()
{

}

int Cotizacion::getIdCotizacion()
{
	return idCotizacion;
}

string Cotizacion::getFechaYHora()
{
	return fechaYHora;
}

int Cotizacion::getIdVendedor()
{
	return idVendedor;
}

Prenda* Cotizacion::getTipoPrenda()
{
	return tipoPrenda;
}
