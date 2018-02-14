#ifndef NEWPOPULATION_H
#define NEWPOPULATION_H
using namespace std;
#include<algorithm>
void emptyPop(vector<Population *> pop)
{
	while (!pop.empty())
	{
		pop.pop_back();
	}
	/*cout << "clear pop" << endl;
	int tempC = 0;
	for (vector<Population * >::iterator it = pop.begin(); it != pop.end(); it++)
	{
		cout << tempC << ": clear pop strings " << (*it)->getNumTotal() << endl;
		cout << tempC << ": clear pop fitness " << (*it)->getFitTotal() << endl;
		tempC++;
	}
	system("pause");*/
}
void newPopulation(vector<Population *> &pop, vector<Population *> children, vector<Population *> mutatedChildren, int Nsize)
{
	int counter = 0;
	int childSize = children.size();
	int mutSize = mutatedChildren.size();



	vector<Population *> tempPop;
	tempPop = pop;
	pop = vector < Population * >();
	emptyPop(pop);

	vector <string> tempString;
	string t;

	Population *k;

	if (Nsize < 11)
	{
	/*	cout << "newPopulation" << endl;
		int tempC = 0;
		for (vector<Population * >::iterator it = pop.begin(); it != pop.end(); it++)
		{
			cout << tempC << ": newPopulation strings " << (*it)->getNumTotal() << endl;
			cout << tempC << ": newPopulation fitness " << (*it)->getFitTotal() << endl;
			tempC++;
		}
		system("pause");*/
		std::sort(tempPop.begin(), tempPop.end(), compareFitness());
		for (vector<Population * >::iterator iter = tempPop.begin(); iter != tempPop.end() - 10; iter++)
		{
			k = new Population();
			tempString = (*iter)->getnum();

			for (vector<string >::iterator it = tempString.begin(); it != tempString.end(); it++)
			{
				t = (*it);


				k->setnum(t);
				
			}
			
			k->setfit((*iter)->getFitTotal());
			pop.push_back(k);
		}

	}
	for (int x = 0; x < childSize; x++)
	{
		pop.push_back(children.front());
		children.erase(children.begin());
	}
	for (int x = 0; x < mutSize; x++)
	{
		pop.push_back(mutatedChildren.front());
		mutatedChildren.erase(mutatedChildren.begin());
	}
	/*for (vector<Population * >::iterator it = pop.begin(); it != pop.end(); it++)
	{
		cout << counter << ": sorted pop: " << (*it)->getNumTotal() << endl;
		cout << counter << ": sorted pop: " << (*it)->getFitTotal() << endl;
		counter++;
		system("pause");
	}*/
}

#endif