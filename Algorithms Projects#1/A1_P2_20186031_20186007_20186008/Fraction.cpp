#include "Fraction.h"
#include <iostream>
using namespace std ; 
Fraction::Fraction()
{
	
}
Fraction::Fraction(int x,int y)
{ 
	nom = x ;
	denom = y ;
}
Fraction::Fraction(const Fraction &obj)
{
    nom = obj.nom;
    denom=obj.denom;
}

void Fraction::setnom(int s)
{
	nom=s;
}
int Fraction::getnom()const
{
	return nom;
}
void Fraction::setdenom(int s)
{
	denom=s;
}
int Fraction::getdenom()const
{
	return denom;
}

istream &operator>>(istream &is,  Fraction &obj) 
{
is>>obj.nom; 
is>>obj.denom ;
return is ; 
}
ostream &operator<<(ostream &os, const Fraction &obj)
{
	if(obj.nom==0)
	{
		os<<"0";
	}
	else if(obj.denom==1)
	{
		os<<obj.nom;
	}
	else
	{
		os<<obj.nom<<"/"<<obj.denom;
	}
return os ; 
}
Fraction Fraction ::operator +(const Fraction &obj)
{
Fraction temp;
 if(denom==obj.denom)
    {
	temp.nom=nom+obj.nom;
    temp.denom=denom;
}
else 
   {
   temp.nom=(nom*obj.denom)+(denom*obj.nom);
   temp.denom=denom*obj.denom;
}
simplify(temp);
return temp;
}
Fraction Fraction ::operator - (const Fraction  &obj)
{
Fraction temp;
if(denom==obj.denom)
    {
	temp.nom=nom-obj.nom;
	if(temp.nom == 0)
	{
		return temp;
	}
    temp.denom=denom;
}
else 
   {
   temp.nom=(nom*obj.denom)-(denom*obj.nom);
   temp.denom=denom*obj.denom;
}
simplify(temp);
return temp;
}
Fraction Fraction ::operator * (const Fraction  &obj)
{
Fraction temp ; 
    temp.nom=nom*obj.nom;
    temp.denom=denom*obj.denom;
    simplify(temp);
return temp;
}
Fraction Fraction:: operator / (const Fraction  &obj)
{
	Fraction temp ; 
    temp.nom=nom*obj.denom;
    temp.denom=denom*obj.nom;
    simplify(temp);
return temp;
}
bool Fraction::operator < (const Fraction &obj)
{
    float f1,f2;
          
    f1 = nom * obj.denom;
    f2 = denom * obj.nom;
    
    return (f1< f2);
}
bool Fraction::operator>(const Fraction &obj) 
{
    float f1,f2;
          
    f1 = nom * obj.denom;
    f2 = denom * obj.nom;
    
    return (f1>f2);
}
bool Fraction::operator <= (const Fraction &obj)
{
    float f1,f2;
          
    f1 = nom * obj.denom;
    f2 = denom * obj.nom;
    
    return (f1<= f2);
}
bool Fraction::operator >= (const Fraction &obj)
{
    float f1,f2;
          
    f1 = nom * obj.denom;
    f2 = denom * obj.nom;
    
    return (f1>=f2);
}
bool Fraction::operator == (const Fraction &obj)
{
    float f1,f2;
          
    f1 = nom * obj.denom;
    f2 = denom * obj.nom;
    
    return (f1 ==f2);
}
void Fraction::simplify(Fraction &d)
{
	for(int i=d.nom*d.denom;i>1;i--)
	{
		if((d.denom%i==0) && (d.nom%i==0))
		{
			d.denom=d.denom/i;
			d.nom=d.nom/i;
		}
	}
}


