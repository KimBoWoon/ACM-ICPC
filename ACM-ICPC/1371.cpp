#include <cstdio>
#include <cstring>
using namespace std;

int max;
char str[5001];
int alphabet[26];

int main() {
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);

        for (int i = 0; i < len; i++) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                alphabet[str[i] - 'a']++;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (max < alphabet[i]) {
            max = alphabet[i];
        }
    }

    for (int i = 0; i < 26; i++) {
        if (max == alphabet[i]) {
            printf("%c", 'a' + i);
        }
    }
}