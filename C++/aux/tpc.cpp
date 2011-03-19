void two_point_crossover(int a[],int b[],int site1,int site2)
{
	int temp[POP] = {'\0'};
	for(int i=site1;i<site2;i++)
	{
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}
}

int main()
{
	srand(time(NULL));
	int Population[POP];
	int a[MAX];
	int b[MAX];
	
	for(int i=0; i<POP; i++)
	{
		Population[i] = random_generate(1024);
	}
	DisplayI(Population);
	int parent1 = random_generate(POP);
	int parent2 = random_generate(POP);
	int site1 = random_generate(MAX);
	int site2 = random_generate(MAX);
	
	for(int i=0; i<MAX;i++)
	{
		a[i] = Population[parent1]%2;
		Population[parent1] = Population[parent1]/2;
	}
	
	for(int i=0; i<MAX;i++)
	{
		b[i] = Population[parent2]%2;
		Population[parent2] = Population[parent2]/2;
	}
	
	two_point_crossover(a,b,site1,site2);
	Population[parent1] = decimal_convert(a);
	Population[parent2] = decimal_convert(b);
	DisplayI(Population);