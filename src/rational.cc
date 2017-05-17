#include "FractionMaker.h"

rational::rational(ulli numerator, ulli denominator, sign s) : numerator(numerator), denominator(denominator), signum(s){}

rational::rational(const rational& original){

	this->numerator = original.numerator;			//tuple = operator
	this->denominator = original.denominator;
	this->signum = original.signum;
}

rational::~rational(){}

void swap(rational& first, rational& second){

	using std::swap;		//enables ADL

	swap(first.numerator,second.numerator);
	swap(first.denominator,second.denominator);
	swap(first.signum, second.signum);
	return;
}

ulli rational::GetNumerator(){ return numerator;}

ulli rational::GetDenominator(){ return denominator;}

int rational::GetSign(){ 

	if (signum == sign::p) return 1;
	return -1;
}

void rational::SetNumerator(ulli numerator){

	this->numerator = numerator;
	return; 
}

void rational::SetDenominator(ulli denominator){

	this->denominator = denominator;
	return;
}

void rational::SetSign(sign s){ 

	this->signum = s;
	return;
}

void rational::Simplify(){

	//take the smaller number's sqrt to check for factors, because it won't have any beyond that and it hardly matters if
	//the larger number does
	ulli newnumerator = this->numerator;
	ulli newdenominator = this->denominator;
	ulli limit = (newnumerator < newdenominator) ? (ulli)sqrt(newnumerator) : (ulli)sqrt(newdenominator);

	ulli factor = 2ULL;
	for(;;){

		//while they keep being divisible by factor, they keep getting reduced by it
		if (newnumerator % factor == 0 && newdenominator % factor == 0){

			newnumerator /= factor;
			newdenominator /= factor;
			limit = (newnumerator < newdenominator) ? (ulli)sqrt(newnumerator) : (ulli)sqrt(newdenominator);
			continue;
		}

		if (factor > limit) break;
		
		if (factor == 2ULL){
			factor++;
			continue;
		}
								//after the 2s are taken care of we will try only odd numbers
		factor += 2;			//not ideal but without storing primes I can't go directly to the next prime
	}

	this->numerator = newnumerator;
	this->denominator = newdenominator;

	return;
}

void rational::Invert(){

	ulli old_numerator = numerator;

	numerator = denominator;
	denominator = old_numerator;

	return;
}

void rational::Negate(){

	if (signum == sign::p){

		signum = sign::n;
		return;
	}

	signum = sign::p;
	return;
}

rational& rational::operator=(const rational rhs){

	swap(*this, rhs);			//omission of self-check is due to infrequency of occurance
	return *this; 
}

rational rational::operator+(const rational& second){

	rational new_rational;

	new_rational.numerator = 
}
rational rational::operator-(const rational&)
rational rational::operator*(const rational&)
rational rational::operator/(const rational&)

rational rational::operator+=(const rational&)
rational rational::operator-=(const rational&)
rational rational::operator*=(const rational&)
rational rational::operator/=(const rational&)