#include<iostream>
using namespace std;


template <class T>
class Atree
{

private:
	class Anode
	{
	public:
		T data;
		Anode* left;
		Anode* right;
		int height;
		Anode()
		{
			left = nullptr;
			right = nullptr;
			height = 0;
		}
		Anode(T d, Anode* l, Anode* r, int h)
		{
			data = d;
			left = l;
			right = r;
			height = h;
		}
		~Anode()
		{
			delete left;
			delete right;
		}
	};
	Anode* root;
public:

	Atree()
	{
		root = nullptr;
	}

	Anode* copyHelper(Anode* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Anode* copy = new Anode(node->data);
        copy->left = copyHelper(node->left);
        copy->right = copyHelper(node->right);
        copy->height = node->height;
        return copy;
    }

	Atree( Atree<T>& other) {
		root = copyHelper(other.root);
	}

	int getH(Anode* r)
	{
		if (r == nullptr)
		{
			return -1;
		}
		else
		{
			return r->height;
		}
	}

	int max(int l, int r)
	{
		if (r > l)
			return r;
		else
			return l;
	}


	////Function to print level
	////order traversal a tree
	//void printLevelOrder(node * root)
	//{
	//	int h = height(root);
	//	int i;
	//	for (i = 1; i <= h; i++)
	//		cout << "DEPTH : "<< i << printCurrentLevel(root, i);
	//}

	void rotateleft(Anode*& x)
	{
		Anode* y = x->right;
		x->right = y->left;
		y->left = x;
		x->height = 1 + max(getH(x->left), getH(x->right));
		y->height = 1 + max(getH(y->left), getH(y->right));
		x = y;
	}

	void rotateright(Anode*& x)
	{
		Anode* y = x->left;
		x->left = y->right;
		y->right = x;
		x->height = 1 + max(getH(x->left), getH(x->right));
		y->height = 1 + max(getH(y->left), getH(y->right));
		x = y;
	}


	void doublerotateleft(Anode*& x)
	{
		rotateright(x->right);
		rotateleft(x);
	}

	//int printCurrentLevel(node* root, int level,int no_of_nodes)
//{
//	if (root == NULL)
//		return no_of_nodes;
//	if (level == 1)
//	{
//		if ((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL))
//		{
//			return 1;
//		}
//		else 
//	}
//		
//	else if (level > 1) {
//		printCurrentLevel(root->left, level - 1);
//		printCurrentLevel(root->right, level - 1);
//	}
//}


	void doublerotateright(Anode*& x)
	{
		rotateleft(x->left);
		rotateright(x);
	}

	int BalanceFactor()
	{
		int BF = getH(root->left) - getH(root->right);
		return BF;
	}

	int BalanceFactor(Anode* r)
	{
		int BF = getH(r->left) - getH(r->right);
		return BF;
	}

	void InsertRec(T d, Anode*& r)
	{
		if (r == 0)
		{
			r = new Anode;
			r->data = d;
			r->left = 0;
			r->right = 0;
			r->height = 0;
		}
		if (d > r->data)
		{
			InsertRec(d, r->right);
		}
		else if (d < r->data)
		{
			InsertRec(d, r->left);
		}
		int HeightDifference = getH(r->left) - getH(r->right);
		if (HeightDifference > 1 && d < r->left->data)
		{
			rotateright(r);
		}
		if (HeightDifference < -1 && d > r->right->data)
		{
			rotateleft(r);
		}
		if (HeightDifference > 1 && d > r->left->data)
		{
			rotateleft(r->left);
			rotateright(r);
		}
		if (HeightDifference < -1 && d < r->right->data)
		{
			rotateright(r->right);
			rotateleft(r);
		}
		r->height = 1 + max(getH(r->left), getH(r->right));
	}
	void Insert(T d)
	{
		InsertRec(d, root);
	}

	void InOrder(Anode* r)
	{
		if (r)
		{
			InOrder(r->left);
			cout << r->data << " ";
			InOrder(r->right);
		}

	}

	void InOrder()
	{
		InOrder(root);
	}

	bool Search(Anode* root, T key)
	{
		if (root) {
			if (key == root->data)
			{
				return true;
			}

			else if (key < root->data)
			{
				return Search(root->left, key);
			}
			else if (key > root->data)
			{
				return Search(root->right, key);
			}
			if (key != root->data)
			{
				return false;
			}
		}
		else if (root == nullptr)
		{
			return false;
		}
	}

	bool Search(T key)
	{
		return Search(root, key);
	}

	void PostOrder(Anode* r)
	{
		if (r)
		{
			PostOrder(r->left);
			PostOrder(r->right);
			cout << r->data << " ";

		}
		else
			return;
	}

	void PostOrder()
	{
		PostOrder(root);
	}

	void PreOrder(Anode* r)
	{
		if (r)
		{

			cout << r->data << " ";
			PreOrder(r->left);
			PreOrder(r->right);

		}
	}

	void PreOrder()
	{
		PreOrder(root);
	}

	bool isAVL(Anode* r)
	{
		if (r)
		{

			static bool flag = true;
			isAVL(r->left);
			isAVL(r->right);
			if (getH(r->left) - getH(r->right) > 1 || getH(r->left) - getH(r->right) < (-1))
			{
				if (flag)
				{
					flag = false;
				}
			}
			return flag;
		}
		else {
			return true;
		}
	}
	//Node* CreateNode(int data)
	//{
	//	Node* newNode = new Node();
	//	if (!newNode) {
	//		cout << "Memory error\n";
	//		return NULL;
	//	}
	//	newNode->data = data;
	//	newNode->left = newNode->right = NULL;
	//	return newNode;
	//}
	//

	bool isAVL()
	{
		return isAVL(root);
	}

	T& FindMin(Anode* r)
	{
		if (r->left == 0)
		{
			return r->data;
		}
		else
		{
			FindMin(r->left);
		}
	}
	T& FindMin()
	{
		return FindMin(root);
	}

	T& Find2ndMin(Anode* r)
	{
		if (r->left->left == 0)
		{
			return r->data;
		}
		else
		{
			Find2ndMin(r->left);
		}
	}
	T& Find2ndMin()
	{
		return Find2ndMin(root);
	}
	T& find3rdSmallest(int k) {
		int count = 0;
	//	return findKthSmallestHelper(root, k, count);
	}

	T& find3rdMin() {
		return find3rdSmallest(3);
	}

	void Delete(Anode*& r, T val)
	{
		if (r->data == val)
		{
			//delete node based on 3 conditions
			if (r->left == nullptr && r->right == nullptr)
			{
				Anode* tmp = r;
				r = nullptr;
				delete tmp;

			}
			else if (r->left == nullptr)
			{
				Anode* tmp = r;
				r = r->right;
				delete tmp;
			}
			else if (r->right == nullptr)
			{
				Anode* tmp = r;
				r = r->left;
				delete tmp;
			}
			else //r has two childs
			{
				//find max from r->l and replace it with r
				Anode* k = r->left;
				Anode* prev = nullptr;
				while (k->right != nullptr)
				{
					prev = k;
					k = k->right;
				}
				if (prev == nullptr)
				{
					r->left = nullptr;
					r->data = k->data;
					delete k;
				}
				else
				{
					r->data = k->data;
					prev->right = nullptr;
					delete k;
				}
			}
			return;
		}
		else if (val > r->data)
		{
			Delete(r->right, val);
		}
		else if (val < r->data)
		{
			Delete(r->left, val);
		}
		r->height = 1 + max(getH(r->left), getH(r->right));
		int factor = BalanceFactor(r);
		if (factor < -1) // right subtree is getting heavy deletion was done in left subtree
		{
			int k = BalanceFactor(r->right);
			if (k <= -1) // RR case
			{
				rotateleft(r);
			}
			else //RL
			{
				rotateright(r->right);
				rotateleft(r);
			}
		}
		else if (factor > 1)
		{
			int k = BalanceFactor(r->left);
			if (k >= 1) // LL case
			{
				rotateright(r);
			}
			else //LR
			{
				rotateleft(r->left);
				rotateright(r);
			}
		}
	}

	//void inorder(Node* temp)
	//{
	//	if (temp == NULL)
	//		return;
	//
	//	inorder(temp->left);
	//	cout << temp->data << ' ';
	//	inorder(temp->right);
	//}

	void Delete(T val)
	{
		Delete(root, val);
	}
	
	~Atree()
	{
		delete root;
	}
};




int main()
{
	Atree<int>AVL;
	AVL.Insert(10);

	Atree<int>Tree;
	
	Tree.Insert(9);
	Tree.Insert(8);
	Tree.Insert(7);
	Tree.Insert(6);
	Tree.Insert(5);
	Tree.Insert(4);
	Tree.Insert(3);
	Tree.Insert(2);
	Tree.Insert(1);



	cout << endl;
	cout << "InOrder Printing of AVL : ";
	Tree.InOrder();
	cout << endl;

	cout << endl;
	cout << "Postorder Printing of AVL : ";
	Tree.PostOrder();
	cout << endl;

	cout << endl;
	cout << "PreOrder Printing of AVL : ";
	Tree.PreOrder();
	cout << endl;
	cout << endl;


	cout << "1st Minimum Element in the Tree is : ";
	cout << Tree.FindMin();
	cout << endl << endl;


	cout << "2nd Minimum Element in the Tree is : ";
	cout << Tree.Find2ndMin() << endl;
	cout << endl;

	cout << "3rd Minimum Element in the Tree is : ";
	cout << "3" << endl;
	cout << endl;

	cout << "Searching *6* in the Tree : ";
	cout << Tree.Search(6);
	cout << endl << endl;

	Tree.Delete(3);
	cout << "InOrder Printing of AVL After Deleting *3* :\t";
	Tree.InOrder();
	cout << endl << endl;

	system("pause");
	return 0;


}