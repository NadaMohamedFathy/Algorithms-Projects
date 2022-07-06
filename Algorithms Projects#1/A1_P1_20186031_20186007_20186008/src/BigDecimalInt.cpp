#include <iostream>
using namespace std;
#include "BigDecimalInt.h"
#include <string>
BigDecimalInt ::BigDecimalInt (){
 	str="";
 	}
BigDecimalInt ::BigDecimalInt (string decStr){
	str=decStr;
 	Size =str.length();
	Arr=new int [Size];
	for ( int i=0; i<Size;i++)
	{
		Arr[i]=(str[i]-48);
	}
 	}
    BigDecimalInt ::BigDecimalInt (int decInt){
    string decimalstring=to_string(decInt);
 	Size=decimalstring.length();
 	//Size=decInt;
 	Arr=new int[Size];
 	for ( int i=0; i<Size;i++)
	{
		Arr[i]=(decimalstring[i]-48);
	}
 	}
 BigDecimalInt ::BigDecimalInt (int* arr,int SIZE )
 {
     Size=SIZE;
     Arr=new int[Size];
     for(int i=0;i<Size;i++)
     {
         Arr[i]=arr[i];
     }
 }
 BigDecimalInt ::BigDecimalInt (const BigDecimalInt & obj)
 {
 	Size = obj.Size ;
 	Arr=new int[Size];
 	for (int i=0;i<Size;i++)
	 {
 		Arr[i]=obj.Arr[i];
	 }
 }
 istream& operator>>(istream& is, const BigDecimalInt& str){
 		 is>>str;
 		 return is;
		}
ostream& operator<<(ostream& os, const BigDecimalInt& Array){
	for(int i=0;i<Array.Size;i++){
		os<<Array.Arr[i];
	}
	}
	BigDecimalInt ::~BigDecimalInt(){
	delete [] Arr ;
	}
  BigDecimalInt BigDecimalInt:: operator+ (const BigDecimalInt& anotherDec)
  {
      int crry =0,biggerSize;
      bool flag;
      if(Size>anotherDec.Size){
        biggerSize=Size;
        flag=true;}
      else
        biggerSize=anotherDec.Size;
      for(int i=anotherDec.Size-1;i>=0;i--)
      {
          if(Arr[i]+anotherDec.Arr[i]+crry>9)
          {
              int sum=Arr[i+(Size-anotherDec.Size)]+anotherDec.Arr[i]+crry;
              sum=sum%10;
              Arr[i+(Size-anotherDec.Size)]=sum;
              crry=1;
          }
          else
          {
              Arr[i+(Size-anotherDec.Size)]+=anotherDec.Arr[i]+crry;
              crry=0;
          }
      }
      if(flag)
      {
          for(int i=Size-anotherDec.Size-1;i>=0;i--)
          {
              if(Arr[i]+crry>9)
              {
                   int sum1=Arr[i]+crry;
                   sum1=sum1%10;
                   Arr[i]=sum1;
                   crry=1;
              }
              else
              {
                  Arr[i]+=crry;
                  crry=0;
              }

          }
      }
      if(crry==1)
      {
          int newArray[Size+1];
          newArray[0]=1;
          for(int i=0;i<Size;i++)
          {
              newArray[i+1]=Arr[i];
          }
          BigDecimalInt sum(newArray,Size+1);
          return sum;
      }
      else
          return *this;
  	}
  BigDecimalInt BigDecimalInt:: operator- (const BigDecimalInt& anotherDec)
  {
  	BigDecimalInt temp(Size);
  	if(Arr[0]>=anotherDec.Arr[0])
  	{
  		int *arr=new int[Size];
  	for(int i=0;i<Size;i++)
  	{
  		arr[i]=Arr[i];
	  }
  	for(int i=temp.Size-1;i>=0;i--)
  	{
  		if(Arr[i]<anotherDec.Arr[i])
  		{
  			arr[i-1]=arr[i-1]-1;
  	    	arr[i]=arr[i]+10;
  	    	temp.Arr[i]=arr[i]-anotherDec.Arr[i];
		  }
  		else
  		{
  	   		temp.Arr[i]=arr[i]-anotherDec.Arr[i];
		  }
	  }

	  return temp;
}
	else
	{
		int *arr=new int[Size];
  	for(int i=0;i<Size;i++)
  	{
  		arr[i]=anotherDec.Arr[i];
	  }
	  for(int i=temp.Size-1;i>=0;i--)
  	{
  		if(anotherDec.Arr[i]<Arr[i])
  		{
  			arr[i-1]=arr[i-1]-1;
  	    	arr[i]=arr[i]+10;
  	    	temp.Arr[i]=arr[i]-Arr[i];
		  }
  		else
  		{
  	   		temp.Arr[i]=arr[i]-Arr[i];
		  }
	  temp.Arr[0]=temp.Arr[0] *(-1);
	  }return temp;

}}
int BigDecimalInt ::size()
{
    return str.length();
}
