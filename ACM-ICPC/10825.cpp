#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Score {
	string name;
	int korean, english, math;
} score;

bool comp(const score& x, const score& y) {
	/*if (x.korean == y.korean) {
		if (x.english == y.english) {
			if (x.math == y.math) {
				return x.name > y.name;
			}
			return x.math > y.math;
		}
		return x.english < y.english;
	}
	return x.korean > y.korean;*/

	if (x.korean > y.korean) {
		return true;
	}
	else if (x.korean == y.korean) {
		if (x.english < y.english) {
			return true;
		}
		else if (x.english == y.english) {
			if (x.math > y.math) {
				return true;
			}
			else if (x.math == x.math) {
				return x.name < x.name;
			}
		}
	}
	return false;
}

int main() {
	/*int n;

	cin >> n;
	vector<score> s(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i].name >> s[i].korean >> s[i].english >> s[i].math;
	}

	stable_sort(s.begin(), s.end(), comp);

	for (int i = 0; i < n; i++) {
		cout << s[i].name << endl;
	}*/
	int n;
	cin >> n;

	vector<score> a(n);

	for (int i = 0; i<n; i++) {
		cin >> a[i].name >> a[i].korean >> a[i].english >> a[i].math;
	}

	stable_sort(a.begin(), a.end(), comp);

	for (int i = 0; i<n; i++) {
		cout << a[i].name << '\n';
	}

	return 0;
}

//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//struct Person {
//	string name;
//	int kor, eng, math;
//};
//
//bool cmp(const Person &u, const Person &v)
//{
//	if (u.kor > v.kor)
//		return true;
//	else if (u.kor == v.kor) {
//		if (u.eng < v.eng) {
//			return    true;
//		}
//		else if (u.eng == v.eng) {
//			if (u.math>v.math) {
//				return true;
//			}
//			else if (u.math == v.math) {
//				return u.name < v.name;
//			}
//		}
//	}
//	return false;
//
//
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//
//	vector<Person> a(n);
//	for (int i = 0; i<n; i++)
//	{
//		cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
//	}
//
//	stable_sort(a.begin(), a.end(), cmp);
//
//	for (int i = 0; i<n; i++)
//	{
//		cout << a[i].name << '\n';
//	}
//
//	return 0;
//}