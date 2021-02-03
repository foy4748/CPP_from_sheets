#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration13_Fresnel.dat");
ofstream file("Integration13_Diffraction.dat");

double f1(double t)
{
	return cos(M_PI*t*t/2.0);
}

double f2(double t)
{
	return sin(M_PI*t*t/2.0);
}

double C(double x)
{
	double u = x*sqrt(2.0/3.0);
	
	double a = 0, b =  u;
	int i, N = 100;
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
	
	
	
	return (h/3)*(f1(a) + 4*I + 2*J + f1(b));
}

double S(double x)
{
	double u = x*sqrt(2.0/3.0);
	
	double a = 0, b =  u;
	int i, N = 100;
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
	
	return (h/3)*(f2(a) + 4*I + 2*J + f2(b));
}

double diffraction(double x)
{
	//double u = x*sqrt(2.0/3.0); //I used to forget this.
 return ((2.0*C(x) + 1)*(2.0*C(x) + 1) + (2.0*S(x) + 1)*(2.0*S(x) + 1))/8;	
 
}

int main()
{
	double x;
	fout<<"x"<<"		"<<"C(u)"<<"		"<<"S(u)"<<endl;
	file<<"x"<<"		"<<"Diffraction"<<endl;
	for(x=-5;x<5;x+=0.01)
	{
		fout<<x<<"		"<<C(x)<<"		"<<S(x)<<endl;
		file<<x<<"		"<<diffraction(x)<<endl;
	}
	
	
}

