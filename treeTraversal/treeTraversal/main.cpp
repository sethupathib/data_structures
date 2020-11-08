//
//  main.cpp
//  treeTraversal
//
//  Created by Sethupathi on 06/11/20.
//  Copyright © 2020 Sethupathi. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;


class Node {
public:
  
    int data;
    Node* left;
    Node* right;
};

Node* getNode(int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->left=new_node->right=NULL;
    return new_node;
}

void inOrder(Node* root)
{
    if(root==NULL) return;
    
    inOrder(root->left);
    cout<<root->data<<"-->";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<"-->";
}

void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
    
}

void levelOrder(Node* root)
{
    if(root==NULL) return;
    
    queue<Node*> Q;
    Q.push(root);
//    Q.push(root);
    while(!(Q.empty())){
        Node* current = Q.front();
        cout<<current->data<<"-->";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
        
    }
}

Node* Insert(Node* root, int data )
{
    
    if(root==NULL){
        root = getNode(data);
    }
    
    else if(data<=root->data){
        root->left = Insert(root->left,data);
    }
    else
        root->right = Insert(root->right,data);
    
    return root;
}


int main(int argc, const char * argv[]) {
    Node* root = NULL;
    root = Insert(root,1);
    root = Insert(root,0);
    //root = Insert(root,30);
    root = Insert(root,4);
    root = Insert(root,5);
    levelOrder(root);

    return 0;
}
