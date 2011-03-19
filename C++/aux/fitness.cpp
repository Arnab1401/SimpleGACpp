#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define MAX 10
using namespace std;

float fitness_value(float n)
{
	return pow(n,2)*sin(n);
}

int random_generate(int limit)
{
	int i;
	i = rand()%limit;
	return i;
}

int main()
{
	srand(time(NULL));
	float pop[MAX];
	for(int i=0; i<MAX; i++)
	{
		pop[i] = fitness(random_generate(20));
	}
	
	for(int j=0; j<MAX; j++)
	{
		cout<<pop[j]<<endl;
	}

return 0;
}
