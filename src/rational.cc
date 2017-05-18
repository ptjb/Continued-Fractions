#include "rational.h"

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

	//defines the convention were 0 is (0,1,p)
	if (newnumerator == 0){

		this->denominator = 1ULL;
		this->signum = sign::p;
		return;
	}

	//deals with +-x/x case before slogging through
	if (newnumerator == newdenominator){

		this->numerator = 1ULL;
		this->denominator = 1ULL;
		return;
	}

	//THIS TEST IS FOR PRIMES. THIS WILL NOT PICK UP 17/17 for example
	//I do think that now the 1/1 case has been dealt with, this should still work
	ulli limit = (newnumerator < newdenominator) ? (ulli)sqrt(newnumerator) : (ulli)sqrt(newdenominator);

	//ulli limit = (newnumerator < newdenominator) ? (ulli)newnumerator : (ulli)newdenominator;

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

void rational::SquareRoot(int sig_fig){

	if (this->denominator != 1){

		std::cout << "NthRoots for non-naturals is not supported at this time" << std::endl;
		return;
	}

	//this gets the integral part of what the double result is, providing the first guess
	ulli temp_numerator = (ulli)sqrt(this->numerator); 	
	ulli temp_denominator = 1ULL;

	ulli size_limit = 1ULL;

	for (int i = 0; i < sig_fig; i++){

		size_limit *= 10ULL;
	}

	while (temp_numerator < size_limit){

		temp_numerator = temp_numerator*temp_numerator*(this->denominator)
							+ temp_denominator*temp_denominator*(this->numerator);
		temp_denominator = temp_numerator*temp_denominator*(this->denominator);
	}

	this->numerator = temp_numerator;
	this->denominator = temp_denominator;
	
	return;
}


rational& rational::operator=(const rational rhs){		//const in argument to allow temporary object passing

	swap(*this, rhs);			//omission of self-check is due to infrequency of occurance
	return *this; 
}

rational rational::operator+(const rational& second){

	rational new_rational;

	//same in all cases
	new_rational.denominator = this->denominator * second.denominator;

	if (this->signum == second.signum){		//the sign of new_rational should match that of each rational

		new_rational.numerator = (this->numerator * second.denominator) + (this->denominator * second.numerator);
		new_rational.signum = this->signum;

		new_rational.Simplify();

		return new_rational;
	}

	//Signs Different; If first rational is larger than second
	int larger_term = ((this->numerator * second.denominator) > (this->denominator * second.numerator)) ?
												1 : 2;
	if (larger_term == 1){

		new_rational.numerator = (this->numerator * second.denominator) - (this->denominator * second.numerator);
		new_rational.signum = this->signum;

		new_rational.Simplify();

		return new_rational;
	}

	new_rational.numerator = (this->denominator * second.numerator) - (this->numerator * second.denominator);
	new_rational.signum = second.signum;

	new_rational.Simplify();

	return new_rational;
}

rational rational::operator-(const rational& second){
	rational new_rational;

	//same in all cases
	new_rational.denominator = this->denominator * second.denominator;

	if (this->signum != second.signum){		//the sign of new_rational should match that of each rational

		new_rational.numerator = (this->numerator * second.denominator) + (this->denominator * second.numerator);
		new_rational.signum = this->signum;

		new_rational.Simplify();

		return new_rational;
	}

	//Signs Same; If first rational is larger than second
	int larger_term = ((this->numerator * second.denominator) > (this->denominator * second.numerator)) ?
												1 : 2;
	if (larger_term == 1){

		new_rational.numerator = (this->numerator * second.denominator) - (this->denominator * second.numerator);
		new_rational.signum = this->signum;

		new_rational.Simplify();

		return new_rational;
	}

	new_rational.numerator = (this->denominator * second.numerator) - (this->numerator * second.denominator);
	new_rational.signum = second.signum;

	new_rational.Simplify();

	return new_rational;
}

rational rational::operator*(const rational& second){

	rational new_rational;

	new_rational.numerator = this->numerator * second.numerator;
	new_rational.denominator = this->denominator * second.denominator;
	new_rational.signum = (this->signum == second.signum) ? sign::p : sign::n;

	new_rational.Simplify();

	return new_rational;
}

rational rational::operator/(const rational& second){

	rational new_rational;

	new_rational.numerator = this->numerator * second.denominator;
	new_rational.denominator = this->denominator * second.numerator;
	new_rational.signum = (this->signum == second.signum) ? sign::p : sign::n;

	new_rational.Simplify();

	return new_rational;
}

rational& rational::operator+=(const rational second){

	this = this + second;
	return *this;
}

rational& rational::operator-=(const rational second){

	this = this - second;
	return *this;
}

rational& rational::operator*=(const rational second){

	this = this * second;
	return *this;
}

rational& rational::operator/=(const rational second){

	this = this / second;
	return *this;
}