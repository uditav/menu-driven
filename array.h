#include<iostream>
using namespace std;
int arr[100];
int traverse(int arr[]);
int insert(int arr[], int position, int value); 
int deletion(int arr[], int position);
int sortArray(int arr[]);
int searchNum(int arr[], int target);
int n;
int arrayMain()
{
  
  cout<<"Enter the size of array :: ";
  cin >> n; // input size of array int arr[n];
  cout<<"Enter array elements :: ";
  for(int i = 0 ; i < n ; i++)
  {
    cin >> arr[i]; // input array elements
  }
  int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for deletion"<<endl;
  cout<<"Press 3 for Searching"<<endl;
  cout<<"Press 4 for Sorting"<<endl;
  cout<<"Press 5 for Traversal"<<endl;
  cout<<"Enter your choice :: "<<endl;
  cin>>opt;
  if (opt==1)
  {  cout<<"enter the position :: ";
     cin>>pos;
     cout<<"enter the value  :: ";
     cin>>val;
     insert(arr, pos, val);
  }
  else if (opt==2)
  {  cout<<"enter the position from which you want to delete :: ";
     cin>>pos;
     deletion(arr, pos);
  }
  else if (opt==3)
  {  cout<<"enter the value you want to search :: ";
     cin>>val;
     int r=searchNum(arr, val);
     if (r==-1)
     cout<<"element not found"<<endl;
     else 
     cout<<"Element found at index :: "<<r<<endl;
  }
  else if (opt==4)
     sortArray(arr); 
  else if (opt==5)
     traverse(arr);
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
  return 0;
}

int traverse(int arr[])
{ for(int i = 0 ; i < n ; i++){
    cout << arr[i] << " ";
}
  cout << endl; 
  
  return 0;
}

int insert(int arr[], int position, int value){

// shift all the elements one place forward 
  for(int i = (n) ; i > position ; i--){
    arr[i] = arr[i - 1];
  }

// insert the new number 
  arr[position] = value;
  n++;
  traverse(arr);
  return 0;
}

int deletion(int arr[], int position){ 
  for(int i = position + 1 ; i < n ; i++){
    arr[i-1] = arr[i];
  }
  n--;
  traverse(arr);
  return 0;
}

int sortArray(int arr[]){ 
  for(int i = 0 ; i < n ; i++){
  for(int j = i + 1 ; j < n ; j++){ 
    if(arr[i] > arr[j]){
      int temp = arr[i]; // swap elements 
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
}
return 0;
}

int searchNum(int arr[], int target){ 
for(int i = 0 ; i < n ; i++){
if(arr[i] == target){ // if target found return index no
return i;
}
}

return -1; // if target not found return -1
}
