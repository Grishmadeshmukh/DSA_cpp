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
        if(head==NULL)
            head=temp;
        else{
            ptr=head;
            while(ptr->next!=NULL){   //Traverse ptr to last node
                ptr=ptr->next;
            }
          ptr->next=temp;
          temp->prev=ptr;
        }
        cout<<"Do you want to continue?(y/n)";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}

void List::display(){
    Node *ptr=head;
    if(head==NULL){
        cout<<"\nList is empty";
    }
    cout<<"\nList contains\n";
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"\nEnd of list";
}

void List::insert(){
    int pos,d;
    Node *ptr=head;
    Node *p;
    cout<<"Enter data for the new node to be inserted: ";
    cin>>d;
    cout<<"Enter position where node should be inserted: ";
    cin>>pos;
    Node *temp= new Node(d);
    // ll is empty
    if (head == NULL) { 
        head = temp;
        cout << "Node Appended" << endl;
    }
    //pos=1
    if(pos==1){
        temp->next=head;
        head->prev=temp;
        head=temp;
        temp->prev=NULL;
}
    // between two nodes
    else{
        for(int i=1;i<pos;i++){
            p=ptr;
            ptr=ptr->next;
        }
        p->next=temp;
        temp->prev=p;
        temp->next=ptr;
    }
    
}

void List::deletenode(){
    int d;
    cout<<"enter data to be deleted";
    cin>>d;
    Node *p,*c;
    c=head;
    p=head;
    while((c->data!=d) && (c!=NULL)){
        p=c;
        c=c->next;
    }
    //delete first node
    if(c==head){
        //cur=head;
        head=head->next;
        head->prev=NULL;
        delete c;
    }
    //delete last node
    if(c->next==NULL){
        (c->prev)->next=NULL;
        delete c;
    }
    //delete node in between
   else{
        p->next=c->next;
        (c->next)->prev=p;
        delete c;
    } 
    
}

void List::reverse(){
    Node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    cout<<ptr->data<<"->";
    while(ptr!=head){
        ptr=ptr->prev;
        cout<<ptr->data<<"->";
    }
}

int main(){
    List li;
    li.create();
    li.display();
    //li.insert();
    //li.deletenode();
    li.reverse();
    //li.display();
}


