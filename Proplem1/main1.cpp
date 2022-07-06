#include <iostream>
using namespace std ;
void OrderArray(int arr[],int size,int n)
{
	int max = 0 ;
	int j ;

	for(int i=0;i<size;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			j=i;
		}
	}
	if(max!=arr[0])
	{
		for(int i=j;i>=0;i--)
		{
			arr[i]=arr[i-1];
		}
	 arr[0]=max;
	}
	int sum=0;
	int q=arr[0];
	sum=q-n;
	for(int i=0;i<size-1;i++)
	{
		sum+=arr[i]-arr[i+1];
	}
	cout<<"Minimal seek time = "<<sum;
}

int main(int argc, char** argv) 
{
	int arr[]={100,50,190};
	int n = 140 ;
	int size =sizeof(arr)/sizeof(arr[0]);
	OrderArray(arr,size,n);
}

