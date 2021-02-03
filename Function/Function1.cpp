#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ofstream fout("Function1.dat");

void a()
{
	double F  = 12.0;
	double m  = 3.0;
	double uk = 0.4;
	double g  = 9.8;
	double theta;
	
	fout<<"Angle"<<"		"<<"Acceleration"<<endl;
	for(theta=0.0; theta<=M_PI/2.0; theta+=0.01)
	fout<<theta<<"		"<<(F/m)*cos(theta) - uk*(g - (F/m)*sin(theta))<<endl;
	
}

int main()
{
	
	
	a();
}