#include <bits/stdc++.h> 
using namespace std; 
int binarySearch(int arr[], int first, int last, int target, int size) 
{ 
	if (last >= first) { 
		int mid = first + (last - first) / 2; 
		if ((mid == 0 || target > arr[mid - 1]) && arr[mid] == target) 
			{
				return mid; 
			}
		if (target > arr[mid]) 
		{
			return binarySearch(arr, (mid + 1), last, target, size); 
		}
		return binarySearch(arr, first, (mid - 1), target, size); 
	} 
	return -1; 
} 
void insertionSort (int s[],int m)
		 {
		 	int j;
		    for (int i = 1; i < m; i++)
            {
      	      int tmp = s [i];

		      for ( j = i; (j > 0 && tmp < s [j-1]); j--)
			    {
				    s [j] = s [j - 1];
				}
		    	s [j] = tmp;
        	}
        } 
void sorting(int A1[], int A2[], int m, int n) 
{ 
	int temp[m], another[m]; 
	int ind = 0; 
	for (int i = 0; i < m; i++) 
	{ 
		temp[i] = A1[i]; 
		another[i] = 0; 
	} 
	insertionSort(temp, m); 
	for (int i = 0; i < n; i++) 
	{ 
		int index = binarySearch(temp, 0, m - 1, A2[i], m); 
		if (index == -1) 
			{
			    continue; 
            }
		for (int j = index; (j < m && temp[j] == A2[i]); j++) 
		{ 
			A1[ind] = temp[j]; 
			another[j] = 1; 
			ind++;
		} 
	} 
	for (int i = 0; i < m; i++) 
	{
		if (another[i] == 0) 
		{
			A1[ind] = temp[i]; 
			ind++;
		}
	}
} 
void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
	{
		cout << arr[i] << " "; 
	}
	cout << "}"<<endl; 
} 

// Driver Code 
int main() 
{ 
	int A1[] = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 }; 
	int A2[] = { 2, 1, 8, 3 }; 
	int a = sizeof(A1) / sizeof(A1[0]); 
	int b = sizeof(A2) / sizeof(A2[0]); 
	cout<<"First array without sorting : A1[] = { ";
	printArray(A1, a); 
	cout<<endl;
	cout << "Sorted array is : A1[] = { "; 
	sorting(A1, A2, a, b); 
	printArray(A1, a); 
	return 0; 
} 

