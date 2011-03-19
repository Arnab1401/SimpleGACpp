#include <iostream>
#include <ctime>
#include <cstdlib>
#define MAX 10
using namespace std;
int random_generate(int limit)
{
	int i;
	i = rand()%limit;
	return i;
}

int main()
{
	srand(time(NULL));
	cout<<random_generate(10)<<endl;
	return 0;
}
