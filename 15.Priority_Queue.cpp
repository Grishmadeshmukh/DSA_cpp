#include <iostream>
using namespace std;
#define MAX 10
class Job{
     public:
     int id;
     int priority;
    
     Job(){
     id = 0;
     priority = 0;
     }
     void getdata();
     void putdata();
     friend class Queue;
};

void Job :: getdata(){

 cout << "Enter job ID: ";
 cin >> id;
 cout << "Enter job priority: ";
 cin >> priority;
}

void Job :: putdata(){
 cout << "ID: " << id;
 cout << "\nPriority: " << priority << endl;
}

class Queue{
     int front, rear;
     Job q[MAX];
    
     public:
     Queue(){
     front = 0;
     rear = -1;
     }
     int empty();
     int full();
     void enqu();
     void dequ();
     void display();
};

void Queue :: enqu(){
     int i;
     if(full()){
         cout << "Queue Full!" << endl;
     }
     else{
         Job j1;
         j1.getdata();
        if(rear==-1){ //first element
             rear++;
             q[rear] = j1;
        }
        else{
             i = rear;
             while(i>=front && q[i].priority > j1.priority){
                 q[i+1] = q[i];
                 i--;
             }
             q[i+1] = j1;
             rear++;
        }
    }
}


void Queue :: dequ(){
     if(empty()){
        cout << "Queue Empty!" << endl;
     }
     else{
         cout << "\nThe Job:\n";
         q[front].putdata();
         cout << "..has been deleted!" << endl;
         front++;
     }
}


void Queue :: display(){
 int i;
 if(empty()){
    cout << "Queue Empty!" << endl;
 }
 else{
     cout << "Priority Queue : \n" << endl;
     for(i=front;i<=rear;i++){
         q[i].putdata();
         cout << "--------------\n";
     }
 }
}


int Queue :: empty(){
 if(front==-1 || front == rear+1) return 1;
 else return 0;
}

int Queue :: full(){
 if(rear == MAX-1) return 1;
 else return 0;
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
 case 1: q1.enqu();
 break;

 case 2: q1.dequ();
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
