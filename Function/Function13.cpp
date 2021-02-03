#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ofstream fout("Function13.dat");

double x(double t, double b)
{
	double A = 1.0;
	double m = 1.0;
	double k = 4.0;
	double omega = sqrt(k/m - (pow(b,2)/(4*m*m)));
	double phi = 0.0;
	
	return A*exp(-(b*t)/(2.0*m))*cos(omega*t + phi);
}

int main()
{
	double t;
	fout<<"Position"<<"			"<<"b=0.3"<<"		"<<"b=4.0"<<endl;
	for(t=0;t<=40;t+=0.01)
	{
		fout<<t<<"		"<<x(t,0.3)<<"			"<<x(t,4.0)<<endl;
	}
}