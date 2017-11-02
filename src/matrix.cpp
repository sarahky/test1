#include <matrix.h>
#include <stdio.h>

matrix::matrix()
{
	/*
		This constructor (the default constructor) creates a matrix with all zero elements
	*/

	e00 = e01 = e10 = e11 = 0;
}

matrix::matrix(double a)
{
	/*
		This constructor should create a diagonal matrix with the diagonal elements equal to a and
		the other elements equal to zero.

		TO DO
	*/
	//added 
	e00 = e11 = a;
	e01 = e10 = 0;

}

matrix::matrix(double a, double b, double c, double d)
{
	/*
		This constructor should set the elements the values of the elements using the
		parameters a,b,c,d

		TO DO
	*/
	//added
	e00 = a;
	e01 = b;
	e10 = c;
	e11 = d;
}

matrix::matrix(const matrix& a)
{
	/*
		This is the copy constructor: it takes a matrix and makes a new one with the same element values
	*/

	e00 = a.e00;
	e01 = a.e01;
	e10 = a.e10;
	e11 = a.e11;
}

matrix& matrix::add(matrix& a)
{
	/*
		The add member function adds the elements of matrix 'a' to this matrix. 
	*/

	e00 = e00 + a.e00;
	e01 = e01 + a.e01;
	e10 = e10 + a.e10;
	e11 = e11 + a.e11;

	return *this;
}


matrix& matrix::multiply(double x)  // TO DO: Multiply the matrix by a scalar
{
//added
	e00 = e00 * x;
	e01 = e01 * x;
	e10 = e10 * x;
	e11 = e11 * x;

	return *this;

}

matrix& matrix::multiply(matrix& m)  // TO DO: Multiply the matrix by another matrix
{
	e00 = e00 * m.e00 + e01 * m.e10;
	e01 = e00 * m.e01 + e01 * m.e11;
	e10 = e10 * m.e00 + e11 * m.e10;
	e11 = e10 * m.e01 + e11 * m.e11;

	return *this;
}

double matrix::element(int s,int c) // TO DO: return the specified element using its column and row number
{
if (s==1 && c==1) {printf("The Matrix element is 1,1 = %f\n",e00); return e00;}
if (s==1 && c==2) {printf("The Matrix element is 1,2 = %f\n",e01); return e01;}
if (s==2 && c==1) {printf("The Matrix element is 2,1 = %f\n",e10); return e10;}
if (s==2 && c==2) {printf("The Matrix element is 2,2 = %f\n",e11); return e11;}
else printf("error for choosing matrix element\n"); return 0;
}

double matrix::determinant() // TO DO: return the determinant of the matrix
{
double d=0;
d = e00 * e11 - e01 * e10;
printf("The dertminant of the matrix = %f\n",d);
return d;

}

matrix& matrix::inverse() // TO DO: return the inverse of the matrixs
{
double d=0;
double h=0;

d = e00 * e11 - e01 * e10;
h = e00;
e00 = e11;
e11 = h;

e10 = -e10;
e01 = -e01;

e00 = e00 / d;
e01 = e01 / d;
e10 = e10 / d;
e11 = e11 / d;
return *this;

}

void matrix::print() // TO DO: a function to print out the matrix to the console.
{

printf("|%f %f|\n",e00,e01);
printf("|%f %f|",e10,e11);
}
/*
The matrix class represents a simple 2x2 matrix with elements:

	|  e00  e01  |
	|  e10  e11  |

it contains member functions to add and multiply matrices. it can also find determinants and inverses.


*/