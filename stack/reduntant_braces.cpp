#include <iostream>
#include <stack>
using namespace std;
int braces(string A)
{
    stack<char> s;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '(' or A[i] == '/' or A[i] == '*' or A[i] == '-' or A[i] == '+')
            s.push(A[i]);
        else if (A[i] == ')')
        {

            if (s.top() == '(')
                return 1;
            while (!s.empty() and s.top() != '(')
                s.pop();
            if (!s.empty())
                s.pop();
        }
    }
    while (!s.empty())
    {
        if (s.top() == '(')
            return 1;
        s.pop();
    }
    return 0;
}

int main()
{
    string s = "(((a+b*(c+d)))";
    cout << braces(s) << endl;
}