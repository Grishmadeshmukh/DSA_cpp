#include<iostream>
using namespace std;
 
class Node {
  public:
      	int data; 
      	Node * next;
     
      Node() {
        data = 0;
        next = NULL;
      }
      Node(int d) {
        data = d;
        next = NULL;
      }
};

class Queue {
  public:
      	Node *front;
      	Node *rear;
      	Queue() {
          front = NULL;
          rear = NULL;
        }
        int isempty();
        void enq();
        void deq();
        void display();
        int count();
};

int Queue::isempty(){
    	if(front==NULL && rear==NULL){ return 1; }
    	else{ return 0; }
 }

void Queue::enq(){
     int d;
     char ch;
     do{
     cout<<"Enter data";
     cin>>d;
     Node *temp=new Node(d);
     if (isempty()==1){
        front = temp;
        rear = temp;
        cout<<"Node  ENQUEUED successfully"<<endl;
      }
      else{
      rear->next=temp;
      rear=temp;
      cout<<"Node  ENQUEUED successfully"<<endl;
    }
         cout<<"Do you want to continue?(y/n)";
         cin>>ch;
    }while(ch=='y'||ch=='Y');
 }
void Queue::deq(){
    Node *temp=NULL;
    if (isempty()==1) {
          cout << "Queue is Empty" << endl;
      } 
    else{
        if(front==rear){
          temp=front;
          front = NULL;
          rear = NULL; 
          cout<<temp->data;
          //return temp;
        }
        else{
          temp=front;
          front = front->next; 
          cout<<temp->data;
         // return temp;
        }
          
    }
}


void Queue::display() {
      if(isempty()==1){
          cout << "Queue is Empty" << endl;
      }
    else{
      cout << "All values in the Queue are :" << endl;
        Node *temp=front;
        while(temp!=NULL){
          cout<<temp->data<<" -> ";
          temp=temp->next;
      	}
      cout<<"end"<<endl;
    }
}

int Queue::count(){
      int count=0;
      Node *temp=front;
      while(temp!=NULL)
      {
        count++;
        temp=temp->next;
    	}
     cout<<"\nnumber of elements in the queue is:" <<count<<endl;
    }

int main(){
    Queue q;
    q.enq();
    q.count();
    q.display();
    q.deq();
    q.count();
    q.display();
    
}




