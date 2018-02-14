#ifndef NQUEENSCLASS_H
#define NQUEENSCLASS_H
using namespace std;
class Nqueens
{
private:
	int row;
	int col;
	string **map;
public:
	Nqueens()
	{
		row = 0;
		col = 0;
	}
	~Nqueens()
	{
		delete [] map;
	}
	void setSizes(int s)
	{
		row = s;
		col = s;
	}
	void makeMap()
	{
		map = new string*[row];
		for (int i = 0; i < row; i++)
		{
			map[i] = new string[col];
		}

		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				map[x][y] = "[ ]";
			}
		}
	}
	void display()
	{
		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				cout << map[x][y];
			}
			cout << endl;
		}
	}
	int checkFitness(vector<string> passedString)
	{
		makeMap();
		string Location;
		int counter = 0;
		double fitness = 0;
		int sizeOFPassedString = 0;

		for (vector<string >::iterator it = passedString.begin(); it != passedString.end(); it++)
		{
			sizeOFPassedString++;
		}
		//cout << sizeOFPassedString << endl;
		for (int x = 0; x < sizeOFPassedString; x++)
		{
			Location = passedString.front();
////////////cout << "inputing into map: " << Location << endl;
			passedString.erase(passedString.begin());
			//cout << "Location Found!" << ":: " << Location << endl;
			putInMap(Location, counter);
			//system("pause");
			counter++;
			Location = "";
		}

		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				if (map[x][y] == "[&]")//reversed X and Y to check top down, left right for queens
				{
					//cout << "we found a QUEEN!" << endl;
					//cout << "Location X: " << x << "\nLocation Y:" << y << endl;

					fitness += checkNE(x, y);
					fitness += checkSE(x, y);
					fitness += checkNW(x, y);
					fitness += checkSW(x, y);
				}
			}

		}
		
		//display();
///////cout << "thirness of this is " << 1 / (fitness + .001) << endl;
		//cout << "string: " << passedString << " with a fitness of : " << fitness << endl;
		return fitness;

		//system("pause");
	}
	int checkNE(int xPassed, int yPassed)
	{

		for (int x = xPassed; x < row;)//checking for NE diagnol
		{
			for (int y = yPassed; y < col;)
			{
				x--;
				y++;
				if (x < 0 || y > row - 1)
				{
					return 0;
				}
				else
				{
					if (map[x][y] == "[&]")
					{
						//	cout << "Found a Confilct!";
						//	system("pause");
						return 1;
					}
				}
			}
		}
	}
	int checkSE(int xPassed, int yPassed)
	{
		for (int x = xPassed; x < row;)//checking for NE diagnol
		{
			for (int y = yPassed; y < col;)
			{
				x++;
				y++;
				if (x > row - 1 || y > row - 1)
				{
					return 0;
				}
				else
				{
					if (map[x][y] == "[&]")
					{
						//	cout << "Found a Confilct!";
						//system("pause");
						return 1;
					}
				}
			}
		}
	}
	int checkSW(int xPassed, int yPassed)
	{
		for (int x = xPassed; x < row;)//checking for NE diagnol
		{
			for (int y = yPassed; y < col;)
			{
				x++;
				y--;
				if (x > row - 1 || y < 0)
				{
					return 0;
				}
				else
				{
					if (map[x][y] == "[&]")
					{
						//cout << "Found a Confilct!";
						//system("pause");
						return 1;
					}
				}
			}
		}
	}
	int checkNW(int xPassed, int yPassed)
	{
		for (int x = xPassed; x < row;)//checking for NE diagnol
		{
			for (int y = yPassed; y < col;)
			{
				x--;
				y--;
				if (x < 0 || y < 0)
				{
					return 0;
				}
				else
				{
					if (map[x][y] == "[&]")
					{
						//cout << "Found a Confilct!";
						//system("pause");
						return 1;
					}
				}
			}
		}
	}
	void putInMap(string Location, int counter)
	{
		int num = strtol(Location.c_str(), NULL, 10);
		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				if (x == num)
				{
					map[x][counter] = "[&]";
					break;
				}
			}

		}
	}
};
#endif