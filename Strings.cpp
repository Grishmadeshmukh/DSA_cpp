/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class stg{
    char s[10];
    int len;
    public:
    stg(){
        len=0;
    }
    void read();
    int length();
    void copy();
    void reverse();
    void concatenate(stg str);
    int compare(stg s1, stg s2);
    void substring(stg str);
    void palindrome();
};

void stg::read(){
    cout<<"enter string: ";
    cin>>s;
    length();
}

int stg::length(){
    for(int i=0;s[i]!='\0';i++){
        len++;
    }
  //  cout<<"length of string is: "<<len;
    return len;
}

void stg::copy(){
   stg s2;
   int i=0;
   cout<<"original string is: "<<s;
   for(i=0;s[i]!='\0';i++){
       s2.s[i]=s[i];
   }
   s2.s[i]='\0';
   cout<<"copied string is: "<<s2.s;
}

void stg::reverse(){
    char c;
    int l=0;
    for(int p=0;s[p]!='\0';p++){
        l++;
    }
     for(int i=0;i<l/2; i++){
        c=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=c;
    }
    cout<<"reversed string is: "<<s;
}

void stg::concatenate(stg str){
    int l=0,i;
    for(int p=0;s[p]!='\0';p++){
        l++;
    }
    for(i=0;str.s[i]!='\0';i++){
        s[l]=str.s[i];
        l++;
    }
    s[l]='\0';
    cout<<"new concatenated string is: "<<s;
}

int stg::compare(stg s1, stg s2){
    int i=0;
    if(s1.length()!=s2.length()){
        return 0;
    }
    else{
        while(s1.s[i]==s2.s[i] && s1.s[i]!='\0' && s2.s[i]!='\0'){
            ++i;
        }
        if(s1.s[i]=='\0' && s2.s[i]=='\0'){
                return 1;
        }
        else{
                return 0;
        }
    }
}

void stg::palindrome(){
    int flag=0;
    int l=0,len=0;
    for(int p=0;s[p]!='\0';p++){
        len++;
    }
    int h=len-1;
    while (h>l) { 
        if (s[l++]!=s[h--]) { 
            cout<<"is Not Palindrome"; 
            return; 
        } 
    } 
    cout<<" is palindrome"; 
}

void stg::substring(stg str){
     int i,j=0,f=0,count=0;
    //int i,j=0,temp,flag=0,count=0;
    for(i=0;str[i]!='\0'|| s2.str[j]!='\0';i++){
       if(s[i] == str.s[j]){
            j++;
        }
        else{ 
            j = 0; 
        } 
        if(str.s[j]=='\0'){
            flag=1;
            count++;
        }
    }
    
    if(flag==1)
        //cout<<"number of occurence of substring: "<<count;
        cout<<"Substring found at position "<< i-j;
    else
      cout<<"Substring not found";
}

int main(){
    stg s,str;
    s.read();
   // s.length();
   // s.copy();
   // s.reverse();
    str.read();
   // str.length();
    //s.concatenate(str);
  //int x= s.compare(s,str);
 // cout<<x;
   // s.palindrome();
    s.substring(str);
    return 0;
}



