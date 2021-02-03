#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration11_Bessel.dat");
ofstream file("Integration11_Radiation.dat");
double fact(int n)
{
	if(n==0) return 1.0;
	else return n*fact(n-1);
}

double f(double theta, double x, int n)
{
	double a = pow(x,n)/(pow(2,n+1)*fact(n));
	double b = cos(x*cos(theta))*pow(sin(theta), 2*n + 1);
	
	return a*b;
}

double Jn(double x, int n)
{
	double a = 0, b = M_PI;
	int i, N = 100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += 4.0*f(a + i*h, x, n);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += 2.0*f(a + i*h, x, n);
	}
	
	I += f(a,x,n);
	J += f(b,x,n);
	I += J;
	
	return (h/3)*I;
}

double ff(double r, double u)
{
	double a = 1 - pow(r,2.0);
	return a*Jn(u*r,0)*r;
}

double G(double u)
{
	double a = 0, b = 1.0;
	double I = 0, J = 0;
	int i, N = 100;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += 4.0*ff(a + i*h, u);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += 2.0*ff(a + i*h, u);
	}
	
	I += ff(a,u) + ff(b,u) + J;
	return h*I/3;
	
}
int main()
{
	double x;
	fout<<"x"<<"		"<<"n=0"<<"		"<<"n=1"<<"			"<<"n=2"<<"			"<<"n=3"<<endl;
	for(x=0;x<=10;x+=0.01)
	{
		fout<<x<<"		"<<Jn(x,0)<<"		"<<Jn(x,1)<<"		"<<Jn(x,2)<<"		"<<Jn(x,3)<<endl;
	}
	
	double u;
	file<<"Distance"<<"		"<<"Radiation"<<endl;
	for(u=0;u<=25;u+=0.01)
	{
		file<<u<<"		"<<G(u)<<endl;
	}
}