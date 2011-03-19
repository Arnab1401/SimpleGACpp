#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define MAX 10
#define POP 5
using namespace std;

void Update_Pop(int array1[], int array2[])
{
	for(int i=0; i<POP; i++)
	{
		array1[i] = array2[i];
	}
}

int main()
{
	int a = {0,2,3,5,6};
	int b = {4,6,7,2,1};
	Update_Pop(a,b);
	for(int i=0; i<POP; i++)
	{
		cout<<a[i]<<"  "<<b[i]<<endl;
	}
	return 0;
}