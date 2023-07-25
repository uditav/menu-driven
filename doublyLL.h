#include<iostream>
using namespace std;

class NodeD {
    public:
    int data;
    NodeD* prev;
    NodeD* next;

    //constructor
    NodeD(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~NodeD() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

//traversing a linked list
void print(NodeD* head) {
    NodeD* temp  = head ;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

//gives length of Linked List
int getLength(NodeD* head) {
    int len = 0;
    NodeD* temp  = head ;

    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }

    return len;
}
void insertAtHead(NodeD* &tail, NodeD* &head, int d) {

    //empty list
    if(head == NULL) {
        NodeD* temp = new NodeD(d);
        head = temp;
        tail = temp;
    }
    else{
        NodeD* temp = new NodeD(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }

}


void insertAtTail(NodeD* &tail,NodeD* &head, int d) {
    if(tail == NULL) {
        NodeD* temp = new NodeD(d);
        tail = temp;
        head = temp;
    }
    else{
        NodeD* temp = new NodeD(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

void insertAtPosition(NodeD* & tail, NodeD* &head, int position, int d) {

    //insert at Start
    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    NodeD* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    //creating a node for d
    NodeD* nodeToInsert = new NodeD(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position, NodeD* & head) { 

    //deleting first or start node
    if(position == 1) {
        NodeD* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        NodeD* curr = head;
        NodeD* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}



int mainDLL() {
    NodeD* head = NULL;
    NodeD* tail = NULL;
    int opt,d,position;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion at head"<<endl;
  cout<<"Press 2 for Insertion at position"<<endl;
  cout<<"Press 3 for Insertion at tail"<<endl;
  cout<<"Press 4 for deletion"<<endl;
  cout<<"Press 5 for Traversal"<<endl;
  cout<<"Enter your choice :: ";
  cin>>opt;
  if (opt==1)
  {  
     cout<<"enter the data of new node :: ";
     cin>>d;
     insertAtHead(tail, head, d);
  }
  else if (opt==2)
  {  cout<<"enter the data of new node :: ";
     cin>>d;
     cout<<"enter the position :: ";
     cin>>position;
     insertAtPosition(tail, head, position,d);
  }
  else if (opt==3)
  {   cout<<"enter the data of new node :: ";
     cin>>d;
     insertAtTail(tail, head, d);
  }
  else if(opt==4){
    cout<<"enter the position :: ";
    cin>>position;
    deleteNode(position, head);
  }
   else if(opt==5){
    print(head);
  }
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
    return 0;
}