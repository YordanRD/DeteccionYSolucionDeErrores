#include "ParityChecker.h"


// Esta funcion obtiene la paridad del numero n. Retorna 1
// si n tiene paridad uniforme, y retorna 0 si n tiene
// paridad impar
bool ParityChecker::getParidad(unsigned int n)
{
	bool paridad = 0;
	while (n)
	{
		paridad = !paridad;
		n = n & (n - 1);
	}
	return paridad;
}