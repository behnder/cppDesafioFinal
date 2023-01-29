#include "MainMenuPresenter.h"
#include "Camisa.h"
#include "Pantalon.h"


using namespace std;
MainMenuPresenter::~MainMenuPresenter()
{
}

MainMenuPresenter::MainMenuPresenter()
{
	shared_ptr<Tienda>tienda = make_shared< Tienda>("Tienda OneBox", "Av Callao 9399");
	vendedor = new Vendedor("Nicolas", "Mercado");


	tienda->CargarCamisas();
	tienda->CargarPantalones();
}

void MainMenuPresenter::InicializarDatos()
{
	this->tienda = new Tienda("Tienda Callao", "Callao 1");
	this->vendedor = new Vendedor("Nicolas", "Mercado");

	tienda->CargarCamisas();
	tienda->CargarPantalones();

}

Prenda* MainMenuPresenter::PrendaSeleccionada(bool esCamisa, bool esMangaCorta, bool esCuelloMao,
	bool esChupin, int* stock, bool esStandard, int precioPrenda,
	int cantPrenda, float cotizacionFinal)
{
	Prenda* prendaCotizada;
	auto prendas = tienda->getPrendas();
	if (esCamisa)
	{
		for (auto prenda : prendas)
		{
			if (auto camisa = dynamic_cast<Camisa*>(prenda.get()))// SI ES CAMISA-
			{

				//si tildo solo  manga corta(manga corta y cuello comun)
				if (esMangaCorta && !esCuelloMao)
				{
					//selecciono manga corta y cuello comun
					if (camisa->getTipoManga() == "corta" && camisa->getTipoCuello() == "comun")
					{
						if (esStandard)
						{
							if (camisa->getCalidad() == "Standard")
							{

								stock = camisa->getStock();
								prendaCotizada = camisa;
								CrearCotizacion(camisa, cantPrenda, precioPrenda, cotizacionFinal);

							}

						}
						else if (!esStandard)
						{

							if (camisa->getCalidad() == "Premium")
							{

								stock = camisa->getStock();
								prendaCotizada = camisa;
								CrearCotizacion(camisa, cantPrenda, precioPrenda, cotizacionFinal);

							}


						}

					}

				}

				// si tildo manga corta y cuello mao
				if (esCuelloMao && esMangaCorta)
				{
					//selecciono manga corta  y cuello mao
					if (camisa->getTipoManga() == "corta" && camisa->getTipoCuello() == "mao")
					{
						if (esStandard)
						{
							if (prenda->getCalidad() == "Standard")
							{

								stock = camisa->getStock();
								prendaCotizada = camisa;

								CrearCotizacion(camisa, cantPrenda, precioPrenda, cotizacionFinal);

							}
						}
						else if (!esStandard)
						{
							if (prenda->getCalidad() == "Premium")
							{
								stock = prenda->getStock();
								prendaCotizada = camisa;

								CrearCotizacion(camisa, cantPrenda, precioPrenda, cotizacionFinal);

							}
						}
					}

				}
				//si NO tildo  manga corta Y NO TILDO cuello comun)
				if (!esCuelloMao && !esMangaCorta)
				{

					//selecciono manga larga  y cuello comun
					if (camisa->getTipoManga() == "larga" && camisa->getTipoCuello() == "comun")
					{

						if (esStandard)
						{
							if (camisa->getCalidad() == "Standard")
							{
								stock = camisa->getStock();
								prendaCotizada = camisa;
								CrearCotizacion(camisa, cantPrenda, precioPrenda, cotizacionFinal);
							}

						}
						else if (!esStandard)
						{
							if (camisa->getCalidad() == "Premium")
							{
								stock = camisa->getStock();
								prendaCotizada = camisa;
								CrearCotizacion(camisa, cantPrenda, precioPrenda, cotizacionFinal);
							}

						}
					}

				}




				//si NO tildo  manga corta y tildo  cuello mao)
				if (!esMangaCorta && esCuelloMao)
				{

					//selecciono manga larga  y cuello mao
					if (camisa->getTipoManga() == "larga" && camisa->getTipoCuello() == "mao")
					{


						if (esStandard)
						{
							if (camisa->getCalidad() == "Standard")
							{
								stock = camisa->getStock();
								prendaCotizada = camisa;
								CrearCotizacion(camisa, cantPrenda, precioPrenda, cotizacionFinal);
							}

						}
						else if (!esStandard)
						{
							if (camisa->getCalidad() == "Premium")
							{
								stock = camisa->getStock();
								prendaCotizada = camisa;
								CrearCotizacion(camisa, cantPrenda, precioPrenda, cotizacionFinal);
							}

						}

					}

				}


			}
		}

	}
	else {
		for (auto prenda : prendas)
		{
			if (auto pantalon = dynamic_cast<Pantalon*>(prenda.get()))
			{

				if (esChupin)
				{

					if (pantalon->getTipoCorte() == "chupin")
					{

						if (esStandard)
						{
							if (pantalon->getCalidad() == "Standard")
							{

								stock = pantalon->getStock();
								prendaCotizada = pantalon;
								CrearCotizacion(pantalon, cantPrenda, precioPrenda, cotizacionFinal);
							}
						}
						else if (!esStandard)
						{
							if (pantalon->getCalidad() == "Premium")
							{

								stock = pantalon->getStock();
								prendaCotizada = pantalon;
								CrearCotizacion(pantalon, cantPrenda, precioPrenda, cotizacionFinal);

							}
						}//-
					}
				}
				//si NO es chupin
				else
				{
					if (pantalon->getTipoCorte() == "normal")
					{
						if (esStandard)
						{
							if (pantalon->getCalidad() == "Standard")
							{
								stock = pantalon->getStock();
								prendaCotizada = pantalon;
								CrearCotizacion(pantalon, cantPrenda, precioPrenda, cotizacionFinal);
							}

						}
						else if (!esStandard)
						{

							if (pantalon->getCalidad() == "Premium")
							{
								stock = pantalon->getStock();
								prendaCotizada = pantalon;
								CrearCotizacion(pantalon, cantPrenda, precioPrenda, cotizacionFinal);
							}


						}
					}
				}
			}
		}
	}
	return prendaCotizada;
}



float  MainMenuPresenter::CrearCotizacion(Prenda* prendaACotizar, int cantidadPrendas, float precio, float cotizacionFinal)
{
;
	if (*prendaACotizar->getStock() < cantidadPrendas)
	{
		cout << "NO HAY SUIFICIENTE STOCK" << endl;
	}
	else
	{
		if (auto camisa = dynamic_cast<Camisa*>(prendaACotizar))
		{

			if (camisa->getTipoManga() == "corta")
			{
				precio *= 0.90f;
				if (camisa->getTipoCuello() == "mao")
				{
					precio *= 1.03f;
				}

			}
			else if (camisa->getTipoCuello() == "mao")
			{
				precio *= 1.03f;
			}

		}
		if (auto pantalon = dynamic_cast<Pantalon*>(prendaACotizar))
		{

			if (pantalon->getTipoCorte() == "chupin")
			{
				precio *= 0.88f;
			}
		}

		if (prendaACotizar->getCalidad() == "Premium")
		{
			precio *= 1.3f;
		}


		historialCotizaciones.push_back(new Cotizacion(this->vendedor->getIdVendedor(), prendaACotizar, cantidadPrendas));
		cotizacionFinal = (cantidadPrendas * precio);


	}

	return cotizacionFinal;

}

void MainMenuPresenter::MostrarHistorial(string listado)
{
	string tipoPrenda = "";
	for (auto cotizacion : historialCotizaciones)
	{

		cout << "\n " << cotizacion->getIdVendedor() << " Fecha: " << cotizacion->getFechaYHora() << 
			" Prenda: " << (dynamic_cast<Camisa*>(cotizacion->getTipoPrenda()) ? "CAMISA" : "PANTALON") << "PRUEBA" << endl;
	}

}

Tienda* MainMenuPresenter::getTienda()
{
	return tienda;
}

Vendedor* MainMenuPresenter::getVendedor()
{
	return vendedor;
}
