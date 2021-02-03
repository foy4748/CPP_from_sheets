#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

ofstream fout("3_EC.dat");

//Define Function
double F(double t, double x, double v, int s)
{
	return -(2/t)*v - pow(x,s);
}

void EC()
{
	//Necessary Variables
	double t[1001][4], x[1001][4], v[1001][4], h = 0.02;
	int i,j;
	
	//Initial values
	for(j=0;j<4;j++) //This loop is for different values of s
	{
		t[0][j] = 0.1;
		x[0][j] = 1.0;
		v[0][j] = 0.0;
	}
	
	//Applying Euler-Cromer method
	for(j=0;j<4;j++) //This loop is for different values of s
	{
		for(i=0;i<1000;i++) //This loop is for number of iterations
		{
			v[i+1][j] = v[i][j] + h*F(t[i][j],x[i][j],v[i][j],j);
			x[i+1][j] = x[i][j] + h*v[i+1][j];
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

int main() { EC(); }