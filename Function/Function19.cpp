#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Function19.dat");


double fourier(double x, int n)
{
	double sum = 0.0;
	int i;
	for(i=1;i<n;i++)
	{
		sum += cos(2*i*x)/(pow(2.0*i,2) - 1);
	}
	
	double result;
	result = 1/(M_PI) + 0.5*sin(x) - sum;
	
	return result;
}

int main()
{
	double x;
	fout<<"x"<<"		"<<"n=2"<<"			"<<"n=3"<<"			"<<"n=4"<<"			"<<"n=5"<<"			"<<"n=6"<<endl;
	for(x=-3*M_PI;x<=3*M_PI;x+=0.01)
	{
		fout<<x<<"		"<<fourier(x,2)<<"			"<<fourier(x,3)<<"			"<<fourier(x,4)<<"			"<<fourier(x,5)<<"			"<<fourier(x,6)<<endl;
	}
}