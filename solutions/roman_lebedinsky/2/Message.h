
#include <iostream>

using namespace std;

class Message
{
private:
	unsigned int TYPE;
	unsigned int TIME;
	unsigned int LEN;
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