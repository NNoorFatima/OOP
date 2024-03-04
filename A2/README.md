# Assignment-2

## Question-1 
In a particular Zoo, to hold the zoo cage information ZooCage structure is used. The Zookeeper
wants to maintain a chain of zoo cages on so that it’s easier to perform different operations.
Implement the ZooChain Class member functions, please use the correct input parameters and
return types.

```
struct
{
    char *name;<br>
    int cageNumber;<br>
    ZooCage* link;<br>
}

class ZooChain
{
  public:
      ZooCage* start;
// Default constructor
      ZooChain() { start = NULL; }
      void add_Cage( char *name,int cageNumber); /*This member function will take the
   name and cageNumber of Animal as input parameter. It creates the ZooCage
    instance. If the new Zoocage instance is the first in the chain then the pointer
    “start“ will point to it.Otherwise a new instance is attached at the end of the
    existing chain.*/
        void print_Chain(); //It prints all the animals with their cage number in the
    chain.
        void delete_Chain( int cageNumber); /* This member function will take the
    cageNumber of Animal as input parameter. It deletes the mentioned cageNumber from
    the chain of ZooCage instances.And rejoins the remaining chain.*/<br>
    void Sort_Chain();// It sort all the elements in the chain based upon their
    cageNumber.
        void update_name_at_cageNumber(int cageNumber, char * name);<br>
        void remove_Duplicate();// It removes all the duplicates in the chain.<br>
        ~ZooChain()
};
```

## Question-2
Your goal is implement “String” class with the following functions. You will need to write two files
(String.h and String.cpp). Your implemented class must fully provide the definitions of following
class (interface) functions.<br>

```
class String {
        char* data;
        // there is need of more data members, think about them...
        public:
        // provide definitions of following functions...
        String(); // default constructor
        String(char* str); // constructor9 String(char *str); // initializes the
        string with constant cstring
        String(const String &); // copy constructor to initialize the string from
        existing string
        String(int x); // initializes a string of pre-defined size
        char* getdata();
        char getChar(int i); // returns the character at index [x] in a string
        bool isEmpty(); // returns true if string is empty..
        String append_string(const String &str); // appends a String at the end of
        the String
        String append_string(const char &str); // appends a char at the end of the
        String
        String append_string(char *&str); // appends a String at the end of the
        String
        String append_string(string& str); // appends a String at the end of the
        String
        String remove_string(const String &substr); //removes the substr from the
        String
        String remove_string(const string &substr); //removes the substr from the
        String
        String remove_string(const char *&substr); //removes the substr from the
        String
        String remove_string(const char &char); //removes the substr from the String

        String& assign_string(const String&); // copies one String to another
        String& assign_string(char*); // copies one c-string to another
        String& assign_string(const string&); // copies one string to another
        bool isEqual(const String&)const; //returns true if two Strings are equal
        bool isEqual(const string&)const; //returns true if two strings are equal
        bool isEqual(char *)const; //returns true if two strings are equal
        int index_at (char) const; // returns the index of the character being
        searched
        int index_at (const String&) const; // returns the start index of the String
        being searched
        int index_at (const string&) const; // returns the start index of the string
        being searched
        int index_at (char *) const; // returns the start index of the c-string
        being searched
        int length(); // returns the length of string
        ̃~String(); // destructor... };
```

## Question-3
A BinaryStore calculator will store bytes “stored in strings” with their addresses “stored in strings”,
i.e., at each address in the BinaryStore there is a stored byte.<br>
Each address will be 4 characters string and each byte will be 8 characters strings.
Your task is to create the BinaryStore class with all the function given in main class. Please use the
correct input arguments and return type for the function of BinaryStore class.<br>
Furthermore, implement all the constructors and member functions required against following
sample cod<br>

```
class BinaryStore
{
// add suitable member attributes
        public:
        BinaryStore (int len); // constructor which creates the store of length len.
        void add_Address(char* s); // add a new address in the list of Binary store.
        void set_Byte(char* address, char* value); // add the byte at newly added address
        // here the first parameter is address and second is byte// Similarly the
        following code adds byte address and later byte // if address not found add
        address and byte both // function also overrides the data given at particular byte
        address.
        char* Get(char* address),; //Get function will retrieve the byte at a given
        address ,
        char* ToString(); //return the BinaryStore as character dynamic array.
        char * Add(char * a, char * b);
        //ADD function will take two strings as input parameters and given the binary
        equivalent in form of string.
        // comp_EQUAL, comp_AND, and comp_OR function will take two strings as input
        parameters and given the binary equivalent in form of string.
        bool comp_EQUAL(char * a, char * b);
        char * comp_AND(char * a, char * b);
        char * comp_OR(char * a, char * b );
        char * comp_NOT(char * a);
        ~BinaryStore()
};
```

## Question-4

We have lots data of students containing their name, addresses, age and CGPA. We want to create
a class Record that will help to read and write this data to file. Class would provide member
functions that will ease the data access and retrieval.<br>

```
class Record
{
        private :
        // add required data members if required
        char* fileName;
        public :
        Record (char* str) ; constructor will create the file with the given file name.
        int record_Input(); /// input function will get the multiple data (name ,address
        ,age and CGPA )from the user and adds to the file,
        void record_Display() ;// the function will display the all the data store in
        file.
        int delete_Record();/// function will delete the complete record that is data
        (name ,address ,age and CGPA ) of person with given name.
        int record_Count();//function will count the total records stored in the file.
        int record_Search(); // Allows to search the file with a particular name
        int record_Insert();//it will allow the user to insert the data (name ,address
        ,age and CGPA ) after some name in the file
        void record_Replace();//it will allow the user to replace the data (name ,address
        ,age and CGPA ) of given name in the file
        ~Record()
};
```
