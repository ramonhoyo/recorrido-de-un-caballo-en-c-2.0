CXX=g++ 
CFLAGS= -c -g 
INCLUDE= -I../include


main.exe: main.o Cconway.o 
	$(CXX) $^ -o  $@
	
main.o: main.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $<
	
Cconway.o: ../src/Cconway.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) $<
	

clean: 
	$(RM) *.exe *.o core