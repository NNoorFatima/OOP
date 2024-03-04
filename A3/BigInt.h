#include <iostream>
using namespace std; 
#include <string>
class BigInt
{
	char *num;
	int size;
	public:
	BigInt(int val);
	BigInt(const string& text);
	BigInt(const BigInt& copy);
	operator string()  ;
	operator int();
	BigInt operator+(const BigInt& val)const;	//
	BigInt operator+(int val)const;
	BigInt operator-(const BigInt& val)const;	//
	BigInt operator-(int val)const;	//
	BigInt operator*(const BigInt& val)const;
	BigInt operator*=(const BigInt& val);
	BigInt operator+=(const BigInt& rh);
	bool operator==(const BigInt& val)const;
	bool operator==(const char* val)const;
	bool operator!=(const BigInt& val)const;
	bool operator<(const BigInt& val)const;
	bool operator<=(const BigInt& val)const;
	bool operator>(const BigInt& val)const;
	bool operator>=(const BigInt& val)const;
	BigInt operator++(int x);
	BigInt operator--(int x);
	BigInt& operator--();
	BigInt& operator++();
	//~BigInt();
	friend ostream& operator<<(ostream& output,const BigInt& val);
	friend istream& operator>>(istream& input,BigInt& val);
};
