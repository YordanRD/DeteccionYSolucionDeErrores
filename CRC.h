#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

class CRC
{
public:

	string toBin(long long int num);

	long long int toDec(string bin);

	void CRCS(string dataword, string generator);


};

