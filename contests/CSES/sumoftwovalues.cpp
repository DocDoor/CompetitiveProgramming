#include <bits/stdc++.h> 
using namespace std;
 
#define ll long long
#define pb push_back
#define vt vector
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second
 
#define trav(i, x) for(auto &i : x)
#define FOR(i, n) for(int i=0; i<n; ++i)
 
void solve() {
	int n, x;
	cin >> n >> x;
	map<int, int> mp;
	vt<int> a(n);
	FOR(i, n) {
		cin >> a[i];
		mp[a[i]]=i+1;
	}
	FOR(i, n) {
		if(mp[x-a[i]]&&i+1!=mp[x-a[i]]) {
			cout << i+1 << " " << mp[x-a[i]];
			return;
		}
	}
	cout << "IMPOSSIBLE";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tc=1;
	// cin >> tc;
	while(tc--) {
		solve();
	}
}
