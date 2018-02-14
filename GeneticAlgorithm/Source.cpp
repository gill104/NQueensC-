
//WORK ON PARENT SELECTION AND CHILDREN NEXT
#include<iostream>
#include<time.h>
#include<algorithm>
#include<vector>
#include<string>
#include<stdlib.h>
#include<sstream>

#include "nQueensClass.h"
#include "populationClass.h"
#include "parentClass.h"
#include "createPopulation.h"
#include "addFitness.h"
#include "ParentSelection.h"
#include "makingChildren.h"
#include "Mutation.h"
#include "newPopulation.h"
using namespace std;

void createPopulation(int, vector<Population *>&);
void addFitness(Population *, vector<Population *>&, string, double, Nqueens,bool&);
void parentSelection(vector<Population *>, vector<Population *>&, int);
void makingChildren(vector<Population *>, vector<Population *>&, int);
void Mutation(vector<Population *> &, vector<Population *> &);
void newPopulation(vector<Population *> &, vector<Population *>, vector<Population *>, int);
void clearMatingPool(vector<Population *> &);
void clearChildren(vector<Population *>& );
void clearMutation(vector<Population *>& );

int main()
{	
	srand(time(NULL));


	//int minFitness;
	//int maxFitness;
	//int avgFitness;
	//int curCrossover;
	//int curMutation;
	//int curPop;
	int generations = 0;
	double fitness = 0.0;//saves the fitness function
	int Nsize;
	int c = 0;
	string stringFitness;
	bool gotIt = false;

	vector<Population *> pop ;
	//<Population *> fitnessPop;
	vector<Population *> matingPool;//clean
	vector<Population *> children;//clean
	vector<Population *> mutatedChildren;//clean


	Nqueens m;
	Population *p = new Population();

	cout << "what is your board size?";
	cin >> Nsize;

	createPopulation(Nsize, pop);

	m.setSizes(Nsize);
	m.makeMap();
	//m.display();

	//loop here till i find the 1000.00
	while (generations < 1000)
	{
		
		addFitness(p, pop, stringFitness, fitness, m, gotIt);//change so that insead of using pop, use fitness to keep track of all population
		//since i am using fitnessPop to get new population
		if (gotIt == true)
		{
			cout << "FOUND SOMETHING GOOD!" << endl;
			cout << generations << endl;
			system("pause");
			return 0;
			
		}
		parentSelection(pop, matingPool, Nsize);

		makingChildren(matingPool, children,Nsize);
	
		Mutation(children, mutatedChildren);

		newPopulation(pop, children, mutatedChildren, Nsize);

		//for (vector<Population * >::iterator it = pop.begin(); it != pop.end(); it++)
		//{
		//	//cout <<c <<  ": FINAL strings " << (*it)->getNumTotal() << endl;
		//	//cout <<c <<  ": FINAL fitness " << (*it)->getFitTotal() << endl;
		//	//c++;
		//	//system("pause");
		//}
		//cout << "gen: " << generations + 1 << endl;
		clearChildren(children);
		clearMutation(mutatedChildren);
		clearMatingPool(matingPool);
		c = 0;
		generations++;
		
		//delete p;
	//	system("pause");
	}


	//for (vector<Population *>::iterator it = matingPool.begin(); it != matingPool.end(); it++)
	//{
	//	(*it)->displayNum();
	//	(*it)->displayFit();
	//	system("pause");
	//}
	
	system("pause");
	return 0;
}
void clearMatingPool(vector<Population *> &matingPool)
{
	/*for (vector<Population * >::iterator it = matingPool.begin(); it != matingPool.end(); it++)
	{
		delete (*it);
	}
	matingPool.clear();
	matingPool.shrink_to_fit();*/
	while (!matingPool.empty())
	{
		matingPool.pop_back();
		
	}
}
void clearChildren(vector<Population *> &children)
{
	/*for (vector<Population * >::iterator it = children.begin(); it != children.end(); it++)
	{
		delete (*it); 
	}
	children.clear();
	children.shrink_to_fit();*/
	while (!children.empty())
	{
		children.pop_back();
	}
}
void clearMutation(vector<Population *> &mutatedChildren)
{
	/*for (vector<Population * >::iterator it = mutatedChildren.begin(); it != mutatedChildren.end(); it++)
	{
		delete (*it);
	}
	mutatedChildren.clear();
	mutatedChildren.shrink_to_fit();*/
	while (!mutatedChildren.empty())
	{
		mutatedChildren.pop_back();
	}
}








