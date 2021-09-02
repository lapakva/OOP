#include <iostream>
using namespace std;

// 1. В класс ForwardList добавить следующие методы:
// 	void push_back(???); DONE
// 	void pop_front();
// 	void pop_back();
// 	void insert(???);
// 	void erase(???);
// 2. Написать деструктор;
// 3. Написать CopyMethods и MoveMethods;

class Element
{
	int Data;
	Element *pNext;

public:
	Element(int Data, Element *pNext = nullptr) : Data(Data), pNext(pNext)
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
	Element *Head;

public:
	ForwardList()
	{
		Head = nullptr;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		Element *Temp = Head;

		while (Temp != nullptr)
		{
			Element *p = Temp->pNext;
			Temp = Temp->pNext;
			delete p;
		}
		cout << "LDestructor:\t" << this << endl;
	}

	//						Adding elements:
	void push_front(int Data)
	{
		Element *New = new Element(Data);
		New->pNext = Head;

		Head = New;
	}

	void push_back(int Data)
	{
		Element *New = new Element(Data);
		//find last pointer to the nullptr
		Element *Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = New;
	}

	void pop_front()
	{
		cout << " Element to front pop: " << Head->Data << endl;
		Head = Head->pNext;
	}

	void pop_back()
	{
		Element *Temp = Head;
		while ((Temp->pNext)->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		cout << " Element to back pop: " << Temp->pNext->Data << endl;
		Temp->pNext = nullptr;
	}

	void insert(int Data, int index)
	{
		Element *New = new Element(Data);
		Element *Temp = Head;
		Element *p = nullptr;

		int i = 0;

		while (Temp->pNext != nullptr)
		{
			if (!index)
			{
				this->push_front(Data);
				break;
			}
			else if (i == index - 1)
			{
				Element *p = Temp->pNext;
				Temp->pNext = New;
				New->pNext = p;
				break;
			}
			i++;
			Temp = Temp->pNext;
		}
		if (Temp->pNext == nullptr)
		{
			cout << " No element with index " << index << " in the List" << endl;
		}
	}

	void erase(int index)
	{
		Element *Temp = Head;
		Element *p = Head;

		int i = 0;

		while (Temp->pNext != nullptr)
		{
			if (!index)
			{
				this->pop_front();
				break;
			}
			else if (i == index)
			{

				p->pNext = Temp->pNext;
				break;
			}
			i++;
			p = Temp;
			Temp = Temp->pNext;
		}
		if (Temp->pNext == nullptr)
		{
			cout << " No element with index " << index << " in the List" << endl;
		}
	}

	//					Methods:
	void print() const
	{
		Element *Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Choose number of elements: ";
	cin >> n;
	ForwardList list;
	//push_front
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	list.push_back(123);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	list.insert(666, 2);
	list.print();
	cout << "##############" << endl;

	list.erase(3);
	list.print();

	return 0;
}
