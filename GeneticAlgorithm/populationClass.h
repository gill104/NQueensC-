#ifndef POPULATIONCLASS_H
#define POPULATIONCLASS_H
using namespace std;
class Population
{
private:
	vector<string> number;
	vector<double> fitness;
	int size;
public:
	Population()
	{
		size = 0;
	}
	Population(vector<string> _number, vector<double> _fitness)
	{
		number = _number;
		fitness = _fitness;
	}
	void eraseNum()
	{
		while (!number.empty())
		{
			number.pop_back();
		}
	}
	void eraseFit()
	{
		while (!fitness.empty())
		{
			fitness.pop_back();
		}
	}
	void setnum(string n)
	{

		number.push_back(n);

	}
	void setfit(double f)
	{
		fitness.push_back(f);
	}

	int getSize()
	{
		return size;
	}
	
	vector<string> getnum()//pushes each character of the string in
	{
		vector<string> total;
		for (vector<string >::iterator it = number.begin(); it != number.end(); it++)
		{
			total.push_back((*it));
		}
		return total;
	}

	string getNumTotal()//get the total num, from start to finish (length)
	{
		string total = "";
		for (vector<string >::iterator it = number.begin(); it != number.end(); it++)
		{
			total += (*it);
			total += " ";
		}
		return total;
	}

	double getFitTotal()//gets the total length of fitness, stores in a vector
	{
		double fitnessT = 0.0;
		for (vector<double>::iterator it = fitness.begin(); it != fitness.end(); it++)
		{
			fitnessT += ((*it));
		}
		return fitnessT;
	}
	vector<double> getfit()//pushes each integer of fitness in
	{
		vector<double> fitnessT;
		for (vector<double>::iterator it = fitness.begin(); it != fitness.end(); it++)
		{
			fitnessT.push_back((*it));
		}
		return fitnessT;
	}
	void displayNum()//shows the total num on the screen all string
	{
		string allNum;
		for (vector<string >::iterator it = number.begin(); it != number.end(); it++)
		{
			allNum += (*it);
			allNum += " ";
		}
		cout << allNum << endl;
		//system("pause");
	}
	void displayFit()//show the total fitness on screen all numbers
	{
		for (vector<double >::iterator it = fitness.begin(); it != fitness.end(); it++)
		{
			cout << (*it);
		}
		//system("pause");
	}

};

class  compareFitness
{
public:
	bool operator() (Population *f, Population *g)
	{
		return f->getFitTotal() > g->getFitTotal();
	}
};
#endif