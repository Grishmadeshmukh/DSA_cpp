#include<iostream>
 //#include<string>
using namespace std;
 
class Stack {
    int top;
  int arr[5];
 
  public:
    Stack() {
      top = -1;
      //for (int i = 0; i < 5; i++) {
      //  arr[i] = 0;
      //}
    }
    int isempty();
    int isfull();
    void push(int val);
    int pop();
    int count();
    int peek(int pos);
    void change(int pos, int val);
    void display();
};
 
  int Stack::isempty() {
    if (top == -1)
      return 1;
    else
      return 0;
  }
  
  int Stack::isfull() {
    if (top == 4)
      return 1;
    else
      return 0;
  }
 
  void Stack::push(int val) {
    if (isfull()==1) {
      cout << "stack overflow" << endl;
    } else {
      top++; // 1
      arr[top] = val;
    }
  }
 
  int Stack::pop() {
    if (isempty()==1) {
      cout << "stack underflow" << endl;
    } else {
      int popValue = arr[top];
      arr[top] = 0;
      top--;
      return popValue;
    }
  }
 
  int Stack::count() {
    return (top + 1);
  }
 
  int Stack::peek(int pos) {
      int c= count();
    if (isempty()==1) {
      cout << "stack underflow" << endl;
    } 
    else {
        if(pos>c-1){
            cout<<"No element at that position";
        }
        else{
           return arr[pos];
        }
    }
  }
 
  void Stack::change(int pos, int val) {
    arr[pos] = val;
    cout << "value changed at location " << pos << endl;
  }
 
  void Stack::display() {
    cout << "All values in the Stack are " << endl;
    int c= count();
    for (int i = c-1; i >= 0; i--) {
      cout << arr[i] << endl;
    }
  }

 
int main() {
  Stack s1;
  int option, postion, value;
 
  do {
    cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. isFull()" << endl;
    cout << "5. peek()" << endl;
    cout << "6. count()" << endl;
    cout << "7. change()" << endl;
    cout << "8. display()" << endl;
    cout << "9. Clear Screen" << endl << endl;
 
    cin >> option;
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Enter an item to push in the stack" << endl;
      cin >> value;
      s1.push(value);
      break;
    case 2:
      cout << "Pop Function Called - Poped Value: " << s1.pop() << endl;
      break;
    case 3:
      if (s1.isempty()==1)
        cout << "Stack is Empty" << endl;
      else
        cout << "Stack is not Empty" << endl;
      break;
    case 4:
      if (s1.isfull()==1)
        cout << "Stack is Full" << endl;
      else
        cout << "Stack is not Full" << endl;
      break;
    case 5:
      cout << "Enter position of item you want to peek: " << endl;
      cin >> postion;
      cout << "Peek Function Called - Value at position " << postion << " is " << s1.peek(postion) << endl;
      break;
    case 6:
      cout << "Count Function Called - Number of Items in the Stack are: " << s1.count() << endl;
      break;
    case 7:
      cout << "Change Function Called - " << endl;
      cout << "Enter position of item you want to change : ";
      cin >> postion;
      cout << endl;
      cout << "Enter value of item you want to change : ";
      cin >> value;
      s1.change(postion, value);
      break;
    case 8:
      cout << "Display Function Called - " << endl;
      s1.display();
      break;
    case 9:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}

