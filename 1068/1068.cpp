#include <cstdio>
using namespace std;

int n;
int parent[55];
int node[55], check[55];

int erase(int no) {
	if (no == -1) {
		return 0;
	}
	if (check[no] == 1) {
		return 1;
	}

	return check[no] = erase(parent[no]);
}

int solve(int rem) {
	int i;
	int cnt = 0;

	check[rem] = 1;
	node[parent[rem]]--;

	for (i = 0; i < n; i++) {
		if (node[i] == 0) {
			if (erase(i) == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	int i, p;
	int rem;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &p);
		parent[i] = p;
		if (p != -1) {
			node[p]++;
		}
	}
	scanf("%d", &rem);

	printf("%d\n", solve(rem));

	return 0;
}