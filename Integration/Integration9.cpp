#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

ofstream fout("Integration9.dat");

double f(double phi, double thetaM)
{
	double a = 4.0*sqrt(0.0253); //Chosen L/g = 0.0253
	double b = pow(sin(phi),2.0);
	double c = pow(sin(thetaM/2),2.0);
	
	return a*(1/sqrt(1 - c*b));
}

/* double T(double thetaM) //Trapizium Rule
{
	double a = 0, b = M_PI/2.0;
	int i, N = 100;
	double I = 0;
	double h =(b-a)/N;
	for(i=1;i<N;i++)
	{
		I += 2.0*f(a + i*h, thetaM);
	}
	
	return 0.5*h*(f(a,thetaM) + I + f(b,thetaM));
} */
double T(double thetaM) //Simpson's 1/3 rule
{
	double a = 0, b = M_PI/2.0;
	int i, N = 100;
	double I = 0, J = 0;
	double h = (b - a)/N;
	
	for(i=1;i<N;i+=2)
	{
		I += 4.0*f(a + i*h, thetaM);
	}
	
	for(i=2;i<N;i+=2)
	{
		J += 2.0*f(a + i*h, thetaM);
	}
	
	double result = (h/3)*(f(a, thetaM) + I + J + f(b, thetaM));
	return result;
}

int main()
{
	double thetaM;
	fout<<"Angle"<<"		"<<"Time-Period"<<endl;
	for(thetaM=0; thetaM<=M_PI/2.0; thetaM+=M_PI/1000.0)
	{
		fout<<thetaM<<"			"<<T(thetaM)<<endl;
	}

}