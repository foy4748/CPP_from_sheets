#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration4_Bessel.dat");
ofstream file("Integration4_Fresnel.dat");


double fact(int n)
{
	if(n==0) return 1.0;
	else return n*fact(n-1);
}

double f(double theta, double z, int n)
{
	double a = pow(z,n)/(pow(2, n+1)*fact(n));
	double b = cos(z*cos(theta));
	double c = pow(sin(theta), 2*n + 1);
	
	return a*b*c;
}


double j(double z, int n)
{
	double a = 0, b = M_PI;
	int i, N = 100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += f(a + i*h, z, n);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += f(a + i*h, z, n);
	}
	
	double result = (h/3)*(f(a,z,n) + 4*I + 2*J + f(b,z,n));
	return result;
}

double fresnel(double z)
{
	return j(z,0)*sqrt(z)/2;
}

double S(double x)
{
	double a = 0, b = x;
	int i, N = 100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += fresnel(a + i*h);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += fresnel(a + i*h);
	}
	
	double result = (h/3)*(fresnel(a) + 4*I + 2*J + fresnel(b));
	return result;
}

int main()
{
	fout<<"z"<<"		"<<"n=0"<<"			"<<"n=1"<<"			"<<"n=2"<<"		"<<"n=3"<<"		"<<"n=4"<<"		"<<"n=5"<<"		"<<endl;
	for(double z=0;z<=20;z+=0.01)
	{
		fout<<z<<"		"<<j(z,0)<<"		"<<j(z,1)<<"		"<<j(z,2)<<"		"<<j(z,3)<<"		"<<j(z,4)<<"		"<<j(z,5)<<"		"<<endl;
	}
	
	file<<"x"<<"		"<<"Spherical-Bessel-Function"<<endl;
	for(double x=0;x<=20;x+=0.01)
	{
		file<<x<<"			"<<S(x)<<endl;
	}
	
}