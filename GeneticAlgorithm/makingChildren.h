#ifndef MAKINGCHILDREN_H
#define MAKINGCHILDREN_H

void makingChildren(vector<Population *> matingPool, vector<Population *>& children, int Nsize)
{
	//cout << "makingChildren" << endl;
	//int tempC = 0;
	//for (vector<Population * >::iterator it = matingPool.begin(); it != matingPool.end(); it++)
	//{
	//	cout << tempC << ": makingChildren strings " << (*it)->getNumTotal() << endl;
	//	cout << tempC << ": makingChildren fitness " << (*it)->getFitTotal() << endl;
	//	tempC++;
	//}
	//system("pause");
	Parents *par;
	Population *newChild;

	vector <Parents *> pairedParents;
	//vector <Population *> children;

	int randomLocationGenotypeC1 = 0;
	int randomLocationGenotypeC2 = 0;
	
	string p1String;
	string p2String;

	stringstream ss1;
	string c1String;

	stringstream ss2;
	string c2String;

	string p1Front = "";
	string p1Back = "";//fitness

	string p2Front = "";
	string p2Back = "";//fitness

	string  p1randCharacter = " ";
	string p2randCharacter = " ";

	string child1 = "";
	string child2 = "";
	int paringCounter = 0;

	for (vector<Population *>::iterator it = matingPool.begin(); it != matingPool.end(); it++)//counting the number of elements in matingpool
	{
		paringCounter++;
		//system("pause");
	}

	vector<string> Vptemp;
	vector<string> V2ptemp;
	string p1temp;
	string p2temp;

	for (int x = 0; x < paringCounter / 2; x++)
	{

		par = new Parents();
		Vptemp = matingPool.front()->getnum();
				
		par->setp1fitness(matingPool.front()->getFitTotal());
		//par->setp1Nuber(matingPool.front()->getNumTotal());

		for (vector<string >::iterator it = Vptemp.begin(); it != Vptemp.end(); it++)
		{
			p1temp = (*it);
			par->setp1Nuber(p1temp);//makes sure each number is stored seprately
		}

		matingPool.erase(matingPool.begin());

		V2ptemp = matingPool.front()->getnum();

		par->setp2fitness(matingPool.front()->getFitTotal());
		//par->setp2Nuber(matingPool.front()->getNumTotal());

		for (vector<string >::iterator it = V2ptemp.begin(); it != V2ptemp.end(); it++)
		{
			p2temp = (*it);
			par->setp2Nuber(p2temp);//makes sure each number is stored seprately
		}
		matingPool.erase(matingPool.begin());

		pairedParents.push_back(par);
	}
	int ppSize = pairedParents.size();

	while (ppSize > 0)
	{
		p1Front = "";
		p1Back = "";
		p2Front = "";
		p2Back = "";
		p1randCharacter = " ";
		p2randCharacter = " ";
		child1 = "";
		child2 = "";
		c1String = "";
		c2String = "";
		//starting crossover



	//	cout << endl << endl << endl;
//cout << "1 paired parents num: " << pairedParents.front()->getp1NuberTotal() << endl;
//cout << "1 paired parents fitness: " << pairedParents.front()->getp1fitnessTotal() << endl;

//cout << "2 paired parents num: " << pairedParents.front()->getp2NuberTotal() << endl;
//cout << "2 paired parents fitness: " << pairedParents.front()->getp2fitnessTotal() << endl;

		//these ensure i get a number in the string, since the numbers are on even intervoles stored as "1 2 3 4 5 6"
		randomLocationGenotypeC1 = rand() % (Nsize-2)+2;//will cuase to have something to snip
//cout << "1 randomNumberGenerated: " << randomLocationGenotypeC1 << endl;
		
		p1randCharacter = pairedParents.front()->getp1Nuber()[randomLocationGenotypeC1];

//cout << "p1randcharacter: " << p1randCharacter << endl;

		randomLocationGenotypeC2 = rand() % (Nsize-2)+2;//will have something to snip

		/*cout << "randomLocationGenotypeC2: " << randomLocationGenotypeC2 << endl;
		pairedParents.front()->getp2Nuber();
		cout << "location of the rand: " << pairedParents.front()->getp2Nuber()[randomLocationGenotypeC2] << endl;*/
		p2randCharacter = pairedParents.front()->getp2Nuber()[randomLocationGenotypeC2];
//cout << "2 randomNumberGenerated: " << randomLocationGenotypeC2 << endl;
//cout << "p2randCharacter: " << p2randCharacter << endl;
		//system("pause");

		vector<string> child1;
		vector<string> child2;

		for (int x = 0; x < pairedParents.front()->getp1Nuber().size(); x++)//splits the string to the front protion, including the character that caused the split
		{
			if (pairedParents.front()->getp1Nuber()[x] != p1randCharacter)
			{
				p1Front = pairedParents.front()->getp1Nuber()[x];
				child1.push_back(p1Front);
			}
			else
			{
				p1Front = pairedParents.front()->getp1Nuber()[x];
				child1.push_back(p1Front);
				break;
			}

		}

		for (int x = 0; x < pairedParents.front()->getp2Nuber().size(); x++)//splits the string to the front protion, including the character that caused the split
		{
			if (pairedParents.front()->getp2Nuber()[x] != p2randCharacter)
			{
				p2Front = pairedParents.front()->getp2Nuber()[x];
				child2.push_back(p2Front);
			}
			else
			{
				p2Front = pairedParents.front()->getp2Nuber()[x];
				child2.push_back(p2Front);
				break;
			}
		}

		bool f = false;

		for (int x = 0; x < pairedParents.front()->getp2Nuber().size(); x++)
		{
			for (vector<string>::iterator it = child1.begin(); it != child1.end(); it++)
			{
				if (*it == pairedParents.front()->getp2Nuber()[x])
				{
					f = true;
					break;
				}
				//system("pause");
			}
			if (f == false)
			{
				child1.push_back(pairedParents.front()->getp2Nuber()[x]);
			}
			f = false;
		}
	

		bool f2 = false;
		for (int x = 0; x < pairedParents.front()->getp1Nuber().size(); x++)
		{
			for (vector<string>::iterator it = child2.begin(); it != child2.end(); it++)
			{
				if (*it == pairedParents.front()->getp1Nuber()[x])
				{
					f2 = true;
					break;
				}
				//system("pause");
			}
			if (f2 == false)
			{
				child2.push_back(pairedParents.front()->getp1Nuber()[x]);
			}
			f2 = false;
		}
		//system("pause"); 

		newChild = new Population();
		int sizeTemp = child1.size();

		for (int x = 0; x < sizeTemp; x++)
		{

			newChild->setnum(child1.front());
			
			child1.erase(child1.begin());

	
		}
		//newChild->setfit(pairedParents.front()->getp1fitnessTotal());
////////cout << "pushing child1: " << newChild->getNumTotal() << endl;
		//system("pause");
		children.push_back(newChild);


		newChild = new Population();
		int size2Temp = child2.size();

		for (int x = 0; x < size2Temp; x++)
		{
	
			newChild->setnum(child2.front());
			
			child2.erase(child2.begin());


		}
		//newChild->setfit(pairedParents.front()->getp2fitnessTotal());
/////////cout << "pushing child2: " << newChild->getNumTotal()<< endl;
		//system("pause");
		children.push_back(newChild);

		pairedParents.erase(pairedParents.begin());
		ppSize--;
	}
	//system("pause");
}

#endif