make:
	g++ Ejercicio3.cpp -o ej3
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./ej3
	rm ej3