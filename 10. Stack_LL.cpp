#include <iostream>
using namespace std;

class node{
    int data;
    node *link;
    public:
    friend class stack;
    node(int d){
        data=d;
        link=NULL;
    }
};

class stack{
   node *top;
   public:
   stack(){
       top=NULL;
   }
   void push(int n);
   int pop();
   void peek();
   int isempty();
   void display();
};

void stack::push(int n){
    node *temp= new node(n);
    temp->data=n;
    temp->link=NULL;
    if(top=NULL){
        top=temp;
    }
    else{
        temp->link=top;
        top=temp;
    }
}

int stack::pop(){
    node *temp;
    int n=top->data;
    temp=top;
    top=top->link;
    delete temp;
    return n;
}



int stack::isempty(){
    if(top=NULL){
        return 1;
    }
   return 0; 
}

void stack::display(){
    node *temp;
    for(temp=top;temp!=NULL;temp=temp->link){
        cout<<temp->data<<endl;
    }
}

void stack::peek(){
    cout<<top->data;
    
}

int main(){
    stack s;
    int n,op;
    do{
        cout<<"\noperations stacks using linked list\n";
        cout<<"1)Push\n2)Pop\n3)Display\n4)peek\n5)Exit";
        cout<<"Enter option";
        cin>>op;
        
        switch(op){
            case 1: 
                    cout<<"Enter number to push";
                    cin>>n;
                    s.push(n);
                    break;
            case 2:
                    if(s.isempty()==1){
                        cout<<"stack is empty";
                    }
                    else{
                        cout<<"element popped:";
                        s.pop();
                    }
            case 3:
                    if(s.isempty()==1){
                        cout<<"stack is empty";
                    }
                    else{
                        s.display();
                    }
            case 4:
                    if(s.isempty()==1){
                        cout<<"stack is empty";
                    }
                    else{
                        s.peek();
                    }
            default: cout<<"invalid choice";
            
        }
    }while(op!=5);
    
    
}   
    






