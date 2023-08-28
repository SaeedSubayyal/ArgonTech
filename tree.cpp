#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
public:
	Node(int d){
		data = d;
		left = nullptr;
		right = nullptr;
			;
	}
};

void inorder(Node * r){
	if (r){
		inorder(r->left);
		cout << r->data;
		inorder(r->right);
	}
}

void preorder(Node* r){
	if (r){
		cout << r->data;
		preorder(r->left);
		preorder(r->right);
	}
}

void postorder(Node* r){
	if (r){
		postorder(r->left);
		postorder(r->right);
		cout << r->data;
	}
}


bool search(Node* root, int key) {
	if (root == NULL) {
		return false;
	}
	if (root->data == key) {
		return true;
	}
	bool exist_left = search(root->left, key);
	bool exist_right = search(root->right, key);
	if (exist_left || exist_right)
		return true;
	else
		return false;
}

Node* deleteNode(Node* root, int key){
	if (root == NULL) {
		return NULL;
	}
	if (root->data == key) {
		if (root->left == NULL && root->right == NULL) {
			delete root;								// Case 1: the node to be deleted is a leaf node
			return NULL;
		}
		else if (root->left == NULL) {
			
			Node* temp = root->right;					// Case 2: the node to be deleted has only right child
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			
			Node* temp = root->left;					// Case 2: the node to be deleted has only left child
			delete root;
			return temp;
		}
		else {											// Case 3: the node to be deleted has both left and right child
			Node* temp = root->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}
			
			root->data = temp->data;
			
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
	else {
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}
}

int max(int i, int j){
	if (i > j)
		return i;
	return j;
}

int height(Node* root) {
	if (root == NULL) {
		return 0;
	}
	int left_height = height(root->left);
	int right_height = height(root->right);
	return 1 + max(left_height, right_height);
}

void printLevel(Node* root, int level) {
	if (root == NULL) {
		return;
	}
	if (level == 1) {
		cout << root->data << " ";
	}
	else if (level > 1) {
		printLevel(root->left, level - 1);
		printLevel(root->right, level - 1);
	}
}

void printLevelOrder(Node* root) {
	int h = height(root);
	for (int i = 1; i <= h; i++) {
		printLevel(root, i);
	}
}



int getLevel(Node* root, int key, int level) {
	if (root == NULL) {
		return 0;
	}
	if (root->data == key) {
		return level;
	}
	int found_in_left = getLevel(root->left, key, level + 1);
	if (found_in_left != 0) {
		return found_in_left;
	}
	return getLevel(root->right, key, level + 1);
}

bool areCousins(Node* root, int x, int y) {
	if (root == NULL) {
		return false;
	}
	int level_x = getLevel(root, x, 1);
	int level_y = getLevel(root, y, 1);
	if (level_x != level_y) {
		return false;
	}
	if (root->left != NULL && root->right != NULL) {
		if (root->left->data == x && root->right->data == y) {
			return false;
		}
		if (root->left->data == y && root->right->data == x) {
			return false;
		}
	}
	return true;
}



int main(){
	Node* root = nullptr;
	root = new Node(6);
	root -> left = new Node(3);
	root ->right = new Node(5);
	root ->left -> left = new Node(7);
	root ->left -> right = new Node(8);
	root -> right -> left = new	Node(1);
	root -> right -> right = new Node(3);

	cout << "Inorder Traversal : ";
	inorder(root);
	cout << endl;

	cout << "Preorder Traversal : ";
	preorder(root);
	cout << endl;

	cout << "Postorder Traversal : ";
	postorder(root);
	cout << endl;

	cout << "Searching 3.... : " <<  search(root, 3) << endl;

	//deleteNode(root, 7);
	//inorder(root);
	cout << endl;

	cout << "Level Order  : ";
	printLevelOrder(root);
	cout<< endl;

	cout << "Checking Cousins : \n1 and 7  : " << areCousins(root, 1, 7);
	cout <<"\n3 and 5  : "<< areCousins(root, 3, 5);
	cout <<"\n7 and 5  : " <<  areCousins(root, 7, 5);


}