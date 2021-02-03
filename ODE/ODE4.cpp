#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

ofstream fout("ODE4.dat");

double f(double t, double x)
{
	return t*sqrt(x);
}

double solution(double t)
{
		return (t*t + 4)*(t*t + 4)/16;
}

void RK(double t0, double x0, double h)
{
	double k1,k2,k3,k4;
	fout<<"Time"<<"		"<<"RK-Method"<<"		"<<"Solution"<<endl;
	for(double t=t0; t<10; t+=h)
	{
		k1 = h*f(t,x0);
		k2 = h*f(t + h/2, x0 + k1/2);
		k3 = h*f(t + h/2, x0 + k2/2);
		k4 = h*f(t +h, x0 + k3);
		
		x0 += (k1 + 2*(k2 + k3) + k4)/6;
		
		fout<<t<<"		"<<x0<<"		"<<solution(t)<<endl;
	}
}

int main()
{
	RK(0,1,0.01);
}