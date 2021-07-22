#include <iostream>
using namespace std;

class sparse{
        public:
            int m[20][3];
            int t,r,c;
            void accept();
            void display();
            void transpose();
            void add(sparse a,sparse b);
};

void sparse::accept(){
    int i;
    cout<<"enter no of rows\n";
    cin>>r;
    cout<<"enter no of columns\n";
    cin>>c;
    cout<<"enter no of non zero values\n";
    cin>>t;
    //this->t=t;
    m[0][0]=r;
    m[0][1]=c;
    m[0][2]=t;
    for(i=1;i<=t;i++){
        cout<<"enter row no.\n";
        cin>>m[i][0];
        cout<<"enter col no.\n";
        cin>>m[i][1];
        cout<<"enter value\n";
        cin>>m[i][2];
    }
}

void sparse::display(){
    cout<<"\n";
    for(int i=0;i<=t;i++){
        cout<<m[i][0]<<" "<<m[i][1]<<" "<<m[i][2]<<"\n";
    }
}

void sparse::transpose(){
    sparse t;
	int i,j,k,n;
	t.m[0][0]=m[0][1];
	t.m[0][1]=m[0][0];
	t.m[0][2]=m[0][2];
	
	k=1;
	n=m[0][2];
	
	for(i=0;i<m[0][1];i++){
		for(j=1;j<=n;j++){
			//if a column number of current triple==i then insert the current triple in b2
			if(i==m[j][1])
			{
				t.m[k][0]=m[j][1];
				t.m[k][1]=m[j][0];
				t.m[k][2]=m[j][2];
				k++;
			}
		}
	}
    t.display();
}

void sparse::add(sparse one,sparse two){
    int i=1,j=1,k=1,t=1;
/*this->t=t;
this->m[0][0]=one.m[0][0];
this->m[0][1]=one.m[0][0];
this->m[0][2]=k;*/
    while(i<=one.t && j<=two.t){
        if(one.m[i][0]==two.m[j][0]){
            if(one.m[i][1]==two.m[j][1]){
                this->m[k][0]=one.m[i][0];
                this->m[k][1]=one.m[i][1];
                this->m[k][2]=one.m[i][2]+two.m[i][2];
                i++;
                j++;
                k++;
                t++;
        }
        else
        if(one.m[i][1]>two.m[j][1]){
            this->m[k][0]=two.m[j][0];
                this->m[k][1]=two.m[j][1];
                this->m[k][2]=two.m[j][2];
                j++;
                k++;
                t++;
        }
        else{
                this->m[k][0]=one.m[i][0];
                this->m[k][1]=one.m[i][1];
                this->m[k][2]=one.m[i][2];
                i++;
                k++;
                t++;
    
        }
    
    
    
        }
        else
        if(one.m[i][0]>two.m[j][0]){
            this->m[k][0]=two.m[j][0];
                this->m[k][1]=two.m[j][1];
                this->m[k][2]=two.m[j][2];
                j++;
                k++;
                t++;
        }
        else{
                 this->m[k][0]=one.m[i][0];
                this->m[k][1]=one.m[i][1];
                this->m[k][2]=one.m[i][2];
                i++;
                k++;
                t++;
    
        }
    }
    while(i<one.t){
         this->m[k][0]=one.m[i][0];
                this->m[k][1]=one.m[i][1];
                this->m[k][2]=one.m[i][2];
                i++;
                k++;
                t++;
    }
    while(j<two.t){
        this->m[k][0]=two.m[j][0];
                this->m[k][1]=two.m[j][1];
                this->m[k][2]=two.m[j][2];
                j++;
                k++;
                t++;
    }
    this->t=t;
    this->m[0][0]=one.m[0][0];
    this->m[0][1]=one.m[0][1];
    this->m[0][2]=k;
    //cout<<"trial: \n"<<this->m[i][0]<<" "<<this->m[i][1]<<" "<<this->m[i][2]<<"\n";
}


int main()
{
    sparse s1,s2,s3;
   s1.accept();
   s1.display();
    s1.transpose();
    
   // s3.add(s1,s2);
  //  s3.display();
    
    return 0;
}





