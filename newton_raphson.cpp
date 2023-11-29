// C++ program for implementation of newton Raphson Method for
// solving equations
#include <iostream>
#include <iomanip>
#define EPSILON 0.0001
using namespace std;

// An example function whose solution is determined using
// Newton Raphson Method. The function is x^2-4x-10.
double func(double x)
{
	return x * x - 4 * x - 10;
}
// Derivative of the above function which is x^2-4x-10.
double derivFunc(double x)
{
	return 2*x - 4;
}
// function to return the absolute value of gien value.
double retAbsVal(double x)
{
	if (x < 0)
	{
		return -1 * x;
	}
	return x;
}

// Function to find the root
void newtonRaphson(double a)
{
	double funcA, derA, nextValue, error,funcNextValue;
	funcA = func(a);
	derA = derivFunc(a);
	if (derA)
	{
		nextValue = a-(funcA/derA);
		funcNextValue=func(nextValue);
		error = retAbsVal(funcNextValue-funcA);
		cout << fixed << setprecision(4);
		cout<<a<<"\t\t"<<nextValue<<"\t\t"<<funcA<<"\t\t"<<derA<<"\t\t"<<error<<endl;
		if (error <= EPSILON)
		{
			cout << "----------------------------------------------------------------------------------" << endl;
			cout << "\t\tsolution is:" << nextValue << endl;
			return;
		}
		else
		{
			a = nextValue;
			newtonRaphson(a);
		}
	}
	else
	{
		cout << "Derivative value is infinite --error occc..." << endl;
	}
}

// main program to test above method
int main()
{
	double initialValue = 0;	 // Initial values assumed
	cout<<"initialValue\t"<<"nextValue\t"<<"F(a)\t\t"<<"F'(A)\t\t"<<"Error\t"<<endl;
	newtonRaphson(initialValue);
	return 0;
}
