#include <iostream>
#include <iomanip>
#include <limits>
#include <time.h>
using namespace std;

void CreateRecursive(int** a, const int n, const int Low, const int High, int i, int j);
void PrintRecursive(int** a, const int n, int i, int j);
void SearchMinEvenAndMaxRecursive(int** a, const int n, int i, int j, int& minRow, int& minCol, int& maxRow, int& maxCol, int& minVal, int& maxVal);
void SwapElemRecursive(int** a, int i, int j, int minRow, int minCol, int maxRow, int maxCol);
void sumValRecursive(int& sum, int& minVal, int& maxVal);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n, sum;
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();
    int minRow, minCol, maxRow, maxCol;
    cout << "n = "; cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    // Call recursive functions
    CreateRecursive(a, n, Low, High, 0, 0);
    PrintRecursive(a, n, 0, 0);
    SearchMinEvenAndMaxRecursive(a, n, 0, 0, minRow, minCol, maxRow, maxCol, minVal, maxVal);
    SwapElemRecursive(a, 0, 0, minRow, minCol, maxRow, maxCol);
    PrintRecursive(a, n, 0, 0);
    sumValRecursive(sum, minVal, maxVal);

    // Clean up memory
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRecursive(int** a, const int n, const int Low, const int High, int i, int j)
{
    if (i < n) {
        if (j < n) {
            a[i][j] = Low + rand() % (High - Low + 1);
            CreateRecursive(a, n, Low, High, i, j + 1);
        }
        else {
            CreateRecursive(a, n, Low, High, i + 1, 0);
        }
    }
}

void PrintRecursive(int** a, const int n, int i, int j)
{
    if (i < n) {
        if (j < n) {
            cout << setw(4) << a[i][j];
            PrintRecursive(a, n, i, j + 1);
        }
        else {
            cout << endl;
            PrintRecursive(a, n, i + 1, 0);
        }
    }
    else {
        cout << endl;
    }
}

void sumValRecursive(int& sum, int& minVal, int& maxVal)
{
    sum = minVal + maxVal;
    cout << setw(4) << "sum: " << sum;
}

void SwapElemRecursive(int** a, int i, int j, int minRow, int minCol, int maxRow, int maxCol)
{
    if (i < maxRow || (i == maxRow && j < maxCol)) {
        int temp = a[minRow][minCol];
        a[minRow][minCol] = a[maxRow][maxCol];
        a[maxRow][maxCol] = temp;

        if (j + 1 < maxCol || (i < maxRow && j + 1 == maxCol)) {
            SwapElemRecursive(a, i, j + 1, minRow, minCol, maxRow, maxCol);
        }
        else {
            SwapElemRecursive(a, i + 1, 0, minRow, minCol, maxRow, maxCol);
        }
    }
}

void SearchMinEvenAndMaxRecursive(int** a, const int n, int i, int j, int& minRow, int& minCol, int& maxRow, int& maxCol, int& minVal, int& maxVal)
{
    if (i < n) {
        if (j < n) {
            if (i < j) {
                if (a[i][j] < minVal) {
                    minVal = a[i][j];
                    minRow = i;
                    minCol = j;
                }
            }
            else if (i > j) {
                if (a[i][j] > maxVal) {
                    maxVal = a[i][j];
                    maxRow = i;
                    maxCol = j;
                }
            }
            SearchMinEvenAndMaxRecursive(a, n, i, j + 1, minRow, minCol, maxRow, maxCol, minVal, maxVal);
        }
        else {
            SearchMinEvenAndMaxRecursive(a, n, i + 1, 0, minRow, minCol, maxRow, maxCol, minVal, maxVal);
        }
    }
}
