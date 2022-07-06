#include <iostream>
using namespace std;

int calculate(int n,int c, int a[],int b[])
{
	int remain[n],minrem[n];	
	//The remaining fuel in each trip
    for (int i = 0; i < n; i++) 
	{
        remain[i] = a[i] - b[i];
    }
    //The minimum remaing fuel
    minrem[n - 1] = remain[n - 1];
    for (int i = n - 2; i >= 0; i--)
	{
        minrem[i] = min(remain[i], remain[i] + minrem[i + 1]);
    }
    //Cover the whole remaing fuel from any point
	minrem[n - 1] = min(remain[n - 1], remain[n - 1] + minrem[0]);
    for (int i = n - 2; i >= 0; i--) 
	{
        minrem[i] = min(remain[i], remain[i] + minrem[i + 1]);
    }
    //Check the capcity of the remaing fuel for each city, upon this he can determine if he can visit the city or not
    for (int i = 0; i < n; i++) 
	{
        if ((-minrem[i] + a[i]) > c) 
		{
            return 0;
        }
    }
    int numOfCities = 0;
    //Upon the remaing fuel, it decides the number of cities he can visit
    for (int i = 0; i < n; i++) 
	{
        if (minrem[i] >= 0) 
		{
            numOfCities++;
        }
    }
    return numOfCities;
}

int main()
{
	cout<<"Enter the number of cities and the galon's capacity"<<endl;
	int c,n;
	cin>>n>>c;
	int a[n],b[n];
	cout<<"Enter the number of galons you can put in each city"<<endl;
	for (int i = 0; i < n; i++) 
	{
        cin>>a[i];
    }
    cout<<"Enter the number of galons you can use in each city"<<endl;
    for (int i = 0; i < n; i++) 
	{
        cin>>b[i];
    }
    int x = calculate(n,c,a,b);
    cout<<"The number of cities you can visit: "<<x;
    return 0;
}
