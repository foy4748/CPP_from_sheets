 #include<iostream>
 #include<cmath>
 #include<fstream>
 
 using namespace std;
 
 ofstream fout("ODE1.dat");
 
 double f(double t, double y)
 {
	 return 2 - exp(-4*t) - 2*y;
 }
 
 double solution(double t)
 {
	 return 1 + 0.5*exp(-4*t) - 0.5*exp(-2*t);
 }
 void euler(double t0, double y0, double h)
 {	
	fout<<"Time"<<"		"<<"Euler_Method"<<"		"<<"Actual_Solution"<<endl;
	 for(double t = t0; t<=10; t+=h)
	 {
		 y0 += f(t,y0)*h;
		 fout<<t<<"		"<<y0<<"		"<<solution(t)<<endl;
	 }
	 
 }
 
 int main()
 {
	 euler(0,1,0.01);
 }