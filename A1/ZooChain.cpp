#include <iostream>
using namespace std;
#include "ZooChain.h"
//==================================================
 void ZooChain :: remove_Duplicate()
{
	ZooCage *find=NULL, *temp_chain=NULL;
	ZooCage *same_element=NULL;
	find = start;
	temp_chain = find;
 
    //comparing each element with the rest elements inthe chain 
	while (find != NULL && find->link != NULL)	//iterates till either fidn (basically start) beccaomes null or till its link beccomes null
	{
		temp_chain = find;
		for (; temp_chain->link != NULL ;)	//loop 2 works till value in temp link reaches null 
		{	
			if (find->cageNumber == temp_chain->link->cageNumber)//we are basically comparing one element with all elements of the chain and then we update find 
			{
				same_element = temp_chain->link;
				temp_chain->link = temp_chain->link->link;
				same_element->name = NULL;	//if duplicate is found first it assigns the address pointed by duplicates link to the previous element'slink and then deletes this memory 
				delete same_element;
			}
			else
				temp_chain = temp_chain->link;	//updates temp_chain .
		}
		find = find->link;	//updates find 
	}
}

//==================================================
ZooChain :: ZooChain()		//default constructor
{   start= NULL; }
//===================================================
ZooChain :: ~ZooChain()	//destructor 
    {
    	start=NULL;
    }
//===================================================
void ZooChain :: Sort_Chain()
{
	char * temp_name ;
	int temp_cNo  ; 
	ZooCage *find = start ;  
	   
	for ( ; find != NULL ; )		//works till NULL 
	{
		ZooCage  *next = find->link ; 
		for ( ; next != NULL ; )	//works till NULL 
		{
			if ( next-> cageNumber < find-> cageNumber  ) //checing which cage number is greater 
			{
				temp_cNo = find->cageNumber ; //storing in temporary var
				temp_name = find->name ; 	//storing in temporary var
				//simple swapping techniques used 
				find->name = next-> name; //now copying the name of next to name of address poiinted by find
				find->cageNumber = next ->cageNumber ; //copying the cagenumber pointed by nect to the find cagenumber 
				next ->cageNumber= temp_cNo;	//assigning "" to cagenumber of address pointed by next
				next-> name = temp_name  ; //assigning temp_name to name of address pointed by next  
			} next = next -> link ; //updating nect 
		}
		find = find -> link ; //updating finnd
	} 

}  

//================================================================================
//UPDATE 
void ZooChain :: update_name_at_cageNumber( int cageNumber,char *name)
{
    ZooCage *search=start->link;
    //if there are no elements in the chain 
    if(start== NULL)
    {   return; }
    //if the first element is the one that needs to be manipulated 
    if (start->cageNumber == cageNumber)
    {       
        start->name= name;		//assign name to name of address pointed by start 
        return;
    }
    //incase we have to search for the cage number in the chain
    while ((search != NULL))
    {
    	if (search->cageNumber == cageNumber)
    	{	
    		search->name= name;	//assign name to name of address pointed by start 
    		break;
    	}
    	search= search->link; 
    }
}

//DELETE CHAIN 
//======================================================================
void ZooChain :: delete_Chain(int cageNumber)
{
    ZooCage *t=start;
    ZooCage *finding=start->link;
    if(start==NULL)     //incase the cchain doesnt exist 
        return;
    if (t->cageNumber == cageNumber)
    {   
    	start= start->link;
        delete t;
        return;
    }
    ZooCage *last=start;		//if a chian exist then we are going through all values and comparing the cage number 
    while ((finding != NULL)&& (finding->cageNumber != cageNumber))
    {                                                   //we do this till either we find the value ot we reached null
        last=finding;
        finding=finding->link;
    }
    ZooCage *temp=finding->link;    //if the loop ended basecaue value is found then i am assigning the next link in chain to temp pointer
    if (finding !=NULL )        //incase the loop ended beacuse the value was found 
    {
        last->link=temp;        //used for rejoining the chain 
        delete finding;         //deleting the found record 
    }   
    else            //if the loop ended beacuse the calue was not found in the chain 
    {
        return;
    }
    
}

//PRINT CHAIN
//===============================================================================
void ZooChain :: print_Chain()
{
	if (start== NULL)
		return;
	ZooCage *print=start;
	while(print->link != NULL)
	{
		cout<<print->name<<endl;	//prints name
		cout<<print->cageNumber<<endl;	//prints cage
		print= print->link;	//updates print 
	}
   // cout<<start->name<<endl;
    //cout<<start->cageNumber<<endl;
}

//ADD CAGE
//=================================================================================
void ZooChain :: add_Cage(char *name, int cageNumber)
{
    ZooCage *z=new ZooCage;
    z->name=name;	//simpily assigning parameters to a structure of zoocage
    z->cageNumber=cageNumber;
    z->link=NULL;
   // int i=0;
    if (start == NULL)	//is start points to nothing adds first elemnt in chain to start
    {
        start= z;
        return;
    }
        //if this is not the first instance in the chain 
        ZooCage *find=start;
        for (; find->link != NULL; )	//iterates till null is not reached so the last element's link is null
        {
            find= find->link;	//updatess find
        }
    
    //adding the new instance at the end of the chain
    find->link=z;
}
