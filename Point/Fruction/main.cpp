#include <iostream>
using namespace std;

//#define constructors_check
//#define increment_check
//#define arichmetical_operators_check
//#define TYPE_CONVERSIONS_HOME_WORK

class Fraction;
Fraction operator*(Fraction left, Fraction right);
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
	explicit operator int()
	{
		return integer;
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



bool operator== (Fraction left, Fraction rigth)
{
	left.to_proper();
	rigth.to_proper();
	left.reduce();
	rigth.reduce();


	return 
		(left.get_integer() == rigth.get_integer() &&
			left.get_numerator() == rigth.get_numerator() &&
			left.get_denominator() == rigth.get_denominator());
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

	int a = 3;
	int b = 6;
	cout << euclideanGcd(6, 3);
	Fraction A = Fraction(2, 6, 12);
	A.print();
	A.reduce();
	A.print();
	Fraction B = Fraction (2, 6, 12);
	B.print();
	B.reduce();
	B.print();
	cout << endl << (A == B) << endl;
	/*operator type()
	{
		..........
		..........
	}*/
#ifdef TYPE_CONVERSIONS_HOME_WORK
	//Task1
	Fraction A(2, 3, 4);
	double a = A;
	cout << a << endl;

	//Task2
	double b = 3.14;
	Fraction B = b;
	B.print();
#endif // TYPE_CONVERSIONS_HOME_WORK

}
