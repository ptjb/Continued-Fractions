#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cmath>
#include <utility>

//enum class sign : std::bitset {p,n};
enum class sign {p,n};		//by default, underlying type is int

class rational{

	typedef unsigned long long int ulli;

	/*ulli numerator;
	ulli denominator;
	sign signum;
	*/
			// p or n for positive or and negative																
	
	public:
		
		ulli numerator;
		ulli denominator;
		sign signum;

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
		rational(ulli, ulli denominator = 1ULL, sign s = sign::p);	//overload a different time
		rational(const rational&);	//copy constructor
		~rational();

		friend void swap(rational&,rational&);

		/*friend void Test_Constructor();
		friend void Test_Copy_Constructor();
		*/
		
		ulli GetNumerator();
		ulli GetDenominator();
		int GetSign();

		void SetNumerator(ulli);
		void SetDenominator(ulli);
		void SetSign(sign);

		void Simplify();
		void Invert();
		void Negate();

		//limiting to integers for now
		void SquareRoot(int sig_fig = 10);		//square-roots itself

		//operators will simplify after use (maybe a performance hit but we'll see)
		rational& operator=(const rational);		//reference return allows chaining. Using copy-swap idiom
		rational operator+(const rational&);
		rational operator-(const rational&);
		rational operator*(const rational&);
		rational operator/(const rational&);

		rational& operator+=(const rational);
		rational& operator-=(const rational);
		rational& operator*=(const rational);
		rational& operator/=(const rational);

		//you will manage without the relational operators for now



	/*private:
		void ManageSigns();		//handle negatives properly
	*/
};

#endif