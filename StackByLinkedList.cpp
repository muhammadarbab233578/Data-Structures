#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
	Node(int n){
		data = n;
		next = NULL;
	}
};
class Stack{
	Node* head;
	int capacity;
	int currSize;
	public:
	Stack(int c){
		this->capacity = c;
		this->currSize = 0;
		head = NULL;
	}
	
	bool isEmpty(){
		return this->head == NULL;
	}
	
	bool isFull(){
		return this->currSize == this->capacity;
	}
	
	void push(int data){
		if(this->currSize == this->capacity){
			cout<<"Overflow"<<endl;
			return;
		}
		Node* newNode = new Node(data);
		newNode->next = this->head;
		this->head = newNode;
		this->currSize++;
	}
	
	int pop(){
		if(this->head == NULL){
			cout<<"Underflow"<<endl;
			return 0;
		}
		Node* newNode = this->head->next;
		this->head->next = NULL;
		Node* toberemove = this->head;
		int result = toberemove->data;
		delete toberemove;
		this->head = newNode;
		currSize--;
		return result;
		
	}
	
	int getTop(){
		if(this->head == NULL){
			cout<<"Underflow"<<endl;
			return 0;
		}
		return this->head->data;
	}
	
	int size(){
		return this->currSize;
	}
	
};
int main(){
	Stack obj(5);
	
	obj.push(12);
	obj.push(15);
	obj.push(19);
	obj.push(12);
	obj.push(15);
	obj.push(19);
	cout<<obj.getTop()<<endl;
	obj.pop();
	cout<<obj.getTop()<<endl;
	cout<<"List is Empty: "<<obj.isEmpty()<<endl;
	cout<<"List is Full: "<<obj.isFull()<<endl;
	cout<<"The Size of Stack is: "<<obj.size()<<endl;
}
