
#include <iostream>
#include <cmath>
using namespace std;

class term{  
    public:
    int coeff,deg;
};

class poly{
   int n;
   term t[20];
   public:
        void accept();
        void display();
        void add(poly a,poly b);
        void multiply(poly p1,poly p2);
        void eval();
};

void poly::accept(){
    cout<<"enter number of terms: ";
    cin>>n;
    cout<<"Enter coeffs and exponents"<<endl;
    for(int i=0;i<n;i++){
        cout<<"enter coeff: ";
        cin>>t[i].coeff;
        cout<<"enter exponent: ";
        cin>>t[i].deg;
    }
}

void poly::display(){
    cout<<t[0].coeff<<"x^"<<t[0].deg;
    for(int i=1;i<n;i++){
        cout<<" + ";
        if(t[i].coeff<0){
            cout<<"("<<t[i].coeff<<")";
        }
        else{
            cout<<t[i].coeff;
        }
        cout<<"x^"<<t[i].deg;
    }
    cout<<"\n"; 
}

void poly::eval(){
    int x,ans=0;
    cout<<"enter value of x: ";
    cin>>x;
    for(int i=0;i<n;i++){
        ans=ans+ t[i].coeff*(pow(x,t[i].deg));
    }
    cout<<"result is: "<<ans;
    
}

void poly::add(poly a,poly b){

int i=0,j=0,k=0,n1,n2;
//this->n=n;
n1=a.n;
n2=b.n;
cout<<"addition result: ";
//cout<<n1<<"  "<<n2<<"\n";
while(n1>0 && n2>0){
    if(a.t[i].deg==b.t[j].deg){
        t[k].coeff=a.t[i].coeff+b.t[j].coeff;
        t[k].deg=a.t[i].deg;
        i++;
        j++;
        k++;
        n1--;
        n2--;
        n++;
    }
    else
    if(a.t[i].deg>b.t[j].deg){
           t[k].deg=a.t[i].deg;
            t[k].coeff=a.t[i].coeff;
            i++;
            k++;
            n1--;
            n++;

    }
    else
    if(a.t[i].deg<b.t[j].deg){
            t[k].deg=b.t[j].deg;
            t[k].coeff=b.t[j].coeff;
            j++;
            k++;
            n2--;
            n++;

    }
}
while(n1>0){
         t[k].deg=a.t[i].deg;
        t[k].coeff=a.t[i].coeff;
n1--;
k++;
i++;
n++;

}
while(n2>0){
     t[k].deg=b.t[j].deg;
      t[k].coeff=b.t[j].coeff;
            j++;
            k++;
            n2--;
            n++;
}
//cout<<n<<"\n";
//cout<<sum.t[0].coeff<<"\n";
//return *this;
}

void poly::multiply(poly p1,poly p2){
        int terms,j,i,k=0,l=0;
    poly p3,p4;
    for(i=0;i<p1.n;i++){
        for(j=0;j<p2.n;j++){
            p3.t[k].coeff=p1.t[i].coeff*p2.t[j].coeff;
            p3.t[k].deg=p1.t[i].deg+p2.t[j].deg;
            k++;
        }
    }
    p3.n=k;
    int flag;
    for(i=0;i<p3.n;i++){
        flag=0;
        for(j=i+1;j<p3.n;j++){
            if(p3.t[i].deg==p3.t[j].deg){
                p4.t[l].coeff=p3.t[i].coeff+p3.t[j].coeff;
                p4.t[l].deg=p3.t[i].deg;
                l++;
                i++;
                flag=1;
            }
        }
        if(flag==0){
            p4.t[l].coeff=p3.t[i].coeff;
            p4.t[l].deg=p3.t[i].deg;
            l++;
        }
    }
    p4.n=l;
    cout<<"Final poly is: ";
    p4.display();



}

int main(){
    poly a,b,ans;
    a.accept();
    a.display();
    b.accept();
    b.display();
    
    //ans.add(a,b);
    //ans.multiply(a,b);
    //a.eval();
    return 0;
}

//a= 5x^2 + 7x - 2
//b = 10x + 3
// a+b = (5x^2 + 17x +1)     ab=(50x^3 + 85x^2 + 1x -6 )

