#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include "FractionCalculator.h"
using namespace std;  
class Fraction
{
	protected: 
	 int nom;
     int denom;
	public:
		Fraction();
		Fraction(int x ,int y) ; 
		Fraction (const Fraction &obj);
		void setnom(int s);
		int getnom()const;
		void setdenom(int s);
		int getdenom()const;
		friend istream &operator>>(istream &is, Fraction &obj);
		friend ostream &operator<<(ostream &os,const Fraction &obj);
		Fraction operator + (const Fraction &obj) ;
        Fraction operator - (const Fraction  &obj);
        Fraction operator * (const Fraction  &obj);
        Fraction operator / (const Fraction  &obj);
        bool operator <= (const Fraction &obj);
        bool operator < (const Fraction &obj);
        bool operator >= (const Fraction &obj);
        bool operator > (const Fraction &obj);
        bool operator == (const Fraction &obj);
        void simplify(Fraction &d) ; 
       
}; 

#endif
