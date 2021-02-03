#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>

using namespace std;

ofstream fout("Function20.dat");

double fact(int n)
{
	if(n>1) return n*fact(n-1);
	else return 1.0;
}

double ramanujan(int n)
{
	return sqrt(M_PI)*pow(n,n)*exp(-n)*pow((8.0*pow(n,3) + 4.0*pow(n,2) + n + (1/30.0)),0.1666666);
}

int main()
{
	//Labeling Data Column
	fout<<"Terms"<<"		"<<"Percentage-Error"<<endl;
	for(int n = 2; n<=12; n++)
	{
		fout<<n<<"		"<<abs(fact(n) - ramanujan(n))/fact(n)<<endl;
	}
	
	
}