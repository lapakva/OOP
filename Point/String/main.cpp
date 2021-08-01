#include <iostream>
//#include "String.h"
using namespace std;
//#define constructors_check

class String;
String operator+(const String& left, const String& right);

class String
{
	unsigned int size; // string  size in bytes 
	char* str; // pointer to  string in dinamic memory

public:
	unsigned int get_size()const
	{
		return size;
	}

	const  char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	explicit String(unsigned int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		//while (str[size++]);
		this->size = strlen(str) + 1;// strlen считает размер в символах
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		cout << "1argConstructor: \t" << this << endl;

	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str; // указатель на указатель, [] говорить что удалить нужно масив
		//delet[] str;
		cout << "Destructor:\t" << this << endl;
	}

	//Operators
	String& operator=(const String& other)
	{
		//0) ѕровер€ем €вл€етс€ ли прин€тый обект нашем же объектом
		if (this == &other)return *this;
		//1) ”дал€ем старое значение обекта, освобождаем занимаему им пам€ть
		delete[] this->str;
		//2) выполн€ем deep copy;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	const char& operator[](unsigned int i)const // i - index
	{
		return str[i];
	}
	char& operator[](unsigned int i) // i - index
	{
		return str[i];
	}

	

	//Methods

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

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

void main()
{
#ifdef constructors_check
	cout << "This is a String class playground" << sizeof(char) << endl;
	String A(5); //  implicit conversion from int to string
	A.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();

	String str2 = str1; //CopyConstructor
	str2.print();
	
	String str3;
	str3 = str2;
	str3.print();
#endif //constructors_check
	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	/*String str3 = str1 +" "+ str2;
	cout << str3 << endl;*/
	str1 += str2;
	cout << str1 << endl;;

	


	
}