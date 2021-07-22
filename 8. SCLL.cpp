#include<iostream>
using namespace std;
class Node{
    int data;
    Node *link;
    public:
    friend class List;
    Node(int d){
        data=d;
        link=NULL;
    }
};
class List{
    Node *head;
    public:
    void create();
    void display();
    void insert();
   void deletenode();
   // void deletefirst();
    //void deletelast();
    List(){
        head=NULL;
    }
};

void List::create(){
    int d;
    char ch;
    Node *ptr;      
    do{
        cout<<"Enter data";
        cin>>d;
        Node *temp=new Node(d);  
        if(head==NULL){
            head=temp;
            head->link=temp;
        }
        else{
            ptr=head;
            while(ptr->link!=head){   //Traverse ptr to last node
                ptr=ptr->link;
             
            }
          ptr->link=temp;  
          temp->link=head;
        }
        cout<<"Do you want to continue?(y/n)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}

void List::display(){
    Node *ptr=head,*c;
    if(head==NULL){
        cout<<" LIST EMPTY!";
    }
    else{
      //cout << endl << "head address : " << head << endl;
      cout << "Circular Linked List Values : " << endl;
      do{
        cout<<ptr->data<<"->";
        ptr= ptr->link;

      }while(ptr!=head);
    }
}

void List::deletenode(){
    int d;
    cout<<"enter data to be deleted";
    cin>>d;
    Node *prev,*cur,*ptr;
    cur=head;
    prev=head;
    ptr=head;
     
     while((cur->data!=d) && (cur->link!=head)){
        prev=cur;
        cur=cur->link;
    }
    while(ptr->link!=head){   //ptr is on last node
        ptr=ptr->link;
        }
        
        cout<<"head"<<head->data<<" ";
        cout<<"cur"<<cur->data<<" ";
        cout<<"prev"<<prev->data<<" ";
        cout<<"ptr"<<ptr->data<<" ";
        
     //delete the only node
   if (cur->link==head) {
          delete cur;
          head=NULL;
    }
      
    //delete first node
    if(cur==head){
          ptr->link=cur->link;
          head=cur->link;
          delete cur;
    }
    
    //delete node in between
    else{
        prev->link=cur->link;
        delete cur;
    }
     
}


void List::insert(){
    int pos,d;
    Node *cur,*ptr,*prev;
    prev=head;
    cur=head;
    ptr=head;
    cout<<"Enter data for the new node to be inserted: ";
    cin>>d;
    cout<<"Enter position where node should be inserted: ";
    cin>>pos;
    Node *temp= new Node(d);
    while(ptr->link!=head){  //ptr is on last node
        ptr=ptr->link;
        }
        
    // ll is empty
    if (head == NULL) { 
        head = temp;
        cout << "Node Appended" << endl;
    }
    //pos=1
    if(pos==1){
        temp->link=head;
        ptr->link=temp;
        head=temp;
        
    }
    // between two nodes
   else{
        for(int i=1;i<pos;i++){
            prev=cur;
            cur=cur->link;
        }
        prev->link=temp;
        temp->link=cur;
    }
}

int main(){
    List li;
    li.create();
    li.display();
    //li.deletenode();
    li.insert();
    li.display();
}




