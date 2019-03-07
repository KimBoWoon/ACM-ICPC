#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX 100001

typedef struct Point {
    int x, y, p, q;
} point;

int n;
point arr[MAX];

bool comp(const point& x, const point& y) {
    if (1LL * x.q * y.p != 1LL * x.p * y.q) {
        return 1LL * x.q * y.p < 1LL * x.p * y.q;
    }

    if (x.y == y.y) {
        return x.x < y.x;
    }
    return x.y < y.y;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;

	if (temp > 0) {
		return 1;
	}
	else if (temp < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

int convexHull() {
    stack<int> s;

    s.push(0);
    s.push(1);

    for (int next = 2; next < n; ) {
        while (s.size() >= 2) {
            int first, second;
            second = s.top();
            s.pop();
            first = s.top();

            if (ccw(arr[first].x, arr[first].y, arr[second].x, arr[second].y, arr[next].x, arr[next].y) > 0) {
                s.push(second);
                break;
            }
        }
        s.push(next++);
    }

    return s.size();
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    sort(arr, arr + n, comp);

    for (int i = 1; i < n; i++) {
        arr[i].p = arr[i].x - arr[0].x;
        arr[i].q = arr[i].y - arr[0].y;
    }

    sort(arr + 1, arr + n, comp);

    printf("%d\n", convexHull());
}