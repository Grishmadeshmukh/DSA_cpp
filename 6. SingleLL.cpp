#include<iostream>
using namespace std;
class Node{
    
    public:
    int data;
    Node *link;
    
    friend class List;
    Node(int d){
        data=d;
        link=NULL;
    }
};
class List{
    
    public:
    Node *head;
    Node *gethead(){
    return head;
}
    void create();
    void display();
    void insert();
    void sortasc();
    void sortdesc();
    void combine(Node *p,Node *q);
    
    void deletenode();
    void deletefirst();
    void deletelast();
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
            while(ptr->link!=NULL){   //Traverse ptr to last node
                ptr=ptr->link;
             
            }
          ptr->link=temp;  
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
        ptr=ptr->link;
    }
    cout<<"NULL";
    cout<<"\nEnd of list";
}

void List::insert(){
    int pos,d;
    Node *ptr=head;
    Node *prev;
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
        temp->link=head;
        head=temp;
    }
    // between two nodes
    else{
        for(int i=1;i<pos;i++){
            prev=ptr;
            ptr=ptr->link;
        }
        prev->link=temp;
        temp->link=ptr;
    }
    
}

void List::deletenode(){
    int d;
    cout<<"enter data to be deleted";
    cin>>d;
    Node *prev,*cur;
    cur=head;
    prev=head;
    while((cur->data!=d) && (cur!=NULL)){
        prev=cur;
        cur=cur->link;
    }
    //delete first node
    if(cur==head){
        //cur=head;
        head=head->link;
        delete cur;
    }
    //delete otherwise
    else{
        prev->link=cur->link;
        delete cur;
    }
}

void List::deletefirst(){
    Node *ptr= head;
    //ll empty
    if(head==NULL){
        cout<<"\nList is empty";
    }
    //delete first element
    ptr=head;
    head=head->link;
    delete ptr;
}

void List::deletelast(){
    Node *current, *previous;
    current=head;
    while(current->link!=NULL)
    {
      previous=current;
      current=current->link;	
    }
    //tail=previous;
    previous->link=NULL;
    delete current;
}

void List::sortasc(){
    Node *p1,*p2;
    int i,c=0;
    p1=head;
    while(p1!=NULL){
        c++;
        p1=p1->link;
    }
    for(i=1;i<c;i++){
        p1=head;
        p2=p1->link;
        for(int j=0;j<c-1;j++){
            if(p1->data>p2->data){
                int temp=p1->data;
                p1->data=p2->data;
                p2->data=temp;
                
            }
            p1=p2;
            p2=p2->link;
        }
    }
    
}

void List::sortdesc(){
    Node *p1,*p2;
    int i,c=0;
    p1=head;
    while(p1!=NULL){
        c++;
        p1=p1->link;
    }
    for(i=1;i<c;i++){
        p1=head;
        p2=p1->link;
        for(int j=0;j<c-1;j++){
            if(p1->data<p2->data){
                int temp=p1->data;
                p1->data=p2->data;
                p2->data=temp;
                
            }
            p1=p2;
            p2=p2->link;
        }
    }
    
}



void List::combine(Node *p,Node *q){
    Node *ptr = p;
    while (ptr->link!= NULL) {
        p=p->link;
    }
 p->link=q;
    while(ptr!=NULL){
     cout<<ptr->data;
     ptr=ptr->link;
 }
    
}


int main(){
    List li,l1,l2,l3;
    Node *p,*q;
   // li.create();
   // li.display();
   // li.insert();
    //li.display();
   //li.deletenode();
    //li.deletefirst();
    //li.display();
   // li.deletelast();
   //li.sortasc();
  // li.sortdesc();
  l1.create();
 l1.display();
  l2.create();
   l2.display();
  p=l1.gethead();
  q=l2.gethead();
   l1.combine(p,q);
   l1.display();
// cout<<p->data;
   
    
}




