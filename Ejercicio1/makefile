make:
	g++ Ejercicio1.cpp -o ej1
	valgrind -s --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes ./ej1
	rm ej1