class Line
{
	int lines=0;	//number of lines
	char* text=NULL;	
	int size=0;	//number of characters in a line
	public:
	Line();
	Line(char *t);
	Line(const string t);
	Line(Line& a);
	~Line();
	Line& operator=(const char *t);
	bool operator==(const Line& a)const;
	friend ostream& operator<<(ostream& out, const Line& l);
};
