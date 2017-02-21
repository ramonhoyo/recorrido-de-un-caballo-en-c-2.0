#ifndef CCONWAY_H
#define CCONWAY_H

const int TAMV=27;
const int TAMH=110;

	class Cconway
	{
		int tablero[TAMV][TAMH];
		int aux[TAMV][TAMH];
		int vecinos;
		int CEN;

		void reglas(int,int);
		void imprimir();

	public:
		Cconway();
		~Cconway(){};

		void run();
		
	};
#endif
