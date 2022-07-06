#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Matrix.h"
#include "MatrixCalculator.h"
using namespace std;
class Matrix
{
	private:
 // Pointer to 2D array
 int row;
 int col;

  public: // constructors,destructor & methods to be implemented
    int **data;
  void setrow(int);
  void setcol(int);
  int getrow()const;
  int getcol()const;
   friend ostream& operator<< (ostream& os,const Matrix& obj);
   friend istream& operator>> (istream& is, Matrix& obj);
   Matrix(int x,int y);//allocates memory for the matrix
   Matrix(const Matrix& m); //a copy constructor
   Matrix operator + (const Matrix &obj); // Matrix add(Matrix mat1); Add if same dimensions
   Matrix operator - (const Matrix &obj); //Matrix subtract(Matrix mat1);  Subtract if same dimensions
   Matrix operator * (const Matrix &obj); //Matrix Multiply(Matrix mat1);  Multiply if col1 == row2
   Matrix operator + (int scalar); // Add a scalar
   Matrix operator - (int scalar); // Subtract a scalar
   Matrix operator * (int scalar); // Multiply by a scalar
   Matrix transpose (); // Return new matrix with the transpose
   bool isSquare (); // True if square matrix
   bool isIdentity (); // True if square and identity friend
   ~Matrix();//de-allocates memory
};

#endif
