void RouletteWheel(int Population[])
{
	float upper, lower;
	float EncodedPopulation[POP];
	float fitness[POP];
	float frequency[POP];
	float cumulative_frequency[POP];
	float random[POP];
	float temp[POP];
	
	cout<<"Enter lower bound: ";
	cin>>lower;
        cout<<"Enter upper bound: ";
	cin>>upper;
	
	for (int n=0; n<POP;n++)
	{
		EncodedPopulation[n] = Encoding(lower,upper,Population[n]);
		fitness[n] = fitness_value(Population[n]);
		random[n] = random_generate(1024)/float(1024);
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
	for(int n=0; n<POP;n++)
	{
		cout<<EncodedPopulation[n]<<"   "<<frequency[n]<<"   "<<cumulative_frequency[n]<<"   ";
		cout<<random[n]<<"   "<<Encoding(lower,upper,temp[n])<<endl;
	}
}