#include<iostream>
#include<cmath>
#include<conio.h>
#include<fstream>
using namespace std;

ofstream fout("Integration3.dat");
double f(double tau)
{
	double c = 2/sqrt(M_PI);
	return c*exp(-tau*tau);
}

void simp(double t)
{
	double a = 0, b =  8/sqrt(t);
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
	fout<<t<<"		"<<100*(1-result)<<endl;
}

int main()
{
	fout<<"Time"<<"		"<<"Tempurature"<<endl;
	for(double t=10;t<=200;t+=0.01)
		simp(t);
	
}