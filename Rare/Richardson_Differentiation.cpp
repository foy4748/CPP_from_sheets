#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;

ofstream fout("test.txt");

double F(double x)
{
	return sin(x);
}

double richard(double x)
{
	//			Number of iterations
	int i,j, 	N = 10;
	
	//		Step size
	double	h = 1.00;
	
	//For storing iteration values
	double D[N][N];
	
	double f = 1.000;
	
	for(i=0; i<N; i++)
	{
		//Calculating the first column
		D[i][0] = (F(x + h) - F(x - h))/(2.000*h);
		
		for(j=0; j<i; j++)
		{
			f *= 4.000;
			
			//Calculating other columns
			D[i][j+1] = (f*D[i][j] - D[i-1][j])/(f - 1.000);
		}
		h = h/2.00;	//Halving the step size
	}
	
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	
	fout<<setprecision(6);
	for(i=0; i<N; i++)
	{
		for(j=0; j<i; j++)
		{
			fout<<setw(6+2)<<D[i][j]<<"\t";
		}
		fout<<endl;
	}
	
	fout.unsetf(ios::fixed);
	fout.unsetf(ios::showpoint);
	
	return D[N-2][N-2];
}

int main()
{
	double q = M_PI/4;
	cout<<"\n Derivative of sin(x) at x = pi/4 is: "<<richard(q)<<endl;
}