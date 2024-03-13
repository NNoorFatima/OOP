
#include <iostream>
using namespace std;
//Noor Fatima,22i-1036, J
void print_row(int n,int);
void print_hash(int, int n);
void print_space(int l);
void print_dot(int x);
void print_line(int l);
void print_star(int x);
void print_hash_down(int x);
//diamond 
void printDiamond(int n);
void print_star(int x);
void printspace(int x);
void diamond(int x,int y);
//vowels
bool vowel_check(char x);
//pattern 1
void print_r2(int n);
void print_c2(int n , int x);
void print_c1(int n, int x);
void print_r1(int n);
//q1
int s_index(char p[], char i[] , int s_p , int s_i ) 


//----------------------------------------------------------------------------------------
char* removeSentence(char* Para, char* input)
{
    int len_i=0,len_p=0;
    
    while (Para[len_p] != '\0') //finding length of para 
        len_p++;
    
    while (input[len_i] != '\0')    ///finding length of input
        len_i++;
        
    char *para_a= new char [len_p] ; //creating a dynamic array of same size as para
    char *input_a = new char [len_i];  //creating a dynamic array of same size as input
    

    input_a=input ;     //input_a points to first  index of input
    int f=0;
    while (f<len_p)     //copying each index value from para to para_a
    {
      para_a[f]=Para[f] ;
      f++;
    }
    Para = para_a ;     //para points to first index of para_a
    int s_pos = s_index(para_a , input_a , len_p , len_i ); //function for finding the starting the position 
    
    if( s_pos==-100 )       //incase substring doesnt exist in the array
        cout<<"The sub-string you are looking for doesn't exist int the paragraph. "<<endl;
    
   
    int pos=0;      //initializing variables 
    bool check=0;
    int w=0,j=0;
    while (w<len_p)
    {
        check=0;
        while(j<len_i)          //using two loops to remove the input from para 
        {
            if(input_a[j] != para_a[w+j])       //comparing values at each index to find the input string which is to be removed
            {
                check=0;
                break;
            }
            else
                check=1;
            j++;
        }
        if (check==1)
        {
            w= (len_i-1)+w;
            continue;
        }
        para_a[pos]=para_a[w];
        ++pos;
        w++;
    }

    
    para_a[pos] = '\0';      //assigning Null cahracter 
    int i=s_pos;                //assigning x to i
    
    while (i<len_p)         //extra spaces are removed
    {   
        para_a[i]=para_a[i+1];
        i++;
        
    }
    Para = para_a ;         //para now points to first index of para_A
    return Para ;  
}

int s_index(char p[], char i[] , int s_p , int s_i ) 
{
    int m=0;
    int a= s_p-s_i;
    for (int k=0 ; k<= a; k++)
    {
        for (m=0 ; m< s_i ; m++)
        {
            if (i[m] != p[m+k])
                break;
        }
        if (m==s_i)
            return k;
    }
        return -100;
}



//------------------------------------------------------------------------------------
bool FindSubString(char* Str, char* substr, int& start, int& end)
{

    bool check=0;		
    int i = 0;
    while (Str[i] != '\0')		//finding length of str
    {
        i++;
    }
    char *p = new char[(2 * i) + 1];		//creating a dynamic array of double length of Str
    for (int k = 0; k < (i); k++)
    {
        p[k] = Str[k];				//copying values from Str starting position till end index in dynamic array and again from starting till end to create a circular array
    }
    for (int k = 0; k < (i + 1); k++)		//eg array abcd will have a dynamic array like abcdabcd\0
    {
        p[i + k] = Str[k];
    }
    int l=0;
    
    //finding length of substr
    while (substr[l] != '\0')			
    {
        l++;
    }
    int x=0;
    while((p[x] != '\0') && (check!=true))		//loops works till either checck is not true or if the character is not equal to null character
    {
        if (p[x]==substr[0])				//matacching first index of substr 
        {
          
            for (int k=0 ; k<l ;k++)			//if match found in a loop compares all other elements of substr with str 
            {
                if (p[x]==substr[k])			//at any point if the letter dont matacch the loop break
                {
                  check=true;
                  x++;
                }
                else 
                {  
                  x=x-k;
                  check =false;
                  break;}
            }   
        }
        if(check==false)
        x++;
        else 
        break;
        
    }
    if(check==true)
    {
      end=x-2;
      if (end >=(i-1))
      {
        end= end -(i-1);
      }
      //start=x-1-l;
      start=x-l;
      return 1;
    }
    else 
    {
        start=-1;
        end=-1;
        return 0;
    }
       
   

}

//Q2
//------------------------------------------------------------------------------------------
char*** ConvertToDynamic(char arr[], int x, int y, int z) //Converts 1D Array to 3D dynamically allocated array
{

}

bool MatchString3DArray(char*** mat, int xSize, int ySize, int zSize, char * input, int**& resultMat, int& colSize)
{

}

void DeleteArray(char***& arr, int x, int y, int z)
{
    
}

//------------------------------------------------------------------------------------------
bool isperfectNumber(int n)
{
    static int i=1;
    static int sum=0;
    if (i==n)
    {
        if (n==sum)
            return true;
        else 
            return false;
    }
    else
    {
        if (n%i==0)
            sum +=i;
        i++;
        return isperfectNumber(n);
    }
}

//----------------------------------------------------------------------------------------
int findVowels(char* str)
{
	int i=0,j=0;
    if (str[i]=='\0')
        return j;
    else 
    {
        
        j += vowel_check(str[i]);
        str++;
        j += findVowels(str);
        
       
    }
    return j;
}
bool vowel_check(char x)
{
    if (x=='A'||x=='a'||x=='E'||x=='e'||x=='I'||x=='i'||x=='O'||x=='o'||x=='U'||x=='u')
        return 1;
    else
        return 0;
}


//---------------------------------------------------------------------------------------
int pascal(int row, int col)
{
	if (col == row || col == 0 || row==0) //base condition 
        return 1;
    	else 
        return pascal(row-1, col) + pascal(row-1, col-1);   //recursive condition
}


//-----------------------------------------------------------------------------------------
void PrintPattern1(int start, int end)
{
    if (end==0);
    else
    {
    print_r1(end/2);
    PrintPattern1(start,end-(2*end/2));
    print_r2(end/2);
    
    }
}
//lower    
void print_r2(int n)
{
    if (n==1);
    else
    {
        print_r2(--n);
        print_c2(n,0);
        cout<<endl;
    }
}
void print_c2(int n , int x)
{
    if (n==x)
        cout<<"*";
    else 
    {    
        cout<<" ";
        x++;
        print_c2(n,x);
    }
            
}
//upper
void print_c1(int n, int x)
{
    if(x==(n-1))
        cout<<"*";
    else 
    {    
      cout<<" ";
      print_c1(n,++x);}
}
void print_r1(int n)
{
    if(n==0);
    else 
    {
        print_c1(n,0);
        cout<<endl;
        print_r1(n-1);
    }
}


//--------------------------------------------------------------------------------------
void printHollowDiamond(int n)
{
    if(n==0);	//base condition 
    else	
    {
        diamond(n,n);
        printHollowDiamond(n-n);	//recursive condition
    }
    
}
//space function 
void printspace(int x)
{
    if(x<=0);		//base condition 
    else
    {
        cout<<"  ";
        printspace(--x);	//recursive condition 
    }
}
//star
void print_star(int x)
{
    if(x<=0);		//base condition 
    else
    {
        cout<<"*";
        print_star(--x);	//recursive condition 
    }
}
void diamond(int x,int y)
{
    if(y<=0);		//base condition 
    else
    {
        print_star(y);
        printspace(x-y);
        print_star(y);
        cout<<endl;
        diamond(x,y-1);	//recursive condition 
        print_star(y);
        printspace(x-y);
        print_star(y);
        cout<<endl;
    }
}

//
//----------------------------------------------------------------------------------------
void PrintPattern2(int n, int x)
{
    int l=1;
    if (n==1);
    else
    {
        print_hash(0,n);
        // print_space(l);
        print_dot(n);
        //print_space(l);
        print_star((x-n));
        // print_space(l);
        print_line(l);
        print_star((x-n));
        print_dot(n);
        print_hash_down(1);
        cout<<endl;
        PrintPattern2(n-1,x);
//unrolling of recursion 
        // space( n);
        print_hash(0,n);
        //print_hash_down(1);
        // print_space(l);
        print_dot(n);
        print_star((x-n));
        //  print_space(l);
        print_line(l);
        print_star((x-n));
        print_dot(n);
        print_hash_down(1);
        cout<<endl;
    }
}
void space(int n)
{
    if(n<=0)
    return;
    else
    {    cout<<"o";
    space(--n);}
}
void print_hash_down(int x)
{
    if(x<=0);
    else
    {
        cout<<"#";
        print_hash_down(--x);
    }
}
void print_star(int x)
{
    if(x<=0)
    {
        return;
        
    }
    else
    {
        cout<<"* * ";
       // print_space(1);
        //cout<<" ";
         //print_space(1);
        print_star(x-1);
    }
}
void print_dot(int x)
{
    if (x==0);
    else
    {
        cout<<" . ";
        print_dot(--x);
        
    }
}


void print_line(int l)
{
    if (l==0);
    else 
    {
        cout<<"| ";
        print_line(--l);
    }
}



void print_space(int l)
{
    if(l==0);
    else
    {
        cout<<" ";
        print_space(--l);
    }
}


void print_hash(int x,int n)
{
    if (n==x)
    {    
        cout<<" #";
    }
    else 
    {
        cout<<" ";
        print_hash(++x,n);
    }
}

//-----------------------------------------------------------------------------------------
void startSnakeGame() // controller of the game
{

}
