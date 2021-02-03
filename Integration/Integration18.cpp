#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

ofstream fout("Integration18.dat");

double fact(int n) //Determines Factorial
{
	if(n==0) return 1;
	else return n*fact(n-1);
}

double P(double x, int n) //Legendre Function
{
	if(n==0) return 1.0;
	else if(n==1) return x;
	else return ((2*n - 1)*x*P(x,n-1) - (n - 1)*P(x,n-2))/n;	
}

double dP(double x, int n) //Derivative of Legendre Function
{ 
	return (n/(x*x - 1))*(x*P(x,n) - P(x,n-1));
}

double H(double x, int n) //Hermite Function
{
	if(n==0) return 1;
	else if(n==1) return 2*x;
	else return 2*x*H(x,n-1) - 2*(n - 1)*H(x,n-2);
}

double u(double x, int n)
{
	double a = 1.0/sqrt(pow(2,n)*fact(n)*sqrt(M_PI));
	double b = exp(-(x*x)/2);
	
	return a*H(x,n)*b;
}



double f(double z, int n, int m)
{
	double x  = z/(1 - z*z);
	double dx = (1 + z*z)/((1-z*z)*(1-z*z));
	
	return u(x,n)*u(x,m)*dx;
}



double gauss(int n, int m) //Initiating Gaussian Quadrature Rule
{
	double a = -1, b = 1;
	int i, N = 20;
	double x0[N], x[N], x_prime[N], w[N], w_prime[N];
	double c, h, result = 0;
	
	for(i=0;i<N;i++)
	{
		x0[i] = cos(M_PI*((i+1) - 0.25)/(N + 0.5));
		c = x0[i];
		h = P(c,N)/dP(c,N);
		
		while(abs(h)>=0.00000001)
		{
			c = c - h;
			h = P(c,N)/dP(c,N);
		}
		
		x[i] = c;
		w[i] = 2/((1 - c*c)*dP(c,N)*dP(c,N));
		
	}
	
	for(i=0;i<N;i++)
	{
		x_prime[i] = 0.5*(b-a)*x[i] + 0.5*(b+a);
		w_prime[i] = 0.5*(b-a)*w[i];
	}
	
	for(i=0;i<N;i++)
	{
		result += w_prime[i]*f(x_prime[i],n,m);
	}
	
	return result;
}

int main()
{
	int n,m;
	
	fout.setf(ios::fixed);
	fout.setf(ios::showpoint);
	for(n=0;n<=5;n++)
	{
		for(m=0;m<=5;m++)
		{
			fout<<gauss(n,m)<<"		";
		}
		fout<<endl;
	}
	fout.unsetf(ios::fixed);
	fout.unsetf(ios::showpoint);
}
	