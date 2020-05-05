#include <cstdio>
#include <cstring>

int testCase, n;
char phoneNumber[11];
bool ans;

class TrieTree {
private:
    // root : trie tree
    // end : 노드의 끝
    // go : 다음 노드가 있는지
    TrieTree *root[10];
    bool end, go;
public:
    TrieTree() {
        memset(root, 0, sizeof(root));
        end = go = false;
    }

    ~TrieTree() {
        for (int i = 0; i < 10; i++) {
            if (root[i] != NULL) {
                delete root[i];
            }
        }
    }

    bool insert(char *phoneNumber) {
        // 마지막 체크
        if (*phoneNumber == '\0') {
            end = true;
            return go;
        }

        // 다음 노드 생성
        if (root[*phoneNumber - '0'] == NULL) {
            root[*phoneNumber - '0'] = new TrieTree;
        }

        // 다음 노드가 존재함
        go = true;

        // end가 true면 일관성이 없는 것이다
        return end || root[*phoneNumber - '0']->insert(phoneNumber + 1);
    }
};

int main() {
    scanf("%d", &testCase);

    while (testCase--) {
        TrieTree *tree = new TrieTree;
        ans = true;

        scanf("%d", &n);

        while (n--) {
            scanf("%s", &phoneNumber);

            if (ans && tree->insert(phoneNumber) == true) {
                ans = false;
            }
        }

        (ans == true) ? printf("YES\n") : printf("NO\n");
    }
}

// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int testCase, n;
// bool answer;

// int main() {
//     cin >> testCase;
    
//     while (testCase--) {
//         answer = true;
//         vector<string> v;

//         cin >> n;
        
//         for (int i = 0; i < n; i++) {
//             string s;
//             cin >> s;
//             v.push_back(s);
//         }
        
//         sort(v.begin(), v.end());

//         for (int i = 0; i < v.size() - 1; i++) {
//             if (v[i] == v[i + 1].substr(0, v[i].size())) {
//                 answer = false;
//                 break;
//             }
//         }
        
//         if (answer) {
//             cout << "YES" << endl;
//         } else {
//             cout << "NO" << endl;
//         }
//     }
// }