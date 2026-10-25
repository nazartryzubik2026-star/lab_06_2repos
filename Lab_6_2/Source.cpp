#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int IFirstEven(int* a, const int size, int i)
{
    if (i >= size)
        return -1;
    if (a[i] % 2 == 0)
        return i;
    return IFirstEven(a, size, i + 1);
}

void MinEven(int* a, const int size, int i, int& min)
{
    if (i < size)
    {
        if (a[i] % 2 == 0 && a[i] < min)
            min = a[i];
        MinEven(a, size, i + 1, min);
    }
}

#ifndef UNIT_TESTING
int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];

    int Low = -20;
    int High = 20;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    int i = IFirstEven(a, n, 0);
    if (i == -1)
        cout << "No even elements" << endl;
    else
    {
        int min = a[i];
        MinEven(a, n, i + 1, min);
        cout << "Min even element = " << min << endl;
    }

    return 0;
}
#endif