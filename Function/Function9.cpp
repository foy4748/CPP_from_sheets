#include<iostream>
#include<cmath>
#include<fstream>
#include<conio.h>
using namespace std;

ofstream fout("Function9.dat");

void input()
{
	double A[10][10];
	int i, j;
	
	cout<<"Enter a 3x3 matrix A: "<<endl;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>A[i][j];
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			fout<<A[i][j]<<"		";
		}
		fout<<endl;
	}
	
	cout<<"The matrix has been wrote to Function9.dat file";
	
	
}

int main()
{
	input();
	getch();
}