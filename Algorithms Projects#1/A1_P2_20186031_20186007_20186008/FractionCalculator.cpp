#include "FractionCalculator.h"
#include <iostream>
#include "Fraction.h"
using namespace std ;
FractionCalculator::FractionCalculator()
{
int a,b,c,d;
cout<<"Enter the nominator " ;
cin>>a ;
cout<<"Enter the doniminator " ;
cin>>b ;
 cout<<"Enter the nominator " ;
cin>>c ;
cout<<"Enter the doniminator " ;
cin>>d ;
if(b==0 || d==0)
	{
		cout<<"Error"<<endl;
		return ;
	}
	
Fraction f1(a,b),f2(c,d),f3; 
while(true)
{
int n ; 
cout<<"1)addition.."<<endl<<"2)substraction.."<<endl<<"3)multiplication.."<<endl<<"4)dividing.."<<endl;
cout<<"5)Compare.."<<endl<<"6)Exit.."<<endl;
cin>>n;
if(n==1)
{
	f3=f1+f2 ; 
	cout<<f3<<endl ; 
}
if(n==2){
	f3=f1-f2;
	cout<<f3<<endl ; 
}
if(n==3){
	
	f3=f1*f2;
	cout<<f3<<endl ; 
}
if (n==4){
	f3=f1/f2;
	cout<<f3<<endl;
}
if (n==5){
if(f1==f2)
cout<<"is equal"<<endl ; 
else if(f1<f2)
cout<<"f1 is less than f2"<<endl ;
else //if(f1>f2)
cout<<"f1 is greater than f2"<<endl ;
//else if(f1<=f2)
//cout<<"f is less than or equal f1"<<endl ; 
//else  if(f1>=f2)
//cout<<"f is greater than or equal f1"<<endl ; 
	
}
if(n==6)
{
	break;
}

	
}}

