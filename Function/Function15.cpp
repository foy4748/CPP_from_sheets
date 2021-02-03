#include<iostream>
#include<cmath>
#include<conio.h>

using namespace std;

void SD()
{
	double x[100];
	double sum = 0, Numerator = 0;
	int i,n;
	cout<<"Enter Number of Datas: ";
	cin>>n;
	
	cout<<"Enter the Datas: "<<endl;
	for(i=0;i<n;i++)
	{
		cin>>x[i];
	}
	
	for(i=0;i<n;i++)
	{
		sum += x[i];
	}
	
	sum /= n;
	
	for(i=0;i<n;i++)
	{
		Numerator += (x[i] - sum)*(x[i] - sum);
	}
	
	cout<<"Standard Deviation is: "<<sqrt(Numerator/(n - 1));
}

int main()
{
	SD();
	getch();
}