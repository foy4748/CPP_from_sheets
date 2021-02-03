#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration8.dat");

double f(double x)
{
	
	double b = exp(-x*x/2);
	return b;
}

double I(double A)
{
	double a = -A, b = A;
	double i, N=100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += f(a + i*h);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += f(a + i*h);
	}
	
	double result = (h/3)*(f(a) + 4*I + 2*J + f(b));
	return (1/sqrt(2*M_PI))*result;
}

int main()
{
	double a;
	fout<<"a"<<"	"<<"Error-Function"<<endl;
	for(double a=-4.0;a<=4.0;a+=0.001)
	{
		fout<<a<<"		"<<abs(I(a))<<endl;
	}
}