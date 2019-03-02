#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 1000001

int find;
string text, pattern;
vector<int> v;

void bruteForce(const int strLen, const int patternLen) {
	for (int i = 0, k = 0; i < strLen; i++) {
		if (text[i] == pattern[0]) {
			for (int j = 1; j < patternLen; j++) {
				if (text[i + j] != pattern[j]) {
					break;
				}
				else if (j == patternLen - 1) {
                    v.push_back(i + 1);
				}
			}
		}
	}
}

void kmp(const int strLen, const int patternLen) {
	int pi[MAX] = { 0 };

    for (int i = 1, j = 0; i < patternLen; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            pi[i] = ++j;
        }
    }

    for (int i = 0, j = 0, k = 0; i < strLen; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            if (j == patternLen - 1) {
				v.push_back(i - patternLen + 2);
                j = pi[j];
            } else {
                j++;
            }
        }
    }
}

int hashFunc(const string& text, int size) {
	int hashValue = 0;

	for (int i = 0; i < size; i++) {
		hashValue = text[i] + (hashValue * 2);
	}

	return hashValue;
}

int reHash(const string& text, int idx, int patternLen, int hashPrev, int coefficient) {
	if (idx == 0) {
		return hashPrev;
	}
	
	return text[idx + patternLen - 1] + ((hashPrev - coefficient * text[idx - 1]) * 2);
}

void karpRabin(const int strLen, const int patternLen) {
	int coefficient = pow(2, pattern.size() - 1);
	int hashText = hashFunc(text, patternLen);
	int hashPattern = hashFunc(pattern, patternLen);

	for (int i = 0, j = 0; i <= strLen - patternLen; i++) {
		hashText = reHash(text, i, patternLen, hashText, coefficient);

		if (hashPattern == hashText) {
			for (j = 0; j < patternLen; j++) {
				if (text[i + j] != pattern[j]) {
					break;
				}
			}

			if (j == patternLen) {
				v.push_back(i + 1);
			}
		}
	}
}

int main() {
    getline(cin, text);
    getline(cin, pattern);

    int strLen = text.size();
    int patternLen = pattern.size();

    // bruteForce(strLen, patternLen);
    // kmp(strLen, patternLen);
    karpRabin(strLen, patternLen);

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}