#include <iostream>
using namespace std;
#define MAX 5

int dq[MAX];
int rear = -1, front = -1;

void dq_insert_rear()
{
    int ele;
    if (rear == MAX - 1)
        cout << "Rear end is full" << endl;
    else
    {
        cout << "Enter the element to insert from rear end : ";
        cin >> ele;
        dq[++rear] = ele;
        if (front == -1)
            front = 0;
    }
}

void dq_insert_front()
{
    int ele;
    if (front == 0)
        cout << "Front end is full" << endl;
    else
    {
        cout << "Enter the element to insert from front end : ";
        cin >> ele;
        if (front == -1)
        {
            dq[++front] = ele;
            rear = 0;
        }
        else
            dq[--front] = ele;
    }
}

void dq_delete_rear()
{
    if (rear == -1)
        cout << "Rear end is empty" << endl;
    else
    {
        cout << "The deleted element from rear end : " << dq[rear--] << endl;
        if (rear < front)
        {
            rear = -1;
            front = -1;
        }
    }
}

void dq_delete_front()
{
    if (front == -1)
        cout << "Front end is empty" << endl;
    else
    {
        cout << "The deleted element from front end : " << dq[front++] << endl;
        if (rear < front)
        {
            rear = -1;
            front = -1;
        }
    }
}
void dq_display()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else
    {
        cout << "The elements in the queue : ";
        for (int i = front; i <= rear; i++)
        {
            cout << dq[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cout << "-----------MENU-----------" << endl;
    cout << "1. Insert into Queue from rear end" << endl;
    cout << "2. Insert into Queue from front end" << endl;
    cout << "3. Delete from Queue from rear end" << endl;
    cout << "4. Delete from Queue from front end" << endl;
    cout << "5. Display Queue Elements " << endl;
    cout << "6. Exit" << endl;

    cout << endl;
    int ch;
    while (1)
    {
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            dq_insert_rear();
            break;

        case 2:
            dq_insert_front();
            break;

        case 3:
            dq_delete_rear();
            break;

        case 4:
            dq_delete_front();
            break;

        case 5:
            dq_display();
            break;

        case 6:
            exit(0);

        default:
            cout << "Please enter the valid choice " << endl;
        }
    }
    return 0;
}
