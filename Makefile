all:
	g++ -g main.cpp -o main
	./main
	rm -rf *o main
valgrind:
	g++ -g main.cpp -o main
	valgrind --leak-check=full -v ./main
	rm -rf *o main
clear:
	clear
