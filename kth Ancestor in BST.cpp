#include<iostream>
using namespace std;
struct node{
	int key;
	node* left;
	node* right;
	
	node(int value){
		key= value;
		left= nullptr;
		right= nullptr;
	}
};

node* FindKthAncestor(node* root, int target, int &k){
	if(root==nullptr){
		return nullptr;
	}
	
	if(root->key == target){
		return root;
	}
	
	if(root->key < target){
		root->right = FindKthAncestor(root->right, target, k);
	}
	else{
		root->left= FindKthAncestor(root->left, target, k);
	}
	
	if(root->left || root->right){
		k--;
		if(k==0){
			cout<<"Kth Ancestor is:  "<<root->key<<endl;
			return nullptr;
		}
		return root;
	}
	return nullptr;
}

void findAncestor(node* root,int  target, int &k){
	FindKthAncestor(root, target, k);
	if(k > 0){
		cout<<"Kth Ancestor does'nt exist."<<endl;
	}
}

int main(){
	node* root= new node(20);
	root->left= new node(13);
	root->right= new node(23);
	root->left->left= new node(9);
	root->left->right= new node(15);
	root->right->left= new node(21);
	root->right->right= new node(26);
	
	int k=2;
	findAncestor(root, 26, k);
	return 0;
	
}