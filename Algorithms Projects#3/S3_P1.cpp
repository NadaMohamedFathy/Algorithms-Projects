#include <iostream>
using namespace std;
struct Node  
		{  
		    public: 
		    int info;  
		    Node *left;  
		    Node *right;  
		    int height;  
		};
		Node* node;  
class avlTree
{
    public:
    	 avlTree()
        {
            node = NULL;
        }
        int height(Node *p)
		{
			if(p==NULL)
				return 0;
			else
				return 1 + max(height(p->left), height(p->right));
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
        int diff(Node *p)
		{
			if(p==NULL)
				return 0;
			else
				return height(p->left) - height(p->right);
		}
		Node* rr_rotation(Node *parent)
		{
		    Node *temp;
		    temp = parent->right;
		    parent->right = temp->left;
		    temp->left = parent;
		    return temp;
		}
		Node* ll_rotation(Node *parent)
		{
		    Node *temp;
		    temp = parent->left;
		    parent->left = temp->right;
		    temp->right = parent;
		    return temp;
		}
		Node* lr_rotation(Node *parent)
		{
		    Node *temp;
		    temp = parent->left;
		    parent->left = rr_rotation (temp);
		    return ll_rotation (parent);
		}
		Node* rl_rotation(Node *parent)
		{
		    Node *temp;
		    temp = parent->right;
		    parent->right = ll_rotation (temp);
		    return rr_rotation (parent);
		}
        Node* balance(Node *temp)
		{
		    int bal_factor = diff (temp);
		    if (bal_factor > 1)
		    {
		        if (diff (temp->left) > 0)
		            temp = ll_rotation (temp);
		        else
		            temp = lr_rotation (temp);
		    }
		    else if (bal_factor < -1)
		    {
		        if (diff (temp->right) > 0)
		            temp = rl_rotation (temp);
		        else
		            temp = rr_rotation (temp);
		    }
		    return temp;
		}
        void inorder(Node* tree)
		{
		    if (tree == NULL)
		        return;
		    inorder (tree->left);
		    cout<<tree->info<<"  ";
		    inorder (tree->right);
		}
		void preorder(Node *tree)
		{
		    if (tree == NULL)
		        return;
		    cout<<tree->info<<"  ";
		    preorder (tree->left);
		    preorder (tree->right);
		 
		}
		void postorder(Node *tree)
		{
		    if (tree == NULL)
		        return;
		    postorder ( tree ->left );
		    postorder ( tree ->right );
		    cout<<tree->info<<"  ";
		}
		Node* insert(int value)
		{
		    node=insert(node, value);
		    return node;
		}
		Node* insert(Node *root,int value)
		{
		    if (root == NULL)
		    {
		        root = new Node;
		        root->info = value;
		        root->left = NULL;
		        root->right = NULL;
		        return root;
		    }
		    else if (value < root->info)
		    {
		        root->left = insert(root->left, value);
		        root = balance (root);
		    }
		    else if (value >= root->info)
		    {
		        root->right = insert(root->right, value);
		        root = balance (root);
		    }
		    return root;
		}
		Node * minValueNode(Node* node)
		{
			Node* current = node;
			while (current->left != NULL)
				current = current->left;
			return current;
		}

		void remove(int k)
		{
			node=deleteNode(node,k); 
		}
		Node* deleteNode(Node* nptr, int k )
		{
			if(nptr == NULL)
			{
				cout << "Key: " << k << " not found" << endl;
				return nptr;
			}
	 
	    	if(k < nptr->info)
			{
				nptr->left = deleteNode(nptr->left, k);
			}
	 	   	else if(k > nptr->info)
			{
	        	nptr->right = deleteNode(nptr->right,  k);
			}
	    	else
			{
	        	// node with only one child or no child
	        	if( (nptr->left == NULL) || (nptr->right == NULL) )
				{
	            	Node *temp = nptr->left ? nptr->left : nptr->right;
	            	// No child case
	            	if(temp == NULL){
	                	temp = nptr;
	                	nptr = NULL;
	            	}
	            	else
					{ // One child case 
						*nptr=*temp;
						delete temp;
	        		}
				}
	        	else
				{
	            	// node with two children, Get the inorder successor (smallest in the right subtree)
	            	Node* temp = minValueNode(nptr->right);
					*nptr=*temp;
	            	// Copy the inorder successor's data to this node
					// Delete the inorder successor
	            	nptr->right = deleteNode(nptr->right, temp->info );
	        	}
	    	}
	 
	 	   if (nptr == NULL)	// If the tree had only one node then return
	 	        return nptr;
			nptr=balance(nptr); //balance the tree after deletion
		}
};
int main(int argc, char** argv) {
	avlTree tree;
	tree.insert(5);
	tree.insert(9);
	tree.insert(7);
	tree.insert(10);
	tree.insert(20);
	tree.insert(80);
	tree.insert(6);
	tree.insert(35);
	cout<<"Display Balanced AVL Tree: "<<endl;
	cout<<"a.InOrder : "<<endl;
	tree.inorder(node);
	cout<<endl<<"b.PostOrder : "<<endl;
	tree.postorder(node);
	cout<<endl<<"c.PreOrder : "<<endl;
	tree.preorder(node);
	cout<<endl<<endl;
	tree.remove(20);
	cout<<"Display Balanced AVL Tree: "<<endl;
	cout<<"a.InOrder : "<<endl;
	tree.inorder(node);
	cout<<endl<<"b.PostOrder : "<<endl;
	tree.postorder(node);
	cout<<endl<<"c.PreOrder : "<<endl;
	tree.preorder(node);
	cout<<endl<<endl;
	tree.remove(9);
	cout<<"Display Balanced AVL Tree: "<<endl;
	cout<<"a.InOrder : "<<endl;
	tree.inorder(node);
	cout<<endl<<"b.PostOrder : "<<endl;
	tree.postorder(node);
	cout<<endl<<"c.PreOrder : "<<endl;
	tree.preorder(node);
	cout<<endl;
	return 0;
}
