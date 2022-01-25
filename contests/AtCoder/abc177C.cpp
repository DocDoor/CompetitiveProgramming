#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long madd(long long a, long long b) {
	return ((a % mod) + (b % mod)) % mod;
}
long long mmul(long long a, long long b) {
	return ((a % mod) * (b % mod)) % mod;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long sum = 0;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum -= a[i];
		ans = madd(ans, mmul(a[i], sum));
	}
	cout << ans;
}
