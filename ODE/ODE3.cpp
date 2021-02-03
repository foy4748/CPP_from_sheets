#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

#define g 9.8

ofstream fout("ODE3_Euler.dat");
ofstream file("ODE3_Euler_Cromer.dat");

double f(double t, double theta)
{
	return -g*theta;
}

void euler(double t0, double theta0, double omega0, double h)
{
	fout<<"Time"<<"		"<<"Angular_Position"<<"		"<<"Angular_Velocity"<<endl;
	for(double t=t0; t<20; t+=h)
	{
		double omegaOld = omega0;
		omega0 += f(t,theta0)*h;
		theta0 += omegaOld*h;
		fout<<t<<"		"<<theta0<<"		"<<omega0<<endl;
	}
}

void euler_cromer(double t0, double theta0, double omega0, double h)
{
	file<<"Time"<<"		"<<"Angular_Position"<<"		"<<"Angular_Velocity"<<endl;
	for(double t=t0; t<20; t+=h)
	{
		
		omega0 += f(t,theta0)*h;
		theta0 += omega0*h;
		file<<t<<"		"<<theta0<<"		"<<omega0<<endl;
	}
}


int main()
{
	euler(0,0,1,0.01);
	euler_cromer(0,0,1,0.01);
}