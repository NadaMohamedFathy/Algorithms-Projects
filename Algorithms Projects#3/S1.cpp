#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
class word
{
public:
    string info;
    vector <int> index;

    friend ostream& operator <<(ostream & os, word key)
    {
        os<<key.info<<" ";
        for (int i=0; i<key.index.size(); i++)
        {
            if (i==key.index.size()-1)
            {
                os<<key.index[i];
                break;
            }
            os<<key.index[i]<<", ";
        }
        return os; 
    }
    bool operator<( word b)
    {
        string c,d;
        for (int i=0; i< info.length() ; ++i)
        {
            c+=tolower(info[i]);
        }
        for (int i=0; i<b.info.length() ; ++i)
        {
            d+=tolower(b.info[i]);
        }
        return (c<d);
    }

    bool operator>( word b)
    {
        string c,d;
        for (int i=0; i< info.length() ; ++i)
        {
            c+=tolower(info[i]);
        }
        for (int i=0; i<b.info.length() ; ++i)
        {
            d+=tolower(b.info[i]);
        }
        return (c>d);
    }
};
template <class t>
class  BSTNode {
	//friend class BSTFCI;
//	protected:
	
	   // friend class  BSTFCI;
	public:
		t key;
	    BSTNode *right;
	    BSTNode *left;
		BSTNode(){
			right=NULL;
			left=NULL;
		} 
	    BSTNode ( BSTNode *right, BSTNode *left){
	    	this->right=right;
	    	this->left=left;
		}	
};
template <class t>
class BSTFCI{
		//friend class BSTNode;
	private:
		
		 static int size ;
		//friend class <t> BSTNode;
	public:
		 BSTNode<t>* root;
	template <typename T2>
    friend bool isSubtree(BSTNode<T2> *n, BSTNode<T2> *S);

    template <typename T2>
    friend bool isSubTree(BSTFCI<T2>* t1, BSTFCI<T2>* t2);
    
    template <typename T2>
    friend bool isSame(BSTNode <T2>* s, BSTNode <T2>* a);
    
    template <typename T2>
    friend bool isBalance(BSTNode <T2>*node);
    
    template<class T2>
	friend int height(BSTNode <T2>*p);
	
	template<class T2>
	friend vector<int> largestValues(BSTNode<T2>* root) ;
	
	template<class T2>
	friend void largest(vector<int>res, BSTNode <T2>* root, int d);
	
	template <typename T2>
    friend void PrintRange(BSTNode<T2> *node, int k1, int k2);
    
    template<class T2>
	friend long treedigitSum (BSTNode <T2> *root, int val) ;
	
	template<class T2>  
	friend long digitSum (BSTNode <T2> *root)  ;
	
	template<class T2>
	friend void largestValueInEachLevel(BSTNode <T2>* root) ;
	    BSTFCI()
		{
	        root=NULL;
		} 
		BSTFCI(BSTNode <t>*node ){
			node->left=NULL;
			node->right=NULL;
		}
		int max(int x, int y)
         {
			if(x >= y)
			{
				return x;
			}
			else
			{
				return y;
			}
		 }
		bool isEmpty()
		{
			if (root==NULL)
			{
				return true;
			}
			return false;
		}
		void clear(BSTNode<t>* &p)
		{
			if(p != NULL)
			{
				clear(p->left);
				clear(p->right);
				delete p;
				p = NULL;
			}
		}
		void clearTree()
		{
			clear(root);
		}
	
		void PrintTreeInOrder(BSTNode<t> * p){
            if(p!=NULL) 
			{
            PrintTreeInOrder(p->left);
            cout << p->key << endl;
            PrintTreeInOrder(p->right);
		    }
		}  
		void PrintTreeInOrder()
        {
	       PrintTreeInOrder(root);
	       cout << endl<<endl;
	    } 
		
		void flip(BSTNode <t>* node = BSTFCI<t>::root)
		 {
			if (node == NULL)
			{
				return;
			}
	        else
	        {
	            BSTNode<t>* temp;
	            flip(node->left);
	            flip(node->right);
	            temp = node->left;
	            node->left = node->right;
	            node->right = temp;
			}
		}
		
		bool check(string a,string b)
		{
		    if(a<b)
		      return false;
		    return true;
		}
		void get_nodes ()
	    {
	        vector<word>a;
	        string s ;
	        string b="";
	        word obj;
	        int n = 4 ;
	        cout<<"Enter your text: "<<endl;
	        for (int i=0; i<n; i++)
	        {
	            getline(cin,s);
	            for (int j=0; j<s.length(); j++)
	            {
	                bool x=0;
	                if (s[j]==' '||s[j]=='.'||s[j]==',')
	                {
	                    x=1;
	                    for (int k=0; k<a.size(); k++)
	                    {
	                        if (a[k].info==b)
	                        {
	                            a[k].index.push_back(i+1);
	                            b="";
	                            break;
	                        }
	                    }
	                    if (b!="")
	                    {
	                        obj.info=b;
	                        obj.index.clear();
	                        obj.index.push_back(i+1);
	                        a.push_back(obj);
	                        b="";
	                        continue;
	                    }
                    }
	
	                if (!x)
	                    b+=s[j];
	                if (j==s.length()-1)
	                {
	                    for (int k=0; k<a.size(); k++)
	                    {
	                        if (a[k].info==b)
	                        {
	                            a[k].index.push_back(i+1);
	                            b="";
	                            break;
	                        }
	                    }
	                    if (b!="")
	                    {
	                        obj.info=b;
	                        obj.index.clear();
	                        obj.index.push_back(i+1);
	                        a.push_back(obj);
	                        b="";
	                        continue;
	                    }
				    }
	            }
	        }
	        for (int i=0; i<a.size(); i++)
	        {
	            Insert(a[i]);
	        }
	    }
		BSTNode<t>* Insert(t data, BSTNode<t>* p)
	    {
	        if (p == NULL)
	        {
	            p = new BSTNode<t>;
	            p->key = data;
	            p->left = p->right = NULL;
	            //size++;
	        }
	        else if (data > p->key)
	            {
	            	p->right = Insert(data, p->right); 
	            //size++;
				}
	        else if(data < p->key)
	           {
	           	 p->left = Insert(data, p->left);
	            //size++;
				}
			//cout<<size<<endl;
	        return p;
	        
	    }
	    void Insert(t data)
	    {
	        root = Insert(data, root);
	    }	
};
		template<class T2>
		bool isSubtree(BSTNode<T2> *n, BSTNode<T2> *S)
		{
		    if (S == NULL)
		        return true;
		
		    if (n == NULL)
		        return false;
		
		    if (isSame(n, S))
		        return true;
		
		    return isSubtree(n->left, S) ||
		           isSubtree(n->right, S);
		}

		template<class T2>
		bool isSubTree(BSTFCI<T2>* t1, BSTFCI<T2>* t2)
		{
		    return isSubtree(t1->root, t2->root);
		}
		template<class T2>
		bool isSame(BSTNode <T2>* s, BSTNode <T2>* a)
		{
				    if(s==NULL && a==NULL)
				        return true;
				    if(s==NULL || a==NULL)
				        return false;
				    if(s->key!=a->key)
				        return false;
				
				    return isSame(s->left,a->left) && isSame(s->right,a->right);
		}
		template<class T2>
		bool isBalance(BSTNode <T2>*node)
				{
					int l,r;
					if(node==NULL)
					{
						return true;
					}
					l=height(node->left);
					r=height(node->right);
					if(abs(l-r)<=1 && isBalance(node->left) && isBalance(node->right))
					{
						return true;
					}
					return false;
				}
	    template<class T2>
		int height(BSTNode <T2>*p)
		{
			if(p==NULL)
				return 0;
			else
				return 1 + max(height(p->left), height(p->right));
		}
		template<class T2>
		void largestValueInEachLevel(BSTNode <T2>* root) 
		{ 
		    // if tree is empty 
		    if (!root) 
		        return; 
		  
		    queue<BSTNode<T2>*> q; 
		    int nc, max; 
		  
		    // push root to the queue 'q' 
		    q.push(root); 
		  
		    while (1) { 
		        // node count for the current level 
		        nc = q.size(); 
		  
		        // if true then all the nodes of  
		        // the tree have been traversed 
		        if (nc == 0) 
		            break; 
		  
		        // maximum element for the current  
		        // level 
		        max = INT_MIN; 
		  
		        while (nc--) { 
		  
		            // get the front element from 'q' 
		           BSTNode<T2>* front = q.front(); 
		  
		            // remove front element from 'q' 
		            q.pop(); 
		  
		            // if true, then update 'max' 
		            if (max < front->key) 
		                max = front->key; 
		  
		            // if left child exists 
		            if (front->left) 
		                q.push(front->left); 
		  
		            // if right child exists 
		            if (front->right) 
		                q.push(front->right); 
		        } 
		  
		        // print maximum element of  
		        // current level 
		        cout << max << " "; 
		    } 
		    /*// if tree is empty 
	    if (!root) 
	        return; 
	  
	    //queue<BSTNode<T2>*> q; 
	    BSTNode<T2>* arr[5];
	    int nc, max; 
	  
	    // push root to the queue 'q' 
	    //q.push(root); 
	    arr[0]=root;
	    cout<<arr[0]<<endl;
	    while (1) { 
	        // node count for the current level 
	        nc = sizeof(arr)/sizeof(arr[0]);
	        cout<<nc<<endl;
	        // if true then all the nodes of  
	        // the tree have been traversed 
	        if (nc == 0) 
	            break; 
	  
	        // maximum element for the current  
	        // level 
	        max = INT_MIN;
			cout<<max; 
	        int i=0;
	        while (nc--) { 
	  
	            // get the front element from 'q' 
	           BSTNode<T2>* front = arr[nc]; 
	           cout<<endl<<front->key<<endl;
	            // remove front element from 'q' 
	            //q.pop(); 
	  
	            // if true, then update 'max' 
	            if (max < front->key) 
	                max = front->key; 
	  
	            // if left child exists 
	            if (front->left) 
	                //q.push(front->left); 
	                arr[i+1]=front->left;
	  
	            // if right child exists 
	            if (front->right) 
	                //q.push(front->right);
					arr[i+1]=front->right; 
	        } 
	  
	        // print maximum element of  
	        // current level 
	        cout << max << " "; 
	    } */
		} 
		/*void largest(vector<int>res, BSTNode <T2> root, int d) 
		{  
		   /*int y =sizeof(x)/sizeof(x[0]);
		    if (!root) 
		        return; 
		   
		    if (d == y ) 
		        x[d]=root->key; 
		  
		    else
		
		        x[d] = max(x[d], root->key); 
		    
		    if (!root) 
		        return; 
		   
		    if (d == res.size()) 
		        res.push_back(root->key); 
		  
		    else
		        res[d] = max(res[d], root->key); 

		   largest(res, root->left, d + 1); 
		    largest(res, root->right, d + 1); 
		    if (!root) 
		        return; 
		  
		    // Expand list size 
		    if (d == res.size()) 
		        res.push_back(root->val); 
		  
		    else
		  
		        // to ensure largest value  
		        // on level is being stored 
		        res[d] = max(res[d], root->val); 
		  
		    // Recursively traverse left and 
		    // right subtrees in order to find 
		    // out the largest value on each level 
		    largest(res, root->left, d + 1); 
		    largest(res, root->right, d + 1); 
		} 
		template<class T2>
		vector<int> largestValues(BSTNode<T2>* root) 
		{ 
		   /* int x[5];
		    if(size>=0&&size<=5)
		   { 
		    largest(x, root, 0); 
		    int a =sizeof(x)/sizeof(x[0]); 
		    for(int i = 0 ; i<a ;i++)
			{
				cout<<x[i]<<" , ";
			}
		    return ; 
			//}
			else {
	
			cout<<"Out of range "<<endl;
			}
			return ;  
		} */
		  /*vector<int> res; 
          largest(res, root, 0); 
          return res; 
      }*/
      template <class T2>
      void PrintRange(BSTNode<T2> *node, int k1, int k2)
		{
		    if ( node == NULL )
		        return ;
		    if ( k1 < node->key )
		        PrintRange(node->left, k1, k2);
		    if ( k1 <= node->key && k2 >= node->key )
		        cout<<node->key<<" ";
		    if ( k2 > node->key )
		        PrintRange(node->right, k1, k2);
		}
		template<class T2>
		long treedigitSum (BSTNode <T2> *root, int val)  
		{  
		    // Base case  
		    if (root == NULL) 
			  return 0;  
		    // Update val  
		    val = (val*10 + root->key);  
	
		    if (root->left==NULL && root->right==NULL)  
		    return val;  
		  
		    return treedigitSum(root->left, val) +  treedigitSum(root->right, val);  
		}  
	    template<class T2>  
		long digitSum (BSTNode <T2> *root)  
		{  
		    // Pass the initial value as 0 
		    // as there is nothing above root  
		    return treedigitSum(root, 0);  
		}  
template<class t>
int BSTFCI<t>::size=0 ; 
int main(int argc, char** argv) 
{
	BSTFCI <int> * Tree1 ;
	Tree1= new BSTFCI <int>();
    BSTFCI <int> * Tree2 ;
	Tree2 = new BSTFCI <int>();
    BSTFCI <int> * Tree3  ; 
	Tree3= new BSTFCI <int>();
	BSTFCI <int> * Tree5  ; 
	Tree5= new BSTFCI <int>();
	BSTFCI <int> * Tree6 ; 
	Tree6= new BSTFCI <int>(); 
	
    Tree1->Insert(5);
    Tree1->Insert(7);
    Tree1->Insert(3);
    Tree1->Insert(9);
    Tree1->Insert(4);
    Tree1->Insert(2);
    Tree1->Insert(10);
    Tree1->Insert(8);
    Tree1->Insert(1);
    Tree1->PrintTreeInOrder();
    cout<<endl;
     PrintRange(Tree1->root,3 ,6);
     cout<<endl;
     PrintRange(Tree1->root,8,15);
     cout<<endl;
     PrintRange(Tree1->root,6 ,6);
     cout<<endl;
     
    Tree2->Insert(9);
    Tree2->Insert(8);
    Tree2->Insert(10);
  
    Tree2->PrintTreeInOrder();

    Tree3->Insert(3);
    Tree3->Insert(4);
    Tree3->Insert(1);
    Tree3->Insert(0);
    Tree3->PrintTreeInOrder();
    
    Tree5->Insert(1);
    Tree5->Insert(4);
    Tree5->Insert(7);
    Tree5->Insert(5);
    Tree5->Insert(3);
    Tree5->PrintTreeInOrder();
    cout<<endl<<endl;
    Tree5->flip(Tree5->root);
     Tree5->PrintTreeInOrder();
    
      if( isSubTree(Tree1, Tree2))
	 { 
	   cout<<"True Tree2 is subTree to Tree1"<<endl<<endl;
	 }
	 else 
	  cout<<"False :( "<<endl<<endl;
	 if( isSubTree(Tree1, Tree3))
	 { 
	   cout<<"True Tree3 is subTree to Tree1"<<endl<<endl;
	 }
	 else 
	  cout<<"False :'( "<<endl<<endl ;
    
    if(isBalance(Tree1->root))
	 { 
	   cout<<"True Tree1 is Blance :D"<<endl<<endl;
	 }
	 else 
	  cout<<"False NOT BALANCE :'( "<<endl<<endl ;
	  
	Tree6->Insert(1);
    Tree6->Insert(0);
    Tree6->Insert(4);
    Tree6->Insert(5);
    Tree6->Insert(3);
    Tree6->PrintTreeInOrder();
    
    cout<<digitSum (Tree6->root)<<endl ;
    largestValueInEachLevel(Tree6->root); 
    cout<<endl;
	 BSTFCI <word> * Tree4 ;
	  Tree4= new BSTFCI <word>();
	   Tree4->get_nodes();
	   Tree4->PrintTreeInOrder();
	
	return 0;
}
