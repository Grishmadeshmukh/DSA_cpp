#include <iostream>
using namespace std;

class array{
    int arr[100];
    int size;
    public:
        void accept();
        void display();
        void insert(int x, int pos);
        void delatpos(int pos);
        void search();
        void sum();
};

void array::accept(){
   cout<<"enter size of array: ";
    cin>>size;
    cout<<"enter elements";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

void array::display(){
    cout<<"The array is:";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void array::insert(int x, int pos){
    size++;
    for(int i=size;i>=pos;i--){
        arr[i] = arr[i - 1];
    }
    arr[pos-1]=x;
}

void array::delatpos(int pos){
    if(pos>size){
        cout<<"\n\nThis value is out of range: ";
   }
   else{
       --pos;
       for(int i=pos;i<=size-1;i++){
        arr[i]=arr[i+1];
       }
       size--;
  }
}

void array::search(){
    int x,c,pos;
    cout<<"enter element to search: ";
    cin>>x;
    for(int i=0;i<size;i++){
        if(arr[i]==x){
                        c=1;
                        pos=i+1;
                        break;
                }
    }
    if(c==0){
            cout<<"\n Element Not Found..!!";
        }
    else{
            cout<<"\n Element "<<x<<" Found At Position "<<pos;
        }
}

void array::sum(){
    int sum=0;
    for(int i=0;i<size;i++){
        sum=sum+arr[i];
    }
    cout<<"sum= "<<sum;
}


int main(){
    array arr;
    arr.accept();
    arr.display();
    //arr.insert(99,2);
    //arr.delatpos(2);
    //arr.display();
    //arr.search();
    arr.sum();
    return 0;
}

