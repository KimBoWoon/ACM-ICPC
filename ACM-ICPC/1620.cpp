#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct Monster {
	int order;
	char name[21];
} monster;

int n, m;
// 1 : 이름, 2 : 순서
monster mon1[100001];
monster mon2[100001];

int comp(const void* x, const void* y) {
	return strcmp(((monster*)x)->name, ((monster*)y)->name);
}

monster nameSearch(const char* name) {
	int start = 0, end = n - 1, mid = (start + end) / 2;

	while (start <= end) {
		mid = (start + end) / 2;

		if (strcmp(mon1[mid].name, name) == 0) {
			return mon1[mid];
		} else if (strcmp(mon1[mid].name, name) > 0) {
			end = mid - 1;
		} else if (strcmp(mon1[mid].name, name) < 0) {
			start = mid + 1;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		char name[21];
		scanf("%s", name);
		mon1[i].order = i + 1;
		strcpy(mon1[i].name, name);
		mon2[i].order = i + 1;
		strcpy(mon2[i].name, name);
	}

	int size = sizeof(mon1) / sizeof(monster);

	qsort(mon1, n, sizeof(monster), comp);

	for (int i = 0; i < m; i++) {
		char target[21];

		scanf("%s", target);

		if (atoi(target) == 0) {
			printf("%d\n", nameSearch(target).order);
		} else {
			printf("%s\n", mon2[atoi(target) - 1].name);
		}
	}
}