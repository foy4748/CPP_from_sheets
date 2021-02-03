#include<iostream>
#include<fstream>
#include<cmath>
#include<conio.h>
using namespace std;

//Function for Sign 
double epsilon(int i, int j, int k)
{
	return (i-j)*(j-k)*(k-i)/2;
}

//Calculating Determinant
double det(double a[3][3])
{
	int i,j,k;
	double sum = 0.0;
	
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

int main()
{
	//Necessary Variables
	int i,j,k;
	double mat[3][3],co_factor[3][3],transpose[3][3],inv[3][3], b[3][1];
	
	//Input System Matrix
	cout<<"Enter the System Matrix: "<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cin>>mat[i][j];
		}
	}
	
	cout<<endl;
	
	//Input b column matrix
	cout<<"Enter b column matrix:"<<endl;
	for(i=0;i<3;i++)
	{
		cin>>b[i][0];
	}
	
	cout<<endl;
	
	//Determining Co-factor matrix
	cout<<"The Co-factor matrix is :"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			co_factor[i][j] = mat[(i+1)%3][(j+1)%3]*mat[(i+2)%3][(j+2)%3] - mat[(i+1)%3][(j+2)%3]*mat[(i+2)%3][(j+1)%3];
			cout<<co_factor[i][j]<<"		";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	//Determining Transpose of Co-factor Matrix
	cout<<"Transpose of the co-factor matrix"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			transpose[i][j] = co_factor[j][i];
			cout<<transpose[i][j]<<"		";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	//Inverting The system matrix
	cout<<"The inverse System Matrix is:"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			inv[i][j] = transpose[i][j]/det(mat);
			cout<<inv[i][j]<<"		";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	//Multiplying Inverse System Matrix and b matrix
	double C[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			C[i][j] = 0;
		}
	}
	
	cout<<"The solution is:"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			for(k=0;k<3;k++)
			{
				C[i][j] += inv[i][k]*b[k][j];
				
			}
		}
		
	}
	
	//Displaying Solution
	for(i=0;i<3;i++)
	{
		for(j=0;j<1;j++)
		{
			cout<<C[i][j]<<"		";
		}
		cout<<endl;
	}
	
	
	
	getch();
}