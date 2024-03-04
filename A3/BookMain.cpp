#include <iostream>
using namespace std;
#include "Book.cpp"
//Noor Fatima, 22i-1306, Assignment #3
int main()
{
	Line l("Adding a new line to an exisiting page.");
	Line l2("This is line 2");
	cout<<l;
	cout<<'\n'<<l2;
	char* a="ASSDSFDSF";
	Line l4(l);
	cout<<endl;
	cout<<l4<<endl;
	Line l3;
	l3=a;
	cout<<endl<<l3<<endl;
	//==
	if(l==l4)
		cout<<"l==l4"<<endl;
	else
		cout<<"l!=l4"<<endl;

	

}
