// C++ program for implementation of false position Method for
// solving equations
#include <iostream>
#include <iomanip>
#define EPSILON 0.0001
using namespace std;

// An example function whose solution is determined using
// false position  Method. The function is x^2-4x-10.
double func(double x)
{
	return x * x - 4 * x - 10;
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
void falsePosition(double a, double b)
{
	double funcA, funcB, nextValue, error, funcNextValue;
	funcA = func(a);
	funcB = func(b);
	if (funcA * funcB < 0)
	{
		nextValue = a-((funcA*(b-a))/(funcB-funcA));
		error = retAbsVal(a-b);
		funcNextValue = func(nextValue);
		cout << fixed << setprecision(4);
		cout<<a<<"\t\t"<<b<<"\t\t"<<nextValue<<"\t\t"<<funcNextValue<<"\t\t"<<error<<endl;
		if (error<= EPSILON||retAbsVal(funcNextValue)<= EPSILON)
		{
			cout << "----------------------------------------------------------------------------------" << endl;
			cout << "\t\tsolution is:" << nextValue << endl;
			return;
		}
		else if (funcA * funcNextValue < 0)
		{
			b = nextValue;
			falsePosition(a, b);
		}
		else if(funcB * funcNextValue < 0)
		{
			a = nextValue;
			falsePosition(a, b);
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
	double firstValue = -2;	 // Initial first values assumed
	double secondValue = -1; // Initial second values assumed
	cout<<"firstValue\t"<<"secondValue\t"<<"nextValue\t"<<"F(C)\t\t"<<"Error\t"<<endl;
	falsePosition(firstValue, secondValue);
	return 0;
}
