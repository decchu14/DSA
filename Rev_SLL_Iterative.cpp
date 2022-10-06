#include <iostream>
#include <stdlib.h>

using namespace std;
typedef struct node
{
    int data;
    struct node *ptr;
} NODE;

int main()
{
    NODE *head = NULL;
    NODE *newnode;
    NODE *temp;
    int n;
    cout << "Enter the total number of nodes you want to insert :";
    cin >> n;

    int val;
    cout << "Enter the data for nodes : ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        newnode = (NODE *)malloc(sizeof(newnode));
        newnode->data = val;
        newnode->ptr = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->ptr != NULL)
            {
                temp = temp->ptr;
            }
            temp->ptr = newnode;
        }
    }

    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->ptr;
    }
    cout << endl;
    // to reverse a linked list
    NODE *prev = NULL;
    NODE *curr = head;
    NODE *next = NULL;

    if (n == 1)
        cout << head->data << endl;
    else
    {
        while (curr != NULL)
        {
            next = curr->ptr;
            curr->ptr = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->ptr;
        }
        cout << endl;
    }

    return 0;
}