#include <iostream>
using namespace std;
//#define ELEVATOR

void elevator(int level)
{
    if(level == 0) return;
    cout<< level << endl;
    elevator(level -1);
    cout<< level << endl;
}
#define FACTORIAL
#define POWER 
int factorial(int n)
{
    // if (n==0) return 1;
    // return n*factorial(n-1); 
    return n==0?1:n*factorial(n-1);
}

double power(double base, int n)
{
    //if(n==0) return 1;
    // if (n>0) return base*power(base,n-1);
    // else return 1/base*power(base,n+1);
    return n==0? 1 2: n> 0?base*power(base,n-1):1/base*power(base,n+1);
}

int main()
{
#ifdef ELEVATOR
    cout<<"Hello World"<< endl;
    int n;
    cout<< " enter level: ";
    cin >> n;
    elevator(n);
#endif //ELEVATOR
// int n;
// cout<<"Enter namber to get the fuctorial"<<endl;
// cin>>n;
// cout<< factorial(n)<< endl;
double a;
int N;
cout<<"Введите основание степени: " ; cin>>a;
cout<<"Введите показатель степени: " ; cin>> N;
cout<< power(a,N)<< endl;
main();
    return 0;
    
}