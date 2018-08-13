all:
	g++ -std=c++0x -g main.cpp -o main
	./main
valgrind:
	g++ -g main.cpp -o main
	valgrind --leak-check=full -v ./main
	rm -rf *o main
clear:
	rm -rf *o maim
	clean
