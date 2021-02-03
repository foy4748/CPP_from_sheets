#include<iostream>
#include<fstream>
#include<cmath>
#include<conio.h>

using namespace std;

//Given Function
double F(double x)
{
	return x*sin(x) + cos(x);
}

//Derivative of the Function
double dF(double x)
{
	return x*cos(x);
}

//Generating data for given Function
void plot()
{
	ofstream fout("Root_function.txt"); //Creating txt file for storing data
	//Labeling data column
	fout<<"Inputs"<<"		"<<"Function-Values"<<endl;
	//Generating Datas
	for(double a = -10.00; a <= 10.00; a+=0.01)
	{
		fout<<a<<"		"<<F(a)<<endl;
	}
}

//Finding root using Newton-Raphson Method
double newt(double x0)
{
	double h;
	h = F(x0)/dF(x0);
	while(abs(h)>=0.000000001)
	{
		x0 = x0 - h;
		h = F(x0)/dF(x0);
	}
	
	return x0;
}

int main()
{
	plot();	//Calling the plot function
	
	ofstream fout("Root_values.txt"); //Creating txt file to store roots
	
	double a;
	//Labeling data column
	fout<<"Approximated"<<"			"<<"Roots"<<endl;
	
	cout<<"Approximated"<<"			"<<"Roots"<<endl;
	//Finding all possible roots within [-10:10] range
	for(a = -3.00; a <= 3.00; a += 1.00)
	{
		if(a == 0.00) continue;
		fout<<newt(a*M_PI)<<"			"<<0<<endl;
		cout<<a*M_PI<<"			"<<newt(a*M_PI)<<endl;
	}
	
	getch();
	
}
