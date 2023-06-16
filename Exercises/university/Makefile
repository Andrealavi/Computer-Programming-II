OBJ = main.o type.o tree.o

University: $(OBJ)
	g++ -o ../../build/$@ $^

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cpp > dependencies

clean:
	rm -rf *.o 

cleanall:
	rm -rf University *.o
