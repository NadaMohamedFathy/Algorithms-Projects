#include <iostream>    
#include <cstring>    
using namespace std;
class TreeExpression
{
    private:
    	struct TNode 
		{
     	   char data;
           TNode *left, *right;
        TNode(char d)
		{
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
        };
    	struct SNode
		{
    		TNode *tNode;
            SNode *next;
        SNode(TNode *t)
        {
           this->tNode = t;
            next = NULL;
        }
		};
        SNode *node;

    public:
        TreeExpression()
        {
            node = NULL;
        }
        void clear()
        {
            node = NULL;
        }
        TNode *top()
        {
            return node->tNode;
        }
        void push(TNode *s)
        {
            if (node == NULL)

                node = new SNode(s);

            else
            {
                SNode *nptr = new SNode(s);
                nptr->next = node;
                node = nptr;
            }
        }
        TNode *pop()
        {
            if (node == NULL)
            {
                cout<<"empty"<<endl;
            }
            else
            {
                TNode *p = node->tNode;
                node = node->next;
                return p;
			}
        }
        void insert(char val)
        {

            if (val >= '0' && val <= '9')
            {
                TNode *np = new TNode(val);
                push(np);
			}
            else if (val == '+' || val == '-' || val == '*' || val == '/')
            {
                TNode *nptr = new TNode(val);
                nptr->left = pop();
                nptr->right = pop();
                push(nptr);
            }
            else
            {
                cout<<"Wrong Exprestion :D"<<endl;
                return;
            }
        }
        int toDigit(char ch)
        {
            return ch - '0';
        }
        void buildTree(string expression)
        {
            for (int i = expression.length() - 1; i >= 0; i--)

                {
                	insert(expression[i]);
				}
        }
        double evaluate()
        {

            return evaluate(top());

        }
        double evaluate(TNode *ptr)
		{

            if (ptr->left == NULL && ptr->right == NULL)
                return toDigit(ptr->data);
            else
            {

                double result = 0.0;

                double left = evaluate(ptr->left);

                double right = evaluate(ptr->right);

                char op = ptr->data;

                switch (op)

                {

                case '+': 

                    result = left + right; 

                    break;

                case '-': 

                    result = left - right; 

                    break;

                case '*': 

                    result = left * right; 

                    break;

                case '/': 

                    result = left / right; 

                    break;

                default: 

                    cout<<"Error :'("<<endl ;
                    break;

                }
                return result;   
            }
        }
        void prefix()
        {
            preOrder(top());
        }
        void preOrder(TNode *n)
        {
            if (n!= NULL)
            {
                cout<<n->data;
                preOrder(n->left);
                preOrder(n->right);            
            }    
        }
};
    
int main()
{
    string s = "+3*4/82";
    string n = "+4*5/63";
    string a = "+5*4/84";
    string m = "+7*4/42";
    string l = "+9*7/93";
    TreeExpression tree;
    TreeExpression tree1;
    TreeExpression tree2;
    TreeExpression tree3;
    TreeExpression tree4;
    tree.buildTree(s);
    cout<<"Prefix: "<<endl;
    tree.prefix();
    cout<<endl<<"Result is : "<<tree.evaluate()<<endl;
    tree1.buildTree(n);
    cout<<"Prefix: "<<endl;
    tree1.prefix();
    cout<<endl<<"Result is : "<<tree1.evaluate()<<endl;
    tree2.buildTree(a);
    cout<<"Prefix: "<<endl;
    tree2.prefix();
    cout<<endl<<"Result is : "<<tree2.evaluate()<<endl;
    tree3.buildTree(m);
    cout<<"Prefix: "<<endl;
    tree3.prefix();
    cout<<endl<<"Result is : "<<tree3.evaluate()<<endl;
    tree4.buildTree(l);
    cout<<"Prefix: "<<endl;
    tree4.prefix();
    cout<<endl<<"Result is : "<<tree4.evaluate()<<endl;
    return 0;

}
