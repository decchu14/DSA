// program to implement singly linked list

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *ptr;
} NODE;

class llist
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
    llist ll;
    NODE *head = NULL;
    int ch;

    cout << "-----------MENU-----------" << endl;
    cout << "1. Insert node at the beginning" << endl;
    cout << "2. Insert node at the end" << endl;
    cout << "3. Insert node at the specified position" << endl;
    cout << "4. Delete node from the beginning" << endl;
    cout << "5. Delete node from the end" << endl;
    cout << "6. Delete node from the specified position" << endl;
    cout << "7. Display the elements in the Singly linked list" << endl;
    cout << "8. Exit" << endl;

    while (1)
    {
        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            head = ll.fnInsertBegin(head);
            break;

        case 2:
            head = ll.fnInsertEnd(head);
            break;

        case 3:
            head = ll.fnInsertPos(head);
            break;

        case 4:
            head = ll.fnDeleteBegin(head);
            break;

        case 5:
            head = ll.fnDeleteEnd(head);
            break;

        case 6:
            head = ll.fnDeletePos(head);
            break;

        case 7:
            ll.fnDisplay(head);
            break;

        case 8:
            exit(0);

        default:
            cout << "Enter Valid Option" << endl;
        }
    }
    return 0;
}
NODE *llist ::fnInsertBegin(NODE *head)
{
    // creating a pointer variable to hold the address which points to empty location
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(newnode));

    // taking input to data part of the node
    int num;
    cout << "Enter the data to insert it at the beginning : ";
    cin >> num;

    // filling the 2 parts of the node that is data part and address part
    newnode->data = num;
    newnode->ptr = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        newnode->ptr = head;
        head = newnode;
    }
    return head;
}

NODE *llist ::fnInsertEnd(NODE *head)
{
    // creating a pointer variable to hold the address which points to empty location
    NODE *newnode, *temp;
    newnode = (NODE *)malloc(sizeof(newnode));

    // taking input to data part of the node
    int num;
    cout << "Enter the data to insert it at the end : ";
    cin >> num;

    // filling the 2 parts of the node that is data part and address part
    newnode->data = num;
    newnode->ptr = NULL;

    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while (temp->ptr != NULL)
            temp = temp->ptr;
        temp->ptr = newnode;
    }
    return head;
}
NODE *llist ::fnInsertPos(NODE *head)
{
    // taking input to position
    int pos;
    cout << "Enter the position where you want to insert the new node : ";
    cin >> pos;

    // counting how many nodes are there in the list
    int count = 1;
    NODE *temp;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->ptr;
    }

    // checking whether the entered position is valid or not
    if (pos > count)
        cout << "Invalid Position" << endl;
    else
    {
        // creating a pointer variable to hold the address which points to empty location
        NODE *newnode;
        newnode = (NODE *)malloc(sizeof(newnode));

        // taking input to data part of the node
        int num;
        cout << "Enter the data to insert : ";
        cin >> num;

        // filling the 2 parts of the node that is data part and address part
        newnode->data = num;
        newnode->ptr = NULL;

        if (head == NULL) // if list is empty
            head = newnode;
        else if (pos == 1) // if insert in the begin
        {
            newnode->ptr = head;
            head = newnode;
        }
        else if (pos == count) // if inserting at the end
        {
            temp = head;
            while (temp->ptr != NULL)
                temp = temp->ptr;

            temp->ptr = newnode;
        }
        else // if inserting in middle
        {
            NODE *temp1, *temp2;
            temp2 = head;
            for (int i = 1; i < pos; i++)
            {
                temp1 = temp2;
                temp2 = temp2->ptr;
            }
            temp1->ptr = newnode;
            newnode->ptr = temp2;
        }
    }

    return head;
}
NODE *llist ::fnDeleteBegin(NODE *head)
{
    NODE *temp;
    if (head == NULL)
        cout << "The list is empty" << endl;
    else
    {
        cout << "The deleted node : " << head->data << endl;
        temp = head;
        if (head->ptr == NULL)
            head = NULL;
        else
        {
            head = head->ptr;
            temp->ptr = NULL;
        }
        free(temp);
    }
    return head;
}
NODE *llist ::fnDeleteEnd(NODE *head)
{
    NODE *temp1, *temp2;
    if (head == NULL)
        cout << "The list is empty" << endl;
    else if (head->ptr == NULL)
    {
        cout << "The deleted node : " << head->data << endl;
        temp1 = head;
        head = NULL;
        free(temp1);
    }
    else
    {
        temp2 = head;
        while (temp2->ptr != NULL)
        {
            temp1 = temp2;
            temp2 = temp2->ptr;
        }
        cout << "The deleted node : " << temp2->data << endl;
        temp1->ptr = NULL;
        free(temp2);
    }

    return head;
}
NODE *llist ::fnDeletePos(NODE *head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
        return head;
    }
    // taking input to position
    int pos;
    cout << "Enter the position of the node to delete : ";
    cin >> pos;

    // counting how many nodes are there in the list
    int count = 0;
    NODE *temp;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->ptr;
    }

    // checking whether the entered position is valid or not
    if (pos > count)
        cout << "Invalid Position" << endl;
    else
    {
        NODE *temp1, *temp2;
        if (head->ptr == NULL) // if only one node exists and position given is 1
        {
            cout << "The deleted node : " << head->data << endl;
            temp1 = head;
            head = NULL;
            free(temp1);
        }
        else if (pos == 1)
        {
            cout << "The deleted node : " << head->data << endl;
            temp1 = head;
            head = head->ptr;
            free(temp1);
        }
        else if (pos == count) // if deleting node is the last node
        {

            temp2 = head;
            while (temp2->ptr != NULL)
            {
                temp1 = temp2;
                temp2 = temp2->ptr;
            }
            cout << "The deleted node : " << temp2->data << endl;
            temp1->ptr = NULL;
            temp = temp2;
            temp2 = NULL;
            free(temp);
        }
        else // if deleting node is in middle
        {
            temp2 = head;
            for (int i = 1; i < pos; i++)
            {
                temp1 = temp2;
                temp2 = temp2->ptr;
            }
            cout << "The deleted node : " << temp2->data << endl;
            temp1->ptr = temp2->ptr;
            temp = temp2;
            temp2 = NULL;
            free(temp);
        }
    }
    return head;
}
void llist::fnDisplay(NODE *head)
{
    NODE *temp;
    temp = head;

    if (head == NULL)
        cout << "The list is empty" << endl;
    else
    {

        cout << "The elements are : ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->ptr;
        }
        cout << endl;
    }
}