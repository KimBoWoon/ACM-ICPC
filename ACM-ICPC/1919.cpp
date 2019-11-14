#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

#define SIZE 1010

int answer;
char str1[SIZE], str2[SIZE];
int temp1[26], temp2[26];

/*
애나그램은 단어를 가지고 만드는 것이기 때문에
단어의 수가 다르면 안된다.
다른 수만큼 빼주면 정답
*/

int main() {
    scanf("%s %s", str1, str2);

    for (int i = 0; i < strlen(str1); i++) {
        temp1[str1[i] - 'a']++;
    }
    for (int i = 0; i < strlen(str2); i++) {
        temp2[str2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        answer += abs(temp1[i] - temp2[i]);
    }

    printf("%d\n", answer);
}