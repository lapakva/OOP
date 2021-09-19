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

	DoubleList(const initializer_list<int>& il):DoubleList()
	{
			cout<<"Type: "<< typeid(il.begin()).name()<< endl;
			for (int const* it = il.begin(); it != il.end(); it++)
			{
				this->push_back(*it);
			}
	}
	DoubleList(const DoubleList& other):DoubleList()
	{
		for(Element* Temp  = other.Head; Temp; Temp =Temp->pNext)
			push_back(Temp->Data);

	}

	~DoubleList()
	{
		while (Head) pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

		//Operators:
	DoubleList& operator=(const DoubleList& other)
	{
		while (Head) pop_front();
		for(Element* Temp  = other.Head; Temp; Temp =Temp->pNext)
			push_back(Temp->Data);
		return *this;
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
		if (size==1){Head=nullptr;}
		else{ Tail->pNext = nullptr;}	
		delete to_del;
		size--;
	}
	void insert(int Data, int index)
	{
		Element *New = new Element(Data);
		
		int i = 0;
		if (index==0)return push_front(Data);
		if (index>=size) return push_back(Data);
		if (size/2>=index){
			Element *Temp = Tail;
			while (Temp->pNext)
				{ if (i == index - 1)						
						{New->pPriv = Temp->pPriv;
						Temp->pPriv = New;
						break;}
					i++;
					Temp = Temp->pPriv;
				}
		}
		else
		{
		Element *Temp = Head;
		while (Temp->pNext)
		{
			 if (i == index - 1)
			{
				New->pNext = Temp->pNext;
				Temp->pNext = New;
				break;
			}
			i++;
			Temp = Temp->pNext;
		}

		}

		size++;

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
 //DoubleList list;
//push_front
// int n;

// cout<<" Enter numeber of elements in the DoubleList: ";cin>>n;
// cout << endl;
// for (int i = 0; i < n; i++)
// {
// 	//list.push_front(rand() % 100);
// 	list.push_back(rand() % 100);
// }
DoubleList list = {3,5,8,13,21};
// list.print();
// list.print();
// list.pop_front();
// list.print();
// list.pop_back();
// list.pop_back();
// list.pop_back();
// list.pop_back();

// DoubleList list2 = list;
// list2.print();

// DoubleList list3;
// list3 = list2;
list.insert(123,2);
list.print();
 return 0;
}