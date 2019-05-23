#include <bits/stdc++.h>
using namespace std;

int person[101];
stack<int> s[101];

int main() {
	int n, k; 
    
    scanf("%d %d", &n, &k);
	
    for(int i = 0; i < n; i++) {
        scanf("%d", &person[i]);
    }

	reverse(person, person + n);

	for(int i = 0; i < 100; i++) {
        s[i].push(101);
    }

	for(int i = 0; i < n; i++) {
		int idx = 0, j;

		for(j = 0; j < k; j++) {
			if(s[j].top() > person[i]) {
                break;
            }
		}

		if(j == k) {
            printf("NO\n");
            return 0;
		}

		s[j].push(person[i]);
	}

    printf("YES\n");
}