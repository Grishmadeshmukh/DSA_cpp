#include<iostream>
using namespace std;

// PASSENGER
class Passenger {
public:
	string name;
	int age, seatno;
	Passenger *next;
	Passenger(string nm, int a, int sno) {
		name = nm;
		age = a;
		seatno = sno;
		next = NULL;
	}
	friend class Queue;
};

// QUEUE
class Queue {
public:
	Passenger *front, *rear;
	Queue() {
		front = NULL;
		rear = NULL;
	}
	bool isEmpty();
	void enqueue(Passenger *p);
	Passenger* dequeue();
};

bool Queue::isEmpty() {
	return front == NULL;
}

void Queue::enqueue(Passenger *p) {
	if (front == NULL) {
		front = p;
		rear = p;
	} 
	else {
		rear->next = p;
		rear = p;
	}
}

Passenger* Queue::dequeue() {
	if (front == NULL) {
		cout << "Queue is Empty";
		return NULL;
	} 
	else {
		Passenger *temp = front;
		front = front->next;
		return temp;
	}
}

// LISTS
class List {
public:
	Passenger *head;
	List() {
		head = NULL;
	}
	void add(Passenger*);
	void delet();
	int length();
};

void List::add(Passenger *p) {
	if (head == NULL) {
		head = p;
	} 
	else {
		Passenger *ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = p;
	}
}

void List::delet() {
	Passenger *prev, *ptr;
	int rn;
	cout << "\nEnter seat number to delete record: ";
	cin >> rn;
	if (head == NULL) {
		cout << "\nList is Empty";
	} 
	else {
		prev = head, ptr = head;
		while (ptr != NULL && ptr->seatno != rn) {
			prev = ptr;
			ptr = ptr->next;
		}
		if (ptr == head) {
			head = head->next;
			delete (ptr);
		} 
		else if (ptr != NULL) {
			prev->next = ptr->next;
			ptr->next = NULL;
			delete (ptr);
		} 
		else {
			cout << "\nNo such record found";
		}
	}
}

int List::length() {
	int count = 0;
	for (Passenger *ptr = head; ptr != NULL; ptr = ptr->next) {
		count++;
	}
	return count;
}

// APPLICATIONS
class application {
public:
	Queue waiting;
	List confirm;
	void bookTicket(Passenger*); //Confirm limit is 3 
	void cancelTicket();
	void displayall();
};

void application::bookTicket(Passenger *p) { //Confirm limit is 3 
	if (confirm.length() < 3) {
		confirm.add(p);
	}
	else {
		waiting.enqueue(p);
	}
}

void application::cancelTicket() {
	confirm.delet();
	if (confirm.length() < 3) {
		Passenger *temp = waiting.dequeue();
		temp->next=NULL;
		confirm.add(temp);
	}
}

void application::displayall() {
	cout << "Confirm tickets are:" << endl;
	for (Passenger *q = confirm.head; q != NULL; q = q->next){
		cout << "\tName: " << q->name << "\t Age:" << q->age << "\t Seat no."<< q->seatno << endl;
	}
	cout<<"----------------------------------------------------------------"<<endl;
	cout << "waiting list:" << endl;
	for (Passenger *q = waiting.front; q != NULL; q = q->next) {
		cout << "\tName: " << q->name << "\t Age:" << q->age << "\t Seat no."<< q->seatno << endl;
	}
	cout<<"----------------------------------------------------------------"<<endl;
}


int main() {
	application a;
	int ch;
	string nm;
	int age, sno;
	Passenger *temp;
	do {
		cout << "\n\tMENU" << endl;
		cout << "1.Book a ticket" << endl;
		cout << "2.Cancellation of a ticket" << endl;
		cout << "3.Display confirmed and waiting list" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter choice: ";
		cin >> ch;
		switch (ch) {
		case 1:
			cout << "Enter name: ";
			cin >> nm;
			cout << "Enter age: ";
			cin >> age;
			cout << "Enter seat no. ";
			cin >> sno;
			temp = new Passenger(nm, age, sno);
			a.bookTicket(temp);
			break;
		case 2:
			a.cancelTicket();
			break;
		case 3:
			a.displayall();
			break;
		case 4:
			cout << "END" << endl;
			break;
		default:
			cout << "Invalid choice" << endl;
		}
	} while (ch != 4);
}




/*
OUTPUT:
       MENU                                                                                                            
1.Book a ticket                                                                                                         
2.Cancellation of a ticket                                                                                              
3.Display confirmed and waiting list                                                                                    
4.Exit                                                                                                                  
Enter choice: 1                                                                                                         
Enter name: gunika                                                                                                      
Enter age: 12                                                                                                           
Enter seat no. 1                                                                                                        
                                                                                                                        
        MENU                                                                                                            
1.Book a ticket                                                                                                         
2.Cancellation of a ticket                                                                                              
3.Display confirmed and waiting list                                                                                    
4.Exit                                                                                                                  
Enter choice: 1                                                                                                         
Enter name: manoj                                                                                                       
Enter age: 45                                                                                                           
Enter seat no. 2  

        MENU                                                                                                            
1.Book a ticket                                                                                                         
2.Cancellation of a ticket                                                                                              
3.Display confirmed and waiting list                                                                                    
4.Exit                                                                                                                  
Enter choice: 1                                                                                                         
Enter name: swapna                                                                                                      
Enter age: 34                                                                                                           
Enter seat no. 3                                                                                                        
                                                                                                                        
        MENU                                                                                                            
1.Book a ticket                                                                                                         
2.Cancellation of a ticket                                                                                              
3.Display confirmed and waiting list                                                                                    
4.Exit                                                                                                                  
Enter choice: 1                                                                                                         
Enter name: raahi                                                                                                       
Enter age: 20                                                                                                           
Enter seat no. 4 

        MENU                                                                                                            
1.Book a ticket                                                                                                         
2.Cancellation of a ticket                                                                                              
3.Display confirmed and waiting list                                                                                    
4.Exit                                                                                                                  
Enter choice: 3                                                                                                         
Confirm tickets are:                                                                                                    
        Name: gunika     Age:12  Seat no.1                                                                              
        Name: manoj      Age:45  Seat no.2                                                                              
        Name: swapna     Age:34  Seat no.3                                                                              
----------------------------------------------------------------                                                                                      
waiting list:                                                                                                           
        Name: raahi      Age:20  Seat no.4                                                                              
----------------------------------------------------------------    

        MENU                                                                                                            
1.Book a ticket                                                                                                         
2.Cancellation of a ticket                                                                                              
3.Display confirmed and waiting list                                                                                    
4.Exit                                                                                                                  
Enter choice: 2                                                                                                         
                                                                                                                        
Enter seat number to delete record: 1                                                                                   
                                                                                                                        
        MENU                                                                                                            
1.Book a ticket                                                                                                         
2.Cancellation of a ticket                                                                                              
3.Display confirmed and waiting list                                                                                    
4.Exit                                                                                                                  
Enter choice: 3                                                                                                         
Confirm tickets are:                                                                                                    
        Name: manoj      Age:45  Seat no.2                                                                              
        Name: swapna     Age:34  Seat no.3                                                                              
        Name: raahi      Age:20  Seat no.4                                                                              
----------------------------------------------------------------
waiting list:                                                                                                                                                                                     
---------------------------------------------------------------- 
*/

/*
TIME COMPLEXITIES
Book a ticket(enqueue):O(1)
Cancellation of a ticket(dequeue):O(1)
*/