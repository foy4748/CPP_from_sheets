#include<iostream>
#include<cmath>
#include<conio.h>

using namespace std;

void mult()
{
	double A[3][3], B[3][3], C[3][3];
	int i,j,k;
	
	//Input Matrix A
	cout<<"Enter a 3x3 matrice (A): "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>A[i][j];
		}
	}
	
	//Input Matrix B
	cout<<"Enter a 3x3 matrice (B): "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>B[i][j];
		}
	}
	
	//Initializing Matrix C
	cout<<"The multiplication of matrix A & B is:"<<endl;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			C[i][j] = 0;
		}
	}
	
	//Multiplying
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	
	//Displaying the Matrix
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<C[i][j]<<"		";
		}
		cout<<endl;
	}	
}

int main()
{
	mult();
	getch();
}
