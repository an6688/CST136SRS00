// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <random>
#include <iostream>
#include <vector>
#include "LetsMakeADeal.h"
#include <sstream>
#include "gsl.h"
using namespace std; 

namespace // unnamed 
{
	enum class Strategy { kUnknown, kSwitch, kStay }; // 'k' lets you use switch 

	void userHelp()
	{
		cout <<
			"MontyHall Help \n"
			"-----\n"
			"Example: MontyHall 1 stay 3 1\n"
			"\n"
			"Usage: MontyHall trials strategy doors disclose\n"
			"trials: The number of times to run the simulation.\n"
			"strategy: stay | switch.\n"
			"doors: The number of doors in the simulation.\n"
			"disclose: The number of doors to be disclosed in the simulation.\n"
			"Note: disclose < doors.\n";
	}

	Strategy parseStrategy(std::string const strategyParam)
	{
		Strategy result = Strategy::kUnknown;
		if (strategyParam == "stay")
		{
			result = Strategy::kStay;
		}
		else if (strategyParam == "switch")
		{
			result = Strategy::kSwitch; 
		}
		return result; 
	}
}

int main(int argc, char *argv[])
{
	constexpr auto kTrialsIndex{ 1 }; 
	constexpr auto kStrategyIndex{ 2 };
	constexpr auto kDoorsIndex{ 3 };
	constexpr auto kDiscloseIndex{ 4 };


	// default parameters
	size_t doors{ 3 }; 
	size_t disclose{ 1 }; 
	size_t trials{ 0 }; 
	Strategy strategy { Strategy::kUnknown};
	// calculate probability 
	if (argc>=3 && argc < 6)
	{
		istringstream iss;
		int tmp{ };

		iss.clear();
		iss.str(argv[kTrialsIndex]);
		tmp = trials;
		iss >> tmp; 
		if (iss.eof())
		{
			trials = tmp; 
		} 

		strategy = parseStrategy(argv[kStrategyIndex]);

		iss.clear();
		iss.str(argv[kDoorsIndex]);
		tmp = doors;
		iss >> tmp;
		if (iss.eof())
		{
			doors = tmp;
		}

		iss.clear();
		iss.str(argv[kDiscloseIndex]);
		tmp = disclose;
		iss >> tmp;
		if (iss.eof())
		{
			disclose = tmp;
		}
	}

	if (disclose >= doors || (strategy != Strategy::kSwitch && strategy != Strategy::kStay) || doors<2 || trials <1 || disclose<0)
	{
		userHelp();
	}
	else
	{
		// TODO: run simuluation 
	}
	return 0;
}

