#include <iostream>
using namespace std;

class NodeCL{
  public:
  int data;
  NodeCL*next;

  NodeCL(int d){
    this->data=d;
    next=NULL;
  }

  ~NodeCL(){
    int value=this->data;
    if(this->next!=NULL){
      delete next;
      next=NULL;
    }
    cout<<"Memory is free for node with data "<<value<<endl;
  }
};

void insertNode(NodeCL*&tail, int element, int d){
  if(tail==NULL){
     NodeCL*newNode=new NodeCL(d);
     tail=newNode;
     newNode->next=newNode;
  }
  else{
     NodeCL*newNode=new NodeCL(d);
     NodeCL*curr=tail;
     while(curr->data!=element){
      curr=curr->next;
     }
     newNode->next=curr->next;
     curr->next=newNode;
  }
}

void print(NodeCL*&tail){
  if(tail==NULL){
    cout<<"list is empty"<<endl;
  }
  NodeCL*temp=tail;
  do{
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  while(temp!=tail);

  cout<<endl;
}

void deleteNode(NodeCL*&tail, int d){
  if(tail==NULL){
    cout<<"List is empty"<<endl;
    return;
  }
  else{
    NodeCL*prev=tail;
    NodeCL*curr=prev->next;
    while(curr->data!=d){
      prev=curr;
      curr=curr->next;
    }
    prev->next=curr->next;

    if(curr==prev){
      tail=NULL;
    }
    else if(tail==curr){
      tail=prev;
    }
    curr->next=NULL;
    delete curr;
  }

}

int circularLLMain()
{
  NodeCL*tail=NULL;
  int opt,d,e;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for deletion"<<endl;
  cout<<"Press 3 for Traversal"<<endl;
  cout<<"Enter your choice :: ";
  cin>>opt;
  if (opt==1)
  {  cout<<"enter the element after which you wish to insert :: ";
     cin>>e;
     cout<<"enter the data of new node :: ";
     cin>>d;
     insertNode(tail,e,d);
  }
  else if (opt==2)
  {  cout<<"enter the data of the node to be deleted :: ";
     cin>>d;
     deleteNode(tail,d);
  }
  else if (opt==3)
  {  print(tail);
  }
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
  return 0;
}
