#include <cstdio>
#include <cstring>
using namespace std;

int n;
char str[101];

int f(int idx, int size) {
    char c;
    int i, answer = 0;

    for (int i = idx; i < size; i++) {
        if (str[i] == '(') { // 여는 괄호 일경우 새로운 계산 시작
            answer += f(i + 1, size);
            i = n;
        } else if (str[i] == ')') { // 닫는 괄호 일경우 뒤에 숫자가 있는지 판단한 뒤에 값 전달과 다음 인덱스 저장
            if (str[i + 1] >= '2' && str[i + 1] <= '9') {
                n = i + 1;
                return answer *= (str[i + 1] - '0');
            } else {
                n = i;
                return answer;
            }
        } else if (str[i] == 'H') { // 원소 H 일 경우 뒤에 숫자를 확인한 뒤 계산
            if (str[i + 1] >= '2' && str[i + 1] <= '9') {
                answer += 1 * (str[i + 1] - '0');
                i++;
            } else {
                answer += 1;
            }
        } else if (str[i] == 'C') { // 원소 C 일 경우 뒤에 숫자를 확인한 뒤 계산
            if (str[i + 1] >= '2' && str[i + 1] <= '9') {
                answer += 12 * (str[i + 1] - '0');
                i++;
            } else {
                answer += 12;
            }
        } else if (str[i] == 'O') { // 원소 O 일 경우 뒤에 숫자를 확인한 뒤 계산
            if (str[i + 1] >= '2' && str[i + 1] <= '9') {
                answer += 16 * (str[i + 1] - '0');
                i++;
            } else {
                answer += 16;
            }
        }
    }

    return answer;
}

int main() {
    scanf("%s", str);

    printf("%d\n", f(0, strlen(str)));
}