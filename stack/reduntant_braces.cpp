#include <iostream>
#include <stack>
using namespace std;
// Coding block version
// int braces(string A)
// {
//     stack<char> s;
//     for (int i = 0; i < A.size(); i++)
//     {
//         if (A[i] !=')')
//             s.push(A[i]);
//        if (A[i] == ')')
//         {

//             if (s.top() == '(')
//                 return 1;
//             else{
//                 while (s.top()!='(')
//                    { s.pop();}
//                 s.pop();
//             }
            
            
            
//         }
//     }
   
//     return 0;
// }
int braces(string A)
{
    stack<char> s;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '(' or A[i] == '/' or A[i] == '*' or A[i] == '-' or A[i] == '+')
            s.push(A[i]);
       if (A[i] == ')')
        {

            if (s.top() == '(')
                return 1;
            else{
                while (A[i]=='/' or A[i]=='*' or A[i]=='-' or A[i]=='+')
                   { s.pop();}
                s.pop();
            }
            
            
            
        }
    }
   
    return 0;
}

int main()
{
    string s = "(((a+b*(c+d)))";
    cout << braces(s) << endl;
}