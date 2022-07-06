#include "Matrix.h"
#include <iostream>
using namespace std;
void Matrix::setrow(int r)
{
	if(r<0)
	{
		cout<<"out of our domain"<<endl;
	}else
	row=r;
}
void Matrix::setcol(int c)
{
	if(c<0)
	{
		cout<<"out of our domin"<<endl;
	}
	else
	col=c;
}
int Matrix::getrow()const
{
	return row;
}
int Matrix::getcol()const
{
	return col;
}
istream& operator>> (istream& is, Matrix& obj)
{
    obj.data=new int *[obj.row];
    for (int i = 0; i < obj.row; i++)
    {
        obj.data[i] = new int[obj.col];
    }
	for(int i=0;i<obj.row;i++)
	{
		for(int j=0;j<obj.col;j++)
		{
			is>>obj.data[i][j];
  		}

	}
	return is ;
}


Matrix::Matrix(int x,int y)
{
	 row=x;
	col=y;
	data=new int*[row];
	for(int i=0;i<row;i++)
	{
		data[i]=new int [col];
	}
}
Matrix::Matrix(const Matrix& m)
{
	row=m.row;
	col=m.col;
	data=new int *[row];
	for(int i=0;i<row;i++)
	{
		data[i]=new int[col];
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			data[i][j]=m.data[i][j];
		}
		cout<<endl;
	}
}
Matrix::~Matrix()
{
	for(int i=0;i<row;i++)
	{
		delete [] data[i];
	}
	delete [] data;
}
Matrix Matrix::operator + (int scalar)
{
	Matrix neo(row,col);
	for(int i=0;i<neo.row;i++)
	{
		for(int j=0;j<neo.col;j++)
		{
			neo.data[i][j]=data[i][j]+scalar;
		}
		cout<<endl;
	}
	return neo;
}
Matrix Matrix::operator - (int scalar)
{
	Matrix neo(row,col);
	for(int i=0;i<neo.row;i++)
	{
		for(int j=0;j<neo.col;j++)
		{
			neo.data[i][j]=data[i][j]-scalar;
		}
		cout<<endl;
	}
	return neo;
}
Matrix Matrix::operator * (int scalar)
{
	Matrix neo(row,col);
	for(int i=0;i<neo.row;i++)
	{
		for(int j=0;j<neo.col;j++)
		{
			neo.data[i][j]=data[i][j]*scalar;
		}
		cout<<endl;
	}
	return neo;
}
Matrix Matrix::operator + (const Matrix &obj)
{
	if((row!=obj.getrow()) || (col!=obj.getcol()))
	{
		cout<<"Addition Error"<<endl;
		//return 0;
	}
	else
	{
	Matrix neo(row,col);
	for(int i=0 ;i<obj.row;i++)
	{
		for(int j=0;j<obj.col;j++)
		{
			neo.data[i][j]=obj.data[i][j] + data[i][j];
		}
		cout<<endl;
	}
	return neo;
}
}
Matrix Matrix::operator - (const Matrix &obj)
{
 	if((row!=obj.row) || (col!=obj.col))
	{
		cout<<"Subtraction Error"<<endl;
		//return 0;
	}
	else
	{
	Matrix neo(row,col);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			neo.data[i][j]=- data[i][j] - obj.data[i][j];		
		}
		cout<<endl;
	}
	return neo;
}
}

Matrix Matrix::operator * (const Matrix &obj)
{
	if(col!=obj.row)
	{
		cout<<"Multiplication Error"<<endl;
		//return 0;
	}
    else
    {
	Matrix neo(row,col);
	for(int i=0;i<row;i++)
	{
	   for(int j=0;j<obj.col;j++)
	    {
			for(int z=0;z<col;z++)
			{
				neo.data[i][j]+=obj.data[z][j] * data[i][z];
				
			}
		}
		cout<<endl;
}
	return neo;

}
}

Matrix Matrix::transpose()
{
	Matrix trans(col ,row);
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			trans.data[j][i]=data[i][j];
		}
		cout<<endl;
	}
	return trans;
}
bool Matrix::isSquare()
{
	if(row==col)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Matrix::isIdentity()
{
	if(row==col)
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				if((i!=j && data[i][j]!=0) || (i==j && data[i][j]!=1))
				{
					return false;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
