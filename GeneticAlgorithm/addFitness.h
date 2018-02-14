#ifndef ADDFITNESS_H
#define ADDFITNESS_H


void addFitness(Population *p, vector<Population *> &pop, string stringFitness, double fitness, Nqueens m,bool &gotIt)
{
	/*cout << "addFitness" << endl;
	int tempC = 0;
	for (vector<Population * >::iterator it = pop.begin(); it != pop.end(); it++)
	{
		cout << tempC << ": addFitness strings " << (*it)->getNumTotal() << endl;
		cout << tempC << ": addFitness fitness " << (*it)->getFitTotal() << endl;
		tempC++;
		
	}
	system("pause");*/

	int counter = 0;
	vector<string> fitString;

	for (vector<Population *>::iterator it = pop.begin(); it != pop.end(); it++)//gets the total amount of items in unfitted population
	{
		//cout << (*it)->getnum();
		counter++;
		//system("pause");
	}
	for (int x = 0; x < counter; x++)//loops through the unfitted population and saves into new vector WITH fitness
	{
		p = new Population();
		stringFitness = "";

		fitString = pop.front()->getnum();
		for (vector<string >::iterator it = fitString.begin(); it != fitString.end(); it++)
		{
			//cout <<"ASDASD:" <<  (*it);
			stringFitness = (*it);
			/*stringFitness = " ";*/
			p->setnum(stringFitness);//makes sure each number is stored seprately
/////////////cout << "fitString inputed: " << stringFitness << endl;
			/*system("pause");*/
		}
		//cout << "at 1: " << fitString.at(1) << endl;
		//cout << "at 2: " << fitString.at(2) << endl;
		//cout << "at 3: " << fitString.at(3) << endl;
		//cout << "at 4: " << fitString.at(4) << endl;
		//system("pause");

		fitness = 1 / (m.checkFitness(fitString) + .001);		//fitness FUNCTION
	
		pop.front()->setfit(fitness);

		p->setfit(fitness);
		//p->setnum(stringFitness);
	if (fitness == 1000)
		{
			gotIt = true;
			m.display();
			return;
		}


		pop.push_back(p);//added to new vector, now has the fitness value

		pop.erase(pop.begin());//removes from vector (pop) without fitness
	}
	/*string p1String;
	string p2String;
	for (int x = 0; x < fitnessPop.front()->getSize(); x++)
	{
	p1String += fitnessPop.front()->getnum()[x];
	}
	cout << p1String << endl;*/
	//system("pause");
	//delete p;
}
#endif
