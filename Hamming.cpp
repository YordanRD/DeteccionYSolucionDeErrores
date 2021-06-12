#include "Hamming.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;
// Funcion para calcular el bit por
// posicion i
int Hamming::ham_calc(int position, int c_l)
{
	int count = 0, i, j;
	i = position - 1;

	//	Atravesar para almacenar el código de Hamming

	while (i < c_l) {

		for (j = i; j < i + position; j++) {

			// Si el acutual bit es 1
			if (code[j] == 1)
				count++;
		}

		// Actualizar i
		i = i + 2 * position;
	}

	if (count % 2 == 0)
		return 0;
	else
		return 1;
}

// Funcion para calcular el codigo Hamming
void Hamming::solve(int input[], int n)
{
	int i, p_n = 0, c_l, j, k;
	i = 0;

	// Encontrar los bits del mensaje teniendo un set bit
	// en la posicion x del numero
	while (n > (int)pow(2, i) - (i + 1)) {
		p_n++;
		i++;
	}

	c_l = p_n + n;

	j = k = 0;

	// Atravesar los msgBits
	for (i = 0; i < c_l; i++) {

		// Actualizar el codigo
		if (i == ((int)pow(2, k) - 1)) {
			code[i] = 0;
			k++;
		}

		// Actualizar el codigo[i] de
		// la entrada de caracter en la posicion j
		else {
			code[i] = input[j];
			j++;
		}
	}

	// Atravezar y actualizar el
	// Codigo Hamming
	for (i = 0; i < p_n; i++) {

		// Encontrar la posicion actual
		int position = (int)pow(2, i);

		// Encontrar el valor de la posicion actual
		int value = ham_calc(position, c_l);

		// Actualizar el codigo
		code[position - 1] = value;
	}

	// Mostrar el resultado
	printf("\nHammingCode");
	printf("\nThe generated Code Word is: ");
	
	for (i = 0; i < c_l; i++) {
		printf("%d", code[i]);
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}