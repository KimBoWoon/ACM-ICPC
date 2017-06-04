#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int testCase;

	scanf("%d", &testCase);

	while (testCase--) {
		int n, m;
		int* q;

		scanf("%d", &n);

		q = (int*)malloc(n * sizeof(int));

		for (int i = 0; i < n; ++i) {
			scanf("%d", &q[i]);
		}

		sort(q, q + n);

		scanf("%d", &m);

		for (int i = 0; i < m; ++i) {
			int ans;
			//            vector<int>::iterator iter;

			scanf("%d", &ans);

			//            iter = find(q.begin(), q.end(), ans);
			//
			//            if(iter != q.end())
			//                printf("1\n");
			//            else
			//                printf("0\n");

			if (binary_search(q, q + n, ans))
				printf("1\n");
			else
				printf("0\n");
		}
	}
}