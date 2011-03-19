int mutation(int n)
{
	int site = random_generate(MAX);
	int i,j;
	int array[MAX];
	
	for(i=0; i<MAX;i++)
	{
		array[i] = n%2;
		n = n/2;
	}
	Flip(array,site);
	return decimal_convert(array);
	cout<<endl;
}

void One_point_mutation(int Population[])
{
	int member = random_generate(POP);
	mutation(Population[member]);
}