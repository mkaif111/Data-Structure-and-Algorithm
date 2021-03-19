#include <iostream>
#include <string>
using namespace std;

long str2int(string s)
{
    long i = 0;
    for (int j = 0; j < s.length(); j++)
    {
        i = i * 10 + (s[j] - '0');
    }
    return i;
}
bool isCB(long num)
{
    if (num == 1 or num == 0)
        return false;
    int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for (int i = 0; i < 10; i++)
    {
        if (num == arr[i])
            return true;
        if (num % arr[i] == 0)
            return false;
    }
    return true;
}
bool isVisited(bool visit[], int l, int r)
{
    for (int i = l; i < r; i++)
    {
        if (visit[i])
            return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool *visit = new bool[n]();
    // cout<<visit[0]<<endl;
    int count = 0;

    // Iterate over evry length of substring
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s.length() - i; j++)
        {
            string temp = s.substr(j, i);
            long num = str2int(temp);
            // cout<<num<<endl;
            if (isCB(num) and isVisited(visit, j, i + j))
            {
                count++;
                for (int k = j; k < i + j; k++)
                    visit[k] = true;
            }
        }
    }
    cout << count << endl;
    return 0;
}