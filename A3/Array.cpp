#include "Array.h"
#include <iostream>
using namespace std;
//Noor Fatima, 22i-1306, Assignment #3
//===============================================================
Array :: Array()
{
	size_a =0;
	arr_a=new int [size_a];
	
	index=0;
}
//===============================================================
Array :: Array (int size)
{
	size_a=size;
	arr_a= new int [size_a];
	for (int i=0 ;i<size_a; i++)
		arr_a[i]=0;
	index=0;	
	
}
//===============================================================
Array ::Array(int *arr, int size)
{
	size_a=size;
	arr_a= new int [size_a];
	for (int i=0 ;i<size_a; i++)
		arr_a[i]=arr[i];
	index=0;	
}
//===============================================================
Array :: Array(const Array& m)
{
	size_a=m.size_a;
	arr_a= new int [size_a];
	for (int i=0 ; i<size_a ; i++)
		arr_a[i]= m.arr_a[i];
	index = m.index;

}
//===============================================================
int Array :: size()
{	return size_a;}
//===============================================================
int& Array :: operator[](int i)
{
	if (i <0 || i>(size_a-1))
		cout<<"Invalid"<<endl;
	else 
		return arr_a[i];
}
//===============================================================
int& Array :: operator[](int i)const
{
	if (i <0 || i>(size_a-1))
		cout<<"Invalid"<<endl;
	else 
		return arr_a[i];
}
//===============================================================
const Array & Array::operator=(const Array& m)
{
	size_a =m.size_a;
	arr_a=new int [size_a];
	for (int i=0 ;i<size_a; i++)
		arr_a[i]= m.arr_a[i];
	index=m.index;
	return *this;
}
//===============================================================
Array Array :: operator+(const Array& m)
{
    for (int i=0 ; i<m.size_a ; i++)
    {
      arr_a[i] =arr_a[i] + m.arr_a[i]; }
      return *this;
}
//===============================================================
Array Array :: operator-(const Array& m) 
{
	for (int i=0 ; i<m.size_a ; i++)
		arr_a[i] =arr_a[i] - m.arr_a[i];
	return *this;
}
//===============================================================
Array Array :: operator++()
{
	for (int i=0 ; i<size_a ; i++)
		++arr_a[i];
	return *this;
}
//===============================================================
Array Array :: operator++(int x)
{
	for (int i=0 ; i<size_a ; i++)
		arr_a[i]++;
	return *this;
}
//==============================================================
Array& Array :: operator--(int x)
{
	for (int i=0 ; i<size_a ; i++)
		--arr_a[i];
	return *this;
}
//==============================================================
bool Array :: operator==(const Array& x)const
{
	if (size_a==x.size_a)
	{
		for (int i =0 ; i<size_a ; i++)
		{
			if (arr_a[i]!=x.arr_a[i])
				return 0;
		}
		return 1;
	}
	return 0;
}
//==============================================================
bool Array :: operator!()
{
	for (int i=0 ; i< size_a; i++)
	{
		if (arr_a[i] != 0)
			return 0;
	}
	return 1;
}
//==============================================================
void Array :: operator+=(const Array& x)
{
	for (int i=0 ; i<x.size_a ; i++)
	{
	      arr_a[i] += x.arr_a[i]; }
  
}
//==============================================================
void Array :: operator-=(const Array& x)
{
	for (int i=0 ; i<x.size_a ; i++)
	{
	      arr_a[i] -= x.arr_a[i]; }
}
//==============================================================
int Array :: operator()(int idx, int val)
{
	//checck if the index is valid
	if(idx<0 || idx>(size_a-1))
		return -1;
	else
	{
		if(arr_a[idx] != val)		//value at index is not equal to the value in parameter 
			return -1;
		arr_a[idx]=0;
		
	}
	return 1;
}

//=============================================================
istream& operator>>(istream &input,Array& a)
{
	//input>>a.size_a;
	//delete[] a.arr_a;
	//a.arr_a= new int [a.size_a];
	for (int i=0 ;i<a.size_a ;i++)
	{
		input>>a.arr_a[i];
	}
	return input;

}
//==============================================================
Array :: ~Array()
{
	delete [] arr_a;
	
}
//==============================================================
ostream& operator<<(ostream &output,const Array& a)
{
	for (int i=0 ;i<a.size_a ; i++)
	{
		output<<a.arr_a[i]<<" ";
	}
	return output;
}
