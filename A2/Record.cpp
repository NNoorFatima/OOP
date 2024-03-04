//Noor Fatima, 22i-1036, J , Assignment # 2
#include <iostream>
#include <fstream>
#include <string>
#include "Record.h"
//=======================================================================
Record :: ~Record()
{
	delete []name;
	delete [] address;
}
//========================================================================
Record :: Record(char* str)
{		//constructor 
    	fstream file;
    	filename=str;
    	file.open(filename, ios::out | ios::app );
    	if(!file)
   	{
       		cout<<"Error in creating file!!!";
      
   	}
  
   	cout<<"File created successfully.";
   	file.close();
    
} //construtor will create the file with the given filename
//========================================================================
int Record :: delete_Record()
{
	//first find if the record exists
	string temp;
	string data;
	int line=1;
	bool check =0;
	int len=0,len_name=0,i=0;
	ifstream data_file;
	data_file.open(filename, ios ::in);
	if (!data_file) {
		cout << "No such file found. Sorry ";
	}
	else 
	{
		cout<<"what is the name you are looking for: ";
		cin>>temp;
		getline(data_file,data);
		while (data[len] != '\0')
			len++;
		while (temp[len_name] != '\0')
			len_name++;		
		while (!data_file.eof())
		{
			//for(int i=0;i<len ;i++)
			i=0;
			check=0;
			
			while (i<len)
			{
				if(temp[0]==data[i])
					check = 1;
				//cout<<temp[0]<<" "<<data[i]<<endl<<len_name;
				for (int k=0 ; k<len_name ; k++, i++)
				{
					if(temp[k]==data[i])
						check=1;
					else
					{	check=0; 
						i-=k;
						break;}
				}
				if (check==1)
					break;
			i++;
			}
			if (check==1)
			break;
			getline(data_file,data);
			line++	;		//the line number where rhe data exists 
		}
		
	}
		
	/*data_file.close();
	if (check ==1)
	ofstream out_file(filename, ios::app);
	ifstream data_file;
	datafile.open(filename, ios :: in);
	int this_line=0;
	while (getline(data_file,data))
	{
		this_line++;
		if (this_line != line || this_line != (line+1))
		{
			data_file<< data <<endl;
		}
	}
	data_file.close();
	data_file.close();

	cout<<"data is at line " <<line<<endl;
	//return line;*/
}
//========================================================================
int Record :: record_Input()
{
	cout<<"Name: ";
	cin>>name;
	cout<<"enter age: ";
	cin>>age;
	cout<<"Enter address: ";	//taking input of age,name, address and gpa 
	cin>>address;
	cout<<"enter cgpa: ";
	cin>>CGPA;
	    
	ofstream outFile(filename, ios::app);
	outFile << "Name: "<<name <<'\n'<< "Address: "<<address << '\n' << "Age: "<<age << '\n' << "CGPA: "<<CGPA << endl; //writing int he file 
	outFile.close();
	   
	    return 1;
}
//========================================================================
int Record :: record_Insert()
{

   	char n[100];
	cout<<"Name: ";
	cin>>name;		//taking input of age,name, address and gpa 
	cout<<"enter age: ";
	cin>>age;
	cout<<"Enter address: ";
	cin>>address;
	cout<<"enter cgpa: ";
	cin>>CGPA;
	    
	ofstream outFile(filename, ios::app);
	outFile << "Name: "<<name <<'\n'<< "Address: "<<address << '\n' << "Age: "<<age << '\n' << "CGPA: "<<CGPA << endl;//writing int he file 
	outFile.close(); //close file 
	   
	    return 1;

}
//========================================================================
void Record :: record_Display ()
{
    	ifstream data_file;
	data_file.open(filename, ios::in);		//oopens file in input form 
	if (!data_file) {
		cout << "No such file found. Sorry ";
	}
	else {
		string data;
		/*while (1) 
		{
			data_file >> data;
			if (data_file.eof())
				break;

			cout <<data<<"";
		}*/
		getline(data_file, data);		//stores file data int he variable dara 
		while ( data_file) {         	
                cout << data << endl;                                 //displaus / outputs the data in endl 
                getline(data_file, data);    
        }
        }

	
	data_file.close();		//close file 
	
}
//========================================================================
int Record :: record_Count()
{
	ifstream data_file;
	int count=0;
	data_file.open(filename, ios ::in);		//open file in input mode 
	if (!data_file) {
		cout << "No such file found. Sorry ";
	}
	else 
	{
		string data;
		getline(data_file,data);
		while (!data_file.eof())		//while file doesnt reach end of file read value of dile in the variable dat a
		{
			count++;	//increments count here counts is beasiclly the line number 
			getline(data_file,data);
		}
	}
	count /=4;	//each record of one persontake four line so the total number of kine divided by 4
	return count;
}
//========================================================================
int Record :: record_Search()
{
	string temp;
	string data;
	bool check =0;
	int len=0,len_name=0,i=0;
	ifstream data_file;
	data_file.open(filename, ios ::in);		//oopen file in input mode 
	if (!data_file) {
		cout << "No such file found. Sorry ";
	}
	else 
	{
		cout<<"what is the name you are looking for: ";
		cin>>temp;
		getline(data_file,data);		//gets the data store in one line of file and store it in a variable called data 
		while (data[len] != '\0')
			len++;
		while (temp[len_name] != '\0')
			len_name++;		//finding the length of name 	
		//cout<<len_name;
		
		while (!data_file.eof())		//iterates while loop doesnt raach end of fiel 
		{
			//for(int i=0;i<len ;i++)
			i=0;
			check=0;
			
			while (i<len)
			{
				if(temp[0]==data[i])		//checks if the data at each index is equal to the first index of tem varbaible 
					check = 1;
				//cout<<temp[0]<<" "<<data[i]<<endl<<len_name;
				for (int k=0 ; k<len_name ; k++, i++)
				{
					//cout<<" mmm"<<data[i]<<endl;
					if(temp[k]==data[i])		//ensures all the values are equal 
						check=1;
					else
					{	check=0; 	//if it is not equal then sets check =0 and updates the value of i and breask from the loop 
						i-=k;
						break;}
				}
				if (check==1)
					break;
			i++;
			}
			if (check==1)
			break;
			getline(data_file,data);
		}
	}
	return check;
	
}
int main() {
  char* fileName = "records1.txt";
  Record record(fileName);

  int choice = -1;

  while (choice != 0) {
    cout << "\nSelect an option:" <<endl;
    cout << "1. Add record" << endl;
    cout << "2. Display records" << endl;
    cout << "3. Delete record" << endl;
    cout << "4. Count records" << endl;
    cout << "5. Search records" <<endl;
    cout << "6. Insert record" << endl;
    cout << "7. Replace record" << endl;
    cout << "0. Quit" << endl;
    cout << "> ";
    cin >> choice;

    switch (choice) {
      case 1:
        record.record_Input();
        break;
      case 2:
        record.record_Display();
        break;
      case 3:
    //    record.delete_Record();
        break;
      case 4:
       cout << "Total records: " << record.record_Count() << endl;
        break;
      case 5:
      {  
      	if(record.record_Search())
      		cout<<"Record found"<<endl;
      	else 
      		cout<<"Not found" <<endl;
        break;
      }
      case 6:
        record.record_Insert();
        break;
      /*case 7:
        record.record_Replace();
        break;*/
      case 0:
        cout << "Goodbye!" << endl;
        break;
      default:
        cout<< "Invalid choice" <<endl;
        break;
    }
  }

  return 0;
}
