#include <iostream>
#include <cmath>
#include <string>

using namespace std;

#define n 1000

class Stack{
    int top;

    public:
        int s[n];

    Stack(){
        top=-1;
    }
    
    void push(int x);
    int pop();
    int IsFull();
    int IsEmpty();
    void display_top();
};

int Stack::IsFull(){
    if(top==n-1){   
        return 1;   
    }
    else {   
        return -1;  
    }
}

int Stack::IsEmpty(){
    if(top==-1){
      return 1;
    }
    else{
        return -1;
    }
}

void Stack::push(int x){
    if(IsFull()==1){
        cout << "Stack is Full." << endl;
    }
    else{
        ++top;
        s[top]=x;
    }
}

int Stack::pop(){
    int x;
    if(IsEmpty()==1){
        cout << "Stack is Empty." << endl;
    }
    else{
        x=s[top];
        top--;
    }
    return x;
}

void Stack::display_top(){
    if(IsEmpty()==1){
        cout << "Stack is Empty." << endl;
    }
    else{
        cout << "\nTop Element is: " << s[top] << endl;
    }
}

int check_char(char ch){
    int no=ch; //assigning ascii value
    if((no>=65 && no<=90)||(no>=97 && no<=122)){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    Stack s;
    int ch, popped;
    char op;
    do{
    cout<<endl;
    cout << "\t***MENU***" << endl;
    cout << "1. Add Element in Stack (PUSH)" << endl;
    cout << "2. Delete Top Element from Stack (POP)" << endl;
    cout << "3. Display Topmost Element from Stack()PEEK" << endl;
    cout << "4. Check if Stack is Empty." << endl;
    cout << "5. Check if Stack is Full." << endl;
    cout << "6. Evaluate value of a Postfix Expression." << endl;
    cout << "7. Exit." << endl;
    cout << "Enter your choice: ";
    cin >> ch;

    switch(ch){
        case 1:
            do{
                int y;
                cout << "\nEnter the Element to be added: " << endl;
                cin >> y;
                s.push(y);
                cout << "Element Pushed!" << endl;
                
                label: 
            
                cout<<"Want to push more elements in the stack?(y/n): ";
                cin>>op;
                
                if((op!='y'&& op!='Y') && (op!='n'&& op!='N')){
                    cout<<"Invalid response. Enter (y/n) only"<<endl;
                    goto label;
                }
                
            }while(op=='y'||op=='Y');
            break;
    
        case 2:
            popped=s.pop();
            cout << "\n"<<popped<<" removed from Stack!" << endl;
            break;
    
        case 3:
            s.display_top();
            break;
    
        case 4:
            {
                s.IsEmpty();
                if(s.IsEmpty()==1){
                    cout <<"\nStack is Empty" << endl;
                }
                else{
                    cout <<"\nStack is not Empty" << endl;
                }
                 break;
            }
    
        case 5:
            {
                s.IsFull();
                if(s.IsFull()==1){
                    cout <<"\nStack is Full" << endl;
                }
                else{
                    cout <<"\nStack is not Full" << endl;
                }
                break;
            }
    
        case 6:
            {
                Stack s2;
                string postfix;
                int value_op,op1,op2;
                cout<<"\nEnter the postfix expression in variables without space(abc+*): ";
                cin>>postfix;
                    for(int i=0;postfix[i]!='\0';i++){ 
                        if(check_char(postfix[i])){ //accept value of operands
                            cout<<"enter value for "<<postfix[i]<<"= ";
                            cin>>value_op;
                            s2.push(value_op);
                        }
                        else{ //if it is an operator
                            op2=s2.pop();
                            op1=s2.pop();
                            switch(postfix[i]){
                                    case '+':
                                        s2.push(op1+op2);
                                        break;
                                    case '-':
                                        s2.push(op1-op2);
                                        break;
                                    case '*':
                                        s2.push(op1*op2);
                                        break;
                                    case '/':
                                        s2.push(op1/op2);
                                        break;
                                    case '%':
                                        s2.push(op1%op2);
                                        break;
                                    case '^':
                                        s2.push(pow(op1,op2));
                                        break;
                                    default:
                                     cout<<"invalid operator\n";
                                
                            }
                        }
                    }  
                
                    cout<<"Evaluation of the expression is= "<<s2.pop()<<endl;
                    break;
                        
            }
    
        case 7:
            cout << "End of the Program" << endl;
            break;
        }
    }while(ch!=7);
    return 0;
}





/*
OUTPUT:

	***MENU***
1. Add Element in Stack (PUSH)
2. Delete Top Element from Stack (POP)
3. Display Topmost Element from Stack()PEEK
4. Check if Stack is Empty.
5. Check if Stack is Full.
6. Evaluate value of a Postfix Expression.
7. Exit.
Enter your choice: 1

Enter the Element to be added: 
1
Element Pushed!
Want to push more elements in the stack?(y/n): y

Enter the Element to be added: 
2
Element Pushed!
Want to push more elements in the stack?(y/n): y

Enter the Element to be added: 
3
Element Pushed!
Want to push more elements in the stack?(y/n): y

Enter the Element to be added: 
4
Element Pushed!
Want to push more elements in the stack?(y/n): y

Enter the Element to be added: 
5
Element Pushed!
Want to push more elements in the stack?(y/n): n

	***MENU***
1. Add Element in Stack (PUSH)
2. Delete Top Element from Stack (POP)
3. Display Topmost Element from Stack()PEEK
4. Check if Stack is Empty.
5. Check if Stack is Full.
6. Evaluate value of a Postfix Expression.
7. Exit.
Enter your choice: 2

5 removed from Stack!

	***MENU***
1. Add Element in Stack (PUSH)
2. Delete Top Element from Stack (POP)
3. Display Topmost Element from Stack()PEEK
4. Check if Stack is Empty.
5. Check if Stack is Full.
6. Evaluate value of a Postfix Expression.
7. Exit.
Enter your choice: 3

Top Element is: 4

	***MENU***
1. Add Element in Stack (PUSH)
2. Delete Top Element from Stack (POP)
3. Display Topmost Element from Stack()PEEK
4. Check if Stack is Empty.
5. Check if Stack is Full.
6. Evaluate value of a Postfix Expression.
7. Exit.
Enter your choice: 4

Stack is not Empty

	***MENU***
1. Add Element in Stack (PUSH)
2. Delete Top Element from Stack (POP)
3. Display Topmost Element from Stack()PEEK
4. Check if Stack is Empty.
5. Check if Stack is Full.
6. Evaluate value of a Postfix Expression.
7. Exit.
Enter your choice: 5

Stack is not Full

	***MENU***
1. Add Element in Stack (PUSH)
2. Delete Top Element from Stack (POP)
3. Display Topmost Element from Stack()PEEK
4. Check if Stack is Empty.
5. Check if Stack is Full.
6. Evaluate value of a Postfix Expression.
7. Exit.
Enter your choice: 6

Enter the postfix expression in variables without space(abc+*): abc+*
enter value for a= 3
enter value for b= 10
enter value for c= 5
Evaluation of the expression is= 45

	***MENU***
1. Add Element in Stack (PUSH)
2. Delete Top Element from Stack (POP)
3. Display Topmost Element from Stack()PEEK
4. Check if Stack is Empty.
5. Check if Stack is Full.
6. Evaluate value of a Postfix Expression.
7. Exit.
Enter your choice: 7
End of the Program

...Program finished with exit code 0                                                                                    
Press ENTER to exit console. 
     
*/

/*
TIME COMPLEXITIES
Add element(PUSH):O(1)
Delete top element(POP):O(1)
Display top element(PEEK):O(1)
Check if empty:O(1)
Check if full:O(1)
Evaluate postfix expression:O(n)
*/

