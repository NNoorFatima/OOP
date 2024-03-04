#include <iostream>
using namespace std;
class Array 
{
	int size_a;
	int index;
	int *arr_a;
	public:
	Array();
	Array(int size);
	Array  (int *arr, int size);
	Array(const Array&);
	int& operator[](int i);
	int& operator[](int i)const;
	int size();	
	const Array & operator=(const Array& );
	Array operator+(const Array&);
	Array operator-(const Array&);
	Array operator++();
	Array operator++(int x);
	Array& operator--(int x);
	bool operator==(const Array& x)const;
	bool operator!();
	void operator+=(const Array& x);
	void operator-=(const Array& x);
	int operator()(int idx, int val);
	friend ostream& operator<<(ostream &output, const Array& a);
	friend istream& operator>>(istream& input,Array& a);
	~Array();
};

