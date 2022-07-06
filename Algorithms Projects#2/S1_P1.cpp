#include <string>
 #include <iostream>
 #include <cassert>
using namespace std;
template<class T> class mylist;
template <class T>
class node
		{
		    T data;
		    node<T> *next;
		    node<T>*prev;
		    friend class mylist<T>;
		    public:
		    	node(){}
		    	node(T s)
				 {  
				    data = s;
				    prev = NULL;
				    next = NULL;
				 }
		};
template <class T>
class mylist
{
	protected:
		
		node<T>*first ; 
        node<T>*last ;
        node<T>*dummy;
        static int length;
	public:
		class iterator 
		{
	    friend class mylist;
	    private:
	      node<T> *nodeit;
	    public:
	      iterator()
		  {
		  	  nodeit=NULL;
		  } 
	      T& operator*() 
		  {
	        return nodeit->data;
	      }
          void operator ++()
		  {
		      nodeit = nodeit->next;
          }
          void operator --()
		  {
			   nodeit = nodeit->prev;
          }
          bool operator ==(const iterator& val)const
		  { 
		       return nodeit== val.nodeit;
		  }
		  bool operator!=(const iterator& val)
		  {
		  	return nodeit!= val.nodeit;
		    }
    }; 
	   mylist()
	    {
            first = NULL;
			last = NULL;
			dummy=new node<T>;
			length=0;
        }
		mylist(T value, int initial_size) 
		{
		 	first = NULL;
			last = NULL;
			dummy=new node<T>;
			length=0;
		 	while(initial_size!=0)
			{
                push(value);
                initial_size--;
            }
		}
		void push(T value){
	    	if(isEmpty()){
	    		first=new node<T>;
	    		first->data=value;
	    		first->next=NULL;
	    		last=first;
	    		length++;
			}
			else
			{
				node<T>*newptr=new node<T>;
				newptr->data=value;
				newptr->next=NULL;
				last->next=newptr;
				last=newptr;
				length++;	
			}
		}
		bool isEmpty()
		{
			if(last==NULL)
			{
				return true;
			}
			else{
				return false;
			}
		}	
		~mylist() 
		{
		    while (first->next != NULL) 
			{
		        node<T>* curr = first;
		        first = first->next;
		        delete curr;
		      }
		      delete first;
		}
		int size()
		{
		  return length;
		}
		void insert(T value, iterator position) 
		{ 
		if (position.nodeit == NULL)
		    {  
		       push(value);
		       return;
		   }
		   node<T>* after = position.nodeit;
		    node<T>* before = after->prev;
		    node<T>* newnode = new node<T>(value);
		    newnode->prev = before;
		    newnode->next = after;
		    after->prev = newnode;
		    if (before == NULL) /* insert at beginning */
		       first = newnode;
		    else
		      before->next = newnode;
		    }   
		iterator erase(iterator position)
		{
			//assert(position.nodeit != NULL);
		    node<T>* remove = position.nodeit;
		    node<T>* before = remove->prev;
		    node<T>* after = remove->next;
		   if (remove == first)
		      {
		      	first = after;
			  }
		    else
		       {
		       	before->next = after;
			   }
		    if (remove == last)
		      {
		      	last = before;
			  }
		    else
		       {
		       	after->prev = before;
			   }
		    position.nodeit = after;
		    delete remove;
		    return position;
       }
       iterator begin() const 
	   {
            iterator it;
	        it.nodeit = first;
	        return it;
       }
       iterator end() const 
	    {
           if(first==NULL)
		   {
	           iterator it;
	           it.nodeit = last;
	           return it;
	        }
	        iterator it;
	        last->next = dummy;
	        dummy->prev = last;
	        dummy->next = NULL;
	        it.nodeit = dummy;
	        return it;
        }
        mylist<T>& operator = (mylist<T> another_list) 
        {
        	if (this != &another_list)
		    {
		    	while (begin() != end())
		    	{
                  erase(begin());
                }
                for (iterator p = another_list.begin(); p != another_list.end(); p++)
                {
                    push(*p);
                }
		    }
		    return *this;
		}
		void display()
		{
			node<T>*curr=first;
			cout<<"data:"<<endl;
			while(curr!=NULL && curr!=last)
			{
				cout<<curr->data<<" ";
				curr=curr->next;
			}
			cout<<last->data;
		}
};
template<class T>
int mylist<T>::length=0;
int main(int argc, char** argv) {
	mylist<int> list(5,5);
	list.display();
	cout<<endl;
	mylist<int>::iterator pos=list.end();
    --pos;
    --pos;
    list.insert(60,pos);
    list.insert(20,pos);
    pos = list.begin();
    ++pos;
    list.insert(20,pos);
    list.display();
    cout<<endl;
    list.erase(pos);
    list.display();
	return 0;
}
