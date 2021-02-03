#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration6.dat");

double f(double theta, double A)
{
	double n = A*cos(theta) + 1;
	double d = pow((A*A + 2*A*cos(theta) + 1), 2);
	double a = 0.5*sin(theta);
	
	return n*a/d;
}

double u(double A)
{
	double a = 0, b = M_PI;
	int i, N = 100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += f(a + i*h, A);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += f(a + i*h, A);
	}
	
	double result = (h/3)*(f(a,A) + 4*I + 2*J + f(b,A));
	return result;
}

int main()
{
	double A;
	fout<<"Mass-Number"<<"			"<<"Cosine-of-Scattering-Angle"<<endl;
	for(A=2;A<=20;A+=0.01)
	{
		fout<<A<<"			"<<u(A)<<endl;
	}
	
}