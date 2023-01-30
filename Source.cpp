#include <iostream>
#include <conio.h>
#include "Prenda.h"
#include "Camisa.h"
#include <cstdlib>
#include "MainMenuPresenter.h"
#include <chrono>
#include <ctime>
#include "Pantalon.h"
#include "Source.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "");

	MainMenuPresenter* menu = new MainMenuPresenter();

	menu->InicializarDatos();

	string nombreTienda = menu->getTienda()->getNombre();
	string direccionTienda = menu->getTienda()->getDireccion();
	string nombreVendedor = menu->getVendedor()->getNombre() + " " + menu->getVendedor()->getApellido();
	int idVendedor = menu->getVendedor()->getIdVendedor();

	bool esCamisa = false;
	bool esMangaCorta = false;
	bool esCuelloMao = false;
	bool esChupin = false;
	bool esStandard = false;
	float cotizacionFinal = 0;

	int precioPrenda = 0;
	int cantPrenda = 0;
	int stock = 0;

	int opcionMenu = 3;



	while (opcionMenu == 3)
	{


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
			cout << "COTIZADOR EXPREESS - HISTORIAL DE COTIZACIONES" << endl;
			cout << "------------------------------------" << endl;
			cout << "Presiona cualquier tecla para volver al menú principal" << endl;
			cout << "------------------------------------" << endl;

			menu->MostrarHistorial(cotizacionAImprimir);

			_getch();
			system("cls");
			opcionMenu = 3;
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
				system("cls");
				if (opcionMenu > 0 && opcionMenu < 3)
				{
					esMangaCorta = opcionMenu == 1 ? true : false;

					system("cls");

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

					ProcesarPedidoPrenda(opcionMenu, esStandard, precioPrenda, cantPrenda, menu, esCamisa,
						esMangaCorta, esCuelloMao, esChupin, stock, cotizacionFinal, idVendedor);
				}
				else
				{
					OpcionMenuIncorrecto(opcionMenu);
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
				if (opcionMenu > 0 && opcionMenu < 3)
				{
					esChupin = opcionMenu == 1 ? true : false;

					ProcesarPedidoPrenda(opcionMenu, esStandard, precioPrenda, cantPrenda, menu, esCamisa,
						esMangaCorta, esCuelloMao, esChupin, stock, cotizacionFinal, idVendedor);
				}
				else
				{
					OpcionMenuIncorrecto(opcionMenu);
				}
				break;
			default:
				OpcionMenuIncorrecto(opcionMenu);

				break;
			}

			break;

		case 3:
			cout << "Adios" << endl;
			return 0;
			break;
		default:
			OpcionMenuIncorrecto(opcionMenu);

			break;
		}


	}

	_getch();

	return 0;
}

void OpcionMenuIncorrecto(int& opcionMenu)
{
	if (cin.fail()) {
		cout << "Entrada inválida. Por favor, ingrese un número." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		opcionMenu = 3;
		_getch();
		system("cls");
	}
	else
	{
		cout << "La opción es incorrecta, vuelva a ingresar la opción correcta" << endl;
		opcionMenu = 3;
		_getch();
		system("cls");

	}
}

void ProcesarPedidoPrenda(int& opcionMenu, bool& esStandard, int& precioPrenda, int& cantPrenda, MainMenuPresenter* menu, bool esCamisa, bool esMangaCorta, bool esCuelloMao, bool esChupin, int stock, float cotizacionFinal, int idVendedor)
{
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
	cout << "------------------------------------" << endl;
	cout << "PASO 5: Ingrese la cantidad de unidades a cotizar" << endl;
	cin >> cantPrenda;
	cout << "------------------------------------" << endl;

	Prenda* prenda = menu->PrendaSeleccionada(esCamisa, esMangaCorta, esCuelloMao, esChupin, stock, esStandard, precioPrenda, cantPrenda, cotizacionFinal);

	cout << "EXISTEN: " << prenda->getStock() << " UNIDADES EN STOCK DE LA PRENDA SELECCIONADA" << endl;

	cout << "------------------------------------" << endl;
	cout << "Número de identificación: " << idVendedor << endl;
	cout << "Fecha y Hora de la cotización: " << menu->getFechaYHoradeCotizacion() << endl;
	cout << "Código del vendedor: " << idVendedor << endl;



	if (auto tipodePrenda = dynamic_cast<Camisa*>(prenda))
	{
		cout << "Prenda cotizada: Camisa " << tipodePrenda->getTipoManga() << " " << tipodePrenda->getTipoCuello() << " " << endl;
	}
	if (auto tipodePrenda = dynamic_cast<Pantalon*>(prenda))
	{
		cout << "Prenda cotizada: Pantalon " << tipodePrenda->getTipoCorte() << " " << endl;
	}

	cout << "Precio unitario: $" << precioPrenda << endl;
	cout << "Cantidad de unidades cotizadas:" << cantPrenda << endl;

	//float precioFinal = menu->CrearCotizacion(prenda, cantPrenda, precioPrenda, cotizacionFinal);

	cout << "Precio Final: $" << menu->getPrecioFinal() << endl;
	cout << "------------------------------------" << endl;
	cout << "Presiona 3 para volver al menú principal" << endl;
	cout << "------------------------------------" << endl;

	cin >> opcionMenu;

	system("cls");
}
