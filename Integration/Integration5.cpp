#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration5_Fresnel.dat");
ofstream file("Integration5_Diffraction.dat");

double f1(double u)
{
		return sin(M_PI*u*u/2);
}

double f2(double u)
{
		return cos(M_PI*u*u/2);
}

double S(double x)
{
	double a = 0, b = x;
	int i, N=100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += f1(a + i*h);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += f1(a + i*h);
	}
	
	double result = (h/3)*(f1(a) + 4*I + 2*J + f1(b));
	return result;
}

double C(double x)
{
	double a = 0, b = x;
	int i, N=100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += f2(a + i*h);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += f2(a + i*h);
	}
	
	double result = (h/3)*(f2(a) + 4*I + 2*J + f2(b));
	return result;
}

double diffraction(double u0)
{
	double a = pow((C(u0) + 0.5),2);
	double b = pow((S(u0) + 0.5),2);
	
	return 0.5*(a + b);
}

int main()
{
	double x, u0;
	fout<<"x"<<"		"<<"Fresnel-Sin"<<"		"<<"Fresnel-Cos"<<endl;
	for(x=0;x<=5;x+=0.01)
	{
		fout<<x<<"		"<<S(x)<<"		"<<C(x)<<endl;
	}
	
	file<<"u0"<<"		"<<"I/Io"<<endl;
	for(u0=-1.0;u0<=4.0;u0+=0.01)
	{
		file<<u0<<"			"<<diffraction(u0)<<endl;	
	}
}