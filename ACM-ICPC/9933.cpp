#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int n;
map<string, bool> m;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        string password, reversePassword;
        cin >> password;
        reversePassword = password;

        reverse(reversePassword.begin(), reversePassword.end());

        if (password.compare(reversePassword) == 0 || m.count(reversePassword)) {
            cout << password.size() << " " << password[password.size() / 2] << endl;
            break;
        } else {
            m[password] = true;
        }
        // char password[14] = { 0 }, reversePassword[14] = { 0 };
        // scanf("%s", password);
        // strcpy(reversePassword, password);

        // reverse(reversePassword, reversePassword + strlen(reversePassword));

        // if (strcmp(password, reversePassword) == 0 || m.count(reversePassword) == 1) {
        //     printf("%d %c\n", strlen(password), password[strlen(password) / 2]);
        //     break;
        // } else {
        //     m[password] = true;
        // }
    }
}