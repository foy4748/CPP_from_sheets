#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>

using namespace std;

ofstream fout("RK.txt");

double F(double x, double v)
{
	return -16.0*x - 4.0*v;
}

double L(double t_any)
{
	//Necessary Variables
	int i,j, N = 501;
	double t[N], x[N], v[N], h = 0.01;
	double k[N][4], l[N][4];
	double D[N];
	
	//Initializing
	t[0] = 0; x[0] = 0.5; v[0] = 0;
	
	//Executing Runge-Kutta Rule
	for(i=0;i<N;i++)
	{
		k[i][0] = h*v[i];
		l[i][0] = h*F(x[i],v[i]);
		
		k[i][1] = h*(v[i] + l[i][0]/2.0);
		l[i][1] = h*F(x[i] + k[i][0]/2.0, v[i] + l[i][0]/2.0);
		
		k[i][2] = h*(v[i] + l[i][1]/2.0);
		l[i][2] = h*F(x[i] + k[i][1]/2.0, v[i] + l[i][1]/2.0);
		
		k[i][3] = h*(v[i] + l[i][2]);
		l[i][3] = h*F(x[i] + k[i][2], v[i] + l[i][2]);
		
		x[i+1] = x[i] + (k[i][0] + 2.0*k[i][1] + 2.0*k[i][2] + k[i][3])/6.0;
		v[i+1] = v[i] + (l[i][0] + 2.0*l[i][1] + 2.0*l[i][2] + l[i][3])/6.0;
		t[i+1] = t[i] + h;
	}
	
	//Applying Lagrange Interpolation
	double p, sum = 0.0;
	
	for(i=0; i<=N; i++)
	{
		p = 1.00;
		for(j=0; j<=N; j++)
		{
			if(i!=j)
			{
				p *= (t_any - t[j])/(t[i] - t[j]);
			}
		}
		sum += p*x[i];
	}
	
	return sum;
}

double der(double t_any)
{
	double h = 0.1;
	return (L(t_any + h) - L(t_any - h))/(2.00*h);
}

double newt(double t0)
{
	double h;
	h = L(t0)/der(t0);
	while(abs(h)>=0.0000000001)
	{
		t0 = t0 - h;
		h = L(t0)/der(t0);
	}
	return t0;
}

void output()
{
	double t;
	for(t=0;t<=5.00;t+=0.01)
	{
		fout<<t<<"		"<<L(t)<<endl;
	}
}
	
int main()
{
	output();
	cout<<newt(2.41769);
	getch();
}
	

	
	
		