#include "Line.cpp"
class Page
{
	Line ob[20];
	int lines;
	public:
	Page();
	Page(const Page &a);
	Page& operator+=(const Line& l);
	Page& operator=(const Page& m);
	~Page();

};
