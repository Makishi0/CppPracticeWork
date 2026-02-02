#include "array_operations.h"

void processArray(int arr[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    int maxVal = arr[0][0];
    int maxIndex = 0;

    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > maxVal)
            {
                maxVal = arr[i][j];
                maxIndex = index;
            }
            index++;
        }
    }

    int onesCount = 0;
    index = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (index == maxIndex)
                break;

            if (arr[i][j] == 1)
                onesCount++;
            else
                return;

            index++;
        }
        if (index == maxIndex)
            break;
    }

    int row = maxIndex / cols;
    int col = maxIndex % cols;
    arr[row][col] = onesCount;
}
