#include "CRC.h"
#include "Hamming.h"
#include "ParityChecker.h"
#include <string>

using namespace std;

Hamming hammingCode;
CRC cr7;
ParityChecker pc;

void main()
{
	// Funcion para obtener el resultado del codigo Hamming
	
	// Given input message Bit
	hammingCode.input[0] = 0;
	hammingCode.input[1] = 1;
	hammingCode.input[2] = 1;
	hammingCode.input[3] = 1;

	int N = 4;

	
	hammingCode.solve(hammingCode.input, N);

/////////////////////////////////////////////////////////////////////////////////////////////////


	//  Funcion para obtener el resultado segun la verificación de redundancia cíclica
	string pClave, Generador;
	pClave = "10011101";
	Generador = "1001";
	cr7.CRCS(pClave, Generador);

/////////////////////////////////////////////////////////////////////////////////////////////////


	// Funcion para obtener el resultado de la paridad
	unsigned int n = 7;
	cout << "Comprovacion de Paridad" << endl;
	cout << "Paridad del numero " << n << " = " << (pc.getParidad(n) ? "impar" : "uniforme");

	getchar();

}
