mem: memory.o driver.o
	g++ memory.o driver.o -o prog

memory.o: memory.cpp
	g++ -g -c memory.cpp

driver.o: driver.cpp
	g++ -g -c driver.cpp


clean:
	rm *.o mem
	

 
