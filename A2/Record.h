//Noor Fatima, 22i-1036 , J , Assignment # 2
#include <iostream>
using namespace std;
#include <fstream>
class Record
{
    private:
    char *filename;
    char *name=new char [100];
    char *address= new char [100];
    int age;
    float CGPA;
    public:
    
    Record(char* str); //construtor will create the file with the given filename*/
    int record_Input();
    void record_Display();
    int delete_Record();
    int record_Count();
    int record_Search();
    int record_Insert();
    void record_Replace();
   ~Record();
    
};
