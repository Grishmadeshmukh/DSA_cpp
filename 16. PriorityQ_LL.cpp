#include <iostream>
using namespace std;

class Node {
     public:
         int data;
         int priority;
         Node * next;
         Node * prev;
        
         Node() {
             data = 0;
             priority=0;
             next = NULL;
         }
         Node(int d,int p) {
             data = d;
             priority=p;
             next = NULL;
         }
         void getdata();
         void putdata();
         friend class Queue;
};
/*
void Node::getdata(){
   cout<<"Enter data: ";
   cin>>d;
   cout<<"Enter priority: ";
   cin>>priority;
}

void Node::putdata(){
    cout<<"Data: "<<data;
    cout<<"\nPriority: "<<priority;
    
}
*/
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
         
};

int Queue::isempty(){
     if(front==NULL && rear==NULL){ return 1; }
     else{ return 0; }
}

void Queue::enq(){
     int d,p;
     char ch;
     do{
         cout<<"Enter data";
         cin>>d;
         cout<<"Enter priority: ";
         cin>>p;
         Node *temp=new Node(d,p);
         Node *ptr=front;
         if (isempty()==1){
             front = temp;
             rear = temp;
             cout<<"Node ENQUEUED successfully"<<endl;
         }
         else{  //at first position
                if (front->priority > p) { 
                    temp->next = front; 
                     front = temp; 
                }
                else { 
 
                    // position to insert new node 
                    while ((ptr->next != NULL) && (ptr->next->priority < p)) { 
                        ptr = ptr->next; 
                    } 
                    temp->next = ptr->next; 
                    ptr->next = temp; 
                } 
            } 
             
            
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
             cout<<temp->data<<",("<<temp->priority<<") -> ";
             temp=temp->next;
         }
     cout<<"end"<<endl;
     }
}


int main(){
     Queue q1;
 int ch;
 char c;
 do{
         cout << "* M E N U *" << endl;
         cout << "\n1. Enqueue\n2. Dequeue\n3. Display"<< endl;
         cout << "Enter your choice: ";
         cin >> ch;
         switch(ch){
             case 1: q1.enq();
             break;
            
             case 2: q1.deq();
             break;
            
             case 3: q1.display();
             break;
            
             default: "INVALID!";
             break;
         }
         cout << "\nDo you want to continue?" << endl;
         cin >> c;
 }while(c=='y' || c=='Y');

 return 0;
}

