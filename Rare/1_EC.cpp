#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("1_EC.dat");

//Defining functions
double F(double x)
{
	double omega = 4.2;
	
	return -omega*omega*x;
}

void EC()
{
	//Initial Values
	double x = 0, z = 1, t, h = 0.01;
	
	//Labeling Data Columns
	fout<<"Time"<<"		"<<"Position"<<"		"<<"Velocity"<<endl;
	
	
	for(t=0;t<=10;t+=h)
	{
		//Printing datas to file
		fout<<t<<"		"<<x<<"		"<<z<<endl;
		
		//Applying Euler-Cromer Rule
		z += F(x)*h;
		x += z*h;
	}
	
}

int main() { EC();}