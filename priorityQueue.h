//#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
  vector<int> pq;

  public :

  PriorityQueue() {

  }

  bool isEmpty() {
    return pq.size() == 0;
  }

  
  int getSize() {
    return pq.size();
  }

  int getMin() {
    if(isEmpty()) {
      return 0;   
    }
    return pq[0];
  }

  void insert(int element) {
    pq.push_back(element);
    
    int childIndex = pq.size() - 1;

    while(childIndex > 0) {
      int parentIndex = (childIndex - 1) / 2;

      if(pq[childIndex] < pq[parentIndex]) {
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
      }
      else {
        break;
      }
      childIndex = parentIndex;
    }

  }

  int removeMin() {
    if(isEmpty()) {
      return 0;   // Priority Queue is empty
    }
    int ans = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq.pop_back();

    int parentIndex = 0;
    int leftChildIndex = 2 * parentIndex + 1;
    int rightChildIndx = 2 * parentIndex + 2;
  
    while(leftChildIndex < pq.size()) {
      int minIndex = parentIndex;
      if(pq[minIndex] > pq[leftChildIndex]) {
        minIndex = leftChildIndex;
      }
      if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
        minIndex = rightChildIndx;
      }
      if(minIndex == parentIndex) {
        break;
      }
      int temp = pq[minIndex];
      pq[minIndex] = pq[parentIndex];
      pq[parentIndex] = temp;
    
      parentIndex = minIndex;
      leftChildIndex = 2 * parentIndex + 1;
      rightChildIndx = 2 * parentIndex + 2;
    }

    return ans;
  }
};

int mainPQ() {
  PriorityQueue p;
  int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion :: "<<endl;
  cout<<"Press 2 for removing min :: "<<endl;
  cout<<"Press 3 for get size :: "<<endl;
  cout<<"Press 4 for get min :: "<<endl;
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
  {  cout<<p.removeMin()<<" is removed."<<endl;
  }
  else if (opt==3)
  {  cout<<p.getSize()<<endl;
  }
  else if (opt==4)
     cout<<p.getMin()<<endl;
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