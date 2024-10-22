#include <iostream>
using namespace std;

class Stack{
	private:
		int capacity;
		int* arr;
		int top;
		
	public:
		Stack(int c){
			this->capacity = c;
			this->arr = new int[c];
			this->top = -1;
		}
		
		//Push Value in Stack
		void push(int data){
			if(this->top >= this->capacity - 1){
				cout<<"Stack is Overflow"<<endl;
				return;
			}
			this->top++;
			this->arr[this->top] = data;
		}
		
		//Pop Value from Stack
		int pop(){
			if(this->top == -1){
				cout<<"Stack is Underflow"<<endl;
				return -1;
			}
			this->top--;
		}
		
		//Get top Element from Stack
		int getTop(){
			if(this->top == -1){
				cout<<"Stack is Empty!"<<endl;
				return 0;
			}
			return this->arr[this->top];
		}
		
		//Check that Stack is Empty
		bool isEmpty(){
			return this->top == -1;
		}
		
		//Check that Stack is Full 
		bool isFull(){
			return this->top == this->capacity - 1;
		}
		
		//Check Size of Stack
		int size(){
			return this->top + 1;
		}
		
		~Stack(){
			delete[] arr;
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
	
	return 0;
}
