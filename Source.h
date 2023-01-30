#pragma once

void ProcesarPedidoPrenda(int& opcionMenu, bool& esStandard, int& precioPrenda, int& cantPrenda, MainMenuPresenter* menu, bool esCamisa, bool esMangaCorta, bool esCuelloMao, bool esChupin, int stock, float cotizacionFinal, int idVendedor);

void OpcionMenuIncorrecto(int& opcionMenu);
