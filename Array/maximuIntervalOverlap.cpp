#include <bits/stdc++.h>
using namespace std;

vector<int> findMaxGuests(int Entry[], int Exit[], int N)
{
    // Your code goes here
    sort(Entry, Entry + N);
    sort(Exit, Exit + N);
    int curr = 1;
    int maxtime = Entry[0];
    int ans = 1;
    int j = 0;
    int i = 1;
    while (i < N and j < N)
    {
        if (Entry[i] <= Exit[j])
        {
            curr++;
            if (curr > ans)
            {
                ans = curr;
                maxtime = Entry[i];
            }
            i++;
        }
        else
        {
            j++;
            curr--;
        }
    }

    return {ans, maxtime};
}