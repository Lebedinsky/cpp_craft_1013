// 2.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include "Message.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	ifstream input_file ("input.txt", ios::binary);
	ofstream output_file ("output.txt", ios::binary);

	unsigned int maxTime =0;

	if (input_file)
	{
		Message mes;
		input_file >> mes;
		if (mes.getTime() > (maxTime - 2))
			output_file << mes;
		if (maxTime < mes.getTime()) maxTime = mes.getTime();
	}

	input_file.close();
	output_file.close();

	return 0;
}

