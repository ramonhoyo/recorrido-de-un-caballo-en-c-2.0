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

#include <Cmano.h>
#include <iostream>
using namespace std;
	Cmano::Cmano()
	{
		puntaje=0;
		cartaAlta=-1;
		cartaBaja=-1;
		Ccarta aux;

		aux.eliminarCarta();
		juego[5]={aux};
		maxJugada=-1;
	}

	Cmano::Cmano(Ccarta _1,Ccarta _2,Ccarta _3,Ccarta _4,Ccarta _5)
	{
		juego[0]=_1;
		juego[1]=_2;
		juego[2]=_3;
		juego[3]=_4;
		juego[4]=_5;
		cartaAlta=-1;
		cartaBaja=-1;
		puntaje=0;
	}

	bool Cmano::escaleraReal()
	{
		int contador=0;
		int contador2=0;
		bool as=false;

		for (int i = 0; i < 5; ++i)
		{
			contador2+=juego[i].getValor();
			if(juego[i].getValor()==0&&juego[i].getColor()==1) as=true;
			if(juego[i].getColor()==1) contador++;
		}
		if(contador2!=42||!as||contador!=5) return false;
		else return true;
	}

	bool Cmano::escaleraColor()
	{
		int contColor=0;
		int contValor=0;
		for (int i = 0; i < 5; ++i)
		{
			contValor+=juego[i].getValor();			
			if(juego[0].getColor()==juego[i].getColor()) contColor++;		
			
		}
		if(contColor!=5) return false;
		if(contValor==42&&contColor==5) return true;
		if((getCartaAlta()-getCartaBaja()==4)&&contColor==5) return true;

		return false;
	}


	bool Cmano::poker()
	{
		int contVeces=0;
		int max=0;
		for (int i = 0; i < 5; ++i)
		{	contVeces=0;
			for (int j = 0; j < 5; ++j)
			{
				if(j==i) continue;
				if(juego[i].getValor()==juego[j].getValor()) contVeces++;
			}
			if(contVeces==4){
				max=juego[i].getValor();
				return true;
			}
		}
		return false;
	}

	bool Cmano::full()
	{
		bool trio=false;
		bool par=false;
		int valor1=-1,valor2=-1;
		int veces=0;

		for (int i = 0; i < 5; ++i)
		{
			if(trio&&par) return true;
			valor1=juego[i].getValor();
			veces=0;
			for (int j = 0; j < 5; ++j)
			{
				if(j==i) continue;
				if(valor1==juego[j].getValor()) veces++;
			}
				if(veces==2) trio=true;
				if(veces==1) par=true;
				if(veces==0) return false;
		}
		return false;
	}

	bool Cmano::color()
	{
		int color=0;	
		
		for (int j = 0; j < 5; ++j)
		{
			if(juego[0].getColor()!=juego[j].getColor()) return false;
			else color++;
		}
		return true;		
	}

	bool Cmano::escalera()
	{
		int contador=0;
		for (int i = 0; i < 5; ++i)
		{
			contador+=juego[i].getValor();
		}
		if(contador==42) return true;
		if((getCartaBaja()*5)+10==contador){
			maxJugada=getCartaAlta();
			return true;
		}


		return false;
	}

	bool Cmano::trio()
	{
		bool trio;
		int valor1=0;
		int veces=0;
		for (int i = 0; i < 5; ++i)
		{

			valor1=juego[i].getValor();
			veces=0;
			for (int j = 0; j < 5; ++j)
			{
				if(j==i) continue;
				if(valor1==juego[j].getValor()) veces++;
			}
				if(veces==2) {
					trio=true;
				}
				if(trio){
					maxJugada=juego[i].getValor();
				 return true;
				}
		}
		return false;
	}

	bool Cmano::doblepar()
	{
		bool par1=false,par2=false;
		int valor1=0;
		int veces=0;
		int max=-1;
		int ceninela=0;
		int yaExiste=-1;

		for (int i = 0; i < 5; ++i)
		{	
			veces=0;
			valor1=juego[i].getValor();	
			for (int j = 0; j < 5; ++j)
			{
				ceninela=0;
				if(i==j)continue;
				if(valor1==juego[j].getValor() ) 
				{
					if(max<juego[i].getValor()) max=juego[i].getValor();
					if(yaExiste!=juego[i].getValor())
					{
						veces++;
						if(yaExiste==-1)
						yaExiste=juego[i].getValor();
					}
				}				
			}
			if((veces==1)&&(!par1))
			{
			 par1=true;
			 ceninela=1;
			}
			if(ceninela==1)continue;
			if((par1)&&(!par2)&&(veces==1))
			{
				par2=true;				
			}
			
			if(par1&&par2)
			{
				maxJugada=max;
				return true;
			}
		}
		return false;
	}

	bool Cmano::par()
	{
		bool par1=false;;
		int valor1=0;
		int veces=0;
		int max=-1;

		for (int i = 0; i < 5; ++i)
		{	
			veces=0;
			valor1=juego[i].getValor();	
			for (int j = 0; j < 5; ++j)
			{
				if(i==j)continue;
				if(valor1==juego[j].getValor() ) 
				{
					if(max<juego[i].getValor()) max=juego[i].getValor();
					return true;
				}				
			}
		}
		return false;
	}

	int Cmano::calcularCartaAlta()
	{
		int max=-1;
		for (int i = 0; i < 5; ++i)
		{
			if(max<juego[i].getValor()) max=juego[i].getValor();
		}
		cartaAlta=max;
	}

	int Cmano::calcularCartaBaja()
	{
		int min=13;
		for (int i = 0; i < 5; ++i)
		{
			if(juego[i].getValor()<min) min=juego[i].getValor();
			
		}
		cartaBaja=min;
		return 0;
	}

	int Cmano::setJuego(Ccarta _1,Ccarta _2,Ccarta _3,Ccarta _4,Ccarta _5)
	{
		juego[0]=_1;
		juego[1]=_2;
		juego[2]=_3;
		juego[3]=_4;
		juego[4]=_5;
		calcularCartaBaja();
		calcularCartaAlta();
		puntaje=-1;
		maxJugada=-1;
	}

	int Cmano::calculaPuntaje()
	{

		if(escaleraReal()) {puntaje=10000; return 0;}
		if(escaleraColor()) {puntaje=7000; return 0;}
		if(poker()) {puntaje=5000; return 0;}
		if(color()) {puntaje=2500; return 0;}
		if(full()) {puntaje=2000 ;return 0;}
		if(escalera()) {puntaje=500; return 0;}
		if(trio()) {puntaje=300; return 0;}
		if(doblepar()) {puntaje=100; return 0;}
		if(par()) {puntaje=50; return 0;}
		puntaje=getCartaAlta();
		return 0;
	}

	int Cmano::getPuntaje()
	{	
		calculaPuntaje();
		return puntaje;
	}

	int Cmano::getCartaAlta()
	{
		calcularCartaAlta();
		return cartaAlta;
	}

	int Cmano::getCartaBaja()
	{
		calcularCartaBaja();
		return cartaBaja;
	}

	void Cmano::imprimirMano()
	{

			cout<<"\t Mano \n ";
			Ccarta aux;
			for (int i = 0; i < 5; ++i)
			{
				aux=getCarataDeMano(i);
				if(aux.getColor()==0)
				cout<<" "<< aux.getValor()+1<<" de Dimantes,";
				if(aux.getColor()==1)
				cout<<" "<< aux.getValor()+1<<" de Corazones,";
				if(aux.getColor()==2)
				cout<<" "<< aux.getValor()+1<<" de picas,";
				if(aux.getColor()==3)
				cout<<" "<< aux.getValor()+1<<" de trebol.";
			}
		cout<<endl;
		cout<<" cartaBaja = "<<getCartaBaja()+1<<"   ,";
		cout<<"cartaAlta = "<<getCartaAlta()+1<< endl;

	}


	Ccarta& Cmano::getCarataDeMano(int _p)
	{
		return (juego[_p]);
	}