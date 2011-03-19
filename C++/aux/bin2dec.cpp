#include <iostream>
#include <cmath>
#include <cstdlib>
#define MAX 10
using namespace std;

int decimal_convert(int array[])
{
	int i,j;
	int sum = 0;
	for(i=MAX-1; i>=0;i--)
	{
		sum+=array[i]*pow(2,i);
	}
	return sum;
}

int main()
{
int arr[MAX];
int i;
for (i=0;i<MAX;i++)
{
	cout<<"->";
	cin>>arr[i];
}
cout<<decimal_convert(arr)<<endl;
return 0;
}
