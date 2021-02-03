#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Function3.dat");

void v()
{
	double m = 60.0, g = 9.8, b = 1.0, v0 = 15.0;
	double c = m*g/b;
	fout<<"Time"<<"			"<<"Velocity"<<endl;
	for(double t = 0; t<=100; t+=0.01)
	fout<<t<<"		"<< c + (v0 - c)*exp(-b*t/m)<<endl;
	
}

int main()
{
	v();
}