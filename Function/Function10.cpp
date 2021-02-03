#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Function10.dat");

double mysin(double x,double k)
{
	double mult = 1.0;
	int i;
	
	for(i=1;i<k;i++)
	{
		mult *=(1 - (pow(x,2)/(pow(i,2)*pow(M_PI,2))));
	}
	
	return x*mult;
}

int main()
{
	double x;
	int i;
	fout<<"Terms"<<"		"<<"PI/4"<<"		"<<"PI/2"<<endl;
	for(i=10;i<=100;i++)
	{
		fout<<i<<"		"<<abs(mysin(M_PI/4.0, i) - sin(M_PI/4.0))<<"			"<<abs(mysin(M_PI/2.0, i) - sin(M_PI/2.0))<<endl;
	}
}