#include <iostream>
using namespace std;
template <class t>
class linkedQueue{
	protected:
		struct node{
			t item;
			node*next;
		};
	    node*first;
	    node*last;
	    static int length;
	    
	public:
		linkedQueue(){
			first=last=NULL;
			length=0;
		}
		 linkedQueue(t value, int intial_size) 
		 {
		 	first = NULL;
			last = NULL;
			length=0;
		 	while(intial_size!=0)
			{
                push(value);
                intial_size--;
            }
		 }
		int size(){
		  return length;
		}
		bool isEmpty(){
			if(last==NULL){
				return true;
			}
			else{
				return false;
			}
		}
	    void push(t value){
	    	if(isEmpty()){
	    		first=new node;
	    		first->item=value;
	    		first->next=NULL;
	    		last=first;
	    		length++;
			}
			else{
				node*newptr=new node;
				newptr->item=value;
				newptr->next=NULL;
				last->next=newptr;
				last=newptr;
				length++;
				
			}
		}
		void pop(){
			if(isEmpty()){
				cout<<"empty queue"<<endl;
			}
			else{
				node*temp=first;
				if(first==last){
					first=NULL;
					last=NULL;
					length=0;
				}
				else{
					first=first->next;
					temp->next=NULL;
					delete temp;
				    length--;
				}	
			}
		}
		 t& front() 
		 {
		 	if(isEmpty())
			{
				cout<<"Is empty"<<endl;		
			}
			else
			{
				return first->item;
			}
		 }
		void display(){
			node*cur=first;
			cout<<"item in the queue:"<<endl;
			while(cur!=NULL){
				cout<<cur->item<<" ";
				cur=cur->next;
			}
		}
		~linkedQueue(){
			
		 	node * temp;
            while(first != NULL)
			{
            temp = first;
            first = first->next;
            delete temp;
		    }
	     }
	   
};
template<class t>
int linkedQueue<t>::length=0;
int main(int argc, char** argv) {
	linkedQueue<int> q(4,3);
	q.display();
	cout<<endl;
	q.pop();
	q.display();
	cout<<endl;
	q.push(200);
	q.push(300);
	cout<<endl<<q.size()<<endl;
	q.display();
	cout<<endl<<q.front()<<endl;
		return 0;
}
