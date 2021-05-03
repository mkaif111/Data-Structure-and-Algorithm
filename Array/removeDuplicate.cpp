#include <bits/stdc++.h>
using namespace std;

int remove_duplicate(int a[], int n)
{
    // code here
    int i = 0;
    for (int j = 0; j < n - 1; j++)
        if (a[j] != a[j + 1])
            a[i++] = a[j];
    a[i++] = a[n - 1];
    return i;
}