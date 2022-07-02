#include <iostream>
using namespace std;
#define MAX 5

int lq[MAX];
int rear = -1, front = -1;

void lq_insert()
{
    int ele;
    if (rear == MAX - 1)
        cout << "Queue is full" << endl;
    else
    {
        cout << "Enter the element to insert into queue : ";
        cin >> ele;
        lq[++rear] = ele;
        if (front == -1)
            front++;
    }
}

void lq_delete()
{
    if (rear == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "The Deleted element : " << lq[front++] << endl;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

void lq_display()
{
    if (rear == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "The elements in the queue : ";
        for (int i = front; i <= rear; i++)
            cout << lq[i] << " ";
        cout << endl;
    }
}
int main()
{
    cout << "-----------MENU-----------" << endl;
    cout << "1. Insert into Queue" << endl;
    cout << "2. Delete from Queue" << endl;
    cout << "3. Display Queue Elements" << endl;
    cout << "4.Exit" << endl;
    cout << endl;
    int ch;
    while (1)
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            lq_insert();
            break;

        case 2:
            lq_delete();
            break;

        case 3:
            lq_display();
            break;

        case 4:
            exit(0);

        default:
            cout << "Please enter the valid choice " << endl;
        }
    }
    return 0;
}
