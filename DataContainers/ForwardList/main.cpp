#include <iostream>
using namespace std;
class Element
{
	int Data; //
	Element* pNext; // next element adress
public:
	Element(int D, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
class ForwardList
{
	Element* Head;// head of the list, point to first element in the list
public:
	ForwardList()
	{
		Head = nullptr;//create empty list
		// if head point to  0 then list is empty
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	//Adding elements:
	void push_front(int Data)
	{
		//create new element
		Element* New = new Element(Data);
		// connect element to the list;
		New->pNext = Head;
		//say that new element is no first element of the list
		Head = New;

	}
};

void main()
{
	//Element e = 5;
	int n; cout << "Enter size of the list"; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}

}