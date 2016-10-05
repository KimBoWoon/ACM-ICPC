#include <iostream>
using namespace std;

int cnt0 = 0, cnt1 = 0;

int fibonacci(int n);

int main()
{
	int cases;

	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		int n = 0;

		cin >> n;

		fibonacci(n);

		cout << cnt0 << " " << cnt1 << endl;

		cnt0 = cnt1 = 0;
	}
}
int fibonacci(int n)
{
	if (n == 0)
	{
		cnt0++;
		return 0;
	}
	else if (n == 1)
	{
		cnt1++;
		return 1;
	}
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}