#include <iostream>
#include "stackArray.h"
#include "stackLL.h"
#include "queueArray.h"
#include "queueLL.h"
#include "circularQueue.h"       
#include "linearLL.h"      
//#include "array.h"
#include "circularLL.h"
#include "doublyLL.h"
#include "priorityQueue.h"
#include "BST.h"
#include "binaryTree.h"
#include "array1.h"
#include "priorityQueueMax.h"

using namespace std;

int main(){
  cout<<"Name: Udita Verma"<<endl;
  cout<<"Enrolment Number: 12301012021"<<endl;
  cout<<endl;
  char ch='y'; int opt; int subopt;
  while((ch=='y') || (ch=='Y'))
  {cout<<"Main Menu"<<endl;
  cout<<"Press 1 for ARRAY"<<endl;
  cout<<"Press 2 for STACK"<<endl;
  cout<<"Press 3 for QUEUE"<<endl;
  cout<<"Press 4 for LINKED LIST"<<endl;
  cout<<"Press 5 for BINARY TREES"<<endl;
  cout<<"Press 6 for BST"<<endl;
  cout<<"Enter your choice :: ";
  cin>>opt;
  if (opt==1){
        cout<<"WELCOME TO THE WORLD OF ARRAYS"<<endl;
  cout<<"=============================="<<endl;
        Array1Main();
  }
  else if (opt==2){
     cout<<"WELCOME TO THE WORLD OF STACKS"<<endl;
  cout<<"=============================="<<endl;
    cout<<"MENU FOR STACKS"<<endl;
     cout<<"Press 1 for STACK USING ARRAY"<<endl;
     cout<<"Press 2 for STACK USING LINK LIST"<<endl;
     cout<<"Press any button to EXIT"<<endl;
     cout<<"Enter your choice :: ";
     cin>>subopt;
     if(subopt==1){
      stackArrayMain();
     }
     else if(subopt==2){
      stackLLMain();
     }
     else{
       exit(0);
     }
  } 
  else if(opt==3){
     cout<<"WELCOME TO THE WORLD OF QUEUES"<<endl;
  cout<<"=============================="<<endl;
     cout<<"MENU FOR QUEUES"<<endl;
     cout<<"Press 1 for QUEUE USING ARRAY"<<endl;
     cout<<"Press 2 for QUEUE USING LINK LIST"<<endl;
     cout<<"Press 3 for CIRCULAR QUEUE"<<endl;
     cout<<"Press 4 for PRIORITY QUEUE"<<endl;
     cout<<"Press any button to EXIT"<<endl;
     cout<<"Enter your choice :: ";
     cin>>subopt;
     if(subopt==1){
          queueArrayMain();
     }
     else if(subopt==2){
          queueLLMain();
     }
     else if (subopt==3){
          circularQueueMain();
     }
     else if (subopt==4){
          cout<<"Press 1 for min priority queue"<<endl;
          cout<<"Press 2 for max priority queue"<<endl;
          int opt1;
          cin>>opt1;
          if(opt1==1){
                  mainPQ();
          }
          else if(opt1==2){
                 mainPQMax();
          }
          
     }
     else 
       exit(0);
     
   }
   else if(opt==4){
     cout<<"WELCOME TO THE WORLD OF LINKED LIST"<<endl;
  cout<<"=============================="<<endl;
    cout<<"MENU FOR LINKED LIST"<<endl;
     cout<<"Press 1 for SINGLY LINKED LIST"<<endl;
     cout<<"Press 2 for CIRCULAR LINKED LIST"<<endl;
     cout<<"Press 3 for DOUBLY LINKED LIST"<<endl;
     cout<<"Press any button to EXIT"<<endl;
     cout<<"Enter your choice :: ";
     cin>>subopt;
     if(subopt==1){
          linearLLMain();
     }
     else if(subopt==2){
          circularLLMain();
     }
     else if (subopt==3){
          mainDLL();
     }
     else 
       exit(0);
     
   }
   else if(opt==5){
     cout<<"WELCOME TO THE WORLD OF BINARY TREES"<<endl;
  cout<<"=============================="<<endl;
       binaryTreemain();
   }
   else if(opt==6){
     cout<<"WELCOME TO THE WORLD OF BINARY SEARCH TREES"<<endl;
  cout<<"=============================="<<endl;
     BSTmain();
   }
  cout<<"DO YOU WANT TO USE ANOTHER DATA STRUCTURE?? (Y/N) :: ";
  cin>>ch;
  }
  return 0;
}