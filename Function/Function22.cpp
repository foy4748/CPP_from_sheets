#include<iostream>
#include<cmath>
#include<fstream>


using namespace std;

ofstream fout("Function22.dat");

double Zeta(int s)
{
	int i;
	double sum = 0.0;
	
	for(i=1;i<=30;i++)
	{
		sum += pow(i, -s);
	}
	
	return sum;
}

double Euler_Mascheroni(int s)
{
	int i;
	double sum = 0.0;
	
	for(i=2;i<=s;i++)
	{
		sum += pow(-1,i)*Zeta(i)/i;
	}
	
	return sum;
}

int main()
{
	int s;
	//Labelling Data Columns
	fout<<"s"<<"		"<<"Zeta(s)"<<"			"<<"Euler-Mascheroni(s)"<<endl;
	
	for(s=2;s<=20;s++)
	{
		fout<<s<<"		"<<Zeta(s)<<"		"<<Euler_Mascheroni(s)<<endl;
	}
	
}