#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("1_RK.dat");

//Defining functions
double F(double x)
{
	double omega = 4.2;
	
	return -omega*omega*x;
}

void RK()
{
	//Necessary Variables
	double k1,k2,k3,k4, l1,l2,l3,l4;
	
	//Initial Values
	double x = 0, z = 1.0, t, h = 0.01;
	
	//Labeling Data Columns
	fout<<"Time"<<"		"<<"Position"<<"		"<<"Velocity"<<endl;
	
	for(t=0;t<10;t+=h)
	{
		//Printing datas to file
		fout<<t<<"		"<<x<<"		"<<z<<endl;
		
		//Applying Runge-Kutta method
		k1 = h*z;
		l1 = h*F(x);
		
		k2 = h*(z + l1/2);
		l2 = h*F(x + k1/2);
		
		k3 = h*(z + l2/2);
		l3 = h*F(x + k2/2);
		
		
		k4 = h*(z + l3);
		l4 = h*F(x + k3);
		
		x += (k1 + 2.0*k2 + 2.0*k3 + k4)/6;
		z += (l1 + 2.0*l2 + 2.0*l3 + l4)/6;
	}	
}

int main() { RK(); }