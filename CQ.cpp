#include <iostream>
using namespace std;
#define MAX 5

int cq[MAX];
int rear = -1, front = -1;

void cq_insert()
{
    int ele;
    if ((rear + 1) % MAX == front)
        cout << "Queue is full" << endl;
    else
    {
        cout << "Enter the element to insert into queue : ";
        cin >> ele;
        rear = (rear + 1) % MAX;
        cq[rear] = ele;
        if (front == -1)
            front = 0;
    }
}

void cq_delete()
{
    if (rear == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "The Deleted element : " << cq[front] << endl;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % MAX;
    }
}

void cq_display()
{
    if (rear == -1)
        cout << "Queue is empty" << endl;
    else if (front <= rear)
    {
        cout << "The elements in the queue : ";
        for (int i = front; i <= rear; i++)
            cout << cq[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "The elements in the queue : ";
        for (int i = front; i < MAX; i++)
            cout << cq[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << cq[i] << " ";
        cout << endl;
    }
}
int main()
{
    cout << "-----------MENU-----------" << endl;
    cout << "1. Insert into Queue" << endl;
    cout << "2. Delete from Queue" << endl;
    cout << "3. Display Queue Elements" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    int ch;
    while (1)
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cq_insert();
            break;

        case 2:
            cq_delete();
            break;

        case 3:
            cq_display();
            break;

        case 4:
            exit(0);

        default:
            cout << "Please enter the valid choice " << endl;
        }
    }
    return 0;
}
