OBJ = main.o graph.o coda-bfs.o

graph: $(OBJ)
	g++ -o ../build/$@ $^

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cpp > dependencies
clean:
	rm -f *.o 
cleanall:
	rm -f graph *.o 
	