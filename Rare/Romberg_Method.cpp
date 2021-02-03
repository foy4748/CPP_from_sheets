#include<iostream>
#include<conio.h>
#include<cmath>
#include<fstream>
using namespace std;

//Creating file for data storage
ofstream fout("test.txt");

//Integral Function
double F(double x)
{
	return x*x;
}
//-----------------

//Romberg Method for Calculating Integrals
double Romberg(double A, double B)
{
	int i,j,k;					//For indexing
	
	int kmax = 30; 				//Number of Iterations
	double eps = 0.00000001;	//Accuracy
	
	double sum;					//For summation
	
	//		Romberg Array		Step size	For Halving the Steps
	double R[kmax+1][kmax+1],	h[kmax+1],	n[kmax+1];
	
	n[0] = 1.00;			//n[k] = 2^k, here k=0, 
	h[0] = (B - A)/n[0]; 	//Stepsize for n[0] = 1.00
	
	//First Array Element i.e. (0,0)th element
	R[0][0] = h[0]*(0.5*F(A) + 0.5*F(B));	
	//-----------------------------------
	
	//Calculating the first column of the arrray i.e. (k,0)th elements
	for(k = 0; k<kmax; k++)
	{
		sum = 0.0;				//Reset initial sum value before each iterations
		
		n[k+1] = pow(2,k+1);	
		h[k+1] = h[0]/n[k+1];
		
		
		for(i=1; i<= n[k]; i++)
		{
			sum += F(A + (i-double(1/2))*h[k]);
		}
		
		R[k+1][0] = double(0.5)*(R[k][0] + h[k]*sum);
		
	}	
	//-------------------------------------------------------------------
	
	
	//Calculating the rest of the elements
	for(k=1; k<kmax; k++)
	{
		for(j = 1; j <= k; j++)
		{
			R[k][j] = (pow(4,j)*R[k][j-1] - R[k-1][j-1])/(pow(4,j) - 1);		
		}
		
	}
	//-------------------------------------
	
	//Writing the elements in a file
	for(i=0;i<kmax;i++)
	{
		for(j=0;j<=i;j++)
		{
			fout<<R[i][j]<<"		";
			//fout<<"("<<i<<","<<j<<")"<<"	";
		}
		fout<<endl;
	}
	//------------------------------
	
	return R[kmax-1][kmax-1];	//Returning last element as the answer
	
	
}
//----------------------------------------	


int main()
{
	cout<<Romberg(0,4);	
	getch();
}