#include<iostream>
#include<math.h>
using namespace std;

class Node{
    int coeff;
    int expo;
    Node *link;
    public:
    friend class Poly;
    Node(){
       coeff=0;
        expo=0;
        link=NULL; 
    }
    Node(int c,int e){
        coeff=c;
        expo=e;
        link=NULL;
    }
};

class Poly{
    public:
    Node *head;
    
    void create();
    void display();
    Node gethead();
    int eval(int x);
    void add(Poly p1, Poly p2,Poly pr);
    Poly(){
        head=NULL;
    }
};

void Poly::create(){
    int c,e;
    char ch;
    Node *ptr;      
    do{
        cout<<"Enter data";
        cout<<"Enter coefficient";
        cin>>c;
        cout<<"Enter exponent";
        cin>>e;
        Node *temp=new Node(c,e);  
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
void Poly::display(){
    Node *ptr=head;
    if(head==NULL){
        cout<<"\nList is empty";
    }
    cout<<"\nList contains\n";
    while(ptr!=NULL){
        cout<<"("<<ptr->coeff<<"x^"<<ptr->expo<<")->";
        ptr=ptr->link;
    }
    cout<<"NULL";
    cout<<"\nEnd of list";
}

int Poly::eval(int x)
{
    Node *temp=head;
    int res=0;
    while(temp!=NULL)
    {
        res+=(temp->coeff)*pow(x,temp->expo);
        temp=temp->link;
    }
    cout<<"\nResult : "<<res;
}






int main(){
    int x;
    Poly p;
    p.create();
    p.display();
    cout<<"enter x: ";
    cin>>x;
    p.eval(x);
     
    
}




