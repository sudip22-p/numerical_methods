// C++ program for implementation of bisection Method for
// solving equations
#include <iostream>
#include <iomanip>
#define EPSILON 0.0001
using namespace std;

// An example function whose solution is determined using
// Bisection Method. The function is x^2-4x-10.
double func(double x)
{
	return x * x - 4 * x - 10;
}
// function to return the absolute value of given value.
double retAbsVal(double x)
{
	if (x < 0)
	{
		return -1 * x;
	}
	return x;
}

// Function to find the root
void bisection(double a, double b)
{
	double funcA, funcB, nextValue, error, funcNextValue;
	funcA = func(a);
	funcB = func(b);
	if (funcA * funcB < 0)
	{
		nextValue = (a + b) / 2;
		error = retAbsVal(b-a);
		funcNextValue = func(nextValue);
		cout << fixed << setprecision(4);
		cout<<a<<"\t\t"<<b<<"\t\t"<<nextValue<<"\t\t"<<funcA<<"\t\t"<<funcB<<"\t\t"<<funcNextValue<<"\t\t"<<error<<endl;
		if (error<= EPSILON||retAbsVal(funcNextValue)<= EPSILON)
		{
			cout << "----------------------------------------------------------------------------------" << endl;
			cout << "\t\tsolution is:" << nextValue << endl;
			return;
		}
		else if (funcA * funcNextValue < 0)
		{
			b = nextValue;
			bisection(a, b);
		}
		else if(funcB * funcNextValue < 0)
		{
			a = nextValue;
			bisection(a, b);
		}else{
			cout<<"unknown error occurrred!!!!!"<<endl;
			return;
		}
	}
	else
	{
		cout << "You have not assumed valid a and b" << endl;
	}
}

// main program to test above method
int main()
{
	double firstValue = -1;	 // Initial first values assumed
	double secondValue = -2; // Initial second values assumed
	cout<<"firstValue\tsecondValue\tnextValue\tF(a)\t\tF(B)\t\tF(C)\t\tError\t"<<endl;
	bisection(firstValue, secondValue);
	return 0;
}
