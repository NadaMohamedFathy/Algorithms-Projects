//Nada Mohamed Fathy 20186031
//Ayat Hany 20186007
//Sarah Khaled 20186008
/*Hint----This project run only on code Blocks because there is a problem with dev c++ with its virsion does not accept library os string 
  we do not know if we will have discussion or not ,so we get the idea to tell you here ....Thanks:)*/
#include <iostream>
#include "BigDecimalInt.h"
#include <string>
using namespace std;
int main(int argc, char** argv) {
	cout<<"done"<<endl;
    BigDecimalInt b1("123456789012345678901234567890");
    BigDecimalInt b2("113456789011345678901134567890");
    BigDecimalInt sum=b1+b2;
    cout<< "num2 + num1 = " <<sum;
    cout<<endl;
    BigDecimalInt sum1=b1-b2;
    cout<< "num2 - num1 = " <<sum1;
    cout<<endl;
    BigDecimalInt b3("9999");
    BigDecimalInt b4("1");
    BigDecimalInt sum2=b3+b4;
    cout<< "num2 + num1 = " <<sum2;
    cout<<endl;
    BigDecimalInt sum3=b3-b4;
    cout<< "num2 - num1 = " <<sum3;
    cout<<endl;
    BigDecimalInt b5("123");
    BigDecimalInt b6("99");
    BigDecimalInt sum4=b5+b6;
    cout<< "num2 + num1 = " <<sum4;
    cout<<endl;
    BigDecimalInt sum5=b5-b6;
    cout<< "num2 - num1 = " <<sum5;
    cout<<endl;
    BigDecimalInt b7("123");
    BigDecimalInt b8("123");
    BigDecimalInt sum6=b7+b8;
    cout<< "num2 + num1 = " <<sum6;
    cout<<endl;
    BigDecimalInt sum7=b7-b8;
    cout<< "num2 - num1 = " <<sum7;
    cout<<endl;
    BigDecimalInt b9("99");
    BigDecimalInt b10("11");
    BigDecimalInt sum8=b9+b10;
    cout<< "num2 + num1 = " <<sum8;
    cout<<endl;
    BigDecimalInt sum9=b9-b10;
    cout<< "num2 - num1 = " <<sum9;
    cout<<endl;
	return 0;
}
