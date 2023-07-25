#include<iostream>
using namespace std;

class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class Stack {
	// Define the data members
    Node*head;
    int size;
    public:
    Stack() {
        // Implement the Constructor
        head=NULL;
        size=0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void push(int element) {
        // Implement the push() function
        Node*newNode=new Node(element);
        if(head==NULL){
            head=newNode;
            size++;
        }
        else{
            newNode->next=head;
            head=newNode;
            size++;
        }
    }

    int pop() {
        // Implement the pop() function
        if(size==0){
            return -1;
        }
        size--;
        Node*a=head;
        int val=head->data;
        head=head->next;
        delete a;
        return val;
    }

    int top() {
        // Implement the top() function
        if(size==0){
            return -1;
        }
        return head->data;
    }

};

int stackLLMain(){
  Stack s;
  int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for deletion"<<endl;
  cout<<"Press 3 for top"<<endl;
  cout<<"Press 4 for size"<<endl;
  cout<<"Press 5 for empty or not"<<endl;
  cout<<"Enter your choice"<<endl;
  cin>>opt;
  if (opt==1)
  {  
     cout<<"enter the value :: ";
     cin>>val;
      s.push(val);
  }
  else if (opt==2)
  {   s.pop();
  }
  else if (opt==3)
  {    cout<<s.top()<<endl;
  }
  else if (opt==4)
     cout<<s.getSize()<<endl;
  else if (opt==5){
      if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
      }
      else{
        cout<<"Stack is not empty"<<endl;
      }
  }
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
  return 0;
}