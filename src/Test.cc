#include <iostream>
#include <vector>
#include <cmath>

#include "FractionMaker.h"

int main(){

	FractionMaker testfrac;
	testfrac.ConvertToFraction(sqrtl(988.0l), 160);
	testfrac.PruneSequence();	//argument gives copies of period

	std::vector<int> result;
	testfrac.CopySequence(result);

	std::cout << "\n";

	for (int i=0; i<result.size(); i++){

		std::cout << result[i] << "\t";
	}

	std::cout << "\n";

	return 0;
}

//Start to finished and working, this took me about an hour
//Poor performance over about 2 periods for long periods >~12, large rounding errors
//If I could prove the 2ao rule it would suffice to do one period's worth
//Perhaps it would be worth creating a rational number type and implementing my own square root operation
//to interact with it rather that using floating point arithmetic?