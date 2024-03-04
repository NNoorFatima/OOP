#include "Line.h"
//Noor Fatima, 22i-1306, Assignment #3
//===========================================================
Line :: Line()
{
	text=new char [40];
	size=0;
	lines=0;
}
//===========================================================
Line :: Line (const string m)
{	
	int i=0;
	if(text == NULL)
		text=new char [40];
	while(m[i]!='\0')
		i++;
	//size+=i;
	for (int k=0 ;k<i ;k++, size++)
		text[size]=m[k];
	text[size]='\0';
	
	
}
//===========================================================
Line :: Line( char *t)
{
	int i=0;
	if(text == NULL)
		text=new char [40];
	while (t[i] != '\0')
		i++;
	for (int k=0 ;k<i ; size++,k++)
		text[size]=t[k];
	text[size]='\0';

}
//===========================================================
Line :: Line (Line& a)
{
	size =a.size;
	lines=a.lines;
	delete [] text;
	text= new char[40];//max num of line in to max num of characters per line 
	for( int i=0 ; i<size ; i++)
		text[i]=a.text[i];

}
//===========================================================
Line& Line :: operator=(const char* t)
{
	int i=0;
	for ( i=0 ; i<40 ;i++)
	{
		text[i]=t[i];
	}
	text[40]='\0';
	size=i;
	return *this;
}
//===========================================================
bool Line :: operator==(const Line& a) const
{
	bool check=0;
	for (int i=0 ; i<40 ; i++)
	{
		if(text[i]==a.text[i])
			check=1;
		else
		{
			check=0;
			break;
		}
		
	}
	if(check==1)
		return 1;
	return 0;
}
//===========================================================
ostream& operator<<(ostream& out, const Line& l)
{
	out<<l.text;
	return out;
}
//===========================================================
Line ::~Line()
{
	delete [] text;
	text=NULL;
}
