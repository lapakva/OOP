#include <iostream>
using namespace std;


class String
{
	const int max = 20; //default string length 80 byte, 1 int is 4 byte
	char *str; //pointer to an array

public:
	String()
	{
		str = new char[max];

		cout << "DefaultConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] str;
		str = nullptr;
	}


};