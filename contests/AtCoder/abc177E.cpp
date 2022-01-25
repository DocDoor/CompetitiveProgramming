#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6 + 7;
int cnt[mxN];
bool pairwise() {
	for (int i = 2; i < mxN; ++i) {
		if (cnt[i] > 1) {
			return false;
		}
	}
	return true;
}
bool setwise(int N) {
	for (int i = 2; i < mxN; i++){
		if (cnt[i] == N) {
			return false;
		}
  }
  return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 2; j * j <= a[i]; ++j) {
			if (a[i] % j == 0) {
				++cnt[j];
				while (a[i] % j == 0) {
					a[i] /= j;
				}
			}
		}
		if (a[i] != 0) {
			++cnt[a[i]];
		}
	}
	if (pairwise()) {
		cout << "pairwise coprime";
	} else if (setwise(n)) {
		cout << "setwise coprime";
	} else {
		cout << "not coprime";
	}
}	
