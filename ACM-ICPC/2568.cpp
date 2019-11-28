#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 500001

pair<int, int> p[MAX];
int n, size, arr[MAX], fr[MAX];
bool visited[MAX];

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &p[i].first, &p[i].second);
	}

	sort(p, p + n);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", p[i].first, p[i].second);
	}

	for (int i = 0; i < n; i++) {
		int h = lower_bound(arr, arr + size, p[i].second) - arr;

		if (h == size) {
			size++;
		}

		arr[h] = p[i].second;
		// fr[arr[h]] = h ? arr[h - 1] : 0;
		if (h) {
			fr[arr[h]] = arr[h - 1];
		} else {
			fr[arr[h]] = 0;
		}
	}

	printf("%d\n", n - size);

	for (int i = arr[size - 1]; i; i = fr[i]) {
		visited[i] = true;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[p[i].second]) {
			printf("%d\n", p[i].first);
		}
	}
	return 0;
}