CXX=g++ -std=c++11
CFLAGS= -c -g 
INCLUDE= -I../include


main.exe: main.o Cpoker.o Cmazo.o Cjugador.o Ccarta.o Cmano.o
	$(CXX) $^ -o  $@
	
main.o: main.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $<
	
Cpoker.o: ../src/Cpoker.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $<
	
Cmazo.o: ../src/Cmazo.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $<

Cjugador.o: ../src/Cjugador.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $<		

Ccarta.o: ../src/Ccarta.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $<

Cmano.o: ../src/Cmano.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $<		


clean:
	$(RM) *.o *.exe core
	