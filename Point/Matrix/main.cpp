#include <iostream>
//#include "String.h"
using namespace std;
//#define constructors_check



///////Class Defenition//////////////////////
unsigned int String::get_size()const
{
	return size;
}

const  char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

 String::String(unsigned int size) :size(size), str(new char[size
] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)//���������� ��������� ������ ������� ������������
{
	//while (str[size++]);
	//this->size = strlen(str) + 1;// strlen ������� ������ � ��������
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = str[i];
	cout << "1argConstructor: \t" << this << endl;

}
String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};*/
	//for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}

String::~String()
{
	delete[] this->str; // ��������� �� ���������, [] �������� ��� ������� ����� �����
	//delet[] str;
	cout << "Destructor:\t" << this << endl;
}

//Operators
String& String::operator=(const String& other)
{
	//0) ��������� �������� �� �������� ����� ����� �� ��������
	if (this == &other)return *this;
	//1) ������� ������ �������� ������, ����������� ��������� �� ������
	delete[] this->str;
	//2) ��������� deep copy;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++) this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
const char& String::operator[](unsigned int i)const // i - index
{
	return str[i];
}
char& String::operator[](unsigned int i) // i - index
{
	return str[i];
}



//Methods

void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
		//cat.get_str()[i+left.get_size()-1] = right.get_str()[i];
	return cat;

}
