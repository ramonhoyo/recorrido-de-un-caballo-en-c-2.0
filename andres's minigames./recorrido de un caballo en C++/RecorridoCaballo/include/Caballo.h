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



#ifndef CCABALLO_H
#define CCABALLO_H 

class Caballo
{
	int x;
	int y;
	int movimiento;
	int setX(int);
	int setY(int);
public:
	Caballo();
	~Caballo(){};

	int mover(int);


	inline int getX()const{return(x);};
	inline int getY()const{return(y);};
	inline int getMovimiento()const{return(movimiento);};	
};

#endif
