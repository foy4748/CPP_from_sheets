#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>
using namespace std;



double S(double T,double V, double m)
{
	double N  = 6.023e23;
	double KB = 1.38e-23;
	double h  = 6.63e-34;
	
	double U = (3.0/2.0)*N*KB*T;
	
	double a = 4*M_PI*m*U;
	double b = 3*N*pow(h,2);
	double c = (V/N);
	
	return N*KB*((3.0/2.0)*log(c*(a/b)) + 5.0/2.0);
}

int main()
{
	double T = 300;
	double V = 0.025;
	double m = 6.64217e-27;
	
	cout<<S(T,V,m);
	getch();
}