OBJ = main.o type.o list.o 

invertedIndex: $(OBJ)
	g++ -o ../build/$@ $^

-include dependencies

.PHONY: clean cleanall

depend:
	g++ -MM *.cpp > dependencies

clean:
	rm -rf *.o 
cleanall:
	rm -rf invertedIndex *.o 
