#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;

double f(double z)
{
	double x  = z/(1 - z);
	double dx = 1/pow((1 - z),2);
	
	return exp(-x*x)*dx;
}

double P(double x, int n)
{
	if(n==0) return 1.0;
	else if(n==1) return x;
	else return ((2*n - 1)*x*P(x,n-1) - (n - 1)*P(x,n-2))/n;	
}

double dP(double x, int n)
{
	return (n/(pow(x,2) - 1))*(x*P(x,n) - P(x,n-1));
}

void gauss(double a, double b)
{
	int i, n = 20;
	double x0[n], x[n], x_prime[n], w[n], w_prime[n];
	double c,h, result = 0;
	
	for(i=0;i<n;i++)
	{
		x0[i] = cos(M_PI*((i+1) - 0.25)/(n + 0.5));
		c = x0[i];
		h = P(c,n)/dP(c,n);
		
		while(abs(h)>=0.00000000001)
		{
			c = c - h;
			h = P(c,n)/dP(c,n);
		}
		
		x[i] = c;
		w[i] = 2/((1 - c*c)*pow(dP(c,n), 2));
	}
	
	for(i=0;i<n;i++)
	{
		x_prime[i] = 0.5*(b-a)*x[i] + 0.5*(b+a);
		w_prime[i] = 0.5*(b-a)*w[i];
	}
	
	for(i=0;i<n;i++)
	{
		result += w_prime[i]*f(x_prime[i]);
	}
	
	cout<<setprecision(14)<<"Integration result using Gaussian Quadrature is: "<<result<<endl;
}

int main()
{
	gauss(0,1);
	getch();
}
