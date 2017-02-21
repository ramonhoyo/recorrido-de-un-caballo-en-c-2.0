CXX= g++ -std=c++11
CFLAGS=-c -g
DIRIN= -I../include/


main.exe: main.o Caballo.o Tablero.o
	$(CXX) $^ -o $@
main.o : main.cpp
	$(CXX) $(CFLAGS) $(DIRIN) $<
Caballo.o : ../src/Caballo.cpp
	$(CXX) $(CFLAGS) $(DIRIN) $<
Tablero.o : ../src/Tablero.cpp
	$(CXX) $(CFLAGS) $(DIRIN) $<

clean:
	$(RM) *.exe *.o core