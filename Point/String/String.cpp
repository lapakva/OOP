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
	String(const char& word)
	{
		str = new char[max];
		*str = word;

	}

	~String()
	{
		delete[] str;
	
	}

	String& operator=(char* word)
	{
		auto length = std::strlen(str) + 1;
		for (int i = 0; i < length; i++) str[i] = word[i];
		
	
		cout << "CopyAssignment:\t" << this << endl;

		return this;
	}


};