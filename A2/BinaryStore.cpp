//Noor Fatima, 22i1036, J , Assignment #2
#include <iostream>
using namespace std;
#include "BinaryStore.h"
//===================================================
BinaryStore :: BinaryStore(int len)//parameterized constructor 
{
	address=new char*[len];
	bytes=new char *[len];
	for (int i=0 ; i<len ; i++)
	{
	  address[i]=NULL;
	  bytes[i]=NULL;
	}
	index=0;
}
//==================================================
BinaryStore :: ~BinaryStore(){			//destructor 
	for (int i=0 ; i< index ; i++)
	{
		delete[] address[i];
		delete[] bytes[i];
	}
	delete [] address;
	delete [] bytes;
}
//===================================================
char * BinaryStore :: Get(char *address)
{
  //first find the addresssss
  int find_index=0;
  bool found =0;
    while (find_index != index)		//loop works till the the last index is reached 
    {
        found=0;
        for (int i =0 ; i<4 ; i++)	//in a loop find the address
        {
            if (this->address[find_index][i]==address[i]) 
            found=1; 
            else		//if at any point the address[i] doesnt match then found is set to 0 and loop breaks 
            {    found=0; 
                break;}
        }
        if (found ==1)	//if found id 1 that means address is found than loop breaks else increments find_index
        break;
    find_index++;
    }
    char *p=new char [9];
	if (found==1)		//checks if the address was found 
	{
		if (bytes[find_index]==NULL)			//if found and than there are no bytes or its set to null than a nullptr is returned
			p=nullptr;
	else{							//otherwise copies values in bytes to p pointer and returns this
		for (int a=0 ; a<8 ;a++){
		p[a]=bytes[find_index][a];}
	p[8]='\0';}
	}
    return p;
    
}
//===================================================
void BinaryStore :: set_Byte(char *address,char *value)
{
  //first find the addresssss
  int find_index=0,k=0;
  bool found =0;
  while (find_index != index)		//in a loop we try to fidn the address 
  {
    found=0;
    for (int i =0 ; i<4 ; i++)
    {
      if (this->address[find_index][i]==address[i]) 
        found=1; 		
      else				//if at any point the address[i] doesnt match then found is set to 0 and loop breaks 
      {  found=0; break;}
    }
    if (found ==1)			//if found id 1 that means address is found than loop breaks else increments find_index
      break;
    find_index++;
  }
  //if address is found then set the byte
  if (found==1)
  {
    bytes[find_index]= new char[9];
    for (int l=0; l<8 ; l++)
    {
      bytes[find_index][l]=value[l] ;		//copies data fromm value parameter to bytes 
    }
    bytes[find_index][8]='\0';			//setting null
  }
  else if (found==0)		//if address is not found 
  {
  	this->address[find_index]=new char [5];	
  	bytes[find_index]=new char [9];
  	index=find_index;
  	while (k<4)			//in a loop we add the address and then the bytes at the same index
  	{
  		this->address[index][k]=address[k];
  		k++;
  	}
  	this->address[index][4]='\0';k=0;
  	while (k<8)
  	{
  		bytes[index][k]=value[k];
  		k++;
  	}
  	bytes[index][8]='\0';
  	index++;
  }
  
}
//===================================================
void BinaryStore :: add_Address(char *s)
{
  address[index]=new char [5];		//creates dynamic memory for the address
  for (int i=0 ; i<4 ; i++)			//in a loop assigns the value 
    address[index][i]=s[i];		
    address[index][4]='\0';		//sets null
    index++;
}
//===================================================
bool BinaryStore :: comp_EQUAL(char *a, char*b)
{
	int i=0;
	bool found=0;
	while (a[i] != '\0')	//loops till null is reached
	{
		if (a[i]==b[i])		//is both values of a and b at eacch index is same then found is true else found will be set to 0 and loop will break 
			found=true;
		else
		{
			found =0;
			break;
		}
		i++;
	}
	return found;
}
//===================================================
char* BinaryStore :: comp_AND(char *a,char *b)
{
	int i=0;
	char *p= new char [9];		//allocates dynamic memory for bytes
	while (a[i] != '\0')
	{
		p[i]=(int)a[i] & (int) b[i];		//uses bitwise & and stores the answer in p 
		i++;
	
	}
	p[8]='\0';	//sets null
	return p;	//return p
}
//===================================================
char* BinaryStore :: comp_OR(char *a, char *b)	
{
	int i=0; 
	char *l= new char[9];	//allocates dynamic memory for bytes 
	while(a[i] != '\0' && b[i] != '\0')		//works while null character is not reached 
	{
		if (a[i]=='1' || b[i]=='1')		//if any of the two b or a is 1 than answer is 1 else answer is 0
			l[i]='1';
		else
			l[i]='0';
	i++;
	}
	l[8]='\0';		//sets null
	return l;	//retunrs pointer

}
//==================================================
char* BinaryStore :: comp_NOT(char*a)
{
    int i=0;
    char *p=new char[9];
    while (a[i]!='\0')		//performs  loop while nul is  not reached 
    {
        if (a[i]=='0')		//if input is 0 then inverts and assigns p  to 1
            p[i]='1';
        else if(a[i]=='1')	//if input is 1 then inverts and assigns p  to 0
            p[i]='0';
        i++;
    }
    p[8]='\0';
    return p;
}
//==================================================
char* BinaryStore :: Add(char *a, char *b)
{
    int i=7;
    int carry=0;
    char *m=new char[9];
    for (int i=0 ; i< 8; i++)
    	m[i]='\0';
    while(a[i] != '\0' && b[i] != '\0')	//works while null is not reached 
    {
        if (a[i]=='1' && b[i]=='1')		//is both inouts are 1 then carry introduced and according value is set to m pointer 
        {	
            if (carry==1){
                m[i]='1';		//simpily uses laws of binary addition
                carry=1;}
            else{
                m[i]='0';
                carry=1;}
            
        }
        else if(a[i]=='1' && b[i]=='0')		//if one input is 1 and other is 1 then carry checked and according value is set to m pointer 
        {
            if (carry==1){
                m[i]='0';
                carry=1;}
            else
            {    m[i]='1';
              carry=0;}
            
        }
        else if(a[i]=='0' && b[i]=='1')		////if one input is 1 and other is 1 then carry checked and according value is set to m pointer 
        {
            if (carry==1){
                m[i]='0';
                carry=1;}
            else
            {    m[i]='1';
                carry=0;}
            
        }
        else if(a[i]=='0' && b[i]=='0')		//if both inputs are 0 then carry checked and according value is set to m pointer 
        {
            if (carry==1){
                m[i]='1';
                carry=0;}
            else
            {    m[i]='0';
              carry=0;}
            
        }
        i--;
  }
  m[8]='\0';		//setting null
   
    return m;
}
