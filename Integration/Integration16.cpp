#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration16.dat");

double f(double x, double T)
{
	double V = 1000e-6;
	double ro = 6.022e28;
	double KB = 1.38e-23;
	double thetaD = 428.0;
	
	double a = 9*V*ro*KB/pow(thetaD,3);
	double b = pow(T,3.0)*pow(x,4)*exp(x);
	double c = pow((exp(x) - 1),2);
	
	return a*b/c;
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

double Cv(double T)
{
	double thetaD = 428.0;
	double a = 0, b = thetaD/T;
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
		result += w_prime[i]*f(x_prime[i],T);
	}
	
	return result;
}

int main()
{
	double T;
	fout<<"Tempurature"<<"			"<<"Specific-Heat"<<endl;
	for(T=5;T<=500;T+=0.1)
	{
		fout<<T<<"		"<<Cv(T)<<endl;
	}
}