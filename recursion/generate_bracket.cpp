#include <iostream>

using namespace std;

void generate_bracket(string output, int index, int n, int open, int close)
{
  if (index == 2 * n)
    {
      cout << output << " ";
      return;
    }
  if (open < n)
    {
      generate_bracket(output + '(', index + 1, n, open + 1, close);
    }
  if (close < open)
    {
      generate_bracket(output + ')', index + 1, n, open, close + 1);
    }

  return;

}

int
main ()
{
//   cout << "Hello World";
  generate_bracket("", 0, 3, 0, 0);

  return 0;
}
