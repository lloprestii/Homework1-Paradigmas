make:
	g++ Ejercicio4.cpp -o ej4
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./ej4
	rm ej4