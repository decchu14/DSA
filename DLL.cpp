// program to implement doubly linked list

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} NODE;

class dlist
{
public:
    NODE *fnInsertBegin(NODE *head);
    NODE *fnInsertEnd(NODE *head);
    NODE *fnInsertPos(NODE *head);
    NODE *fnDeleteBegin(NODE *head);
    NODE *fnDeleteEnd(NODE *head);
    NODE *fnDeletePos(NODE *head);
    void fnDisplay(NODE *head);
};

int main()
{
    dlist dl;
    int ch;
    NODE *head = NULL;

    cout << "----------------MENU-------------" << endl;
    cout << "1. Insert at begin" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Insert at specified position" << endl;
    cout << "4. Delete from begin" << endl;
    cout << "5. Delete from end" << endl;
    cout << "6. Delete from specified position" << endl;
    cout << "7. Display the elements of doubly linked list" << endl;
    cout << "8. Exit" << endl;

    while (1)
    {
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            head = dl.fnInsertBegin(head);
            break;
        case 2:
            head = dl.fnInsertEnd(head);
            break;
        case 3:
            head = dl.fnInsertPos(head);
            break;
        case 4:
            head = dl.fnDeleteBegin(head);
            break;
        case 5:
            head = dl.fnDeleteEnd(head);
            break;
        case 6:
            head = dl.fnDeletePos(head);
            break;
        case 7:
            dl.fnDisplay(head);
            break;
        case 8:
            exit(0);

        default:
            cout << "Invalid Choice" << endl;
        }
    }
}

NODE *dlist::fnInsertBegin(NODE *head)
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(newnode));

    int num;
    cout << "Enter the data to insert it at the beginning : ";
    cin >> num;

    newnode->data = num;
    newnode->right = NULL;
    newnode->left = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        newnode->right = head;
        head->left = newnode;
        head = newnode;
    }

    return head;
}

NODE *dlist::fnInsertEnd(NODE *head)
{
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(newnode));

    int num;
    cout << "Enter the data to insert it at the end : ";
    cin >> num;

    newnode->data = num;
    newnode->right = NULL;
    newnode->left = NULL;

    temp = head;
    if (head == NULL)
        head = newnode;
    else
    {
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = newnode;
        newnode->left = temp;
    }
    return head;
}

NODE *dlist::fnInsertPos(NODE *head)
{
    int pos;
    cout << "Enter the position in which you want to enter the data : ";
    cin >> pos;

    int count = 0;
    NODE *temp;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    if (pos > count + 1 || pos < 1)
    {
        cout << "Invalid position" << endl;
        return head;
    }

    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(newnode));

    int num;
    cout << "Enter the data to insert it at the position : ";
    cin >> num;

    newnode->data = num;
    newnode->right = NULL;
    newnode->left = NULL;

    NODE *temp1, *temp2;

    if (pos == 1 && count == 0)
    {
        head = newnode;
        return head;
    }
    else if (pos == 1)
    {
        newnode->right = head;
        head->left = newnode;
        head = newnode;
    }
    else if (count == 1 && pos == 2)
    {
        newnode->left = head;
        head->right = newnode;
    }
    else if (pos == count + 1)
    {
        temp1 = head;
        while (temp1->right != NULL)
        {
            temp1 = temp1->right;
        }

        newnode->left = temp1;
        temp1->right = newnode;
    }
    else
    {

        temp1 = head;
        temp2 = head->right;

        for (int i = 0; i < pos - 2; i++)
        {
            temp1 = temp1->right;
            temp2 = temp2->right;
        }

        newnode->right = temp2;
        // cout << newnode << endl;
        temp2->left = newnode;

        newnode->left = temp1;

        temp1->right = newnode;
    }

    return head;
}

NODE *dlist::fnDeleteBegin(NODE *head)
{
    NODE *temp1;
    if (head == NULL)
        cout << "Doubly linked list is empty" << endl;
    else
    {
        cout << "The delete node : " << head->data << endl;
        temp1 = head;
        if (head->right == NULL)
            head = NULL;
        else
        {
            head = temp1->right;
            head->left = NULL;
            temp1->left = NULL;
            free(temp1);
        }
    }
    return head;
}

NODE *dlist::fnDeleteEnd(NODE *head)
{
    NODE *temp, *temp1;
    if (head == NULL)
        cout << "Doubly linked list is empty" << endl;
    else
    {
        temp = head;
        // cout << "The deleted node is : " << temp->data << endl;

        if (head->right == NULL)
        {
            cout << "The deleted node is : " << temp->data << endl;
            head = NULL;
        }
        else
        {

            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            cout << "The deleted node is : " << temp->data << endl;
            temp1 = temp->left;
            temp1->right = NULL;
            temp1 = temp;
            temp1 = NULL;
            free(temp);
        }
    }
    return head;
}

NODE *dlist::fnDeletePos(NODE *head)
{
    int pos, count = 0;
    NODE *temp, *temp1, *temp2;
    if (head == NULL)
        cout << "The doubly linked list is empty" << endl;
    else
    {
        cout << "Enter the position of the node to delete : ";
        cin >> pos;

        // count the number of nodes present in the list
        temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->right;
        }

        if (pos > count || pos < 1)
        {
            cout << "Invalid Position" << endl;
            return head;
        }

        if (count == 1 && pos == 1)
        {
            cout << "The deleted node is : " << head->data << endl;
            head = NULL;
        }
        else if (pos == 1)
        {
            cout << "The deleted node is : " << head->data << endl;
            temp = head;
            head = head->right;
            temp = NULL;
            free(temp);
        }
        else if (count == pos)
        {
            temp = head;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }

            cout << "The deleted node is : " << temp->data << endl;
            temp1 = temp->left;
            temp1->right = NULL;
            temp = NULL;
            free(temp);
        }
        else
        {
            temp2 = head;
            for (int i = 1; i < pos; i++)
            {
                temp1 = temp2;
                temp2 = temp2->right;
            }
            temp = temp2->right;
            cout << "The deleted node is : " << temp2->data << endl;
            temp1->right = temp2->right;
            temp->left = temp2->left;

            temp2 = NULL;
            free(temp2);
        }
    }
    return head;
}

void dlist::fnDisplay(NODE *head)
{
    NODE *temp;
    temp = head;

    if (head == NULL)
        cout << "The doubly linked list is empty" << endl;
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << endl;
    }
}