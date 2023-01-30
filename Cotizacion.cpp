#include "Cotizacion.h"
#include <chrono>
#include <ctime>
using namespace std;

Cotizacion::Cotizacion(int idVendedor, Prenda* prendaCotizada, int cantPrendas)
{
	this->idCotizacion++;
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
	string fechaCotizacion;
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	char buf[26];

	std::tm tm;
	localtime_s(&tm, &now_c);
	std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
	return buf;

}

int Cotizacion::getIdVendedor()
{
	return idVendedor;
}

Prenda* Cotizacion::getTipoPrenda()
{
	return tipoPrenda;
}
