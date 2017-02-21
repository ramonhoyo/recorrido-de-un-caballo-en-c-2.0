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

	Ccarta::Ccarta(){
		valor=-1;
		tipo=-1;
	}

	int Ccarta::setValor(int _V)
	{
		if(_V>=0&&_V<14)
		{
			valor=_V;
			return 0;
		}
		else return 1;
	}	

	int Ccarta::setColor(int _T)
	{
		if(_T>=0&&_T<4)
		{
			tipo=_T;
			return 0;
		}
		else return 1;
	}

	int Ccarta::setCarta(int _T,int _V)
	{
		this->setColor(_T);
		this->setValor(_V);
		return 0;
	}
	
	bool Ccarta::operator==( const Ccarta& _aux)
	{
		if(this->valor==_aux.getValor()&&this->tipo==_aux.getColor()) return true;
		else return false;
	}

	Ccarta& Ccarta::operator=( const Ccarta& _aux)
	{
		this->valor=_aux.getValor();
		this->tipo=_aux.getColor();
		return *this;
	}

	int Ccarta::eliminarCarta()
	{
		valor=-1;
		tipo=-1;
	}