#!make -f

all: demo
	./$< 


	
demo:  Editor.o Document.o main.o
	clang++-5.0 -std=c++17 $^ -o demo

%.o: %.cpp Editor.hpp Document.hpp main.hpp
	clang++-5.0 -std=c++17 --compile $< -o $@

clean:
	rm -f *.o demo 
