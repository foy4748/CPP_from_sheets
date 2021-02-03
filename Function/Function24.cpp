#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;


void s()
{
	int i, j, n = 9;
	double a[] = {55,22,99,66,44,88,33,100,77};
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1]) swap(a[j], a[j+1]);
		}
	}
	
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<", ";
	}
}

int main()
{
	s();
	getch();
}