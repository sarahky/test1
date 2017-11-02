#include <matrix.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
//matrix A;
matrix B(1.5);
//matrix C(144,0.344543,3656,1.4123);
matrix D(1,3,5,4);
//matrix E()
//A.add(B);  //where B is a matrix
//D.multiply(1.4);
//D.multiply(B);
//B.element(3,1);
B.determinant();
//B.inverse();
B.print();
return 0;
}