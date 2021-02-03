#include<iostream>
#include<conio.h>
#include<fstream>
#include<cmath>
using namespace std;
#define e 0.0000001
double f(double x)
{
	// return x*exp(x) - 1; 	//Interval -0.5, 1; approximated 0.5;
	// return cos(x) - x*exp(x); //Interval -9, -6; approximated -7.8;
	// return x - exp(-x); 		//Interval -1,1; approximated 0.5;
	return x*sin(x) + cos(x); //Interval -7,-5; approximated -6.1
}

double df(double x)
{
	// return x*exp(x) + exp(x);
	// return -sin(x) - (x*exp(x) + exp(x));
	// return 1 + exp(-x);
	return x*cos(x);
}


void plot()
{	
	ofstream fout("Root1.dat");
	for(double x=-10;x<=10;x+=0.01)
	{
		fout<<x<<"		"<<f(x)<<endl;
	}
}

//Bisection Method
void bisection(double a, double b)
{
	
	double c;
	c = (a+b)/2;
	while(abs(b-c)>=e)
	{
		if(f(a)*f(c)<0) b = c;
		else a = c;
		c = (a+b)/2;
	}
	cout<<"Bisection Root:  "<<c<<endl;
}
//Newton Raphson Method
void newton_raphson(double x0)
{
	double h;
	h = f(x0)/df(x0);
	while(abs(h)>=e)
	{
		x0 = x0 - h;
		h = f(x0)/df(x0);
	}
	cout<<"Newton Raphson Root: "<<x0<<endl;
}

//Secant Method
void secant(double a, double b)
{
	double c;
	c = (a*f(b) - f(a)*b)/(f(b) - f(a));
	while(abs(b-a)>=e)
	{
		a = b;
		b = c;
		c = (a*f(b) - f(a)*b)/(f(b) - f(a));
	}
	cout<<"Secant result:  "<<c<<endl;
}

int main()
{	
	plot();
	double a,b,c;
	cout<<"Enter approximated interval: ";
	cin>>a>>b;
	cout<<"Enter approximated root: ";
	cin>>c;
	bisection(a,b);
	newton_raphson(c);
	secant(a,b);
	getch();
}
