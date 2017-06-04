#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

#pragma warning(disable:4996)

typedef struct order {
	int num, flag;
} Order;

int n, k;
int arr[100001];
vector<Order> v;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &k);

	for (int i = 0; i < k * 2; i++) {
		int x;
		scanf("%d", &x);
		
		while (true) {
			if (v.empty()) {
				v.push_back({ x, i % 2 });
				break;
			}
			else {
				if (v[v.size() - 1].num < x) {
					v.pop_back();
				}
				else {
					v.push_back({ x, i % 2 });
					break;
				}
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].flag) {
			sort(arr + 1, arr + v[i].num + 1, greater<int>());
		}
		else {
			sort(arr + 1, arr + v[i].num + 1, less<int>());
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}