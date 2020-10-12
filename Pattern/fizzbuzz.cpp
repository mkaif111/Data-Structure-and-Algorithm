vector<string> Solution::fizzBuzz(int A)
{
    vector<string> ans;
    for (long long int i = 1; i <= A; i++)
    {

        if (i % 3 == 0 and i % 5)
        {

            ans.push_back("Fizz");
        }
        else if (i % 5 == 0 and i % 3)
        {
            ans.push_back("Buzz");
        }
        else if (i % 15 == 0)
        {
            ans.push_back("FizzBuzz");
        }
        else
        {
            ans.push_back(to_string(i));
        }
    }
    return ans;
}
