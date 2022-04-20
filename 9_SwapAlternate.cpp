#include <iostream>
using namespace std;

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void SwapAlternate(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i = i + 2)
    {
        temp = arr[i];
        arr[i] = arr[i - 1];
        arr[i - 1] = temp;
    }
    PrintArray(arr, n);
}

int main()
{
    int even[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int odd[5] = {1, 2, 3, 4, 5};

    SwapAlternate(even, 8);
    SwapAlternate(odd, 5);
    return 0;
}