#ifndef MUTATION_H
#define MUTATION_H
using namespace std;
#include <algorithm>

void Mutation(vector<Population *> &children, vector<Population *> &mut)
{
	/*cout << "Mutation" << endl;
	int tempC = 0;
	for (vector<Population * >::iterator it = children.begin(); it != children.end(); it++)
	{
		cout << tempC << ": Mutation strings " << (*it)->getNumTotal() << endl;
		cout << tempC << ": Mutation fitness " << (*it)->getFitTotal() << endl;
		tempC++;
	}
	system("pause");*/

	double position1;
	double position2;
	int willItMutate;

	string a;
	string b;
	int counter = 0;

	willItMutate = rand() % 100;
	//vector<Population *> mut;
	Population *L;
	

	

		for (vector<Population * >::iterator it = children.begin(); it != children.end(); it++)
		{
			counter++;
		}
		for (int k = 0; k < counter; k++)
		{
			L = new Population();

			position1 = rand() % children.front()->getnum().size();
			position2 = rand() % children.front()->getnum().size();
			willItMutate = rand() % 100;

			if (willItMutate < 10)
			{
				for (int x = 0; x < children.front()->getnum().size(); x++)
				{
					if (x == position1)
					{
						a = children.front()->getnum()[x];
					}
					if (x == position2)
					{
						b = children.front()->getnum()[x];
					}
				}
				for (int x = 0; x < children.front()->getnum().size(); x++)
				{

					if (x == position1)
					{
						L->setnum(b);
					}

					else if (x == position2)
					{
						L->setnum(a);
					}
					else
					{
						L->setnum(children.front()->getnum()[x]);
					}
				}
				a = "";
				b = "";

				//L->setfit(children.front()->getFitTotal());
/////cout << "pusing in mutated child: " << L->getNumTotal() << endl;
				//system("pause");
				mut.push_back(L);
				children.erase(children.begin());
			}
	}
	for (vector<Population * >::iterator it = mut.begin(); it != mut.end(); it++)
	{
/////cout << " ths muted: " << (*it)->getNumTotal();
//////////////////system("pause");
	}
}


#endif