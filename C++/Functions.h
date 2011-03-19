#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define BITS 8
#define POP 10
using namespace std;

int random_generate(int limit)								//Generating random integer in specified range
{
	int i;
	i = rand()%limit;
	return i;
}

void InitialPop(int array[])               							//Initialize random population
{
	for(int i=0; i<POP; i++)
	{
		array[i] = random_generate(256);
	}
}

int decimal_convert(int array[])								//convert a binary value of a number as an array to its decimal value
{
	int i,j;
	int sum = 0;
	for(i=BITS-1; i>=0;i--)
	{
		sum+=array[i]*pow(2,i);
	}
	return sum;
}

float Encoding(float lower, float upper, int n)					//Converting random sample into the range of the problem
{
	float enco;
	enco = lower + ((upper-lower)/(pow(2,BITS) - 1))*n;
	return enco;
}

float sumF(float array[])									//Sum of the normalized frequency
{
	float SumF = 0;
	for (int i = 0;i<POP;i++)
	{
		SumF+=abs(array[i]);
	}
	return SumF;
}

void Flip(int array[],int site)									//Flip bit of a binary number represented by array
{
	array[site] == 0? array[site]=1: array[site]=0;
}

float fitness_value(float n)									//The objective function
{
	return pow(n,2)*sin(n);
}

void Update_Pop(int array1[], int array2[])						//Updating the generations after a certain operation
{
	for(int i=0; i<POP; i++)
	{
		array1[i] = array2[i];
	}
}

void DisplayF(float array[])									//Display Current Endcoded Population
{
	for(int i = 0; i<POP; i++)
	{
		cout<<array[i]<<endl;
	}
}

void DisplayI(int array[])										//Display Current Integer Population
{
	for(int i = 0; i<POP; i++)
	{
		cout<<array[i]<<endl;
	}
}

float max_fitness(float array[])								//maximum fitness of a current population
{
	float max = array[0];
	for(int i=0; i<POP; i++)
	{
		if(array[i]>max)
		{
			array[i] = max;
		}
	}
	return max;
}