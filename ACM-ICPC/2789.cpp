#include <cstdio>
using namespace std;

char str[101];
int position;

int main() {
    scanf("%s", str);

    // CAMBRIDGE에 해당하면 넘어간다
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'C' || str[i] == 'A' || str[i] == 'M' || str[i] == 'B' || str[i] == 'R' || str[i] == 'I' || str[i] == 'D' || str[i] == 'G' || str[i] == 'E') {
            continue;
        }
        printf("%c", str[i]);
    }
}