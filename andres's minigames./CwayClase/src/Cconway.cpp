#include <Cconway.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
	Cconway::Cconway()
	{
		srand(time(NULL));
		tablero[TAMV][TAMH]=0;
		int ran=0;
		int i=0;
		int j=0;
		
		for (i=0; i < TAMV; ++i)
		{
			for (j=0; j < TAMH; ++j)
			{
			


				ran=rand()%(TAMH*TAMV);
				if(ran<=((TAMV*TAMH)/1.5)) tablero[i][j]=1;
				else tablero[i][j]=0;
			}
		}
		for (i = 0; i < TAMV; ++i)
		{
			for (j = 0; j < TAMH; ++j)
			{
				aux[i][j]=0;
			}
		}

		vecinos=0;
		CEN=0;
	}

	void Cconway::run()
	{
		int i=0;
		int j=0;
		
		for(;;){		
			system("clear");
			imprimir();
			for ( i = 0; i <TAMV; i++)
			{
				for ( j = 0; j < TAMH; j++)
				{	

				vecinos=0;		
				CEN=0;	

					if( (i-1<0 || j-1<0) &&CEN==0){
					
					CEN=1;
						if( (i-1<0) && (j-1<0) ){
							if(tablero[i][j+1]) vecinos++;
							if(tablero[i+1][j]) vecinos++;
							if(tablero[i+1][j+1]) vecinos++;							
							reglas(i,j);							
						}

						if(((i-1)<0) && ((j+1)==TAMH)){
							if(tablero[i][j-1]) vecinos++;
							if(tablero[i+1][j-1]) vecinos++;
							if(tablero[i+1][j]) vecinos++;							
							reglas(i,j);
						}
						
						if(((i+1)==TAMV) &&  ((j-1)<0)){
							if(tablero[i][j+1]) vecinos++;
							if(tablero[i-1][j]) vecinos++;
							if(tablero[i-1][j+1]) vecinos++;							
							reglas(i,j);
		
						}
						if(((i-1)<0) && ((j-1)>=0) &&j+1<=TAMH){
							if(tablero[i][j+1]) vecinos++;
							if(tablero[i][j-1]) vecinos++;
							if(tablero[i+1][j]) vecinos++;
							if(tablero[i+1][j+1]) vecinos++;
							if(tablero[i+1][j-1]) vecinos++;														
							reglas(i,j);
				
						}	
						if(((i-1)>=0) && ((j-1)<0) && i+1<=TAMV){
							if(tablero[i][j+1]) vecinos++;
							if(tablero[i-1][j]) vecinos++;
							if(tablero[i-1][j+1]) vecinos++;
							if(tablero[i+1][j]) vecinos++;
							if(tablero[i+1][j+1]) vecinos++;														
							reglas(i,j);
						}					
												
					}
									
					if(((i+1==TAMV) || j+1 ==TAMH) &&CEN==0){
					CEN=1;
						if(((i-1)<0) && ((j+1)==TAMH)){
							if(tablero[i][j-1]) vecinos++;
							if(tablero[i+1][j]) vecinos++;
							if(tablero[i+1][j-1]) vecinos++;							
							reglas(i,j);
						}
						
						if(((i+1)==TAMV) && ((j+1)==TAMH)){
							if(tablero[i][j-1]) vecinos++;
							if(tablero[i-1][j]) vecinos++;
							if(tablero[i-1][j-1]) vecinos++;							
							reglas(i,j);					

						}
						if(((i+1)==TAMV) && ((j-1)<0)){
							if(tablero[i][j+1]) vecinos++;
							if(tablero[i-1][j]) vecinos++;
							if(tablero[i-1][j+1]) vecinos++;							
							reglas(i,j);
						}
												
						if(((i+1)==TAMV) && ((j+1)<=TAMH) && j-1>=0){
							if(tablero[i][j+1]) vecinos++;
							if(tablero[i-1][j]) vecinos++;
							if(tablero[i-1][j+1]) vecinos++;
							if(tablero[i-1][j-1]) vecinos++;
							if(tablero[i][j-1]) vecinos++;							
							reglas(i,j);
						}
						if(((i+1)<=TAMV) && ((j+1)==TAMH) && i-1>=0){
							if(tablero[i][j-1]) vecinos++;
							if(tablero[i-1][j]) vecinos++;
							if(tablero[i-1][j-1]) vecinos++;
							if(tablero[i+1][j-1]) vecinos++;
							if(tablero[i+1][j]) vecinos++;							
							reglas(i,j);
						}
					}	
					
					if(CEN==0){
						
							if(tablero[i][j-1]) vecinos++;
							if(tablero[i-1][j]) vecinos++;
							if(tablero[i-1][j-1]) vecinos++;
							if(tablero[i+1][j-1]) vecinos++;
							if(tablero[i+1][j]) vecinos++;
							if(tablero[i+1][j+1]) vecinos++;
							if(tablero[i][j+1]) vecinos++;
							if(tablero[i-1][j+1]) vecinos++;
							
							reglas(i,j);


					}

				}						
			
			}
					for ( i = 0; i < TAMV; ++i)
					{
						for ( j = 0; j < TAMH; ++j)
						{
							tablero[i][j]=aux[i][j];
						}
					}	
			system("sleep 0.1");
			
			imprimir();	

		}

	}
	
	void Cconway::reglas(int i,int j)
	{
		if(tablero[i][j]==1){
			if((vecinos==2||vecinos==3)){aux[i][j]=1;}
			else aux[i][j]=0;
		}
							
		if(tablero[i][j]==0){
			if(vecinos==3) aux[i][j]=1;			
		}
	}

	void Cconway::imprimir()
	{
		for( int i=0;i<TAMV;i++){
			for(int j=0;j<TAMH;j++){
				if(tablero[i][j]) cout<<"@";
				else cout<<" ";
			}
			cout<<"\n";		
		}
	}



