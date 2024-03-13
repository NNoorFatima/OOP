//Noor Fatima, 22i-1036, J , Assignment # 2
#include "String.h" // header in local directory
#include <iostream> 
using namespace std;
//========================================================================
String :: String()		//default  constructor 
{	//*data='\0';
	data= new char[1];
	data[0]='\0';
	len=length();	}
//========================================================================
String :: String (char* str)	//parameterized constructor 
{	
	int l=0;
	while (str[l] != '\0')
		l++;
	len=l;
	data=new char[l+1];
	//data=str;
	for (int i=0 ; i<len ; i++)
	{
		data[i]=str[i];
	}
	data[len]='\0';
}
//========================================================================
String :: String (const String &str)	//parameterized constructor 
{
	int l=0;
	int m=0;
	while (str.data[l] != '\0')
		l++;
	len=l;
	data= new char[len+1];
	while (str.data[m] != '\0')
	{
		data[m]= str.data[m];
		m++;
	}
}
//========================================================================
String :: String (int x)	//parameterized constructor 
{
	len=x;
	data= new char[x+1];
	//*data='\0';
	for (int i=0 ; i<len ; i++)
	{
		data[i]='\0';	}
	data[len]='\0';		
}
//========================================================================
char String :: getChar(int i)
{	
	if (i>len-1 || i< 0)
		return '\0'; 	//returning null in case if it wants an invalid index
	return data[i];
}
//========================================================================
bool String :: isEmpty()
{
	if (*data == '\0') //checks if data is empty therefore it will be equal to null
		return 1;
	return 0;
}
//========================================================================
int String :: length()
{
	int k=0;
	while(data[k] != '\0')
		k++;		//finds the lenfth of data 
	return k;
}
//========================================================================
char* String :: getdata()	//getter function 
{
	return data;
}
//========================================================================1st
bool String :: isEqual (const String& str2)const
{
	//int l=str2.len;
	/*//finding length of string 2
	while (str2.data[l] != '\0')
		l++;
	str2.len=l; //assigning l to the object (str2) len*/
	bool check=0;
	if (len==str2.len)	//checkcing if both lengths are equal 
	{
		for (int i =0 ; i<len ;i++)
		{
			if (str2.data[i] == data[i])	//comparing value at eacch index 
				check=1;
			if (check==0)
				return 0;
		} 
	}
	if (check==1)
		return 1;
}
//========================================================================3rd
bool String :: isEqual(char* str2)const
{
	bool check=0;
	int l=0;
	//comparing length of both strings if they are not same function return 0
	while (str2[l] != '\0')
		l++;
	if(l != len)		//if the length is not same means the c-string doesnt have the same value 
		return 0;
	//incase length is same 
	for (int i=0 ; i<len; i++)		//otherwise in a loop compares all values at each index 
	{
		if(data[i]==str2[i])
			check=1;	//if the values are smake check = 1 else check =0 and then 0 is retuned frm the fntion indicating that hey are not equal 
		if (check==0)
			return 0;
	}
	if(check==1)
		return 1;
}
//========================================================================2nd
bool String :: isEqual(const string& m)const
{
	int l=0;
	bool check=0;
	while (m[l] != '\0')		//finds lenfgth of the parameter 
		l++;
	if (l != len)
		return 0;
	for (int i=0 ;i<len ; i++)
	{
		if(data[i] == m[i])	//in a loop checks if the data at eachindex is equal 
			check =1;
		else 			//if at any point the values is not same assgns 0 to check and returns 0 
			check=0;
		if (check==0)
			return 0;	//if values are not same return 0 indicating that the data its not equal 
	}
	if (check==1)
		return 1;
}

//======================================================================== 1st
int String :: index_at(char st)const
{
	int l=0;
	while (data[l] != '\0')		//works till null character not found 
	{
		if (data[l] == st)	//if the characted is found then breaks and returns l (which is the index of character st)
			break;
		l++;
	}
	if (l<len)
		return l;		
	else
		return -1;	//in case null character reachers and character st not found thenreturn -1
		
}
//========================================================================2nd
int String :: index_at(const String& str1)const
{
	int l=0,k=0;
	int start=-1;
	bool check =1;
	//finding length of str1
	int len_s=0;
	while (str1.data[len_s] != '\0')		//finds the length
		len_s++;
	while (k<len)
	{
		start=k;
		check=0;
		if (data[k]== str1.data[l])		//if the value of data and thr str.data is same
		{
			for (int i=0 ; i<len_s ;i++)	//then in a loop checcks if the other values are also same 
			{
				if(data[k]== str1.data[l])
				{
					k++;l++;
					check=1;
				}
				else		//if theu are not same at any point then sets check to 0 and breaks the loop 
				{
					check=0;
					k=start;
					l=0;break;
				}
			}
		}
		if (check==1)		//if check is 1 then return the start else return -1
			return start;
		k++;
	}
	if (check==0)
		return -1;


}
//========================================================================3rd
int String :: index_at(const string& m)const
{
	int len_m=0,k=0;
	bool check=0;
	int start=0;
	while (m[len_m] != '\0')//finds the length
		len_m++;
	while (k<len_m)
	{
		if (data[k]==m[0])		//if the value of data and thr str.data is same
		{
			start=k;
			for (int i=0 ; i<len_m ; i++)//then in a loop checcks if the other values are also same 
			{
				if (data[k]==m[i])
				{
					check=1;
					k++;
				}
				else		//if theu are not same at any point then sets check to 0 and breaks the loop
				{
					check=0;
					k=k-i;		//updates k  and breaks the loop 
					break;
				}
			}
		
		}
		if (check==1)		//if check is 1 then return the start else return -1
			return start;	
		k++;
	}
	return -1;


}
//========================================================================4th
int String :: index_at(char *s)const
{
	//finding the length of the c-string 
	int len_s=0,start=0;
	bool check=0;
	while (s[len_s] != '\0')//finds the length
		len_s++;
	int k=0,l=0;	
	while (k<len)
	{
		if (data[k] == s[l])		//if the value of data and thr str.data is same
		{
			start=k;
			for (int i =0; i<len_s ; i++)//then in a loop checcks if the other values are also same
			{
				if (data[k] == s[l])
				{	k++;l++;	
					check=1;	}
				else		//if theu are not same at any point then sets check to 0 and breaks the loop
				{
					check=0;
					k=k-i;
					l=0;break;	}
				
			}
		}
		if (check ==1)
			return start;	//if check is 1 then return the start else return -1
		k++;
	}
		return -1;

}
//========================================================================
//------------------------------------------------2nd
String String :: append_string(const char &str)
{
    
    int l=0;
    while (data[l] != '\0')		//finds length
        l++;
    int k=0; 
    char* s1=new char[l+2];		//dynamically allocates array 
    while (data[k] != '\0')
    {
        s1[k] = data[k];	//copies all values of data to pointer s
        k++;
    }
    s1[k]=str;	//assigns the character
    s1[k+1]='\0';	//assigns null
    delete [] data;
    len=k+1;	//changes len 
    data= s1;
    
    return *this;
        

}
//========================================================================3
String String :: append_string(char *&str)
{
    int i=0,m=0;
    while (str[i] != '\0')//finding the length of string 
        i++;
    int k=0;
    //creating a pointer
    int length= i+len+1;
    char *s= new char[length];
    while (data[k] != '\0')	//copies data to s till data is not null 
    {    
        s[k]=data[k];
        k++; }
    m=0;
    while (k<(length-1))		//after data is copies now it copies the str in parameter in a loop 
    {
        s[k]=str[m];
        m++;
        k++;
    }
    s[length-1]='\0';	//assignns null 
    delete [] data;
    len=length;	//changes lenfth 
    data=s;	//assigns s to data 
    return *this;

}
//=======================================================================4th
String String :: append_string(string& str)
{
	int k=0,l=0,i=0,g=0;
	while (str[i] != '\0')	//finding the length of string 
		i++;
	while (data[g] != '\0')
		g++;
	int length= i+g+1;
	char *s=new char [length];
	while (data[k] != '\0')	//copies data to s till data is not null 
	{
		s[k]=data[k];
		k++;
	}
	int m=0;
	while (k<(length -1))	//after data is copies now it copies the str in parameter in a loop 
	{
		s[k]=str[m];
		m++;k++;
	}
	s[length-1]='\0';//assignns null 
	delete [] data;
	len=length;	//updates len
	data=s;//assigns s to data 
	return *this;

}
//========================================================================1st
String String :: append_string(const String &str)
{
    int k=0;
    int i=0;
    int length=str.len + len+ 1 ;
    char *s= new char[length];    //dynamically allocates array 
    while (data[i] != '\0')//copies data to s till data is not null 
    {    
        s[k]=data[i];
        k++;
        i++;
    }
    
    int m=0;
    while (k<length)//after data is copies now it copies the str in parameter in a loop 
    {
        s[k]=str.data[m];
        m++;
        k++;
    }
    
    s[length -1]='\0';//assignns null 
    delete [] data;
    len=length;	//upadtes len
    data= s;//assigns s to data 
    return *this;
    
}
//========================================================================
//-------------------------------------------------------3rd
String& String :: assign_string(const string& m)
{
	/*if (m != NULL)
		delete [] data;*/
	int l=0;
	while (m[l] != '\0')	//finds lengthof m 
		l++;
	data=new char [l+1];	//creates dynamically allocated array of size of m +1 for null character 
	len =l;
	int s=0;
	while (m[s] != '\0')		//itereates while m is not equal to null character 
	{
		data[s]=m[s];	//copies data 
		s++;
	}
	return *this;
} 

//========================================================================
//-------------------------------------------------------2nd
String& String :: assign_string(char *s)
{
	if (s != NULL)
		delete [] data;
	int l=0;
	while (s[l] != '\0')		//finds lengthof m 
		l++;
	len= l;
	data= new char[l+1];	//creates dynamically allocated array of size of m +1 for null character
	int m=0;
	while (s[m] != '\0')	//itereates while m is not equal to null character
	{
		data[m]=s[m];//copies data 
		m++;
	}
	return *this;

}
//========================================================================
//--------------------------------------------------------1st
String& String :: assign_string(const String& str)
{
	//checks if str is null or not 
	
	int l=0;
	
	data= new char [str.len+1];	//creates dynamically allocated array of size of obejcts (str) lenght +1 for null character
	data=str.data;	//copies data 
	len=str.len;		//updtes length 
	
	return *this;
}
//========================================================================
//===========================================================1st
String String :: remove_string(const String &substr)
{
    bool check=0;
    int m=0,c=0,f=0;
    if (data == NULL)
        return *this;
    int l=0 ;
    int start=0;
    while (substr.data[l] != '\0')
        l++;
         int n=len-l+1;
            char *new_data= new char [n];  //dynamically allocates array
    while (data[m] != '\0')
    {
        if (data[m] == substr.data[c])		//checks if data at mth index is equal to substsr 
        {
            start=m;
            check=0;        //staring of the string whihc must be removed
            for (int i=0 ; i<l ; i++)		//checks if the string is equal at all values 
            {
                if (data[m] == substr.data [i])		
                {
                    check=1;
                    m++;
                }
                else
                {
                    check=0;	//if at any point value is not equal it sets check to 0 
                    m -=start;	//updates the values of start and breaks the loop 
                    break;
                }
            }
            if (check ==1)//if true in a loop copy elements till start 
            {
                for (f=0 ; f<start ; f++)	
                {
                    new_data[f]=data[f];
                }
                int h=f;
                f +=l;
                while (data[f] != '\0')
                {  new_data[h]=data[f];f++;h++;}
                new_data[h]='\0';//assignns null 
                break;
            }
        }
        m++;
    }
    delete [] data;
    len -=l;		//updates len
    data=new_data;	//updates data
    return *this;	
}
//========================================================================4th
String String :: remove_string(const char &substr)
{

    //removing a single alphabet from the data 
    char *new_string= new char[len];		//dynamically allocates array
    int m=0,i,n=0,start=0;
    bool check=0;
    while (data[m] != '\0')
    {
        if (data[m] == substr)
        {    check=1;
            start= m;
            for (i=0 ; i<start ; i++)
            {
                new_string[i]=data[i];	//copies data 
            }
            n=i+1;		//n is added by i which is the index till whchi data is copied and 1 which is the elngth of subtstr
            while (data [n] != '\0')
            {
                new_string[i]= data[n];	//copies data 
                n++;
                i++;
            }
            new_string[i]='\0';//assignns null 
        
        }
        m++;
    }
    if (check ==1)
    {
        delete [] data;
        len -=1;		//updates len
        data= new_string;	//updates data
    }
    return *this;
    

}
//==============================================================3rd
String String :: remove_string( char *&substr)
{

    //removing a single alphabet from the data 
    int m=0,i,n=0,start=0,k=0;
    bool check=0;
    while (substr[k] != '\0')
      k++;
      char *new_string= new char[len-k+1];	//dynamiically allocates array 
    while (data[m] != '\0')
    {
        if (data[m] == *substr)
        {    check=1;
            start= m;	//assignsn m to start 
            for (i=0 ; i<start ; i++)		//in a loop assigns data to new string 
            {
                new_string[i]=data[i];
            }
            n=i+k;		//n is added by i which is the index till whchi data is copied and k which is the elngth of subtstr 
            while (data [n] != '\0')
            {
                new_string[i]= data[n];//copies data 
                n++;
                i++;	//increments
            }
            new_string[i]='\0';//assignns null 
          if (check == 1)
            break;
        }
        m++;
    }
    if (check ==1)
    {
        delete [] data;
        len -=k;	//updates len
        data= new_string;	//updates data
    }
    return *this;
}
//================================================================2nd
String String :: remove_string( string &substr)
{
	int m=0,i,n=0,start=0,k=0;
	bool check=0;
	while (substr[k] != '\0')
		k++;
	char *new_string= new char[len-k+1];		//dynamiically allocates array 
	while (data[m] != '\0')
	{
		if(data[m] == substr [0])	//checks if data at indecx m equal substr at 0th index 
		{
			start=m;	//assignsn m to start 
			check=1;
			for (i=0 ; i<start ; i++)	//in a loop assigns data to new string 
			{
				new_string[i]=data[i];
			}
			n=i+k;	//n is added by i which is the index till whchi data is copied and k which is the elngth of subtstr 
			while (data [n] != '\0')	
			{
				new_string[i]= data[n];		//copies data 
				n++;
				i++;
			}
			new_string[i]='\0'; //assigns null 
		if (check == 1)
            	break;
       		}
        m++;
    	}
	if (check ==1)
	{
		delete [] data;	
		len -=k;	//updates len
		data= new_string;	//upates data 
	}
    return *this;
}



