#include<iostream>
#include<cmath>
#include<conio.h>

using namespace std;

#define e 0.00000001
double f(double x, double n)
{
	return x - sqrt(n);
}



//Bisection Method
void bisection(double a, double b, double n)
{
	double c;
	c = (a+b)/2;
	while(abs(b-c)>=e)
	{
		if(f(a,n)*f(c,n)<0) b = c;
		else a = c;
		c = (a+b)/2;
	}
	
	cout<<"Bisection Result: "<<c<<endl;
}

//Newton Raphson Method
void newt(double x0, double n)
{
	double h;
	h = f(x0,n)/1;
	while(abs(h)>e)
	{
		x0 = x0 - h;
		h = f(x0,n)/1;
	}
	cout<<"Newton-Raphson Result: "<<x0<<endl;
}

//Secant Method
void secant(double a, double b, double n)
{
	double c;
	c = (a*f(b,n) - f(a,n)*b)/(f(b,n) - f(a,n));
	while(abs(b-c)>=e)
	{
		a = b;
		b = c;
		c = (a*f(b,n) - f(a,n)*b)/(f(b,n) - f(a,n));
	}
	cout<<"Secant Result: "<<c<<endl;
}

int main()
{
	cout<<"n = ";
	double n;
	cin>>n;
	cout<<"Interval = ";
	double a,  b;
	cin>>a>>b;
	cout<<"Enter close approximation: ";
	double x0;
	cin>>x0;
	bisection(a,b,n);
	newt(x0,n);
	secant(a,b,n);
	getch();
}