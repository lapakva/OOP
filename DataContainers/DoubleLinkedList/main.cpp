#include <iostream>
using namespace std; 

class Element
{
	static int count;
	int Data;
	Element *pNext; // pointer to next element
    Element *pPriv;// pointer to prior element

public:
	Element(int Data, Element *pNext = nullptr, Element *pPriv = nullptr)
     : Data(Data), pNext(pNext), pPriv(pPriv)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class DoubleList;
};
int Element::count = 0;


class DoubleList
{
	Element *Head;
    Element *Tail;
	size_t size;

public:
	DoubleList()
	{
		Head = nullptr;
        Tail = nullptr;
		size =0;
		cout << "LConstructor:\t" << this << endl;
	}

	// ForwardList(const initializer_list<int>& il):ForwardList()
	// {
	// 		cout<<"Type: "<< typeid(il.begin()).name()<< endl;
	// 		for (int const* it = il.begin(); it != il.end(); it++)
	// 		{
	// 			this->push_back(*it);
	// 		}
	//}
	// ForwardList(const ForwardList& other):ForwardList()
	// {
	// 	for(Element* Temp  = other.Head; Temp; Temp =Temp->pNext)
	// 		push_back(Temp->Data);

	// }

	~DoubleList()
	{
		while (Head) pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

    	//						Adding elements:
	void push_front(int Data)
	{
		if (size==0)
		{
			Element *New = new Element(Data);
			Head = New;
        	Tail = New;
		}
		else
		{ 
			Element *New = new Element(Data);
			New->pNext = Head;
			Head->pPriv = New;
			Head = New;

        	// Tail does not change

		}
		size++;
	}

	void push_back(int Data)
	{
		if (size==0)
		{
			Element *New = new Element(Data);
			Head = New;
        	Tail = New;
		}
		else
		{ 
			Element *New = new Element(Data);
			New->pPriv = Tail; 
			Tail->pNext = New;
			Tail = New;
        	// Head does not change

		}
		size++;
	}

	       //Removing elements
	void pop_front()
	{
		cout << " Element to front pop: " << Head->Data << endl;
		//remember address of element to delet
		
		Element* to_del = Head;
		Head = Head->pNext;
		if (size==1){Tail = nullptr;}
		else {Head->pPriv = nullptr;}
		delete to_del;
		size--;

	}
	void pop_back()
	{
		cout << " Element to pop back: " << Tail->Data << endl;
		//remember address of element to delet
		
		Element* to_del = Tail;
		Tail = Tail->pPriv;
		Tail->pNext = nullptr;
		delete to_del;
		size--;
	}

		//					Methods:
	void print() const
	{
		Element *Temp = Head;
		for(Element* Temp=Head; Temp!=nullptr; Temp=Temp->pNext)
		{ cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext<< 
		 ' ' << Temp->pPriv << endl;}
		cout<<" Number of element in the list: " << size<<endl;
		cout<<" Number of all element: " << Element::count<<endl;
	}
};

int main()
{
 //Element e (4);
 DoubleList list;
//push_front
int n;

cout<<" Enter numeber of elements in the DoubleList: ";cin>>n;
cout << endl;
for (int i = 0; i < n; i++)
{
	//list.push_front(rand() % 100);
	list.push_back(rand() % 100);
}
list.print();
list.pop_front();
list.print();

 return 0;
}