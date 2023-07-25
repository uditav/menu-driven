#include<iostream>
using namespace std;
int arr[100];
int traverse(int arr[]);
int insert(int arr[], int position, int value); 
int deletion(int arr[], int position);
int sortArray(int arr[]);
int searchNum(int arr[], int target);

void bubbleSort(int *input, int size)
{
    for(int j=0;j<size-1;j++){
     for(int i=0;i<size-1-j;i++){
        if(input[i]>input[i+1]){
            int temp=input[i];
            input[i]=input[i+1];
            input[i+1]=temp;
        }
     }
    }
}

void insertionSort(int *array, int size)
{
  int key, j;
  for(int i = 1; i<size; i++) {
    key = array[i]; //take value
    j = i;
    while(j > 0 && array[j-1]>key) {
             array[j] = array[j-1];
              j--;
    }
    array[j] = key; //insert in right place
   }

}

void merge(int input[], int si, int ei){
	int size=ei-si+1;
	int mid=(si+ei)/2;
	int* out=new int[size];
	int i=si;
	int j=mid+1;
	int k=0;
	while(j<=ei && i<=mid){
		if(input[i]<input[j]){
			out[k]=input[i];
			k++;
			i++;
		}
		else{
			out[k]=input[j];
			k++;
			j++;
		}
	}
	while(j<=ei){
		out[k]=input[j];
		k++;
		j++;
	}
	while(i<=mid){
		out[k]=input[i];
		k++;
		i++;
	}
	int m=0;
	for(int i=si;i<=ei;i++){
		input[i]=out[m];
		m++;
	}
	delete [] out;
}

void mergeSort(int input[], int si, int ei){
    if(si>=ei){
		return;
	}
	int mid=(si+ei)/2;
	 mergeSort(input, si, mid);
	 mergeSort(input, mid+1, ei);
	 merge(input, si, ei);
}


void mergeSort(int input[], int size){
	// Write your code here
	    int si=0;
		int ei=size-1;
        mergeSort(input,si,ei);
}

int partition(int input[],int s, int e){
        long int count=0;

        for(int i=s+1;i<=e;i++)
                if(input[i]<=input[s])
                    count++;

        int pivt = s+count;
        swap(input[pivt],input[s]);
  
            int i=s,j=e;
            while(i<pivt && j>pivt){
                
                while(input[i] <= input[pivt] && i<pivt){
                    i++;
                }
                while(input[j] > input[pivt] && j>pivt){
                    j--;
                }
                
                if(i<pivt && j>pivt){            
                    swap(input[i],input[j]);
                    i++;
                    j--;
                }
                    
            }
            
            return pivt;
    }
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here
        if(start>=end)
            return;
        int c=partition(input,start,end);
        quickSort(input,start,c-1);
        quickSort(input,c+1,end);
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}

void make(int arr[], int n, int i){
    if(i==n){
        return;
    }
    int childIndex = i;
    while(childIndex>0){
        int parentIndex = (childIndex - 1) / 2;
        if (arr[childIndex] > arr[parentIndex]) {
            int temp = arr[parentIndex];
            arr[parentIndex] = arr[childIndex];
            arr[childIndex] = temp;
            childIndex = parentIndex;
        }
        else{
            break;
        }
    }
    make(arr,n,i+1);
    return;
 
}
void del(int arr[], int n){
    if(n==0){
        return;
    }
    int temp = arr[0];
    arr[0] = arr[n-1];
    arr[n-1] = temp;
    int parentIndex = 0;
    int child1 = 2 * parentIndex + 1;
    int child2 = 2 * parentIndex + 2;
    while (child1 < n-1) {
      int minIndex = parentIndex;
      if (arr[child1] > arr[minIndex]) {
        minIndex = child1;
      }
      if (arr[child2] > arr[minIndex] && child2 < n-1 ) {
        minIndex = child2;
      }
      if (minIndex == parentIndex) {
        break;
      }
      int temp1 = arr[parentIndex];
      arr[parentIndex] = arr[minIndex];
      arr[minIndex] = temp1;
      parentIndex = minIndex;
      child1 = 2 * parentIndex + 1;
      child2 = 2 * parentIndex + 2;
    }
    del(arr,n-1);
    return;
}

void heapSort(int arr[], int n) {
    if(n==0){
        cout<<"The array is empty";
    }
    if(n==1){
        return;
    }
    make(arr,n,1);
    del(arr,n);
    return;

}

int n;
int Array1Main()
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
  else if (opt==4){
    int opt1;
    cout<<"Press 1 for Bubble Sort"<<endl;
    cout<<"Press 2 for Insertion Sort"<<endl;
    cout<<"Press 3 for Quick Sort"<<endl;
    cout<<"Press 4 for Merge Sort"<<endl;
    cout<<"Press 5 for Heap Sort"<<endl;
    cout<<"Enter your choice :: "<<endl;
    cin>>opt1;
    if (opt1==1){
           bubbleSort(arr,n);
    }
    else if(opt1==2){
           insertionSort(arr,n);
    }
    else if(opt1==3){
      quickSort(arr,n);
    }
    else if(opt1==4){
      mergeSort(arr,n);
    }
    else if(opt1==5){
      heapSort(arr,n);
    }
  }
    
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
