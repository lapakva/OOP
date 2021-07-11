#include <iostream>
#include <cmath>
using namespace std;
#define tab "\t"
//#define STRACT_POINT
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
#define delimeter "\n-----------------------------------------------------\n"

//#define constructor_overloading 
class Point

{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}

	void set_x(double x)
	{
		Point::x = x;
	}
	void set_y(double y)
	{
		Point::y = y;
	}
	// COnstructors
#ifdef constructor_overloading

	Point()
	{	//конструктор по умолчанию
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;

	}

	Point(double x)
	{	//конструктор  с одним параметром
		this->x = x;
		this->y = 0;
		cout << "SinglArgumentConstructor:\t" << this << endl;

	}
#endif // constructor_overloading

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "NormalConstructor:\t" << this << endl;

	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}


	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;

		return *this;
	}

	double distance(const Point& other) const

	{
		double x_dist = this->x - other.x;
		double y_dist = this->y - other.y;
		return sqrt(pow(x_dist, 2) + pow(y_dist, 2));
	}
	void print() const
	{
		cout << "X= " << x << tab << "Y= " << y << endl;

	}

};


double distance(const Point& A, const Point& B)
{
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}


void main()
{

#ifdef STRACT_POINT
	Point A;
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;
	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;

#endif // STRACT_POINT
#ifdef DISTANCE_CHECK
	Point A;
	Point B;

	A.set_x(2);
	A.set_y(3);
	B.set_x(5);
	B.set_y(5);
	cout << delimeter << endl;
	cout << A.get_x() << tab << A.get_y() << endl;
	cout << delimeter << endl;
	cout << "Distance to point  " << A.distance(B) << endl;
	cout << delimeter << endl;
	cout << "Distance between points  " << distance(A, B) << endl;


#endif // DISTANCE_CHECK


#ifdef CONSTRUCTORS_CHECK

	Point A; //default constructor
	A.print();
	Point B = 3; //Single-argument constructor
	B.print();
	Point C(2, 3); //Parametrized  constructor
	C.print();
	Point D = C; //copyConstuctor
	D.print();
	Point E; //DefaultConstructor
	E = C; //CopyAssignment
	E.print();

#endif //CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << "\n-----------------------------------------------------\n";
	A = B = C = Point(4, 5);
	cout << "\n-----------------------------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK


}

