#include <cstdio>
#include <cstring>

char str[51];
int alphabet[26];
int len, odd, oddIndex;

int main() {
    scanf("%s", &str);

    len = strlen(str);

    for (int i = 0; i < len; i++) {
        alphabet[str[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] % 2 == 1) {
            odd++;
            oddIndex = i;
        }
    }

    if ((len % 2 == 0 && odd) || (len % 2 == 1 && odd != 1)) {
        printf("I'm Sorry Hansoo");
        return 0;
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < alphabet[i] / 2; j++) {
            printf("%c", 'A' + i);
        }
    }

    if (len % 2 == 1) {
        printf("%c", 'A' + oddIndex);
    }

    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < alphabet[i] / 2; j++) {
            printf("%c", 'A' + i);
        }
    }

    return 0;
}