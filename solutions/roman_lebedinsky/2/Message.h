#include <stdint.h>
#include <iostream>

using namespace std;

class Message
{
public:
	uint32_t TYPE;
	uint32_t TIME;
	uint32_t LEN;
	char* MSG;

public:
	Message();

	~Message();

	unsigned int getTime ();

	friend istream &operator>> (istream &input, Message &mes);
	friend ostream &operator<< (ostream &output, Message &mes);

	bool operator<(const Message &mes) ;
	bool operator>(const Message &mes) ;
};