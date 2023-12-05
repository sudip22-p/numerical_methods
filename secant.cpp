#include <iostream>
#include <cmath>
#include <iomanip>
#define error 0.0001

using namespace std;

double function(double x) {
  // Replace this with the actual function you want to find the root of
  return x * x - 1;
}

double secantMethod(double x1, double x2,int iteration) {
  double f1 = function(x1);
  double f2 = function(x2);
  cout<<fixed<<setprecision(4);
  cout << "Iteration " << iteration << ": x = " << x2 << ", f(x) = " << f2 << endl;

  if (fabs(f2) < error) {
    return x2;
  }
  double x3 = ((f2*x1)-(f1*x2))/(f2-f1);
  return secantMethod(x2, x3,iteration+1);
}

int main() {
  double x1 = 0.5; // Initial guess 1
  double x2 = -8.0; // Initial guess 2

  double root = secantMethod(x1, x2,1);

  cout << "Root: " << root << endl;

  return 0;
}