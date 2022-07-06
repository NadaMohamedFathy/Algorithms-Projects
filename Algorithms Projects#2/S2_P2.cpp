#include <iostream>
#include <stack>
using namespace std ; 
bool areSame(char open , char close) 
{
	if(open=='('&&close==')')
	  return true ; 
	else if (open=='['&&close==']')
	  return true ; 
	else if (open=='{'&&close=='}')
	  return true ; 
	else 
	  return false ; 
}
bool areBalanced(string bract)
{
	stack<char> q ; 
	for(int i = 0 ; i<bract.length();i++)
	{
		if(bract[i]=='('||bract[i]=='['||bract[i]=='{')
		  q.push(bract[i]) ; //put it in the stack 
		else if(bract[i]==')'||bract[i]=='}'||bract[i]==']')
	    {
		   if(q.empty()||!areSame(q.top(),bract[i]))
		      return false ; 
		    else 
		      q.pop() ; //remove bracet from stack 
	    }
		
	}
 if(q.empty())	
  return true ; 
 else 
  return false ; 
}
int main(int argc, char** argv) {
	
	string b ; 
	cout<<"enter an expression  ======>> "<<endl ; 
	cin>>b;
	if(areBalanced(b))
	  cout<<"the expression is balanced :D "<<endl ; 
	else
	 cout<<"the expression is not balanced :( "<<endl ; 
	
	return 0;
}
