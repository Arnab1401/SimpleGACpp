#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define BITS 8
#define POP 10
#include "Functions.h"

void RouletteWheel(int Population[],float lower, float upper)
{
	float EncodedPopulation[POP];
	float fitness[POP];
	float frequency[POP];
	float cumulative_frequency[POP];
	float random[POP];
	int temp[POP];
	
	for (int n=0; n<POP;n++)
	{
		EncodedPopulation[n] = Encoding(lower,upper,Population[n]);
		fitness[n] = fitness_value(Population[n]);
		random[n] = random_generate(256)/float(256);
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
	
	Update_Pop(Population,temp);
	/*for(int n=0; n<POP;n++)
	{
		cout<<EncodedPopulation[n]<<"   "<<frequency[n]<<"   "<<cumulative_frequency[n]<<"   ";
		cout<<random[n]<<"   "<<Encoding(lower,upper,temp[n])<<endl;
	}*/
}

void Tournament(int Population[], float lower, float upper)
{
	int a[BITS];
	int b[BITS];
	int temp[POP];
	
	for(int i=0; i<POP; i++)
	{
		int player1 = random_generate(POP);
		int player2 = random_generate(POP);
	
		float fitness1 = fitness_value(Encoding(lower, upper,Population[player1]));
		float fitness2 = fitness_value(Encoding(lower, upper,Population[player2]));
		
		temp[i] = fitness1>fitness2 ? Population[player1] : Population[player2];
	}
	Update_Pop(Population,temp);
}

void crossover1(int a[],int b[],int site)															//Exchange of bits at site
{
	for(int i=site;i<POP;i++)
	{
		a[i] = a[i] + b[i];
		b[i] = a[i] - b[i];
		a[i] = a[i] - b[i];
	}
}
void One_point_crossover(int Population[], float Pc)
{
	int a[BITS];																			//Binary Array representation of population member
	int b[BITS];
	int temp[POP];
	for(int i=0; i<POP; i++)
	{
		temp[i] = -1;
	}
	int cycles = (int(POP*Pc)%2==0) ? int(POP*Pc) : int(POP*Pc) + 1;                                                               //To Determine no of times crossover takes place
	
	for(int j = 0; j<cycles; j++)
	{
		int index1 = random_generate(POP);
		int index2 = random_generate(POP);
		int parent1 = Population[index1];
		int parent2 = Population[index2];
		int site = random_generate(BITS);
	
		for(int i=0; i<BITS;i++)
		{
			a[i] = parent1%2;
			parent1 = parent1/2;
		}
	
		for(int i=0; i<BITS;i++)
		{
			b[i] = parent2%2;
			parent2 = parent2/2;
		}
	
		crossover1(a,b,site);
		temp[index1] = decimal_convert(a);
		temp[index2] = decimal_convert(b);
	}
	int j = 0;
	while(j<POP)
	{
		if(temp[j]!= -1)
		{	
			Population[j] = temp[j];
		}
		j++;
	}
}

void crossover2(int a[],int b[],int site1,int site2)
{
	for(int i=site1;i<site2;i++)
	{
		a[i] = a[i] + b[i];
		b[i] = a[i] - b[i];
		a[i] = a[i] - b[i];
	}
}

void Two_point_crossover(int Population[], float Pc)
{
	int a[BITS];
	int b[BITS];
	
	int cycles = (int(POP*Pc)%2==0) ? int(POP*Pc) : int(POP*Pc) + 1;
	int temp[POP];
	for(int i=0; i<POP; i++)
	{
		temp[i] = -1;
	}
	
	for(int j = 0; j<cycles; j++)
	{
		int index1 = random_generate(POP);
		int index2 = random_generate(POP);
		int parent1 = Population[index1];
		int parent2 = Population[index2];
		int site1 = random_generate(BITS);
		int site2 = random_generate(BITS);
	
		for(int i=0; i<BITS;i++)											//Converting population member to its binary value
		{
			a[i] = parent1%2;
			parent1 = parent1/2;
		}
	
		for(int i=0; i<BITS;i++)
		{
			b[i] = parent2%2;
			parent2 = parent2/2;
		}
	
		crossover2(a,b,site1,site2);
		temp[parent1] = decimal_convert(a);
		temp[parent2] = decimal_convert(b);
	}
	int j = 0;
	while(j<POP)
	{
		if(temp[j]!= -1)
		{	
			Population[j] = temp[j];
		}
		j++;
	}
}

int mutation(int n)
{
	int site = random_generate(BITS);
	int i;
	int array[BITS];
	
	for(i=0; i<BITS;i++)                                                                                 //Converting the Population member to binary array
	{
		array[i] = n%2;
		n = n/2;
	}
	Flip(array,site);											//Flipping the bit at random generated site
	return decimal_convert(array);								//Mutated integer value
	cout<<endl;
}

void One_point_mutation(int Population[], float Pm)					//Performing mutation of population member
{
	int cycles = int(POP*Pm);
	if(cycles!=0)
	{
		for(int j=0; j<cycles; j++)
		{
			int member = random_generate(POP);
			Population[member] = mutation(Population[member]);
		}
	}
}