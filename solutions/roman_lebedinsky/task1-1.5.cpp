// task1-1.5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
//#include <utility>

using namespace std;

bool inMap(long i, long j , int sizeX, int sizeY)
{
	if ((i>=0) & (j>=0)) 
		if ((i<sizeY) & (j<sizeX)) return true;
	else return false;
}

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
	/*sizeX+=2;
	sizeY+=2;
	*/
	char **map = new char*[sizeY];
	for (int i = 0; i < sizeY; i++)
		map[i] = new char[sizeX];
	for (int i = 0; i < sizeY; i++)
		for (int j = 0; j < sizeX; j++)
			map[i][j] = '~';
	
	vector<string> v;

	for (int i = 0; i < sizeY; i++)
	{
		v.push_back(*vect_lines.rbegin());
		vect_lines.pop_back();
	}

	for (int i = 0; i< sizeY; i++)
	{
		string line = *v.rbegin();
		v.pop_back();
		for(int j = 0; j < sizeX; j++)
			map[i][j] = line[j];
	}

	vector<pair <long , long>> bfs_coord;
	long count_islands = 0;

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (map[i][j] == 'o')
			{
				map[i][j] = '~';
				count_islands++;
				pair<long, long> coord(i,j);
				bfs_coord.push_back(coord);
				vector<pair <long , long>>::iterator s = bfs_coord.begin();
				vector<pair <long , long>>::iterator f = bfs_coord.end();
				int p = 0;
				while (s != f)
				{
					p++;
					pair<long, long> c = *s;
					if (inMap(c.first-1,c.second, sizeX, sizeY) && (map[c.first-1][c.second] == 'o'))
					{
						pair<long, long> newPair (c.first-1, c.second);
						bfs_coord.push_back(newPair);
						f = bfs_coord.end();
						map[c.first-1][c.second] = '~';
					}
					if (inMap(c.first+1,c.second, sizeX, sizeY) && (map[c.first+1][c.second] == 'o'))
					{
						pair<long, long> newPair (c.first+1, c.second);
						bfs_coord.push_back(newPair);
						f = bfs_coord.end();
						map[c.first+1][c.second] = '~';
					}
					if (inMap(c.first,c.second-1, sizeX, sizeY) && (map[c.first][c.second-1] == 'o'))
					{
						pair<long, long> newPair (c.first, c.second-1);
						bfs_coord.push_back(newPair);
						f = bfs_coord.end();
						map[c.first][c.second-1] = '~';
					}
					if (inMap(c.first,c.second+1, sizeX, sizeY) && (map[c.first][c.second+1] == 'o'))
					{
						pair<long, long> newPair (c.first, c.second+1);
						bfs_coord.push_back(newPair);
						f = bfs_coord.end();
						map[c.first][c.second+1] = '~';
					}
					s = bfs_coord.begin() + p;
				}
				bfs_coord.clear();
			}
		}
	}

	output_file << count_islands;

    delete [] map;
	return 0;
}

