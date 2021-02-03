#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Function6.dat");

double fact(int n)
{
	if(n==0) return 1;
	else return n*fact(n-1);
}

double psum(int n)
{
	double sum = 0;
	for(double p=1;p<=20;p++)
	{
		sum += pow(p, -2*n);
	}
	
	return sum;
}

double bernoulli(int n)
{
	double a = pow(-1, n - 1)*2*fact(2*n);
	double b = pow(2*M_PI, 2*n);
	
	return a*psum(n)/b;
}

double mytan(double x, int n)
{
	double sum = 0;
	for(double i=0;i<n;i++)
	{
		sum += pow(-1, i-1)*pow(2, 2*i)*(pow(2, 2*i) - 1)*bernoulli(i)*pow(x,2*i - 1)/fact(2*i);
	}
	
	return sum;
}

int main()
{
	fout<<"x"<<"		"<<"Using-Bernoulli"<<"			"<<"Actual"<<endl;
	for(double x = -M_PI/3;x<=M_PI/3;x+=0.01)
	{
		fout<<x<<"		"<<mytan(x,20)<<"		"<<tan(x)<<endl;
	}
}