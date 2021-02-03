#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Function16.dat");

double mycos(double x, double k)
{
	double mult = 1.0;
	
	int i;
	for(i=1;i<k;i++)
	{
		mult *= (1 - (4.0*pow(x,2))/(pow((2*i - 1),2)*pow(M_PI,2)));
	}
	
	return mult;
}

int main()
{
	fout<<"Terms"<<"		"<<"x=PI/4.0"<<"		"<<"x=PI/3.0"<<endl;
	for(int i=10;i<=100;i++)
	{
		fout<<i<<"		"<<abs(cos(M_PI/4.0) - mycos(M_PI/4.0,i))<<"		"<<abs(cos(M_PI/3.0) - mycos(M_PI/3.0,i))<<endl;
	}
}