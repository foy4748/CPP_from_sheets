#include<iostream>
#include<cmath>
#include<conio.h>
#include<fstream>
using namespace std;

ofstream fout("Function2.dat");

void PI()
{
	int n = 1000;
	double sum = 0;
	int i;
	fout<<"Terms"<<"		"<<"Difference"<<endl;
	for(i=0;i<n;i++)
	{
		sum += 4.0*pow(-1.0,i)/(2*i+1);
		
		fout<<i<<"		"<<abs(M_PI - sum)<<endl;
	}
	
	cout<<sum;
}

int main()
{
	PI();
	getch();
}