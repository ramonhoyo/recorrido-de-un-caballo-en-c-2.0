#ifndef CMAZO_H
#define CMAZO_H

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

#include <Ccarta.h>
	class Cmazo
	{
		Ccarta mazo[52];
		Ccarta auxMazo[52];

	public:
		Cmazo();
		~Cmazo(){};

		Ccarta& getCarta(int);
		int setCarta(const Ccarta&,int);
		virtual void barajar();
		virtual void imprimirMazo();
		Ccarta sacarCarta();
		int meterCarta(Ccarta&);
		void repetidas();
		int llenarAuto();

 
	};

#endif