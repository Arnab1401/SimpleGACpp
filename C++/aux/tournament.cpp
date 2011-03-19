#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define MAX 10
#define POP 5
#include "Functions.h"
using namespace std;

int main()
{
	srand(time(NULL));
	int Population[POP];
	int a[MAX];
	int b[MAX];
	int temp[POP];
	
	for(int i=0; i<POP; i++)
	{
		Population[i] = random_generate(1024);
	}
	DisplayI(Population);
	
	for(int i=0; i<POP; i++)
	{
		int player1 = random_generate(POP);
		int player2 = random_generate(POP);
	
		float fitness1 = fitness_value(Encoding(0, 10,Population[player1]));
		float fitness2 = fitness_value(Encoding(0, 10,Population[player2]));
		
		temp[i] = fitness1>fitness2 ? Population[player1] : Population[player2];
	}
	DisplayI(temp);
	return 0;
}