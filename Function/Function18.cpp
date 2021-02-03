#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>
using namespace std;

ofstream fout("Function18.dat");

double fourier(double x, int n)
{
	double sum = 0.0;
	int i;
	for(i=1;i<=n;i++)
	{
		sum += 2.0*pow(-1,i+1)*sin(i*x)/i;
	}
	
	return sum;
}

int main()
{
	double x;
	fout<<"x"<<"		"<<"n=2"<<"			"<<"n=3"<<"			"<<"n=4"<<"			"<<"n=5"<<"			"<<"n=6"<<"			"<<"n=7"<<"			"<<"n=8"<<"			"<<endl;
	for(x=-M_PI;x<=M_PI;x+=0.01)
	{
		fout<<x<<"		"<<fourier(x,2)<<"			"<<fourier(x,3)<<"			"<<fourier(x,4)<<"			"<<fourier(x,5)<<"			"<<fourier(x,6)<<"			"<<fourier(x,7)<<"			"<<fourier(x,8)<<"			"<<endl;
	}
	
}