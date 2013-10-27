// task1-1.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <cmath>
#include <stdint.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input_file ("input.txt", ios::in);
	ofstream output_file ("output.txt");

	const int degr = 10000;
	vector <int64_t> vectorD;
	double x;
	int64_t y;
	int countEl, counter = -2;

	while (input_file >> x)
	{
		counter++;
		if (counter == -1) countEl = x;
		if (counter >= 0 && counter < countEl) 
		{
			y = floor(x * degr) * degr;
			vectorD.push_back(y);
		}
		if (counter >= countEl)
		{
			double num = x;
			y = floor(x * degr) * degr;
			bool is_find = false;
			for (vector <int64_t>::const_iterator i = vectorD.begin(); i != vectorD.end(); ++i)
			{
				if (y == *i) 
				{
					is_find = true;
					output_file << "YES" << endl;
					break;
				}
			}
			if (!is_find) output_file << "NO" << endl;
		}
	}

	input_file.close();
	output_file.close();
	return 0;
}

