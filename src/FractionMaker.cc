#include "FractionMaker.h"

FractionMaker::FractionMaker(){}

FractionMaker::FractionMaker(long double init_val) : residue(init_val){}

FractionMaker::~FractionMaker(){}

void FractionMaker::ConvertToFraction(long double init_val, int num_terms){

	residue = init_val;

	for (int i=0; i<num_terms; i++) this->NextTerm(residue);
	
	return;
}

void FractionMaker::PruneSequence(){

	int period = this->MeasurePeriod();
	this->TruncateValues(period);
	return;
}

void FractionMaker::PruneSequence(int copies){

	int period = this->MeasurePeriod();
	this->TruncateValues(period, copies);
	return;
}

void FractionMaker::CopySequence(std::vector<int>& vessel){

	vessel = this->sequence;
	return;
}

void FractionMaker::NextTerm(long double& value){

	long double term;
	value = modfl(value, &term);		//term now points to the location of the integral part of the float

	sequence.push_back((int)term);
	value = 1.0l/value;

	return;
}

int FractionMaker::MeasurePeriod(){		//remember, the 0th element of sequence should be ignored as it is the 
										//integral part of the number
	int count = 0;
	for (int i=1; i<sequence.size(); i++){

		count++;
		if (sequence[i] == 2*sequence[0]) break;
	}

	return count;
}

void FractionMaker::TruncateValues(int period, int copies){

	sequence.erase(sequence.begin()+(copies*period)+1, sequence.end());
	return;

}