//Noor Fatima, 22i-1036, J , Assignment #2
#include <string>
class String 
{
	char* data;
	int len;
	public:
	String();		//default 
	String (char* str);
	String (const String &str);
	String (int x);
	char *getdata();
	int length();
	char getChar(int i);
	bool isEmpty();
	String append_string(const String &str);
	String append_string(const char &str);
	String append_string(char *&str);
	String append_string(string& str);
	bool isEqual(const String&)const;
	bool isEqual(const string&)const;
	bool isEqual(char* str2)const;
	int index_at(char)const;
	int index_at(const String& )const;		
	int index_at(const string&)const;	//ek test left
	int index_at(char*)const;
	String& assign_string(const String&);
	String& assign_string(char*);
	String& assign_string(const string&);			
	String remove_string(const String &substr);
	String remove_string( string &substr);
	String remove_string(char *&substr);
	String remove_string(const char &c);
	//~ String(){
	//	delete [] data;}
};
