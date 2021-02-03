#include<iostream>
#include<cmath>
#include<conio.h>

using namespace std;

double epsilon(int i, int j, int k)
{
	return (i-j)*(j-k)*(k-i)/2;
}


double det(double a[10][10])
{
	double sum = 0;
	int i, j, k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				sum += epsilon(i,j,k)*a[0][i]*a[1][j]*a[2][k];
			}
		}
	}
	
	return sum;
}

void ans()
{
	int i,j;
	
	double DX[10][10], DY[10][10], DZ[10][10], D[10][10];
	
	//Inputting System Matrix
	cout<<"Enter matrix D"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>D[i][j];
		}
	}
	
	//Inputting DX matrix
	cout<<"Enter matrix DX"<<endl;
		for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>DX[i][j];
		}
	}
	
	//Inputting DY matrix
	cout<<"Enter matrix DY"<<endl;
		for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>DY[i][j];
		}
	}
	
	//Inputting DZ matrix
	cout<<"Enter matrix DZ"<<endl;
		for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>DZ[i][j];
		}
	}
	
	cout<<endl;
	
	cout<<"x= "<<det(DX)/det(D)<<endl; //x=5
	cout<<"y= "<<det(DY)/det(D)<<endl; //y=1
	cout<<"z= "<<det(DZ)/det(D)<<endl; //z=-2
	
}

int main()
{
	ans();
	getch();
}