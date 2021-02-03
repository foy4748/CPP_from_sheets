//Gaussian Elimination Method for solving any order system
#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;

void ge()
{
	//Necessary Variables
    int i,j,k,n;
    double A[100][100], sum , x[100], c;
	
	//Input System Matrix
    cout<<"Enter dimension of the matrix: ";
    cin>>n;
	cout<<endl;
	
	//Input Elements
    cout<<"Enter elements: "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        {
            cin>>A[i][j];
        }
    }
	
	cout<<endl;
	
	//Commencing Row operation
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            if(i>j)
            {
                c = A[i][j]/A[j][j];
                for(k=0;k<n+1;k++)
                {
                    A[i][k] = A[i][k] - c*A[j][k];
                }
            }
        }
    }
	

    /* //Result of the Row operation
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<A[i][j]<<"		";
		}
		cout<<endl;
	} */



	//Back Substitution
	for(i=n-1;i>=0;i--)
	{
		sum = 0;
		for(j=i;j<n;j++)
		{
			sum = sum + A[i][j]*x[j];
		}
		x[i] = (A[i][n] - sum)/A[i][i];
	}

	//Output
	cout<<"Solutions are :"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"x"<<i+1<<" = "<<x[i]<<endl;
	}

}

int main()
{
	ge();
	getch();
}
