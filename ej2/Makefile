all:
	g++ -std=c++0x -g main.cpp -o tests
	./tests < t1.txt
	rm -rf *o tests
valgrind:
	g++ -g tests.cpp -o tests
	valgrind --leak-check=full -v ./tests
	rm -rf *o tests
clear:
	clear
