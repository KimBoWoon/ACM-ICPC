#include <iostream>
#include <cmath>
using namespace std;

class Distance
{
private:
	int x1, y1, x2, y2, r1, r2;
public:
	Distance();
	double distance();
	int compute();
};

Distance::Distance()    { cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2; }
double Distance::distance() { return hypot((double)x2 - x1, (double)y2 - y1); }

int Distance::compute()
{
	double dist = distance();

	if (dist == 0)
	{
		if (r1 == 0 && r2 == 0)
			return 1;
		else if (r1 == r2 && (r1 + r2) != 0)
			return -1;
		else
			return 0;
	}
	else if ((dist + r1) < r2 || (dist + r2) < r1 || (r1 + r2) < dist)
		return 0;
	else if ((dist + r1) == r2 || (dist + r2) == r1 || (r1 + r2) == dist)
		return 1;
	else
		return 2;
}
int main()
{
	int cases;

	cin >> cases;

	for (int i = 0; i < cases; i++)
	{
		Distance d;

		if (d.compute() == 0)
			cout << "0" << endl;
		else if (d.compute() == 1)
			cout << "1" << endl;
		else if (d.compute() == 2)
			cout << "2" << endl;
		else if (d.compute() == -1)
			cout << "-1" << endl;
	}
}