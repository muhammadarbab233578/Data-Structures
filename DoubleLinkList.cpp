#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
	Node(int value){
		data = value;
		next = NULL;
		prev = NULL;
	}
};

class doublyLinkesList{
	public:
		Node* head;
		Node* tail;
		
	doublyLinkesList(){
		head = NULL;
		tail = NULL;
	}
		
	
	//Insert Value in Head
	void insertatHead(int value){
		Node* ptr = new Node(value);
	
	    if(head == NULL){
		    head = ptr;
		    tail = ptr;
		    return;
	    }
	
	    ptr->next = head;
	    head->prev = ptr;
    	head = ptr;
	}
	
	//Insert Value in Tail
	void insertatTail(int value){
		Node* ptr = new Node(value);
		
		if(tail == NULL){
			head = ptr;
			tail = ptr;
			return;
		}
		tail->next = ptr;
		ptr->prev = tail;
		tail = ptr; 
		
	}
	
	
	//Insert Value at nth position
	void inseratPosition(int value, int pos){
		Node* ptr = new Node(value);
		Node* temp = head;
		int count = 1;
		
		while(count < (pos - 1)){
			temp = temp->next;
			count++;
		}
		ptr->next = temp->next;
		temp->next = ptr;
		
		ptr->prev = temp;
	    ptr->next->prev = ptr;
	    return;
	}
	
	//Delete first node
	void headDelete(){
		if(head == NULL){
			return;
		}
		Node* temp = head;
		head = head->next;
		if(head == NULL){
			tail = NULL;
		}else{
			head->prev = NULL;
		}
		delete temp;
	}
	
	//Delete End List
	void EndDelete(){
		if(head == NULL){
			return;
		}
		Node* temp = tail;
		tail = tail->prev;
		if(tail==NULL){
			head = NULL;
		}else{
			tail->next = NULL;
		}
		delete temp;
		return;
	}
	
	//Delete nth node
	void deletenthNode(int pos){
		Node* temp = head;
		int count = 1;
		
		while(count < pos){
			temp = temp->next;
			count++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	
	//Display List
    void display(){
	    if(head == NULL){
            cout<<"List is Empty!"<<endl;
            return;
        }
    
	    Node* temp = head;
	
	    while(temp != NULL){
		    cout<<temp->data<<" ";
		    temp = temp->next;
	    }
	    cout<<endl;
    }
    
    //Display Link in reverse
    void reverserDisplay(){
    	if(tail == NULL){
    		cout<<"List is Empty!"<<endl;
    		return;
		}
		Node* temp = tail;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->prev;
		}
		cout<<endl;
	}
    
};

//Main program
int main(){
	doublyLinkesList obj;
	
	obj.insertatHead(23);
	obj.insertatHead(24);
	obj.insertatHead(25);
	obj.insertatTail(30);
	obj.display();
	cout<<"Reverse Link List is: ";
	obj.reverserDisplay();
	obj.inseratPosition(35, 3);
	obj.display();
	obj.deletenthNode(2);
	obj.EndDelete();
	obj.headDelete();
	obj.display();
	
}
