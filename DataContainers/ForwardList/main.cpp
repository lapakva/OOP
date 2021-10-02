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
	static int count;
	int Data;
	Element *pNext;

public:
	Element(int Data, Element *pNext = nullptr) : Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
int Element::count = 0;

class ForwardList
{
	Element *Head;
	size_t size;

public:
	class Iterator
	{
	Element* Temp;
	public:
	Iterator(Element* Temp = nullptr):Temp(Temp)
	{
		cout<<"ItConstructor:\t"<< this <<endl;
	}
	~Iterator()
	{
		cout<<"ItDestructor:\t"<< this <<endl;
	}
	Iterator& operator++()
	{
		Temp =Temp->pNext;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator old = *this;
		Temp =Temp->pNext;
		return old;
	}
	bool operator==(const Iterator& other)
	{
		return this->Temp == other.Temp;
	}

	bool operator!=(const Iterator& other)
	{
		return this->Temp != other.Temp;
	}
	int& operator*()
	{
		return Temp->Data;
	} 
	};
	Iterator  begin()
	{
		return this->Head;
	}
	Iterator end()
	{
		return nullptr;
	}

	ForwardList()
	{
		Head = nullptr;
		size =0;
		cout << "LConstructor:\t" << this << endl;
	}

	ForwardList(const initializer_list<int>& il):ForwardList()
	{
			cout<<"Type: "<< typeid(il.begin()).name()<< endl;
			for (int const* it = il.begin(); it != il.end(); it++)
			{
				this->push_back(*it);
			}
	}
	ForwardList(const ForwardList& other):ForwardList()
	{
		for(Element* Temp  = other.Head; Temp; Temp =Temp->pNext)
			push_back(Temp->Data);

	}

	~ForwardList()
	{
		 while (Head) pop_front();
		// Element *Temp = Head;

		// while (!Temp)
		// {
		// 	Element *p = Temp;
		// 	Temp = Temp->pNext;
		// 	delete p;
		// }
		cout << "LDestructor:\t" << this << endl;
	}

	//Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		while (Head) pop_front();
		for(Element* Temp  = other.Head; Temp; Temp =Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}

	//						Adding elements:
	void push_front(int Data)
	{
		Element *New = new Element(Data);
		New->pNext = Head;

		Head = New;
		size++;
	}

	void push_back(int Data)
	{
	
		//find last pointer to the nullptr
		if (!Head) return push_front(Data);
		Element *Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
		size++;
	}
       //Removing elements
	void pop_front()
	{
		cout << " Element to front pop: " << Head->Data << endl;
		//remember address of element to delet
		
		Element* to_del = Head;
		Head = Head->pNext;
		delete to_del;
		size--;
	}

	void pop_back()
	{
		Element *Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		cout << " Element to back pop: " << Temp->pNext->Data << endl;
		
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void insert(int Data, int index)
	{
		Element *New = new Element(Data);
		Element *Temp = Head;
		
		int i = 0;
		if (index==0)return push_front(Data);
		if (index>=size) return push_back(Data);

		while (Temp->pNext)
		{
			if (!index)
			{
				this->push_front(Data);
				break;
			}
			else if (i == index - 1)
			{
				New->pNext = Temp->pNext;
				Temp->pNext = New;
				break;
			}
			i++;
			Temp = Temp->pNext;
		}
		size++;

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
		size--;
	}

	//					Methods:
	void print() const
	{
		Element *Temp = Head;
		// while (Temp != nullptr)
		// {
		// 	cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		// 	Temp = Temp->pNext;
		// }
		for(Element* Temp=Head; Temp!=nullptr; Temp=Temp->pNext)
		{ cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;}
		cout<<" Number of element in the list: " << size<<endl;
		cout<<" Number of all element: " << Element::count<<endl;
	}
};
// #define base_check
int main()
{
	setlocale(LC_ALL, "");
#ifdef base_check
	int n;
	cout << "Choose number of elements: ";
	cin >> n;
	ForwardList list;
	//push_front
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	// 
#endif //base_check

ForwardList list = {3,5,8,13,21};
for (int i: list){cout<<i<<"\t";}
// list.print();
// ForwardList list2 = list;
// list2.print();
// ForwardList list3;
// list3 = list2;
// list3.print();
	return 0;
}
