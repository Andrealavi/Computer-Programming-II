OBJ = dijkstra.o graph.o codap.o

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
	