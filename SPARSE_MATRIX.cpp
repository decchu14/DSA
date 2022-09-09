// program to implement sparse matrix and transpose of a sparse matrix
#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter rows : ";
    cin >> m;
    cout << " Enter Columns : ";
    cin >> n;

    int sparse[m * n][3];
    int val, sparse_indx = 0;

    // taking inputs for sparse matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter value for [" << i << "][" << j << "] :";
            cin >> val;
            if (val != 0)
            {
                sparse[sparse_indx][0] = i;
                sparse[sparse_indx][1] = j;
                sparse[sparse_indx][2] = val;
                sparse_indx++;
            }
        }
    }

    // printing sparse matrix
    cout << "----------sparse matrix----------" << endl;
    for (int i = 0; i < sparse_indx; i++)
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;

    // modifying the sparse matrix to transpose of a sparse matrix
    int temp;
    for (int i = 0; i < sparse_indx; i++)
    {
        temp = sparse[i][0];
        sparse[i][0] = sparse[i][1];
        sparse[i][1] = temp;
    }

    // printing transpose of a sparse matrix
    cout << "----------transpose of a sparse matrix----------" << endl;
    for (int i = 0; i < sparse_indx; i++)
        cout << sparse[i][0] << " " << sparse[i][1] << " " << sparse[i][2] << endl;
    return 0;
}