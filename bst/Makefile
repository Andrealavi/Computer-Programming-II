OBJ = main.o bst.o string.o key.o 

bst: $(OBJ)
	g++ -o ../build/$@ $^

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cpp > dependencies

clean:
	rm -f *.o 
cleanall:
	rm -f bst *.o


