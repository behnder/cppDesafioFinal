#include <iostream>
#include <conio.h>
#include "Prenda.h"
#include "Camisa.h"
#include <cstdlib>
#include "MainMenuPresenter.h"
#include <chrono>
#include <ctime>
#include "Pantalon.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "");

	MainMenuPresenter* menu = new MainMenuPresenter();

	menu->InicializarDatos();

	string nombreTienda = menu->getTienda()->getNombre();
	string direccionTienda = menu->getTienda()->getDireccion();
	string nombreVendedor = menu->getVendedor()->getNombre() + " " + menu->getVendedor()->getApellido();
	int idVendedor = menu->getVendedor()->getIdVendedor();

	bool esCamisa;
	bool esMangaCorta;
	bool esCuelloMao;
	bool esChupin;
	bool esStandard;
	float cotizacionFinal;

	int precioPrenda;
	int cantPrenda;
	int* stock = new int();

	int opcionMenu;

	//Menu principal
	cout << " COTIZADOR EXPRESS - MENÚ PRINCIPAL" << endl;
	cout << "------------------------------------" << endl;
	cout << nombreTienda << " | " << direccionTienda << endl;
	cout << "------------------------------------" << endl;
	cout << nombreVendedor << " | Vendedor Id nro: " << idVendedor << endl;
	cout << "------------------------------------" << endl;
	cout << "\n" << endl;
	cout << "SELECCIONE UNA OPCIÓN DEL MENÚ" << endl;

	cout << "\n" << endl;

	cout << "1) Historial de Cotizaciones" << endl;
	cout << "2) Realizar una cotización" << endl;
	cout << "3) Salir" << endl;

	cin >> opcionMenu;

	system("cls");


	string cotizacionAImprimir = "";

	switch (opcionMenu)
	{
	case 1:
		//Historial de cotizaciones
		cout << "COTIZADOR EXPREESS - HISTORIAL DE COTIZACIONES" << endl;
		cout << "------------------------------------" << endl;
		cout << "Presiona 3 para volver al menú principal" << endl;
		cout << "------------------------------------" << endl;
		menu->MostrarHistorial(cotizacionAImprimir);
		cout << "Número de identificación: 000" << endl;
		cout << "Fecha y Hora de la cotización" << endl;
		cout << "Código del Vendedor: 000" << endl;
		cout << "Prenda cotizada: Camisa - manga corta - premium" << endl;
		cout << "Precio unitario: $xx.xx" << endl;
		cout << "Cantidad de unidades cotizadas: 17" << endl;
		cout << "Precio final: $xx.xx" << endl;

		cin >> opcionMenu;
		system("cls");
		break;
	case 2:
		cout << "COTIZADOR EXPREESS - COTIZAR" << endl;
		cout << "------------------------------------" << endl;
		cout << "Presiona 3 para volver al menú principal" << endl;
		cout << "PASO 1: Selecciona la prenda a cotizar" << endl;
		cout << "1) Camisa" << endl;
		cout << "2) Pantalón" << endl;
		cout << "------------------------------------" << endl;

		cin >> opcionMenu;

		system("cls");

		switch (opcionMenu)
		{
		case 1:
			esCamisa = true;
			cout << "COTIZADOR EXPREESS - COTIZAR" << endl;
			cout << "------------------------------------" << endl;
			cout << "Presiona 3 para volver al menú principal" << endl;
			cout << "Paso 2.a: La camisa a cotizar, ¿Es Manga corta?" << endl;
			cout << "1) Sí" << endl;
			cout << "2) No" << endl;
			cout << "------------------------------------" << endl;

			cin >> opcionMenu;

			esMangaCorta = opcionMenu == 1 ? true : false;

			system("cls");

			switch (opcionMenu)
			{
			case 1:
				esMangaCorta = true;
				cout << "COTIZADOR EXPREESS - COTIZAR" << endl;
				cout << "------------------------------------" << endl;
				cout << "Presiona 3 para volver al menú principal" << endl;
				cout << "Paso 2.b: La camisa a cotizar, ¿Es Cuello Mao?" << endl;
				cout << "1) Sí" << endl;
				cout << "2) No" << endl;
				cout << "------------------------------------" << endl;

				cin >> opcionMenu;
				
				esCuelloMao = opcionMenu == 1 ? true : false;

				system("cls");

				break;
			default:
				break;
			}

			break;
		case 2:
			esCamisa = false;
			cout << "COTIZADOR EXPREESS - COTIZAR" << endl;
			cout << "------------------------------------" << endl;
			cout << "Presiona 3 para volver al menú principal" << endl;
			cout << "Paso 2: El Pantalón a cotizar, ¿Es chupín?" << endl;
			cout << "1) Sí" << endl;
			cout << "2) No" << endl;
			cout << "------------------------------------" << endl;

			cin >> opcionMenu;

			system("cls");

			esChupin = opcionMenu == 1 ? true : false;

			break;
		case 3:
			cout << "Adios" << endl;
			return 0;
			break;
		default:
			break;
		}

		break;

	case 3:
		cout << "Adios" << endl;
		return 0;
		break;
	default:
		break;
	}



	cout << "COTIZADOR EXPREESS - COTIZAR" << endl;
	cout << "------------------------------------" << endl;
	cout << "Presiona 3 para volver al menú principal" << endl;
	cout << "Paso 3: Seleccione al calidad de la prenda" << endl;
	cout << "1) Standard" << endl;
	cout << "2) Premium" << endl;
	cout << "------------------------------------" << endl;

	cin >> opcionMenu;

	system("cls");

	esStandard = opcionMenu == 1 ? true : false;

	cout << "COTIZADOR EXPREESS - COTIZAR" << endl;
	cout << "------------------------------------" << endl;
	cout << "Presiona 3 para volver al menú principal" << endl;
	cout << "Paso 4: Ingrese el precio unitario de la prenda a cotizar" << endl;
	cin >> precioPrenda;
	cout << "------------------------------------" << endl;

	system("cls");

	cout << "COTIZADOR EXPREESS - COTIZAR" << endl;
	cout << "------------------------------------" << endl;
	cout << "Presiona 3 para volver al menú principal" << endl;
	cout << "\n" << endl;
	cout << "INFORMACIÓN:" << endl;
	cout << "EXISTE x CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA" << endl;
	cout << "\n" << endl;
	cout << "PASO 5: Ingrese la cantidad de unidades a cotizar" << endl;
	cin >> opcionMenu;
	cout << "------------------------------------" << endl;

	cin >> opcionMenu;

	system("cls");


	Prenda *prenda = menu->PrendaSeleccionada(esCamisa, esMangaCorta, esCuelloMao, esChupin, stock, esStandard, precioPrenda, cantPrenda, cotizacionFinal);


	cout << "COTIZADOR EXPREESS - COTIZAR" << endl;
	cout << "------------------------------------" << endl;
	cout << "Presiona 3 para volver al menú principal" << endl;
	cout << "------------------------------------" << endl;
	cout << "Número de identificación: " << idVendedor << endl;
	std::time_t now = std::time(nullptr);
	std::tm* local_time = std::localtime(&now);
	cout << "Fecha y Hora de la cotización: 1" << local_time->tm_mday << endl;
	cout << "Código del vendedor: " << idVendedor << endl;



	if (auto tipodePrenda = dynamic_cast<Camisa*>(prenda))
	{
		
		cout << "Prenda cotizada: Camisa " << tipodePrenda->getTipoManga() << " " << tipodePrenda->getTipoCuello() << " " << endl;
	}
	if (auto tipodePrenda = dynamic_cast<Pantalon*>(prenda))
	{
		cout << "Prenda cotizada: Camisa " << tipodePrenda->getTipoCorte() << " "<< endl;

	}

	cout << "Precio unitario: $" << precioPrenda << endl;
	cout << "Cantidad de unidades cotizadas:"<< cantPrenda << endl;

	menu->CrearCotizacion(prenda, cantPrenda, precioPrenda, cotizacionFinal);

	cout << "Precio Final: $xx,xx" << endl;
	cin >> opcionMenu;
	cout << "------------------------------------" << endl;
	cout << "Presiona 3 para volver al menú principal" << endl;
	cout << "------------------------------------" << endl;

	cin >> opcionMenu;

	system("cls");

	_getch();

	delete stock;
	return 0;
}