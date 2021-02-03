#include<iostream>
#include<fstream>
#include<cmath>
#include<conio.h>
using namespace std;

ofstream fout("Root3.dat");

double f1(double beta)
{
	return beta;
}

double f2(double beta)
{
	return tan(beta);
}

double f(double beta)
{
	return sin(beta) - beta*cos(beta) ;
}

double df(double beta)
{
	return beta*sin(beta);
}

void plot()
{
	fout<<"beta"<<"		"<<"beta"<<"		"<<"tan(beta)"<<endl;
	for(double theta=-10*M_PI;theta<=10*M_PI; theta+=0.01)
	{
		fout<<theta<<"		"<<f1(theta)<<"		"<<f2(theta)<<endl;
	}
}

void newt(double theta0)
{
	double h;
	h = f(theta0)/df(theta0);
	while(abs(h)>=0.000001)
	{
		theta0 = theta0 - h;
		h = f(theta0)/df(theta0);
	}
	cout<<"Root: "<<theta0<<endl;
}

int main()
{
	cout<<"Enter approximated root: "<<endl;
	double x0;
	cin>>x0;
	plot();
	newt(x0);
	
	getch();
}


