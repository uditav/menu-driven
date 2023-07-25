#include<iostream>
using namespace std;

int size1=100;
int q1[10], front=0,rear=0;

void enqueue(int d){
  if(rear==size1){
      cout<<"overflow"<<endl;
  }
  else{
    q1[rear]=d;
    rear++;
  }
}

void dequeue(){
  if(front==rear){
    cout<<"underflow"<<endl;
  }
  else{
    cout<<q1[front]<<" is deleted"<<endl;
    front++;
  }
}

void displayq(){
  for(int i=front;i<rear;i++){
    cout<<q1[i]<<" ";
  }
}

int queueArrayMain(){
  int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for deletion"<<endl;
  cout<<"Press 3 for display"<<endl;
  cout<<"Enter your choice"<<endl;
  cin>>opt;
  if (opt==1)
  {  
     cout<<"enter the value :: ";
     cin>>val;
     enqueue(val);
  }
  else if (opt==2)
  { 
     dequeue();
  }
  else if (opt==3)
  {  
     displayq();
  }
  
    cout<<"\nDo you want to continue the program ?? Press y/n:: "<<endl;
  cin>>ch;
  }
  return 0;
}




