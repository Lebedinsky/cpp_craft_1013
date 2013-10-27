#include "stdafx.h"
#include "Message.h"

Message::Message()
{
	TYPE = 0;
	LEN = 0;
	TIME = 0;
	MSG = "";
}

Message::~Message()
{
}

istream &operator >> (istream &input, Message &mes)
{
	input.read((char*) &mes.TYPE, sizeof(unsigned int));
	input.read((char*) &mes.TIME, sizeof(unsigned int));
	input.read((char*) &mes.LEN, sizeof(unsigned int));
	mes.MSG = new char[mes.LEN + 1];
	input.read(mes.MSG, mes.LEN);
	return input;
}

ostream &operator << (ostream &output, Message &mes)
{
	output.write((char*) &mes.TYPE, sizeof(unsigned int));
	output.write((char*) &mes.TIME, sizeof(unsigned int));
	output.write((char*) &mes.LEN, sizeof(unsigned int));
	output.write(mes.MSG, mes.LEN);
	return output;
}

unsigned int Message::getTime()
{
	return TIME;
}

bool Message::operator<(const Message &mes)  {
    return (TIME < mes.TIME);
}

bool Message::operator>(const Message &mes)  {
    return (TIME > mes.TIME);
}
