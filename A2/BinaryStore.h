//Noor Fatima, 22i-1036, J, Assignment # 2
class BinaryStore
{
	char **address;
	char **bytes;
	int index;	
	
	public:
	//BinaryStore()		//notincluded in assignment 
	BinaryStore(int len=1);
	void add_Address(char *s);
	void set_Byte(char *address, char *value);
	char* Get(char *address);
	char *ToString();		
	char* Add(char *a , char *b);
	bool comp_EQUAL(char *a, char *b);
	char* comp_AND(char* a, char* b);
	char* comp_OR(char* a,char* b);
	char* comp_NOT(char *a);
	~BinaryStore();		//done in cppp

};
