#include<bits/stdc++.h>
using namespace std;
#include <queue>

//BINARY SEARCH TREE IMPLEMENTATION USING RECURSION

//write 3 functions
//getNode --> Here, root is becoming global. Hence, pointer to pointer is not used.
//insert
//search

//turned out to be a lot more than just 3 functions 

class BstNode {
	public:
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* getNode(int new_data)
{
	BstNode* new_node = new BstNode();
	new_node->data = new_data;
	new_node->left=new_node->right=NULL;
	return new_node;
	}

BstNode* Insert(BstNode* root,int new_data)
{
	if (root==NULL)
	{
		root = getNode(new_data);
				
	}

	else if(new_data<=root->data)
	{
		root->left = Insert(root->left,new_data);
		}
	else
	{
		root->right = Insert(root->right,new_data);
		}

	
	//cout<<root->data<<"\t ";
	return root;

	
	}
bool Search (BstNode* root,int data)
{
	if(root==NULL) 
		{
			return false;
		}
		
	if(root->data==data)
	{
		return true;
		}

	else if (data<=root->data)
	{
		return Search(root->left,data);
		}

	else
		return Search(root->right,data);
	}

//finding the smallest element in the BST
int findSmall(BstNode* root)
{
	BstNode* current = root;
	if(current==NULL)
		{
		cout<<"No element in the BST";
		return -1;
		}

	while(current->left!=NULL)
	{
		current=current->left;
		
		}
		return current->data;
	}

//finding the largest element in the BST
int findLarge(BstNode* root)
{
	BstNode* current = root;
	if(current==NULL)
		{
		cout<<"No element in the BST";
		return -1;
		}

	while(current->right!=NULL)
	{
		current=current->right;
		
		}
		return current->data;
	}
/*

Finding Largest using recursion

findLarge(Node *root)
{
	BstNode* current = root;
	if(current==NULL)
		{
		cout<<"No element in the BST";
		return -1;
		}

	else if (current->right==NULL)
	{

	return current->data;
		}

		return findLarge(current->right);
	}
*/

//function to return the maximum of two numbers
//int max(int left,int right)
//{
//	if(left>right)
//		return left;
//
//		return right;
//	}

//int findHeight(BstNode* root)
//{
//	int leftHeight, rightHeight,maxHeight;
//	if(root==NULL)
//		return -1;
//
//		else{
//	
//	leftHeight = findHeight(root->left);
//	rightHeight = findHeight(root->right);
//		}
//
//
//	if(leftHeight>rightHeight)
//		maxHeight = leftHeight+1;
//		else
//			maxHeight = rightHeight+1;
//	
////	cout<<leftHeight<<"\t"<<rightHeight;
//	
//	return maxHeight;
//
//}


int findHeight(BstNode* root)
{
	if(root==NULL)
		return -1;
		return max(findHeight(root->left),findHeight(root->right))+1;
		}

//level order traversal
void levelOrder(BstNode* root)
{
	if(root==NULL)
	{
		return;
		}

	
	queue <BstNode*> Q;
	Q.push(root);

	while(!(Q.empty()))
	{
		BstNode* current = Q.front();

		cout<<current->data<<" ";
		if(current->left!=NULL) Q.push(current->left);
		if(current->right!=NULL) Q.push(current->right);
		Q.pop();
		}

	
	}
// pre-order traveresal
void preOrder (BstNode* root)
{
	if(root==NULL) return;
	cout<<root->data<<endl;
	preOrder(root->left);
	preOrder(root->right);
	}

//in-order traversal

void inOrder (BstNode* root)
{
	if(root==NULL) return;
	inOrder(root->left);
	cout<<root->data<<endl;
	inOrder(root->right);
	}
//post-order traversal

void postOrder (BstNode* root)
{
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<endl;
	}

bool isBST (BstNode* root,int minValue, int maxValue)
{
	if(root==NULL) return true;

	if(root->data > minValue && root->data < maxValue && 
		isBST(root->left,minValue,root->data) &&
		isBST(root->right,root->data,maxValue))

		return true;
		else return false;
	}

BstNode* findMin(BstNode* root)


{
	while(root!=NULL) root = root->left;
	return root;
	}


BstNode* deleteNode(BstNode* root, int data)
{
	if(root==NULL) return root;

	else if (data< root->data) deleteNode(root->left,data);
	else if(data> root->data) deleteNode(root->right,data);


	else

		//case1: no child
		if(root->left==NULL && root->right==NULL)
			
			delete root;
			root=NULL;
			return root;

		//case2 : one child



		if(root->left == NULL)
			{
			BstNode* temp = root;
			root = root->right;
			delete temp;
			return root;
			}

		if(root->right==NULL)
		{
			BstNode* temp = root;
			root= root->left;
			delete temp;
			return root;
			}

		else {
			BstNode* temp = findMin (root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
			return root;
			
			}
	}

//Function to find some data in the tree

BstNode* Find(BstNode* root, int data) {

	if(root == NULL) return NULL;

	else if(root->data == data) return root;

	else if(root->data < data) return Find(root->right,data);

	else return Find(root->left,data);

}



BstNode* getSuccessor(BstNode* root, int data)

{

	BstNode* current = Find(root,data);

	if(current==NULL) return NULL;

	//case 1 : Node has a right subtree
	
		
		if(current->right!=NULL)
			return findMin(current->right);
	
	

	else {
	
		BstNode* successor = NULL;
		BstNode* ancestor = root;
		
		while(ancestor!=current)
		{
			if(current->data = ancestor->data)
			{
				successor =  ancestor;
				ancestor = ancestor->left;
				}
				else ancestor = ancestor->right;
			
			}
			return successor;
	
	}
	
	}



	int main()

	{
		BstNode* root = NULL;
		root = Insert(root,1);
		root = Insert(root,0);
		//root = Insert(root,30);
		root = Insert(root,4);
		root = Insert(root,5);

		cout<<"level Order traversal";
		levelOrder(root);

		cout<<"\n";
		cout<<"\t";
		cout<<"pre Order traversal";
		preOrder(root);
		cout<<"in Order traversal";
		inOrder(root);
		cout<<"post Order traversal";
		postOrder(root);
		cout<<"\n";
		//cout<<isBST(root,INT_MIN,INT_MAX);
		cout<<"\n";
		deleteNode(root,5);
		inOrder(root);
	cout<<"enter the number to be searched in the BST "<<endl;
	int n;
	//cin>>n;
	//if(Search(root,n)== true) cout<<"No. available";
	//else cout<<"No. not available";
	cout<<"\n";
	cout<<"Smallest Element in the BST is "<<findSmall(root)<<endl;
	cout<<"Largest Element in the BST is "<<findLarge(root)<<endl;
	cout<<"Height of the Binary Search Tree is  "<<findHeight(root)<<endl;
	cout<<"successor of 0 is"<< (getSuccessor(root,0))->data;
	return 0;
		}






