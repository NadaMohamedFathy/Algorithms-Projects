#include <iostream>
using namespace std;
template<class t>
class stack{
	private:
		struct node
		{
			t item;
			node*next;
		};
		node*first;
	    static int length;
	public:
		stack(){
			first=NULL;
			length=0;
		}
		stack(t value, int intial_size) 
		{
			first = NULL;
			length=0;
		 	while(intial_size!=0)
			{
                push(value);
                intial_size--;
            }
		}
		void push(t value)
		{
			node*newnode=new node;
			newnode->item=value;
			newnode->next=first;
			first=newnode;
			length++;
		}
		 t& top() 
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
		void pop()
		{
			if(isEmpty())
			{
				cout<<"Is empty"<<endl;		
			}
			else
			{
				node*newnode=first;
				first=first->next;
				newnode=newnode->next=NULL;
				delete newnode;
				length--;
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
	    bool isEmpty(){
			if(first==NULL){
				return true;
			}
			else{
				return false;
			}
		}
	    int size(){
		  return length;
		}
	    ~stack(){
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
int stack<t>::length=0;
int main(int argc, char** argv) {
	int x;
	stack <int> q(4,3);
	q.display();
	cout<<endl;
	cout<<q.top()<<endl;
	cout<<endl;
	q.pop();
	q.display();
	cout<<endl;
	q.push(200);
	q.push(300);
	q.display();
	cout<<endl;
	cout<<q.top()<<endl;
	cout<<endl<<q.size()<<endl;
	return 0;
}
