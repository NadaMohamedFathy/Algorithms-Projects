#include <bits/stdc++.h> 
using namespace std; 

class node 
{ 
	public: 
	char data; 
	node* left; 
	node* right; 
}; 

/* Prototypes for utility functions */
int search(string arr, int strt, int end, char value); 
node* newNode(char data); 

node* buildTree(string pre, string in, int inStrt, int inEnd) 
{ 
	static int preIndex = 0; 

	if (inStrt > inEnd) 
		return NULL; 


	node* tNode = newNode(pre[preIndex++]); 

	if (inStrt == inEnd) 
		return tNode; 
	int inIndex = search(in, inStrt, inEnd, tNode->data); 
	tNode->left = buildTree(pre, in, inStrt, inIndex - 1); 
	tNode->right = buildTree(pre, in, inIndex + 1, inEnd); 

	return tNode; 
} 

int search(string arr, int strt, int end, char value) 
{ 
	int i; 
	for (i = strt; i <= end; i++) 
	{ 
		if (arr[i] == value) 
			return i; 
	} 
} 

node* newNode(char data) 
{ 
	node* Node = new node(); 
   Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 

	return(Node); 
} 
/*void printPostorder(node snode) 
{ 
	if (snode == NULL) 
	return; 
	printPostorder(snode->left); 
	printPostorder(snode->right);
	cout<<snode->data; 	 
} */
void postorder( node *root) {
   if (root != NULL) {   
      postorder(root->left);
      postorder(root->right);
      if(root->data!=0)
      cout<<root->data<<" ";
   }
}  
void printPostOrder(string pre , string in) 
{   
     int len = sizeof(in) / sizeof(in[0]); 
     node* root =  buildTree(pre, in, 0, len );
    cout << "postorder traversal of the constructed tree is \n"; 
	postorder(root); 
} 
/* Driver code */
int main() 
{ 
	string pre = "ABFGC"; 
	string in = "FBGAC";
	printPostOrder(pre,in);
	cout<<endl;
	/*string pre1 = "AWKLD"; 
	string in1 = "KWLAD";
	printPostOrder(pre1,in1);
	cout<<endl;*/

}
