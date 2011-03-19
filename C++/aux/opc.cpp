void One_point_crossover(int Population[])
{
	int a[MAX];
	int b[MAX];
	
	int parent1 = random_generate(POP);
	int parent2 = random_generate(POP);
	int site = random_generate(MAX);
	
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
	
	one_point_crossover(a,b,site);
	Population[parent1] = decimal_convert(a);
	Population[parent2] = decimal_convert(b);
}