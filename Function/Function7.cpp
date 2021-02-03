#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>
using namespace std;

ofstream fout("Function7.dat");

double f(double b, int n)
{
	if(n==0) return 1.0;
	else return 0.5*(f(b,n-1) + b/f(b,n-1));
}

int main()
{
	fout<<"Number_of_Iteration"<<"			"<<"Difference"<<endl;
	for(double n=1;n<=20;n++)
	{
		fout<<n<<"		"<<abs(f(100,n)-sqrt(100))<<endl;
	}
}