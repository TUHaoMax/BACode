Output: main.o  test.o
           g++  main.o  test.o  -o  output
main.o: main.cpp
            g++ -c main.cpp
test.o: test.cpp test.h
           g++ -c test.cpp 
clean: 
            rm *.o output
