#include <iostream>
#include <malloc.h>
using namespace std;

class DMAStack
{
    int total_size;
    int curr_size;
    int *arr;

public:
    DMAStack(int size)
    {
        this->total_size = size;
        this->curr_size = 0;
        this->arr = (int *)malloc(this->total_size * sizeof(int *));
    }

    bool isEmpty()
    {
        return this->curr_size == 0;
    }

    bool isFull()
    {
        return this->curr_size == this->total_size;
    }

    void push(int value)
    {
        if (isFull())
            cout << "Stack Overflow" << endl;
        else
            this->arr[this->curr_size++] = value;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
            return this->arr[--this->curr_size];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Nothing to return" << endl;
            return -1;
        }
        else
            return this->arr[this->curr_size - 1];
    }

    void display()
    {
        if (isEmpty())
            cout << "Nothing to Display" << endl;
        else
        {
            for (int i = 0; i < this->curr_size; i++)
            {
                cout << this->arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    DMAStack *s1 = new DMAStack(5);
    int ch, value, pop_ele, peek_ele;

    cout << "------MENU--------" << endl;
    cout << "1. Push into the Stack" << endl;
    cout << "2. Pop from the Stack" << endl;
    cout << "3. Return peek element" << endl;
    cout << "4. Display Elements from the stack" << endl;
    cout << "5. exit" << endl;

    while (true)
    {

        cout << "Enter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value to push into the stack : ";
            cin >> value;
            s1->push(value);
            break;

        case 2:
            pop_ele = s1->pop();
            if (pop_ele != -1)
                cout << "The popped element : " << pop_ele << endl;
            break;
        case 3:
            peek_ele = s1->peek();
            if (pop_ele != -1)
                cout << "The peek element : " << peek_ele << endl;
            break;

        case 4:
            s1->display();
            break;

        case 5:
            exit(0);
        }
    }
    return 0;
}