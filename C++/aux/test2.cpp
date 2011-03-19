#include<iostream>
using namespace std;
int main()
{
	int a[4] = {1,3,5,7} ;
	int b[4] = {2,4,6,8} ;
	for(int i=0; i<4; i++)
	{
		a[i] = a[i] + b[i];
		b[i] = a[i] - b[i];
		a[i] = a[i] - b[i];
	}
	for(int i=0; i<4; i++)
	{
		cout<<a[i]<<endl;
	}
	for(int i=0; i<4; i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}