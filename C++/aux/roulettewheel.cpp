#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define MAX 10
#define POP 5
#include "Functions.h"
using namespace std;

/*int random_generate(int limit)
{
	int i;
	i = rand()%limit;
	return i;
}

float Encoding(int n, float lower, float upper)
{
	float enco;
	enco = lower + ((upper-lower)/(pow(2,MAX) - 1))*n;
	return enco;
}

float fitness_value(float x)
{
	float fit = pow(x,2)*sin(x);
	return fit;
}*/

float sumF(float array[])
{
	float SumF = 0;
	for (int i = 0;i<POP;i++)
	{
		SumF+=abs(array[i]);
	}
	return SumF;
}

void Display(float array[])
{
	for(int i=0; i<POP; i++)
	{
		cout<<array[i]<<endl;
	}
}

int main()
{
	srand(time(NULL));
	float upper, lower;
	float Population[POP];
	float fitness[POP];
	float frequency[POP];
	float cumulative_frequency[POP];
	float random[POP];
	float temp[POP];
	
	cout<<"Enter lower bound: ";
	cin>>lower;
        cout<<"Enter upper bound: ";
	cin>>upper;
	
	for (int n=0; n<POP;n++)
	{
		Population[n] = Encoding(lower,upper,random_generate(1024));
		fitness[n] = fitness_value(Population[n]);
		random[n] = random_generate(1024)/float(1024);
	}
	
	for(int n=0;n<POP;n++)
	{
		frequency[n]=abs(fitness[n])/sumF(fitness);
		if(n!=0) 
			cumulative_frequency[n] = cumulative_frequency[n-1]+frequency[n];
		else 
			cumulative_frequency[n] = frequency[n]; 
	}
	
	for(int n=0;n<POP;n++)
	{
		int j=0;
		while (random[n]>cumulative_frequency[j])
		{
			j++;
		}
		temp[n]=Population[j];
	}
	
	for(int n=0; n<POP;n++)
	{
		cout<<Population[n]<<"   "<<frequency[n]<<"   "<<cumulative_frequency[n]<<"   ";
		cout<<random[n]<<"   "<<temp[n]<<endl;
	}
	//Display(Population);
	//Display(random);
	//Display(temp);
	//Display(frequency);
	//Display(cumulative_frequency);
return 0;
}