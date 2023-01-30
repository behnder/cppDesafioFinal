#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include "Prenda.h"
#include <time.h>
#include "Tienda.h"
#include "Vendedor.h"
#include "Cotizacion.h"
#include <chrono>
#include <ctime>

using namespace std;
class MainMenuPresenter
{
private:
	Tienda* tienda;
	Vendedor* vendedor;
	int stock = 0;
	//Cotizacion* cotizacion;
	list<Cotizacion*> historialCotizaciones;
	float precioFinal;

public:
	~MainMenuPresenter();
	MainMenuPresenter();
	void InicializarDatos();
	Prenda* PrendaSeleccionada(bool esCamisa, bool esMangaCorta, bool esCuelloMao,
		bool esChupin,int stock, bool esStandard, int precioPrenda,
		int cantPrenda, float cotizacionFinal);

	float CrearCotizacion(Prenda * prendaACotizar, int cantidadPrendas, float precio, float cotizacionFinal);
	void MostrarHistorial(string listado);
	string getFechaYHoradeCotizacion();
	Tienda* getTienda();
	Vendedor* getVendedor();
	float getPrecioFinal();
	int getStock();

};

