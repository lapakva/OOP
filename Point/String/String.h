#pragma once
#include <iostream>
using namespace std;
///////////////////Class Declaration///////////////////

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

class String
{
	unsigned int size; // string  size in bytes 
	char* str; // pointer to  string in dinamic memory

public:
	unsigned int get_size()const;

	const  char* get_str()const;
	char* get_str();

	explicit String(unsigned int size = 80);
	String(const char* str);
	String(const String& other);
	~String();

	//Operators
	String& operator=(const String& other);

	String& operator+=(const String& other);
	const char& operator[](unsigned int i)const;
	char& operator[](unsigned int i);



	//Methods

	void print()const;
};
/////////////////////////////////////////////////

