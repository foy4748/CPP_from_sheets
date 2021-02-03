#include<iostream>
#include<cmath>


using namespace std;

double F(double x)
{
	return x*x*x;
}

double P(double x, int n)
{
	if(n==0) return 1.0;
	else if(n==1) return x;
	else return ((2*n - 1)*x*P(x,n-1) - (n - 1)*P(x, n - 2))/n;
}

double dP(double x, int n)
{
	return (n/(x*x - 1))*(x*P(x,n) -  P(x, n - 1));
}

void GQ()
{
	double a = 2,  b = 3;
	int i, n = 20;
	double h;
	double c, result = 0;
	double x0[20], x[20], x_prime[20], w[20], w_prime[20];
	
	for(i=0;i<n;i++)
	{
		x0[i] = cos(M_PI*((i+1) - 0.25)/(n + 0.5));
		c = x0[i];
		h = P(c,n)/dP(c,n);
		while(abs(h)>=0.0000001)
		{
			c = c - h;
			h = P(c,n)/dP(c,n);
		}
		
		x[i] = c;
		w[i] = 2/((1 - c*c)*dP(c,n)*dP(c,n));
	}
	
	for(i=0;i<n;i++)
	{
		x_prime[i] = 0.5*(b-a)*x[i] + 0.5*(b+a);
		w_prime[i] = 0.5*(b-a)*w[i];
	}
	
	for(i=0;i<n;i++)
	{
		result += w_prime[i]*F(x_prime[i]);
	}
	
	cout<<result;
}

int main() 
{
	GQ();
}

		
	
	
