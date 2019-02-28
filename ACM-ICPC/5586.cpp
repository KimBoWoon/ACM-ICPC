#include <cstdio>
#include <cstring>
using namespace std;

int len, joi, ioi;
char str[10001];

int main() {
	scanf("%s", str);

    len = strlen(str);

    // joi와 ioi가 있는지 하나씩 검사한다
    for (int i = 0; i < len; i++) {
        if (str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            joi++;
        }
        if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            ioi++;
        }
    }

    printf("%d\n%d\n", joi, ioi);
}