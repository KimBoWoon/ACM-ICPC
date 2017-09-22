#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int size, result, cnt = 0;
	vector<int> vec;

	cin >> size;

	for (int i = 0; i < size; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	cin >> result;

	sort(vec.begin(), vec.end());

	for (int i = 0, j = vec.size() - 1; i < j;) {
		if (vec[i] + vec[j] == result) {
			i++;
			j--;
			cnt++;
		}
		else if (vec[i] + vec[j] < result)
			i++;
		else if (vec[i] + vec[j] > result)
			j--;
	}
	cout << cnt << endl;
}