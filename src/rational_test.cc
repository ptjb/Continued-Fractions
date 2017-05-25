#include <cassert>

#include "rational.h"

void Test_Constructor(){

	rational first(34ULL);
	assert(first.numerator == 34ULL);
	assert(first.denominator == 1ULL);
	assert(first.signum == sign::p);

	rational second(43ULL, 23ULL);
	assert(second.numerator == 43ULL);
	assert(second.denominator == 23ULL);
	assert(second.signum == sign::p);

	rational third(56ULL, 3ULL, sign::n);
	assert(third.numerator == 56ULL);
	assert(third.denominator == 3ULL);
	assert(third.signum == sign::n);
	
	return;
}

void Test_Copy_Constructor(){

	rational first(34ULL);
	rational cpfirst(first);
	assert(cpfirst.numerator == 34ULL);
	assert(cpfirst.denominator == 1ULL);
	assert(cpfirst.signum == sign::p);

	rational second(43ULL, 23ULL);
	rational cpsecond(second);
	assert(cpsecond.numerator == 43ULL);
	assert(cpsecond.denominator == 23ULL);
	assert(cpsecond.signum == sign::p);

	rational third(56ULL, 3ULL, sign::n);
	rational cpthird(third);
	assert(cpthird.numerator == 56ULL);
	assert(cpthird.denominator == 3ULL);
	assert(cpthird.signum == sign::n);

	return;
}

void Test_GetNumerator(){

	rational first(34ULL);
	assert(first.GetNumerator() == 34ULL);
	assert(first.denominator == 1ULL);
	assert(first.signum == sign::p);

	rational second(43ULL, 23ULL);
	assert(second.GetNumerator() == 43ULL);
	assert(second.denominator == 23ULL);
	assert(second.signum == sign::p);

	rational third(56ULL, 3ULL, sign::n);
	assert(third.GetNumerator() == 56ULL);
	assert(third.denominator == 3ULL);
	assert(third.signum == sign::n);
}

void Test_GetDenominator(){

	rational first(34ULL);
	assert(first.numerator == 34ULL);
	assert(first.GetDenominator() == 1ULL);
	assert(first.signum == sign::p);

	rational second(43ULL, 23ULL);
	assert(second.numerator == 43ULL);
	assert(second.GetDenominator() == 23ULL);
	assert(second.signum == sign::p);

	rational third(56ULL, 3ULL, sign::n);
	assert(third.numerator == 56ULL);
	assert(third.GetDenominator() == 3ULL);
	assert(third.signum == sign::n);

	return;
}

void Test_GetSign(){ 

	rational first(34ULL);
	assert(first.numerator == 34ULL);
	assert(first.denominator == 1ULL);
	assert(first.GetSign() == 1);

	rational second(43ULL, 23ULL);
	assert(second.numerator == 43ULL);
	assert(second.denominator == 23ULL);
	assert(second.GetSign() == 1);

	rational third(56ULL, 3ULL, sign::n);
	assert(third.numerator == 56ULL);
	assert(third.denominator == 3ULL);
	assert(third.GetSign() == -1);

	return;
}

void Test_SetNumerator(){ 

	rational first(34ULL);
	first.SetNumerator(15ULL);
	assert(first.numerator == 15ULL);
	assert(first.denominator == 1ULL);
	assert(first.signum == sign::p);

	rational sfirst(34ULL);
	sfirst.SetNumerator(34ULL);
	assert(sfirst.numerator == 34ULL);
	assert(sfirst.denominator == 1ULL);
	assert(sfirst.signum == sign::p);

	rational second(43ULL, 23ULL);
	second.SetNumerator(51ULL);
	assert(second.numerator == 51ULL);
	assert(second.denominator == 23ULL);
	assert(second.signum == sign::p);

	rational ssecond(43ULL, 23ULL);
	ssecond.SetNumerator(43ULL);
	assert(ssecond.numerator == 43ULL);
	assert(ssecond.denominator == 23ULL);
	assert(ssecond.signum == sign::p);

	rational third(56ULL, 3ULL, sign::n);
	third.SetNumerator(37ULL);
	assert(third.numerator == 37ULL);
	assert(third.denominator == 3ULL);
	assert(third.signum == sign::n);

	rational sthird(56ULL, 3ULL, sign::n);
	sthird.SetNumerator(56ULL);
	assert(sthird.numerator == 56ULL);
	assert(sthird.denominator == 3ULL);
	assert(sthird.signum == sign::n);

	return;
}

void Test_SetDenominator(){ 

	rational first(34ULL);
	first.SetDenominator(15ULL);
	assert(first.numerator == 34ULL);
	assert(first.denominator == 15ULL);
	assert(first.signum == sign::p);

	rational sfirst(34ULL);
	sfirst.SetDenominator(1ULL);
	assert(sfirst.numerator == 34ULL);
	assert(sfirst.denominator == 1ULL);
	assert(sfirst.signum == sign::p);

	rational second(43ULL, 23ULL);
	second.SetDenominator(51ULL);
	assert(second.numerator == 43ULL);
	assert(second.denominator == 51ULL);
	assert(second.signum == sign::p);

	rational ssecond(43ULL, 23ULL);
	ssecond.SetDenominator(23ULL);
	assert(ssecond.numerator == 43ULL);
	assert(ssecond.denominator == 23ULL);
	assert(ssecond.signum == sign::p);

	rational third(56ULL, 3ULL, sign::n);
	third.SetDenominator(37ULL);
	assert(third.numerator == 56ULL);
	assert(third.denominator == 37ULL);
	assert(third.signum == sign::n);

	rational sthird(56ULL, 3ULL, sign::n);
	sthird.SetDenominator(3ULL);
	assert(sthird.numerator == 56ULL);
	assert(sthird.denominator == 3ULL);
	assert(sthird.signum == sign::n);

	return;
}

void Test_SetSign(){ 

	rational nfirst(34ULL);
	nfirst.SetSign(sign::n);
	assert(nfirst.numerator == 34ULL);
	assert(nfirst.denominator == 1ULL);
	assert(nfirst.signum == sign::n);

	rational pfirst(34ULL);
	pfirst.SetSign(sign::p);
	assert(pfirst.numerator == 34ULL);
	assert(pfirst.denominator == 1ULL);
	assert(pfirst.signum == sign::p);

	rational nsecond(43ULL, 23ULL);
	nsecond.SetSign(sign::n);
	assert(nsecond.numerator == 43ULL);
	assert(nsecond.denominator == 23ULL);
	assert(nsecond.signum == sign::n);

	rational psecond(43ULL, 23ULL);
	psecond.SetSign(sign::p);
	assert(psecond.numerator == 43ULL);
	assert(psecond.denominator == 23ULL);
	assert(psecond.signum == sign::p);

	rational nthird(56ULL, 3ULL, sign::n);
	nthird.SetSign(sign::n);
	assert(nthird.numerator == 56ULL);
	assert(nthird.denominator == 3ULL);
	assert(nthird.signum == sign::n);

	rational pthird(56ULL, 3ULL, sign::n);
	pthird.SetSign(sign::p);
	assert(pthird.numerator == 56ULL);
	assert(pthird.denominator == 3ULL);
	assert(pthird.signum == sign::p);

	return;
}

void Test_Simplify(){ return;}
void Test_Invert(){ return;}
void Test_Negate(){ return;}


void Test_SquareRoot(){ return;}		


void Test_Assignment(){ return;}		
void Test_Add(){ return;}
void Test_Subtract(){ return;}
void Test_Multiply(){ return;}
void Test_Divide(){ return;}

void Test_Increment(){ return;}
void Test_Decrement(){ return;}
void Test_Scale(){ return;}
void Test_Shrink(){ return;}

int main(){

	Test_Constructor();
	Test_Copy_Constructor();

	Test_GetNumerator();
	Test_GetDenominator();
	Test_GetSign();

	Test_SetNumerator();
	Test_SetDenominator();
	Test_SetSign();

	Test_Simplify();
	Test_Invert();
	Test_Negate();


	Test_SquareRoot();		


	Test_Assignment();		
	Test_Add();
	Test_Subtract();
	Test_Multiply();
	Test_Divide();

	Test_Increment();
	Test_Decrement();
	Test_Scale();
	Test_Shrink();
	//rational first(34ULL);
	//std::cout << first.numerator << std::endl;

	std::cout << "Passed." << std::endl;
	return 0;
}