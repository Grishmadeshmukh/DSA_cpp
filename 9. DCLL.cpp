#include<iostream>
using namespace std;

class Node{
    int data;
    Node *prev;
    Node *next;
    public:
    friend class List;
    Node(int d){
        data=d;
        prev=NULL;
        next=NULL;
    }
};

class List{
    Node *head;
    public:
    void create();
    void display();
    void insert();
    void deletenode();
    void reverse();
    void search();
    List(){
        head=NULL;
    }
};

void List::create(){
    int d;
    char ch;
    Node *ptr=head;
    do{
        cout<<"enter data for the new node";
        cin>>d;
        Node *temp=new Node(d);
       
        if(head==NULL){
         head=temp;
         head->prev=temp;
         head->next=temp;
        }
       
        else{ 
           
            head->prev->next=temp; 
            temp->prev=head->prev;
            head->prev=temp;
            temp->next=head;
           
           
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
        //cout<<"\t"<<ptr->prev<<" "<<ptr->data<<"  "<<ptr->next;
        cout<<ptr->data<<"->";
        ptr=ptr->next;
        }while(ptr->next!=head);
        cout<<ptr->data<<"->";
    //cout<<"\t"<<ptr->prev<<"  "<<ptr->data<<"  "<<ptr->next;
    }    
}

void List::insert(){
   
    Node *ptr,*temp;
    int pos,i=1,d;
    cout<<"Enter pos";
    cin>>pos;
    cout<<"Enter data to insert"<<endl;
    cin>>d;
    temp=new Node(d);
    if(pos==1){
        temp->next=head;
        temp->prev=head->prev;
        head->prev=temp;
        head=temp;
        head->prev->next=head;
    }

    else{ 
         ptr=head;
        for(i=1;i<(pos-1);i++){
            ptr=ptr->next;
        }
            temp->next=ptr->next;
            ptr->next->prev=temp;
            ptr->next=temp;
            temp->prev=ptr;
    }
}

void List::deletenode(){
    Node *ptr;
    int val;
    cout<<"Enter data to be deleted"<<endl;
    cin>>val;
    if(head==NULL){
        cout<<"list empty";
    }
    else{
    for(ptr=head;ptr->data!=val;ptr=ptr->next);
    if(ptr==head){
        head=head->next;
        head->prev=ptr->prev;
        head->prev->next=head;
        delete ptr;
    }
    else{ 
        ptr->next->prev=ptr->prev;
        ptr->prev->next=ptr->next;
        delete ptr;
    }
  }
}

void List::search(){
    char ch;
    int i=0,flag=0,d; 
    Node *ptr;
    cout<<"enter data to be searched:";
    cin>>d;
    if(head->data==d){
       // i++;
        flag=1;
    }
    else{
        i=1;
        ptr=head->next;
        while(ptr!=head){
            if(ptr->data==d){ 
                flag=1;
                i++;
                break;
            }
            else{
                i++;
                ptr=ptr->next;
            }
        }// end while
    }// end outer else
    if(flag==1){
        cout<<"found data "<<d<<" at location:"<<i;
    }
    else{
        cout<<"invalid";
    }
}

int main(){
    List li;
    li.create();
    //li.insert();
   // li.deletenode();
    li.display();
    li.search();
}




