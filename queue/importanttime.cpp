#include <iostream>
#include <queue>
using namespace std;

int main()
{

	int n;
	cin >> n;
	queue<int> order;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		order.push(item);
	}
	int desire[n];
	for (int i = 0; i < n; i++)
	{
		cin >> desire[i];
	}
	int time = 0;
	for (int i = 0; i < n; i++)
	{

		while (desire[i] != order.front())
		{
			int f = order.front();
			order.pop();
			order.push(f);
			time++;
		}
		order.pop();
		time++;
	}
	cout << time << "\n";

	return 0;
}