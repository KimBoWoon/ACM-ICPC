#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char binary[103], answer[103];
int size;

int main() {
    scanf("%s", binary);

    while (true) {
        size = strlen(binary);

        if (size % 3 == 0) {
            break;
        }

        for (int i = size; i > 0; i--) {
            binary[i] = binary[i - 1];
        }
        binary[0] = '0';
    }

    size = strlen(binary);

    for (int i = 0, idx = 0; i < size; i += 3) {
        answer[idx++] = ((binary[i] - '0') * 4 + (binary[i + 1] - '0') * 2 + (binary[i + 2] - '0')) + '0';
    }

    printf("%s\n", answer);
}