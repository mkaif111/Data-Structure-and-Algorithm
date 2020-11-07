string Solution::convertToTitle(int A)
{

    string ans = "";
    while (A > 0)
    {
        int digit = A % 26 ? A % 26 : 26;
        char c = digit + 'A' - 1;
        ans = c + ans;
        A = A % 26 ? A / 26 : A / 26 - 1;
    }
    return ans;
}
