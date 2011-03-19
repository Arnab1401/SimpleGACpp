#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define POP_SIZE 10
using namespace std;
float Encoding(float lower, float upper, int n)
{
	float enco;
	enco = lower + ((upper-lower)/(pow(2,4) - 1))*n;
	return enco;
}

int main()
{
cout<<"Welcome to Genetic Algorithm\n";
cout<<Encoding(2.0,17.0,20)<<endl;
return 0;
}
