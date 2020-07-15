//write functions for push and pop first 
//then implement reverse function using stack (reversing the linked list)


#include <bits/stdc++.h>
using namespace std;
#include <stack>


class Node {
	public:
	int data;
	Node* next;
};

void Push(Node** head, int new_data )
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
	}


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

void printList(Node* n)
{
	while(n!=NULL)
		{
			cout<<n->data<<"->";
			n=n->next;
			}
		}



void reverse(Node** head)
{
	if(*head==NULL) return;
	stack<Node*> S;
	Node* temp =*head;
	while(temp!=NULL)
	{
		S.push(temp);
		temp=temp->next;
		}
		temp=S.top(); *head= temp;
		S.pop();
		while(!S.empty()){
			temp->next = S.top();
			S.pop();
			temp = temp->next;
		}
		temp->next = NULL;
}




int main()
{
	Node* head = NULL;
	//append(&head,6); 	//6->NULL
	Push(&head,7);		//7->6->NULL
	Push(&head,1);		//1->7->6->NULL
//	append(&head,4);	//1->7->6->4->NULL
//	insertAfter(&head,1,8); //1->7->8->6->4->NULL     //explanation 1 is head, head->next is 7. so insert 8 after 7.
	//this implementation of inserting a node @ nth position is not the best.
//	append(&head,111);
	Push(&head,1000);
	printList(head);
//	deleteNode(&head,3);
	reverse(&head);
	cout<<"\n"<<"Reversed List is -->\n"<<endl;
	printList(head);
	cout<<"\n";
//	recurfprint(head);
	cout<<"\n\n";
//	recurrprint(head);
	cout<<"\n";
	//reverse_recur(&head,head);
	return 0;
	}







_______________________________________________________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100


class Stack
{
	private:
	
	int A[MAX_SIZE];
	int top;
	

	public:
	
	Stack()
	{
	top = -1;
	}


	void push(int n)
	{
		if(top==MAX_SIZE-1)
		{
			cout<<"stack overflow"<<endl;
			return;
			}

			A[++top] = n;
			
			}
int Top()
{
	return A[top];
	}



	int IsEmpty()

	{

		if(top == -1) return 1;

		return 0;

	}




	void pop()
	{
		if(top==-1)
			{
				cout<<"stack empty";
				}
			top--;	

			}


	void print()
	{

		cout<<"Stack now is:"<<endl;
		for(int i=0;i<=top;i++)
		{
			//printf("%d \t\n",A[i]);
			cout<<"\t\n"<<A[i];
			
			}
			
			}
};



int main()

{
	Stack S;
	S.push(12);
	S.print();
	
	S.push(11);
	S.print();

	S.push(10);
	S.print();
	
	S.pop();

	S.push(121);
	S.print();
	
	cout<<"top is :"<<S.Top()<<endl;
return 0;
}
___________________________________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;

class Node  
{
	public:
	int data;
	Node* next;
	};

	void push(Node** head, int new_data)
	{
		Node* new_node = new Node();
		new_node->data = new_data;
		if(*head ==NULL)
		{
		new_node->next = NULL;
		*head = new_node;
		return;
		}
		
		new_node->next = *head;
		*head = new_node;
		
		
		}

	void pop(Node **head)
	{
		Node* temp;
		temp = *head;
		*head = temp->next;
		delete temp;
		}


	void print (Node *n)
	{
		cout<<"The elements in the stack are :\t"<<endl;
		if(n==NULL)
		{
			cout<<"stack empty"<<endl;
			return;
			}

		while(n!=NULL)
		{
			cout<<n->data<<"\n";
			n=n->next;
			}
		}

//driver code


int main()
{
	Node *head = NULL;
	push(&head, 10);
	push(&head, 11);
	push(&head, 12);
	push(&head, 13);
	print(head);
	cout<<"After popping one element from top \n";
	pop(&head);
	print(head);
	
	return 0;
	}





________________________________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <string>

void Reverse(char C[], int n)
{
	stack<char> S;
	
	//push
	for(int i=0;i<n;i++)
	{
		S.push(C[i]);
		}

	//pop

	for(int i=0;i<n;i++)
	{
		C[i] = S.top();
		S.pop();
		}

	}






int main()
{
	char C[100];
	cout<<"Enter a string"<<endl;
	fgets(C,sizeof(C),stdin);

	Reverse(C,strlen(C));
	printf("Output is %s",C);

		return 0;
	}


______________________________________________________________________________________________________________