#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <string>
using namespace std;
#include "BigDecimalInt.h"
class BigDecimalInt
{
	public:
		int Size ;
	    int *Arr ; //intialize pointer of array
	    string str;
	    BigDecimalInt ();
		BigDecimalInt (string decStr); // Initialize from string
        BigDecimalInt (int decInt); // Initialize from integer or decimal
        BigDecimalInt (int* arr,int SIZE );
        BigDecimalInt (const BigDecimalInt &);
        BigDecimalInt operator+ (const BigDecimalInt& anotherDec); //overloaded +
        BigDecimalInt operator- (const BigDecimalInt& anotherDec); //overloaded -
        friend ostream& operator<<(ostream& os, const BigDecimalInt& array); //Overloading operators <<
        int size();
        ~BigDecimalInt(); //destructor
};

#endif
