make:
	g++ Ejercicio2.cpp -o ej2
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./ej2
	rm ej2