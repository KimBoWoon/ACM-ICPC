#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, x, y;
vector<pair<int, string> > v;
vector<pair<int, string> > ans;

int main() {
	v.push_back({ 1967, "DavidBowie" });
	v.push_back({ 1969, "SpaceOddity" });
	v.push_back({ 1970, "TheManWhoSoldTheWorld" });
	v.push_back({ 1971, "HunkyDory" });
	v.push_back({ 1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars" });
	v.push_back({ 1973, "AladdinSane" });
	v.push_back({ 1973, "PinUps" });
	v.push_back({ 1974, "DiamondDogs" });
	v.push_back({ 1975, "YoungAmericans" });
	v.push_back({ 1976, "StationToStation" });
	v.push_back({ 1977, "Low" });
	v.push_back({ 1977, "Heroes" });
	v.push_back({ 1979, "Lodger" });
	v.push_back({ 1980, "ScaryMonstersAndSuperCreeps" });
	v.push_back({ 1983, "LetsDance" });
	v.push_back({ 1984, "Tonight" });
	v.push_back({ 1987, "NeverLetMeDown" });
	v.push_back({ 1993, "BlackTieWhiteNoise" });
	v.push_back({ 1995, "1.Outside" });
	v.push_back({ 1997, "Earthling" });
	v.push_back({ 1999, "Hours" });
	v.push_back({ 2002, "Heathen" });
	v.push_back({ 2003, "Reality" });
	v.push_back({ 2013, "TheNextDay" });
	v.push_back({ 2016, "BlackStar" });

	cin >> n;

	while (n--) {
		cin >> x >> y;

		for (int i = 0; i < v.size(); i++) {
			if (x <= v[i].first && y >= v[i].first) {
				ans.push_back(v[i]);
			}
		}

		if (ans.size() == 0) {
			cout << 0 << endl;
		}
		else {
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}

		ans.clear();
	}
}