#ifndef PARENTCLASS_H
#define PARENTCLASS_H
using namespace std;

class Parents
{
private:
	vector<double> parent1Fitness;
	vector<string> parent1Number;

	vector<double> parent2Fitness;
	vector<string> parent2Number;
public:
	Parents()
	{
		/*parent1Fitness = 0.0;
		parent1Number = "n/a";

		parent2Fitness = 0.0;
		parent2Number = "n/a";*/
	}
	void setp1fitness(double p1fit)
	{
		parent1Fitness.push_back(p1fit);
	}
	void setp1Nuber(string p1num)
	{
		parent1Number.push_back(p1num);
	}
	void setp2fitness(double p2fit)
	{
		parent2Fitness.push_back(p2fit);
	}
	void setp2Nuber(string p2num)
	{
		parent2Number.push_back(p2num);
	}

	vector<double> getp1fitness()
	{
		vector<double> p1FitTotal;
		for (vector<double>::iterator it = parent1Fitness.begin(); it != parent1Fitness.end(); it++)
		{
			p1FitTotal.push_back((*it));
		}
		return p1FitTotal;

	}
	vector<string> getp1Nuber()
	{
		vector<string> p1NumTotal;
		for (vector<string>::iterator it = parent1Number.begin(); it != parent1Number.end(); it++)
		{
			p1NumTotal.push_back((*it));
		}
		return p1NumTotal;
	}
	vector<double> getp2fitness()
	{
		vector<double> p2FitTotal;
		for (vector<double>::iterator it = parent2Fitness.begin(); it != parent2Fitness.end(); it++)
		{
			p2FitTotal.push_back((*it));
		}
		return p2FitTotal;
	}
	vector<string> getp2Nuber()
	{
		vector<string> p2NumTotal;
		for (vector<string>::iterator it = parent2Number.begin(); it != parent2Number.end(); it++)
		{
			p2NumTotal.push_back((*it));
		}
		return p2NumTotal;
	}
	double getp1fitnessTotal()
	{
		double p1FT = 0.0;
		for (vector<double>::iterator it = parent1Fitness.begin(); it != parent1Fitness.end(); it++)
		{
			p1FT += (*it);
		}
		return p1FT;
	}
	string getp1NuberTotal()
	{
		string p1NT;
		for (vector<string>::iterator it = parent1Number.begin(); it != parent1Number.end(); it++)
		{
			p1NT += ((*it));
			p1NT += " ";
		}
		return p1NT;
	}
	double getp2fitnessTotal()
	{
		double p2FT = 0.0;
		for (vector<double>::iterator it = parent2Fitness.begin(); it != parent2Fitness.end(); it++)
		{
			p2FT += ((*it));
		}
		return p2FT;
	}
	string getp2NuberTotal()
	{
		string p2NT;
		for (vector<string>::iterator it = parent2Number.begin(); it != parent2Number.end(); it++)
		{
			p2NT += ((*it));
			p2NT += " ";
		}
		return p2NT;
	}

};
#endif