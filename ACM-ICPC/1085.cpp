#include <cstdio>
#include <algorithm>
using namespace std;

#pragma warning(disable:4996)

int main() {
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	printf("%d\n", min(min(w - x, x), min(y, h - y)));
}