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

#include <Caballo.h>


	Caballo::Caballo():x(0),y(0),movimiento(0) {}

	int Caballo::mover(int _N)
	{
		switch(_N)
		{
			case 1:
				x=1;
				y=2;		
				return 0;
				break;
			case 2:
				x=1;
				y=-2;		
				return 0;				
				break;
			case 3:
				x=2;
				y=1;		
				return 0;				
				break;
			case 4:
				x=2;
				y=-1;		
				return 0;				
				break;
			case 5:
				x=-1;
				y=2;		
				return 0;				
				break;
			case 6:
				x=-1;
				y=-2;		
				return 0;				
				break;		
			case 7:
				x=-2;
				y=1;		
				return 0;				
				break;
			case 8:
				x=-2;
				y=-1;		
				return 0;				
				break;										
			default:
				return 1;
				break;
		}
	}

	int Caballo::setY(int _N)
	{
		y=_N;
		return 0;
	}
	int Caballo::setX(int _N)
	{
		x=_N;
		return 0;
	}
