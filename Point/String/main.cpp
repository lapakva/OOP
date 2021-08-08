#include "String.h"

void main()
{
#ifdef constructors_check
	cout << "This is a String class playground" << sizeof(char) << endl;
	String A(5); //  implicit conversion from int to string
	A.print();
	String str1 = "Hello";
	str1 = str1;
	str1.print();

	String str2 = str1; //CopyConstructor
	str2.print();
	
	String str3;
	str3 = str2;
	str3.print();
#endif //constructors_check
	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	/*String str3 = str1 +" "+ str2;
	cout << str3 << endl;*/
	str1 += str2;
	cout << str1 << endl;;

	


	
}