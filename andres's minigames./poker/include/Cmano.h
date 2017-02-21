/*
	----LICENCE------------
	
	This file is part of poker.
  Copyright (C) 2016 by Ramon A. hoyo

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

  Any user request of this software, write to 

  Ramon Hoyo

  ramonandreshoyodiaz@gmail.com
*/

#ifndef CMANO_H
#define CMANO_H

#include <Ccarta.h>

	class Cmano
	{	
		int puntaje;
		int  maxJugada;
		int cartaAlta;
		int cartaBaja;
		Ccarta juego[5];

		bool escaleraReal();
		bool escaleraColor();
		bool poker();
		bool full();
		bool color();
		bool escalera();
		bool trio();
		bool doblepar();
		bool par();
		int calcularCartaAlta();
		int calcularCartaBaja();
		int calculaPuntaje();
		Ccarta& getCarataDeMano(int);
	public:
		Cmano();
		Cmano(Ccarta,Ccarta,Ccarta,Ccarta,Ccarta);
		~Cmano(){};

		int setJuego(Ccarta,Ccarta,Ccarta,Ccarta,Ccarta);
		int getPuntaje();
		int getCartaAlta();
		int getCartaBaja();
		void imprimirMano();
		
	};

#endif