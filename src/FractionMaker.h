#ifndef FRACTIONMAKER_H
#define FRACTIONMAKER_H

#include <iostream>
#include <vector>
#include <cmath>

class FractionMaker{

	std::vector<int> sequence;
	long double residue;

	public:
		FractionMaker();
		FractionMaker(long double);
		~FractionMaker();
		void ConvertToFraction(long double,int);
		void PruneSequence();
		void PruneSequence(int);
		void CopySequence(std::vector<int>&);

	private:
		void NextTerm(long double&);
		int MeasurePeriod();	//assuming that the 2ao rule is correct
		void TruncateValues(int,int copies = 1);
};

#endif