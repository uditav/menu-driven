#include<iostream>
using namespace std;

class NodeL{
  public:
  int data;
  NodeL*next;

  NodeL(int data){
    this->data=data;
    next=NULL;
  }
};

void InsertAtHead(NodeL* &head,NodeL* &tail, int d){
  if(head==NULL && tail==NULL){
     NodeL* newNode=new NodeL(d);
     head=tail=newNode;
     return;
  }
   NodeL* newNode=new NodeL(d);
   newNode->next=head;
   head=newNode;
   
}

void insertAtTail(NodeL* &head,NodeL* &tail, int d){
  if(head==NULL && tail==NULL){
     NodeL*newNode=new NodeL(d);
    tail=head=newNode;
    return;
  }
   NodeL*newNode=new NodeL(d);
   tail->next=newNode;
   tail=tail->next;
   
}

void insertAtPosition(NodeL*&head, NodeL*&tail, int d, int pos){
  NodeL*newNode=new NodeL(d);
  if(pos==1){
    newNode->next=head;
    head=newNode;
    return;
  }
  NodeL*temp=head;
  int c=1;
  while(c<pos-1){
    temp=temp->next;
    c++;
  }
  

  if(temp->next==NULL){
    tail->next=newNode;
    tail=tail->next;
    return;
  }

  
  newNode->next=temp->next;
  temp->next=newNode;
}

void deleteAtPos(NodeL*&head,NodeL*&tail, int pos){
  if(pos==1){
      NodeL*temp=head;
      head=head->next;
      delete temp;
  }
  else{


  NodeL*curr=head;
  NodeL*prev=NULL;
  int c=1;
  while(c<pos){
    prev=curr;
    curr=curr->next;
     c++;
  }
  if(curr->next==NULL){
    tail=prev;
  }
  prev->next=curr->next;
  curr->next=NULL;
  delete curr;
  }
}

void print(NodeL*&head){
  NodeL*temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

int linearLLMain(){
   NodeL* tail=NULL;
  NodeL * head= NULL;
  /*
  NodeL* node1=new NodeL(10);
  NodeL * head= node1;
  NodeL* tail=node1;*/
 int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion at head"<<endl;
  cout<<"Press 2 for insertion at tail"<<endl;
  cout<<"Press 3 for insertion at a position"<<endl;
  cout<<"Press 4 for deletion"<<endl;
  cout<<"Press 5 for traversal"<<endl;
  cout<<"Enter your choice :: ";
  cin>>opt;
  if (opt==1)
  {  
     cout<<"enter the value :: ";
     cin>>val;
     InsertAtHead(head,tail,val);
  }
  else if (opt==2)
  {  
    cout<<"enter the value :: ";
    cin>>val;
    insertAtTail(head,tail,val); 
  }
  else if (opt==3)
  {
    cout<<"enter the position :: "<<endl;
    cin>>pos;
    cout<<"enter the value"<<endl;
    cin>>val;
    insertAtPosition(head,tail,val,pos);
  }
  else if (opt==4){
    cout<<"enter the position :: "<<endl;
    cin>>pos;
    deleteAtPos(head,tail,pos);
  }
     
  else if(opt==5){
      print(head);
   }
  
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  } 
  return 0;
}