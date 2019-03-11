#include <cstdio>
using namespace std;

#define MAX 10001

int size;
int tree[MAX];

void postorder(int left,int right) {
    if(left > right) {
        return;
    }
    int m = left;
    while(tree[++m] < tree[left]) {

    }
    postorder(left + 1, m - 1);
    postorder(m, right);
    printf("%d\n", tree[left]);
}

int main() {
    while (scanf("%d", &tree[size]) != EOF) {
        size++;
    }

    tree[size] = 2e9;
    postorder(0, size - 1);
}