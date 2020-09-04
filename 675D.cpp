#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> ans;
class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           int data;
        };
        tree_node* root;
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
       
        bool isEmpty() const { return root==NULL; }
        void insert(int);
};

void BinarySearchTree::insert(int d)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    
    if(isEmpty()) root = t;
    else
    {
        tree_node* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(t->data > curr->data) curr = curr->right;
            else curr = curr->left;
        }

        if(t->data < parent->data)
           parent->left = t;
        else
           parent->right = t;
        ans.push_back(parent->data);
    }
}

int main()
{
    BinarySearchTree b;
    
    int n;cin >>n;
    for (int i = 0;i < n; ++i){
		int x;cin >> x;
		b.insert(x);
	}
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << " ";
}
