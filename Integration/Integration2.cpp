#include<iostream>
#include<cmath>
#include<conio.h>

using namespace std;


#define N 100

double f(double x)
{
	
	return exp(-1/(1 + x*x));
}

//Trapizium Rule
void trap()
{
	
	int i;
	double a = -1, b = 1;
	double h = (b-a)/N;
	double I = 0;
	for(i=1;i<N;i++)
	{
		I += f(a + i*h);
	}
	double result = (h/2)*(f(a) + 2*I + f(b));
	cout<<"Trapizium Rule Result: "<<result<<endl;
}

void simp()
{
	
	int i;
	double a = -1, b = 1;
	double h = (b-a)/N;
	double I = 0, J = 0;
	for(i=1;i<N;i+=2)
	{
		I += f(a + i*h);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += f(a + i*h);
	}
	
	double result = (h/3)*(f(a) + 4*I + 2*J + f(b));
	cout<<"Simpson's 1/3 Rule Result: "<<result<<endl;
	
}

void simp38()
{
	
	int i;
	double a = -1, b = 1;
	double h = (b-a)/N;
	double I = 0, J = 0, K = 0;
	for(i=1;i<N;i+=3)
	{
		I += f(a + i*h);
	}
	
	for(i=2;i<N;i+=3)
	{
		J += f(a + i*h);
	}
	
	for(i=3;i<N;i+=3)
	{
		K += f(a + i*h);
	}
	
	double result = (3*h/8)*(f(a) + 3*I + 3*J + 2*K + f(b));
	cout<<"Simpson's 3/8 Rule Result: "<<result<<endl;
	
}

int main()
{
	trap();
	simp();
	simp38();
	getch();
}