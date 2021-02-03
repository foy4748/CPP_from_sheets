#include<iostream>
#include<cmath>
#include<fstream>


using namespace std;

ofstream fout("Function21.dat");

double taninv(double x, int n)
{
	int i; double sum = 0.0;
	
	for(i=1;i<=n;i++)
	{
		sum += pow(-1, i+1)*pow(x, 2*i - 1)/(2*i - 1);
	}
	
	return sum;
}

int main()
{
	int n;
	//Labeling Data Columns
	fout<<"Terms"<<"		"<<"Difference"<<endl;
	for(n=10;n<=1000;n++)
	{
		fout<<n<<"		"<<abs(taninv(1,n) - atan(1))<<endl;
	}
}