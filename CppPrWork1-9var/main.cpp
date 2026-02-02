#include <iostream>
#include "array_operations.h"

using namespace std;

int main()
{
    int rows, cols;
    int arr[MAX_ROWS][MAX_COLS];

    cout << "Введите количество строк и столбцов: ";
    cin >> rows >> cols;

    cout << "Введите элементы массива:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    processArray(arr, rows, cols);

    cout << "Результат:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
