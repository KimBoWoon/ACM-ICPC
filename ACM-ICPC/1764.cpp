//
// Created by null on 11/1/17.
//

#define LOCAL

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<string> v, ans;

bool binarySearch(string target) {
    int start = 0, end = v.size();

    while (start <= end) {
        int mid = (start + end) / 2;

        if (v[mid] == target) {
            return true;
        }
        else if (v[mid] < target) {
            start = mid + 1;
        }
        else if (v[mid] > target) {
            end = mid - 1;
        }
    }

    return false;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);

    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        if (binarySearch(s)) {
            ans.push_back(s);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}