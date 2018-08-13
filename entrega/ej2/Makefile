all:
	g++ -std=c++0x -g main.cpp -o main
	./main < input.txt
	rm -rf *o main
valgrind:
	g++ -g tests.cpp -o tests
	valgrind --leak-check=full -v ./tests
	rm -rf *o tests
clear:
	clear
