#include<iostream>
using namespace std;
class NodeLL {
    	public :
    	int data;
    	NodeLL *next;

    	NodeLL(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

class Queue {
	// Define the data members
    NodeLL*head;
    NodeLL*tail;
    int size;
    
   public:
    Queue() {
		// Implement the Constructor
        head=NULL;
        tail=NULL;
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

    void enqueue(int data) {
		// Implement the enqueue() function
        NodeLL *newNode=new NodeLL(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            size++;
            return;
        }
        tail->next=newNode;
        tail=tail->next;
        size++;
	}

    int dequeue() {
        // Implement the dequeue() function
        if(size==0){
            return -1;
        }
        NodeLL*a=head;
        int ans=head->data;
        head=head->next;
        delete a;
        size--;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(size==0){
            return -1;
        }
        return head->data;
    }
};

int queueLLMain(){
  Queue q;
 int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for deletion"<<endl;
  cout<<"Press 3 for front"<<endl;
  cout<<"Press 4 for Size"<<endl;
  cout<<"Press 5 for empty or not"<<endl;
  cout<<"Enter your choice :: ";
  cin>>opt;
  if (opt==1)
  {  
     cout<<"enter the value :: ";
     cin>>val;
     q.enqueue(val);
  }
  else if (opt==2)
  {  q.dequeue();
  }
  else if (opt==3)
  {  cout<<q.front()<<endl;
  }
  else if (opt==4)
     cout<<q.getSize()<<endl;
  else if (opt==5)
      cout<<q.isEmpty()<<endl;
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
  return 0;
}


  

