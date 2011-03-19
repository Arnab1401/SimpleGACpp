#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "GA.h"
#define BITS 8
#define POP 10
#define GENERATIONS 10

using namespace std;

int main()
{
	srand(time(NULL));
	float lower, upper;
	float Pc, Pm;
	int Population[POP];
	
	cout<<"\t\t\t\t\t\t\t==============================================================\n";
	cout<<"\t\t\t\t\t                 		GENETIC ALGORITHM DEMO\n";
	cout<<"\t\t\t\t\t\t\t==============================================================\n";
	cout<<"\t\t\t\t\t\t\tOur aim is to maximize (x^2)*sin(x)\n";
	cout<<"\t\t\t\t\t\t\tWe have taken a Bit length of 8\n";
	cout<<"\t\t\t\t\t\t\tOur Population size is 10\n\n";
	cout<<"Enter the lower bound of variable x: ";
	cin>>lower;
	cout<<"Enter the upper bound of variable x: ";
	cin>>upper;
	
	InitialPop(Population);
	cout<<"Initial Population as random generated integer values\n";
	DisplayI(Population);
	
	for (int g=0; g<GENERATIONS; g++)
	{
		cout<<"\n\n\t~~~~~~GENERATION "<<g+1<<endl;
		//--------------------------Selection-----------------------------
		cout<<"\t\t\t\t\t\t\t!~SELECTION~!\n";
		int schoice;
		cout<<"\t\t\t\t\t\t\t1:Roulette wheel Selection                            2:Tournament Selection\n";
		cout<<"Choice==> ";
		cin>>schoice;
		switch(schoice)
		{
			case 1:
				for(int i=0; i<POP; i++)
				{
					RouletteWheel(Population,lower,upper);
				}
			case 2:
				for(int i=0; i<POP; i++)
				{
					Tournament(Population,lower,upper);
				}
			default:
				break;
		}
		/*cout<<"After Selection Population is\n";
		DisplayI(Population);*/
	
		//-----------------------Crossover-------------------------------
		cout<<"\t\t\t\t\t\t\t!~CROSSOVER~!\n";
		cout<<"Enter Crossover Probability: ";
		cin>>Pc;
		cout<<"\t\t\t\t\t\t\t1:One Point Crossover                            2:Two Point Crossover\n";
		cout<<"Choice==> ";
		int cchoice;
		cin>>cchoice;
	
		switch(cchoice)
		{
			case 1:
				One_point_crossover(Population, Pc);
			case 2:
				Two_point_crossover(Population, Pc);
			default:
				break;
		}
		/*cout<<"After Crossover Population is\n";
		DisplayI(Population);*/
	
		//------------------------Mutation-----------------------------------
		cout<<"\t\t\t\t\t\t\t!~MUTATION~!\n";
		cout<<"Enter Mutation Probability: ";
		cin>>Pm;
		int mchoice;
		cout<<"\t\t\t\t\t\t\t1:One Point Mutation\n";
		cout<<"Choice==>";
		cin>>mchoice;
	
		switch(mchoice)
		{
			case 1:
				One_point_mutation(Population,Pm);
			default:
				break;
		}
		/*cout<<"After Mutation Population is\n";
		DisplayI(Population);*/
	
		float fitness[POP];
		for(int i=0; i<POP; i++)
		{
			fitness[i] = fitness_value(Encoding(lower,upper,Population[i]));
		}
		cout<<"Maximum fitness in this generation: "<<max_fitness(fitness)<<endl;
	}
	
	return 0;
}