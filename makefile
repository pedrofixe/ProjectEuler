main: main.cpp
	g++ main.cpp -o main -g -std=c++11

file: test.cpp
	g++ file.cpp -o file -g

clean:
	rm -f main
