OBJ = main.o tree.o string.o coda-bfs.o

Tree: $(OBJ)
	g++ -o ../build/$@ $^

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cpp > dependencies

clean:
	rm -f *.o 

cleanall:
	rm -f Tree *.o 