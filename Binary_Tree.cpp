// program to implement Binary Tree

#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *buildTree()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int x;
    cout << "Enter the value : ";
    cin >> x;
    if (x == -1)
        return 0;
    newnode->data = x;

    cout << "create the left node for : " << x << " : ";
    newnode->left = buildTree();
    cout << "Create the right node for : " << x << ":";
    newnode->right = buildTree();
    return newnode;
}

void inorder(struct node *root)
{
    if (root == 0)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == 0)
        return;

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == 0)
        return;

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

void levelorder(struct node *root)
{
    if (root == 0)
        return;

    queue<struct node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct node *current = q.front();
        cout << current->data << " ";
        if (current->left != 0)
            q.push(current->left);
        if (current->right != 0)
            q.push(current->right);
        q.pop();
    }
}
int main()
{
    struct node *root;
    cout << "------------Building Tree-----------" << endl;
    root = buildTree();
    cout << "------------TREAVERSALS-----------" << endl;
    cout << "1. Level Order Traversal : ";
    levelorder(root);
    cout << endl;
    cout << "2. InOrder Traversal : ";
    inorder(root);
    cout << endl;
    cout << "3. PreOrder Traversal : ";
    preorder(root);
    cout << endl;
    cout << "4. PostOrder Traversal : ";
    postorder(root);
    cout << endl;
    return 0;
}
