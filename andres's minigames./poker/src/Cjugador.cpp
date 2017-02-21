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

#include <Cjugador.h>

	Cjugador::Cjugador(): dinero(0.0)
	{

	}

	int Cjugador::valorMano()
	{
		int valor=this->mano.getPuntaje();
		return(valor);
	}




	float Cjugador::getDinero()
	{
		return dinero;
	}

	int Cjugador::setDinero(float _D)
	{
		if(_D<0) _D*=-1; 
		dinero=_D;
	}

	void Cjugador::setMano(Ccarta& _1,Ccarta& _2,Ccarta& _3,Ccarta& _4,Ccarta& _5)
	{
		mano.setJuego(_1,_2,_3,_4,_5);
	}

	int Cjugador::getCartaAlta()
	{
		return (mano.getCartaAlta());
	}


	void Cjugador::imprimirMano()
	{
		mano.imprimirMano();
	}

	int Cjugador::getCartaBaja()
	{
		return (mano.getCartaBaja());

	}