#include "Tienda.h"
#include "Camisa.h"
#include <memory>
#include "Pantalon.h"
#include "Prenda.h"
#include "Vendedor.h"

using namespace std;
Tienda::Tienda(string nombre, string direccion)
{
	this->nombre = nombre;
	this->direccion = direccion;
}


void Tienda::CargarCamisas()
{
	//Camisas Manga Corta
	listaPrendas.push_back(make_shared<Camisa>("Standard", 100, "corta", "mao"));
	listaPrendas.push_back(make_shared<Camisa>("Premium", 100, "corta", "mao"));
	listaPrendas.push_back(make_shared<Camisa>("Standard", 150, "corta", "comun"));
	listaPrendas.push_back(make_shared<Camisa>("Premium", 150, "corta", "comun"));

	//Camisas Manga Larga
	listaPrendas.push_back(make_shared<Camisa>("Standard", 75, "larga", "mao"));
	listaPrendas.push_back(make_shared<Camisa>("Premium", 75, "larga", "mao"));
	listaPrendas.push_back(make_shared<Camisa>("Standard", 175, "corta", "comun"));
	listaPrendas.push_back(make_shared<Camisa>("Premium", 175, "larga", "comun"));
}

void Tienda::CargarPantalones()
{
	//Pantalones chupin
	listaPrendas.push_back(make_shared<Pantalon>("Standard", 750, "chupin"));
	listaPrendas.push_back(make_shared<Pantalon>("Premium", 750, "chupin"));

	//Pantalones chupin
	listaPrendas.push_back(make_shared<Pantalon>("Standard", 250, "normal"));
	listaPrendas.push_back(make_shared<Pantalon>("Premium", 250, "normal"));
}

Tienda::~Tienda()
{

}

list<shared_ptr<Prenda>> Tienda::getPrendas() {
	return listaPrendas;
}

void Tienda::setListaPrendas(list<shared_ptr<Prenda>> newListaPrendas) {
	listaPrendas = newListaPrendas;
}

string Tienda::getNombre()
{
	return nombre;
}

string Tienda::getDireccion()
{
	return direccion;
}

