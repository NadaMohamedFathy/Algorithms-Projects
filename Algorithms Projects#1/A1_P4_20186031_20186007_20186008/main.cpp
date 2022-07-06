//Nada Mohamed Fathy 20186031
//Ayat Hany 20186007
//Sarah Khaled 20186008
#include <iostream>
using namespace std;
int power1(int,int);
int power1(int a,int n){
	if(n!=0){
		return (a*power1(a,n-1));
	}
	else 
	    return 1;
}
int power2(int,int);
int power2(int b, int m) 
{ 
    if (m == 0) 
        return 1; 
    else if (m % 2 == 0) 
        return power2(b, m/ 2) * power2(b, m / 2); 
    else
        return b * power2(b, m / 2) * power2(b, m / 2);
} 
int main(int argc, char** argv) {
	int a ,n,b,m,result1,result2;
	cout<<"2^2="<<power1(2,2)<<endl;
	cout<<"2^2="<<power2(2,2)<<endl;
	cout<<"2^5="<<power2(2,5)<<endl;
	cout<<"enter the number please: ";
	cin>>a;
	cout<<"enter power please: ";
	cin>>n;
	result1=power1(a,n);
	cout<<a<<"^"<<n<<"="<<result1<<endl;
	cout<<"enter the number please: ";
	cin>>b;
	cout<<"enter power please: ";
	cin>>m;
	result2=power2(b,m);
	cout<<b<<"^"<<m<<"="<<result2<<endl;
	return 0;
}
