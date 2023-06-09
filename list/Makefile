OBJ = doublyLinkedList.o type.o lists.o appFunctions.o 

Web-list: $(OBJ)
	g++ -o ../build/$@ $^
	
-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cpp > dependencies
clean:
	rm -f *.o 
cleanall:
	rm -f Web-list *.o 
 