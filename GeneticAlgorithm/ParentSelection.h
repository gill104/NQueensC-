#ifndef PARENTSELECTION_H
#define PARENTSELECTION_H

int populationSize(int Nsize)
{
	if (Nsize < 11)
	{
		return 100;
	}
	else
		return Nsize * 10;
}
void parentSelection(vector<Population *> fitnessPop, vector<Population *> &matingPool, int Nsize)
{
	/*cout << "ParentSeleciton" << endl;
	int tempC = 0;
	for (vector<Population * >::iterator it = fitnessPop.begin(); it != fitnessPop.end(); it++)
	{
		cout << tempC << ": ParentSeleciton strings " << (*it)->getNumTotal() << endl;
		cout << tempC << ": ParentSeleciton fitness " << (*it)->getFitTotal() << endl;
		tempC++;
	}
	system("pause");*/
	double tenPercent = populationSize(Nsize) * .10;
/////cout << "we need to get: " << tenPercent << endl;
	double maxValue = 0;

	vector<Population *> threeChosen;
	Population *p;

	int chosenTenPercent = 0;
	int randomValue = 0;


	while (chosenTenPercent < tenPercent)
	{
		p = new Population();

		for (int x = 0; x < 3; x++)//doing this with replacement not removing anything from parent pop;
		{
			randomValue = rand() % fitnessPop.size();
			threeChosen.push_back(fitnessPop[randomValue]);
		}

		//vector<string> t;
		//string e;
		//t = threeChosen.front()->getnum();
		//for (vector<string>::iterator it = t.begin(); it != t.end(); it++)//gets the total amount of items in unfitted population
		//{
		//	e += (*it);
		//	e += " ";
		//	cout << "e: " << e << endl;
		//	/*cout << "\nMating pool string: " << (*it)->getNumTotal() << endl;
		//	cout << "Mating pool fitness: " << (*it)->getFitTotal() << endl;*/
		//	system("pause");
		//}
		//cout << "at 1: " << t.at(1) << endl;
		//cout << "at 2: " << t.at(2) << endl;
		//cout << "at 3: " << t.at(3) << endl;
		//cout << "at 4: " << t.at(4) << endl;
		//system("pause");

		vector<string> fitString;//rename if needed
		string s;
		for (int x = 0; x < 3; x++)
		{
		
			if (maxValue < threeChosen.front()->getFitTotal())
			{
				maxValue = threeChosen.front()->getFitTotal();
				fitString = threeChosen.front()->getnum();

				p->eraseNum();
				p->eraseFit();

				for (vector<string >::iterator it = fitString.begin(); it != fitString.end(); it++)
				{
					s = (*it);
					p->setnum(s);//makes sure each number is stored seprately
				}
				p->setfit(maxValue);
				threeChosen.erase(threeChosen.begin());
			}
			else
			{
				threeChosen.erase(threeChosen.begin());
			}
		}


		maxValue = 0.0;

//cout << "best out of the three: " << p->getNumTotal() << endl;
//cout << "best out of the 3: " << p->getFitTotal() << endl;

		matingPool.push_back(p);
		chosenTenPercent++;
	}

	if (matingPool.size() % 2 != 0)//ensures even parents
	{
		p = new Population();
		vector<string> makeEven;
		string evenNum;

		

		randomValue = rand() % fitnessPop.size();
		threeChosen.push_back(fitnessPop[randomValue]);
		makeEven = threeChosen.front()->getnum();

		//p->setnum(threeChosen.front()->getNumTotal());

		for (vector<string >::iterator it = makeEven.begin(); it != makeEven.end(); it++)
		{
			evenNum = (*it);
			p->setnum(evenNum);//makes sure each number is stored seprately
		}
		p->setfit(threeChosen.front()->getFitTotal());

		matingPool.push_back(p);
	}
	for (vector<Population *>::iterator it = matingPool.begin(); it != matingPool.end(); it++)//gets the total amount of items in unfitted population
	{
/*cout << "\nMating pool string: " << (*it)->getNumTotal() << endl;
cout << "Mating pool fitness: " << (*it)->getFitTotal() << endl;*/
//system("pause");
	}
}
#endif