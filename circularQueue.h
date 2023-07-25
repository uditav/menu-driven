#include<iostream>
using namespace std;

int front2=-1;int rear2=-1;int q2[100]; int size2=100;
void enqueue(int q[], int d){
    if((rear2==size2-1 && front2==0)||(front2==rear2+1)){
        cout<<"full"<<endl;
    }
    else if(front2==-1){
        front2=rear2=0;
        q2[rear2]=d;
    }
    else if(rear2==size2-1){
        rear2=0;
        q2[rear2]=d;
    }
    else{
        rear2++;
        q2[rear2]=d;
    }
}

void display(int q2[],int front2, int rear2){
    for(int i=front2;i<=rear2;i++){
        cout<<q2[i]<<" ";
    }
    cout<<endl;
}


void dequeue2(){
  if(front2==-1){                  //no element
    cout<<"queue is empty"<<endl;
  }
  else if(front2==size2-1){
    front2=0;
  }
  else if(front2==rear2){     //only one element
    front2=rear2=-1;
  }
  else{
    front2++;
  } 
}



int circularQueueMain(){
  int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for deletion"<<endl;
  cout<<"Press 3 for display"<<endl;
  cout<<"Enter your choice :: ";
  cin>>opt;
  if (opt==1)
  {  
     cout<<"enter the value :: ";
     cin>>val;
     enqueue(q2,val);
  }
  else if (opt==2)
  { 
     dequeue2();
  }
  else if (opt==3)
  {  
     display(q2,front2,rear2);
  }
  
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
  return 0;
}


