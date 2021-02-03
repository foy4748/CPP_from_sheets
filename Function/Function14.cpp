#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ofstream fout("Function14.dat");

double P(double x, int n)
{
	if(n==0) return 1.0;
	else if(n==1) return x;
	else return ((2*n - 1)*x*P(x,n-1) - (n - 1)*P(x,n-2))/n;
}

int main()
{
	double x;
	fout<<"x"<<"		"<<"n=0"<<"			"<<"n=1"<<"			"<<"n=2"<<"			"<<"n=3"<<endl;
	for(x=-1.0;x<=1.0;x+=0.01)
	{
		fout<<x<<"		"<<P(x,0)<<"		"<<P(x,1)<<"		"<<P(x,2)<<"		"<<P(x,3)<<endl;
	}
}
