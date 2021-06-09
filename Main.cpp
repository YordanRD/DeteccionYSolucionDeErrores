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
	// Given input message Bit
	hammingCode.input[0] = 0;
	hammingCode.input[1] = 1;
	hammingCode.input[2] = 1;
	hammingCode.input[3] = 1;

	int N = 4;

	// Function Call
	hammingCode.solve(hammingCode.input, N);

	string dataword, generator;

	dataword = "10011101";
	generator = "1001";
	cr7.CRCS(dataword, generator);


	
	unsigned int n = 7;
	cout << "Parity Checker" << endl;
	cout << "Parity of no " << n << " = " << (pc.getParity(n) ? "odd" : "even");

	getchar();

}
