#include "CRC.h"

using namespace std;

// Funcion para convertir un integer a un string binario
string CRC::toBin(long long int num) {
	string bin = "";
	while (num) {
		if (num & 1)
			bin = "1" + bin;
		else
			bin = "0" + bin;
		num = num >> 1;
	}
	return bin;
}

// Funcion para convertir un string binario a un decimal
long long int CRC::toDec(string bin) {
	long long int num = 0;
	for (int i = 0; i < bin.length(); i++) {
		if (bin.at(i) == '1')
			num += 1 << (bin.length() - i - 1);
	}
	return num;
}

// Funcion para computar CRC y la palabra clave
void CRC::CRCS(string dataword, string generator) {
	int l_gen = generator.length();
	long long int gen = toDec(generator);

	long long int dword = toDec(dataword);

	// Añadir 0s al dividendo
	long long int dividend = dword << (l_gen - 1);

	// shft specifies the no. of least
	// bits significantes no siendo XOR
	int shft = (int)ceill(log2l(dividend + 1)) - l_gen;
	long long int rem;

	while ((dividend >= gen) || (shft >= 0)) {

		// XOR de bit a bit del MSBs del dividendo con el generador
		// reemplazando el MSBs operado del dividendo con
		// el recordatorio generado
		rem = (dividend >> shft) ^ gen;
		dividend = (dividend & ((1 << shft) - 1)) | (rem << shft);

		// cambia la variable shft 
		shft = (int)ceill(log2l(dividend + 1)) - l_gen;
	}

	// y el dividendo original con el recordatorio (=dividend)
	long long int codeword = (dword << (l_gen - 1)) | dividend;

	cout << "Verificación de redundancia cíclica" << endl;
	cout << "Recordatorio: " << toBin(dividend) << endl;
	cout << "Palabra Clave : " << toBin(codeword) << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}