	float lower, upper;
	int Population[POP];
	int a[MAX];
	int b[MAX];
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