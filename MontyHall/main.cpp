// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <iostream>
#include <vector>

using namespace std; 
int main(int argc, char **argv)
{
	static std::random_device rd; 
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis(1, 6); 
	vector<bool>boxes(3, false);

	return 0;
}

