#include "MatrixCalculator.h"
#include <iostream>
#include "Matrix.h"
using namespace std;
ostream& operator<< (ostream& os ,Matrix& obj)
{
	os<<"Matrix :"<<endl;
	for(int i=0;i<obj.getrow();i++)
	{
		for(int j=0;j<obj.getcol();j++)
		{
			os<< obj.data[i][j]<<" ";
		}
		os<<endl;
	}
	return os ;
}
MatrixCalculator::MatrixCalculator()
{
    string name;
    cout<<"Enter your name : ";
    cin>>name;
	cout << "Welcome "<<name<<" to your Matrix Calculator"<<endl;
    cout << "--------------------------------------------"<<endl;
	int m,n,e,f;
	cout<<"Enter size of mtrix"<<endl;
	cin>>m>>n;
	Matrix A(m,n);
	A.setrow(m);
	A.setcol(n);
	cout<<"enter the values: "<<endl;
	cin>>A;
	for(int h=0;;)
	{
		cout<<endl;
		cout<<"What do you want to do with your mtrix?"<<endl;
	    cout<<"1) Add scalar"<<endl<<"2) Subtract scalar"<<endl<<"3) Multiply scalar"<<endl;
    	cout<<"4) Add matrix"<<endl<<"5) Subtract matrix"<<endl<<"6) Multiply matrix"<<endl;
    	cout<<"7) Transpose matrix"<<endl<<"8) Check if the matrix Squar or not"<<endl;
    	cout<<"9) Check if the matrix Identity or not"<<endl<<"10)Print your Matrix"<<endl<<"11) Exit"<<endl;
    	int b,q;
    	cin>>b;
		if(b==1)
		{
			cout<<"Enter scalar: ";
			cin>>q;
			Matrix x = A+q;//here we use copy constructor
			cout<<x;//here we use friend function
		}
		else if(b==2)
		{
			cout<<"Enter scalar: ";
			cin>>q;
			Matrix x = A-q;//here we use copy constructor
			cout<<x;//here we use friend function
		}
		else if(b==3)
		{
			cout<<"Enter scalar: ";
			cin>>q;
			Matrix x = A*q;//here we use copy constructor
			cout<<x;//here we use friend function
		}
		else if(b==4)
		{
			cout<<"Enter size of  the other mtrix"<<endl;
	        cin>>e>>f;
	        Matrix B(e,f);
			B.setrow(e);
			B.setcol(f);
			cout<<"enter value of the matrix :  "<<endl ; 
			cin>>B;
            //B.setvalue(e,f);
			Matrix x = A+B;//here we use copy constructor
			cout<<x;//here we use friend function
		}
		else if(b==5)
		{
			cout<<"Enter size of the other mtrix"<<endl;
	        cin>>e>>f;
	        Matrix B(e,f);
			B.setrow(e);
			B.setcol(f);
			cout<<"enter value of the matrix :  "<<endl ; 
			cin>>B;
        	//B.setvalue(e,f);
			Matrix x = A-B;//here we use copy constructor
			cout<<x;//here we use friend function
		}
		else if(b==6)
		{
			cout<<"Enter size of  the other mtrix"<<endl;
	        cin>>e>>f;
	        Matrix B(e,f);
			B.setrow(e);
			B.setcol(f);
			cout<<"enter value of the matrix :  "<<endl ; 
			cin>>B;
        	//B.setvalue(e,f);
			Matrix x = A*B;//here we use copy constructor
			cout<<x;//here we use friend function
		}
		else if(b==7)
		{
			Matrix x = A.transpose();//here we use copy constructor
			cout<<x;//here we use friend function
		}
		else if(b==8)
		{
			cout<<A.isSquare();
		}
		else if(b==9)
		{
			cout<<A.isIdentity();
		}
		else if(b==10)
		{
			cout<<A;//here we use friend function
		}
		else if(b==11)
		{
			break;
		}
	}
}

