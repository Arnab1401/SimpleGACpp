#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

int main()
{
	srand(time(NULL));
	int limit = 20;
	int i;
	for (i=0; i<4; i++)
	{
		cout<<(rand()%limit)/float(limit)<<endl;
	}
	return 0;
}
