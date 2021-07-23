# define _CRT_SECURE_NO_WARNINGS//for strtok
#include <iostream>
using namespace std;

//#define constructors_check
//#define increment_check
//#define arichmetical_operators_check
#define TYPE_CONVERSIONS_HOME_WORK
//#define COMPERISON_OPERATORS
//#define OUTPUT_CHECK
//#define IMPUT_CHECK

class Fraction;
Fraction operator*(Fraction left, Fraction right);
bool operator==(const Fraction& left, const Fraction& rigth);
bool operator>(const Fraction& left, const Fraction& rigth);

int  euclideanGcd(int a, int b);

class Fraction
{

	int integer;  //целая часть
	int numerator; //Числитель
	int denominator;// Знаменатель
public:
	int get_integer() const
	{
		return integer;
	}	
	
	int get_numerator() const
	{
		return numerator;
	}	
	
	int get_denominator() const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	// Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal *denominator;
		reduce();
	}

	Fraction( int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);// можем просто set_denominator(denominator)
		cout << "Constructor:\t" << this << endl;
	}
	

	Fraction(int integer, int numerator, int denominator )
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;

	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		//*this = *this * other;
		return *this = *this * other; ;
	}


	// Increment/Decrement:

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int) //Postfix increment
	{
		Fraction old = *this;//сохраняем старое значениею Copy Constructor
		integer++;
		return old;// CopyConstructor
	}

	Fraction& operator--()
	{
		integer-- ;
		return *this;
	}

	// type cast operator
	explicit operator int()const
	{
		return integer;
	}

	explicit operator double()const
	{
		return integer + (double) numerator / denominator;
	}


	//        Methods
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator/denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction& reduce()
	{
		to_proper();
		int max_com_div = euclideanGcd(numerator , denominator);
		numerator /= max_com_div;
		denominator /= max_com_div;
		return *this;
	
	}

	void print()const
	{
		if (integer) cout << integer;
		if (integer && numerator) cout << "(";
		if (numerator) cout << numerator << "/" << denominator;
		if (integer && numerator) cout << ")";
		if (integer == 0 && numerator == 0) cout << 0;
		cout << endl;

	}
	Fraction inverted()// обращает дробь
	{
		to_improper();
		/*int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;*/
		return Fraction(denominator, numerator);
	}
};

Fraction operator* (Fraction left, Fraction rigth)
{
	left.to_improper();
	rigth.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * rigth.get_numerator());
	result.set_denominator(left.get_denominator() * rigth.get_denominator());*/
	
	
	/*Fraction result
	(
		left.get_numerator() * rigth.get_numerator(),
		left.get_denominator() * rigth.get_denominator()
	);
		return result;*/
	return Fraction
	(
		left.get_numerator() * rigth.get_numerator(),
		left.get_denominator() * rigth.get_denominator()
	);

}
Fraction operator/(Fraction left, Fraction rigth)
{
	//left.to_improper();
	//rigth.to_improper();
	//return Fraction
	//(
	//	left.get_numerator() * rigth.get_denominator(),
	//	left.get_denominator() * rigth.get_numerator()
	//);
	
	return left * rigth.inverted();

}
Fraction operator+(Fraction left, Fraction rigth)
{
	left.to_improper();
	rigth.to_improper();
	//Fraction sum(
	//	left.get_numerator()* rigth.get_denominator() +
	//	rigth.get_numerator()* left.get_denominator(),
	//	left.get_denominator() * rigth.get_denominator()
	//);
	//sum.to_proper();
	//return sum;
	return Fraction (left.get_numerator()* rigth.get_denominator() +
		rigth.get_numerator()* left.get_denominator(),
		left.get_denominator() * rigth.get_denominator()
	).to_proper();
}



//bool operator==(Fraction left, Fraction rigth)
//{
//	left.to_proper();
//	rigth.to_proper();
//	left.reduce();
//	rigth.reduce();
//
//
//	return 
//		(left.get_integer() == rigth.get_integer() &&
//			left.get_numerator() == rigth.get_numerator() &&
//			left.get_denominator() == rigth.get_denominator());
//}



bool operator==(const Fraction& left, const Fraction& right)
{
	return (double)left == (double) right;
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(const Fraction& left, const Fraction& right)
{
	//left.to_improper();
	//rigth.to_improper();


	//return  (double)left.get_numerator() / left.get_denominator() > (double)rigth.get_numerator() / rigth.get_denominator();
	//return (double)left > (double)right;
	return (double) left > (double) right;

}

bool operator<(const Fraction& left, const Fraction& right)
{
	return (double)left < (double)right;
}

bool operator>=(const Fraction& left, const Fraction& right)
{
	//return  (left > right)||(left == right);
	return  !(left < right);
}


bool operator<=(const Fraction& left, const Fraction& right)
{
	//return  (left > right)||(left == right);
	return  !(left > right);
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator()) os << "(";
	if (obj.get_numerator()) os << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator()) os << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0) os << 0;
	return os;
}

istream& operator>>(istream& is,  Fraction& obj)
{
	//int integer, numerator, denominator;
	//is >> integer >> numerator >> denominator;
	//obj.set_integer(integer);
	//obj.set_numerator (numerator);
	//obj.set_denominator(denominator);
	const int n = 32;
	char buffer[n] = {};
	char delimeters[] = "(/) +";
	char* number[5] = {};
	cin.getline(buffer, n);
	int i = 0;
	
		for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters), i++)
		{
			number[i] = pch;
		}
		switch (i)
		{
		case 1: obj.set_integer(atoi(number[0])); break;
		case 2: obj.set_numerator(atoi(number[0]));
			obj.set_denominator(atoi(number[1]));
			break;
		case 3: 
			obj.set_integer(atoi(number[0]));
			obj.set_numerator(atoi(number[1]));
			obj.set_denominator(atoi(number[2]));
			break;
		default: cout << "Error: " << endl;

		}
	return is;
}


int  euclideanGcd(int a, int b) {
	int t;
	while (b != 0)
	{

		t = b;
		b = a % b;
		a = t;

	}
	return a;


}

void main()

{

#ifdef constructors_check

	Fraction A; //Default consructor
	A.print();	
	Fraction B = 3; //Default consructor
	B.print();
	Fraction C(3,4);
	C.print();
	Fraction D(2,3,4);
	D.print();
	Fraction E = D; //CopyConstructor
	E.print();

	Fraction F;
	F = E; // Copy Assignment
	F.print();

#endif // constructors_check
#ifdef arichmetical_operators_check
	Fraction A(2,3,4);
	Fraction B(3,4,5);
	Fraction C = A * B;
	C.print();
	Fraction D = A / B;
	D.print();
	Fraction E = A + B;
	E.print();
#endif 

#ifdef increment_check

	for (double i = .25; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif
	//A.print();
	//B.print();
	//A.to_improper();
	//A.print();
	//A.to_proper();
	//A.print();

#ifdef COMPERISON_OPERATORS

	//Fraction A(2, 3, 4);
	//Fraction B(3, 4, 5); 
	//A *=  B;// implicit operator call
	//A.operator*=(B); // explicit operator call
	//operator*(A,B); // explicit operator call
	//A.print();


	//int a = 2;
	//Fraction A = Fraction(5);
	//A.print();
	//Fraction B;
	//B =(Fraction)3;
	//B.print();

	//int b;
	//b = (int)B;

	/*int a = 3;
	int b = 6;
	cout << euclideanGcd(6, 3);*/
	/*Fraction A = Fraction(2, 6, 12);
	A.print();
	A.reduce();
	A.print();
	Fraction B = Fraction (2, 7, 12);
	B.print();
	B.reduce();
	B.print();
	cout << endl << "(A == B): " << (A == B) << endl;
	cout << endl << "(A != B): " << (A != B) << endl;
	cout << endl << "(A > B): " << (A > B) << endl;*/
	/*operator type()
	{
		..........
		..........
	}*/

#endif // COMPERISON_OPERATORS

#ifdef OUTPUT_CHECK
	Fraction A(2, 3);
	cout << A << endl;

#endif // OUTPUT_CHECK

#ifdef IMPUT_CHECK
	Fraction A;
	cin >> A; 
	cout << A << endl;

#endif // IMPUT_CHECK

#ifdef TYPE_CONVERSIONS_HOME_WORK
	//Task1
	Fraction A(2, 3, 4);
	double a = (double) A;
	cout << a << endl;

	//Task2
	double b = 2.75;
	Fraction B = b;
	B.print();
#endif // TYPE_CONVERSIONS_HOME_WORK

}
