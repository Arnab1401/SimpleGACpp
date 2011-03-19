#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#define MAX 10
using namespace std;

int random_generate()
{
	srand(time(NULL));
	int i;
	int limit = MAX;
	i = rand()%limit;
	return i;
}

int decimal_convert(int array[])
{
	int i,j;
	int sum = 0;
	for(i=0; i<MAX;i++)
	{
		sum+=array[i]*pow(2,MAX-1-i);
	}
	return sum;
}

int mutation(int a[],int site)
{
	a[site-1] = a[site-1]==0 ? 1:0;
	int ans = decimal_convert(a);
	return ans;
}

int main()
{
	int array[] = {0,1,0,0,1,0,1,0,1,1};
	int site = random_generate();
	cout<<decimal_convert(array)<<endl;
	cout<<mutation(array,site)<<endl;
	return 0;
}
	