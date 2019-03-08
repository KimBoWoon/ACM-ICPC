#include <cstdio>
#include <cstring>
using namespace std;

bool flag;

int main() {
    for (int i = 0; i < 5; i++) {
        char name[11];
        scanf("%s", name);

        int len = strlen(name);

        if (strstr(name, "FBI") != NULL) {
            printf("%d ", i + 1);
            flag = true;
        }
    }

    if (!flag) {
        printf("HE GOT AWAY!\n");
    } else {
        printf("\n");
    }
}