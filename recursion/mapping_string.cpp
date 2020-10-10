#include <iostream>
#include <string>
using namespace std;

void generate_str(string s, string output, int index)
{
    if (index >= s.length())
    {
        cout << output << endl;
        return;
    }
    int digit = s[index] - '0';
    char c = digit + 'A' - 1;
    generate_str(s, output + c, index + 1);

    if (index + 1 < s.length())
    {
        int digit2 = s[index + 1] - '0';
        int no = digit * 10 + digit2;
        if (no <= 26)
        {
            c = no + 'A' - 1;
            generate_str(s, output + c, index + 2);
        }
    }

    return;
}
int main()
{
    string s;
    cin >> s;
    generate_str(s, "", 0);
    return 0;
}