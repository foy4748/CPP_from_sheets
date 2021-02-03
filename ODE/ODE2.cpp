#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("ODE2.dat");

double f(double t, double y)
{
	return y - 0.5*exp(t/2)*sin(5*t) + 5*exp(t/2)*cos(5*t);
}

double solution(double t)
{
	return exp(t/2)*sin(5*t);
}

void euler(double t0, double y0, double h)
{
	fout<<"Time"<<"		"<<"Euler-Method"<<"	"<<"Solution"<<endl;
	for(double t=t0; t<=5; t+=h)
	{
		y0 += f(t,y0)*h;
		fout<<t<<"		"<<y0<<"		"<<solution(t)<<endl;
	}
}

int main()
{
	euler(0,0,0.1);
}