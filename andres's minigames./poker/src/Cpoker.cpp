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

#include <Cpoker.h>
#include <iostream>
#include <Ccarta.h>

using namespace std;

	Cpoker::Cpoker()
	{
		turno=0;
	}

	int Cpoker::nuevo()
	{
		MAZO.llenarAuto();
		MAZO.barajar();
		turno=0;
		ganador=-1;
		return 0;
	}

	int Cpoker::repartir()
	{

		imprimirMazo();
		Ccarta mano_Aux[5];
		Ccarta mano_Aux2[5];

			for (int j = 0; j < 5; ++j)
			{
				mano_Aux[j]=MAZO.sacarCarta();
				mano_Aux2[j]=MAZO.sacarCarta();
			}
			jugadores[0].setMano(mano_Aux[0],mano_Aux[1],mano_Aux[2],mano_Aux[3],mano_Aux[4]);
			jugadores[1].setMano(mano_Aux2[0],mano_Aux2[1],mano_Aux2[2],mano_Aux2[3],mano_Aux2[4]);
			jugadores[0].imprimirMano();
			jugadores[1].imprimirMano();
		return 0;
	}

	int Cpoker::resultado()
	{	
		int valor_1=0;
		int valor_2=0;
		int carta_alta=0;
		int carta_alta2=0;
		valor_1=jugadores[0].valorMano();
		valor_2=jugadores[1].valorMano();
		cout<<"............................................................."<<endl;
		cout<<"puntaje del jugador 1 "<<valor_1<<endl;
		cout<<"puntaje del jugador 2 "<<valor_2<<endl;
		cout<<"............................................................."<<endl;
		

		if(valor_1>valor_2) ganador=1;
		if(valor_2>valor_1) ganador=2;
		if(valor_1==valor_2)
		{
			if(jugadores[0].getCartaBaja()==0) carta_alta=15;
			else carta_alta=jugadores[0].getCartaAlta();

			if(jugadores[1].getCartaBaja()==0) carta_alta2=15;
			else carta_alta2=jugadores[1].getCartaAlta();

			if(carta_alta>carta_alta2) ganador=1;
			if(carta_alta2>carta_alta) ganador=2;
			if(carta_alta==carta_alta2) ganador=0;
		}

		return 0;
	}

	int Cpoker::imprimir()
	{

		if(ganador!=0)
		cout<<"el ganador es el jugador "<< ganador<<endl; 
		else cout<<"hubo un empate \n";
	}

	void Cpoker::run()
	{
		for(int i=0;i<10;i++)
		{
			this->nuevo();
			this->repartir();
			this->resultado();
			this->imprimir();

		}


	}

	int Cpoker::imprimirMazo()
	{
	//	this->MAZO.imprimirMazo();
		return 0;
	}