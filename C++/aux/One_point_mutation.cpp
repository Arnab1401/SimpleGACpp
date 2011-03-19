#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define MAX 10
#define POP 5
using namespace std;

int random_generate(int limit)
{
	int i;
	i = rand()%limit;
	return i;
}

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

void Flip(int array[],int site)
{
	array[site] == 0? array[site]=1: array[site]=0;
}

int One_point_mutation(int n)
{
	cout<<n<<endl;
	int site = random_generate(MAX);
	int i,j;
	int array[MAX];
	
	for(i=0; i<MAX;i++)
	{
		array[i] = n%2;
		n = n/2;
	}
	Flip(array,site);
	return decimal_convert(array);
	cout<<endl;
}

int main()
{
	srand(time(NULL));
	cout<<One_point_mutation(145)<<endl;
	return 0;
}