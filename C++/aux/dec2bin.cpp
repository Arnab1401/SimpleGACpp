#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX 10
using namespace std;

void binary_convert(int n)
{
	int i,j;
	int array[], int temp[];
	for(i=0; i<MAX;i++)
	{
		array[i] = n%2;
		n = n/2;
	}
	for(j=MAX-1;j>=0;j--)
	{
		cout<<array[j];
	}
	cout<<endl;
}
int main()
{
binary_convert(7);
return 0;
}
