#include <iostream>
#include <math.h>
using namespace std;

void fibonacci(int n)
{

    int fib1 = 0;
    int fib2 = 1;
    int fib3 = 0;
    cout << fib1 << " " << fib2 << " ";
    for (int i = 2; i < n; i++)
    {
        fib3 = fib1 + fib2;
        cout << fib3 << " ";
        fib1 = fib2;
        fib2 = fib3;
    }
}

int main()
{
    int n;
    cout << "Enter n to find n fibonacci series: ";
    cin >> n;
    fibonacci(n);
    return 0;
}
