#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#define MAX 10
#define POP 5

int random_generate(int limit)
{
	int i;
	i = rand()%limit;
	return i;
}
