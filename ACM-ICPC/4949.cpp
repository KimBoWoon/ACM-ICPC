#include <cstdio>
#include <stack>
#include <memory.h>
using namespace std;

#define SIZE 1000

int main() {
    while (true) {
        char str[SIZE];
        bool flag = true;
        int size;
        stack<char> s;

        fgets(str, SIZE, stdin);
        size = strlen(str);

        if (str[0] == '.') {
            return 0;
        }

        for (int i = 0; i < size; i++) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            } else if (str[i] == ')') {
                if (s.empty()) {
                    flag = false;
                    break;
                }
                if (s.top() == '(') {
                    s.pop();
                } else {
                    flag = false;
                    break;
                }
            } else if (str[i] == ']') {
                if (s.empty()) {
                    flag = false;
                    break;
                }
                if (s.top() == '[') {
                    s.pop();
                } else {
                    flag = false;
                    break;
                }
            }
        }

        if (flag && s.empty()) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}