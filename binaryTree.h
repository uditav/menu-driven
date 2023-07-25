#include<iostream>
#include "queue"
using namespace std;
/*
template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};
*/

void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

void inOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	cout<<root->data<<" ";
	postOrder(root->right);
}

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}


void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size()!=0){
		BinaryTreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
        
        cout<<front->data<<":";

		if(front->left!=NULL){
			cout<<"L:"<<front->left->data<<",";
            pendingNodes.push(front->left);
                }
		else{
                  cout << "L:" << -1 << ",";
                }

        if (front->right != NULL) {
                  cout << "R:" << front->right->data << endl;
                  pendingNodes.push(front->right);
        } else {
                  cout << "R:" << -1 << endl;
         }
     }
}

int numNodes(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
}

int binaryTreemain(){
 BinaryTreeNode<int>* root;
   int opt,pos,val;
  char ch='y';
  while ((ch=='y') || (ch=='Y'))
  {cout<<"Menu"<<endl;
  cout<<"Press 1 for Insertion"<<endl;
  cout<<"Press 2 for number of nodes"<<endl;
  cout<<"Press 3 for display"<<endl;
  cout<<"Enter your choice :: ";
  cin>>opt;
  if (opt==1)
  {  
     root=takeInputLevelWise();
     
  }
  else if (opt==2)
  { 
    int ans=numNodes(root);
		cout<<"No of nodes :: "<<ans<<endl;
  }
  else if (opt==3)
  {  
		int opt1;
    cout<<"Press 1 for In-order traversal"<<endl;
    cout<<"Press 2 for Pre-order traversal"<<endl;
    cout<<"Press 3 for Post-order traversal"<<endl;
    cout<<"Enter your choice :: ";
    cin>>opt1;
	  if(opt1==1){
		  inOrder(root);
			cout<<endl;
	  }
	  else if(opt1==2){
      preOrder(root);
			cout<<endl;
	  }
	  else if(opt1==3){
      postOrder(root);
			cout<<endl;
	  }
  }
  
    cout<<"Do you want to continue the program ?? Press y/n"<<endl;
  cin>>ch;
  }
	delete root;
}