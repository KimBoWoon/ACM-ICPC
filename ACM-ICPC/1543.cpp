#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char str[2501], pattern[51];
// string str, pattern;
int answer;

int main() {
    fgets(str, 2501, stdin);
    fgets(pattern, 51, stdin);
    // scanf("%[^\n]s", str);
    // scanf("%[^\n]s", pattern);
    // getline(cin, str);
    // getline(cin, pattern);

    int strLen = strlen(str) - 1, patternLen = strlen(pattern) - 1;

    if (patternLen > strLen) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < strLen - patternLen + 1; i++) {
        bool flag = true;

        for (int j = 0; j < patternLen; j++) {
            if (str[i + j] != pattern[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            answer++;
            i += patternLen - 1;
        }
    }

    printf("%d\n", answer);
}