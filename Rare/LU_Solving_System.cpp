#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
	int i,j,k,n;
	double a[10][10],b[10],L[10][10],U[10][10];
	cout<<"Enter dimension of the matrix: ";
	cin>>n;
	cout<<"Enter the elements of the matrix: "<<endl;
	
	//Input the Matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	
	//Input the c terms
	cout<<"Enter b matrix: "<<endl;
	for(j=0;j<n;j++)
	{
		cin>>b[j];
	}
	
	//LU Decomposing
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<i) L[j][i] = 0;
			else
			{
				L[j][i] = a[j][i];
				for(k=0;k<i;k++)
				{
					L[j][i] = L[j][i] - L[j][k]*U[k][i];
				}
			}
		}
		
		for(j=0;j<n;j++)
		{
			if(j<i) U[i][j] = 0;
			else if(j==i) U[i][j] = 1;
			else
			{
				U[i][j] = a[i][j]/L[i][i];
				for(k=0;k<i;k++)
				{
					U[i][j] = U[i][j] - (L[i][k]*U[k][j])/L[i][i];
				}
			}
		}
	}
	
	//Printing Those Matrices
	cout<<endl;
	cout<<"The Lower Triangular Matrix: "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<L[i][j]<<"		";
		}
		cout<<endl;
	}
	
	cout<<endl;
	cout<<"The Upper Triangular Matrix: "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<U[i][j]<<"		";
		}
		cout<<endl;
	}
	
	//Solving The System
	
	//Finding Z; LZ = b
	double z[n],x[n], sum;
	for(i=0;i<n;i++)
	{
		sum = 0;
		for(j=0;j<i;j++)
			sum += L[i][j]*z[j];
		z[i] = (b[i] - sum)/L[i][i];
	}
	
	//Finding X; UX = Z
	for(i=n-1;i>=0;i--)
	{
		sum = 0;
		for(j=n-1;j>i;j--)
			sum += U[i][j]*x[j];
		
		x[i] = (z[i] - sum)/U[i][i];
	}
	
	cout<<"\nThe solutions are: \n";
	for(j=0;j<n;j++)
	{
		cout<<"x["<<j+1<<"]: "<<x[j]<<"		";
	}

	
	getch();
}
				
	