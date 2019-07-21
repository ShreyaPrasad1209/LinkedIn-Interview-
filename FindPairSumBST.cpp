// CPP program to find a pair with 
// given sum using hashing 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	struct Node *left, *right; 
}; 

Node* NewNode(int data) 
{ 
	Node* temp = (Node*)malloc(sizeof(Node)); 
	temp->data = data; 
	temp->left = NULL; 
	temp->right = NULL; 
	return temp; 
} 

Node* insert(Node* root, int key) 
{ 
	if (root == NULL) 
		return NewNode(key); 
	if (key < root->data) 
		root->left = insert(root->left, key); 
	else
		root->right = insert(root->right, key); 
	return root; 
} 

bool findpairUtil(Node* root, int sum, unordered_set<int> &set) 
{ 
	if (root == NULL) 
		return false; 

	if (findpairUtil(root->left, sum, set)) 
		return true; 

	if (set.find(sum - root->data) != set.end()) { 
		cout << "Pair is found ("
			<< sum - root->data << ", "
			<< root->data << ")" << endl; 
		return true; 
	} 
	else
		set.insert(root->data); 

	return findpairUtil(root->right, sum, set); 
} 

void findPair(Node* root, int sum) 
{ 
	unordered_set<int> set; 
	if (!findpairUtil(root, sum, set)) 
		cout << "Pairs do not exit" << endl; 
} 

// Driver code 
int main() 
{ 
	Node* root = NULL; 
	root = insert(root, 15); 
	root = insert(root, 10); 
	root = insert(root, 20); 
	root = insert(root, 8); 
	root = insert(root, 12); 
	root = insert(root, 16); 
	root = insert(root, 25); 
	root = insert(root, 10); 

	int sum = 33; 
	findPair(root, sum); 

	return 0; 
} 
