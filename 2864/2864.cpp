//
// Created by secret on 10/26/16.
//

#include <cstdio>
#include <string>

using namespace std;

string replaceString(string subject, const string &search, const string &replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

int main() {
    int a, b;
    string sa, sb;

    scanf("%d %d", &a, &b);

    sa = to_string(a);
    sb = to_string(b);

    int minV1 = stoi(replaceString(sa, "6", "5"));
    int minV2 = stoi(replaceString(sb, "6", "5"));

    printf("%d ", minV1 + minV2);

    int maxV1 = stoi(replaceString(sa, "5", "6"));
    int maxV2 = stoi(replaceString(sb, "5", "6"));

    printf("%d ", maxV1 + maxV2);
}