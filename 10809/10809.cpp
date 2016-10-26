//
// Created by secret on 10/26/16.
//

#include <cstdio>
using namespace std;

int arr[26];
char s[101];

int main() {
    scanf("%s", s);

    for (int i = 0; i < 26; i++) {
        arr[i] = -1;
    }

    for (int i = 0; s[i] != 0; i++) {
        if (arr[s[i] - 'a'] == -1) {
            arr[s[i] - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", arr[i]);
    }
}