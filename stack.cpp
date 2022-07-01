#include <iostream>
using namespace std;
#define MAX 5

int stk[MAX], top = -1;

void push()
{
    int ele;
    if (top == MAX - 1)
        cout << "Stack is full" << endl;
    else
    {
        cout << "Enter the element to push into the stack = ";
        cin >> ele;
        stk[++top] = ele;
    }
}

void pop()
{
    if (top == -1)
        cout << " Stack is empty" << endl;
    else
    {
        cout << "The popped element = " << stk[top--] << endl;
    }
}

void display()
{
    if (top == -1)
        cout << " Stack is empty" << endl;
    else
    {
        cout << "The stack elements = ";
        for (int i = 0; i <= top; i++)
        {
            cout << stk[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "---------MENU----------" << endl;
    cout << "1. Push the element into the Stack" << endl;
    cout << "2. Pop the element from the stack" << endl;
    cout << "3. Display the elements of the stack" << endl;
    cout << "4. Exit" << endl;

    int ch;
    while (1)
    {
        cout << "Enter your Choice = ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            cout << "Enter the valid choice" << endl;
        }
    }
    return 0;
}
