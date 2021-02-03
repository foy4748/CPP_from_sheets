#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>
using namespace std;

ofstream fout("Function17.dat");

double fact(int n)
{
	double mult = 1.0;
	for(int i=0;i<=n;i++)
	{
		mult *=(2*i + 1);
	}
	
	return mult;
}

double erf(double x, int k)
{
	double sum = 0.0;
	for(int i=0;i<=k;i++)
	{
		sum += pow(2.0,i)*pow(x, 2*i + 1)/fact(i);
	}
	
	return 2.0*exp(-pow(x,2))*sum/sqrt(M_PI);
}


int main()
{
	fout<<"x"<<"		"<<"erf(x)"<<endl;
	for(double x = -2.0;x<=2.0;x+=0.01)
	{
		fout<<x<<"		"<<erf(x,20)<<endl;
	}
}