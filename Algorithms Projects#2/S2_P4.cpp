#include <iostream>
using namespace std ; 
class Student
{     
    friend class StudentList ; 
    protected :  
	 string name ; 
	 float gpa ;
	 int id ; 
	public : 
	Student()
	{
		name = " " ; 
		gpa = 0.0 ;
		id = 0 ;  
	}
	Student(string na , int i ,float g)
	{
		name=na;
		id=i ; 
		gpa=g;
        	
	}
};
class StudentList 
{   
    friend class Student;
     struct node 
	{ 
	string na ; 
	 float g ;
	 int i; 
  	node* next; //next
    };	
    node*first ; //head
    node*last ; //link
    int length ; 
	public :
	Student *s ;
	StudentList()
      {
	    first = last = NULL ;
	    length = 0 ; 
      }  
    bool isEmpty()
	{
    	return length==0 ; 
    }
	void insertion(Student *n)
   {   
      node* NewNode = new node;
      NewNode->na = n->name;
      NewNode->i = n->id;
      NewNode->g = n->gpa;
      node* Node1 = first;
      node** Node2 = &first;
      
      while(Node1 != NULL && Node1->i < NewNode->i)
    {
    	
           Node2 = &Node1->next;
           Node1 = Node1->next;
            
    }
    
      *Node2 = NewNode;
       NewNode->next = Node1;
      
    }
	void delection(int element)
	{
    	node*prev=NULL ;
	    node*curr = first;
	    node*newnode;
	    if (first == NULL)
	   {
         cout<<("list is empty");
       }
       else 
	   {
        while (curr != NULL) 
		{
        if (curr->i!=element)
		{
            prev = curr; 
            curr = curr->next; 
        } 
		else if (curr == first&&curr->i==element)
		{
            first = first->next; 
            curr = curr->next; 
        } 
		else if (curr != first && curr->next != NULL&&curr->i==element) 
		{
            prev->next = curr->next; 
            curr = curr->next;
        } 
		else if (curr->i==element&&curr->next == NULL) 
		{
            
        	prev->next = NULL ;  
        	last=prev ; 
	       delete curr ; 
        }
        else 
        {
        	cout<<"Not found"<<endl;
		}
        }   
    }

        return ;
	}
	void display()
	{
	 node*curr = first; //head
	while(curr!=NULL)
	{  
	    cout<<curr->na<<"  ";
		cout<<curr->i<<"  ";
		cout<<curr->g<<endl;
		curr=curr->next; 
	} 	
	}
	int search(int element)
	{
	node*curr=first ; 
	while(curr!=NULL)
	{
		if(curr->i==element)
		{
		  cout<<"found : "<<curr->na<<" "<<curr->g<<" "<<curr->i ;
		 return 1; 
     	}
		curr=curr->next  ; 
    }
	 cout<<"Not found"<<endl ;
	}
    float search(double element2)
    {
	 node*curr=first ; 
	while(curr!=NULL)
	{
		if(curr->g==element2)
		{    
		 cout<<"found : "<<curr->na<<" "<<curr->i<<" " <<curr->g;
		 return 1; 
     	}
		curr=curr->next  ; 
	} 
	 cout<<"not found"<<endl; 
    }
	string search(string element3)
	{
	 node*curr=first ; 
	while(curr!=NULL)
	{
		if(curr->na==element3)
		{
		  cout<<"found : "<<curr->i<<" "<<curr->g<<" ";
		  return curr->na;  
     	}
		curr=curr->next  ; 
	}
	string str="not found";
	return  str; 
    }
};
int main(int argc, char** argv) {
Student s("sara",201201,3) ; 
Student s2("nada",201204,2) ;
Student s3("ayat",201203,2.1);
Student s4("mark",201202,2.5);
StudentList list ; 
list.insertion(&s);
list.insertion(&s2);
list.insertion(&s3);
list.insertion(&s4);
list.display();
list.search(2.5);
cout<<endl;
list.search(201200);
list.search(201203);
cout<<endl<<list.search("y")<<endl ; 
cout<<list.search("sara");
 
return 0;
}
