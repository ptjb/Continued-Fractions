#ifndef FRACTIONMAKER_H
#define FRACTIONMAKER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <utility>

//enum class sign : std::bitset {p,n};
enum class sign {p,n};		//by default, underlying type is int

class rational{

	typedef unsigned long long int ulli;

	ulli numerator;
	ulli denominator;
	sign signum;
			// p or n for positive or and negative																
	
	public:
		//REQUIRED:
		//
		//Constructor
		//Destructor
		//Copy Constructor
		//
		//Function to put in Simplest Form
		//Function to Invert
		//Function to Negate
		//Function to return the numerator
		//Function to return the denominator
		//+ operator (for other Rationals and with ints (don't worry about doubles for now))
		//- operators		//be sure to handle the signs properly so you don't accidentally make things negative
		//* operators		//get operators to handle signs themselves
		// / operator
		//= operator
		//assignment operators for each
		//
		//nth root
		//Test Suite for class, to be implemented in a test programme

		//not bothered about move-constructor right now
		rational(ulli, ulli, sign s = sign::p);	//overload a different time
		rational(const rational&);	//copy constructor
		~rational();

		friend void swap(rational&,rational&);

		ulli GetNumerator();
		ulli GetDenominator();
		int GetSign();

		void SetNumerator(ulli);
		void SetDenominator(ulli);
		void SetSign(sign);

		void Simplify();
		void Invert();
		void Negate();

		rational& operator=(const rational);		//reference return allows chaining. Using copy-swap idiom
		rational operator+(const rational&);
		rational operator-(const rational&);
		rational operator*(const rational&);
		rational operator/(const rational&);

		rational operator+=(const rational&);
		rational operator-=(const rational&);
		rational operator*=(const rational&);
		rational operator/=(const rational&);

		//you will manage without the relational operators for now

	/*private:
		void ManageSigns();		//handle negatives properly
	*/
};

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