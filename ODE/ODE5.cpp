#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;
#define k 150
#define m 7.2
ofstream fout("ODE5.dat");

double f(double x)
{
	return -k*x/m;
}

void RK(double t0, double x0, double v0, double h)
{
	double k1,k2,k3,k4;
	double l1, l2, l3, l4;
	fout<<"Time"<<"		"<<"Position"<<"		"<<"Velocity"<<endl;
	for(double t=t0; t<10; t+=h)
	{
		k1 = h*v0;
		l1 = h*f(x0);
		
		k2 = h*(v0 + l1/2);
		l2 = h*f(x0 + k1/2);
		
		k3 = h*(v0 + l2/2);
		l3 = h*f(x0 + k2/2);
		
		k4 = h*(v0 + l3);
		l4 = h*f(x0 + k3);
		
		x0 += (k1 + 2*(k2 + k3) + k4)/6;
		v0 += (l1 + 2*(l2 + l3) + l4)/6;
		
		fout<<t<<"		"<<x0<<"		"<<"		"<<v0<<endl;
		
	}
}

int main()
{
	RK(0,0.5,4,0.01);
}