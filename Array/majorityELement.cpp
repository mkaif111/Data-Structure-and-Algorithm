#include <bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int n)
{

    // your code here
    int count = 1;
    int curr = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] != curr)
            count--;
        else
            count++;

        if (count <= 0)
        {
            curr = a[i];
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == curr)
            count++;
    }
    // printf("%d\n",curr);

    if (count > n / 2)
        return curr;
    return -1;
}