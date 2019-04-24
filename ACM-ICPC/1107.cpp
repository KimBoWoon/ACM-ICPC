#include <bits/stdc++.h>
using namespace std;

int answer = 0x3f3f3f3f;
int channel, n;
int button[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

void find(string s) {
    for (int i = 0; i < 10; i++) {
        if (button[i]) {
            string temp = s + (char)(i + '0');
            answer = min(answer, abs(channel - atoi(temp.c_str())) + (int) temp.length());

            if (temp.length() < 6) {
                find(temp);
            }
        }
    }
}

int main() {
    scanf("%d %d", &channel, &n);

    answer = min(answer, abs(100 - channel));

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        button[x] = 0;
    }

    if (n < 10) {
        find("");
    }

    printf("%d\n", answer);
}