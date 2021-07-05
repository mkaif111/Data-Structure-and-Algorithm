#include <bits/stdc++.h>
#include <vector>
using namespace std;
int findAnagrams(char *input1, char *input2)
{
    int n = strlen(input1);
    int m = strlen(input2);
    vector<int> freq1(256, 0);
    for (int i = 0; i < n; i++)
    {
        freq1[input1[i]]++;
    }
    vector<int> freq2(256, 0);
    for (int i = 0; i < m; i++)
        freq2[input2[i]]++;
    int count = 0;
    for (int i = 0; i <= 256; i++)
    {
        if (freq2[i] != 0)
            count += abs(freq1[i] - freq2[i]);
    }
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq2[input1[i]] != 0)
            continue;
        count += i - l;
        l = i;
        while (i < n and freq2[input1[i]] == 0)
            count++, i++;
    }
    return count;
}

int main()
{

    char input1[1000];
    cin.getline(input1, 1000);
    char input2[1000];
    cin.getline(input2, 1000);
    cout << findAnagrams(input1, input2) << endl;
    return 0;
}