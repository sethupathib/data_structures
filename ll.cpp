//Linked List Implementation
//fully_correct
//Wow, This feels really good.
//Here, push is equivalent to insertAfter(&head,1,new_data)
//i.e if n=1, push operation is performed

#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node* next;
};

//write  3 functions
/* one for inserting a node in the beginning
one for inserting a node at the nth position
one for inserting a node at the end
*/

void push(Node** head, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
	
	}

//void insertAfter(Node* prev_node, int new_data)
//{
//	if(prev_node == NULL)
//	{
//		cout<<"previous node can not be null"<<endl;
//		return;
//		}
//	Node* new_node = new Node();
//	new_node->data = new_data;
//	new_node->next=prev_node->next;
//	prev_node->next = new_node;
//}


void insertAfter(Node** head, int n, int new_data)
{
	Node * new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;

	if(n==1)
	{
		new_node->next = *head;
		*head = new_node;
		return;
		}
	Node * temp = *head;

	for(int i=0;i<n-2;i++)
	{
		temp= temp->next;
		}

	new_node->next = temp->next;
	temp->next = new_node;

}

	

void append(Node** head, int new_data)
{
	Node* new_node = new Node();
	Node* last = *head;
	new_node->data = new_data;
	new_node->next = NULL;

	if(*head == NULL)
	{
		*head = new_node;
		return;
		}

//linked list traversal
	while(last->next!=NULL)
	{
		last= last->next;
		}
	last->next = new_node;	
	return;
	}




//Function for deleting a node 

void deleteNode (Node** head,int n)
{
	Node *temp = *head;
	if (n==1)
	{
		*head= temp->next;
		delete temp;
		return;
		}

	for (int i=0;i<n-2;i++)
	{
		temp = temp->next;
		Node* temp1 = temp->next;
		temp->next = temp1->next;
		delete temp1;
		}

	
	}

//function to reverse the linked list
void reverse(Node** head)

{
	Node* current;
	Node* next1;
	Node* prev;
	current = *head;
	prev = NULL;
	while(current !=NULL)
	{

		next1 = current->next;
		current->next = prev;
		prev = current;
		current=next1;
	}
	*head = prev;
	}





//printList Function

void printList(Node* n)
{
	while(n!=NULL)
		{
			cout<<n->data<<"->";
			n=n->next;
			}
		}



//driver code

int main()
{
	Node* head = NULL;
	append(&head,6); 	//6->NULL
	push(&head,7);		//7->6->NULL
	push(&head,1);		//1->7->6->NULL
	append(&head,4);	//1->7->6->4->NULL
	insertAfter(&head,1,8); //1->7->8->6->4->NULL     //explanation 1 is head, head->next is 7. so insert 8 after 7.
	//this implementation of inserting a node @ nth position is not the best.
	append(&head,111);
	push(&head,1000);
	printList(head);
	deleteNode(&head,3);
	reverse(&head);
	cout<<"\n"<<"Reversed List is -->\n"<<endl;
	printList(head);
	return 0;
	}

