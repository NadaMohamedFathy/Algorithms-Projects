#include <iostream>
#include <stack>
#include <cmath>
using namespace std ; 
int Binary_to_decimal(int BinaryNumber)
{ 
	stack<int>s ;
	int bit , no ;
 	int decimal = 0 , weight = 0 ; 
	while(BinaryNumber!=0)
	{
	 	bit=BinaryNumber%10;
		s.push(bit); 
		weight++;
	 	BinaryNumber = BinaryNumber/10 ; 
	}
	weight--;
	while(!s.empty() && weight>=0)
	{
	   	no=s.top(); 
	   	cout<<no;
	   	s.pop();
		decimal = decimal +no * pow(2,weight) ; 
	    weight-- ; 	
	}
	cout<<endl;
	return decimal;
}
int main(int argc, char** argv) {
	int BinaryNo;
	BinaryNo=1001101;
	cout<<Binary_to_decimal(BinaryNo)<<endl;
	BinaryNo = 11000101 ;
	cout<<Binary_to_decimal(BinaryNo)<<endl;
	BinaryNo =10101010;
	cout<<Binary_to_decimal(BinaryNo)<<endl;
	BinaryNo =11111111;
	cout<<Binary_to_decimal(BinaryNo)<<endl;
	BinaryNo =10000000;
	cout<<Binary_to_decimal(BinaryNo)<<endl;
	BinaryNo =1111100000;
	cout<<Binary_to_decimal(BinaryNo)<<endl;
	return 0;
}

