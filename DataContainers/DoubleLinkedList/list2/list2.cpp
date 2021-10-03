#include<iostream>
using namespace std;
#define DEBUG
#define inerators_check
template<typename T>
class List
{
    class Element
    { 
        T Data;
        Element* pNext;
        Element* pPrev;
    public:
        Element(T Data, Element *pNext = nullptr, Element *pPrev = nullptr)
            : Data(Data), pNext(pNext), pPrev(pPrev)
            {
                cout << "EConstructor:\t" << this << endl;
            }

        ~Element()
        {
            
            cout << "EDestructor:\t" << this << endl;
        }

    friend class List;
    }*Head,*Tail;
size_t size;
size_t get_size()const
{
    return this-> size;
}
public:
    class Iterator
    {
        Element* Temp;
    public:
    Iterator(Element* Temp = nullptr): Temp(Temp)
    {
        cout<< "ItConstructor:\t" << this << endl;
    }
    ~Iterator()
    {
        cout<< "ItDestructor:\t" << this << endl;
    }
    Iterator& operator++()
    {
        Temp = Temp->pNext;
        return*this;
    }
    Iterator operator++(int)
    {
        Iterator old = *this;
        Temp =Temp->pNext;
        return old;
    }
    bool operator!=(const Iterator& other)const
    {
            return this-> Temp != other.Temp;
    }

    bool operator==(const Iterator& other)const
    {
            return this-> Temp == other.Temp;
    }

    int& operator*()
    {
        return this-> Temp-> Data;
    }
    

    };

    Iterator begin()
    {
        return Head;
    }
    Iterator end()
    {return nullptr;}
List()
{
    Head=Tail=nullptr;
    size =0;
    cout << "LConstructor:\t"<< this << endl;

}
List (const initializer_list<T>& il):List()
{
    for (T const* it = il.begin(); it!= il.end();it++)
    push_back(*it);
}
List(const List<T>& other): List()
{
    for (Element* Temp = other.Head; Temp; Temp=Temp->pNext)
    push_back(Temp->Data);
}
~List()
{
    while (Head) pop_back();
    cout<<"LDestructor:\t" << this << endl;
}
	List<T>& operator=(const List<T>& other)
	{
		if (this==&other)return *this;
        while (Head) pop_front();
		for (Element* Temp = other.Head; Temp; Temp=Temp->pNext)
		return *this;
	}

    // Adding elements
    void push_front(T Data)
    {
        if (Head == nullptr && Tail == nullptr)
        {Head =Tail =new Element(Data);}
        else 
        {
        //     Element* New = new Element(Data);
        //     New->pNext = Head;
		// 	Head->pPrev = New;
		// 	Head = New;

            Head = Head->pPrev = new Element(Data, Head);

        }        
        size ++;

    }
        void push_back(T Data)
    {
        if (!Head && !Tail) return push_front(Data);
        // Element* New = new Element(Data);
        // New->pPrev = Tail;
        // Tail->pNext = New;
        // Tail = New;
        Tail = Tail->pNext = new Element(Data, nullptr, Tail);
        size ++;
        
               

    }
    //Removing elements
    void pop_front()
    {
        //check if the element is the last in the list
        if(Head==Tail)
        {
            delete Head;
            Head = Tail = nullptr;
            return;
        }
        // exclude element from the list
        Head = Head->pNext;
        //delet element from the memory
        delete Head->pPrev;
        //foget deleted element
        Head->pPrev = nullptr;
        size--;
    }
    
    void pop_back()
    {
        //check if the element is the last in the list
        if(Head==Tail){pop_front(); return;}

        // exclude element from the list
        Tail = Tail->pPrev;
        //delet element from the memory
        delete Tail->pNext;
        //foget deleted element
        Tail->pNext = nullptr;
        size--;
    }
    

    // Methods
    void print()const
    {
        for(Element* Temp =Head;Temp;Temp=Temp->pNext)
        {
            cout<< Temp->pPrev <<"\t"<< Temp<<"\t"
            <<Temp->Data<<"\t"<<Temp->pNext<< endl;
        }
        cout<<"Number of elements: "<< this->size << endl;
    
    }
    void revers_print()const
    {
        for(Element* Temp =Tail;Temp;Temp=Temp->pPrev)
        {
            cout<< Temp->pPrev <<"\t"<< Temp<<"\t"
            <<Temp->Data<<"\t"<<Temp->pNext<< endl;
        }
        cout<<"Number of elements: "<< this->size << endl;
    }

};

int main()
{
//     int n;

// cout<<" Enter number of elements in the DoubleList: ";cin>>n;
// cout << endl;
// List list;
// for (int i = 0; i < n; i++)
// {
// 	// list.push_front(rand() % 100);
// 	list.push_back(rand() % 100);
// }
#ifdef inerators_check
List<int> list ={3,5,8,13, 21};
    list.print();
    list.revers_print();
    List<int> list2 =list;
    list = list;
    List<int> list3;
    list3 = list;
    for(List<int>::Iterator it = list2.begin(); it !=list2.end(); it++)
    {
        cout<<*it<<"\t";
    }
#endif //inerators_check
 int arr[] ={3,5,8,13,21};
 for(int x:arr) cout<<x<<"\t" ;
 cout<< endl;

    return 0;
}