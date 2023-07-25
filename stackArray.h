#include <iostream>
using namespace std;
int size=100;
int q[100]; int top=-1;

void push(int d){
  if(top==size-1){
    cout<<"overflow"<<endl;
  }
  else{
    q[++top]=d;
  }
}

void pop(){
  if(top==-1){
    cout<<"underflow"<<endl;
  }
  else{
    top--;
  }
}

void display(){
  for(int i=top;i>-1;i--){
    cout<<q[i]<<endl;
  }
}

int stackArrayMain(){
 int opt,pos,val;
  char ch='y';
  while((ch=='y') || (ch=='Y'))
  {
    cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for deletion"<<endl;
  cout<<"Press 3 for display"<<endl;
  cout<<"Enter your choice"<<endl;
  cin>>opt;
  if (opt==1)
  {  
     cout<<"enter the value :: ";
     cin>>val;
     push(val);
  }
  else if (opt==2)
  { 
     pop();
  }
  else if (opt==3)
  {  
     display();
  }
  
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
  return 0;

}