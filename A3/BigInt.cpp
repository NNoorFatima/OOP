#include "BigInt.h"
//Noor Fatima, 22i-1306, Assignment #3
//=======================================================================
BigInt :: BigInt(int val=0)		//constructor
{
	int temp=0,i=0,m=0,t;
	char mod;
	char *a;
  if (val ==0)
    {
        num= new char [2];
        num[0]='0';
        num[1]='\0';
    }
    else
    {
        temp=val;
        //finding length of the number 
        while(temp != 0)
        {
            temp /=10;
            i++;
        }
        num= new char [i+1];
        a= new char[i];
        while (val != 0)
        {
            t= val;
            val /=10;
            mod= t - (val*10);
            a[m]=mod + '0';
            m++;
        }
        for (int k=0 ; k<i ; k++)
          num[k]=a[i-k-1];
      num[i]='\0';
      size= i;
    }
}
//======================================================================
BigInt :: BigInt(const string& text)		//constructor
{
	int i=0;
	while (text[i] != '\0')
		i++;
	size=i;
	num= new char[size+1];
	for (int d=0 ;d<size ; d++)
		num[d]=text[d];
	num [size]='\0';
}

//========================================================================
BigInt :: BigInt(const BigInt& copy)		//constructor
{
	size = copy.size;
	num = new char[size+1];
	for (int i = 0; i < size; i++) {
	        num[i] = copy.num[i];
    }
    num[size]='\0';
}
//=======================================================================
BigInt :: operator string() 		//convert to string
{
        string str;
        int m=0;
        while (num[m] != '\0')
        	m++;
        for (int i=0 ; i<m ; i++)
        	str+=  num[i];
	//cout<<num<<"SFSF"<<endl;
        return str;
}
//========================================================================
BigInt :: operator int()
{
	int i=0;	
	while (num[i] != '\0')		//counting the number of integers and returning it
		i++;			//for eg 221 this will return 3 as 3 digits 
		
	return i;
}
//=======================================================================
BigInt BigInt :: operator+(const BigInt& val) const			//add
{
    char *p;
    int store,c,d;
    int a,sum=0,carry=0;
    if(size > val.size)    
        a=size;
    else 
        a=val.size;  
    p= new char[a+1];
    for (int i=0 ; i< a ; i++)
    {
        if (i>=val.size || i>=size)
        {   
		if (i>=size)
		    store= val.num[val.size-i-1] -'0';   
		else if (i>=val.size)
		    store= num[size-i-1] -'0';
        }
        else 
        {  
            c= num[size-i-1] -'0';
            d= val.num[val.size-i-1]-'0';
            store= c+d;}
        if (carry==0)
        {
            carry=0;
            if (store > 9)
            {
                sum = store % 10;
                carry= store /10;
                p[a-i-1]=sum + '0';
            }
            else 
                p[a-i-1]=store + '0';
        }
        else if (carry != 0)
        {
            store+= carry;
            carry=0;
            if (store > 9)
            {
                sum = store % 10;
                carry= store /10;
                p[a-i-1]=sum + '0';              
            }
            else 
                p[a-i-1]=store + '0';
        }
    }
    p[a]='\0';
    char *g;
    if (carry != 0)
    {
        g= new char [a+2];
        g[0]=carry + '0';
        int k=0;
        for (int i=1; k<a ; i++, k++)
            g[i]= p[k];
        g[a+1]='\0';
        BigInt m(g);
        return m;
    }
    BigInt m(p); 
    return m;
}
//=======================================================================
BigInt BigInt :: operator+(int val) const			//add
{
	int a,carry=0,sum=0;
	char *tab;
	tab= new char [size];
	for (int i=0 ; i<size ; i++)
	{  
		if ('0' <= num[size-i-1] && num[size-i-1] <= '9')
			a = num[size-i-1] - '0';
		if (i==0)
			a += val;
		if (carry==0)
		{
			carry=0;
			if (a>9)
			{
				sum=a % 10;
				carry= a/10;
				tab[size-i-1]= sum + '0';
			}
			else 
				tab[size-i-1]= a + '0';
	      		}
      		else if (carry != 0)
      		{
			a += carry;
			carry=0;
			if (a>9)
			{
          			sum=a % 10;
				  carry= a/10;
				  tab[size-i-1]= sum + '0';
			}
			else 
				tab[size-i-1]= a + '0';
      		}  
	}
	char *s;
	if (carry != 0)
	{
		s=new char[size+2];
		s[0]= carry+'0';
		int k=0;
		for (int i=1;k<size ;k++, i++)
			s[i]=tab[k];  
		s[size+1]='\0';
		BigInt m(s);
		return m;
    	}
	cout<<"size "<<size<<endl;
	s= new char[size];
	for (int i=0 ; i< size ; i++)
		s[i]=tab[i];
        BigInt m(s);
    return m;
}
//=======================================================================
BigInt BigInt :: operator+=(const BigInt& rh)			//add
{
    char *s;
    int sum=0,carry=0;
    int a,m;
    if (size> rh.size)
        a=size;
    else
        a=rh.size;
    s= new char[a+1];
    for(int i =0 ; i<a ; i++ )
    {
        if (rh.size >size)
        {
          if (i>=size) 
          m=rh.num[rh.size-1-i] - '0';
          else
           m = num[size-1-i] -'0' + rh.num[rh.size-1-i] - '0';
        }
        else if (size>rh.size)
        {
          if (i>=rh.size) 
          m=num[size-1-i] -'0';
          else
           m = num[size-1-i] -'0' + rh.num[rh.size-1-i] - '0';
        }
        else
          m = num[size-1-i] -'0' + rh.num[rh.size-1-i] - '0';
        if (carry == 0)
        {
            if (m>9)
            {
                sum= m % 10;
                carry = m /10;
                s[a-1-i]=sum + '0';
            }
            else
            {
                s[a-i-1]=m + '0';
            }
        }
        else if (carry != 0)
        {
            m+= carry;
            if(m>9)
            {
                sum= m % 10;
                carry = m /10;
                s[a-1-i]=sum + '0';                
            }
            else
            {
                s[a-1-i]=m + '0';
            }
        }
    }
    char *d;
    if (carry != 0)
    {
        d= new char [a+2];
        d[0]=carry +'0';
        int k=0;
        for (int i=1;k<a ;k++, i++)
            d[i]=s[k];  
        d[a+1]='\0';
        delete [] num;
        num= new char [a+2];
        num=d;
    }
    else
    {
        delete [] num;
        num= new char [a+1];
        for (int i=0 ; i<a ; i++)
          num[i]=s[i];
        num[a]='\0';
    }
    return *this;
}
//========================================================================
bool BigInt :: operator==(const BigInt& val)const		//equality 
{
	bool check=0;
	if (val.size == size )		//first cchecks size if size is different then will return 0 
	{
		for (int i =0 ; i<size ; i++)
		{
			if (num[i] == val.num[i])		//if size is ssame then compares values at each index 
				check=1;
			else 
				return 0;
		}
	}
	else 
		return 0;
	if (check==1)
		return 1;
}

//==========================================================================
bool BigInt :: operator==(const char* val)const			//equality 
{
	int l=0;
	bool check =0;
	while (val[l] != '\0')		//finds length 
		l++;
	if(l==size)		//if length is same as size else will return 0
	{
		for (int i=0 ; i<size ; i++)
		{
			if (val[i]==num[i])	//comparing value at each index 
				check=1;
			else
				return 0;
		}
	}
	else
		return 0;
	return 1;
}
//===========================================================================
bool BigInt ::operator!=(const BigInt& val)const			//not equal to 
{
	bool check =0;
	if (size != val.size)		//if size is not equal then return 1 as provs not equal
		return 1;
	else
	{
		for (int i=0 ; i< size ; i++)
		{
			if (num[i] == val.num[i])		//compares valye at each index
				check=1;
			else
			{
				check=0;
				break;
			}
		}	
	}
	if (check ==0)
		return 1;
	return 0;
}
//==============================================================================
bool BigInt :: operator<(const BigInt& val)const		//less than
{
	if (size<val.size)
		return 1;
	else if(size>val.size)
		return 0;
	else if (size == val.size)
	{
		if (num[0]<val.num[0])
			return 1;
		else
			return 0;
	}
}
//=============================================================================
bool BigInt :: operator>(const BigInt& val)const		//greater than
{
	if (size<val.size)
		return 0;
	else if(size>val.size)
		return 1;
	else if (size == val.size)
	{
		if (num[0]<val.num[0])
			return 0;
		else
			return 1;
	}
}
//===============================================================================
bool BigInt :: operator<=(const BigInt& val)const		//less than equal to 
{
	bool check =0;
	if(size>val.size)
		return 0;
	else if (size==val.size)
	{
		for (int i=0 ;i<size ; i++)
		{
			if (num[i]==val.num[i])
				check=1;
			else
				return 0;
		}
		if(check==1)
			return 1;	
	}
	else if (size<val.size)
		return 1;

}
//===============================================================================
bool BigInt :: operator>=(const BigInt& val)const		//greater than equal to 
{
	bool check =0;
	if(size<val.size)
		return 0;
	else if (size==val.size)
	{
		for (int i=0 ;i<size ; i++)
		{
			if (num[i]==val.num[i])
				check=1;
			else
				return 0;
		}
		if(check==1)
			return 1;	
	}
	else if (size>val.size)
		return 1;

}
//===============================================================================
BigInt BigInt :: operator++(int x)		//post increement 
{
     int m=0,g,carry=0,sum=0;
     m= num[size-1] + 1 -'0';
   //  g= num[size-2] + 1 -'0';
     if (m>9 )
    {
      sum=m % 10;
      carry= m/10;
      num[size-1]= sum + '0';
     }
    else 
      num[size-1]= m - '0';   
    for (int i=1 ; i< size ; i++)
    {
        if (carry == 0)
        {
          g=  num[size-i-1] + carry -'0';
          carry=0;
            if (g>9 )
            {
              sum=g % 10;
              carry= g/10;
              num[size-i-1]= sum + '0';
            }
            else 
            num[size-i-1]= g + '0';                
        }
        else if (carry != 0)
        {
            g=  num[size-i-1] + carry -'0';
            carry=0;
            if (g>9)
            {
              sum= g% 10;
              carry= g/10;
              num[size-i-1]= sum + '0';
            }
            else 
            num[size-i-1]= g + '0';    
        }
    }
    char *n;
    if (carry != 0)
    {
        int k=0;
        n= new char [size +2];
        n[0]=carry +'0';
        for (int i=1; k<size;k++,i++)
            n[i]=num[k]; 
        n[size +1] ='\0';
    delete [] num;
    num= new char[size +2];
    for (int i=0 ; i< size+1 ; i++)
    {    num[i]=n[i];    }
    num[size+1]='\0';
    }
    return *this;

}

//===============================================================================
BigInt& BigInt :: operator++()		//preincrement 
{
	int m=0,g,carry=0,sum=0;
	BigInt s(num);
	//cout<<"SnoroSD"<<endl;
	m= num[size-1] + 1 -'0';
	if (m>9 )
    	{
	      sum=m % 10;
	      carry= m/10;
	      num[size-1]= sum + '0';
	}
	else 
		num[size-1]= m + '0';   
	for (int i=1 ; i< size ; i++)
	{
		if (carry == 0)
		{
			g=  num[size-i-1] + carry -'0';
			carry=0;
			if (g>9 )
            		{
				sum=g % 10;
				carry= g/10;
				num[size-i-1]= sum + '0';
 			}
			else 
				num[size-i-1]= g + '0';                
		}
		else if (carry != 0)
		{
			g=  num[size-i-1] + carry -'0';
			carry=0;
			if (g>9)
			{
				sum= g% 10;
				carry= g/10;
				num[size-i-1]= sum + '0';
            		}
		else 
		num[size-i-1]= g + '0';    
		}
	}
	char *n;
	if (carry != 0)
	{
		int k=0;
		n= new char [size +2];
		n[0]=carry +'0';
		for (int i=1; k<size;k++,i++)
            		n[i]=num[k]; 
        	n[size +1] ='\0';
		delete [] num;
    		num= new char[size +2];
	    	for (int i=0 ; i< size+1 ; i++)
		{    num[i]=n[i];    }
		num[size+1]='\0';
	}
    return s;

}
//===============================================================================
BigInt BigInt :: operator*(const BigInt& val)const 
{
    int i = 0,ans,ans_c,l=0,k=0,mod;
    int numA = 0;
    int numB=0;
    while (num[i] != 0)
    {
        numA=  (num[i] - '0')  + (numA * 10);
        i++;
    }
    i=0;
    while (val.num[i] != 0)
    {
        numB=  (val.num[i] - '0')  + (numB * 10);
        i++;
    }
    ans= numA * numB;
    ans_c=ans;
    //size of ans
    while (ans_c !=0)
    {  ans_c/=10;l++;}
    if(ans==0)
    {
      char *ans_a= new char [2];
       ans_a[0]='0';
      ans_a[1]='\0';

     BigInt m(ans_a);
    return m;}
    else
    { 
      char *ans_a= new char [l+1];
      while(k<l)
      {
        mod= ans % 10;
        ans_a[l-k-1]=mod + '0';
        ans /=10;
        k++;
      }
      ans_a[l]='\0';
      BigInt m(ans_a);
    return m;
    }
}
//===============================================================================
BigInt BigInt::operator*=(const BigInt& val)  {
    int n = size;
    int m = val.size;
    int len = n + m;
    char* result = new char[len+1];
    for (int i = 0; i < len; i++) {
        result[i] = '0';
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        int carry = 0;
        for (int j = m - 1; j >= 0; j--) 
        {
            int product = (val.num[j] - '0') * (num[i] - '0') + carry + (result[i+j+1] - '0');
            carry = product / 10;
            result[i+j+1] = (product % 10) + '0';
        }
        result[i] += carry;
    }
    result[len]='\0';
    int i = 0;
   
    while(result[i]=='0' && i<(len-1))
    {
        i++;
    }
    if (result[0] == '0')
    {
        delete [] num;
        num= new char [len-1];
       // cout<<"SDFS"<<endl;
        
        for (int m=0 ;m<len-1 ;m++)
            num[m]=result[m+1];
            return *this;
    }
    delete [] num;
    num=result;
    return *this;
}
//==========================================================================
ostream& operator<<(ostream& output,const BigInt& val)
{
	for (int i=0 ;i<val.size ; i++)
		output<<val.num[i];
	return output;
}
//===========================================================================
istream& operator>>(istream& input,BigInt& val)
{
	int i=0;
	string c;
	input>>c;
	val=BigInt(c);//calling constructor 
	return input;

}
//==============================================================================
BigInt& BigInt :: operator--()
{

}
BigInt BigInt :: operator--(int x)
{

} 
//============================================================================
/*BigInt :: ~BigInt()
{
	delete [] num;
	num=NULL;
}*/

/*
using namespace std ;
int main() {
  char *a="332";
  int size_a=3;
  int mod=0;int max,less;
  int val=32;int mul;
  int d;d=val;int i=0;
  //find size of val
  while (d != 0)
  {  d/=10;i++;}
  int size_b=i;
  int s=i;
  if(size_a>i)
  {
    max=size_a;less=i;}
  else
  {
    max=i;
    less=size_a;}
    char **p= new char *[less];
    for(int k=0 ; k<less ;k++)
      p[k]= new char [max+k];
    
    for (int i=0 ;i<less ;i++)
      for (int l=0 ;l<max+i ; l++)
        p[i][l]='0';
      
    
  char *b= new char [i];
  while (val != 0)
  {
    mod = val % 10;
    b[i-1]=mod +'0';
    i--;
    val/=10;
  }
  bool check=0;
  if (size_a>size_b)
  check=1;
  
  for(int k=0 ; k<less ; k++)
  {
    mul= a[size_a-k-1] -'0';
    for (int j=0 ; j<max ;j++)
    {
      if(check==0)
        p[k][max-j-1]=((b[size_b-j-1]-'0')*mul)+'0';
      else
        p[k][max-j-1]=((a[size_a-j-1]-'0')*mul)+'0';
      
    }
  }
  
  
  return 0;
}
*/
