#include <iostream>
#include <stack>
using namespace std;
#define ll long long int
int main()
{
	int n;
	cin >> n;
	ll bar[n];
	for (int i = 0; i < n; i++)
	{
		cin >> bar[i];
	}

	stack<int> s;
	ll area = 0;
	int top;
	int i = 0;
	while (i < n)
	{
		if (s.empty() || bar[s.top()] <= bar[i])
		{
			s.push(i);
			i++;
		}
		else
		{
			top = s.top();
			s.pop();
			if (s.empty())
			{
				area = max(area, bar[top] * i);
			}
			else
			{
				area = max(area, bar[top] * (i - 1 - s.top()));
			}
		}
	}
	while (!s.empty())
	{
		top = s.top();
		s.pop();

		if (s.empty())
		{
			area = max(area, bar[top] * i);
		}
		else
		{
			area = max(area, bar[top] * (i - 1 - s.top()));
		}
	}
	cout << area << endl;
	return 0;
}