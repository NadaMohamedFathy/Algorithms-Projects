#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
using namespace std ; 
int Binary_to_decimal(int BinaryNumber)
{ 
	 vector<int>v ; 
	 stack<int>s ;
	 int bit , no ;
 	int decimal = 0 , weight = 0 ;  
  while(BinaryNumber!=0)
   {
 	bit=BinaryNumber%10;
 	v.push_back(bit) ; 
 	BinaryNumber = BinaryNumber/10 ; 
   }
   	for(int i = v.size()-1;i>=0;i--)
   	{
   		cout<<v[i];
	}
	cout<<endl;
	for(int i = v.size()-1;i>=0;i--)
	{
		s.push(v[i]);
	}
	while(!s.empty())
	{
	   	no=s.top(); 
	   	cout<<no;
		decimal = decimal +no * pow(2,weight) ; 
	    weight++ ; 
	   	s.pop();
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

