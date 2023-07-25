#include<iostream>
using namespace std;

class MaxPriorityQueue {
  int *arr;
  int capacity;
  int nextIndex;

  public :

  MaxPriorityQueue(int size) {
    arr = new int[size];
    capacity = size;
    nextIndex = 0;
  }

  bool isEmpty() {
    return nextIndex == 0;
  }

  void full(){
    if(nextIndex==capacity){
      cout<<"The priority queue is full"<<endl;
      return;
    }
    else{
      cout<<"The priority queue is not full"<<endl;
    }
  }
  
  void getSize() {
    cout<<"The size of the priority queue is: "<<nextIndex<<endl;
  }

  void getMax() {
    if(isEmpty()) {
      cout<<"The priority queue is empty."<<endl;  
    }
    cout<<"The maximum element is: "<<arr[0]<<endl;
  }

  void insert(int element) {
    if(nextIndex==capacity){
      cout<<"The priority queue is full"<<endl;
      return;
    }
    arr[nextIndex] = element;
    nextIndex++;
    
    int childIndex = nextIndex - 1;

    while(childIndex > 0) {
      int parentIndex = (childIndex - 1) / 2;

      if(arr[childIndex] > arr[parentIndex]) {
        int temp = arr[childIndex];
        arr[childIndex] = arr[parentIndex];
        arr[parentIndex] = temp;
      }
      else {
        break;
      }
      childIndex = parentIndex;
    }

  }

  void removeMin() {
    if(isEmpty()) {
      cout<<"The priority queue is empty"<<endl;   // Priority Queue is empty
      return;
    }
    int ans = arr[0];
    arr[0] = arr[nextIndex - 1];
    arr[nextIndex-1] = 0;
    nextIndex--;

    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndx = 2 * parentIndex + 2;
  
    while(leftChildIndex < nextIndex) {
      int maxIndex = parentIndex;
      if(arr[maxIndex] < arr[leftChildIndex]) {
        maxIndex = leftChildIndex;
      }
      if(rightChildIndx < nextIndex && arr[rightChildIndx] > arr[maxIndex]) {
        maxIndex = rightChildIndx;
      }
      if(maxIndex == parentIndex) {
        break;
      }
      int temp = arr[maxIndex];
      arr[maxIndex] = arr[parentIndex];
      arr[parentIndex] = temp;
    
      parentIndex = maxIndex;
      leftChildIndex = 2 * parentIndex + 1;
      rightChildIndx = 2 * parentIndex + 2;
    }

    cout<<"The removed element is: "<<ans<<endl;
  }

  void display(){
    if(isEmpty()){
      cout<<"The priority queue is empty"<<endl;
      return;
    }
    for(int i=0; i<nextIndex;i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
};

int mainPQMax() {
  int size;
  cout<<"Enter size :: ";
  cin>>size;
  MaxPriorityQueue p(size) ;
  int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion :: "<<endl;
  cout<<"Press 2 for removing max :: "<<endl;
  cout<<"Press 3 for get size :: "<<endl;
  cout<<"Press 4 for get max :: "<<endl;
  cout<<"Press 5 for empty or not :: "<<endl;
  cout<<"Enter your choice :: "<<endl;
  cin>>opt;
  cout<<endl;
  if (opt==1)
  {  
     cout<<"enter the value :: "<<endl;
     cin>>val;
     p.insert(val);
  }
  else if (opt==2)
  {  p.removeMin();
  }
  else if (opt==3)
  {  p.getSize();
  }
  else if (opt==4)
     p.getMax();
  else if (opt==5){
      if(p.isEmpty()){
        cout<<"Empty"<<endl;
      }
      else{
        cout<<"Not Empty"<<endl;
      }
  }
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
  
}