#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("2_RK.dat");

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

void RK()
{
	//Initial Values
	double L = 1.0, v = 0, theta = 0.3, omega = 0;
	
	//Necessary Variables
	double k1,k2,k3,k4,   l1,l2,l3,l4,  m1,m2,m3,m4,  n1,n2,n3,n4;
	double t, h = 0.01;
	
	//Labeling Data columns
	fout<<"Time"<<"		"<<"String-Length"<<"		"<<"Angular-Position"<<endl;
	for(t=0;t<20;t+=h)
	{
		//Printing datas to file
		fout<<t<<"		"<<L<<"		"<<theta<<endl;
		
		//Applying Runge-Kutta method
		k1 = h*v;
		l1 = h*F(L,theta,omega);
		m1 = h*omega;
		n1 = h*G(L,v,theta, omega);
		
		k2 = h*(v + l1/2);
		l2 = h*F(L + k1/2,theta + m1/2, omega + n1/2);
		m2 = h*(omega + n1/2);
		n2 = h*G(L + k1/2, v + l1/2, theta + m1/2, omega + n1/2);
		
		k3 = h*(v + l2/2);
		l3 = h*F(L + k2/2,theta + m2/2, omega + n2/2);
		m3 = h*(omega + n1/2);
		n3 = h*G(L + k2/2, v + l2/2, theta + m2/2, omega + n2/2);
		
		k4 = h*(v + l3);
		l4 = h*F(L + k3,theta + m3, omega + n3);
		m4 = h*(omega + n3);
		n4 = h*G(L + k3, v + l3, theta + m3, omega + n3);
		
		L += (k1 + 2.0*k2 + 2.0*k3 + k4)/6;
		v += (l1 + 2.0*l2 + 2.0*l3 + l4)/6;
		theta += (m1 + 2.0*m2 + 2.0*m3 + m4)/6;
		omega += (n1 + 2.0*n2 + 2.0*n3 + n4)/6;
	
	}
	
}

int main() { RK(); }