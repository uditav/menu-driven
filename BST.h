	#include<iostream>
  using namespace std;
  template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
class BST {
    // Define the data members
    BinaryTreeNode<int>*root;

    private:
      bool search(int data, BinaryTreeNode<int>* node) {
        if (node == NULL) {
          return false;
        }

        if (node->data == data) {
          return true;
        } else if (data < node->data) {
          return search(data, node->left);
        } else {
          return search(data, node->right);
        }
      }

      BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node) {
        if (node == NULL) {
          BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
          return newNode;
        }

        if (data <= node->data) {
          node->left = insert(data, node->left);
        } else {
          node->right = insert(data, node->right);
        }
        return node;
      }

      BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int>*node){
        if (node == NULL) {
          return NULL;
        }

        if (data > node->data) {
          node->right = remove(data, node->right);
          return node;
        } else if (data < node->data) {
          node->left = remove(data, node->left);
          return node;
        } else {
          if (node->left == NULL && node->right == NULL) {
            delete node;
            return NULL;
          } else if (node->left == NULL) {
            BinaryTreeNode<int> *temp = node->right;
            node->right = NULL;
            delete node;
            return temp;
          } else if (node->right == NULL) {
            BinaryTreeNode<int> *temp = node->left;
            node->left = NULL;
            delete node;
            return temp;
          } else {
            BinaryTreeNode<int> *minNode = node->right;
            while (minNode->left != NULL) {
              minNode = minNode->left;
            }
            int rightMin = minNode->data;
            node->data = rightMin;
            node->right = remove(rightMin, node->right);
            return node;
          }
        }
      }

      void print(BinaryTreeNode<int>* node) {
        if (node == NULL) {
          return;
        }
        cout << node->data << ":";
        if (node->left != NULL) {
          cout << "L:" << node->left->data<<",";
        }

        if (node->right != NULL) {
          cout << "R:" << node->right->data;
        }
        cout << endl;
        print(node->left);
        print(node->right);
      }

          public : BST() {
        // Implement the Constructor
       root=NULL;
      }

        /*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
        root=remove(data,root);
    }

    void print() { 
        // Implement the print() function
        print(root);
    }

    void insert(int data) { 
        // Implement the insert() function 
        root=insert( data, root);
    }

    bool search(int data) {
		// Implement the search() function 
        return search(data,root);
    }
};

int BSTmain(){
  BST b;
  int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for deletion"<<endl;
  cout<<"Press 3 for display"<<endl;
  cout<<"Press 4 for searching"<<endl;
  cout<<"Enter your choice :: ";
  cin>>opt;
  if (opt==1)
  {  
     cout<<"enter the value :: ";
     cin>>val;
     b.insert(val);
  }
  else if (opt==2)
  { 
     cout<<"enter the value to be deleted :: ";
     cin>>val;
     b.remove(val);
  }
  else if (opt==3)
  {  
     b.print();
  }
  else if (opt==4)
  {  
    cout<<"enter the value to be searched :: ";
     cin>>val;
     bool ans=b.search(val);
     if(ans){
      cout<<"Element found!!"<<endl;
     }
     else{
      cout<<"Element not found!!"<<endl;
     }
     
  }
  
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
  return 0;
}