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

#include <Cmazo.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;
	Cmazo::Cmazo()
	{
		srand(time(NULL));
		int contador=0;
		for(int i=0;i<4;i++)
		{
			for (int j = 0; j < 13; ++j)
			{
				mazo[contador].setValor(j);
				mazo[contador].setColor(i);
				auxMazo[contador].setValor(j);
				auxMazo[contador].setColor(i);
				contador++;
			}
		}

	}

	Ccarta& Cmazo::getCarta(int _P)
	{
		if(_P>=0&&_P<53)
		return mazo[_P];
		
	}

	int Cmazo::setCarta(const Ccarta& _C ,int _P)
	{
		mazo[_P].setValor(_C.getValor());
		mazo[_P].setColor(_C.getColor());
		return 0;
	}


	void Cmazo::barajar()
	{
		//system("sleep 0.5");
	
		bool movidas[52]={false};

		int random=0;
		int contador=0;
		do{
			random=rand()%51;
			if (!movidas[random])
			{
				auxMazo[contador]=mazo[random];
				contador++;
				movidas[random]=true;
			}
		} while (contador!=51);
		for (int i = 0; i < 52; ++i)
		{
			mazo[i]=auxMazo[i];
		}
	}

	void Cmazo::imprimirMazo()
	{
		cout<<"\t MAZO \n ";
		int tipo=0;
		for (int i = 0; i < 52; ++i)
		{
			tipo=mazo[i].getColor();
			if(tipo==0)
			{
				cout<<" carta "<< (i+1)<<"  = "<<mazo[i].getValor()+1<< " de Diamante";
			}
			if(tipo==1)
			{
				cout<<" carta "<< (i+1)<<" = "<<mazo[i].getValor()+1<<" de Corazon";
			}
			if(tipo==2)
			{
				cout<<" carta "<< (i+1)<<" = "<<mazo[i].getValor()+1<<" de Picas";
			}
			if(tipo==3)
			{
				cout<<" carta "<< (i+1)<<" = "<<mazo[i].getValor()+1<<" de Trebol";
			}
			cout<<endl;							
		}
		cout<<endl;
	}

	Ccarta Cmazo::sacarCarta()
	{
		Ccarta aux;
		int centinela=0;
			do{
			if(mazo[centinela].getValor()!=-1)
				{
				aux=mazo[centinela];
				mazo[centinela].eliminarCarta();
				return(aux);
				centinela=51;
				}
				centinela++;
			}while (centinela!=51);
		
	}

	int Cmazo::meterCarta(Ccarta& _aux)
	{
		for (int i = 0; i < 52; ++i)
		{
			if(mazo[i].getValor()==-1)
			{
				mazo[i]=_aux;
				return 0;
			}
		}
		return 1;
	}

	int Cmazo::llenarAuto()
	{
		int contador=0;
		for(int i=0;i<4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				mazo[contador].setCarta(i,j);
				auxMazo[contador].setCarta(i,j);
				contador++;
			}
		}
		repetidas();
		 return 0;
	}

	void Cmazo::repetidas()
	{
		int rep=0;
		for (int i = 0; i < 52; ++i)
		{
			for (int j = 0; j < 52; ++j)
			{
				if(i==j) continue;
				if(mazo[i]==mazo[j]) rep++;
			}

		}
		if(rep!=0) cout<<" ERROR hay "<<rep<<" cartas repetidas \n";
	}