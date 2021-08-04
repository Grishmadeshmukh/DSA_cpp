#include <iostream>
using namespace std;
class Queue {
  int front,rear;
  int arr[5];
 
  public:
    Queue() {
      front = -1;
      rear = -1;
    }
        int isfull();
        int isempty();
        void enq();
        int deq();
        void display();
        int count();
};


int Queue::isempty(){  //returns 1 if empty
    if(front==-1 && rear==-1){ // || front==rear+1)
      	return 1;  
    }
    else{return 0;}
	
}

int Queue::isfull(){  //returns 1 if full
    if((front==0 && rear==4) ||(rear + 1) % 5 == front){ return 1;}
    else{ return 0;}
}

void Queue::enq(){
    int n;
    if(isfull()==1){
        cout<<"Queue is full";
    }
    
    else if(isempty()==1){
        cout<<"Enter value to enqueue: ";
        cin>>n;
        front=0;
        rear=0;
        arr[rear]=n;
    }
    else{
        cout<<"Enter value to enqueue: ";
        cin>>n;
         rear = (rear + 1) % 5;
        arr[rear]=n;
    }
}

int Queue::deq(){
    int x;
    if(isempty()==1){
        cout<<"Queue is empty";
    }
    else if (rear == front) {
      x = arr[rear];
      rear = -1;
      front = 0;
      return x;
    }
    else {
      cout << "front value: " << front << endl;
      x = arr[front];
      arr[front] = 0;
      front = (front + 1) % 5;
      return x;
    }
}

void Queue::display(){
    int c= count();
    cout << "All values in the Queue are - " << endl;
    int i= front;
    for(int i=front;i!=rear;i=(i+1)%5){
      cout << arr[i] << "  ";
    }
    cout<<arr[rear];
  }
  
int Queue::count(){
    return (rear - front + 1);
  }

int main(){
  Queue q1;
  int op;
 
  do {
    cout << "\n\nWhat operation do you want to perform? Select Option number." << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. count()" << endl;
    cout << "6. display()" << endl;
    cout << "7. Exit" << endl << endl;
 
    cin >> op;
  
   
  switch(op){
    case 1:
      cout << "Enqueue Operation:\n" << endl;
      q1.enq();
      break;
    case 2:
      cout << "Dequeue Operation \nDequeued Value : " << q1.deq() << endl;
      break;
    case 3:
      if (q1.isempty()==1)
        cout << "Queue is Empty" << endl;
      else
        cout << "Queue is not Empty" << endl;
      break;
    case 4:
      if (q1.isfull()==1)
        cout << "Queue is Full" << endl;
      else
        cout << "Queue is not Full" << endl;
      break;
    case 5:
      cout << "Count Operation \nCount of items in Queue : " << q1.count() << endl;
      break;
    case 6:
      cout << "Display Function Called - " << endl;
      q1.display();
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
}while(op!=7);
  }




