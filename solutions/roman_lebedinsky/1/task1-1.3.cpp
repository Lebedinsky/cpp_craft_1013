// task1-1.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input_file("input.txt", ios::in );
	ofstream output_file ("output.txt");

	string line, first_line = "";
	const string spec_symbols = " -\\";
	int numLine = 0;

	if (input_file)
	while (!input_file.eof())
	{
		getline(input_file, line);
		if (line.empty()) break;
		numLine++;
					
		int index = 0;
		while (index != -1) 
		{
			index = -1;
			index = line.find_first_of(spec_symbols);
			if (index != -1) 
				line.erase(line.begin()+index);
		}

		string reverse_line = "";
		for (int i = line.size()-1 ; i >= 0; i--)
		{
			if (line[i] >= 'A' && line[i] <= 'Z') 
				line[i] += 32;
			reverse_line += line[i];
		}

		if (numLine > 1)
		{
			int found = -1;
			found = first_line.find(reverse_line);
			if (found != -1) output_file << "YES" << endl;
			else output_file << "NO" << endl;
		}
		else first_line = line;
	}
	else output_file << "File not opened" << endl;

	input_file.close();
	output_file.close();
	return 0;
}

