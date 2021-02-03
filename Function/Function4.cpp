#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Function4.dat");

double H(double x, int n)
{
	if(n==0) return 1.0;
	else if (n==1) return 2.0*x;
	else return 2.0*x*H(x,n - 1) - 2.0*(n - 1)*H(x,n - 2);
}

int main()
{
	fout<<"x"<<"		"<<"n=0"<<"			"<<"n=1"<<"			"<<"n=2"<<"			"<<"n=3"<<"			"<<"n=4"<<endl;
	for(double x=-3.0;x<=3.0;x+=0.01)
	{
		fout<<x<<"			"<<H(x,0)<<"		"<<H(x,1)<<"		"<<H(x,2)<<"		"<<H(x,3)<<"		"<<H(x,4)<<"		"<<endl;
	}
}