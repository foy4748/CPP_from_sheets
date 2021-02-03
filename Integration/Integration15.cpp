#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ofstream fout("Integration15.dat");

double V(double x)
{
	return pow(x,4);
}

double f(double x, double A)
{
	double m = 1.0;
	double a = sqrt(8*m);
	double b = sqrt(V(A) - V(x));
	
	return a/b;
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

double gauss(double A)
{
	double a = 0, b = A;
	int i, N = 20;
	double x0[N], x[N], x_prime[N], w[N], w_prime[N];
	double c, h, result = 0;
	
	for(i=0;i<N;i++)
	{
		x0[i] = cos(M_PI*((i+1) - 0.25)/(N + 0.5));
		c = x0[i];
		h = P(c,N)/dP(c,N);
		
		while(abs(h)>=0.0000001)
		{
			c = c - h;
			h = P(c,N)/dP(c,N);
		}
		
		x[i] = c;
		w[i] = 2/((1 - pow(c,2))*pow(dP(c,N),2));
	}
	
	for(i=0;i<N;i++)
	{
		x_prime[i] = 0.5*(b - a)*x[i] + 0.5*(b + a);
		w_prime[i] = 0.5*(b - a)*w[i];
	}
	
	for(i=0;i<N;i++)
	{
		result += w_prime[i]*f(x_prime[i],A);
	}
	
	return result;
}

int main()
{
	double A;
	fout<<"Amplitude"<<"		"<<"Time-Period"<<endl;
	for(double A=0; A<=2; A+=0.01)
	{
		fout<<A<<"		"<<gauss(A)<<endl;
	}
}