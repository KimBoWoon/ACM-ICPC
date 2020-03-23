#include <cstdio>

int n, root, removeNode, tree[55], cnt;

// dfs를 사용하여 모든 경우 탐색
void dfs(int node) {
	int i = n, isleafNode = 1;

	// 지워야하는 노드면 넘어간다
	if (node == removeNode) {
		return;
	}

	// 모든 노드 탐색
	while (i--) {
		// 트리에서 node를 부모로 가지는 노드가 있는지 확인
		// 지워야하는 노드는 넘어간다
		// 위 두 조건 모두 만족하면 전달받은 node는 리프노드가 아니므로 node에서 다시 탐색
		if (tree[i] == node && i != removeNode) {
			dfs(i); // 자식이 있으므로 재탐색
			isleafNode = 0; // 리프노드가 아니다
		}
	}

	cnt += isleafNode;
}

int main() {
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &tree[i]);
		// 루트가 되는 노드 번호 찾기(루트 값은 -1)
		if (tree[i] < 0) {
			root = i;
		}
	}

	scanf("%d", &removeNode);

	// 해당하는 번호 부터 시작
	dfs(root);

	printf("%d\n", cnt);

	return 0;
}