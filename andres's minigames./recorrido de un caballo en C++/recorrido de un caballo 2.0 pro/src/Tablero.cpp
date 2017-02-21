/*	----LICENCE------------
	
	This file is part of Recorrido de un caballo 2.0 pro.
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
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
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
	int Tablero::bestMove(int X_a,int Y_a)
	{
		int mejor=0;
		int valor=0;
			for (int i = 1; i <= 8; ++i)
			{
				aniAux.mover(i);		
				if(tablero[X_a+aniAux.getX()][Y_a+aniAux.getY()]!=0)continue;
				if(X_a+aniAux.getX()<0||X_a+aniAux.getX()>=8) continue;
				if(Y_a+aniAux.getY()<0||Y_a+aniAux.getY()>=8) continue;
				if(valor<tableroVALOR[X_a+aniAux.getX()][Y_a+aniAux.getY()])
				{
					mejor=i;
					valor=tableroVALOR[X_a+aniAux.getX()][Y_a+aniAux.getY()];
				}				
			}
		return(mejor);
	}

	void Tablero::run()
	{
		srand(time(NULL));
		int _X=rand()%7;
		int _Y=rand()%7;
		int mejor=0;
		do
		{			
		
			tablero[_X][_Y]=contador++;
			system("clear");
			imprimir(); 
			cout<<"\t"<<contador-1<<endl;
			system("sleep 1");	

			mejor=bestMove(_X,_Y);
			if(mejor==0) contador=64;
			ani.mover(mejor);
			if(!esValida(_X,_Y))contador =64;		
			_X=(ani.getX())+_X;
			_Y=(ani.getY())+_Y;
			
		} while (contador!=64);

	}
