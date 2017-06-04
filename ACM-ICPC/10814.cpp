#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct Account {
	string name;
	int age, order;
} account;

int n;
account a[100001];

bool comp(const account &x, const account &y) {
	if (x.age == y.age) {
		return x.order < y.order;
	}

	return x.age < y.age;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i].age >> a[i].name;
		a[i].order = i;
	}

	sort(a, a + n, comp);

	for (int i = 0; i < n; i++) {
		cout << a[i].age << " " << a[i].name << endl;
	}
}