/*	----LICENCE------------
	
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

#include <Tablero.h>
#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;

Tablero::Tablero()
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				tablero[i][j]=0;
			}
		}		
		contador=1;		
	}

	void Tablero::imprimir()
	{
		int i,j;
		for ( i = 0; i < 8; ++i)
		{
			for ( j = 0; j < 8; ++j)
			{
				cout<<"-"<<tablero[i][j]<<"-";
			}
			cout<<"\n";
		}	
	}

	bool Tablero::esValida(int TX,int TY)
	{
		int si=0;
		if(ani.getX()+TX<0||ani.getX()+TX>=8) si++;
		if(ani.getY()+TY<0||ani.getY()+TY>=8) si++;
		if(tablero[ani.getX()+TX][ani.getY()+TY]!=0) si++;
		if(si==0) return true;
		else return false;
	}

	void Tablero::run()
	{
		srand(time(NULL));
		int _X=rand()%7;
		int _Y=rand()%7;
		int move=0;
		int max=0;

		do
		{			
			system("clear");
			imprimir(); 
			cout<<"\t"<<contador-1<<endl;
			system("sleep 1");	
			max=0;
			do{
				max++;
				move=1+rand()%8;
				ani.mover(move);
			} while (!esValida(_X,_Y));
			_X=(ani.getX())+_X;
			_Y=(ani.getY())+_Y;
			tablero[_X][_Y]=contador++;
		} while (contador!=64);
	}
