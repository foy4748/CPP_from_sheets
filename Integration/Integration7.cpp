#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration7.dat");

double f(double t)
{
	return (2/sqrt(M_PI))*exp(-t*t);
}

double erf(double x)
{
	double a = 0, b = x;
	int i, N=100;
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
	
	return result;
}

int main()
{
	double x;
	fout<<"x"<<"		"<<"Error-Function"<<endl;
	for(x=-2.0;x<=2.0;x+=0.01)
	{
		fout<<x<<"		"<<erf(x)<<endl;
	}
}