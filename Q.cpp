#include<iostream>
using namespace std;
template <typename T>

class Node
{
	public:
		T data;
		Node<T> *next;
		Node(int d=0,Node *n=0)
		{
			data=d;
			next=n;
		}	
};
template <typename T>
class Queue
{
	public:
		Node<T> *front;
		Node<T> *rear;
		Queue()
		{
			front=0;
			rear=0;
		}
		void display()
		{
			if(front==0){
				cout<<"underflow !!!"<<endl;
			}
			else{
				Node<T> *temp;
				temp=front;
				while(temp!=0){
					cout<<temp->data<<" ";
					temp=temp->next;
				}
			}
			cout<<endl;
		}
		void enqueue(T data)
		{
			Node<T>* p=new Node<T>(data);
			if(isEmpty())
			{
				front=rear=p;
			}
			rear->next=p;
				rear=p;
				rear->next=0;			
		}
		T dequeue()
		{
			if(isEmpty())
			throw "underFlow !!! ";
			else if(front ==rear)
			{
				Node<T> *temp= front;
				front= front->next;
				T x=temp->data;			
				delete temp;
				front =rear=0;
				return x;	
			}
			else
			{
				Node<T> *temp= front;
				front= front->next;
				T x=temp->data;			
				delete temp;
				return x;
			}
		}
		
		bool isEmpty()
		{
			if(front ==0)
			return true;
			else{
				return false;
			}
		}
		T getfront()
		{
			return front->data;
		}
		
		T dequeueRear()
		{
			T x;
			Node<T> *temp= front;
			if(isEmpty())
				throw "Empty Queue!!! ";
			else if(front ==rear)
			{
				x=rear->data;			
				front =rear=0;	
			}
			else
			{
				while(temp->next!=rear)
				temp= temp->next;
				x= rear->data;
				delete rear;
				rear=temp;			
		}
			delete temp;
			return x;
		}

		void insertFront(T data)
		{
			Node<T>* p=new Node<T>(data);
			if(Queue::isEmpty())
			{
				front=rear=p;
			}
			p->next=front;
			front=p;	 		
		}					
};

