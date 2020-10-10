#include <iostream>
#include <map>
using namespace std;
int count = 0;
string searchIn[] = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
void search_str(string output)
{
    int k = output.length();
    int r = 10;
    for (int i = 0; i <= 10; i++)
    {
        string s = searchIn[i];
        for (int j = 0; j < s.length() - k; j++)
        {
            // cout<<output<<" "<<s.substr(j,k)<<" "<<endl;
            if (output == s.substr(j, k))
            {
                cout << s << endl;
                break;
            }
        }
    }
    return;
}
void generate_str(string s, string output, int index, map<int, string> m)
{
    if (index >= s.length())
    {
        count++;
        search_str(output);
        return;
    }
    int d = s[index] - '0';
    if (d == 0)
    {
        generate_str(s, output, index + 1, m);
    }
    else
    {
        string c = m[d];
        for (int i = 0; i < c.length(); i++)
        {
            generate_str(s, output + c[i], index + 1, m);
        }
    }

    return;
}
int main()
{
    string s;
    cin >> s;
    map<int, string> m;
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";

    generate_str(s, "", 0, m);
    // cout << endl;
    // cout << count << endl;
    return 0;
}