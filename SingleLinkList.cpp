#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int value){
			data = value;
			next = NULL;
		}
};
//Insert Value in List 
void insertValue(Node*& head, int value) {
    Node* newNode = new Node(value);
    

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Insert Value at head
void insertHead(Node* &head, int value){
	Node* ptr = new Node(value);
	
	ptr->next = head;
	head = ptr;
}

//Insert Value at Tail
void insertTail(Node* &head, int value){
	Node* ptr = new Node(value);
	Node* temp = head;
	
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = ptr;
}

//Insert Value nth position
void insertposition(Node* &head, int value, int pos){
	
	if(pos == 0){
		insertHead(head, value);
		return;
	}
	Node* ptr = new Node(value);
	Node* temp = head;
	int currentposition = 0;
	
	while(currentposition != pos-1){
		temp = temp->next;
		currentposition++;
	}
	ptr->next = temp->next;
	temp->next = ptr;
}

//Delete head Node
void deleteHead(Node* &head){
	Node* temp = head;
	head = head->next;
	delete temp;
}

//Delete Tail Node
void deleteTail(Node* &head){
	Node* secondLast = head;
	
	while(secondLast->next->next != NULL){
		secondLast = secondLast->next;
	}
	Node* temp = secondLast->next;
	secondLast->next = NULL;
	delete temp;
}

//Delete nth node
void deleteposition(Node* &head, int pos){
	if(pos == 0){
		deleteHead(head);
		return;
	}
	
	int currentposition = 0;
	Node* pre = head;
	
	while(currentposition != pos-1){
		pre = pre->next;
	}
	Node* temp = pre->next;
	pre->next = pre->next->next;
	delete temp;
}

//Display Node of the List
void display(Node* head){
	if(head == NULL){
        cout<<"List is Empty."<<endl;
        return;
    }
    
	Node* temp = head;
	
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

//Reverse list
void displayreverse(Node* head){
	if(head == NULL){
		return;
	}
	displayreverse(head->next);
	cout<<head->data<<" ";
}

//Count List
int countList(Node* head){
	Node* temp = head;
	int count = 0;
	while(temp != NULL){
		temp = temp->next;
		count++;
	}
	return count;
}

//Main program
int main(){
	Node* head = NULL;
	cout<<"After put values in List: ";
    insertValue(head, 24);
    insertValue(head, 37);
    display(head);
    cout<<"\nAfter insert Values in Head of List: ";
    insertHead(head, 12);
	insertHead(head, 10);
	display(head);
	cout<<"\nAfter insert Value in Tail of List: ";
	insertTail(head, 20);
	display(head);
	cout<<"\nAfter insert Value in special position of the List: ";
	insertposition(head, 100, 2);
	display(head);
	cout<<"\nTotal number in list is: "<<countList(head);
	cout<<"\nReverse List: ";
	displayreverse(head);
	cout<<"\nAfter Delete Values from Head of List: ";
	deleteHead(head);
	display(head);
	cout<<"\nAfter Delete Values from Tail of List: ";
	deleteTail(head);
	display(head);
	cout<<"\nAfter Delete Values from specail position of List: ";
	deleteposition(head, 1);
	display(head);
	
}
