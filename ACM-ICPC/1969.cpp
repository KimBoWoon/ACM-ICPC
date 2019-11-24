#include <cstdio>
#include <algorithm>
using namespace std;

char dna[1001][51];
int n, m, answer;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", dna[i]);
    }

    for (int i = 0; i < m; i++) {
        int a = 0, t = 0, g = 0, c = 0;

        for (int j = 0; j < n; j++) {
            switch (dna[j][i]) {
                case 'A': 
                    a++;
                    break;
                case 'T': 
                    t++;
                    break;
                case 'G': 
                    g++;
                    break;
                case 'C': 
                    c++;
                    break;
            }
        }

        int maxChar = max(max(a, c), max(g, t));
        answer += n - maxChar;
        if (maxChar == a) {
            printf("A");
        } else if (maxChar == c) {
            printf("C");
        } else if (maxChar == g) {
            printf("G");
        } else if (maxChar == t) {
            printf("T");
        }
    }
    printf("\n%d\n", answer);
}