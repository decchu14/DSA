// program to implement Insertion and deletion in Binary Search Tree

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insertBST(struct node *root, int val)
{

    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = NULL;
        root->right = NULL;
        root->data = val;
        return root;
    }
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool searchnode(int srch, struct node *root)
{
    if (root == NULL)
        return false;
    if (root->data == srch)
        return true;

    if (srch < root->data)
        return searchnode(srch, root->left);
    else
        return searchnode(srch, root->right);
}

struct node *minnode(struct node *root)
{
    struct node *minptr;
    minptr = root;
    while (minptr->left != NULL)
    {
        minptr = minptr->left;
    }
    return minptr;
}

struct node *maxnode(struct node *root)
{
    struct node *maxptr;
    maxptr = root;
    while (maxptr->left != NULL)
    {
        maxptr = maxptr->left;
    }
    return maxptr;
}

struct node *deleteBST(struct node *root, int del)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == del)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            int mini = minnode(root->right)->data;
            root->data = mini;
            root->right = deleteBST(root->right, mini);
            delete root;
        }
    }
    else if (del < root->data)
    {
        root->left = deleteBST(root->left, del);
        return root;
    }
    else
    {
        root->right = deleteBST(root->right, del);
        return root;
    }
}

int main()
{
    struct node *root = NULL;

    int ch, val, srch, del;
    cout << "---MENU---" << endl;
    cout << "1. Insert a Node" << endl;
    cout << "2. Delete a Node" << endl;
    cout << "3. Search a Node" << endl;
    cout << "4. Display Binary Search in inorder" << endl;
    cout << "5. Display Minimum and Maximum Node Value" << endl;
    cout << "6. Exit" << endl;
    while (1)
    {
        cout << "Enter your choice : ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter the node value : ";
            cin >> val;
            root = insertBST(root, val);
        }
        else if (ch == 2)
        {
            cout << "Enter the node value to delete : ";
            cin >> del;
            root = deleteBST(root, del);
        }
        else if (ch == 3)
        {
            cout << "Enter the node value to search : ";
            cin >> srch;

            if (searchnode(srch, root))
                cout << "Found" << endl;
            else
                cout << "Not Found" << endl;
        }
        else if (ch == 4)
        {
            inorder(root);
            cout << endl;
        }
        else if (ch == 5)
        {
            cout << "MAX : " << maxnode(root) << endl;
            cout << "MIN : " << minnode(root) << endl;
        }
        else if (ch == 6)
            break;
        else
            cout << "Invalid Option" << endl;
    }
    return 0;
}
