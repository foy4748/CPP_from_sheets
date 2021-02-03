#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration12_Period.dat");
ofstream file("Integration12_Elliptic.dat");

double f1(double theta, double m)
{
	return 1/sqrt(1 - m*pow(sin(theta),2));
}

double f2(double theta, double m)
{
	return sqrt(1 - m*pow(sin(theta),2));
}

double K(double m)
{
	double a = 0, b = M_PI/2;
	int i, N = 100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += f1(a + i*h, m);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += f1(a + i*h, m);
	}
	
	return (h/3)*(f1(a,m) + 4*I + 2*J + f1(a,m));
}

double E(double m)
{
	double a = 0, b = M_PI/2;
	int i, N = 100;
	double I = 0, J = 0;
	double h = (b-a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += f2(a + i*h, m);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += f2(a + i*h, m);
	}
	
	return (h/3)*(f2(a,m) + 4*I + 2*J + f2(a,m));
}

double T(double thetaM)
{	
	double a = 4*sqrt(0.0254);
	double b = pow(sin(thetaM/2),2);
	
	return a*K(b);
	
}

int main()
{
	double thetaM;
	fout<<"angle"<<"		"<<"Time-Period"<<endl;
	for(thetaM=0;thetaM<=M_PI/2.0;thetaM+=0.01)
	{
		fout<<thetaM<<"			"<<T(thetaM)<<endl;
	}
	
	double m;
	file<<"m"<<"		"<<"K(m)"<<"		"<<"E(m)"<<endl;
	for(m=0.0;m<=1.0;m+=0.01)
	{
		file<<m<<"		"<<K(m)<<"		"<<E(m)<<endl;
	}
}
