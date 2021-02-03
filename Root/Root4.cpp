#include<iostream>
#include<fstream>
#include<cmath>
#include<conio.h>
using namespace std;
#define c  10.498597
//Approximated Root -2.3 and 2.3; Intersects only two points
ofstream fout("Root4.dat");

double f1(double x)
{
	return -1/tan(x);
}

double f2(double x)
{
	
	return sqrt(c - x*x)/x;
}

double f(double x)
{
	return sin(x)*sqrt(c - x*x) + x*cos(x);
}

double df(double x)
{
	return cos(x) - x*sin(x)*(1 + (1/sqrt(c - x*x)));
}

void plot()
{
	fout<<"x"<<"		"<<"-cot(x)"<<"		"<<"Potential"<<endl;
	for(double x=-2*M_PI;x<=2*M_PI;x+=0.01)
	{
		fout<<x<<"		"<<f1(x)<<"			"<<f2(x)<<endl;
	}
}

void newt(double x0)
{
	double h;
	h = f(x0)/df(x0);
	while(abs(h)>=0.000001)
	{
		x0 = x0 - h;
		h = f(x0)/df(x0);
	}
	cout<<"Root: "<<x0<<endl;
}

int main()
{
	plot();
	cout<<"Enter approximation: ";
	double x0;
	cin>>x0;
	newt(x0);
	getch();
}
