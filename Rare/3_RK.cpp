#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ofstream fout("3_RK.dat");

//Define Function
double F(double t, double x, double v, int s)
{
	return -(2/t)*v - pow(x,s);
}

void RK()
{
	//Necessary Variables
	double t[1001][4], x[1001][4], v[1001][4], h = 0.02;
	double k1,k2,k3,k4, l1,l2,l3,l4;
	int i,j;
	
	//Initial values
	for(j=0;j<4;j++)
	{
		t[0][j] = 0.1;
		x[0][j] = 1.0;
		v[0][j] = 0.0;
	}
	
	//Applying Runge Kutta method
	for(j=0;j<4;j++) //This loop is for different values of s
	{
		for(i=0;i<1000;i++) //This loop is for number of iterations
		{
			k1 = h*v[i][j];
			l1 = h*F(t[i][j], x[i][j],v[i][j], j);
			
			k2 = h*(v[i][j] + l1/2);
			l2 = h*F(t[i][j] + h/2, x[i][j] + k1/2, v[i][j] + l1/2, j);
			
			k3 = h*(v[i][j] + l2/2);
			l3 = h*F(t[i][j] + h/2, x[i][j] + k2/2, v[i][j] + l2/2, j);
			
			k4 = h*(v[i][j] + l3);
			l4 = h*F(t[i][j] + h, x[i][j] + k3, v[i][j] + l3, j);
			
			x[i+1][j] = x[i][j] + (k1 + 2.0*k2 + 2.0*k3 + k4)/6;
			v[i+1][j] = v[i][j] + (l1 + 2.0*l2 + 2.0*l3 + l4)/6;
			t[i+1][j] = t[i][j] + h;
		}
	}
	
	//Labeling Data columns
	fout<<"Time"<<"		"<<"s=0"<<"		"<<"s=1"<<"		"<<"s=2"<<"		"<<"s=3"<<"		"<<endl;
	
	//Printing Datas to file
	for(i=0;i<=1000;i++)
	{
		fout<<t[i][0]<<"		"<<x[i][0]<<"		"<<x[i][1]<<"		"<<x[i][2]<<"		"<<x[i][3]<<endl;
	}
	
}

int main() { RK(); }