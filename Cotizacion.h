#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include "Prenda.h"
#include <time.h>


using namespace std;

class Cotizacion
{
private:
	int idCotizacion=0;
	int idVendedor;
	Prenda* tipoPrenda;
	int cantPrendas;
	float cotizacionTotal;
	string fechaYHora;
public:
	Cotizacion(int idVendedor, Prenda *prendaCotizada, int cantPrendas);
	~Cotizacion();
	int getIdCotizacion();
	string getFechaYHora();
	string getFechaYHoraDeVenta();

	int getIdVendedor();
	Prenda* getTipoPrenda();



};

