#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;

ofstream fout("Function11.dat");

double h(double t)
{
	double g  = 9.8;
	double k  = 0.1;
	double h0 = 300;
	double m  = 0.25;
	
	double result = h0 - (m*g/k)*t + (pow(m/k,2)*g)*(1 - exp(-k*t/m));
	
	return result;
}

double dh(double t)
{
	double g  = 9.8;
	double k  = 0.1;
	double m  = 0.25;
	
	return (m*g/k)*(exp(-k*t/m) - 1);
}

double newt(double t0)
{
	double hh;
	
	hh = h(t0)/dh(t0);
	while(abs(hh)>=0.000000001)
	{
		t0 = t0 - hh;
		hh = h(t0)/dh(t0);
	}
	
	return t0;
}

int main()
{
	double t;
	fout<<"Time"<<"			"<<"Height"<<endl;
	for(t=0;t<=20;t+=0.01)
	{
		fout<<t<<"			"<<h(t)<<endl;
	}
	
	cout<<"Approximated time for hitting the ground is: 14"<<endl;
	cout<<setprecision(10)<<"Accurate time for hitting the ground is: "<<newt(14.7);
	getch();
}