#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration10_Bessel.dat");
ofstream file("Integration10_Transmitted.dat");

double fact(int n)
{
	if(n<1) return 1;
	else return n*fact(n - 1);
}


double F(double theta, double x, int n)
{
	return cos(x*sin(theta))*pow(cos(theta), 2*n);
}

double Jn(double x, int n)
{
	double B = M_PI/2, A = 0;
	int i, N = 100;
	double h = (B-A)/N;
	double I = 0, J = 0;
	
	for(i=1;i<N;i+=2)
	{
		I += F(A + i*h, x, n);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += F(A + i*h, x, n);
	}
	
	double result;
	result = (h/3)*(F(A,x,n) + 4*I + 2*J + F(B,x,n));
	
	double a = 2/(sqrt(M_PI)*fact(n - 1/2));
	double b = pow(0.5*x, n);
	
	return a*b*result;
}

void bessel()
{
	double x;
	fout<<"x"<<"	"<<"n=0"<<"	"<<"n=1"<<"	"<<"n=2"<<"	"<<"n=3"<<endl;
	for(x = -10; x<=10; x+=0.01)
	{	fout<<x<<"	"<<Jn(x,0)<<"		"<<Jn(x,1)<<"		"<<Jn(x,2)<<"		"<<Jn(x,3)<<"		"<<endl; }
}

double T(double q)
{
	double k = 2*M_PI;
	double A = 0, B = 2*k*q;
	int i , N = 100;
	double h = (B - A)/N;
	double I = 0, J = 0;
	
	for(i=1;i<N;i+=2)
	{
		I += Jn(A + i*h, 0);
	}
	
	for(i=1;i<N;i+=2)
	{
		J += Jn(A + i*h, 0);
	}
	
	double result = (h/3)*(Jn(A,0) + 4*I + 2*J + Jn(B,0));
	
	return 1 - (1/(2*k*q))*result;
}

int main()
{
	bessel();
	file<<"q"<<"		"<<"Transmitted(q)"<<endl;
	for(double q = 0; q<=4; q+=0.01)
	{	file<<q<<"	"<<T(q)<<endl; }
}
	
	