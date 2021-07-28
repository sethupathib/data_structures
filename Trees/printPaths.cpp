#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int val;
    node* left;
    node* right;
};


void printArray(int *path, int n){
    for(int i=0;i<n;i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

void printpathRecur(node* root, int * path, int pathLen){
    if(!root) return;
    path[pathLen] = root->val;
    pathLen++;
    if(!root->left and !root->right){
        printArray(path,pathLen);
    }
    printpathRecur(root->left,path,pathLen);
    printpathRecur(root->right,path,pathLen);
}

void printPaths(node* root){
    int path[100];
    printpathRecur(root,path,0);
}

node* newnode(int val){
    node* Node = new node();
    Node->val = val;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}



int main() {
    node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(2);
    root->left->left = newnode(3);
    root->left->right = newnode(5);
    root->right->left = newnode(2);
     
    printPaths(root);
	return 0;
}
