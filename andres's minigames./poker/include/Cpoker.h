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
#ifndef CPOKER_H
#define CPOKER_H 

#include <Cmazo.h>
#include <Cjugador.h>
#include <Ccarta.h>


	class Cpoker
	{
		Cmazo MAZO;
		Cjugador jugadores[2];
		int turno;
		int ganador;
		int nuevo();
		int repartir();
		int resultado();
		int imprimir();
		int imprimirMazo();

	public:
		Cpoker();
		~Cpoker(){};

		void run();		
	};

#endif