/* Queue - Circular Array implementation in C++*/

#include<iostream>

using namespace std; 

#define MAX_SIZE 101  //maximum size of the array that will store Queue. 



// Creating a class named Queue.

class Queue

{

private:

	int A[MAX_SIZE];

	int front, rear; 

public:

	// Constructor - set front and rear as -1. 

	// We are assuming that for an empty Queue, both front and rear will be -1.

	Queue()

	{

		front = -1; 

		rear = -1;

	}



	// To check wheter Queue is empty or not

	bool IsEmpty()

	{

		return (front == -1 && rear == -1); 

	}



	// To check whether Queue is full or not

	bool IsFull()

	{

		return (rear+1)%MAX_SIZE == front ? true : false;

	}



	// Inserts an element in queue at rear end

	void Enqueue(int x)

	{

		cout<<"Enqueuing "<<x<<" \n";

		if(IsFull())

		{

			cout<<"Error: Queue is Full\n";

			return;

		}

		if (IsEmpty())

		{ 

			front = rear = 0; 

		}

		else

		{

		    rear = (rear+1)%MAX_SIZE;

		}

		A[rear] = x;

	}



	// Removes an element in Queue from front end. 

	void Dequeue()

	{

		cout<<"Dequeuing \n";

		if(IsEmpty())

		{

			cout<<"Error: Queue is Empty\n";

			return;

		}

		else if(front == rear ) 

		{

			rear = front = -1;

		}

		else

		{

			front = (front+1)%MAX_SIZE;

		}

	}

	// Returns element at front of queue. 

	int Front()

	{

		if(front == -1)

		{

			cout<<"Error: cannot return front from empty queue\n";

			return -1; 

		}

		return A[front];

	}

	/* 

	   Printing the elements in queue from front to rear. 

	   This function is only to test the code. 

	   This is not a standard function for Queue implementation. 

	*/

	void Print()

	{

		// Finding number of elements in queue  

		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;

		cout<<"Queue       : ";

		for(int i = 0; i <count; i++)

		{

			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front

			cout<<A[index]<<" ";

		}

		cout<<"\n\n";

	}

};

int main()

{

	/*Driver Code to test the implementation

	  Printing the elements in Queue after each Enqueue or Dequeue 

	*/

   Queue Q; // creating an instance of Queue. 

   Q.Enqueue(2);  Q.Print();  

   Q.Enqueue(4);  Q.Print();  

   Q.Enqueue(6);  Q.Print();

   Q.Dequeue();	  Q.Print();

   Q.Enqueue(8);  Q.Print();

}




____________________________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;


//this implementation is done keeping circular arrray in mind
//write four functions
//enqueue
//dequeue
//isEmpty
//front
//isFull
#define MAX_SIZE 10

class Queue
{
private:

int A[MAX_SIZE];
int rear;
int front;

public:

Queue()
{
	//A[MAX_SIZE] = 0;
	rear=-1;
	front=-1;
	}

void Enqueue(int x)
{
	//cout<<"Enqueueing";

	if(isFull())
	{
		cout<<"Queue Full";
		return;
		}
	if(isEmpty())
	{
		front = 0;
		rear = 0;
	}

//	if((rear+1)%MAX_SIZE==front) 			//isFull Function
//	{
//		cout<<"Queue full";
//		return;
//		}
		else rear = (rear+1)% MAX_SIZE;

	A[rear] = x;
	}

bool isEmpty()
{
	
	if(rear==-1 && front ==-1)
		return true;
		return false;
		}

bool isFull()
{
	return (rear+1)%MAX_SIZE == front ? true: false;
	}

void Dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue Empty"<<endl;
		return;
		}
	else if (front==rear)
		{
			front = -1;
			rear = -1;
		}
	else
		front = (front+1)% MAX_SIZE;
}





	int Front()
	{
		return A[front];
		}


//print function

void printQ()
{
	cout<<"Queue:";
	//finding no. of elements in the queue
	int count = (rear+MAX_SIZE-front)%MAX_SIZE +1;
	for(int i=0;i<count;i++)
	{
		int index = (front+i)%MAX_SIZE;
		cout<<A[index]<<"  ";
		}cout<<"\n";
	}
};




int main()
{
	Queue Q;	
	Q.Enqueue(10); Q.printQ();
	Q.Enqueue(20); Q.printQ();
	Q.Enqueue(30); Q.printQ();
	Q.Enqueue(40);Q.printQ();
	Q.Enqueue(50);Q.printQ();
	Q.Enqueue(60);
	Q.printQ();
	Q.Dequeue();Q.printQ();
	Q.Dequeue();Q.printQ();
	//Q.Dequeue();
	cout<<"\n";
	cout<<"Queue after dequeueing \n";
	Q.printQ();
	
	
	return 0;
	}




______________________________________________________________________________________

#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node* next;
};

Node* rear = NULL;
Node* front = NULL;

//enqueue

void enqueue(int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;

	if(front==NULL && rear==NULL)
	{
		front=new_node;
		rear=new_node;
		}

	else
		rear->next = new_node;
		rear = new_node;
	
	}

void dequeue()
{
	Node* temp;
	temp = front;
	if(front==NULL)
		return;

	if(front==rear)
	{
		front=rear=NULL;
		}

	else
		front= front->next;
		delete temp;
	}
void Print() {

	struct Node* temp = front;

	while(temp != NULL) {

		printf("%d ",temp->data);

		temp = temp->next;

	}

	printf("\n");

}

	int main()
	{
		
		enqueue(10);
		enqueue(20);
		enqueue(30);
		enqueue(40);
		enqueue(50);
		Print();
		dequeue();
		dequeue();
		dequeue();
		Print();
		return 0;
		}


_____________________________________________________________________________________________