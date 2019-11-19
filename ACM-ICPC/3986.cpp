#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int t, answer;
char word[100001];

int main() {
    scanf("%d", &t);

    while (t--) {
        stack<char> s;
        int len;

        scanf("%s", word);

        len = strlen(word);

        for (int i = 0; i < len; i++) {
            if (s.empty()) {
                s.push(word[i]);
            } else if (s.top() != word[i]) {
                s.push(word[i]);
            } else if (s.top() == word[i]) {
                s.pop();
            }
        }

        if (s.empty()) {
            answer++;
        }
    }
    
    printf("%d\n", answer);
}