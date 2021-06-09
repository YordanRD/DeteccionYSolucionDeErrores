#pragma once
class Hamming
{
public:

	// Store input bits
	int input[32];

	// Store hamming code
	int code[32];

	int ham_calc(int, int);
	void solve(int input[], int);
};

