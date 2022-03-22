#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1)
        return 0;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    cout << "Enter the number to check whether its prime or not : ";
    cin >> n;
    if (isPrime(n))
        cout << "Prime";
    else
        cout << "Not Prime";
    return 0;
}
