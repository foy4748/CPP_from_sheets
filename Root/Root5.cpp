#include<iostream>
#include<fstream>
#include<cmath>
#include<conio.h>

using namespace std;
#define J 100
#define T 10
ofstream fout("Root5.dat");

double f1(double m)
{
	return m;
}

double f2(double m)
{
	return tanh(10*m);
}

void plot()
{	fout<<"magnetization"<<"		"<<"m"<<"		"<<"tanh(J*m/T)"<<endl;
	for(double m=-3.0;m<=3.0;m+=0.01)
	{
		fout<<m<<"		"<<f1(m)<<"			"<<f2(m)<<endl;
	}
}

double f(double m)
{
	return f1(m) - f2(m);
}

double df(double m)
{
	return 1 - ((J/T)*(1-pow(tanh((J*m)/T),2)));
}

void newt(double m0)
{
	double h;
	h = f(m0)/df(m0);
	while(abs(h)>=0.0000001)
	{
		m0 = m0 - h;
		h = f(m0)/df(m0);
	}
	cout<<"Root: "<<m0<<endl;
}

int main()
{	
	cout<<"Enter approximation: ";
	double m0;
	cin>>m0;
	plot();
	newt(m0);
	getch();
}