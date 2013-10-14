// task1-1.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input_file ("input.txt" , ios::in);
	ofstream output_file ("output.txt");

	vector<string> vect_lines;
	string line;
	
	int sizeX = 0, sizeY = 0;

	while (!input_file.eof())
	{
		getline(input_file, line);
		if (line.empty()) break;
		sizeX = line.size();
		sizeY++;
		vect_lines.push_back(line);	
	}
	sizeX+=2;
	sizeY+=2;

	char **map = new char*[sizeY];
	for (int i = 0; i < sizeY; i++)
		map[i] = new char[sizeX];
	for (int i = 0; i < sizeY; i++)
		for (int j = 0; j < sizeX; j++)
			map[i][j] = '~';
	
	for (int i = 0; i< sizeY-2; i++)
	{
		string line = *vect_lines.rbegin();
		vect_lines.pop_back();
		for(int j = 0; j < sizeX-2; j++)
			map[i][j] = line[j];
	}
	
	for (int i = sizeY-1; i >= 0; i--)
		for(int j = sizeX-1; j >= 0; j--)
			map[i][j] = map[i][j-1];
	
	for (int i = sizeY-1; i > 0; i--)
		for(int j = sizeX-1; j > 0; j--)
			map[i][j] = map[i-1][j];

	for (int i = 0; i < sizeY; i++)
	{
		map[i][0] = '~';
		map[i][sizeX] = '~';
	}

	for (int j = 0; j < sizeX; j++)
	{
		map[0][j] = '~';
		map[sizeY-1][j] = '~';
	}

	int **num_map = new int*[sizeY];
	for (int i = 0; i < sizeY; i++)
		num_map[i] = new int[sizeX];
	for (int i = 0; i < sizeY; i++)
		for (int j = 0; j < sizeX; j++)
			num_map[i][j] = 0;

	int count_islands = 0;

	for (int i = 1; i < sizeY-1; i++)
		for(int j = 1; j < sizeX-1; j++)
		{
			if (map[i][j] =='o')
				if ((num_map[i-1][j] > 0) || (num_map[i+1][j] > 0) || (num_map[i][j-1] > 0) || (num_map[i][j+1] > 0))
					num_map[i][j] = max(max(num_map[i-1][j],num_map[i+1][j]),max(num_map[i][j-1],num_map[i][j+1]));
				else 
				{	
					count_islands++;
					num_map[i][j] = count_islands;
				}	
		}
	count_islands--;
	output_file << count_islands;

    delete [] map;
	delete [] num_map;
	return 0;
}

