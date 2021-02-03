#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("2_EC.dat");

//Defining functions
double F(double L, double theta, double omega)
{
	double L0 = 1.0, k = 3.5, m = 0.2, g = 9.8;
	return (L0 + L)*omega*omega - (k/m)*L + g*cos(theta);
}

double G(double L, double v, double theta, double omega)
{
	double L0 = 1.0, g = 9.8;
	return (-1/(L0 + L))*(g*sin(theta) + 2*v*omega);
}

void EC()
{
	//Initial Values & Necessary Variables
	double L0 = 1.0, L = 1.0, v = 0, theta = 0.3, omega = 0;
	double t, h = 0.01;
	
	//Labeling Data columns
	fout<<"Time"<<"		"<<"String-Length"<<"		"<<"Angular-Position"<<endl;
	
	//Applying Euler-Cromer Rule
	for(t=0;t<20;t+=h)
	{
		//Printing datas to file
		//fout<<t<<"		"<<L<<"		"<<theta<<endl;
		fout<<(L0+L)*sin(theta)<<"		"<<(L0+L)*cos(theta)<<endl;
		
		//First updating velocities
		omega += h*G(L,v,theta,omega);
		v += h*F(L,theta,omega);
		
		//Using updated velocites to calculate positions
		L += v*h;
		theta += omega*h;
	}
	
}

int main() { EC(); }