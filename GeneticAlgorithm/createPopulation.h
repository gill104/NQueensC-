#ifndef CREATEPOPULACTION_H
#define CREATEPOPULCATION_H
void createPopulation(int Nsize, vector<Population *>& population)
{
	/*cout << "createPopulation" << endl;
	int tempC = 0;
	for (vector<Population * >::iterator it = population.begin(); it != population.end(); it++)
	{
		cout << tempC << ": createPopulation strings " << (*it)->getNumTotal() << endl;
		cout << tempC << ": createPopulation fitness " << (*it)->getFitTotal() << endl;
		tempC++;
	}
	system("pause");*/
	Population *p;

	int rNum = 0;
	string concatString = "";
	ostringstream oss;

	vector<int> randpop;

	for (int i = 0; i < Nsize; i++)//fills a helper vector with numbers 0 - Nsize
	{
		randpop.push_back(i);
	}

	if (Nsize < 11)
	{
		for (int i = 0; i < 100; i++)//creates the population to given size
		{
			p = new Population();

			random_shuffle(randpop.begin(), randpop.end());//shuffles the numbers within the randpop (helper variables)
			//p->setSize(randpop.size());
			for (vector<int>::iterator iter = randpop.begin(); iter != randpop.end(); iter++)//collects the numbers in the vector in order
			{
				oss << *iter;
				p->setnum(oss.str());

				oss.str("");
				oss.clear();
			}
			//p->displayNum();
			//system("pause");
			//equals the string to what the (shuffled)vector had inside

			population.push_back(p);//pushes this RANDOM (shuffled)	;
			//	population.front()->displayNum();

			concatString = "";//clearing variables
			oss.str("");
			oss.clear();
		}
		//cout << "position value 2: " << population.front()->getnum().at(2) << endl;
		//system("pause");
		//for (vector<Population *>::iterator it = population.begin(); it != population.end(); it++)
		//{
		//	cout << (*it)->getnum() << endl;
		//	//system("pause");
		//}
	}
	else
	{
		for (int i = 0; i < Nsize * 10; i++)//creates the population to given size
		{
			p = new Population();
			random_shuffle(randpop.begin(), randpop.end());//shuffles the numbers within the randpop (helper variables)
			for (vector<int>::iterator iter = randpop.begin(); iter != randpop.end(); iter++)//collects the numbers in the vector in order
			{
				oss << *iter;
				p->setnum(oss.str());
				oss.str("");
				oss.clear();
			}
			//equals the string to what the (shuffled)vector had inside

			population.push_back(p);//pushes this RANDOM (shuffled)	;

			concatString = "";//clearing variables

		}

		//for (vector<Population *>::iterator it = population.begin(); it != population.end(); it++)
		//{
		//	cout << (*it)->getnum() << endl;
		//	//system("pause");
		//}
	}

}
#endif