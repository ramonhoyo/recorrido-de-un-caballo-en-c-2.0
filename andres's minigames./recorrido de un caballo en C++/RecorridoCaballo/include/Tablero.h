/*

	----LICENCE------------
	
	This file is part of Recorrido de un caballo.
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

#ifndef TABLERO_H
#define TABLERO_H 
#include <Caballo.h>
class Tablero
	{
		Caballo ani;
		int tablero[8][8];
		int contador;

	public:
		Tablero();
		~Tablero(){};
		void imprimir();
		void run();
		bool esValida( int ,int );
		
	};

#endif
